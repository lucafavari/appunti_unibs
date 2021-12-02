#include <stdio.h>
#include "complessi.h"


int main() {
    Complesso a = {1, 1};
    ComplessoExp b;
    float m = modulo(a);
    b = convertiInExp(a);
    printf("%f\n", m);
    stampa(a);
    stampaExp(b);
    ComplessoExp c = {3, 1.2};
    stampaExp(c);
    ComplessoExp c_coniugato;
    c_coniugato = convertiInExp(coniugato(convertiInComplesso(c)));
    stampaExp(c_coniugato);
    Complesso d = somma(a, convertiInComplesso(c));
    stampa(d);
    return 0;
}
