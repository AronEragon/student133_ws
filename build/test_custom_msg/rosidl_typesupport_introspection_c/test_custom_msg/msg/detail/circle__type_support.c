// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_custom_msg:msg/Circle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_custom_msg/msg/detail/circle__rosidl_typesupport_introspection_c.h"
#include "test_custom_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_custom_msg/msg/detail/circle__functions.h"
#include "test_custom_msg/msg/detail/circle__struct.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/point.h"
// Member `center`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_custom_msg__msg__Circle__init(message_memory);
}

void test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_fini_function(void * message_memory)
{
  test_custom_msg__msg__Circle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_member_array[2] = {
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_custom_msg__msg__Circle, center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_custom_msg__msg__Circle, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_members = {
  "test_custom_msg__msg",  // message namespace
  "Circle",  // message name
  2,  // number of fields
  sizeof(test_custom_msg__msg__Circle),
  test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_member_array,  // message members
  test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_init_function,  // function to initialize message memory (memory has to be allocated)
  test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_type_support_handle = {
  0,
  &test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_custom_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_custom_msg, msg, Circle)() {
  test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_type_support_handle.typesupport_identifier) {
    test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &test_custom_msg__msg__Circle__rosidl_typesupport_introspection_c__Circle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif