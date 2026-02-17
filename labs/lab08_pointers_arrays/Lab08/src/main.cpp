#include <iostream>
// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
using namespace std;

#define N 10
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    // Стат массив индекс
    int spis_1[N];
    for (int i = 0; i < N; i++)
        spis_1[i] = i * i;

    cout << "Статический индексный: ";
    for (int i = 0; i < N; i++)
        cout << spis_1[i] << " ";
    cout << "\n";

    // Стат массив указатель
    int spis_2[N];
    int* ukaz = spis_2;

    for (int i = 0; i < N; i++) {
        *ukaz = i * i;
        ukaz++;
    }

    ukaz = spis_2;
    cout << "Статический через указатель: ";
    for (int i = 0; i < N; i++) {
        cout << *ukaz << " ";
        ukaz++;
    }
    cout << "\n";

    // Динам массив индекс
    int* spis_3 = new int[N];

    for (int i = 0; i < N; i++)
        spis_3[i] = i * i;

    cout << "Динамический индексный: ";
    for (int i = 0; i < N; i++)
        cout << spis_3[i] << " ";
    cout << "\n";

    delete[] spis_3;

    // Динам массив указатель
    int* spis_4 = new int[N];
    int* ukaz_2 = spis_4;

    for (int i = 0; i < N; i++) {
        *ukaz_2 = i * i;
        ukaz_2++;
    }

    ukaz_2 = spis_4;
    cout << "Динамический через указатель: ";
    for (int i = 0; i < N; i++) {
        cout << *ukaz_2 << " ";
        ukaz_2++;
    }
    cout << "\n";

    delete[] spis_4;


    // Объединение двух упорядоченных массивов


    int* arr_1 = new int[11]{ -1, 2, 5, 7, 11, 13, 14, 17, 19, 20, 20 };
    int* arr_2 = new int[8]{ -10, 3, 4, 12, 14, 16, 19, 25 };
    int* arr_sliyn = new int[19];

    int i = 0, j = 0, k = 0;

    while (i < 11 && j < 8) {
        if (arr_1[i] <= arr_2[j]) {
            arr_sliyn[k++] = arr_1[i++];
        }
        else {
            arr_sliyn[k++] = arr_2[j++];
        }
    }

    while (i < 11)
        arr_sliyn[k++] = arr_1[i++];

    while (j < 8)
        arr_sliyn[k++] = arr_2[j++];

    cout << "Объединённый массив: ";
    for (int t = 0; t < 19; t++)
        cout << arr_sliyn[t] << " ";
    cout << "\n";

    delete[] arr_1;
    delete[] arr_2;
    delete[] arr_sliyn;

    // Двусвязный список из 10 элементов

    Node* head = nullptr;

    for (int i = 0; i < 10; i++) {
        Node* newNode = new Node(i);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    cout << "Список вперёд: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    cout << "Список назад: ";
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << "\n";

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

