#include "Strassen.h"
#include <stdexcept>
#include <algorithm>

namespace Strassen {


    int nextPowerOfTwo(int n) {
        if (n <= 0) return 1;

        // Швидка бітова перевірка, чи n вже є степенем двійки
        // (напр. 8 це 1000, 7 це 0111. 8 & 7 = 0)
        if ((n & (n - 1)) == 0) return n;

        int m = 1;
        while (m < n) m *= 2;
        return m;
    }

    // Створює нову матрицю newSize x newSize і копіює в неї стару
    Matrix padMatrix(const Matrix& A, int newSize) {
        Matrix A_pad(newSize, newSize); // Створюється заповнена нулями
        for (int i = 0; i < A.rows; i++)
            for (int j = 0; j < A.cols; j++)
                A_pad.data[i][j] = A.data[i][j];
        return A_pad;
    }

    // Створює нову матрицю origRows x origCols і копіює в неї лівий верхній кут
    Matrix unpadMatrix(const Matrix& A_pad, int origRows, int origCols) {
        Matrix C(origRows, origCols);
        for (int i = 0; i < origRows; i++)
            for (int j = 0; j < origCols; j++)
                C.data[i][j] = A_pad.data[i][j];
        return C;
    }

    Matrix strassenRecursive(const Matrix& A, const Matrix& B) {
        int n = A.rows;

        // Базовий випадок рекурсії
        if (n <= RECURSION_THRESHOLD) {
            return A.multiplyClassic(B);
        }

        // Крок рекурсії
        int k = n / 2; // Розмір підматриць

        // Створюємо матриці для чвертей
        Matrix A11(k, k), A12(k, k), A21(k, k), A22(k, k);
        Matrix B11(k, k), B12(k, k), B21(k, k), B22(k, k);

        // Розділяємо A і B на 4 чверті
        Matrix::split(A, A11, A12, A21, A22);
        Matrix::split(B, B11, B12, B21, B22);

        // Обчислюємо 7 проміжних матриць (M1-M7) рекурсивно
        Matrix M1 = strassenRecursive(A11 + A22, B11 + B22);
        Matrix M2 = strassenRecursive(A21 + A22, B11);
        Matrix M3 = strassenRecursive(A11, B12 - B22);
        Matrix M4 = strassenRecursive(A22, B21 - B11);
        Matrix M5 = strassenRecursive(A11 + A12, B22);
        Matrix M6 = strassenRecursive(A21 - A11, B11 + B12);
        Matrix M7 = strassenRecursive(A12 - A22, B21 + B22);

        // Обчислюємо чверті результуючої матриці C
        Matrix C11 = M1 + M4 - M5 + M7;
        Matrix C12 = M3 + M5;
        Matrix C21 = M2 + M4;
        Matrix C22 = M1 - M2 + M3 + M6;

        // Збираємо результат
        Matrix C(n, n);
        Matrix::combine(C, C11, C12, C21, C22);
        return C;
    }

    Matrix multiply(const Matrix& A, const Matrix& B) {
        if (A.cols != B.rows) {
            throw std::invalid_argument("Incompatible dimensions for multiplication");
        }

        // Знаходимо найбільший розмір і наступний степінь двійки
        int n_max = std::max({A.rows, A.cols, B.rows, B.cols});
        int m = nextPowerOfTwo(n_max);

        // Доповнюємо матриці нулями до розміру m x m
        Matrix A_pad = padMatrix(A, m);
        Matrix B_pad = padMatrix(B, m);

        Matrix C_pad = strassenRecursive(A_pad, B_pad);

        return unpadMatrix(C_pad, A.rows, B.cols);
    }

}