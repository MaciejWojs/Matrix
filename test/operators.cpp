#include <gtest/gtest.h>
#include "../Matrix.hpp"

enum class Operation {
    Add,
    Multiply,
    Divide,
    Subtract
};

TEST(MatrixOperators, MatrixEquality) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(size, array);

    bool result = m1 == m2;

    bool expected = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (m1.show(i, j) != m2.show(i, j)) {
                expected = false;
                break;
            }
        }
    }
    EXPECT_EQ(result, expected);
}

TEST(MatrixArithmetic, MatrixAddition) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 2, 3, 4, 5 };
    Matrix expected(size, expected_array);

    m1 += 1;

    EXPECT_EQ(m1, expected);
}