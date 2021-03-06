///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Idlib: A C++ utility library
// Copyright (C) 2017-2018 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "gtest/gtest.h"
#include "idlib/math.hpp"

namespace idlib::tests {

TEST(matrix_4s_4s_test, transpose)
{
    using M = idlib::matrix<single, 4, 4>;
    std::vector<M> matrices =
    { 
        //
        identity<M>(),
        //
        zero<M>(),
        //
        rotation_matrix_x(angle<single, degrees>(0.0f)),
        //
        rotation_matrix_x(angle<single, degrees>(90.0f)),
        //
        rotation_matrix_x(angle<single, degrees>(180.0f)),
        //
        rotation_matrix_x(angle<single, degrees>(270.0f)),
        //
        rotation_matrix_y(angle<single, degrees>(0.0f)),
        //
        rotation_matrix_y(angle<single, degrees>(90.0f)),
        //
        rotation_matrix_y(angle<single, degrees>(180.0f)),
        //
        rotation_matrix_y(angle<single, degrees>(270.0f)),
        //
        rotation_matrix_z(angle<single, degrees>(0.0f)),
        //
        rotation_matrix_z(angle<single, degrees>(90.0f)),
        //
        rotation_matrix_z(angle<single, degrees>(180.0f)),
        //
        rotation_matrix_z(angle<single, degrees>(270.0f)),
        //
        translation_matrix({ 1.0f, 0.0f, 0.0f }),
        //
        translation_matrix({ 0.0f, 1.0f, 0.0f }),
        //
        translation_matrix({ 0.0f, 0.0f, 1.0f }),
    };
    for (const auto& matrix : matrices)
    {
        ASSERT_EQ(transpose(transpose(matrix)), matrix);
    }
}

} // namespace idlib::tests
