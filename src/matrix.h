#pragma once

#include "Complex.h"
#include <vector>
#include <iostream>

/**
 * @class Matrix
 * @brief Клас для представлення 2D матриці комплексних чисел.
 *
 * Інкапсулює дані матриці та надає безпечні методи доступу,
 * базову арифметику та допоміжні функції для алгоритму Штрассена.
 */
class Matrix {
public:
 /**
   * @brief Вектор векторів, що зберігає елементи матриці.
   * Є публічним для спрощення реалізації `split` та `combine`.
   */
    std::vector<std::vector<Complex>> data;

 /**
     * @brief Конструктор матриці.
     *
     * Гарантує, що всі елементи будуть ініціалізовані нулями
     * (Complex(0,0)) завдяки конструктору std::vector.
     *
     * @example matrix_constructor.cpp
     *
     * @param r Кількість рядків.
     * @param c Кількість стовпців.
     */
    Matrix(int r = 0, int c = 0);

 /**
     * @brief Безпечний доступ до елемента (читання/запис).
     * @param r Індекс рядка (починаючи з 0).
     * @param c Індекс стовпця (починаючи з 0).
     * @return Посилання на елемент data[r][c].
     * @throws std::out_of_range Якщо індекси `r` або `c` виходять за межі матриці.
     */
    Complex& at(int r, int c);

 /**
     * @brief Безпечний доступ до елемента (тільки читання) для const-об'єктів.
     * @param r Індекс рядка (починаючи з 0).
     * @param c Індекс стовпця (починаючи з 0).
     * @return Константне посилання на елемент data[r][c].
     * @throws std::out_of_range Якщо індекси `r` або `c` виходять за межі матриці.
     */
    const Complex& at(int r, int c) const;

    /**
     * @brief Гетер для кількості рядків.
     * @return Кількість рядків.
     */
    int getRows() const;

    /**
     * @brief Гетер для кількості стовпців.
     * @return Кількість стовпців.
     */
    int getCols() const;

 /**
  * @brief Поелементне додавання матриць.
  * @param other Матриця для додавання.
  * @return Нова матриця, що є сумою.
  * @throws std::invalid_argument Якщо розміри матриць не збігаються.
  */
    Matrix operator+(const Matrix& other) const;

 /**
  * @brief Поелементне віднімання матриць.
  * @param other Матриця для віднімання.
  * @return Нова матриця, що є різницею.
  * @throws std::invalid_argument Якщо розміри матриць не збігаються.
  */
    Matrix operator-(const Matrix& other) const;

 /**
   * @brief Поелементне порівняння матриць.
   * @param other Матриця для порівняння.
   * @return true, якщо всі елементи "майже" рівні (з допуском EPSILON).
   */
    bool operator==(const Matrix& other) const;

 /**
     * @brief Поелементне порівняння матриць на нерівність.
     * @param other Матриця для порівняння.
     * @return true, якщо хоча б один елемент нерівний.
     */
    bool operator!=(const Matrix& other) const;

 /**
     * @brief Класичне (наївне) множення матриць O(N^3).
     * Використовується як базовий випадок для Штрассена та для верифікації у тестах.
     * @param other Матриця для множення.
     * @return Результуюча матриця.
     * @throws std::invalid_argument Якщо розміри матриць несумісні (A.cols != B.rows).
     */
    Matrix multiplyClassic(const Matrix& other) const;

 /**
     * @brief Розділяє матрицю M на 4 рівні чверті (квадранти).
     * Приймає вихідні матриці за посиланням для уникнення зайвого копіювання.
     * @param M Вхідна матриця (повинна бути парного розміру).
     * @param M11 Вихідна матриця (верхня ліва чверть).
     * @param M12 Вихідна матриця (верхня права чверть).
     * @param M21 Вихідна матриця (нижня ліва чверть).
     * @param M22 Вихідна матриця (нижня права чверть).
     */
    static void split(const Matrix& M, Matrix& M11, Matrix& M12, Matrix& M21, Matrix& M22);

 /**
  * @brief Збирає одну велику матрицю M з 4-х чвертей.
  * @param M Вихідна матриця (куди збирається результат).
  * @param M11 Вхідна матриця (верхня ліва чверть).
  * @param M12 Вхідна матриця (верхня права чверть).
  * @param M21 Вхідна матриця (нижня ліва чверть).
  * @param M22 Вхідна матриця (нижня права чверть).
  */
    static void combine(Matrix& M, const Matrix& M11, const Matrix& M12, const Matrix& M21, const Matrix& M22);

private:
    int rows, cols; ///< Приватні змінні для зберігання розмірів
};

/**
 * @brief Перевантаження оператора << для друку Matrix у потік.
 * @param os Потік виводу (напр. std::cout).
 * @param m Матриця для друку.
 * @return Посилання на потік виводу.
 */
std::ostream& operator<<(std::ostream& os, const Matrix& m);