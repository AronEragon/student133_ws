// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_custom_msg:msg/Triangle.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_HPP_
#define TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'a'
// Member 'b'
// Member 'c'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__test_custom_msg__msg__Triangle __attribute__((deprecated))
#else
# define DEPRECATED__test_custom_msg__msg__Triangle __declspec(deprecated)
#endif

namespace test_custom_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Triangle_
{
  using Type = Triangle_<ContainerAllocator>;

  explicit Triangle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : a(_init),
    b(_init),
    c(_init)
  {
    (void)_init;
  }

  explicit Triangle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : a(_alloc, _init),
    b(_alloc, _init),
    c(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _a_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _a_type a;
  using _b_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _b_type b;
  using _c_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _c_type c;

  // setters for named parameter idiom
  Type & set__a(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__c(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_custom_msg::msg::Triangle_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_custom_msg::msg::Triangle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_custom_msg::msg::Triangle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_custom_msg::msg::Triangle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_custom_msg__msg__Triangle
    std::shared_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_custom_msg__msg__Triangle
    std::shared_ptr<test_custom_msg::msg::Triangle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Triangle_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const Triangle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Triangle_

// alias to use template instance with default allocator
using Triangle =
  test_custom_msg::msg::Triangle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_custom_msg

#endif  // TEST_CUSTOM_MSG__MSG__DETAIL__TRIANGLE__STRUCT_HPP_
