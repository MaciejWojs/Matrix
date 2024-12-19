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


    std::cout << "\nMatrix 1 after randomizing with attribute 5:\n";
    matrix.random(5);

    const int s_size = 3;
    int s_array[s_size * s_size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix s(s_size, s_array);
    std::cout << "\nNew Matrix\n";
    s.print();

    s.diagonal(array);

    std::cout << "\nMatrix after filling diagonal with array:\n";

    s.print();

    s.diagonal_k(array, 1);

    std::cout << "\nMatrix after filling diagonal with array and k = 1:\n";

    s.print();

    s.column(1, array);

    s.print();

    s.row(2, array);

    s.print();
    return 0;
}