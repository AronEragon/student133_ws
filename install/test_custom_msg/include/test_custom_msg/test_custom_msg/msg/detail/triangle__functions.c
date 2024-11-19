// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from test_custom_msg:msg/Triangle.idl
// generated code does not contain a copyright notice
#include "test_custom_msg/msg/detail/triangle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `a`
// Member `b`
// Member `c`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
test_custom_msg__msg__Triangle__init(test_custom_msg__msg__Triangle * msg)
{
  if (!msg) {
    return false;
  }
  // a
  if (!geometry_msgs__msg__Point__init(&msg->a)) {
    test_custom_msg__msg__Triangle__fini(msg);
    return false;
  }
  // b
  if (!geometry_msgs__msg__Point__init(&msg->b)) {
    test_custom_msg__msg__Triangle__fini(msg);
    return false;
  }
  // c
  if (!geometry_msgs__msg__Point__init(&msg->c)) {
    test_custom_msg__msg__Triangle__fini(msg);
    return false;
  }
  return true;
}

void
test_custom_msg__msg__Triangle__fini(test_custom_msg__msg__Triangle * msg)
{
  if (!msg) {
    return;
  }
  // a
  geometry_msgs__msg__Point__fini(&msg->a);
  // b
  geometry_msgs__msg__Point__fini(&msg->b);
  // c
  geometry_msgs__msg__Point__fini(&msg->c);
}

bool
test_custom_msg__msg__Triangle__are_equal(const test_custom_msg__msg__Triangle * lhs, const test_custom_msg__msg__Triangle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->a), &(rhs->a)))
  {
    return false;
  }
  // b
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->b), &(rhs->b)))
  {
    return false;
  }
  // c
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->c), &(rhs->c)))
  {
    return false;
  }
  return true;
}

bool
test_custom_msg__msg__Triangle__copy(
  const test_custom_msg__msg__Triangle * input,
  test_custom_msg__msg__Triangle * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  if (!geometry_msgs__msg__Point__copy(
      &(input->a), &(output->a)))
  {
    return false;
  }
  // b
  if (!geometry_msgs__msg__Point__copy(
      &(input->b), &(output->b)))
  {
    return false;
  }
  // c
  if (!geometry_msgs__msg__Point__copy(
      &(input->c), &(output->c)))
  {
    return false;
  }
  return true;
}

test_custom_msg__msg__Triangle *
test_custom_msg__msg__Triangle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_custom_msg__msg__Triangle * msg = (test_custom_msg__msg__Triangle *)allocator.allocate(sizeof(test_custom_msg__msg__Triangle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(test_custom_msg__msg__Triangle));
  bool success = test_custom_msg__msg__Triangle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
test_custom_msg__msg__Triangle__destroy(test_custom_msg__msg__Triangle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    test_custom_msg__msg__Triangle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
test_custom_msg__msg__Triangle__Sequence__init(test_custom_msg__msg__Triangle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_custom_msg__msg__Triangle * data = NULL;

  if (size) {
    data = (test_custom_msg__msg__Triangle *)allocator.zero_allocate(size, sizeof(test_custom_msg__msg__Triangle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = test_custom_msg__msg__Triangle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        test_custom_msg__msg__Triangle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
test_custom_msg__msg__Triangle__Sequence__fini(test_custom_msg__msg__Triangle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      test_custom_msg__msg__Triangle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

test_custom_msg__msg__Triangle__Sequence *
test_custom_msg__msg__Triangle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  test_custom_msg__msg__Triangle__Sequence * array = (test_custom_msg__msg__Triangle__Sequence *)allocator.allocate(sizeof(test_custom_msg__msg__Triangle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = test_custom_msg__msg__Triangle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
test_custom_msg__msg__Triangle__Sequence__destroy(test_custom_msg__msg__Triangle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    test_custom_msg__msg__Triangle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
test_custom_msg__msg__Triangle__Sequence__are_equal(const test_custom_msg__msg__Triangle__Sequence * lhs, const test_custom_msg__msg__Triangle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!test_custom_msg__msg__Triangle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
test_custom_msg__msg__Triangle__Sequence__copy(
  const test_custom_msg__msg__Triangle__Sequence * input,
  test_custom_msg__msg__Triangle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(test_custom_msg__msg__Triangle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    test_custom_msg__msg__Triangle * data =
      (test_custom_msg__msg__Triangle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!test_custom_msg__msg__Triangle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          test_custom_msg__msg__Triangle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!test_custom_msg__msg__Triangle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
