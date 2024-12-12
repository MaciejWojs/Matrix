#include <iostream>
#include "Matrix.hpp"
#include <cmath>

Matrix::Matrix() : size{}, array(nullptr) {}

Matrix::Matrix(int size) {
    this->size = size;
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int;
    }
    array = arr;
}

Matrix::Matrix(int size, int* _array) : Matrix(size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->array[i][j] = _array[i * size + j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->array[i];
    }
    delete[] this->array;
}

void Matrix::print() {
    std::cout << *this << std::endl;
}

Matrix& Matrix::insert(int row, int column, int value) {
    this->array[row][column] = value;
    return *this;
}

std::istream& operator>>(std::istream& input_stream, Matrix& m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            input_stream >> m.array[i][j];
        }
    }
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, Matrix& m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            output_stream << m.array[i][j] << " ";
        }
        output_stream << std::endl;
    }
    return output_stream;
}

int Matrix::show(int row, int column) {
    return this->array[row][column];
}

bool Matrix::operator==(const Matrix& m) const {
    if (this->size != m.size) {
        return false;
    }
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->array[i][j] != m.array[i][j]) {
                return false;
            }
        }
    }
    return true;
}