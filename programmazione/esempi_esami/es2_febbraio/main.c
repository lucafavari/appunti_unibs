#include <stdio.h>
#include <stdlib.h>

#define N 10

float distanza(float v1[], float v2[], int n)
{
    float totale = 0;
    for (int i = 0; i < n; i++)
        //totale += abs(v1[i] - v2[2]);
    {
        float differenza = v1[i] - v2[i];
        if (differenza < 0)
            differenza = -differenza;
        totale += differenza;
    }
    return totale;
}

int riga_vicina(float M[][N], float V[], int n)
{
    int minimo = distanza(M[0], V, n);
    for (int i = 1; i < n; i++)
    {
        float d = distanza(M[i], V, n);
        if (d < minimo)
            minimo = d;
        //if (distanza(M[i], V, n) < minimo)
        //    minimo = distanza(M[i], V, n);
    }
    return minimo;
}

int main()
{
    float M[N][N], V[N];
    //....
    int riga = riga_vicina(M, V, N);
    return 0;
}
