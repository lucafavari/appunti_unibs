#include <stdio.h>

/**
 *
 * @param v Il vettore da cui rimuovere un elemento
 * @param n Il numero di elementi contenuti nel vettore
 * @param k La posizione dell'elemento da rimuovere
 */
void rimuovi_elemento(int v[], int n, int k){
    for (int i = k; i < n - 1; ++i) {
        v[i] = v[i + 1];
    }
}

/**
 *
 * @param v Il vettore da cui rimuovere un elemento
 * @param n Il numero di elementi contenuti nel vettore, che verrà aggiornato dopo l'eliminazione
 * @param k La posizione dell'elemento da rimuovere
 */
void rimuovi_elemento_fix(int v[], int *n, int k){
    for (int i = k; i < *n - 1; ++i) {
        v[i] = v[i + 1];
    }
    *n = *n - 1;
}

/**
 *
 * @param v
 * @param c Il vettore dove avverrà la copia degli elementi "validi"
 * @param n
 * @param k
 */
void rimuovi_elementi_copia(int v[], int c[], int n, int k){
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i != k){
            c[j] = v[i];
            j++;
        }
    }
}

/**
 * Aggiunge un elemento al vettore in posizione k
 * @param v IL vettore che conterrà il nuovo elemento
 * @param n Il numero di elementi validi
 * @param k La posizione dove inserire il nuovo elemento
 * @param valore Il valore da inserire
 */
void aggiungi_elemento(int v[], int n, int k, int valore){
    for (int i = n - 1 ; i >= k; --i) {
        v[i + 1] = v[i];
    }
    v[k] = valore;
}



int main() {
    int v[] = {1,2,3,4,5,6,7,0,0,0};
    int n = 7;
    /*int c[10];
    rimuovi_elemento(v, 7, 3);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    rimuovi_elemento(v, 6, 3);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    int n = 5;
    rimuovi_elemento_fix(v, &n, 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");*/

    /*
    rimuovi_elementi_copia(v, c, n, 0);
    n--;
    for (int i = 0; i < n; ++i) {
        printf("%d ", c[i]);
    }
    */
    aggiungi_elemento(v, n, 1, 44);
    n++;
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
