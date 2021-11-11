#include <stdio.h>

#define N 3

/*La matrice contiene
    * 0 se non è stato ancora inserito niente
    * 1 se c'è un simbolo del giocatore 1
    * 2 se c'è un simbolo del giocatore 1
*/
int stato_gioco(int tris[][N], int r)
{
    //controllo del tris nelle righe
    for (int i = 0; i < r; ++i) {
        if (tris[i][0] == tris[i][1] &&
            tris[i][1]== tris[i][2] &&
            tris[i][0] != 0)
        {
            return tris[i][0];
        }
    }
    //controllo del tris nelle colonne
    for (int i = 0; i < N; ++i) {
        if (tris[0][i] == tris[1][i] &&
            tris[1][i]== tris[2][i] &&
            tris[0][i] != 0)
        {
            return tris[0][i];
        }
    }
    //Controllo della diagonale principale
    if (tris[0][0] == tris[1][1] &&
        tris[1][1] == tris[2][2] &&
        tris[0][0] != 0)
        return tris[0][0];
    //Controllo della diagonale secondaria
    if (tris[0][2] == tris[1][1] &&
        tris[1][1] == tris[2][0] &&
        tris[0][2] != 0)
        return tris[0][2];
    int conta_zeri = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < N; ++j) {
            if (tris[i][j] == 0)
                conta_zeri++;
        }
    }
    if (conta_zeri > 0)
        return 0;
    return 3;
}

char codifica(int n)
{
    if (n == 0)
        return ' ';
    if (n == 1)
        return '0';
    if (n == 2)
        return 'X';
}

void mostra_griglia(int tris[][N], int r)
{
    /*
     *  O | X | O
     *  ---------
     *  X | O | X
     *  ---------
     *    | O |
     */
    printf(" %c | %c | %c\n", codifica(tris[0][0]),codifica(tris[0][1]),
           codifica(tris[0][2]));
    for (int i = 1; i < r; ++i) {
        printf("---------\n");
        printf(" %c | %c | %c\n", codifica(tris[i][0]),codifica(tris[i][1]),
               codifica(tris[i][2]));
    }
}

int controllo_input(int tris[][N], int r, int riga, int colonna)
{
    if (riga < 0 || riga > r - 1)
        return -1;
    if (colonna < 0 || colonna > N - 1)
        return -1;
    if (tris[riga][colonna] != 0)
        return -1;
    return 1;
}

void cambio_turno(int *giocatore)
{
    if (*giocatore == 1)
        *giocatore = 2;
    else
        *giocatore = 1;
}

int main() {
    int tris[][N] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    int giocatore = 1;
    int stato = stato_gioco(tris, N);
    printf("Gioco del tris\n");
    mostra_griglia(tris, N);
    while(stato == 0)
    {
        int riga, colonna;
        printf("Inserisci la riga (1,2,3): ");
        scanf("%d", &riga);
        printf("Inserisci la colonna (1,2,3): ");
        scanf("%d", &colonna);
        while (controllo_input(tris, N, riga - 1, colonna - 1) == -1)
        {
            printf("Attenzione, i valori inseriti non sono corretti!\n");
            printf("Inserisci la riga: ");
            scanf("%d", &riga);
            printf("Inserisci la colonna: ");
            scanf("%d", &colonna);
        }
        tris[riga - 1][colonna - 1] = giocatore;
        mostra_griglia(tris, N);
        cambio_turno(&giocatore);
        stato = stato_gioco(tris, N);
    }
    switch (stato) {
        case 1:
            printf("Ha vinto il giocatore 1.\n");
            break;
        case 2:
            printf("Ha vinto il giocatore 2.\n");
            break;
        default:
            printf("Partita finita in parità.\n");
    }

    return 0;
}
