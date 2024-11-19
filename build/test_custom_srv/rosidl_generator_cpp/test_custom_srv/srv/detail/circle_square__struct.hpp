// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_custom_srv:srv/CircleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_HPP_
#define TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__test_custom_srv__srv__CircleSquare_Request __attribute__((deprecated))
#else
# define DEPRECATED__test_custom_srv__srv__CircleSquare_Request __declspec(deprecated)
#endif

namespace test_custom_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CircleSquare_Request_
{
  using Type = CircleSquare_Request_<ContainerAllocator>;

  explicit CircleSquare_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
      this->part = 0.0;
    }
  }

  explicit CircleSquare_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
      this->part = 0.0;
    }
  }

  // field types and members
  using _radius_type =
    double;
  _radius_type radius;
  using _part_type =
    double;
  _part_type part;

  // setters for named parameter idiom
  Type & set__radius(
    const double & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__part(
    const double & _arg)
  {
    this->part = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_custom_srv__srv__CircleSquare_Request
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_custom_srv__srv__CircleSquare_Request
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CircleSquare_Request_ & other) const
  {
    if (this->radius != other.radius) {
      return false;
    }
    if (this->part != other.part) {
      return false;
    }
    return true;
  }
  bool operator!=(const CircleSquare_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CircleSquare_Request_

// alias to use template instance with default allocator
using CircleSquare_Request =
  test_custom_srv::srv::CircleSquare_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace test_custom_srv


#ifndef _WIN32
# define DEPRECATED__test_custom_srv__srv__CircleSquare_Response __attribute__((deprecated))
#else
# define DEPRECATED__test_custom_srv__srv__CircleSquare_Response __declspec(deprecated)
#endif

namespace test_custom_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CircleSquare_Response_
{
  using Type = CircleSquare_Response_<ContainerAllocator>;

  explicit CircleSquare_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->square = 0.0;
    }
  }

  explicit CircleSquare_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->square = 0.0;
    }
  }

  // field types and members
  using _square_type =
    double;
  _square_type square;

  // setters for named parameter idiom
  Type & set__square(
    const double & _arg)
  {
    this->square = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_custom_srv__srv__CircleSquare_Response
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_custom_srv__srv__CircleSquare_Response
    std::shared_ptr<test_custom_srv::srv::CircleSquare_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CircleSquare_Response_ & other) const
  {
    if (this->square != other.square) {
      return false;
    }
    return true;
  }
  bool operator!=(const CircleSquare_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CircleSquare_Response_

// alias to use template instance with default allocator
using CircleSquare_Response =
  test_custom_srv::srv::CircleSquare_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace test_custom_srv

namespace test_custom_srv
{

namespace srv
{

struct CircleSquare
{
  using Request = test_custom_srv::srv::CircleSquare_Request;
  using Response = test_custom_srv::srv::CircleSquare_Response;
};

}  // namespace srv

}  // namespace test_custom_srv

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__STRUCT_HPP_
