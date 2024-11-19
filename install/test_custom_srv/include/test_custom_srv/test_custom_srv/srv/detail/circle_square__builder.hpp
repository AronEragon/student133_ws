// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_custom_srv:srv/CircleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__BUILDER_HPP_
#define TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_custom_srv/srv/detail/circle_square__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_custom_srv
{

namespace srv
{

namespace builder
{

class Init_CircleSquare_Request_part
{
public:
  explicit Init_CircleSquare_Request_part(::test_custom_srv::srv::CircleSquare_Request & msg)
  : msg_(msg)
  {}
  ::test_custom_srv::srv::CircleSquare_Request part(::test_custom_srv::srv::CircleSquare_Request::_part_type arg)
  {
    msg_.part = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_srv::srv::CircleSquare_Request msg_;
};

class Init_CircleSquare_Request_radius
{
public:
  Init_CircleSquare_Request_radius()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CircleSquare_Request_part radius(::test_custom_srv::srv::CircleSquare_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_CircleSquare_Request_part(msg_);
  }

private:
  ::test_custom_srv::srv::CircleSquare_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_srv::srv::CircleSquare_Request>()
{
  return test_custom_srv::srv::builder::Init_CircleSquare_Request_radius();
}

}  // namespace test_custom_srv


namespace test_custom_srv
{

namespace srv
{

namespace builder
{

class Init_CircleSquare_Response_square
{
public:
  Init_CircleSquare_Response_square()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::test_custom_srv::srv::CircleSquare_Response square(::test_custom_srv::srv::CircleSquare_Response::_square_type arg)
  {
    msg_.square = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_custom_srv::srv::CircleSquare_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_custom_srv::srv::CircleSquare_Response>()
{
  return test_custom_srv::srv::builder::Init_CircleSquare_Response_square();
}

}  // namespace test_custom_srv

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__BUILDER_HPP_
