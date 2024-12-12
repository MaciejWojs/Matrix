#include <iostream>
#include "Matrix.hpp"
#include <random>
#include <fstream>

int main() {
    std::cout << "\n\n";

    int size = 2;
    int array[size * size] = { 1, 2, 3, 4 };
    Matrix m(size, array);

    int array2[size * size] = { 1, 2, 3, 4 };
    Matrix m2(size, array2);

    std::cout << "Matrix 1:\n";
    m.print();
    std::cout << "Matrix 2:\n";
    m2.print();


    if (m == m2) {
        std::cout << "Matrix 1 is equal to Matrix 2\n";
    } else {
        std::cout << "Matrix 1 is not equal to Matrix 2\n";
    }

    return 0;
}