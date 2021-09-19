/*
Dato un naturale n questo programma calcola
la somma di tutti i naturali da 1 a n
Es. n = 4 risultato -> 10
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, risultato = 0;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        risultato += i; //risultato = risultato + addendo;
    printf("Il risultato vale: %d", risultato);
    return 0;
}
