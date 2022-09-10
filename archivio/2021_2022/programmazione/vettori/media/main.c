#include <stdio.h>
#include <stdlib.h>

#define MAX 100

double media(double v[], int n)
{
    double m = 0;
    for (int i = 0; i < n; i++)
        m += v[i];
    return m/n;
}

int main() {
    double vettore[MAX];
    int n = 50;
    for (int i = 0; i < n; i++)
        vettore[i] = rand()/100.0;
    printf("Media del vettore: %lf\n", media(vettore, n));
    printf("Indirizzo di partenza del vettore: %p\n", vettore);
    printf("Indirizzo di partenza del vettore: %p\n", &vettore[0]);

    return 0;
}
