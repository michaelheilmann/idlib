// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_SCALAR_H_INCLUDED)
#define IDLIB_SCALAR_H_INCLUDED

/// @since 1.0
/// Alias for float.
typedef float idlib_f32;

/// @since 1.0
/// Alias for double.
typedef double idlib_f64;

#include <stdbool.h>

#if _DEBUG
  
  void
  idlib_debug_assert
    (
      bool expression_value,
      char const* file,
      int line,
      char const* expression_string
    );

  #define IDLIB_DEBUG_ASSERT(expression) \
    idlib_debug_assert(expression, __FILE__, __LINE__, #expression);

#else

  #define IDLIB_DEBUG_ASSERT(expression)

#endif // _DEBUG

/**
 * @since 1.0
 * Symbolic constant for the idlib_f32 representation of Pi.
 */
#define IDLIB_PI_F32 3.1415926f

/** 
 * @since 1.0
 * Symbolic constant for the idlib_f64 representation of Pi.
 */
#define IDLIB_PI_F64 3.1415926

/** 
 * @since 1.0
 * Convert an angle in degrees into the corresponding angle in radians.
 * @param operand The angle in degrees.
 * @return The corresponding angle in radians.
 */
static inline idlib_f32
idlib_deg_to_rad_f32
  (
    idlib_f32 x
  )
{ return (x / 180.f) * IDLIB_PI_F32; }

/** 
 * @since 1.0
 * Convert an angle in degrees into the corresponding angle in radians.
 * @param operand The angle in degrees.
 * @return The corresponding angle in radians.
 */
static inline idlib_f64
idlib_deg_to_rad_f64
  (
    idlib_f64 operand
  )
{ return (operand / 180.) * IDLIB_PI_F64; }

/**
 * @since 1.0
 * Compute the cosine.
 * @param operand An angle in radians.
 * @return The cosine of the angle.
 */
idlib_f32
idlib_cos_f32
  (
    idlib_f32 operand
  );

/**
 * @since 1.0
 * Compute the cosine.
 * @param operand An angle in radians.
 * @return The cosine of the angle.
 */
idlib_f64
idlib_cos_f64
  (
    idlib_f64 operand
  );

/**
 * @since 1.0
 * Compute the sine.
 * @param operand An angle in radians.
 * @return The sine of the angle.
 */
idlib_f32
idlib_sin_f32
  (
    idlib_f32 operand
  );

/**
 * @since 1.0
 * Compute the sine.
 * @param operand An angle in radians.
 * @return The sine of the angle.
 */
idlib_f64
idlib_sin_f64
  (
    idlib_f64 operand
  );

/**
 * @since 1.0
 * Compute the tangens.
 * @param operand An angle in radians.
 * @return The tangens of the angle.
 */
idlib_f32
idlib_tan_f32
  (
    idlib_f32 operand
  );

/**
 * @since 1.0
 * Compute the tangens.
 * @param operand An angle in radians.
 * @return The tangens of the angle.
 */
idlib_f64
idlib_tan_f64
  (
    idlib_f64 operand
  );

#endif // IDLIB_SCALAR_H_INCLUDED
