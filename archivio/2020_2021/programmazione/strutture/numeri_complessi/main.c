#include <stdio.h>
#include <stdlib.h>

#include "complessi.h"

int main()
{
    Complesso a = {3.12, 4.43};
    stampaAlg(a);
    ComplessoExp b = convertiExp(a);
    stampaExp(b);
    a = convertiAlg(b);
    stampaAlg(a);
    a = coniugato(a);
    stampaAlg(a);
    Complesso c = somma(a, a);
    stampaAlg(c);
    c = prodotto(a, c);
    stampaAlg(c);
    c = somma(prodotto(a,c), prodotto(c,c));
    stampaAlg(c);

    return 0;
}
