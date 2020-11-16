#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

void inizializza_griglia(int m[][M], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < M; j++)
            m[i][j] = rand()%100;
}

void rimuovi_riga_colonna (int m[][M], int n, int R, int C)
{
    //Controllo di correttezza di R e C lasciato al lettore
    for (int i = 0; i < M; i++)
    {
        //Per ogni colonna elemino l'elemento in posizione R
        for (int j = R; j < n - 1; j++)
            m[j][i] = m[j + 1][i];
    }
    for (int i = 0; i < n; i++)
    {
        //Per ogni riga
        for (int j = C; j < M - 1; j++)
            m[i][j] = m[i][j+1];
    }
}

void stampa_matrice(int m[][M], int n, int c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%6d", m[i][j]);
        printf("\n");
    }

}

int main()
{
    int m[N][M];
    inizializza_griglia(m, N);
    stampa_matrice(m, N, M);
    rimuovi_riga_colonna(m, N, 2, 3);
    printf("------\n");
    stampa_matrice(m, N - 1, M - 1);
    rimuovi_riga_colonna(m, N, 1, 1);
    printf("------\n");
    stampa_matrice(m, N - 2, M - 2);
    return 0;
}
