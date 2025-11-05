/**
* @file matrix_constructor.cpp
 * @brief Приклад використання конструктора Matrix
 *
 * @details
 * Це показує, як створити матрицю 3x3.
 * Вона автоматично буде заповнена нулями (Complex(0,0)).
 *
 * @code
 * #include "src/Matrix.h" // Потрібно для компіляції
 * #include <iostream>
 *
 * int main() {
 * // Створює матрицю 3x3, заповнену нулями.
 * Matrix m(3, 3);
 *
 * std::cout << "Створена матриця 3х3:" << std::endl;
 * std::cout << m << std::endl;
 *
 * return 0;
 * }
 * @endcode
 */