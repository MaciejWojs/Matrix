#include <iostream>
#include "Matrix.hpp"
#include <random>
#include <fstream>

int main() {
    std::cout << "\n\n";
    // int size
    std::cout << "Enter the size of the matrix: ";
    int size = 2;
    std::cin >> size;
    Matrix m(size);



    std::cout << "Enter the values of the matrix: ";
    std::cin >> m;
    // std::ifstream file("matrix.txt");
    // file >> m;



    // std::cin >> size; // get the matrix size

    // int array[] = {1,2,3,4,5,6,7,8,9};

    // m << std::cin;

    // std::random_device rd;
    // std::mt19937 gen(rd());

    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         m.insert(i, j, gen() % 10);
    //     }
    // }

    m.print();

    std::ofstream file2("matrix2.txt");
    file2 << m;


    std::cout << "Hello, World!" << std::endl;
    return 0;


}