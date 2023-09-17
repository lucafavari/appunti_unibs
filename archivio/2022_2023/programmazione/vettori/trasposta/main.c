#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 3

int main() {
    int m[N][N], t[M][N];
    //Inserisco dei valori in m
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            m[i][j] = rand()%100;
        }

    }
    printf("Matrice originale\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            t[j][i] = m[i][j];
        }
    }
    //Matrice trasposta
    printf("Matrice trasposta\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%3d", t[i][j]);
        }
        printf("\n");
    }
    //Cosa succede dovendo fare la rotazione "sul posto"
    //Così non andrebbe bene
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int temp = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = temp;
        }
    }

    int v[] = {1,2,3,4,5,6};
    for (int i = 0; i < 3; ++i) {
        int temp = v[i];
        v[i] = v[5-i];
        v[5-i] = temp;
    }
    printf("Vettore per capire come funziona l'inversione sul posto\n");
    for (int i = 0; i < 6; ++i) {
        printf("%3d", v[i]);
    }

    printf("\nMatrice trasposta sul posto\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
