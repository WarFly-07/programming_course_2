#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream fin("input.txt");
    ofstream matrixFile("matrix.txt");
    ofstream listFile("list.txt");
    ofstream edgesFile("edges.txt");

    if (!fin.is_open()) {
        cout << "Не удалось открыть input.txt\n";
        return 1;
    }

    int n, m;
    fin >> n >> m;


    int** matrix = new int*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;

        matrix[a - 1][b - 1] = 1;
        matrix[b - 1][a - 1] = 1;
    }

  
    matrixFile << "Матрица смежности:\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixFile << matrix[i][j] << " ";
        }
        matrixFile << "\n";
    }


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


    edgesFile << "Последовательность рёбер:\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                edgesFile << i + 1 << " " << j + 1 << "\n";
            }
        }
    }


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    fin.close();
    matrixFile.close();
    listFile.close();
    edgesFile.close();

    cout << "Готово. Файлы matrix.txt, list.txt и edges.txt созданы.\n";

    return 0;
}