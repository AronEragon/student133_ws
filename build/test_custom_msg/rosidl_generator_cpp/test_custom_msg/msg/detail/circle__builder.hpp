// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_msg:msg/Circle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__BUILDER_HPP_
#define TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_msg/msg/detail/circle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_msg
{

namespace msg
{

namespace builder
{

class Init_Circle_radius
{
public:
  explicit Init_Circle_radius(::test_custom_msg::msg::Circle & msg)
  : msg_(msg)
  {}
  ::test_custom_msg::msg::Circle radius(::test_custom_msg::msg::Circle::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg::msg::Circle msg_;
};

class Init_Circle_center
{
public:
  Init_Circle_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Circle_radius center(::test_custom_msg::msg::Circle::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Circle_radius(msg_);
  }

private:
  ::test_custom_msg::msg::Circle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg::msg::Circle>()
{
  return test_custom_msg::msg::builder::Init_Circle_center();
}

}  // namespace test_custom_msg

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__CIRCLE__BUILDER_HPP_
