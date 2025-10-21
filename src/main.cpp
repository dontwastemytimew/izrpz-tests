#include "Strassen.h"
#include <iostream>
#include <chrono>

int main() {
    using namespace std;

    int N = 4;
    Matrix A(N, N), B(N, N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A.at(i, j) = Complex(i + 1, j + 1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B.at(i, j) = Complex(j + 1, i + 1);

    cout << "Matrix A:\n" << A << "\n";
    cout << "Matrix B:\n" << B << "\n";

    try {
        auto start = chrono::high_resolution_clock::now();
        
        Matrix C = Strassen::multiply(A, B);
        
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "Result of Strassen multiplication:\n" << C << "\n";
        
        cout << "Time for Strassen multiplication of " << N << "x" << N
             << " matrices: " << elapsed.count() * 1000.0 << " ms.\n";

        cout << "\nChecking against classic multiplication...\n";
        Matrix C_classic = A.multiplyClassic(B);
        if (C == C_classic) {
            cout << "SUCCESS: Strassen result matches classic result.\n";
        } else {
            cout << "FAILURE: Strassen result DOES NOT match classic result.\n";
            cout << "Classic result:\n" << C_classic << "\n";
        }

    } catch (const std::exception& e) {
        cerr << "An error occurred: " << e.what() << '\n';
    }

    return 0;
}