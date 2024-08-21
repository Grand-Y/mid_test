import sys
sys.path.append("../")
from cyber_py3 import cyber
from modules.common.util.testdata.simple_pb2 import SimpleMessage
from modules.a_mid_test.cyber.py.cyber_node import CyberNode
import time
import sys
import os

logs = []
node_name = "DINGZHEN_2"
topic = "/apollo/ruike5"
file_path = os.path.join("./log", node_name + '.txt')

def write_log(path):
   with open(path, 'a') as file:
      for line in logs:
         file.write(line + '\n')
      file.write("\n")

def callback(data):

    """
    reader message callback.
    """
    print("="*80)
    print("py:reader callback msg->:")
    print(data)
    # logs.append(",".join([node_name, topic, "s", str(time.time()), str(data.text)]))
    # if len(logs) == 100:
    #      write_log(file_path)
    #      logs.clear()
    

def test_listener_class():
    """
    reader message.
    """
    if not os.path.exists(os.getcwd()):
        os.makedirs(os.getcwd())

    print("=" * 80)
    test_node = cyber.Node(node_name)
    test_node.create_reader(topic,
            SimpleMessage, callback)
    test_node.spin()


class demo_reader(CyberNode):
   def __init__(self, name, topic, **kwargs):
      super().__init__(name, **kwargs)
      self.reader = self.new_reader(topic, SimpleMessage, self.go)
    #   self.timer = self.new_timer(rate, self.go)
    #   self.timer.start()
      self.i = 0
      print("----a")

   def go(self, data):
      print("----b")
      msg = SimpleMessage()
      print(data)
    #   print(a)

if __name__ == '__main__':

    # cyber.init()
    # test_listener_class()
    # cyber.shutdown()
    cn = demo_reader("dingzhen2", "/apollo/ruike5")
    cn.spin()
