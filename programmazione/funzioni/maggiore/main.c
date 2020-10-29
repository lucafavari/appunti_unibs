#include <stdio.h>
#include <stdlib.h>

int maggiore(int a, int b)//Firma della funzione
{
    if (a > b)
        return a;
    else
        return b;
    /*
    Scrittura alternativa
    int maggiore;
    if (a > b)
        maggiore = a;
    else
        maggiore = b;
    return maggiore;
    */
}

int main()
{
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int c = maggiore(a, b);
    printf("Il maggiore tra %d e %d vale %d\n", a, b, c);
    printf("Il maggiore tra %d e %d vale %d\n", a, b, maggiore(a,b));


    return 0;
}
