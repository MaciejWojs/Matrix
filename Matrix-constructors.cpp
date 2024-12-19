#include <iostream>
#include "Matrix.hpp"
#include <cmath>

Matrix::Matrix() : Matrix({}) {}

Matrix::Matrix(int size) : size(size), array(nullptr) {
    if (size > 0) {
        allocate(size);
    }
}

Matrix::Matrix(int size, int* _array) : Matrix(size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->array[i][j] = _array[i * size + j];
        }
    }
}

Matrix::Matrix(Matrix& matrix) : Matrix(matrix.size) {
    for (int i = 0; i < matrix.size; i++) {
        for (int j = 0; j < matrix.size; j++) {
            this->array[i][j] = matrix.array[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocate();
}

Matrix& Matrix::allocate(int size) {
    if (this->array == nullptr) {
#ifdef DEBUG
        std::cout << "Allocating memory\n";
#endif
        allocateMemory(size);
    } else if (this->size < size) {
#ifdef DEBUG
        std::cout << "Deallocating memory\n";
#endif
        deallocate();
#ifdef DEBUG
        std::cout << "Allocating memory\n";
#endif
        allocateMemory(size);
    }
    return *this;
    }

void Matrix::deallocate() {
    if (array != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] array[i];
        }
        delete[] array;
        array = nullptr;
        size = 0;
    }
}

void Matrix::allocateMemory(int size) {
    this->size = size;
    array = new int* [size];
    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
    }
}