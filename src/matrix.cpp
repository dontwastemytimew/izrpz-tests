#include "Matrix.h"
#include <stdexcept>

// Ініціалізує data вектором векторів потрібного розміру
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<Complex>(c)) {}

// Реалізація .at() з перевіркою виходу за межі
Complex& Matrix::at(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix access out of range");
    }
    return data[r][c];
}

// Реалізація const .at() з перевіркою
const Complex& Matrix::at(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix access out of range");
    }
    return data[r][c];
}

Matrix Matrix::operator+(const Matrix& other) const {
    // Перевірка сумісності розмірів
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions mismatch for addition");
    }
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res.data[i][j] = data[i][j] + other.data[i][j];
    return res;
}

Matrix Matrix::operator-(const Matrix& other) const {
    // Перевірка сумісності розмірів
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions mismatch for subtraction");
    }
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res.data[i][j] = data[i][j] - other.data[i][j];
    return res;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    // Поелементне порівняння
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// Реалізація класичного множення
Matrix Matrix::multiplyClassic(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions mismatch for multiplication");
    }
    Matrix res(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            Complex sum(0, 0);
            for (int k = 0; k < cols; k++) {
                sum = sum + data[i][k] * other.data[k][j];
            }
            res.data[i][j] = sum;
        }
    }
    return res;
}

// Копіюємо 4 чверті з M у відповідні підматриці
void Matrix::split(const Matrix& M, Matrix& M11, Matrix& M12, Matrix& M21, Matrix& M22) {
    int k = M.rows / 2; // Розмір чверті
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            M11.data[i][j] = M.data[i][j];     // Верхня ліва
            M12.data[i][j] = M.data[i][j + k];   // Верхня права
            M21.data[i][j] = M.data[i + k][j];   // Нижня ліва
            M22.data[i][j] = M.data[i + k][j + k]; // Нижня права
        }
    }
}

// Збираємо матрицю M з 4-х чвертей
void Matrix::combine(Matrix& M, const Matrix& M11, const Matrix& M12, const Matrix& M21, const Matrix& M22) {
    int k = M11.rows; // Розмір чверті
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            M.data[i][j] = M11.data[i][j];
            M.data[i][j + k] = M12.data[i][j];
            M.data[i + k][j] = M21.data[i][j];
            M.data[i + k][j + k] = M22.data[i][j];
        }
    }
}

// Реалізація оператора виводу
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j];
            if (j + 1 < m.cols) os << "\t";
        }
        os << "\n";
    }
    return os;
}