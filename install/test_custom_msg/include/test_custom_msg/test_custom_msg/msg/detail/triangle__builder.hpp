// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_msg:msg/Triangle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__BUILDER_HPP_
#define TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_msg/msg/detail/triangle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_msg
{

namespace msg
{

namespace builder
{

class Init_Triangle_c
{
public:
  explicit Init_Triangle_c(::test_custom_msg::msg::Triangle & msg)
  : msg_(msg)
  {}
  ::test_custom_msg::msg::Triangle c(::test_custom_msg::msg::Triangle::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_msg::msg::Triangle msg_;
};

class Init_Triangle_b
{
public:
  explicit Init_Triangle_b(::test_custom_msg::msg::Triangle & msg)
  : msg_(msg)
  {}
  Init_Triangle_c b(::test_custom_msg::msg::Triangle::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_Triangle_c(msg_);
  }

private:
  ::test_custom_msg::msg::Triangle msg_;
};

class Init_Triangle_a
{
public:
  Init_Triangle_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_b a(::test_custom_msg::msg::Triangle::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Triangle_b(msg_);
  }

private:
  ::test_custom_msg::msg::Triangle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_msg::msg::Triangle>()
{
  return test_custom_msg::msg::builder::Init_Triangle_a();
}

}  // namespace test_custom_msg

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__BUILDER_HPP_
