// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from test_custom_srv:srv/CircleSquare.idl
// generated code does not contain a copyright notice

#ifndef TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__FUNCTIONS_H_
#define TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "test_custom_srv/msg/rosidl_generator_c__visibility_control.h"

#include "test_custom_srv/srv/detail/circle_square__struct.h"

/// Initialize srv/CircleSquare message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * test_custom_srv__srv__CircleSquare_Request
 * )) before or use
 * test_custom_srv__srv__CircleSquare_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__init(test_custom_srv__srv__CircleSquare_Request * msg);

/// Finalize srv/CircleSquare message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Request__fini(test_custom_srv__srv__CircleSquare_Request * msg);

/// Create srv/CircleSquare message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * test_custom_srv__srv__CircleSquare_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
test_custom_srv__srv__CircleSquare_Request *
test_custom_srv__srv__CircleSquare_Request__create();

/// Destroy srv/CircleSquare message.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Request__destroy(test_custom_srv__srv__CircleSquare_Request * msg);

/// Check for srv/CircleSquare message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__are_equal(const test_custom_srv__srv__CircleSquare_Request * lhs, const test_custom_srv__srv__CircleSquare_Request * rhs);

/// Copy a srv/CircleSquare message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__copy(
  const test_custom_srv__srv__CircleSquare_Request * input,
  test_custom_srv__srv__CircleSquare_Request * output);

/// Initialize array of srv/CircleSquare messages.
/**
 * It allocates the memory for the number of elements and calls
 * test_custom_srv__srv__CircleSquare_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__Sequence__init(test_custom_srv__srv__CircleSquare_Request__Sequence * array, size_t size);

/// Finalize array of srv/CircleSquare messages.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Request__Sequence__fini(test_custom_srv__srv__CircleSquare_Request__Sequence * array);

/// Create array of srv/CircleSquare messages.
/**
 * It allocates the memory for the array and calls
 * test_custom_srv__srv__CircleSquare_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
test_custom_srv__srv__CircleSquare_Request__Sequence *
test_custom_srv__srv__CircleSquare_Request__Sequence__create(size_t size);

/// Destroy array of srv/CircleSquare messages.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Request__Sequence__destroy(test_custom_srv__srv__CircleSquare_Request__Sequence * array);

/// Check for srv/CircleSquare message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__Sequence__are_equal(const test_custom_srv__srv__CircleSquare_Request__Sequence * lhs, const test_custom_srv__srv__CircleSquare_Request__Sequence * rhs);

/// Copy an array of srv/CircleSquare messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Request__Sequence__copy(
  const test_custom_srv__srv__CircleSquare_Request__Sequence * input,
  test_custom_srv__srv__CircleSquare_Request__Sequence * output);

/// Initialize srv/CircleSquare message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * test_custom_srv__srv__CircleSquare_Response
 * )) before or use
 * test_custom_srv__srv__CircleSquare_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__init(test_custom_srv__srv__CircleSquare_Response * msg);

/// Finalize srv/CircleSquare message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Response__fini(test_custom_srv__srv__CircleSquare_Response * msg);

/// Create srv/CircleSquare message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * test_custom_srv__srv__CircleSquare_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
test_custom_srv__srv__CircleSquare_Response *
test_custom_srv__srv__CircleSquare_Response__create();

/// Destroy srv/CircleSquare message.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Response__destroy(test_custom_srv__srv__CircleSquare_Response * msg);

/// Check for srv/CircleSquare message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__are_equal(const test_custom_srv__srv__CircleSquare_Response * lhs, const test_custom_srv__srv__CircleSquare_Response * rhs);

/// Copy a srv/CircleSquare message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__copy(
  const test_custom_srv__srv__CircleSquare_Response * input,
  test_custom_srv__srv__CircleSquare_Response * output);

/// Initialize array of srv/CircleSquare messages.
/**
 * It allocates the memory for the number of elements and calls
 * test_custom_srv__srv__CircleSquare_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__Sequence__init(test_custom_srv__srv__CircleSquare_Response__Sequence * array, size_t size);

/// Finalize array of srv/CircleSquare messages.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Response__Sequence__fini(test_custom_srv__srv__CircleSquare_Response__Sequence * array);

/// Create array of srv/CircleSquare messages.
/**
 * It allocates the memory for the array and calls
 * test_custom_srv__srv__CircleSquare_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
test_custom_srv__srv__CircleSquare_Response__Sequence *
test_custom_srv__srv__CircleSquare_Response__Sequence__create(size_t size);

/// Destroy array of srv/CircleSquare messages.
/**
 * It calls
 * test_custom_srv__srv__CircleSquare_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
void
test_custom_srv__srv__CircleSquare_Response__Sequence__destroy(test_custom_srv__srv__CircleSquare_Response__Sequence * array);

/// Check for srv/CircleSquare message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__Sequence__are_equal(const test_custom_srv__srv__CircleSquare_Response__Sequence * lhs, const test_custom_srv__srv__CircleSquare_Response__Sequence * rhs);

/// Copy an array of srv/CircleSquare messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_test_custom_srv
bool
test_custom_srv__srv__CircleSquare_Response__Sequence__copy(
  const test_custom_srv__srv__CircleSquare_Response__Sequence * input,
  test_custom_srv__srv__CircleSquare_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUSTOM_SRV__SRV__DETAIL__CIRCLE_SQUARE__FUNCTIONS_H_