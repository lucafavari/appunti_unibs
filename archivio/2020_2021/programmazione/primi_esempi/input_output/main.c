/*
    Autore: Alessandro
    Data: 16/10/2020
    Fa la somma tra due numeri
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Output costante
    printf("Hello world!\n\n");
    int a, b, c;
    //Input
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("Inserisci un numero: ");
    scanf("%d", &b);

    c = a + b;
    //Output variabile
    printf("Il risultato di %d + %d vale: %d", a, b, c);
    return 0;
}
