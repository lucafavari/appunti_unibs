#include <stdio.h>
#include <stdlib.h>

#define MAX 100

double prodotto_scalare(double v1[], double v2[], int n)
{
    double p = 0;
    for (int i = 0; i < n; ++i) {
        p += v1[i] * v2[i];
    }
    return p;
}

void stampa_vettore(double v[], int n)
{
    printf("{ %lf", v[0]);
    for(int i = 1; i < n; i++)
        printf(", %lf", v[i]);
    printf("}\n"); //[ 1, 2, 3]
}

int main() {
    double v1[MAX], v2[MAX];
    int n = 3;
    for (int i = 0; i < n; i++){
        v1[i] = rand()%10;
        v2[i] = rand()%10;
    }
    stampa_vettore(v1, n);
    stampa_vettore(v2, n);
    printf("Il prodotto scalare vale: %lf\n", prodotto_scalare(v1, v2, n));
    return 0;
}
