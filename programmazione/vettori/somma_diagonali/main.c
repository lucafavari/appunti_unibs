#include <stdio.h>
#include <stdlib.h>

#define N 3

int main() {
    int m[N][N];
    //Riempimento casuale delle celle della matrice
    //Ciclo esterno per muoversi sulle righe
    for (int i = 0; i < N; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < N; ++j) {
            m[i][j] = rand()%100;
        }
    }
    int somma_principale = 0;
    int somma_secondaria = 0;
    for (int i = 0; i < N; ++i) {
        somma_principale += m[i][i];
    }
    for (int i = 0; i < N; ++i) {
        somma_secondaria += m[i][N - i - 1];
    }
    for (int i = 0; i < N; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < N; ++j) {
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
    printf("La diagonale principale ha somma: %d\n", somma_principale);
    printf("La diagonale secondaria ha somma: %d\n", somma_secondaria);

    return 0;
}
