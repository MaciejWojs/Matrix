#include <gtest/gtest.h>
#include "../Matrix.hpp"

TEST(MatrixCopyConstructor, MatrixEqualityAfterCopyConstructor) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1, m2);
}

TEST(MatrixTranspose, MatrixTranspose) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    int array_transposed[size * size] = { 1, 3, 2, 4 };
    Matrix m(size, array);
    m.transpose();

    Matrix expected_matrix(size, array_transposed);
    EXPECT_EQ(m, expected_matrix);
}

TEST(MatrixTranspose, MatrixTransposeDoubled) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m(size, array);
    Matrix expected_matrix(m);
    m.transpose();
    m.transpose();

    EXPECT_EQ(m, expected_matrix);
}