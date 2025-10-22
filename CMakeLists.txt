cmake_minimum_required(VERSION 3.14)

project(izrpz_tests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Налаштування GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG    main
)
# Вимикаємо збірку тестів самого GoogleTest
set(GTEST_DISABLE_TESTS ON CACHE BOOL "")
FetchContent_MakeAvailable(googletest)


# Створюємо БІБЛІОТЕКУ
add_library(strassen_lib
        src/Matrix.cpp
        src/Strassen.cpp
)
# (Папка src/ буде доступна для #include)
target_include_directories(strassen_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)



add_executable(main src/main.cpp
        tests/test_matrix.cpp)

target_link_libraries(main PRIVATE strassen_lib)



enable_testing()

add_executable(run_tests
        tests/test_complex.cpp
        tests/test_matrix.cpp

)


target_link_libraries(run_tests PRIVATE
        strassen_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)