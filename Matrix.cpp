#include <iostream>
#include <cstdlib>
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

Matrix& Matrix::transpose() {
    Matrix temp(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            temp.array[j][i] = this->array[i][j];
        }
    }
    *this = temp;
    return *this;
}

Matrix& Matrix::random() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->array[i][j] = std::rand() % 100; // losowe wartości od 0 do 99
        }
    }
    return *this;
}

Matrix& Matrix::random(int how_much) {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->array[i][j] = std::rand() % how_much;
        }
    }
    return *this;
}