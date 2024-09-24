import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fyier/testing/ros_ws/src/chat_service/install/chat_service'
