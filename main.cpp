#include <iostream>
#include "Matrix.hpp"
#include <random>
#include <fstream>

int main() {
    std::cout << "\n\n";

    const int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix matrix(size, array);
    // m.random();

    Matrix m2(matrix);

    std::cout << "Original Matrix 1:\n";
    matrix.print();
    std::cout << "Matrix 1 after adding 1 to all elements:\n";
    matrix += 1;
    matrix.print();
    std::cout << "Matrix 1 after subtracting 2 from all elements:\n";
    matrix -= 2;
    matrix.print();
    std::cout << "Matrix 1 after subtracting -20 from all elements:\n";
    matrix -= -20;
    matrix.print();
    std::cout << "Matrix 1 after multiplying by 2:\n";
    matrix *= 2;
    matrix.print();
    std::cout << "Matrix 1 transposed:\n";
    matrix.transpose();
    matrix.print();

    std::cout << "Matrix 2:\n";
    m2.print();

    return 0;
}