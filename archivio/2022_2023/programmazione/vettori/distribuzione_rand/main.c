#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param n Numero di facce del dado
 * @return
 */
int lancio_dado(int n){
    return rand() % n + 1;
}

/**
 *
 * @param k numero di dadi da lanciare
 * @param n facce del singolo dado
 * @return
 */
int lancio_dadi(int k, int n){
    int totale = 0;
    for (int i = 0; i < k; ++i) {
        totale += lancio_dado(n);
    }
    return totale;
}

#define MAX 100

void azzera(int v[], int n){
    for (int i = 0; i < n; ++i) {
        v[i] = 0;
    }
}

/**
 *
 * @param v vettore che conterrà i risultati della simulazione
 * @param k numero di dadi
 * @param n numero delle facce di un dado
 * @param n_lanci numero di lanci della simulazione
 */
void simulazione(int v[], int k, int n, int n_lanci){
    for (int i = 0; i < n_lanci; ++i) {
        int valore = lancio_dadi(k, n);
        v[valore]++;
    }
}

/**
 *
 * @param v Il vettore dei valori da mettere nell'istogramma
 * @param prima La prima colonna valida
 * @param ultima L'ultima colonna valida
 * @param max_asterischi L'altezza massima dell'istogramma in asterischi
 */
void disegna_istogramma(int v[], int prima, int ultima, int max_asterischi){
    int massimo = v[prima];
    for (int i = prima; i <= ultima; ++i) {
        if (v[i] > massimo){
            massimo = v[i];
        }
    }
    //Ciclo esterno per visitare tutte le colonne
    for (int i = prima; i <= ultima ; ++i) {
        printf("%4d -> ", i);
        //Disegno della singola colonna i-esima
        int asterischi = ((float)v[i])/massimo*max_asterischi;
        for (int j = 0; j < asterischi; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int lanci[MAX]; //Contiene il conteggio dei lanci per ogni valore
    azzera(lanci, MAX);
    simulazione(lanci, 2, 6, 10000);
    for (int i = 2; i <= 12; ++i) {
        printf("%d %d\n", i, lanci[i]);
    }
    disegna_istogramma(lanci, 2, 12, 30);
    azzera(lanci, MAX);
    simulazione(lanci, 1, 6, 100000);
    for (int i = 1; i <= 6; ++i) {
        printf("%d %d\n", i, lanci[i]);
    }
    disegna_istogramma(lanci, 1, 6, 30);
    return 0;
}
