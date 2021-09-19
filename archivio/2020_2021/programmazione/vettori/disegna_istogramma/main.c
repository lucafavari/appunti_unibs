#include <stdio.h>
#include <stdlib.h>

int massimo(int v[], int n)
{
    int m = v[0];
    for (int i = 0; i < n; i++)
        if (v[i] > m)
            m = v[i];
    return m;
}

void disegna_barra(int n)
{
    for (int i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

void disegna_istogramma(int v[], int n, int max)
{
    int m = massimo(v, n);
    for (int i = 0; i < n; i++)
        disegna_barra((float)v[i]/m*max);
}

int main()
{
    int v[] = {23,344,123,544,235};
    disegna_istogramma(v, 5, 30);
    return 0;
}
