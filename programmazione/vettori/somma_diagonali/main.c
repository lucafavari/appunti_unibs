#include <stdio.h>
#include <stdlib.h>

#define RIGHE 4
#define COLONNE 4

int main() {
    int m[RIGHE][COLONNE];
    int principale = 0, secondaria = 0;
    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            m[i][j] = rand()%100;
        }
    }
    //Calcolo del valore della diagonale principale
    //Primo metodo che denota una certa ottusità
    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            if (i == j){
                principale += m[i][j];
            }
        }
    }
    principale = 0;
    //Codice corretto
    for (int i = 0; i < RIGHE; ++i) {
        principale += m[i][i];
    }
    //Calcolo del valore della diagonale secondaria
    int j = COLONNE - 1;
    for (int i = 0; i < RIGHE; ++i) {
        secondaria += m[i][COLONNE - i - 1];
        //secondaria += m[i][j];
        //j--;
    }
    return 0;
}
