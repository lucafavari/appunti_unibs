//
// Created by alex on 01/12/2021.
//

#include <stdio.h>
#include <math.h>
#include "complessi.h"

float modulo(Complesso c)
{
    return sqrt(c.re*c.re + c.im*c.im);
}

ComplessoExp convertiInExp(Complesso c)
{
    ComplessoExp ce;
    ce.modulo = modulo(c);
    ce.fase = atan2(c.im, c.re);
    return ce;
}

void stampa( Complesso c){
    printf("%f + i%f\n", c.re, c.im);
}

void stampaExp( ComplessoExp c)
{
    printf("Modulo: %f Fase: %f\n", c.modulo, c.fase);
}

Complesso coniugato(Complesso c)
{
    Complesso r;
    r.re = c.re;
    r.im = -c.im;
    return r;
}

Complesso convertiInComplesso(ComplessoExp a)
{
    Complesso c;
    c.re = a.modulo*cos(a.fase);
    c.im = a.modulo*sin(a.fase);
    return c;
}

Complesso reciproco(Complesso c)
{
    Complesso r;
    r.re = c.re / (c.re * c.re + c.im * c.im);
    r.im = -c.im / (c.re * c.re + c.im * c.im);
    return r;
}

Complesso somma(Complesso a, Complesso b)
{
    Complesso c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}