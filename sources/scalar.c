// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#include "scalar.h"

// sin(f), tan(f)
#include <math.h>

#if _DEBUG

  // fprintf, stderr
  #include <stdio.h>

  // exit, EXIT_FAILURE
  #include <stdlib.h>

  void
  idlib_debug_assert
    (
      bool expression_value,
      char const* file,
      int line,
      char const* expression_string
    )
  {
    if (!expression_value) {
      fprintf(stderr, "%s:%d: debug assertion `%s` failed\n", file, line, expression_string);
      exit(EXIT_FAILURE);
    }

  }

#endif // _DEBUG

idlib_f32
idlib_sin_f32
  (
    idlib_f32 operand
  )
{ return sinf(operand); }

idlib_f64
idlib_sin_f64
  (
    idlib_f64 operand
  )
{ return sin(operand); }

idlib_f32
idlib_tan_f32
  (
    idlib_f32 operand
  )
{ return tanf(operand); }

idlib_f64
idlib_tan_f64
  (
    idlib_f64 operand
  )
{ return tan(operand); }
