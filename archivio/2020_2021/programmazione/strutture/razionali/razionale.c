#include "razionale.h"

void stampa(Razionale r)
{
    if (r.numeratore * r.denominatore > 0)
    {
        if (r.numeratore > 0)
            printf("%d/%d\n", r.numeratore, r.denominatore);
        else
            printf("%d/%d\n", -r.numeratore, -r.denominatore);
    }
    else
    {
        if (r.denominatore < 0)
            printf("-%d/%d\n", r.numeratore, -r.denominatore);
        else
            printf("%d/%d\n", r.numeratore, r.denominatore);
    }

}

Razionale somma(Razionale a, Razionale b)
{
    Razionale temp;
    temp.numeratore = a.numeratore*b.denominatore +
            b.numeratore*a.denominatore;
    temp.denominatore = a.denominatore*b.denominatore;
    int m = MCD(temp.numeratore, temp.denominatore);
    temp.numeratore = temp.numeratore/m;
    temp.denominatore = temp.denominatore/m;
    return temp;
}

Razionale somma_razionali(Razionale v[], int n)
{
    Razionale temp;
    for(int i = 0; i < n; i++)
        temp = somma(temp, v[i]);
    return temp;
}

float converti(Razionale r)
{
    return (float)r.numeratore/r.denominatore;
}

//Algoritmo di Euclide
int MCD(int a, int b)
{
    while(a % b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}
