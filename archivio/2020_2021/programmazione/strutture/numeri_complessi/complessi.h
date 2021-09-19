#ifndef COMPLESSI_H_INCLUDED
#define COMPLESSI_H_INCLUDED

typedef struct{
    float re;
    float im;
} Complesso;

typedef struct{
    float modulo;
    float fase;
} ComplessoExp;

//Stampa un numero complesso in forma algebrica a + ib
void stampaAlg(Complesso c);

//Stampa un numero complesso in forma esponenziale
void stampaExp(ComplessoExp c);

Complesso convertiAlg(ComplessoExp c);

ComplessoExp convertiExp(Complesso c);

float modulo(Complesso c);

Complesso coniugato(Complesso c);

Complesso somma(Complesso a, Complesso b);

Complesso prodotto(Complesso a, Complesso b);

#endif // COMPLESSI_H_INCLUDED
