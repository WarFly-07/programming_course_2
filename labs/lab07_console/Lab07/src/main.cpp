#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Lab 07
// TODO: реализуйте решение по заданию в labs/lab07_console/README.md
//
// Рекомендация по выводу:
// - без лишнего
// - числа через пробел
// - если несколько строк — в фиксированном порядке

int main() {
    setlocale(LC_ALL, "Russian");
    //Sinus
    double x0 = 0.0;
    if (!(cin >> x0)) {
        cout << "Подумай ещё";
        return 0;
    }
    double dot = (4.0 - x0) / 10.0;
    for (int i = 0; i < 10; i++) {
        double x = x0 + dot * (i + 1);
        cout << sin(x) / x << " "; 
    }
    cout << endl; 
    //Fibbi
    long long max_value = 0;
    cin >> max_value;
    long long a = 1, b = 1;
    long long S = 0;
    int N = 0;
    while (S + a <= max_value) {
        S += a;
        long long temp = a + b;
        a = b;
        b = temp;
        N++;
    }
    cout << N << " " << S << endl; 
    //Creditka
    int months;
    double credit, stavka;
    double ost, part, percent, payment, vsego_percent;

    scanf("%lf %d %lf", &credit, &months, &stavka); 

    ost = credit;
    part = credit / months;
    vsego_percent = 0;
    stavka /= 1200.0; 

    for (int i = 1; i <= months; i++) {
        percent = ost * stavka;        
        payment = part + percent;
        if (ost < 0) ost = 0;
        printf("%.2f %.2f %.2f\n", ost, percent, payment); 
        ost -= part;
        vsego_percent += percent;
    }
    printf("%.2f\n", vsego_percent); 
    return 0;
}