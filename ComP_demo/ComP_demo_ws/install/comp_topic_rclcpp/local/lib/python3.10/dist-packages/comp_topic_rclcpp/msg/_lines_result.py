# generated from rosidl_generator_py/resource/_idl.py.em
# with input from comp_topic_rclcpp:msg/LinesResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LinesResult(type):
    """Metaclass of message 'LinesResult'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('comp_topic_rclcpp')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'comp_topic_rclcpp.msg.LinesResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lane_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lane_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lane_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lane_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lane_result

            from comp_topic_rclcpp.msg import PointDetect
            if PointDetect.__class__._TYPE_SUPPORT is None:
                PointDetect.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LinesResult(metaclass=Metaclass_LinesResult):
    """Message class 'LinesResult'."""

    __slots__ = [
        '_header',
        '_left1',
        '_right1',
        '_left2',
        '_right2',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'left1': 'comp_topic_rclcpp/PointDetect',
        'right1': 'comp_topic_rclcpp/PointDetect',
        'left2': 'comp_topic_rclcpp/PointDetect',
        'right2': 'comp_topic_rclcpp/PointDetect',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['comp_topic_rclcpp', 'msg'], 'PointDetect'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['comp_topic_rclcpp', 'msg'], 'PointDetect'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['comp_topic_rclcpp', 'msg'], 'PointDetect'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['comp_topic_rclcpp', 'msg'], 'PointDetect'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from comp_topic_rclcpp.msg import PointDetect
        self.left1 = kwargs.get('left1', PointDetect())
        from comp_topic_rclcpp.msg import PointDetect
        self.right1 = kwargs.get('right1', PointDetect())
        from comp_topic_rclcpp.msg import PointDetect
        self.left2 = kwargs.get('left2', PointDetect())
        from comp_topic_rclcpp.msg import PointDetect
        self.right2 = kwargs.get('right2', PointDetect())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.left1 != other.left1:
            return False
        if self.right1 != other.right1:
            return False
        if self.left2 != other.left2:
            return False
        if self.right2 != other.right2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def left1(self):
        """Message field 'left1'."""
        return self._left1

    @left1.setter
    def left1(self, value):
        if __debug__:
            from comp_topic_rclcpp.msg import PointDetect
            assert \
                isinstance(value, PointDetect), \
                "The 'left1' field must be a sub message of type 'PointDetect'"
        self._left1 = value

    @builtins.property
    def right1(self):
        """Message field 'right1'."""
        return self._right1

    @right1.setter
    def right1(self, value):
        if __debug__:
            from comp_topic_rclcpp.msg import PointDetect
            assert \
                isinstance(value, PointDetect), \
                "The 'right1' field must be a sub message of type 'PointDetect'"
        self._right1 = value

    @builtins.property
    def left2(self):
        """Message field 'left2'."""
        return self._left2

    @left2.setter
    def left2(self, value):
        if __debug__:
            from comp_topic_rclcpp.msg import PointDetect
            assert \
                isinstance(value, PointDetect), \
                "The 'left2' field must be a sub message of type 'PointDetect'"
        self._left2 = value

    @builtins.property
    def right2(self):
        """Message field 'right2'."""
        return self._right2

    @right2.setter
    def right2(self, value):
        if __debug__:
            from comp_topic_rclcpp.msg import PointDetect
            assert \
                isinstance(value, PointDetect), \
                "The 'right2' field must be a sub message of type 'PointDetect'"
        self._right2 = value
