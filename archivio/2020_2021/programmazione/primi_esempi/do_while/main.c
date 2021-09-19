#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, risultato;
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%f", &n);
    }while(n < 0);

    risultato = sqrt(n);
    printf("Il risultato vale: %f", risultato);
    return 0;
}
