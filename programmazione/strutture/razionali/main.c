#include <stdio.h>
#include <stdlib.h>
#include "razionale.h"

int main()
{
    float f = 1/10.0;
    Razionale r = {1,10}, s = {1,3}, t = {1,3};
    stampa(r);
    stampa(s);
    stampa(t);
    stampa(somma(s,t));
    printf("%d\n", MCD(6,9));
    float g = converti(r);
    printf("%f %f\n", f, g);
    float sommatoria_float = 0;
    Razionale sommatoria_razionale = {0, 1};
    for (int i = 0; i < 10000000; i++)
    {
        sommatoria_float += f;
        sommatoria_razionale = somma(sommatoria_razionale, r);
    }
    printf("Con i float: %f\nCon i razionali :", sommatoria_float);
    stampa(sommatoria_razionale);
    Razionale v[] = {
        {1,3},
        {2,5},
        {7,8}
    };
    stampa(somma_razionali(v, 3));
    return 0;
}
