#include "gtest/gtest.h"
#include "../src/Strassen.h"

// Тести для граничних випадків Штрассена
TEST(StrassenEdgeCaseTest, NonPowerOfTwo_3x3) {
    // Arrange:
    Matrix A(3, 3);
    Matrix B(3, 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A.at(i, j) = Complex(i * 2, j * 2);
            B.at(i, j) = Complex(i - j, j + 1);
        }
    }

    // Act: Множимо двома способами
    // 1. Padding (доповнення) матриць до 4x4
    // 2. Виклик рекурсивного множення
    // 3. Unpadding (обрізання) результату назад до 3x3
    Matrix strassenResult = Strassen::multiply(A, B);
    Matrix classicResult = A.multiplyClassic(B);

    // Assert: Перевіряємо, що результати ідентичні
    ASSERT_EQ(strassenResult, classicResult);
}

TEST(StrassenEdgeCaseTest, RectangularMatrices_3x5_mul_5x2) {
    // Arrange: Створюємо прямокутні матриці
    Matrix A(3, 5);
    Matrix B(5, 2);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 5; ++j)
            A.at(i, j) = Complex(i + 1, j + 1);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 2; ++j)
            B.at(i, j) = Complex(j + 1, i + 1);

    // Act: Множимо двома способами
    // max(3, 5, 5, 2) = 5 -> nextPowerOfTwo(5) = 8
    // Обидві матриці доповнюються до 8x8
    // Результуюча матриця має бути 3x2.
    Matrix strassenResult = Strassen::multiply(A, B);
    Matrix classicResult = A.multiplyClassic(B);

    // Assert
    ASSERT_EQ(strassenResult.getRows(), 3);
    ASSERT_EQ(strassenResult.getCols(), 2);
    ASSERT_EQ(strassenResult, classicResult);
}

TEST(StrassenEdgeCaseTest, SingleElement_1x1) {
    // Arrange
    Matrix A(1, 1);
    A.at(0, 0) = Complex(5, 2);

    Matrix B(1, 1);
    B.at(0, 0) = Complex(3, 4);

    // Act
    Matrix strassenResult = Strassen::multiply(A, B);
    Matrix classicResult = A.multiplyClassic(B);

    // Assert
    ASSERT_EQ(strassenResult, classicResult);
}


TEST(StrassenEdgeCaseTest, ThrowsOnMismatchedMultiplication) {
    // Arrange
    Matrix A(3, 4);
    Matrix B(5, 2);

    // Act & Assert
    // Перевіряємо, що виклик Strassen::multiply кидає виняток
    ASSERT_THROW(Strassen::multiply(A, B), std::invalid_argument);
}
