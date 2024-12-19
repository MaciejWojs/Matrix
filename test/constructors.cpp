#include "gtest/gtest.h"
#include "../Matrix.hpp"

TEST(MatrixConstructors, DefaultConstructor) {
    Matrix m;
    EXPECT_EQ(m.get_size(), 0);
    EXPECT_EQ(m.to_array(), nullptr);
}

TEST(MatrixConstructors, ConstructorWithSize) {
    int size = 2;
    Matrix m(size);
    EXPECT_EQ(m.get_size(), size);
    EXPECT_NE(m.to_array(), nullptr);
}

TEST(MatrixConstructors, ConstructorWithSizeAndArray) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m(size, array);
    EXPECT_EQ(m.get_size(), size);

    int* expected_array = m.to_array();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected_array[i], array[i]);
    }
}

TEST(MatrixConstructors, CopyingConstructor) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    Matrix m2(m1);

    EXPECT_EQ(m1, m2);
}