from modules.common.util.testdata.simple_pb2 import SimpleMessage
from cyber_py3 import cyber, cyber_time, cyber_timer, parameter
from cyber.a_mid_test.cyber.py.cyber_node import CyberNode

import time
import sys
import os
import threading
import random
import string

lst = []
nodes = []


def generate_random_string(min_size_kb=1, max_size_kb=5):
    # 1KB = 1024 bytes, 1MB = 1024 * 1024 bytes
    size = random.randint(min_size_kb * 1024, max_size_kb * 1024)  # Size in bytes
    characters = string.ascii_letters + string.digits
    random_string = ''.join(random.choices(characters, k=size))
    return random_string


class Reader:
   def __init__(self, topic, reader):
      self.topic = topic
      self.reader = reader

class demo_writer(CyberNode):
   def __init__(self, name, topic, rate, stop_event, **kwargs):
      super().__init__(name, **kwargs)
      self.name = name
      self.topic = topic
      self.i = 0
      self.log = []
      self.log_path = os.path.join("../log2", name + '.txt')

      self.stop_event = stop_event

      self.writer = self.new_writer(topic, SimpleMessage, 10)
      self.timer = self.new_timer(rate, self.go)
      self.timer.start()
      print("----a")

   def go(self):
      # global FLAG
      # while FLAG > 0 and len(self.log) == 0:
      #    pass
      if not self.stop_event.is_set():
         msg = SimpleMessage()
         msg.text = generate_random_string()
         msg.integer = self.i
         self.writer.write(msg)
         self.log.append(",".join([self.name, self.topic, "p", str(time.time()), str(msg.text)]))
         self.i += 1
      else:
         print("----------------------------")
         # self.write_log()
         # self.log.clear()
         self.timer.stop()

   def write_log(self):
      with open(self.log_path, 'a') as file:
         for line in self.log:
            file.write(line + '\n')


class demo_reader(CyberNode):
   def __init__(self, name, topic, stop_event, **kwargs):
      super().__init__(name, **kwargs)
      self.name = name
      self.topic = topic
      self.log = []
      self.log_path = os.path.join("../log2", name + '.txt')

      self.stop_event = stop_event

      for i in topic:
         self.new_reader(i, SimpleMessage, self.go, i)

   def go(self, data, topic):
      # global FLAG
      if not self.stop_event.is_set():
         self.log.append(",".join([self.name, topic, "s", str(time.time()), str(data.text)]))
         msg = SimpleMessage()
         print(data)
      else:
         print("----------------------------")
         # self.write_log()
         # self.log.clear()
   
   def write_log(self):
      with open(self.log_path, 'a') as file:
         for line in self.log:
            file.write(line + '\n')


def run_node(node):
    node.spin()

if __name__ == '__main__':
   stop_event = threading.Event()
   p1 = demo_writer("p1", "/apollo/p1", 2000, stop_event)
   p2 = demo_writer("p2", "/apollo/p2", 5000, stop_event)
   s1 = demo_reader("s1", ["/apollo/p1", "/apollo/p2"], stop_event)

   threads = []
   lst = [p1, p2, s1]
   for n in lst:
      thread = threading.Thread(target=run_node, args=(n,))
      threads.append(thread)
      thread.start()

   time.sleep(60)
   stop_event.set()

   for node in lst:
      node.write_log()
   
   for thread in threads:
      thread.join()


   pass