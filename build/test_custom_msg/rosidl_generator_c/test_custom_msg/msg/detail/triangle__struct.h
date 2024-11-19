// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_custom_msg:msg/Triangle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_H_
#define TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'a'
// Member 'b'
// Member 'c'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Triangle in the package test_custom_msg.
typedef struct test_custom_msg__msg__Triangle
{
  geometry_msgs__msg__Point a;
  geometry_msgs__msg__Point b;
  geometry_msgs__msg__Point c;
} test_custom_msg__msg__Triangle;

// Struct for a sequence of test_custom_msg__msg__Triangle.
typedef struct test_custom_msg__msg__Triangle__Sequence
{
  test_custom_msg__msg__Triangle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_custom_msg__msg__Triangle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_H_
