// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_VECTOR_2_H_INCLUDED)
#define IDLIB_VECTOR_2_H_INCLUDED

#include "scalar.h"
// NULL
#include <stddef.h>

/// @since 1.0
/// A two component vector with elements of type idlib_f32.
typedef struct idlib_vector_2_f23 {
  idlib_f32 e[2];
} idlib_vector_2_f32;

/// @since 0.1
/// Assign an idlib_vector_2_f32 object the specified scalar values.
/// @param target A pointer to the idlib_vector_2_f32 object.
/// @param x, y The scalar values.
static inline void
idlib_vector_2_f32_set
  (
    idlib_vector_2_f32* target,
    idlib_f32 x,
    idlib_f32 y
  );

/// @since 0.1
/// Assign an idlib_vector_2_f32 object the values of an zero vector.
/// @param target A pointer to the idlib_vector_2_f32 object.
static inline void
idlib_vector_2_f32_set_zero
  (
    idlib_vector_2_f32* target
  );

/// @since 1.0
/// Compute the sum of two idlib_vector_2_f32 objects and assign the result to a idlib_vector_2_f32 object.
/// @param target The idlib_vector_2_f32 object to assign the result to.
/// @param operand1 The idlib_vector_2_f32 object that is the augend (aka first term).
/// @param operand2 The idlib_vector_2_f32 object that is the addend (aka second term).
/// @remarks @a target, @a operand1, and @a operand2 all may refer to the same idlib_vector_2_f32 object.
static inline void
idlib_vector_2_f32_add
  (
    idlib_vector_2_f32* target,
    idlib_vector_2_f32* operand1,
    idlib_vector_2_f32* operand2
  );

/// @since 1.0
/// Compute the difference of two idlib_vector_2_f32 objects and assign the result to a idlib_vector_2_f32 object.
/// @param target The idlib_vector_2_f32 object to assign the result to.
/// @param operand1 The idlib_vector_2_f32 object that is the minuend (aka first term).
/// @param operand2 The idlib_vector_2_f32 object that is the subtrahend (aka second term).
/// @remarks @a target, @a operand1, and @a operand2 all may refer to the same idlib_vector_2_f32 object.
static inline void
idlib_vector_2_f32_subtract
  (
    idlib_vector_2_f32* target,
    idlib_vector_2_f32* operand1,
    idlib_vector_2_f32* operand2
  );

/// @since 1.0
/// Get if two idlib_vector_2_f32 objects are equal.
/// @param operand1 The first operand.
/// @param operand2 The second operand.
/// @return @a true if the idlib_f32 objects are equal. @a false otherwise.
static inline bool
idlib_vector_2_are_equal
  (
    idlib_vector_2_f32 const* operand1,
    idlib_vector_2_f32 const* operand2
  );

static inline void
idlib_vector_2_f32_set
  (
    idlib_vector_2_f32* target,
    idlib_f32 x,
    idlib_f32 y
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);

  target->e[0] = x;
  target->e[1] = y;
}

static inline void
idlib_vector_2_f32_set_zero
  (
    idlib_vector_2_f32* target
  )
{ idlib_vector_2_f32_set(target, 0.f, 0.f); }

static inline void
idlib_vector_2_f32_add
  (
    idlib_vector_2_f32* target,
    idlib_vector_2_f32* operand1,
    idlib_vector_2_f32* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  target->e[0] = operand1->e[0] + operand2->e[0];
  target->e[1] = operand1->e[1] + operand2->e[1];
}

static inline void
idlib_vector_2_f32_subtract
  (
    idlib_vector_2_f32* target,
    idlib_vector_2_f32* operand1,
    idlib_vector_2_f32* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  target->e[0] = operand1->e[0] - operand2->e[0];
  target->e[1] = operand1->e[1] - operand2->e[1];
}

static inline bool
idlib_vector_2_are_equal
  (
    idlib_vector_2_f32 const* operand1,
    idlib_vector_2_f32 const* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  if (operand1 == operand2) {
    return true;
  }
  return operand1->e[0] == operand2->e[0]
      && operand1->e[1] == operand2->e[1];
}

#endif // IDLIB_VECTOR_2_H_INCLUDED
