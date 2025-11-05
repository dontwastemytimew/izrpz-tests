/**
* @file strassen_multiply.cpp
 * @brief Приклад використання Strassen::multiply
 *
 * Демонструє, як помножити дві матриці 2x2
 * та обробити можливі винятки.
 */
class Matrix; // Уявне оголошення
namespace Strassen { class Matrix; Matrix multiply(const Matrix&, const Matrix&); } // Уявне оголошення
#include <iostream>
#include <stdexcept>

void example() {
    // @code
    // Приклад використання:
    Matrix A(2, 2);
    Matrix B(2, 2);
    // ... (заповнення A та B) ...
    try {
        Matrix C = Strassen::multiply(A, B);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    // @endcode
}