#include <gtest/gtest.h>
#include "../Matrix.hpp"

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
TEST(MatrixPickRandom, MatrixPickRandomColumn) {
    const int size = 5;
    int i = (Matrix(size)).pick_Random_Column();
    EXPECT_GE(i, 0);
    EXPECT_LE(i, size - 1);
}
TEST(MatrixPickRandom, MatrixPickRandomRow) {
    const int size = 5;
    int i = (Matrix(size)).pick_Random_Row();
    EXPECT_GE(i, 0);
    EXPECT_LE(i, size - 1);
}
TEST(MatrixRandom, MatrixRandomWithAttribute) {
    const int size = 2;
    int array[size * size] = { 10, 20, 30, 40 };
    Matrix m(size, array);
    m.random(5);
    bool is_random = false;
    int* matrix = m.to_array();

    for (int i = 0; i < m.get_size(); i++) {
        if (matrix[i] > 0 && matrix[i] < 10) {
            is_random = true;
            break;
        }
    }
    EXPECT_EQ(is_random, true);
}