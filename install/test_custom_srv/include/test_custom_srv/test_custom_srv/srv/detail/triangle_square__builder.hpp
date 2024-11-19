// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_srv:srv/TriangleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__TRIANGLE_SQUARE__BUILDER_HPP_
#define TEST_CUSTOM_SRV__SRV__DETAIL__TRIANGLE_SQUARE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_srv/srv/detail/triangle_square__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_srv
{

namespace srv
{

namespace builder
{

class Init_TriangleSquare_Request_c
{
public:
  explicit Init_TriangleSquare_Request_c(::test_custom_srv::srv::TriangleSquare_Request & msg)
  : msg_(msg)
  {}
  ::test_custom_srv::srv::TriangleSquare_Request c(::test_custom_srv::srv::TriangleSquare_Request::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_srv::srv::TriangleSquare_Request msg_;
};

class Init_TriangleSquare_Request_b
{
public:
  explicit Init_TriangleSquare_Request_b(::test_custom_srv::srv::TriangleSquare_Request & msg)
  : msg_(msg)
  {}
  Init_TriangleSquare_Request_c b(::test_custom_srv::srv::TriangleSquare_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_TriangleSquare_Request_c(msg_);
  }

private:
  ::test_custom_srv::srv::TriangleSquare_Request msg_;
};

class Init_TriangleSquare_Request_a
{
public:
  Init_TriangleSquare_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriangleSquare_Request_b a(::test_custom_srv::srv::TriangleSquare_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_TriangleSquare_Request_b(msg_);
  }

private:
  ::test_custom_srv::srv::TriangleSquare_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_srv::srv::TriangleSquare_Request>()
{
  return test_custom_srv::srv::builder::Init_TriangleSquare_Request_a();
}

}  // namespace test_custom_srv


namespace test_custom_srv
{

namespace srv
{

namespace builder
{

class Init_TriangleSquare_Response_square
{
public:
  Init_TriangleSquare_Response_square()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::test_custom_srv::srv::TriangleSquare_Response square(::test_custom_srv::srv::TriangleSquare_Response::_square_type arg)
  {
    msg_.square = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_srv::srv::TriangleSquare_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_srv::srv::TriangleSquare_Response>()
{
  return test_custom_srv::srv::builder::Init_TriangleSquare_Response_square();
}

}  // namespace test_custom_srv

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__TRIANGLE_SQUARE__BUILDER_HPP_
