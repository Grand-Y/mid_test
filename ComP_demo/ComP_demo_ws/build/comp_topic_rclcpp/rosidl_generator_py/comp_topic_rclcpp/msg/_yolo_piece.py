# generated from rosidl_generator_py/resource/_idl.py.em
# with input from comp_topic_rclcpp:msg/YoloPiece.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_YoloPiece(type):
    """Metaclass of message 'YoloPiece'."""

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
                'comp_topic_rclcpp.msg.YoloPiece')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__yolo_piece
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__yolo_piece
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__yolo_piece
            cls._TYPE_SUPPORT = module.type_support_msg__msg__yolo_piece
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__yolo_piece

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class YoloPiece(metaclass=Metaclass_YoloPiece):
    """Message class 'YoloPiece'."""

    __slots__ = [
        '_x',
        '_y',
        '_w',
        '_h',
        '_prob',
        '_obj_id',
        '_track_id',
        '_frames_counter',
    ]

    _fields_and_field_types = {
        'x': 'double',
        'y': 'double',
        'w': 'double',
        'h': 'double',
        'prob': 'float',
        'obj_id': 'int32',
        'track_id': 'int32',
        'frames_counter': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.w = kwargs.get('w', float())
        self.h = kwargs.get('h', float())
        self.prob = kwargs.get('prob', float())
        self.obj_id = kwargs.get('obj_id', int())
        self.track_id = kwargs.get('track_id', int())
        self.frames_counter = kwargs.get('frames_counter', int())

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
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.w != other.w:
            return False
        if self.h != other.h:
            return False
        if self.prob != other.prob:
            return False
        if self.obj_id != other.obj_id:
            return False
        if self.track_id != other.track_id:
            return False
        if self.frames_counter != other.frames_counter:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def w(self):
        """Message field 'w'."""
        return self._w

    @w.setter
    def w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w = value

    @builtins.property
    def h(self):
        """Message field 'h'."""
        return self._h

    @h.setter
    def h(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'h' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'h' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._h = value

    @builtins.property
    def prob(self):
        """Message field 'prob'."""
        return self._prob

    @prob.setter
    def prob(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'prob' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'prob' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._prob = value

    @builtins.property
    def obj_id(self):
        """Message field 'obj_id'."""
        return self._obj_id

    @obj_id.setter
    def obj_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obj_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'obj_id' field must be an integer in [-2147483648, 2147483647]"
        self._obj_id = value

    @builtins.property
    def track_id(self):
        """Message field 'track_id'."""
        return self._track_id

    @track_id.setter
    def track_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'track_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'track_id' field must be an integer in [-2147483648, 2147483647]"
        self._track_id = value

    @builtins.property
    def frames_counter(self):
        """Message field 'frames_counter'."""
        return self._frames_counter

    @frames_counter.setter
    def frames_counter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frames_counter' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'frames_counter' field must be an integer in [-2147483648, 2147483647]"
        self._frames_counter = value
