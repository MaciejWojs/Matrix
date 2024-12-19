/**
 * @~english
 * @file Matrix.hpp
 * @brief Header file for Matrix class.
 * @details Contains declarations for Matrix class.
 *
 * @~polish
 * @file Matrix.hpp
 * @brief Plik nagłówkowy dla klasy Matrix.
 * @details Zawiera deklaracje klasy Matrix.
 */
#ifndef A6AD9251_8722_4046_9226_D571B42EF548
#define A6AD9251_8722_4046_9226_D571B42EF548
#include <iostream>

 /**
  * @~english
  * @class Matrix
  * @brief Class representing a square matrix.
  *
  * @details Consists of:
  * - size: square matrix dimension
  * - array: dynamic two-dimensional array storing elements
  *
  * Private methods:
  * - deallocate(): frees memory
  * - allocateMemory(): allocates memory for new matrix
  *
  * Main operations:
  * - Constructors: default, with size, with array, copy
  * - Operators: arithmetic (+, *, -), assignment, comparison
  * - Manipulation methods: transpose(), random(), diagonal()
  *
  * @throws May throw exceptions on invalid memory allocation
  *
  * @note Class provides complete memory management functionality
  *
  * @warning Care should be taken when operating on large matrices
  *
  * @~polish
  * @class Matrix
  * @brief Klasa reprezentująca macierz kwadratową.
  *
  * @details Składa się z:
  * - size: rozmiar macierzy kwadratowej
  * - array: dynamiczna tablica dwuwymiarowa przechowująca elementy
  *
  * Metody prywatne:
  * - deallocate(): zwalnia pamięć
  * - allocateMemory(): alokuje pamięć dla nowej macierzy
  *
  * Główne operacje:
  * - Konstruktory: domyślny, z rozmiarem, z tablicą, kopiujący
  * - Operatory: arytmetyczne (+, *, -), przypisania, porównania
  * - Metody manipulacji: transpose(), random(), diagonal()
  *
  * @throws Może zgłaszać wyjątki przy nieprawidłowej alokacji pamięci
  *
  * @note Klasa zapewnia pełną funkcjonalność zarządzania pamięcią
  *
  * @warning Należy zachować ostrożność przy operacjach na dużych macierzach
  */
class Matrix {
  private:
  int size; ///< @~english Dimension of the square matrix (n x n) @~polish Wymiar kwadratowej macierzy (n x n)
  int** array; ///< @~english Two-dimensional dynamic array storing matrix @~polish Dwuwymiarowa dynamiczna tablica przechowująca macierz

  void deallocate();
  void allocateMemory(int size);
  public:
  /**
   * @~english
   * @brief Default constructor.
   * @details Initializes an empty matrix.
   *
   * @~polish
   * @brief Konstruktor domyślny.
   * @details Inicjalizuje pustą macierz.
   */
  Matrix();

  /**
   * @~english
   * @brief Constructor with size.
   * @param size Dimension of the square matrix.
   *
   * @~polish
   * @brief Konstruktor z rozmiarem.
   * @param size Rozmiar macierzy kwadratowej.
   */
  Matrix(int size);

  /**
   * @~english
   * @brief Constructor with size and array.
   * @param size Dimension of the square matrix.
   * @param array Pointer to the array of elements.
   *
   * @~polish
   * @brief Konstruktor z rozmiarem i tablicą.
   * @param size Rozmiar macierzy kwadratowej.
   * @param array Wskaźnik na tablicę elementów.
   */
  Matrix(int size, int* array);

  /**
   * @~english
   * @brief Copy constructor.
   * @param matrix Reference to the matrix to copy.
   *
   * @~polish
   * @brief Konstruktor kopiujący.
   * @param matrix Referencja do kopiowanej macierzy.
   */
  Matrix(Matrix& matrix);

  /**
   * @~english
   * @brief Destructor.
   * @details Frees allocated memory.
   *
   * @~polish
   * @brief Destruktor.
   * @details Zwalnia zaalokowaną pamięć.
   */
  ~Matrix();



  /**
   * @~english
   * @brief Allocates memory for the matrix.
   * @param n Size of the matrix.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Alokuje pamięć dla macierzy.
   * @param n Rozmiar macierzy.
   * @return Referencja do macierzy.
   */
  Matrix& allocate(int n);

  /**
   * @~english
   * @brief Inserts a value into the matrix.
   * @param row Row index.
   * @param column Column index.
   * @param value Value to insert.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wstawia wartość do macierzy.
   * @param row Indeks wiersza.
   * @param column Indeks kolumny.
   * @param value Wartość do wstawienia.
   * @return Referencja do macierzy.
   */
  Matrix& insert(int row, int column, int value);

  /**
   * @~english
   * @brief Shows the value at a specific position.
   * @param row Row index.
   * @param column Column index.
   * @return Value at the specified position.
   *
   * @~polish
   * @brief Pokazuje wartość na określonej pozycji.
   * @param row Indeks wiersza.
   * @param column Indeks kolumny.
   * @return Wartość na określonej pozycji.
   */
  int show(int row, int column);

  /**
   * @~english
   * @brief Transposes the matrix.
   * @return Reference to the transposed matrix.
   *
   * @~polish
   * @brief Transponuje macierz.
   * @return Referencja do transponowanej macierzy.
   */
  Matrix& transpose();

  /**
   * @~english
   * @brief Fills the matrix with random values.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia macierz losowymi wartościami.
   * @return Referencja do macierzy.
   */
  Matrix& random();

  /**
   * @~english
   * @brief Fills the matrix with random digits (0-9).
   * @param how_much Number of positions to fill with random digits.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia macierz losowymi cyframi (0-9).
   * @param how_much Liczba pozycji do wypełnienia losowymi cyframi.
   * @return Referencja do macierzy.
   */
  Matrix& random(int how_much);

  /**
   * @~english
   * @brief Fills the main diagonal with values from array, sets other elements to 0.
   * @param array Pointer to the array of values for the diagonal.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia główną przekątną wartościami z tablicy, pozostałe elementy ustawia na 0.
   * @param array Wskaźnik na tablicę wartości dla przekątnej.
   * @return Referencja do macierzy.
   */
  Matrix& diagonal(int* array);

  /**
   * @~english
   * @brief Fills diagonal k with values from array, other elements set to 0.
   * @param array Pointer to the array of values.
   * @param k Diagonal shift: 0 - main diagonal, positive - shifts up, negative - shifts down.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia przekątną k wartościami z tablicy, pozostałe elementy ustawia na 0.
   * @param array Wskaźnik na tablicę wartości.
   * @param k Przesunięcie przekątnej: 0 - główna przekątna, dodatnie - w górę, ujemne - w dół.
   * @return Referencja do macierzy.
   */
  Matrix& diagonal_k(int* array, int k);

  /**
   * @~english
   * @brief Copies data from array to specified column.
   * @param x Column index.
   * @param array Array with data to copy.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Przepisuje dane z tablicy do wskazanej kolumny.
   * @param x Indeks kolumny.
   * @param array Tablica z danymi do skopiowania.
   * @return Referencja do macierzy.
   */
  Matrix& column(int x, int* array);

  /**
   * @~english
   * @brief Copies data from array to specified row.
   * @param y Row index.
   * @param array Array with data to copy.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Przepisuje dane z tablicy do wskazanego wiersza.
   * @param y Indeks wiersza.
   * @param array Tablica z danymi do skopiowania.
   * @return Referencja do macierzy.
   */
  Matrix& row(int y, int* array);

  /**
   * @~english
   * @brief Fills matrix with 1s on diagonal and 0s elsewhere.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia macierz: 1 na przekątnej, 0 poza przekątną.
   * @return Referencja do macierzy.
   */
  Matrix& fill_diagonal();

  /**
   * @~english
   * @brief Fills matrix with 1s below diagonal and 0s elsewhere.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia macierz: 1 pod przekątną, 0 nad przekątną i na przekątnej.
   * @return Referencja do macierzy.
   */
  Matrix& fill_under_diagonal();

  /**
   * @~english
   * @brief Fills the area above the main diagonal of the matrix.
   * @return Reference to the matrix.
   *
   * @~polish
   * @brief Wypełnia obszar nad główną przekątną macierzy.
   * @return Referencja do macierzy.
   */
  Matrix& fill_above_diagonal();

  /**
   * @~english
   * @brief Sets the chess board pattern shape of the matrix.
   * @return Matrix object where 1 represents black fields and 0 represents white fields.
   *
   * @~polish
   * @brief Ustawia kształt szachownicy macierzy.
   * @return Obiekt Matrix gdzie 1 reprezentuje czarne pola, a 0 reprezentuje białe pola.
   */
  Matrix check_shape();

  /**
   * @~english
   * @brief Adds two matrices.
   * @param m Matrix to add.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Dodaje dwie macierze.
   * @param m Macierz do dodania.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator+(Matrix& m);

  /**
   * @~english
   * @brief Multiplies two matrices.
   * @param m Matrix to multiply.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Mnoży dwie macierze.
   * @param m Macierz do pomnożenia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator*(Matrix& m);

  /**
   * @~english
   * @brief Adds a scalar to the matrix.
   * @param a Scalar value to add.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Dodaje skalar do macierzy.
   * @param a Wartość skalarna do dodania.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator+(int a);

  /**
   * @~english
   * @brief Multiplies the matrix by a scalar.
   * @param a Scalar value to multiply.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Mnoży macierz przez skalar.
   * @param a Wartość skalarna do pomnożenia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator*(int a);

  /**
   * @~english
   * @brief Subtracts a scalar from the matrix.
   * @param a Scalar value to subtract.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Odejmowanie skalaru od macierzy.
   * @param a Wartość skalarna do odjęcia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator-(int a);

  /**
   * @~english
   * @brief Adds a scalar to the matrix (friend function).
   * @param a Scalar value to add.
   * @param m Matrix to add to.
   * @return Resulting matrix.
   *
   * @~polish
   * @brief Dodaje skalar do macierzy (funkcja zaprzyjaźniona).
   * @param a Wartość skalarna do dodania.
   * @param m Macierz do dodania.
   * @return Wynikowa macierz.
   */
  friend Matrix operator+(int a, Matrix& m);

  /**
   * @~english
   * @brief Multiplies the matrix by a scalar (friend function).
   * @param a Scalar value to multiply.
   * @param m Matrix to multiply.
   * @return Resulting matrix.
   *
   * @~polish
   * @brief Mnoży macierz przez skalar (funkcja zaprzyjaźniona).
   * @param a Wartość skalarna do pomnożenia.
   * @param m Macierz do pomnożenia.
   * @return Wynikowa macierz.
   */
  friend Matrix operator*(int a, Matrix& m);

  /**
   * @~english
   * @brief Subtracts a scalar from the matrix (friend function).
   * @param a Scalar value to subtract.
   * @param m Matrix to subtract from.
   * @return Resulting matrix.
   *
   * @~polish
   * @brief Odejmowanie skalaru od macierzy (funkcja zaprzyjaźniona).
   * @param a Wartość skalarna do odjęcia.
   * @param m Macierz do odjęcia.
   * @return Wynikowa macierz.
   */
  friend Matrix operator-(int a, Matrix& m);

  /**
   * @~english
   * @brief Post-increment operator.
   * @return Reference to the incremented matrix.
   *
   * @~polish
   * @brief Operator inkrementacji (postfiksowy).
   * @return Referencja do inkrementowanej macierzy.
   */
  Matrix& operator++(int);
  Matrix& operator++();

  /**
   * @~english
   * @brief Post-decrement operator.
   * @return Reference to the decremented matrix.
   *
   * @~polish
   * @brief Operator dekrementacji (postfiksowy).
   * @return Referencja do dekrementowanej macierzy.
   */
  Matrix& operator--(int);

  /**
   * @~english
   * @brief Adds a scalar to the matrix.
   * @param a Scalar value to add.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Dodaje skalar do macierzy.
   * @param a Wartość skalarna do dodania.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator+=(int a);

  /**
   * @~english
   * @brief Subtracts a scalar from the matrix.
   * @param a Scalar value to subtract.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Odejmowanie skalaru od macierzy.
   * @param a Wartość skalarna do odjęcia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator-=(int a);

  /**
   * @~english
   * @brief Multiplies the matrix by a scalar.
   * @param a Scalar value to multiply.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Mnoży macierz przez skalar.
   * @param a Wartość skalarna do pomnożenia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator*=(int a);

  /**
   * @~english
   * @brief Divides the matrix by a scalar.
   * @param a Scalar value to divide.
   * @return Reference to the resulting matrix.
   *
   * @~polish
   * @brief Dzieli macierz przez skalar.
   * @param a Wartość skalarna do podzielenia.
   * @return Referencja do wynikowej macierzy.
   */
  Matrix& operator/=(int a);

  /**
   * @~english
   * @brief Stream insertion operator for printing the matrix.
   * @param o Output stream.
   * @param m Matrix to print.
   * @return Reference to the output stream.
   *
   * @~polish
   * @brief Operator wstawiania strumienia do drukowania macierzy.
   * @param o Strumień wyjściowy.
   * @param m Macierz do wydrukowania.
   * @return Referencja do strumienia wyjściowego.
   */
  friend std::ostream& operator<<(std::ostream& o, const Matrix& m);

  /**
   * @~english
   * @brief Equality comparison operator.
   * @param m Matrix to compare.
   * @return True if matrices are equal, false otherwise.
   *
   * @~polish
   * @brief Operator porównania równości.
   * @param m Macierz do porównania.
   * @return True, jeśli macierze są równe, w przeciwnym razie false.
   */
  bool operator==(const Matrix& m) const;

  /**
   * @~english
   * @brief Greater than comparison operator.
   * @param m Matrix to compare.
   * @return True if this matrix is greater than the other, false otherwise.
   *
   * @~polish
   * @brief Operator porównania większe niż.
   * @param m Macierz do porównania.
   * @return True, jeśli ta macierz jest większa od drugiej, w przeciwnym razie false.
   */
  bool operator>(const Matrix& m);

  /**
   * @~english
   * @brief Less than comparison operator.
   * @param m Matrix to compare.
   * @return True if this matrix is less than the other, false otherwise.
   *
   * @~polish
   * @brief Operator porównania mniejsze niż.
   * @param m Macierz do porównania.
   * @return True, jeśli ta macierz jest mniejsza od drugiej, w przeciwnym razie false.
   */
  bool operator<(const Matrix& m);

  /**
   * @~english
   * @brief Prints the matrix to the standard output.
   *
   * @~polish
   * @brief Drukuje macierz na standardowe wyjście.
   */
  Matrix& print();

  /**
   * @~english
   * @brief Converts the matrix to a one-dimensional array.
   * @return Pointer to the array.
   *
   * @~polish
   * @brief Konwertuje macierz na jednowymiarową tablicę.
   * @return Wskaźnik na tablicę.
   */
  int* to_array();

  /**
   * @~english
   * @brief Gets the size of the matrix.
   * @return Size of the matrix.
   *
   * @~polish
   * @brief Pobiera rozmiar macierzy.
   * @return Rozmiar macierzy.
   */
  int get_size();

  /**
   * @~english
   * @brief Stream extraction operator for reading the matrix.
   * @param input_stream Input stream.
   * @param m Matrix to read into.
   * @return Reference to the input stream.
   *
   * @~polish
   * @brief Operator ekstrakcji strumienia do odczytu macierzy.
   * @param input_stream Strumień wejściowy.
   * @param m Macierz do odczytu.
   * @return Referencja do strumienia wejściowego.
   */
  friend std::istream& operator>>(std::istream& input_stream, Matrix& m);
  int pick_Random_Column();
  int pick_Random_Row();
  Matrix& clear();
};



#endif /* A6AD9251_8722_4046_9226_D571B42EF548 */
