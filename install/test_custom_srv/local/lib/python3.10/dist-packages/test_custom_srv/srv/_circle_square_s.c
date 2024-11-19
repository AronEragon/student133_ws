// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from test_custom_srv:srv/CircleSquare.idl
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
#include "test_custom_srv/srv/detail/circle_square__struct.h"
#include "test_custom_srv/srv/detail/circle_square__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool test_custom_srv__srv__circle_square__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
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
    assert(strncmp("test_custom_srv.srv._circle_square.CircleSquare_Request", full_classname_dest, 55) == 0);
  }
  test_custom_srv__srv__CircleSquare_Request * ros_message = _ros_message;
  {  // radius
    PyObject * field = PyObject_GetAttrString(_pymsg, "radius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->radius = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // part
    PyObject * field = PyObject_GetAttrString(_pymsg, "part");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->part = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * test_custom_srv__srv__circle_square__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CircleSquare_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("test_custom_srv.srv._circle_square");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CircleSquare_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  test_custom_srv__srv__CircleSquare_Request * ros_message = (test_custom_srv__srv__CircleSquare_Request *)raw_ros_message;
  {  // radius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->radius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "radius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // part
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->part);
    {
      int rc = PyObject_SetAttrString(_pymessage, "part", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "test_custom_srv/srv/detail/circle_square__struct.h"
// already included above
// #include "test_custom_srv/srv/detail/circle_square__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool test_custom_srv__srv__circle_square__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
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
    assert(strncmp("test_custom_srv.srv._circle_square.CircleSquare_Response", full_classname_dest, 56) == 0);
  }
  test_custom_srv__srv__CircleSquare_Response * ros_message = _ros_message;
  {  // square
    PyObject * field = PyObject_GetAttrString(_pymsg, "square");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->square = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * test_custom_srv__srv__circle_square__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CircleSquare_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("test_custom_srv.srv._circle_square");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CircleSquare_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  test_custom_srv__srv__CircleSquare_Response * ros_message = (test_custom_srv__srv__CircleSquare_Response *)raw_ros_message;
  {  // square
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->square);
    {
      int rc = PyObject_SetAttrString(_pymessage, "square", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
