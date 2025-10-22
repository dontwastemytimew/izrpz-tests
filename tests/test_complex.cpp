#include "gtest/gtest.h"
#include "../src/Complex.h"

// Тест-кейс для класу Complex
// Перший параметр: назва "групи" тестів
// Другий параметр: назва конкретного тесту
TEST(ComplexTest, Addition) {
    // Arrange
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex expected(4.0, 6.0);

    // Act
    Complex result = a + b;

    // Assert
    ASSERT_EQ(result, expected);
}

TEST(ComplexTest, Multiplication) {
    // Arrange
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    // (1*3 - 2*4) + (1*4 + 2*3)i = (3 - 8) + (4 + 6)i = -5 + 10i
    Complex expected(-5.0, 10.0);

    // Act
    Complex result = a * b;

    // Assert
    ASSERT_EQ(result, expected);
}

TEST(ComplexTest, EqualityWithEpsilon) {
    // Arrange
    Complex a(1.0, 1.0);
    Complex b(1.000000001, 0.999999999);
    Complex c(1.0, 1.1);

    // Assert
    // ПРЯМО ПЕРЕВІРЯЄМО, ЩО РІЗНИЦЯ МЕНША ЗА EPSILON
    // Це найнадійніший спосіб тестування float/double.
    ASSERT_NEAR(a.re, b.re, EPSILON);
    ASSERT_NEAR(a.im, b.im, EPSILON);

    // Перевіряємо, що наш operator== теж працює для очевидно нерівних чисел
    ASSERT_NE(a, c);
}