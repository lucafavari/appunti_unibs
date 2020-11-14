#include <stdio.h>
#include <stdlib.h>

#define N 3

void inizializza_griglia(int m[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
}

char stampa_simbolo(int n)
{
    if (n == 0)
        return ' ';
    if (n == 1)
        return 'o';
    if (n == 2)
        return 'x';
}

void stampa_valori_riga(int v[])
{
    printf(" %c | %c | %c\n", stampa_simbolo(v[0]),
           stampa_simbolo(v[1]), stampa_simbolo(v[2]));
}

void stampa_linea()
{
    printf("------------\n");
}

void stampa_griglia(int m[][N], int n)
{
    stampa_valori_riga(m[0]);
    stampa_linea();
    stampa_valori_riga(m[1]);
    stampa_linea();
    stampa_valori_riga(m[2]);
}

/**
    La funzione di controllo restituisce
    1 se ha vinto il giocatore 1
    2 se ha vinto il giocatore 2
    0 se la partita può continuare
    3 se la partita è patta
*/

int controllo(int m[][N], int n)
{
    //controllo per righe
    for (int i = 0; i < N; i++)
        if (m[i][0] == m[i][1] &&
            m[i][1] == m[i][2] && m[i][0] != 0)
            return m[i][0];
    //controllo per colonne
    for (int i = 0; i < N; i++)
        if (m[0][i] == m[1][i] &&
            m[1][i] == m[2][i] && m[0][i] != 0)
            return m[0][i];
    //Controllo diagonale principale
    if (m[0][0] == m[1][1] &&
            m[1][1] == m[2][2] && m[0][0] != 0)
            return m[0][0];
    if (m[0][2] == m[1][1] &&
            m[1][1] == m[2][0] && m[1][1] != 0)
            return m[1][1];
    int cont = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] == 0)
                cont++;
    if (cont > 0)
        return 0;
    return 3;
}

int main()
{
    int tris[N][N];
    inizializza_griglia(tris, N);
    stampa_griglia(tris, N);
    tris[0][0] = 1;
    tris[1][1] = 2;
    stampa_griglia(tris, N);
    return 0;
}
