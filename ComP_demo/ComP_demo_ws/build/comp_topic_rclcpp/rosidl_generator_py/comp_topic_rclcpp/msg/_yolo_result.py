# generated from rosidl_generator_py/resource/_idl.py.em
# with input from comp_topic_rclcpp:msg/YoloResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_YoloResult(type):
    """Metaclass of message 'YoloResult'."""

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
                'comp_topic_rclcpp.msg.YoloResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__yolo_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__yolo_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__yolo_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__yolo_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__yolo_result

            from comp_topic_rclcpp.msg import YoloPiece
            if YoloPiece.__class__._TYPE_SUPPORT is None:
                YoloPiece.__class__.__import_type_support__()

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


class YoloResult(metaclass=Metaclass_YoloResult):
    """Message class 'YoloResult'."""

    __slots__ = [
        '_header',
        '_result_num',
        '_result_array',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'result_num': 'uint32',
        'result_array': 'sequence<comp_topic_rclcpp/YoloPiece>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['comp_topic_rclcpp', 'msg'], 'YoloPiece')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.result_num = kwargs.get('result_num', int())
        self.result_array = kwargs.get('result_array', [])

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
        if self.result_num != other.result_num:
            return False
        if self.result_array != other.result_array:
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
    def result_num(self):
        """Message field 'result_num'."""
        return self._result_num

    @result_num.setter
    def result_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'result_num' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'result_num' field must be an unsigned integer in [0, 4294967295]"
        self._result_num = value

    @builtins.property
    def result_array(self):
        """Message field 'result_array'."""
        return self._result_array

    @result_array.setter
    def result_array(self, value):
        if __debug__:
            from comp_topic_rclcpp.msg import YoloPiece
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, YoloPiece) for v in value) and
                 True), \
                "The 'result_array' field must be a set or sequence and each value of type 'YoloPiece'"
        self._result_array = value