from modules.common.util.testdata.simple_pb2 import SimpleMessage
from cyber_py3 import cyber, cyber_time, cyber_timer, parameter
from modules.a_mid_test.cyber.py.cyber_node import CyberNode


"""Module for example of talker."""
import time
import sys
import os
sys.path.append("../")

logs = []
node_name = "DINGZHEN_1"
topic = "/apollo/ruike5"
file_path = os.path.join("./log", node_name + '.txt')

def write_log(path):
   with open(path, 'a') as file:
      for line in logs:
         file.write(line + '\n')
      file.write("\n")

class demo_writer(CyberNode):
   def __init__(self, name, **kwargs):
      super().__init__(name, **kwargs)
      self.writer = self.new_writer(topic, SimpleMessage, 10)
      self.timer = self.new_timer(1, self.go)
      self.timer.start()
      self.i = 0
      print("----a")

   def go(self):
      print("----b")
      msg = SimpleMessage()
      msg.text = "talker:send Alex!"
      msg.integer = self.i
      self.writer.write(msg)
      self.i += 1

class demo(object):
   def __init__(self, name):
      self.node = cyber.Node(name)
      self.writer = self.node.create_writer(topic, SimpleMessage, 10)
      self.timer = cyber_timer.Timer(1, self.go)
      self.i = 0
      print("----a")
   
   def go(self):
      print("----b")

      msg = SimpleMessage()
      msg.text = "talker:send Alex!"
      msg.integer = self.i
      self.writer.write(msg)
      self.i += 1
       

def test_talker_class():
   """
   test talker.
   """
   if not os.path.exists(os.getcwd()):
      os.makedirs(os.getcwd())


   msg = SimpleMessage()
   msg.text = "talker:send Alex!"
   msg.integer = 0
   g_count = 1
   # test_node = cyber.Node(node_name)
   # writer = test_node.create_writer(topic,SimpleMessage, 6)
   node = CyberNode(node_name)
   writer = node.new_writer(topic, SimpleMessage, 10)

   while not cyber.is_shutdown():
      # time.sleep(0.2)
      g_count = g_count + 1
      msg.integer = g_count
      print("="*80)
      print("write msg -> %s" % msg)

      # if len(logs) == 100:
      #    write_log(file_path)
      #    logs.clear()

      logs.append(",".join([node_name, topic, "p", str(time.time()), msg.text]))
      writer.write(msg)
   # print("-")
   # msg.integer = 1
   # writer.write(msg)
   # print("-")
   # node.spin()



if __name__ == '__main__':
   # cyber.init()
   # test_talker_class()
   cn = demo_writer("dingzhen1")
   # cn = demo("dingzhen1")
   cn.spin()
   # cyber.shutdown()