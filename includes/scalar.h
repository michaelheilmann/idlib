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
 * @param a The angle in degrees.
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
 * @param a The angle in degrees.
 * @return The corresponding angle in radians.
 */
static inline idlib_f64
idlib_deg_to_rad_f64
  (
    idlib_f64 x
  )
{ return (x / 180.) * IDLIB_PI_F64; }

#endif // IDLIB_SCALAR_H_INCLUDED
