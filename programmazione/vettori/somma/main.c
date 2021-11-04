#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int somma(int v[], int n)
{
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int somma1(int *v, int n)
{
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += *(v + i);
    }
    return s;
}

int somma2(int *v, int n)
{
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
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

int main() {
    int v[MAX];
    int n = 10;
    riempi(v, n, 0, 10);
    stampa_vettore(v, n);
    printf("La somma degli elementi vale: %d\n", somma(v, n));
    printf("La somma degli elementi vale: %d\n", somma1(v, n));
    printf("La somma degli elementi vale: %d\n", somma2(v, n));
    return 0;
}
