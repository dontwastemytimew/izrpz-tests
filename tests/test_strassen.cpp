#include "gtest/gtest.h"
#include "../src/Strassen.h"

// Тести для алгоритму Штрассена
TEST(StrassenTest, StrassenVsClassic2x2) {
    // Arrange:
    Matrix A(2, 2);
    A.at(0, 0) = Complex(1, 1); A.at(0, 1) = Complex(2, 2);
    A.at(1, 0) = Complex(3, 3); A.at(1, 1) = Complex(4, 4);

    Matrix B(2, 2);
    B.at(0, 0) = Complex(5, 5); B.at(0, 1) = Complex(6, 6);
    B.at(1, 0) = Complex(7, 7); B.at(1, 1) = Complex(8, 8);

    // Act: Множимо двома способами
    Matrix strassenResult = Strassen::multiply(A, B);
    Matrix classicResult = A.multiplyClassic(B);

    // Assert: Перевіряємо, що результати ідентичні
    ASSERT_EQ(strassenResult, classicResult);
}

TEST(StrassenTest, StrassenVsClassic4x4) {
    // Arrange:
    Matrix A(4, 4);
    Matrix B(4, 4);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            A.at(i, j) = Complex(i + 1, j + 1);
            B.at(i, j) = Complex(i - j, j - i);
        }
    }

    // Act:
    Matrix strassenResult = Strassen::multiply(A, B);
    Matrix classicResult = A.multiplyClassic(B);

    // Assert:
    ASSERT_EQ(strassenResult, classicResult);
}

TEST(StrassenTest, MultiplyByIdentity) {
    // Arrange: Створюємо матрицю A та одиничну матрицю I
    Matrix A(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            A.at(i, j) = Complex(i + j, i - j);
        }
    }

    Matrix I(4, 4);
    for (int i = 0; i < 4; ++i) {
        I.at(i, i) = Complex(1, 0);
    }

    // Act:
    Matrix result = Strassen::multiply(A, I);

    // Assert: Перевіряємо, що результат дорівнює A (A * I = A)
    ASSERT_EQ(result, A);
}