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
    setlocale(LC_ALL, "Russian");

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cout << "Не удалось открыть input.txt\n";
        return 1;
    }

    if (!fout.is_open()) {
        cout << "Не удалось открыть output.txt\n";
        return 1;
    }

    int m, n;

    while (!(fin >> m >> n)) {
        fin.clear();
        string skip;
        getline(fin, skip);

        if (fin.eof()) {
            cout << "Не удалось найти размеры матрицы в input.txt\n";
            return 1;
        }
    }

    if (m <= 0 || n <= 0) {
        cout << "Некорректные размеры матрицы\n";
        return 1;
    }

    double** a = new double*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new double[n + 1];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (!(fin >> a[i][j])) {
                cout << "Ошибка чтения матрицы из файла\n";
                for (int k = 0; k < m; k++) {
                    delete[] a[k];
                }
                delete[] a;
                return 1;
            }
        }
    }

    fout << "Лабораторная работа №13\n";
    fout << "Метод Гаусса-Жордана\n\n";

    fout << "Исходная матрица системы:\n";
    printMatrix(fout, a, m, n);

    int row = 0;

    for (int col = 0; col < n && row < m; col++) {
        int k = row;

        while (k < m && fabs(a[k][col]) < EPS) {
            k++;
        }

        if (k == m) {
            continue;
        }

        if (k != row) {
            for (int j = 0; j <= n; j++) {
                double temp = a[row][j];
                a[row][j] = a[k][j];
                a[k][j] = temp;
            }
        }

        double div = a[row][col];
        for (int j = 0; j <= n; j++) {
            a[row][j] = a[row][j] / div;
        }

        for (int i = 0; i < m; i++) {
            if (i != row) {
                double factor = a[i][col];
                for (int j = 0; j <= n; j++) {
                    a[i][j] = a[i][j] - a[row][j] * factor;
                }
            }
        }

        row++;
    }

    fout << "Матрица после приведения к ступенчатому виду:\n";
    printMatrix(fout, a, m, n);

    bool noSolution = false;

    for (int i = 0; i < m; i++) {
        bool allZero = true;

        for (int j = 0; j < n; j++) {
            if (fabs(a[i][j]) > EPS) {
                allZero = false;
                break;
            }
        }

        if (allZero && fabs(a[i][n]) > EPS) {
            noSolution = true;
            break;
        }
    }

    if (noSolution) {
        fout << "Система несовместна. Решений нет.\n";
    } else {
        int rank = 0;

        for (int i = 0; i < m; i++) {
            bool nonZeroRow = false;
            for (int j = 0; j < n; j++) {
                if (fabs(a[i][j]) > EPS) {
                    nonZeroRow = true;
                    break;
                }
            }
            if (nonZeroRow) {
                rank++;
            }
        }

        if (rank < n) {
            fout << "Система имеет бесконечно много решений.\n";
            fout << "Единственного решения нет.\n";
        } else {
            fout << "Система имеет единственное решение:\n";

            for (int i = 0; i < n; i++) {
                fout << "x" << i + 1 << " = " << fixed << setprecision(6) << a[i][n] << "\n";
            }
        }
    }

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    fin.close();
    fout.close();

    cout << "Готово. Результат записан в output.txt\n";
    return 0;
}