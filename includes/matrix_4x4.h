// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_MATRIX_4X4_H_INCLUDED)
#define IDLIB_MATRIX_4X4_H_INCLUDED

#include "scalar.h"
// NULL
#include <stddef.h>
#include "vector_3.h"

/// @since 1.0
/// @brief A row-major matrix with elements of type idlib_f32.
/// Row major means: The first index denotes the row, the second index denotes the column.
typedef struct idlib_matrix_4x4_f32 {
	idlib_f32 e[4][4];
} idlib_matrix_4x4_f32;

/// @since 0.1
/// @brief Assign an idlib_matrix_4x4_f32 object the values of an identity matrix.
/// @param target Pointer to the idlib_matrix_4x4_f32 object.
static inline void
idlib_matrix_4x4_f32_set_identity
	(
		idlib_matrix_4x4_f32* target
	);

/// @since 1.0
/// @brief Assign an idlib_matrix_4x4_f32 object the values of a translation matrix.
/// @param target Pointer to the idlib_matrix_4x4_f32 object.
/// @param operand Pointer to the idlib_vector_3_f32 object representing the translation vector.
/// @remarks
/// @code
/// 1 0 0 x
/// 0 1 0 y
/// 0 0 1 z
/// 0 0 0 1
/// @endcode
static inline void
idlib_matrix_4x4_f32_set_translation
	(
		idlib_matrix_4x4_f32* target,
		idlib_vector_3_f32* operand
	);

static inline void
idlib_matrix_4x4_f32_set_identity
	(
		idlib_matrix_4x4_f32* target
	)
{
	IDLIB_DEBUG_ASSERT(NULL != target);

	// first column
	target->e[0][0] = 1.f;
	target->e[1][0] = 0.f;
	target->e[2][0] = 0.f;
	target->e[3][0] = 0.f;

	// second column
	target->e[0][1] = 0.f;
	target->e[1][1] = 1.f;
	target->e[2][1] = 0.f;
	target->e[3][1] = 0.f;

	// third column
	target->e[0][2] = 0.f;
	target->e[1][2] = 0.f;
	target->e[2][2] = 1.0f;
	target->e[3][2] = 0.f;

	// fourth column
	target->e[0][3] = 0.f;
	target->e[1][3] = 0.f;
	target->e[2][3] = 1.0f;
	target->e[2][3] = 0.f;
}

static inline void
idlib_matrix_4x4_f32_set_translation
	(
		idlib_matrix_4x4_f32* target,
		idlib_vector_3_f32* operand
	)
{
	// first column
	target->e[0][0] = 1.f;
	target->e[1][0] = 0.f;
	target->e[2][0] = 0.f;
	target->e[3][0] = 0.f;

	// second column
	target->e[0][1] = 0.f;
	target->e[1][1] = 1.f;
	target->e[2][1] = 0.f;
	target->e[3][1] = 0.f;

	// third column
	target->e[0][2] = 0.f;
	target->e[1][2] = 0.f;
	target->e[2][2] = 1.f;
	target->e[3][2] = 0.f;

	// column #4
	target->e[0][3] = operand->e[0];
	target->e[1][3] = operand->e[1];
	target->e[2][3] = operand->e[2];
	target->e[3][3] = 1.f;
}

#endif // IDLIB_MATRIX_4X4_H_INCLUDED
