#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool readTwoInts(string line, int& a, int& b) {
    stringstream ss(line);
    ss >> a >> b;

    if (ss.fail()) {
        return false;
    }

    string extra;
    if (ss >> extra) {
        return false;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream fin("input.txt");
    ofstream matrixFile("matrix.txt");
    ofstream listFile("list.txt");
    ofstream edgesFile("edges.txt");

    if (!fin.is_open()) {
        cout << "Ошибка: не удалось открыть input.txt\n";
        return 1;
    }

    string line;
    int testNumber = 0;

    while (getline(fin, line)) {
        int n, m;

        // Ищем строку вида: количество вершин и количество рёбер
        if (!readTwoInts(line, n, m)) {
            continue;
        }

        if (n <= 0 || m < 0) {
            continue;
        }

        int** matrix = new int*[n];

        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }

        bool graphIsCorrect = true;

        for (int i = 0; i < m; i++) {
            string edgeLine;
            int a, b;

            if (!getline(fin, edgeLine)) {
                graphIsCorrect = false;
                break;
            }

            if (!readTwoInts(edgeLine, a, b)) {
                graphIsCorrect = false;
                break;
            }

            if (a < 1 || a > n || b < 1 || b > n) {
                graphIsCorrect = false;
                break;
            }

            // Неориентированный граф
            matrix[a - 1][b - 1] = 1;
            matrix[b - 1][a - 1] = 1;
        }

        if (!graphIsCorrect) {
            for (int i = 0; i < n; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            continue;
        }

        testNumber++;

        matrixFile << "=============================\n";
        matrixFile << "Граф " << testNumber << "\n";
        matrixFile << "Количество вершин: " << n << "\n";
        matrixFile << "Количество рёбер: " << m << "\n\n";
        matrixFile << "Матрица смежности:\n\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrixFile << matrix[i][j] << " ";
            }
            matrixFile << "\n";
        }

        matrixFile << "\n";

        listFile << "=============================\n";
        listFile << "Граф " << testNumber << "\n";
        listFile << "Список смежности:\n\n";

        for (int i = 0; i < n; i++) {
            listFile << i + 1 << ": ";

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    listFile << j + 1 << " ";
                }
            }

            listFile << "\n";
        }

        listFile << "\n";

        edgesFile << "=============================\n";
        edgesFile << "Граф " << testNumber << "\n";
        edgesFile << "Последовательность рёбер:\n\n";

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    edgesFile << i + 1 << " " << j + 1 << "\n";
                }
            }
        }

        edgesFile << "\n";

        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    fin.close();
    matrixFile.close();
    listFile.close();
    edgesFile.close();

    cout << "Готово. Обработано графов: " << testNumber << endl;
    cout << "Созданы файлы: matrix.txt, list.txt, edges.txt\n";

    return 0;
}