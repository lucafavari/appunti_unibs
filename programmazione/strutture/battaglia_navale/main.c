#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 0
#define E 1
#define S 2
#define W 3

#define N2 5 //Ci saranno 5 navi da due caselle
#define N3 4
#define N4 3

#define DIM 10

#define TEST

typedef struct {
    int r;
    int c;
}Posizione;

typedef struct {
    Posizione posizione;
    int dimensione;
    int orientamento;
    int colpi_subiti;
    int affondata;
}Nave;

typedef struct{
    Nave navi[N2 + N3 + N4];
    int n_navi;
}Flotta;

typedef struct {
    int m[DIM][DIM];
}Pannello;

typedef struct {
    Pannello pannello;
    Flotta flotta;
    char nome[50];
    int punteggio;
}Giocatore;

/**
 * Verifica che la nave sia completamente nel campo di gioco
 * @param n La nave da controllare
 * @return 1 se la nave è completamente nel campo, 0 altrimenti
 */
int nave_in_campo(Nave n){
    if (n.posizione.r < 0 || n.posizione.r >= DIM)
        return 0;
    if (n.posizione.c < 0 || n.posizione.c >= DIM)
        return 0;
    Posizione poppa;
    if (n.orientamento == N){
        poppa.r = n.posizione.r - n.dimensione + 1;
        poppa.c = n.posizione.c;
    }
    if (n.orientamento == E){
        poppa.r = n.posizione.r;
        poppa.c = n.posizione.c + n.dimensione - 1;
    }
    //Stessa cosa per S e W
    if (n.orientamento == S){
        poppa.r = n.posizione.r + n.dimensione - 1;
        poppa.c = n.posizione.c;
    }
    if (n.orientamento == W){
        poppa.r = n.posizione.r;
        poppa.c = n.posizione.c - n.dimensione + 1;
    }
    if (poppa.r < 0 || poppa.r >= DIM)
        return 0;
    if (poppa.c < 0 || poppa.c >= DIM)
        return 0;
    return 1;
}

int nave_qta_corretta(Flotta flotta, Nave nave){
    int n2, n3, n4;
    n2 = n3 = n4 = 0;
    for (int i = 0; i < flotta.n_navi; ++i) {
        if (flotta.navi[i].dimensione == 2){
            n2++;
        }
        if (flotta.navi[i].dimensione == 3){
            n3++;
        }
        if (flotta.navi[i].dimensione == 4) {
            n4++;
        }
    }
    if (nave.dimensione == 2 && n2 == N2)
        return 0;
    if (nave.dimensione == 3 && n3 == N3)
        return 0;
    if (nave.dimensione == 4 && n4 == N4)
        return 0;
    return 1;
}

int nave_incrocio(Nave n1, Nave n2){
    //Definisco una matrice di "disegno"
    int m[DIM][DIM];
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            m[i][j] = 0;
        }
    }
    Posizione p = n1.posizione;
    for (int i = 0; i < n1.dimensione; ++i) {
        m[p.r][p.c] = 1;
        if (n1.orientamento == N){
            p.r--;
        }
        if (n1.orientamento == E){
            p.c++;
        }
        if (n1.orientamento == S){
            p.r++;
        }
        if (n1.orientamento == W){
            p.c--;
        }
    }
    p = n2.posizione;
    for (int i = 0; i < n2.dimensione; ++i) {
        if (m[p.r][p.c] == 1)
            return 1;
        if (n2.orientamento == N){
            p.r--;
        }
        if (n2.orientamento == E){
            p.c++;
        }
        if (n2.orientamento == S){
            p.r++;
        }
        if (n2.orientamento == W){
            p.c--;
        }
    }
    return 0;
}

int nave_senza_incroci(Flotta flotta, Nave nave){
    for (int i = 0; i < flotta.n_navi; ++i) {
        if (nave_incrocio(flotta.navi[i], nave) == 1){
            return 0;
        }
    }
    return 1;
}

int inserisci_nave(Flotta *flotta, Nave nave){
    if (!nave_in_campo(nave))
        return 0;
    if (!nave_qta_corretta(*flotta, nave))
        return 0;
    if (!nave_senza_incroci(*flotta, nave))
        return 0;
    flotta->navi[flotta->n_navi] = nave;
    flotta->n_navi++;
    return 1;
}

int nave_colpita(Nave nave, Posizione colpo){
    Posizione p = nave.posizione;
    for (int i = 0; i < nave.dimensione; ++i) {
        if (p.r == colpo.r && p.c == colpo.c)
            return 1;
        if (nave.orientamento == N){
            p.r--;
        }
        if (nave.orientamento == E){
            p.c++;
        }
        if (nave.orientamento == S){
            p.r++;
        }
        if (nave.orientamento == W){
            p.c--;
        }
    }
    return 0;
}

/**
 *
 * @param f
 * @param colpo
 * @return 0 se il colpo è andato a vuoto, 1 se è stato colpito un pezzo di nave
 * 2,3 o 4 se è stata affondata una nave da 2, 3 o 4
 */
int colpisci(Flotta *f, Posizione colpo){
    for (int i = 0; i < f->n_navi; ++i) {
        if (nave_colpita(f->navi[i], colpo))
        {
            f->navi[i].colpi_subiti++;
            if (f->navi[i].colpi_subiti == f->navi[i].dimensione) {
                f->navi[i].affondata = 1;
            }
            if (f->navi[i].affondata)
                return f->navi[i].dimensione;
            return 1;
        }
    }
    return 0;
}


void segna_colpo(Giocatore *g, Posizione colpo, int esito){
    g->pannello.m[colpo.r][colpo.c] = esito;
}

int flotta_affondata(Flotta f)
{
    for (int i = 0; i < f.n_navi; ++i) {
        if (!f.navi[i].affondata){
            return 0;
        }
    }
    return 1;
}

int navi_rimaste(Flotta f)
{
    int navi_rimaste = 0;
    for (int i = 0; i < f.n_navi; ++i) {
        if (!f.navi[i].affondata){
            navi_rimaste++;
        }
    }
    return navi_rimaste;
}

void stampa_nave(Nave nave){
    printf("Nave da %d", nave.dimensione);
    if (nave.colpi_subiti)
        printf(", colpita in %d parti", nave.colpi_subiti);
    printf("\n");
}

void stampa_navi_rimaste(Flotta f){
    for (int i = 0; i < f.n_navi; ++i) {
        if (!f.navi[i].affondata)
            stampa_nave(f.navi[i]);
    }
}

void azzera_pannello (Pannello *p){
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            p->m[i][j] = 8;
        }
    }
}

void stampa_pannello (Pannello p){
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            printf("%d ", p.m[i][j]);
        }
        printf("\n");
    }
}



int main() {
    Giocatore giocatori[2];
    strncpy(giocatori[0].nome, "Pino", 50);
    strncpy(giocatori[1].nome, "Piero", 50);
    giocatori[0].flotta.n_navi = 0;
    giocatori[1].flotta.n_navi = 0;
    azzera_pannello(&giocatori[0].pannello);
    azzera_pannello(&giocatori[1].pannello);
    int turno = 0;
    Posizione colpo;
    //Parte dell'inserimento delle flotte, ogni giocatore inserisce le proprie
    //navi, partendo dalle più piccole fino alle più grosse
    for (int i = 0; i < 2; ++i) {
        Nave nave;
        int riuscita;
        printf("Inserimento delle navi.\n");
        printf("Inserisci le navi da due.\n");
        for (int j = 0; j < N2; ++j) {
            do {
                printf("\nNavi già inserite: %d\n", giocatori[i].flotta.n_navi);
                printf("Inserisci la posizione della prua: ");
#ifdef TEST
                nave.posizione.c = rand()%10;
                nave.posizione.r = rand()%10;
#else
                scanf("%d", &nave.posizione.r);
                scanf("%d", &nave.posizione.c);
#endif
                printf("Inserisci la direzione (N - 0, E - 1, S - 2, W - 3): ");
#ifdef TEST
                nave.orientamento = rand()%4;
#else
                scanf("%d", &nave.orientamento);
#endif
                nave.dimensione = 2;
                nave.colpi_subiti = 0;
                nave.affondata = 0;
                riuscita = inserisci_nave(&giocatori[i].flotta, nave);
            } while (!riuscita);
        }
        printf("Inserisci le navi da tre.\n");
        for (int j = 0; j < N3; ++j) {
            do {
                printf("\nNavi già inserite: %d\n", giocatori[i].flotta.n_navi);
                printf("Inserisci la posizione della prua: ");
#ifdef TEST
                nave.posizione.c = rand()%10;
                nave.posizione.r = rand()%10;
#else
                scanf("%d", &nave.posizione.r);
                scanf("%d", &nave.posizione.c);
#endif
                printf("Inserisci la direzione (N - 0, E - 1, S - 2, W - 3): ");
#ifdef TEST
                nave.orientamento = rand()%4;
#else
                scanf("%d", &nave.orientamento);
#endif
                nave.dimensione = 3;
                nave.colpi_subiti = 0;
                nave.affondata = 0;
                riuscita = inserisci_nave(&giocatori[i].flotta, nave);
            } while (!riuscita);
        }
        printf("Inserisci le navi da quattro.\n");
        for (int j = 0; j < N4; ++j) {
            do {
                printf("\nNavi già inserite: %d %d\n", giocatori[i].flotta.n_navi, j);
                printf("Inserisci la posizione della prua: ");
#ifdef TEST
                nave.posizione.c = rand()%10;
                nave.posizione.r = rand()%10;
#else
                scanf("%d", &nave.posizione.r);
                scanf("%d", &nave.posizione.c);
#endif
                printf("Inserisci la direzione (N - 0, E - 1, S - 2, W - 3): ");
#ifdef TEST
                nave.orientamento = rand()%4;
#else
                scanf("%d", &nave.orientamento);
#endif
                nave.dimensione = 4;
                nave.colpi_subiti = 0;
                nave.affondata = 0;
                riuscita = inserisci_nave(&giocatori[i].flotta, nave);
            } while (!riuscita);
        }
    }

    //Gioco
    do {
        printf("Riepilogo della tua situazione\n");
        stampa_pannello(giocatori[turno].pannello);
        stampa_navi_rimaste(giocatori[turno].flotta);
        printf("\nInserisci il colpo giocatore %d: ", turno + 1);
        scanf("%d", &colpo.r);
        scanf("%d", &colpo.c);
        int esito = colpisci(&giocatori[1 - turno].flotta, colpo);
        if (esito > 0)
            printf("Hai colpito qualcosa!\n");
        segna_colpo(&giocatori[turno], colpo, esito);
        turno = 1 - turno;
    }while(navi_rimaste(giocatori[0].flotta) && navi_rimaste(giocatori[1].flotta));
    return 0;
}
