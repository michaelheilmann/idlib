// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_COLOR_H_INCLUDED)
#define IDLIB_COLOR_H_INCLUDED

#include "scalar.h"

/**
 * @since 1.2
 * @brief
 * Representation of a color consisting of three components, red, green, and blue.
 * The component values are layed out consecutively in memory and are of type idlib_u8 where
 * 0 denotes the minimum intensity and 255 denotes the maximum intensity.
 */
typedef struct idlib_color_3_u8 {
	union {
		struct {
			uint8_t r, g, b;
		};
		uint8_t components[3];
	};
} idlib_color_3_u8;

/** 
 * @since 1.2
 * @brief Assign an idlib_color_3_u8 object the specified component values.
 * @param target Pointer to the idlib_matrix_4x4_f32 object.
 * @param r The value to be assigned to the "red" component.
 * @param g The value to be assigned to the "green" component.
 * @param b The value to be assigned to the "blue" component.
 */
static inline void
idlib_color_3_u8_set
	(
		idlib_color_3_u8 *target,
		idlib_u8 r,
		idlib_u8 g,
		idlib_u8 b
	);

static inline void
idlib_color_3_u8_set
	(
		idlib_color_3_u8 *target,
		idlib_u8 r,
		idlib_u8 g,
		idlib_u8 b
	)
{
	IDLIB_DEBUG_ASSERT(NULL != target);
	target->r = r;
	target->g = g;
	target->b = b;
}

#endif // IDLIB_COLOR_H_INCLUDED
