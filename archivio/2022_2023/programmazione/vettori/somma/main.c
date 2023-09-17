#include <stdio.h>

/**
 *
 * @param v Il vettore di cui si vuole calcolare la somma
 * @param n I primi n elementi del vettore di cui si vuole fare la somma
 * @return
 */
int somma(int v[], int n){
    int totale = 0;
    for (int i = 0; i < n; ++i) {
        totale += v[i];
    }
    return totale;
}

int somma2(int *v, int n){
    int totale = 0;
    for (int i = 0; i < n; ++i) {
        totale += *(v + i);
    }
    return totale;
}

int main() {
    //Inizializzare un vettore con una lista di valori permette al compilatore
    //di decidere la dimensione basandosi sulla lunghezza della lista, in questo
    //esempio 5
    int v[] = {2,5,7,6,9};
    printf("La somma è %d", somma(v,5));
    printf("La somma è %d", somma2(v,5));
    return 0;
}
