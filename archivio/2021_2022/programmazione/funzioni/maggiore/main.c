#include <stdio.h>

//Definizione della funzione
int maggiore (int a, int b)
{
    int mag;
    if (a > b)
        mag = a;
    else
        mag = b;
    //return mag;
}

int main() {
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d", &a);
    scanf("%d", &b);
    //Chiamata di una funzione

    printf("Il maggiore tra %d e %d è il numero %d\n",
           a, b, maggiore(a, b));

    return 0;
}
