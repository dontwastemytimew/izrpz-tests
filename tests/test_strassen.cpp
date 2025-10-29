#include "gtest/gtest.h"
#include "../src/Strassen.h"
#include "../src/Matrix.h"

// Тести для алгоритму Штрассена
// Створюємо клас-фікстуру (виконуватиметься автоматично перед кожним тестом)
class StrassenTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        A_2x2 = Matrix(2, 2);
        A_2x2.at(0, 0) = Complex(1, 1); A_2x2.at(0, 1) = Complex(2, 2);
        A_2x2.at(1, 0) = Complex(3, 3); A_2x2.at(1, 1) = Complex(4, 4);

        B_2x2 = Matrix(2, 2);
        B_2x2.at(0, 0) = Complex(5, 5); B_2x2.at(0, 1) = Complex(6, 6);
        B_2x2.at(1, 0) = Complex(7, 7); B_2x2.at(1, 1) = Complex(8, 8);

        A_4x4 = Matrix(4, 4);
        I_4x4 = Matrix(4, 4);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                A_4x4.at(i, j) = Complex(i + 1, j + 1);
            }
            I_4x4.at(i, i) = Complex(1, 0); // Одинична матриця
        }
    }

    // Об'єкти, які будуть доступні в тестах
    Matrix A_2x2, B_2x2;
    Matrix A_4x4, I_4x4;
};

TEST_F(StrassenTestFixture, StrassenVsClassic2x2) {
    // Arrange

    // Act
    Matrix strassenResult = Strassen::multiply(A_2x2, B_2x2);
    Matrix classicResult = A_2x2.multiplyClassic(B_2x2);

    // Assert
    ASSERT_EQ(strassenResult, classicResult);
}

TEST_F(StrassenTestFixture, StrassenVsClassic4x4) {
    // Arrange

    // Act
    Matrix strassenResult = Strassen::multiply(A_4x4, A_4x4);
    Matrix classicResult = A_4x4.multiplyClassic(A_4x4);

    // Assert
    ASSERT_EQ(strassenResult, classicResult);
}

TEST_F(StrassenTestFixture, MultiplyByIdentity) {
    // Arrange

    // Act
    Matrix result = Strassen::multiply(A_4x4, I_4x4);

    // Assert
    ASSERT_EQ(result, A_4x4);
}


TEST_F(StrassenTestFixture, MultiplyByZeroMatrix) {
    // Arrange: Створюємо матрицю А та нульову матрицю Z
    Matrix Z_4x4(4, 4);

    // Act:
    Matrix result = Strassen::multiply(A_4x4, Z_4x4);

    // Assert: Перевіряємо, що результат -- це нульова матриця
    ASSERT_EQ(result, Z_4x4);
}
