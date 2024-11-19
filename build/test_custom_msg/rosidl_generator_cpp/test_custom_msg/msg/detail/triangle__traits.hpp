// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_custom_msg:msg/Triangle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__TRAITS_HPP_
#define TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "test_custom_msg/msg/detail/triangle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'a'
// Member 'b'
// Member 'c'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace test_custom_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Triangle & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    to_flow_style_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    to_flow_style_yaml(msg.b, out);
    out << ", ";
  }

  // member: c
  {
    out << "c: ";
    to_flow_style_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Triangle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a:\n";
    to_block_style_yaml(msg.a, out, indentation + 2);
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b:\n";
    to_block_style_yaml(msg.b, out, indentation + 2);
  }

  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c:\n";
    to_block_style_yaml(msg.c, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Triangle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace test_custom_msg

namespace rosidl_generator_traits
{

[[deprecated("use test_custom_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_custom_msg::msg::Triangle & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_custom_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_custom_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const test_custom_msg::msg::Triangle & msg)
{
  return test_custom_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<test_custom_msg::msg::Triangle>()
{
  return "test_custom_msg::msg::Triangle";
}

template<>
inline const char * name<test_custom_msg::msg::Triangle>()
{
  return "test_custom_msg/msg/Triangle";
}

template<>
struct has_fixed_size<test_custom_msg::msg::Triangle>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<test_custom_msg::msg::Triangle>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<test_custom_msg::msg::Triangle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__TRAITS_HPP_
