// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#include "scalar.h"

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
