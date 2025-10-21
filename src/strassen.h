#pragma once

#include "Matrix.h"

namespace Strassen {

    // Поріг рекурсії: якщо N <= 32, перемикаємось на класичне множення
    // бо воно швидше для малих матриць (менше накладних витрат)
    inline constexpr int RECURSION_THRESHOLD = 32;

    // Знаходить найближчий степінь двійки, що >= n
    int nextPowerOfTwo(int n);

    // Доповнює матрицю нулями до розміру newSize x newSize
    Matrix padMatrix(const Matrix& A, int newSize);

    // Обрізає матрицю до оригінального розміру origRows x origCols
    Matrix unpadMatrix(const Matrix& A_pad, int origRows, int origCols);


    // Рекурсивний крок алгоритму
    // Працює ТІЛЬКИ з квадратними матрицями, розмір яких є степенем двійки
    Matrix strassenRecursive(const Matrix& A, const Matrix& B);

    // Публічна функція, яку викликає користувач
    // Вона виконує: перевірку, доповнення (padding), виклик рекурсії, обрізання (unpadding)
    Matrix multiply(const Matrix& A, const Matrix& B);

}