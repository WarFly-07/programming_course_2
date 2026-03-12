#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#define EOF (-1)

int main() {
    int SIN , SCAN1, WRITE , GETS;
    float SCAN2 ;
    cin >> SIN;
    cout << "SIN = " << SIN << endl;

    scanf("%d %f", &SCAN1, &SCAN2 );
    printf("VIVOD V C : %d %.2f \n", SCAN1, SCAN2);

    char g[10];
    getchar();
    gets(g);
    puts("ETO PUTS");
    puts(g);

    int x, z;
    z = 9;

    FILE *f = fopen("new.txt", "r");
    fscanf(f, "%d", &x);
    printf("chislo iz faila = %d \n", x);
    fclose(f);

    FILE *w = fopen("new.txt", "w");
    fprintf(w, "%d", z);
    fclose(w);

    char buf[20];
    int n = read(0, buf, 20);
    write(1, buf, n);

    FILE *r = fopen("fd.txt", "r");
    while (!feof(f)){
        char c = fgetc(f);
        printf("%c", c);
    }

    return 0;
}