#include <stdio.h>

#define N 10

float Distanza(float v1[], float v2[], int n)
{
    float somma = 0;
    for (int i = 0; i < n; ++i) {
        float differenza = v1[i] - v2[i];
        if (differenza < 0)
            differenza = -differenza;
        somma += differenza;
    }
    return somma/n;
}

int cerca_minimo(float m[][N], float v[], int n)
{
    int riga_minima = 0;
    for (int i = 0; i < n; ++i) {
        if (Distanza(m[i], v, n) < Distanza(m[riga_minima], v, n))
            riga_minima = i;
    }
    return riga_minima;
}

//Non richiesto nell'esercizio originale
int cerca_minimo_colonne(float m[][N], float v[], int n)
{
    int colonna_minima = 0;
    float distanza_minima;
    int v_temp[N];
    for (int i = 0; i < n; ++i) {
        v_temp[i] = m[i][0];
    }
    distanza_minima = Distanza(v_temp, v, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v_temp[j] = m[j][i];
        }
        if (Distanza(v_temp, v, n) < distanza_minima) {
            colonna_minima = i;
            distanza_minima = Distanza(v_temp, v, n);
        }
    }
    return colonna_minima;
}


int main() {
    float m[N][N], v[N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("Inserisci un elemento: ");
            scanf("%f", &m[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("Inserisci un elemento del vettore: ");
        scanf("%f", &v[i]);
    }
    printf("La riga di distanza minima è quella di indice: %d",
           cerca_minimo(m, v, N));
    return 0;
}
