#include <stdio.h>
#include <stdlib.h>

#define RIGHE 4
#define COLONNE 3

int main() {
    int m[RIGHE][COLONNE], t[COLONNE][RIGHE];
    //Ciclo esterno per muoversi sulle righe
    for (int i = 0; i < RIGHE; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < COLONNE; ++j) {
            m[i][j] = rand()%100;
        }
    }
    for (int i = 0; i < RIGHE; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < COLONNE; ++j) {
            t[j][i] = m[i][j];
        }
    }

    for (int i = 0; i < RIGHE; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < COLONNE; ++j) {
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
    for (int i = 0; i < COLONNE; ++i) {
        //ciclo interno per muoversi sulle colonne
        for (int j = 0; j < RIGHE; ++j) {
            printf("%5d",t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
