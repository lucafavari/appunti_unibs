#include <stdio.h>
#include <stdlib.h>

#define N 4

void riempi_matrice(int m[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand()%100 + 1;
}

void stampa_matrice(int m[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%6d", m[i][j]);
        printf("\n");
    }

}

int somma_principale(int m[][N], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += m[i][i];
    return s;
}

int somma_secondaria(int m[][N], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += m[n - i - 1][i];
    return s;
}

//Non è ralativa a questo problema, è solo per rispondere
//a una domanda posta a lezione da uno studente
int leggi_input()
{
    int v;
    printf("Inserisci un numero: ");
    scanf("%d", &v);
    return v;
}

int main()
{
    int m[N][N];
    int v;
    v = leggi_input();
    printf("%d", v);
    riempi_matrice(m, N);
    stampa_matrice(m, N);
    printf("Diagonale principale: %d", somma_principale(m, N));
    printf("Diagonale secondaria: %d", somma_secondaria(m, N));
    return 0;
}
