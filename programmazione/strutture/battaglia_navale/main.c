#include <stdio.h>

#define N 0
#define E 1
#define S 2
#define W 3

#define N2 5 //Ci saranno 5 navi da due caselle
#define N3 4
#define N4 3

#define DIM 10

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

void stampa_flotta(Flotta f)
{
    int navi_rimaste = 0;
    for (int i = 0; i < f.n_navi; ++i) {
        if (!f.navi[i].affondata){
            navi_rimaste++;
        }
    }
    printf("Ti sono rimaste %d navi\n", navi_rimaste);
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
    int turno = 1;
    Posizione colpo;
    int esito = colpisci(&giocatori[1 - turno].flotta, colpo);
    segna_colpo(&giocatori[turno], colpo, esito);
    return 0;
}
