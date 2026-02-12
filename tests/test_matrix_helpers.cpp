#include "gtest/gtest.h"
#include "../src/Matrix.h"

TEST(MatrixHelpersTest, SplitAndCombine) {
    Matrix Original(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Original.at(i, j) = Complex(i, j);
        }
    }

    // (Split): Розділяємо її на 4 чверті
    Matrix M11(2, 2), M12(2, 2), M21(2, 2), M22(2, 2);
    Matrix::split(Original, M11, M12, M21, M22);

    // (Split): Перевіряємо, чи кожна чверть скопіювалась правильно
    ASSERT_EQ(M11.at(0, 0), Complex(0, 0)); // Верхній лівий кут
    ASSERT_EQ(M12.at(0, 1), Complex(0, 3)); // Верхній правий
    ASSERT_EQ(M21.at(1, 0), Complex(3, 0)); // Нижній лівий
    ASSERT_EQ(M22.at(1, 1), Complex(3, 3)); // Нижній правий

    // (Combine): Збираємо матрицю назад з цих чвертей
    Matrix Recombined(4, 4);
    Matrix::combine(Recombined, M11, M12, M21, M22);

    // (Combine): Перевіряємо, що зібрана матриця ідентична вихідній
    ASSERT_EQ(Original, Recombined);
}
