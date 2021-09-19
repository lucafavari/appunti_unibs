/*
Programma per il calcolo della radice quadrata
con il metodo di bisezione
*/

#include <stdio.h>
#include <stdlib.h>

#define DELTA 0.0001

int main()
{
    float n, a, b, m;
    printf("Inserisci il valore del numero di cui vuoi clalcolare la radice: ");
    scanf("%f", &n);
    a = 0;
    b = n;
    while (b - a > DELTA)
    {
        m = (a + b)/2;
        if (m*m > n)
            b = m;
        else
            a = m;
    }
    printf("La radice di %f vale %f\n", n, m);
    float test;
    test = sqrt(n);
    printf("La radice di %f vale %f\n", n, test);
    return 0;
}







