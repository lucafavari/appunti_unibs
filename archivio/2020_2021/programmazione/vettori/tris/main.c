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
        return 'O';
    if (n == 2)
        return 'X';
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
    for (int i = 0; i < n; i++)
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

/**
Controllo della correttezza di una mossa
Ritorna 1 se la mossa è corretta, 0 altrimenti
*/

int mossa_corretta(int m[][N], int n, int riga, int colonna)
{
    if (riga < 0 || riga >= n)
        return 0;
    if (colonna < 0 || colonna >= N)
        return 0;
    if (m[riga][colonna] != 0)
        return 0;
    return 1;
}

int main()
{
    int tris[N][N];
    int turno = 1;
    int controllo_termine = 0;
    inizializza_griglia(tris, N);
    stampa_griglia(tris, N);
    while(controllo_termine == 0)
    {
        int riga, colonna;
        printf("Fai la tua mossa giocatore %d\n", turno);
        scanf("%d", &riga);
        scanf("%d", &colonna);

        //while(mossa_corretta(tris, N, riga, colonna) == 0)
        while(!mossa_corretta(tris, N, riga-1, colonna-1))
        {
            printf("Attenzione, fai una mossa corretta\n", turno);
            scanf("%d", &riga);
            scanf("%d", &colonna);
        }
        riga--;
        colonna--;
        tris[riga][colonna] = turno;
        stampa_griglia(tris, N);
        if (turno == 1)
            turno = 2;
        else
            turno = 1;
        controllo_termine = controllo(tris, N);
    }
    if (controllo_termine == 1)
        printf("Hai vinto giocatore 1\n");
    else if (controllo_termine == 2)
        printf("Hai vinto giocatore 2\n");
    else
        printf("La partita è finita in parità\n");


    /*tris[0][0] = 1;
    tris[1][1] = 2;
    stampa_griglia(tris, N);
    printf("Controllo %d\n", controllo(tris, N));
    tris[1][0] = 2;
    tris[1][2] = 2;
    stampa_griglia(tris, N);
    printf("Controllo %d\n", controllo(tris, N));
    */
    return 0;
}




