//
// Created by alex on 05/12/2022.
//
#include <stdio.h>
#include <math.h>
#include "complessi.h"

void stampa(Complesso c){
    if (c.im < 0)
        printf("%.2lf %.2lfi\n", c.re, c.im);
    else
        printf("%.2lf + %.2lfi\n", c.re, c.im);
}

double modulo(Complesso c){
    return sqrt(c.re*c.re + c.im*c.im);
}

Complesso somma(Complesso a, Complesso b){
    Complesso c;
    //c = a + b; NO
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

Complesso differenza(Complesso a, Complesso b){
    b.re = -b.re;
    b.im = -b.im;
    return somma(a, b);
}




