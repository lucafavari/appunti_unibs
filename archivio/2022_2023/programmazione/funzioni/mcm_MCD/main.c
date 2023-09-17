#include <stdio.h>

int mcm(int a, int b){
    int  c, d;
    c = a;
    d = b;
    while (c != d){
        if (c < d){
            c += a;
        }
        else{
            d += b;
        }
    }
    return c;
}

int MCD(int a, int b){
    int resto;
    while (a % b != 0){
        resto = a % b;
        a = b;
        b = resto;
    }
    return b;
}

int mcm2(int a, int b){
    return (a * b)/MCD(a, b);
}

int main() {
    int a = 12, b = 18;
    printf("Il mcm tra %d e %d è %d\n", a, b, mcm(a, b));
    printf("Il MCD tra %d e %d è %d\n", a, b, MCD(a, b));
    printf("Il MCD tra %d e %d è %d\n", a, b, mcm2(a, b));

    return 0;
}
