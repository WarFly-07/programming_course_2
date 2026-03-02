#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
// Lab 10
// TODO: реализуйте решение по заданию в labs/lab10_functions/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
using namespace std;

const int N = 1000;
const int MAX_VALUE = 17;
const int RANGE = 18;

void generateSortedArray(int* arr, int size);
void packArray(int* arr, int size, int* packed);
void unpackArray(int* packed, int* restored, int size);
void printArray(int* arr, int size);
int main()
{
    srand(time(NULL));

    int original[N];
    int packed[RANGE] = {0};
    int restored[N];

    generateSortedArray(original, N);
    packArray(original, N, packed);
    unpackArray(packed, restored, N);

    cout << "Perviy\n";
    printArray(original, 30);

    cout << "\nPosledniy\n";
    printArray(restored, 30);

    return 0;
}
void generateSortedArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand() % RANGE;

    sort(arr, arr + size);
}
void packArray(int* arr, int size, int* packed)
{
    for(int i = 0; i < size; i++)
        packed[arr[i]]++;
}
void unpackArray(int* packed, int* restored, int size)
{
    int index = 0;

    for(int value = 0; value < RANGE; value++)
    {
        for(int count = 0; count < packed[value]; count++)
        {
            restored[index++] = value;
        }
    }
}
void printArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}    

