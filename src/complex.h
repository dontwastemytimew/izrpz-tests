#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

// Константа для коректного порівняння чисел double
const double EPSILON = 1e-9;

// Клас для комплексного числа (a + bi)
class Complex {
public:
    double re, im; // re - дійсна частина, im - уявна частина

    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    // Арифметичні оператори
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    // Множення: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im,
                       re * other.im + im * other.re);
    }

    // Оператори порівняння
    bool operator==(const Complex& other) const {
        return std::abs(re - other.re) < EPSILON &&
               std::abs(im - other.im) < EPSILON;
    }
    
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
};

// Перевантаження оператора << для друку Complex
inline std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re;
    if (c.im >= 0) os << "+";
    os << c.im << "i";
    return os;
}