#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

/**
 * @brief Константа для коректного порівняння чисел double (з допуском).
 * Використовується в operator== для уникнення проблем з точністю.
 */
constexpr double EPSILON = 1e-8;

/**
 * @class Complex
 * @brief Представляє комплексне число (a + bi) та його базову арифметику.
 */
class Complex {
public:
    double re, im; // re - дійсна частина, im - уявна частина

    /**
     * @brief Конструктор за замовчуванням.
     * @param r Дійсна частина.
     * @param i Уявна частина.
     */
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    /**
     * @brief Перевантаження оператора додавання.
     * @param other Інше комплексне число для додавання.
     * @return Новий об'єкт Complex, що є сумою.
     */
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    /**
     * @brief Перевантаження оператора віднімання.
     * @param other Інше комплексне число для віднімання.
     * @return Новий об'єкт Complex, що є різницею.
     */
    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    /**
     * @brief Множить два комплексних числа.
     * Реалізує формулу: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
     * @param other Комплексне число для множення.
     * @return Новий об'єкт Complex, що є результатом множення.
     */
    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im,
                       re * other.im + im * other.re);
    }

    /**
     * @brief Перевіряє рівність двох комплексних чисел з допуском EPSILON.
     * @param other Інше комплексне число.
     * @return true, якщо числа "майже" рівні (різниця <= EPSILON).
     */
    bool operator==(const Complex& other) const {
        return std::abs(re - other.re) <= EPSILON &&
               std::abs(im - other.im) <= EPSILON;
    }

    /**
     * @brief Перевіряє нерівність двох комплексних чисел.
     * @param other Інше комплексне число.
     * @return true, якщо числа нерівні.
     */
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
};

/**
 * @brief Перевантаження оператора << для друку Complex у потік.
 * @param os Потік виводу.
 * @param c Комплексне число.
 * @return Посилання на потік.
 */
inline std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re;
    if (c.im >= 0) os << "+";
    os << c.im << "i";
    return os;
}