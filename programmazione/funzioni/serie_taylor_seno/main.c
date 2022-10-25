#include <stdio.h>
#include <math.h>

int fattoriale(int n){
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

/**
 * Funziona solo per esponenti positivi
 * @param base
 * @param esponente
 * @return
 */
double potenza_intera(double base, int esponente){
    double risultato = 1;
    for (int i = 0; i < esponente; ++i) {
        risultato *= base;
    }
    return risultato;
}


/**
 *
 * @param x L'angolo di cui si vuole sapere il seno
 * @param n Il numero di termini della sommatoria che si vogliono utilizzare
 * @return Il seno di x
 */
double seno_taylor(double x, int n){
    double seno = 0;
    for (int i = 0; i < n; ++i) {
        seno += potenza_intera(-1, i) * potenza_intera(x, 2*i + 1) /
                fattoriale(2*i + 1);
    }
    return seno;
}

int main() {
    double x = 0.564;
    printf("Il seno di %lf è %lf\n", x, seno_taylor(x, 2));
    printf("Il seno di %lf è %lf\n", x, sin(x));
    return 0;
}
