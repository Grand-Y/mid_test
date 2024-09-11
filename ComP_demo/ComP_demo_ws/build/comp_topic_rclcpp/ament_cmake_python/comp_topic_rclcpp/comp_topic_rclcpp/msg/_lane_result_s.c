// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from comp_topic_rclcpp:msg/LaneResult.idl
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
#include "comp_topic_rclcpp/msg/detail/lane_result__struct.h"
#include "comp_topic_rclcpp/msg/detail/lane_result__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool comp_topic_rclcpp__msg__point_detect__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * comp_topic_rclcpp__msg__point_detect__convert_to_py(void * raw_ros_message);
bool comp_topic_rclcpp__msg__point_detect__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * comp_topic_rclcpp__msg__point_detect__convert_to_py(void * raw_ros_message);
bool comp_topic_rclcpp__msg__point_detect__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * comp_topic_rclcpp__msg__point_detect__convert_to_py(void * raw_ros_message);
bool comp_topic_rclcpp__msg__point_detect__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * comp_topic_rclcpp__msg__point_detect__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool comp_topic_rclcpp__msg__lane_result__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("comp_topic_rclcpp.msg._lane_result.LaneResult", full_classname_dest, 45) == 0);
  }
  comp_topic_rclcpp__msg__LaneResult * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left1
    PyObject * field = PyObject_GetAttrString(_pymsg, "left1");
    if (!field) {
      return false;
    }
    if (!comp_topic_rclcpp__msg__point_detect__convert_from_py(field, &ros_message->left1)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // right1
    PyObject * field = PyObject_GetAttrString(_pymsg, "right1");
    if (!field) {
      return false;
    }
    if (!comp_topic_rclcpp__msg__point_detect__convert_from_py(field, &ros_message->right1)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left2
    PyObject * field = PyObject_GetAttrString(_pymsg, "left2");
    if (!field) {
      return false;
    }
    if (!comp_topic_rclcpp__msg__point_detect__convert_from_py(field, &ros_message->left2)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // right2
    PyObject * field = PyObject_GetAttrString(_pymsg, "right2");
    if (!field) {
      return false;
    }
    if (!comp_topic_rclcpp__msg__point_detect__convert_from_py(field, &ros_message->right2)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * comp_topic_rclcpp__msg__lane_result__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LaneResult */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("comp_topic_rclcpp.msg._lane_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LaneResult");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  comp_topic_rclcpp__msg__LaneResult * ros_message = (comp_topic_rclcpp__msg__LaneResult *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left1
    PyObject * field = NULL;
    field = comp_topic_rclcpp__msg__point_detect__convert_to_py(&ros_message->left1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "left1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right1
    PyObject * field = NULL;
    field = comp_topic_rclcpp__msg__point_detect__convert_to_py(&ros_message->right1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "right1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left2
    PyObject * field = NULL;
    field = comp_topic_rclcpp__msg__point_detect__convert_to_py(&ros_message->left2);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "left2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right2
    PyObject * field = NULL;
    field = comp_topic_rclcpp__msg__point_detect__convert_to_py(&ros_message->right2);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "right2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
