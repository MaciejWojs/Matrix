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
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            std::swap(array[i][j], array[j][i]);
        }
    }

    return *this;
}

Matrix& Matrix::random() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->array[i][j] = std::rand() % 10; // losowe wartości od 0 do 99
        }
    }
    return *this;
}
//wypełniamy cyframi od 0 do 9 elementy macierzy. Zmienna x określa ile cyfr będziemy losować. Następnie algorytm losuje, w które miejsca wstawi wylosowane cyfry, 
Matrix& Matrix::random(int how_much) {
    for (int i = 0; i < how_much; i++) {
        int x = pick_Random_Row();
        int y = pick_Random_Column();
        int randomValue = std::rand() % 10;
#ifdef DEBUG
        std::cout << "Row: " << x << " Column: " << y << " randomValue: " << randomValue << std::endl;
#endif
        array[x][y] = randomValue;
#ifdef DEBUG
        print();
#endif
    }
    return *this;
}

Matrix& Matrix::diagonal(int* array) {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (i == j) {
                this->array[i][j] = array[i];
            } else {
                this->array[i][j] = 0;
            }
        }
    }
    return *this;
}

Matrix& Matrix::diagonal_k(int* array, int k) {
    if (k == 0) {
        return diagonal(array);
    }

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (i == j - k) {
                this->array[i][j] = array[i];
            } else {
                this->array[i][j] = 0;
            }
        }
    }
    return *this;
}
Matrix& Matrix::column(int x, int* array) {
    if (x >= this->size) {
        throw std::invalid_argument("Index out of range");
    }
    for (int i = 0; i < this->size; i++) {
        this->array[i][x] = array[i];
    }
    return *this;
}

Matrix& Matrix::row(int y, int* array) {
    if (y >= this->size) {
        throw std::invalid_argument("Index out of range");
    }
    for (int i = 0; i < this->size; i++) {
        this->array[y][i] = array[i];
    }
    return *this;
}

Matrix& Matrix::fill_diagonal() {
    for (int i = 0; i < this->size; i++) {
        this->array[i][i] = 1;
    }
    return *this;
}

Matrix& Matrix::fill_under_diagonal() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < i; j++) {
            this->array[i][j] = 1;
        }
    }
    return *this;
}

Matrix& Matrix::fill_above_diagonal() {
    for (int i = 0; i < this->size; i++) {
        for (int j = i + 1; j < this->size; j++) {
            this->array[i][j] = 1;
        }
    }
    return *this;
}

int* Matrix::to_array() {
    if (size == 0 && array == nullptr) {
        return nullptr;
    }

    int* array = new int[this->size * this->size];
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            array[i * this->size + j] = this->array[i][j];
        }
    }
    return array;
}

int Matrix::get_size() {
    return this->size;
}

int Matrix::pick_Random_Column() {
    return std::rand() % this->size;
}

int Matrix::pick_Random_Row() {
    return std::rand() % this->size;
}