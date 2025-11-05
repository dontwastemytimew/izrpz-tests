/**
* @file strassen_multiply.cpp
 * @brief Приклад використання Strassen::multiply
 *
 * @details
 * Демонструє, як помножити дві матриці 2x2
 * та обробити можливі винятки.
 *
 * @code
 * #include "src/Strassen.h" // Потрібно для компіляції
 * #include <iostream>
 * #include <stdexcept>
 *
 * int main() {
 * Matrix A(2, 2);
 * Matrix B(2, 2);
 * // ... (тут могло б бути заповнення A та B) ...
 *
 * try {
 * Matrix C = Strassen::multiply(A, B);
 * std::cout << "Результат множення:" << std::endl;
 * std::cout << C;
 * } catch (const std::invalid_argument& e) {
 * std::cerr << "Помилка: " << e.what() << std::endl;
 * }
 *
 * return 0;
 * }
 * @endcode
 */