#include <stdio.h>

int main() {
    //Variabili di input
    int N, numero;
    //Variabili di output
    int massimo, minimo;
    printf("Dimmi quanti numeri vuoi inserire: ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    massimo = minimo = numero;
    for (int i = 0; i < N - 1; ++i) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > massimo){
            massimo = numero;
        }
        if (numero < minimo){
            minimo = numero;
        }
    }
    printf("Massimo: %d Minimo %d\n", massimo, minimo);
    return 0;
}
