// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from comp_topic_rclcpp:msg/YoloPiece.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "comp_topic_rclcpp/msg/detail/yolo_piece__struct.h"
#include "comp_topic_rclcpp/msg/detail/yolo_piece__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool comp_topic_rclcpp__msg__yolo_piece__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("comp_topic_rclcpp.msg._yolo_piece.YoloPiece", full_classname_dest, 43) == 0);
  }
  comp_topic_rclcpp__msg__YoloPiece * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // w
    PyObject * field = PyObject_GetAttrString(_pymsg, "w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // h
    PyObject * field = PyObject_GetAttrString(_pymsg, "h");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->h = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // prob
    PyObject * field = PyObject_GetAttrString(_pymsg, "prob");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->prob = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // obj_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "obj_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obj_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // track_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "track_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->track_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // frames_counter
    PyObject * field = PyObject_GetAttrString(_pymsg, "frames_counter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frames_counter = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * comp_topic_rclcpp__msg__yolo_piece__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of YoloPiece */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("comp_topic_rclcpp.msg._yolo_piece");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "YoloPiece");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  comp_topic_rclcpp__msg__YoloPiece * ros_message = (comp_topic_rclcpp__msg__YoloPiece *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // h
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prob
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->prob);
    {
      int rc = PyObject_SetAttrString(_pymessage, "prob", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obj_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->obj_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obj_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // track_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->track_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "track_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frames_counter
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->frames_counter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frames_counter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
