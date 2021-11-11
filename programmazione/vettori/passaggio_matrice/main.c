#include <stdio.h>
#include <stdlib.h>

#define RIGHE 4
#define COLONNE 3

int trova_massimo(int m[][COLONNE], int r, int c)
{
    int massimo = m[0][0];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (m[i][j] > massimo)
                massimo = m[i][j];
        }
    }
    return massimo;
}

void inizializza(int r, int c, int m[][c])
{
    for (int i = 0; i < r; ++i) {
    //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < c; ++j) {
            m[i][j] = rand()%100;
        }
    }
}

void stampa_matrice(int m[][COLONNE], int r, int c)
{
    for (int i = 0; i < r; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < c; ++j) {
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[RIGHE][COLONNE];

    //.....
    inizializza(m, RIGHE, COLONNE);
    stampa_matrice(m, RIGHE, COLONNE);
    int massimo = trova_massimo(m, RIGHE, COLONNE);
    printf("Il massimo vale: %d\n", massimo);
    return 0;
}
