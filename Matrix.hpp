#ifndef A6AD9251_8722_4046_9226_D571B42EF548
#define A6AD9251_8722_4046_9226_D571B42EF548
#include <iostream>

class Matrix {
    public:
    Matrix();
    Matrix(int size);
    Matrix(int size, int* array);
    Matrix(Matrix& matrix);

    ~Matrix();

    Matrix& allocate(int n);
    Matrix& insert(int row, int column, int value);
    int show(int row, int column);
    Matrix& transpose();
    Matrix& random();
    Matrix& random(int how_much);
    Matrix& diagonal(int* array);
    Matrix& diagonal_k(int* array);
    Matrix& column(int x, int* array);
    Matrix& row(int y, int* array);
    Matrix& fill_diagonal();
    Matrix& fill_under_diagonal();
    Matrix& fill_above_diagonal();
    Matrix check_shape();

    Matrix& operator+(Matrix& m);
    Matrix& operator*(Matrix& m);
    Matrix& operator+(int a);
    Matrix& operator*(int a);
    Matrix& operator-(int a);
    friend Matrix operator+(int a, Matrix& m);
    friend Matrix operator*(int a, Matrix& m);
    friend Matrix operator-(int a, Matrix& m);
    Matrix& operator++(int);
    Matrix& operator--(int);
    Matrix& operator+=(int a);
    Matrix& operator-=(int a);
    Matrix& operator*=(int a);
    // Matrix& operator (double);

    friend std::ostream& operator<<(std::ostream& o, Matrix& m);
    bool operator==(const Matrix& m);
    bool operator>(const Matrix& m);
    bool operator<(const Matrix& m);

};



#endif /* A6AD9251_8722_4046_9226_D571B42EF548 */
