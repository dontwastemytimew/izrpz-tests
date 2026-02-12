/**
 * @file strassen_multiply.cpp
 * @brief Приклад використання Strassen::multiply
 */
#include "Strassen.h"
#include "Matrix.h"
#include "Complex.h"
#include <iostream>
#include <stdexcept>


void example_multiply() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    try {
        Matrix C = Strassen::multiply(A, B);
        std::cout << "Результат множення:" << std::endl;
        std::cout << C;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
}