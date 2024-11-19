// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_custom_srv:srv/CircleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_H_
#define TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CircleSquare in the package test_custom_srv.
typedef struct test_custom_srv__srv__CircleSquare_Request
{
  double radius;
  double part;
} test_custom_srv__srv__CircleSquare_Request;

// Struct for a sequence of test_custom_srv__srv__CircleSquare_Request.
typedef struct test_custom_srv__srv__CircleSquare_Request__Sequence
{
  test_custom_srv__srv__CircleSquare_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_custom_srv__srv__CircleSquare_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CircleSquare in the package test_custom_srv.
typedef struct test_custom_srv__srv__CircleSquare_Response
{
  double square;
} test_custom_srv__srv__CircleSquare_Response;

// Struct for a sequence of test_custom_srv__srv__CircleSquare_Response.
typedef struct test_custom_srv__srv__CircleSquare_Response__Sequence
{
  test_custom_srv__srv__CircleSquare_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_custom_srv__srv__CircleSquare_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_H_
