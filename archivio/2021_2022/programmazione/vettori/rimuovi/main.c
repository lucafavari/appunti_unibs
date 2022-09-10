#include <stdio.h>
#include <stdlib.h>

int rimuovi(int v[], int n, int pos)
{
    if (pos < 0 || pos > n - 1)
        return n;
    for (int i = pos; i < n - 1; i++)
        v[i] = v[i + 1];
    return n - 1;
}

void riempi(int v[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
        v[i] = rand()%(max - min) + min;
}

void stampa_vettore(int v[], int n)
{
    printf("[ %d", v[0]);
    for(int i = 1; i < n; i++)
        printf(", %d", v[i]);
    printf("]\n"); //[ 1, 2, 3]
}

#define MAX 100

int main() {
    int v[MAX];
    int n = 10;
    riempi(v, 10, 1, 20);
    stampa_vettore(v, n);
    n = rimuovi(v, n, -100000);
    stampa_vettore(v, n);
    n = rimuovi(v, n, 4);
    stampa_vettore(v, n);
    n = rimuovi(v, n, 8);
    stampa_vettore(v, n);
    return 0;
}
