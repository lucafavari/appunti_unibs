#include <stdio.h>
#include <stdlib.h>

/*
    5
    12 34 8 345 -23
    Massimo 345
    Minimo -23
*/

int main()
{
    int N, valore;
    int massimo, minimo;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);
    printf("Inserisci un valore: ");
    scanf("%d", &valore);
    massimo = valore;
    minimo = valore;
    for (int i = 0; i < N - 1; i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &valore);
        if (valore > massimo)
            massimo = valore;
        if (valore < minimo)
            minimo = valore;
    }
    printf("Il massimo vale %d e il minimo vale %d\n",
           massimo, minimo);
    return 0;
}
