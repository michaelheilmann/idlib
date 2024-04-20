// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_MATRIX_4X4_H_INCLUDED)
#define IDLIB_MATRIX_4X4_H_INCLUDED

#include "configure.h"
#include "scalar.h"
// NULL
#include <stddef.h>
#include "vector_3.h"

// 'Windows.h', which is frequently included in Windows
// programs, defines the macros 'near' and 'far' causing
// an unintended substitution of names of parameters in
// 'matrix_4x4.h'.This prevents this substitution.
#if IDLIB_COMPILER_C == IDLIB_COMPILER_C_MSVC
	#pragma push_macro("near")
	#undef near
	#pragma push_macro("far")
	#undef far
#endif

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
/// | 1 | 0 | 0 | x |
/// | 0 | 1 | 0 | y |
/// | 0 | 0 | 1 | z |
/// | 0 | 0 | 0 | 1 |
/// @endcode
static inline void
idlib_matrix_4x4_f32_set_translation
	(
		idlib_matrix_4x4_f32* target,
		idlib_vector_3_f32* operand
	);

/// @since 1.0
/// @brief Assign an idlib_matrix_4x4_f32 object the values of a rotation matrix.
/// @details The rotation matrix is a counter-clockwise rotation around the x-axis by the specified number of degrees.
/// @param m A pointer to this matrix.
/// @param a The angle of rotation, in degrees.
/// @remarks
/// @code
/// | 1 | 0 |  0 | 0 |
/// | 0 | c | -s | 0 |
/// | 0 | s |  c | 0 |
/// | 0 | 0 |  0 | 1 |
/// @endcode
static inline void
idlib_matrix_4x4_f32_set_rotation_x
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
	);

/// @since 1.0
/// @brief Assign this matrix the values of transformation matrix representing
/// a counter-clockwise rotation around the y-axis by the specified number of degrees.
/// @param m A pointer to this matrix.
/// @param a The angle of rotation, in degrees.
/// @remarks
/// @code
/// |  c | 0 | s | 0 |
/// |  0 | 1 | 0 | 0 |
/// | -s | 0 | c | 0 |
/// |  0 | 0 | 0 | 1 |
/// @endcode
static inline void
idlib_matrix_4x4_f32_set_rotation_y
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
	);

/// @since 1.0
/// @brief Assign this matrix the values of transformation matrix representing
/// a counter-clockwise rotation around the z-axis by the specified number of degrees.
/// @param target A pointer to this matrix.
/// @param operand The angle of rotation, in degrees.
/// @remarks
/// @code
/// | c | -s | 0 | 0 |
/// | s |  c | 0 | 0 |
/// | 0 |  0 | 1 | 0 |
/// | 0 |  0 | 0 | 1 |
/// @endcode
static inline void
idlib_matrix_4x4_f32_set_rotation_z
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
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

static inline void
idlib_matrix_4x4_f32_set_rotation_x
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
	)
{
	idlib_f32 a = idlib_deg_to_rad_f32(operand);
	idlib_f32 c = idlib_cos_f32(a);
	idlib_f32 s = idlib_sin_f32(a);

	// First column.
	target->e[0][0] = 1.f;
	target->e[1][0] = 0.f;
	target->e[2][0] = 0.f;
	target->e[3][0] = 0.f;

	// Second column.
	target->e[0][1] = 0.f;
	target->e[1][1] = c;
	target->e[2][1] = s;
	target->e[3][1] = 0.f;

	// Third column.
	target->e[0][2] = 0.f;
	target->e[1][2] = -s;
	target->e[2][2] = c;
	target->e[3][2] = 0.f;

	// Fourth column.
	target->e[0][3] = 0.f;
	target->e[1][3] = 0.f;
	target->e[2][3] = 0.f;
	target->e[3][3] = 1.f;
}

static inline void
idlib_matrix_4x4_f32_set_rotation_y
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
	)
{
	idlib_f32 a = idlib_deg_to_rad_f32(operand);
	idlib_f32 c = idlib_cos_f32(a);
	idlib_f32 s = idlib_sin_f32(a);

	// First column.
	target->e[0][0] = c;
	target->e[1][0] = 0.f;
	target->e[2][0] = -s;
	target->e[3][0] = 0.f;

	// Second column.
	target->e[0][1] = 0.f;
	target->e[1][1] = 1.f;
	target->e[2][1] = 0.f;
	target->e[3][1] = 0.f;

	// Third column.
	target->e[0][2] = s;
	target->e[1][2] = 0.f;
	target->e[2][2] = c;
	target->e[3][2] = 0.f;

	// Fourth column.
	target->e[0][3] = 0.f;
	target->e[1][3] = 0.f;
	target->e[2][3] = 0.f;
	target->e[3][3] = 1.f;
}

static inline void
idlib_matrix_4x4_f32_set_rotation_z
	(
		idlib_matrix_4x4_f32* target,
		idlib_f32 operand
	)
{
	idlib_f32 a = idlib_deg_to_rad_f32(operand);
	idlib_f32 c = idlib_cos_f32(a);
	idlib_f32 s = idlib_sin_f32(a);

	// First column.
	target->e[0][0] = c;
	target->e[1][0] = s;
	target->e[2][0] = 0.f;
	target->e[3][0] = 0.f;

	// Second column.
	target->e[0][1] = -s;
	target->e[1][1] = c;
	target->e[2][1] = 0.f;
	target->e[3][1] = 0.f;

	// Third column.
	target->e[0][2] = 0.f;
	target->e[1][2] = 0.f;
	target->e[2][2] = 1.f;
	target->e[3][2] = 0.f;

	// Fourth column.
	target->e[0][3] = 0.f;
	target->e[1][3] = 0.f;
	target->e[2][3] = 0.f;
	target->e[3][3] = 1.f;
}

#if IDLIB_COMPILER_C == IDLIB_COMPILER_C_MSVC
	#pragma pop_macro("near")
	#pragma pop_macro("far")
#endif

#endif // IDLIB_MATRIX_4X4_H_INCLUDED
