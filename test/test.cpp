#include <gtest/gtest.h>
#include <fstream>
#include "../Matrix.hpp"
#define FILENAME "matrix.txt"

void create_file() {
    int size = 2;
    int array[size * size] = { 1,2,3,4 };
    Matrix m(size, array);
    std::ofstream file(FILENAME);
    file << m;
}
TEST(MatrixFileOperations, MatrixEqualityAfterFileOperations) {
    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m1(size, array);
    std::ofstream file(FILENAME);
    file << m1;
    file.close();

    std::ifstream infile(FILENAME);
    Matrix m2(size);
    infile >> m2;
    infile.close();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            EXPECT_EQ(m1.show(i, j), m2.show(i, j));
        }
    }
}

TEST(MatrixFileOperations, MatrixInputOperator) {
    create_file();
    std::ifstream file(FILENAME);
    Matrix m(2);
    file >> m;
    EXPECT_EQ(m.show(0, 0), 1);
    EXPECT_EQ(m.show(0, 1), 2);
    EXPECT_EQ(m.show(1, 0), 3);
    EXPECT_EQ(m.show(1, 1), 4);
}

int main(int argc, char const* argv[]) {
    ::testing::InitGoogleTest(&argc, (char**)argv);
    return RUN_ALL_TESTS();
    return 0;
}
