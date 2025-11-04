#pragma once

#include "Matrix.h"

/**
 * @namespace Strassen
 * @brief Ізолює всю логіку, пов'язану з алгоритмом Штрассена.
 *
 * Містить рекурсивну реалізацію, а також допоміжні функції
 * для доповнення (padding) та обрізання (unpadding) матриць.
 */
namespace Strassen {

 /**
  * @brief Поріг рекурсії.
  * Якщо розмір матриці N <= RECURSION_THRESHOLD,
  * алгоритм перемикається на класичне множення O(N^3),
  * оскільки воно стає швидшим через менші накладні витрати.
  */
    inline constexpr int RECURSION_THRESHOLD = 32;

 /**
  * @brief Знаходить найближчий степінь двійки, що >= n.
  * Обробляє 0, повертаючи 1 (мінімальний розмір матриці).
  * @param n Вхідне число.
  * @return Найближчий степінь двійки.
  */
    int nextPowerOfTwo(int n);

 /**
   * @brief "Доповнює" матрицю нулями до розміру newSize x newSize.
   * @param A Матриця для доповнення.
   * @param newSize Новий квадратний розмір (степінь двійки).
   * @return Нова матриця `newSize x newSize` з даними з `A` у верхньому лівому куті.
   */
    Matrix padMatrix(const Matrix& A, int newSize);

 /**
  * @brief "Обрізає" матрицю до оригінального розміру.
  * @param A_pad Доповнена матриця.
  * @param origRows Кількість рядків у фінальному результаті.
  * @param origCols Кількість стовпців у фінальному результаті.
  * @return Нова матриця `origRows x origCols`.
  */
    Matrix unpadMatrix(const Matrix& A_pad, int origRows, int origCols);


 /**
  * @brief Основний рекурсивний крок алгоритму Штрассена.
  *
  * **Увага:** Працює ТІЛЬКИ з квадратними матрицями, розмір яких є степенем двійки.
  * Не повинна викликатися напряму; використовуйте `Strassen::multiply`.
  *
  * @param A Перша матриця.
  * @param B Друга матриця.
  * @return Результуюча матриця.
  */
    Matrix strassenRecursive(const Matrix& A, const Matrix& B);

 /**
  * @brief "Публічна" функція множення Штрассена.
  *
  * Це головний API, який викликає користувач. Функція інкапсулює
  * всю логіку: перевірку, доповнення, виклик рекурсії та обрізання.
  *
  * @param A Перша матриця (A.cols).
  * @param B Друга матриця (B.rows).
  * @return Результуюча матриця.
  * @throws std::invalid_argument Якщо розміри матриць несумісні (A.cols != B.rows).
  */
    Matrix multiply(const Matrix& A, const Matrix& B);

}