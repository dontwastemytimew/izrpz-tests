/**
* @file matrix_constructor.cpp
 * @brief Приклад використання конструктора Matrix
 */
#include "Matrix.h"
#include "Complex.h"
#include <iostream>

void example_constructor() {
    // Створює матрицю 3x3, заповнену нулями.
    Matrix m(3, 3);

    std::cout << "Створена матриця 3х3:" << std::endl;
    std::cout << m << std::endl;
}