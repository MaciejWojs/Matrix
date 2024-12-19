#include <gtest/gtest.h>
#include "../Matrix.hpp"

TEST(MatrixOperators, MatrixEquality) {
    const int size = 2;
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

TEST(MatrixArithmetic, MatrixAdditionPostitive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 2, 3, 4, 5 };
    Matrix expected(size, expected_array);

    m1 += 1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixAdditionNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 0, 1, 2, 3 };
    Matrix expected(size, expected_array);

    m1 += -1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixAdditionZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    m1 += 0;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixSubstractionPostitive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 0, 1, 2, 3 };
    Matrix expected(size, expected_array);

    m1 -= 1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixSubstractionNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 2, 3, 4, 5 };
    Matrix expected(size, expected_array);

    m1 -= -1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixSubstractionZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    m1 -= 0;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixMultiplicationPostitive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 2, 4, 6, 8 };
    Matrix expected(size, expected_array);

    m1 *= 2;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixMultiplicationNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { -2, -4, -6, -8 };
    Matrix expected(size, expected_array);

    m1 *= -2;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixMultiplicationZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 0,0,0,0 };
    Matrix expected(size, expected_array);

    m1 *= 0;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixMultiplicationNoChanges) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    Matrix expected(m1);

    m1 *= 1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixDivisionPostitive) {
    const int size = 2;
    int array[size * size] = { 2, 4, 6, 8 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 1, 2, 3, 4 };
    Matrix expected(size, expected_array);

    m1 /= 2;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixDivisionNegative) {
    const int size = 2;
    int array[size * size] = { -2, -4, -6, -8 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 1, 2, 3, 4 };
    Matrix expected(size, expected_array);

    m1 /= -2;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixDivisionNegativeOpposite) {
    const int size = 2;
    int array[size * size] = { 2, 4, 6, 8 };
    Matrix m1(size, array);

    int expected_array[size * size] = { -1, -2, -3, -4 };
    Matrix expected(size, expected_array);

    m1 /= -2;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixDivisionZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    EXPECT_THROW(m1 /= 0, std::invalid_argument);
}

TEST(MatrixArithmetic, MatrixDivisionNoChanges) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    Matrix expected(m1);

    m1 /= 1;

    EXPECT_EQ(m1, expected);
}

TEST(MatrixArithmetic, MatrixPostIncrement) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    expected += 1;
    EXPECT_EQ(m1++, expected);
}

TEST(MatrixArithmetic, MatrixPreIncrement) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    expected += 1;
    EXPECT_EQ(++m1, expected);
}

TEST(MatrixArithmetic, MatrixPostDecrement) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    expected -= 1;
    EXPECT_EQ(m1--, expected);
}

TEST(MatrixArithmetic, MatrixPreDecrement) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix expected(m1);

    expected -= 1;
    EXPECT_EQ(--m1, expected);
}

TEST(MatrixArithmetic, AdditionMatrixPositive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 + 5, m2 += 5);
}

TEST(MatrixArithmetic, AdditionMatrixPositiveOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(5 + m1, m2 += 5);
}

TEST(MatrixArithmetic, AdditionMatrixNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 + -5, m2 += -5);
}

TEST(MatrixArithmetic, AdditionMatrixNegativeOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(-5 + m1, m2 -= 5);
}

TEST(MatrixArithmetic, SubstractionMatrixPositive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 - 5, m2 -= 5);
}

TEST(MatrixArithmetic, SubstractionMatrixPositiveOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(5 - m1, m2 -= 5);
}

TEST(MatrixArithmetic, SubstractionMatrixNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 - -5, m2 += 5);
}

TEST(MatrixArithmetic, SubstractionMatrixNegativeOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(-5 - m1, m2 += 5);
}

TEST(MatrixArithmetic, MultiplicationMatrixPositive) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 * 2, m2 *= 2);
}

TEST(MatrixArithmetic, MultiplicationMatrixPositiveOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(2 * m1, m2 *= 2);
}

TEST(MatrixArithmetic, MultiplicationMatrixNegative) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 * -2, m2 *= -2);
}

TEST(MatrixArithmetic, MultiplicationMatrixNegativeOpposite) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(-2 * m1, m2 *= -2);
}

TEST(MatrixArithmetic, MultiplicationMatrixZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    int expected_array[size * size] = { 0, 0, 0, 0 };
    Matrix expected(size, expected_array);

    EXPECT_EQ(m1 * 0, expected);
}

TEST(MatrixArithmetic, MultiplicationMatrixNoChanges) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    Matrix expected(m1);

    EXPECT_EQ(m1 * 1, expected);
}

TEST(MatrixArithmetic, DivisionMatrixPositive) {
    const int size = 2;
    int array[size * size] = { 2, 4, 6, 8 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 / 2, m2 /= 2);
}

TEST(MatrixArithmetic, DivisionMatrixPositiveOpposite) {
    const int size = 2;
    int array[size * size] = { 2, 4, 6, 8 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(2 / m1, m2 /= 2);
}

TEST(MatrixArithmetic, DivisionMatrixNegative) {
    const int size = 2;
    int array[size * size] = { -2, -4, -6, -8 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1 / -2, m2 /= -2);
}

TEST(MatrixArithmetic, DivisionMatrixNegativeOpposite) {
    const int size = 2;
    int array[size * size] = { 2, 4, 6, 8 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(-2 / m1, m2 /= -2);
}

TEST(MatrixArithmetic, DivisionMatrixZero) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    EXPECT_THROW(m1 / 0, std::invalid_argument);
}

TEST(MatrixArithmetic, DivisionMatrixNoChanges) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);

    Matrix expected(m1);

    EXPECT_EQ(m1 / 1, expected);
}

TEST(MatrixArithmetic, MatrixGreaterThan) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    int array2[size * size] = { 2,3,4,5 };
    Matrix m1(size, array);
    Matrix m2(size, array2);

    EXPECT_FALSE(m1 > m2);
    EXPECT_TRUE(m2 > m1);
}

TEST(MatrixArithmetic, MatrixLessThan) {
    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    int array2[size * size] = { 2,3,4,5 };
    Matrix m1(size, array);
    Matrix m2(size, array2);

    EXPECT_TRUE(m1 < m2);
    EXPECT_FALSE(m2 < m1);
}

TEST(MatrixArithmetic, MatrixGreaterThanDifferentSizes) {
    const int size = 2;
    const int size2 = size + 1;
    int array[size * size] = { 1, 2, 3, 4 };
    int array2[size2 * size2] = { 1,2,3,4,5,6,7,8,9 };
    Matrix m1(size, array);
    Matrix m2(size2, array2);

    EXPECT_THROW(m1 < m2, std::invalid_argument);
}

TEST(MatrixArithmetic, MatrixLessThanDifferentSizes) {
    const int size = 2;
    const int size2 = size + 1;
    int array[size * size] = { 1, 2, 3, 4 };
    int array2[size2 * size2] = { 1,2,3,4,5,6,7,8,9 };
    Matrix m1(size, array);
    Matrix m2(size2, array2);

    EXPECT_THROW(m1 < m2, std::invalid_argument);
}