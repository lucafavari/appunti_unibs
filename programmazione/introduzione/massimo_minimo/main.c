#include <stdio.h>

int main() {
    int N, numero;
    int minimo, massimo;
    printf("Inserisci quanti numeri vuoi: ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    massimo = numero;
    minimo = numero;
    for (int i = 0; i < N - 1; i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > massimo)
            massimo = numero;
        if (numero < minimo)
            minimo = numero;
    }
    return 0;
}
