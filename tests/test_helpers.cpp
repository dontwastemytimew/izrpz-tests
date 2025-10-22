#include "gtest/gtest.h"
#include "gtest/gtest-param-test.h"
#include "../src/Strassen.h"
#include <tuple>

// Клас-фікстура для параметризованого тесту
// Параметр - це пара {вхідне число, очікуваний результат}
class NextPowerOfTwoTest : public ::testing::TestWithParam<std::tuple<int, int>> {
};


TEST_P(NextPowerOfTwoTest, HandlesVariousInputs) {
    // Отримуємо параметри
    int input = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    // Act & Assert
    ASSERT_EQ(Strassen::nextPowerOfTwo(input), expected);
}


// Набір даних
INSTANTIATE_TEST_SUITE_P(
    Default,
    NextPowerOfTwoTest,
    ::testing::Values(
        std::make_tuple(3, 4),    // Перевірка не степеня двійки
        std::make_tuple(4, 4),    // Перевірка степеня двійки
        std::make_tuple(5, 8),    // Перевірка іншого не степеня двійки
        std::make_tuple(7, 8),
        std::make_tuple(8, 8),    // Перевірка іншого степеня двійки
        std::make_tuple(1, 1),    // Граничний випадок
        std::make_tuple(0, 1)     // Граничний випадок
    )
);