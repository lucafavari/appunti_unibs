#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numeri_alternative = 6;
    int inizio = 1;
    for (int i = 0; i < 10; ++i) {
        //La funzione rand genera un numero pseudocasuale ogni volta che viene chiamata
        //In questo ambiente i valori generati sono compresi tra 0 e 32000 e rotti
        int numero = rand() % numeri_alternative + inizio;
        printf("%d\n", numero);
    }
    return 0;
}
