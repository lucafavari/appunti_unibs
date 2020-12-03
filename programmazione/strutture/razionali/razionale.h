#ifndef RAZIONALE_H_INCLUDED
#define RAZIONALE_H_INCLUDED

typedef struct{
    int numeratore;
    int denominatore;
} Razionale;

void stampa(Razionale r);

Razionale somma(Razionale a, Razionale b);

int MCD(int a, int b);

float converti(Razionale r);

Razionale somma_razionali(Razionale v[], int n);

#endif // RAZIONALE_H_INCLUDED
