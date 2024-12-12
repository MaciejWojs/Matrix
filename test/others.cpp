#include <gtest/gtest.h>
#include "../Matrix.hpp"

TEST(MatrixCopyConstructor, MatrixEqualityAfterCopyConstructor) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1, m2);
}