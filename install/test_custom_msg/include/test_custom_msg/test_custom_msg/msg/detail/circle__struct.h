// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_custom_msg:msg/Circle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__STRUCT_H_
#define TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Circle in the package test_custom_msg.
typedef struct test_custom_msg__msg__Circle
{
  geometry_msgs__msg__Point center;
  double radius;
} test_custom_msg__msg__Circle;

// Struct for a sequence of test_custom_msg__msg__Circle.
typedef struct test_custom_msg__msg__Circle__Sequence
{
  test_custom_msg__msg__Circle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_custom_msg__msg__Circle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__STRUCT_H_
