#ifndef A6AD9251_8722_4046_9226_D571B42EF548
#define A6AD9251_8722_4046_9226_D571B42EF548
#include <iostream>

class Matrix {
    private:
    int size;
    int** array;

    void deallocate();
    void allocateMemory(int size);
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
    Matrix& diagonal_k(int* array, int k);// po przekątnej są wpisane dane z tabeli,a pozostałe elementy są równe 0. Parametr k może oznaczać: 0 - przekątna przechodząca przez środek (czyli tak jak metoda diagonalna), cyfra dodatnia przesuwa diagonalną do góry macierzy o podaną cyfrę, cyfra ujemna przesuwa diagonalną w dół o podaną cyfrę,
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

    friend std::ostream& operator<<(std::ostream& o, const Matrix& m);
    bool operator==(const Matrix& m) const;
    bool operator>(const Matrix& m);
    bool operator<(const Matrix& m);

    void print();
    friend std::istream& operator>>(std::istream& input_stream, Matrix& m);
};



#endif /* A6AD9251_8722_4046_9226_D571B42EF548 */
