#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const double EPS = 1e-9;

void printMatrix(ofstream& fout, double** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        fout << "| ";
        for (int j = 0; j < n; j++) {
            fout << setw(10) << fixed << setprecision(4) << a[i][j] << " ";
        }
        fout << "| " << setw(10) << fixed << setprecision(4) << a[i][n] << " |\n";
    }
    fout << "\n";
}

int main() {
    
}