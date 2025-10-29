#pragma once

#include "Complex.h"
#include <vector>
#include <iostream>

// Клас для матриці комплексних чисел
class Matrix {
public:
    std::vector<std::vector<Complex>> data;

    Matrix(int r = 0, int c = 0);

    // Безпечний доступ до елемента (читання/запис)
    // Кидає виняток std::out_of_range, якщо індекси некоректні
    Complex& at(int r, int c);
    const Complex& at(int r, int c) const;

    int getRows() const;
    int getCols() const;

    // Оператори
    // Поелементне додавання матриць
    Matrix operator+(const Matrix& other) const;
    // Поелементне віднімання матриць
    Matrix operator-(const Matrix& other) const;
    // Поелементне порівняння матриць
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    // Класичне множення
    // Використовується для базових випадків у Штрассені
    Matrix multiplyClassic(const Matrix& other) const;

    // Розділяє матрицю M на 4 рівні чверті (квадранти)
    static void split(const Matrix& M, Matrix& M11, Matrix& M12, Matrix& M21, Matrix& M22);
    // Збирає одну велику матрицю M з 4-х чвертей
    static void combine(Matrix& M, const Matrix& M11, const Matrix& M12, const Matrix& M21, const Matrix& M22);

private:
    int rows, cols;
};

// Перевантаження оператора << для друку Matrix у потік
std::ostream& operator<<(std::ostream& os, const Matrix& m);