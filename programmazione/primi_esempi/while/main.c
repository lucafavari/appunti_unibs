/*
Esempio con il while per ottenere lo stesso
effetto di un do-while
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, risultato;
    printf("Inserisci un numero positivo: ");
    scanf("%f", &n);
    while(n < 0)
    {
        printf("Asino, inserisci un numero positivo: ");
        scanf("%f", &n);
    }

    risultato = sqrt(n);
    printf("Il risultato vale: %f", risultato);
    return 0;
}
