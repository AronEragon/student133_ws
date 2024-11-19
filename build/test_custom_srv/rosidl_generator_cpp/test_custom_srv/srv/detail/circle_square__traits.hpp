// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_custom_srv:srv/CircleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__TRAITS_HPP_
#define TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "test_custom_srv/srv/detail/circle_square__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_custom_srv
{

namespace srv
{

inline void to_flow_style_yaml(
  const CircleSquare_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: part
  {
    out << "part: ";
    rosidl_generator_traits::value_to_yaml(msg.part, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CircleSquare_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: part
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "part: ";
    rosidl_generator_traits::value_to_yaml(msg.part, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CircleSquare_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace test_custom_srv

namespace rosidl_generator_traits
{

[[deprecated("use test_custom_srv::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_custom_srv::srv::CircleSquare_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_custom_srv::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_custom_srv::srv::to_yaml() instead")]]
inline std::string to_yaml(const test_custom_srv::srv::CircleSquare_Request & msg)
{
  return test_custom_srv::srv::to_yaml(msg);
}

template<>
inline const char * data_type<test_custom_srv::srv::CircleSquare_Request>()
{
  return "test_custom_srv::srv::CircleSquare_Request";
}

template<>
inline const char * name<test_custom_srv::srv::CircleSquare_Request>()
{
  return "test_custom_srv/srv/CircleSquare_Request";
}

template<>
struct has_fixed_size<test_custom_srv::srv::CircleSquare_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_custom_srv::srv::CircleSquare_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_custom_srv::srv::CircleSquare_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace test_custom_srv
{

namespace srv
{

inline void to_flow_style_yaml(
  const CircleSquare_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: square
  {
    out << "square: ";
    rosidl_generator_traits::value_to_yaml(msg.square, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CircleSquare_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: square
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "square: ";
    rosidl_generator_traits::value_to_yaml(msg.square, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CircleSquare_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace test_custom_srv

namespace rosidl_generator_traits
{

[[deprecated("use test_custom_srv::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_custom_srv::srv::CircleSquare_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_custom_srv::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_custom_srv::srv::to_yaml() instead")]]
inline std::string to_yaml(const test_custom_srv::srv::CircleSquare_Response & msg)
{
  return test_custom_srv::srv::to_yaml(msg);
}

template<>
inline const char * data_type<test_custom_srv::srv::CircleSquare_Response>()
{
  return "test_custom_srv::srv::CircleSquare_Response";
}

template<>
inline const char * name<test_custom_srv::srv::CircleSquare_Response>()
{
  return "test_custom_srv/srv/CircleSquare_Response";
}

template<>
struct has_fixed_size<test_custom_srv::srv::CircleSquare_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_custom_srv::srv::CircleSquare_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_custom_srv::srv::CircleSquare_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<test_custom_srv::srv::CircleSquare>()
{
  return "test_custom_srv::srv::CircleSquare";
}

template<>
inline const char * name<test_custom_srv::srv::CircleSquare>()
{
  return "test_custom_srv/srv/CircleSquare";
}

template<>
struct has_fixed_size<test_custom_srv::srv::CircleSquare>
  : std::integral_constant<
    bool,
    has_fixed_size<test_custom_srv::srv::CircleSquare_Request>::value &&
    has_fixed_size<test_custom_srv::srv::CircleSquare_Response>::value
  >
{
};

template<>
struct has_bounded_size<test_custom_srv::srv::CircleSquare>
  : std::integral_constant<
    bool,
    has_bounded_size<test_custom_srv::srv::CircleSquare_Request>::value &&
    has_bounded_size<test_custom_srv::srv::CircleSquare_Response>::value
  >
{
};

template<>
struct is_service<test_custom_srv::srv::CircleSquare>
  : std::true_type
{
};

template<>
struct is_service_request<test_custom_srv::srv::CircleSquare_Request>
  : std::true_type
{
};

template<>
struct is_service_response<test_custom_srv::srv::CircleSquare_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__TRAITS_HPP_
