#include <iostream>
#include "Matrix.hpp"
#include <cmath>


std::istream& operator>>(std::istream& input_stream, Matrix& m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            input_stream >> m.array[i][j];
        }
    }
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Matrix& m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            output_stream << m.array[i][j] << " ";
        }
        output_stream << std::endl;
    }
    return output_stream;
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

Matrix& Matrix::operator+=(int a) {
    if (std::abs(a) != 0) {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                this->array[i][j] += a;
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(int a) {
    this->operator+=(-a);
    return *this;
}

Matrix& Matrix::operator*= (int a) {
    if (a != 1) {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                this->array[i][j] *= a;
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(int a) {
    if (a == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a != 1) {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                this->array[i][j] /= a;
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator++(int) {
    this->operator+=(1);
    return *this;
}

Matrix& Matrix::operator++() {
    return (*this)++;
}

Matrix& Matrix::operator--(int) {
    return (*this).operator+=(-1);
}

Matrix& Matrix::operator--() {
    return (*this)--;
}

Matrix& Matrix::operator+(int a) {
    return (*this) += a;
}

Matrix operator+(int a, Matrix& m) {
    return m + a;
}

Matrix& Matrix::operator-(int a) {
    return (*this) -= a;
}

Matrix operator-(int a, Matrix& m) {
    return m - a;
}

Matrix& Matrix::operator*(int a) {
    return (*this) *= a;
}

Matrix operator*(int a, Matrix& m) {
    return m * a;
}

Matrix& Matrix::operator/(int a) {
    return (*this) /= a;
}

Matrix operator/(int a, Matrix& m) {
    return m / a;
}

bool Matrix::operator>(const Matrix& m) {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrices have different sizes");
    }

    bool greater = true;

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->array[i][j] < m.array[i][j]) {
                greater = false;
                return greater;
            }
        }
    }
    return greater;
}

bool Matrix::operator<(const Matrix& m) {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrices have different sizes");
    }
    return  !((*this) > m);
}

Matrix& Matrix::check_shape() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if ((i + j) % 2 == 0) {
                this->array[i][j] = 1;
            } else {
                this->array[i][j] = 0;
            }
        }
    }
    return *this;
}