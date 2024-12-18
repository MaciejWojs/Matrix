#include <iostream>
#include "Matrix.hpp"
#include <random>
#include <fstream>

int main() {
    std::cout << "\n\n";

    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m(size, array);
    // m.random();

    Matrix m2(m);

    std::cout << "Matrix 1:\n";
    m.print();
    std::cout << "Matrix 1 transposed:\n";
    m.transpose();
    m.print();

    std::cout << "Matrix 2:\n";
    m2.print();

    return 0;
}