#include "complessi.h"

void stampaAlg(Complesso c)
{
    if (c.im > 0)
        printf("%f + i%f\n", c.re, c.im);
    else
        printf("%f - i%f\n", c.re, -c.im);
}

void stampaExp(ComplessoExp c)
{
    printf("Modulo: %f fase: %f\n", c.modulo, c.fase);
}

Complesso convertiAlg(ComplessoExp c)
{
    Complesso temp;
    temp.re = c.modulo * cos(c.fase);
    temp.im = c.modulo * sin(c.fase);
    return temp;
}

ComplessoExp convertiExp(Complesso c)
{
    ComplessoExp temp;
    temp.modulo = sqrt(c.re*c.re + c.im*c.im);
    temp.fase = atan2(c.im, c.re);
    return temp;
}

float modulo(Complesso c)
{
    return sqrt(c.re*c.re + c.im*c.im);
}

Complesso coniugato(Complesso c)
{
    Complesso temp;
    temp.re = c.re;
    temp.im = -c.im;
    return temp;
}

Complesso somma(Complesso a, Complesso b)
{
    Complesso temp;
    temp.re = a.re + b.re;
    temp.im = a.im + b.im;
    return temp;
}
