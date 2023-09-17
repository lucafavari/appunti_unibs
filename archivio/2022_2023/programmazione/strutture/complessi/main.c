#include <stdio.h>
#include <stdlib.h>
#include "complessi.h"

#define MAX 10

Complesso somma_vettore(Complesso v[], int n){
    Complesso totale = {0};
    for (int i = 0; i < n; ++i) {
        totale = somma(totale, v[i]);
    }
    return totale;
}

int main() {
    Complesso c;
    c.re = 2;
    c.im = 3;
    stampa(c);
    Complesso d;
    d.re = 0;
    d.im = -2;
    stampa(d);
    printf("Modulo: %lf\n", modulo(d));
    Complesso e;
    e = somma(c, d);
    Complesso v[MAX];
    for (int i = 0; i < MAX; ++i) {
        v[i].re = rand()/100.0;
        v[i].im = rand()/100.0;
    }
    stampa(somma_vettore(v, MAX));
    return 0;
}
