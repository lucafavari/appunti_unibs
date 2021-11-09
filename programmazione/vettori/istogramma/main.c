#include <stdio.h>
#include <stdlib.h>

void disegna_istogramma(int v[], int n, int max)
{
    int massimo = v[0];
    for (int i = 0; i < n; ++i) {
        if (v[i] > massimo)
            massimo = v[i];
    }
    double f = (double)max / massimo;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)(v[i] * f); ++j) {
            printf("*");
        }
        printf("\n");
    }
}


void disegna_istogramma_verticale(int v[], int n, int max)
{
    int massimo = v[0];
    for (int i = 0; i < n; ++i) {
        if (v[i] > massimo)
            massimo = v[i];
    }
    double f = (double)max / massimo;
    for (int altezza = max; altezza > 0; altezza--)
    {
        for (int i = 0; i < n; ++i) {
            if ((int)(v[i] * f) >= altezza)
                printf(" *");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    //Questa scrittura utile per velocizzare gli esercizi
    //prevede che il compilatore decida la dimensione del vettore
    //in base alla lista dei valori passati tra parentesi graffe
    /*
    int v[] = {56, 98, 13, 45, 67};
    printf("Istogramma orizzontale\n");
    disegna_istogramma(v, 5, 15);
    printf("Istogramma verticale");
    disegna_istogramma_verticale(v, 5, 15);
    return 0;
     */
    int v[13];
    for (int i = 0; i < 6; ++i) {
        v[i] = 0;
    }
    for (int i = 0; i < 10000; ++i) {
        int lancio = rand()%6;
        v[lancio]++;
    }
    disegna_istogramma(v, 6, 20);

    for (int i = 0; i < 13; ++i) {
        v[i] = 0;
    }
    for (int i = 0; i < 10000; ++i) {
        int lancio = rand()%6 + 1 + rand()%6 + 1;
        v[lancio]++;
    }
    disegna_istogramma(v, 13, 20);

}
