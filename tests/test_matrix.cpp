#include "gtest/gtest.h"
#include "../src/Matrix.h"

// Тести для базових операцій Matrix
TEST(MatrixTest, ConstructorAndAccess) {
    // Arrange & Act
    Matrix A(2, 3);
    A.at(0, 0) = Complex(1, 1);
    A.at(1, 2) = Complex(5, 5);

    // Assert: Перевіряємо розміри та значення
    ASSERT_EQ(A.getRows(), 2);
    ASSERT_EQ(A.getCols(), 3);
    ASSERT_EQ(A.at(0, 0), Complex(1, 1));
    ASSERT_EQ(A.at(1, 2), Complex(5, 5));
    ASSERT_EQ(A.at(0, 1), Complex(0, 0)); // Перевіряємо, що інші елементи - нулі
}

TEST(MatrixTest, Addition) {
    // Arrange
    Matrix A(2, 2);
    A.at(0, 0) = Complex(1, 1);
    A.at(1, 1) = Complex(4, 4);

    Matrix B(2, 2);
    B.at(0, 0) = Complex(2, 2);
    B.at(1, 1) = Complex(3, 3);
    
    Matrix Expected(2, 2);
    Expected.at(0, 0) = Complex(3, 3);
    Expected.at(1, 1) = Complex(7, 7);

    // Act
    Matrix Result = A + B;

    // Assert
    ASSERT_EQ(Result, Expected);
}

//Тести на винятки

TEST(MatrixTest, ThrowsOnMismatchedAddition) {
    // Arrange
    Matrix A(2, 2);
    Matrix B(3, 3);

    // Act & Assert
    // Перевіряємо, що код A + B кидає саме виняток std::invalid_argument
    ASSERT_THROW(A + B, std::invalid_argument);
}

TEST(MatrixTest, ThrowsOnAccessOutOfBounds) {
    // Arrange
    Matrix A(5, 5);

    // Act & Assert
    // Перевіряємо, що спроба доступу за межами матриці кидає std::out_of_range
    ASSERT_THROW(A.at(10, 10), std::out_of_range);
}
