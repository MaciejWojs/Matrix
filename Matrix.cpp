#include <iostream>
#include "Matrix.hpp"

void Matrix::print() {
    std::cout << *this << std::endl;
}

Matrix& Matrix::insert(int row, int column, int value) {
    this->array[row][column] = value;
    return *this;
}

int Matrix::show(int row, int column) {
    return this->array[row][column];
}
