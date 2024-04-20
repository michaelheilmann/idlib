// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_H_INCLUDED)
#define IDLIB_H_INCLUDED

#include "scalar.h"
#include "version.h"
#include <assert.h>

/// @since 1.0
/// A row-major matrix with elements of type idlib_f32.
/// Row major means: The first index denotes the row, the second index denotes the column.
typedef struct idlib_matrix_4x4_f32 {
	idlib_f32 e[4][4];
} idlib_matrix_4x4_f32;

/// @since 0.1
/// Assign an idlib_matrix_4x4_f32 object the values of an identity matrix.
/// @param m A pointer to the idlib_matrix_4x4_f32 object.
static inline void
idlib_matrix_4x4_f32_set_identity
	(
		idlib_matrix_4x4_f32* a
	)
{
	assert(NULL != a);
	
	// first column
	a->e[0][0] = 1.f;
	a->e[1][0] = 0.f;
	a->e[2][0] = 0.f;
	a->e[3][0] = 0.f;
	
	// second column
	a->e[0][1] = 0.f;
	a->e[1][1] = 1.f;
	a->e[2][1] = 0.f;
	a->e[3][1] = 0.f;
	
	// third column
	a->e[0][2] = 0.f;
	a->e[1][2] = 0.f;
	a->e[2][2] = 1.0f;
	a->e[3][2] = 0.f;
	
	// fourth column
	a->e[0][3] = 0.f;
	a->e[1][3] = 0.f;
	a->e[2][3] = 1.0f;
	a->e[2][3] = 0.f;
}

/// @since 1.0
/// A two component vector with elements of type idlib_f32.
typedef struct idlib_vector_2_f23 {
	idlib_f32 e[2];
} idlib_vector_2_f32;

/// @since 0.1
/// Assign an idlib_vector_2_f32 object the values of an zero vector.
/// @param m A pointer to the idlib_vector_2_f32 object.
static inline void
idlib_vector_2_f32_set_zero
	(
		idlib_vector_2_f32* a
	)
{
	assert(NULL != a);
	
	a->e[0] = 0.f;
	a->e[1] = 0.f;
}

/// @since 0.1
/// A three component vector with elements of type idlib_f32.
typedef struct idlib_vector_3_f32 {
	idlib_f32 e[3];
} idlib_vector_3_f32;

/// @since 0.1
/// Assign an idlib_vector32_f32 object the values of an zero vector.
/// @param m A pointer to the idlib_vector_3_f32 object.
static inline void
idlib_vector_3_f32_set_zero
	(
		idlib_vector_3_f32* a
	)
{
	assert(NULL != a);
	
	a->e[0] = 0.f;
	a->e[1] = 0.f;
	a->e[2] = 0.f;
}

#endif // IDLIB_H_INCLUDED
