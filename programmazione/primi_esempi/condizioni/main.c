/*
Esempio di utilizzo delle condizioni
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 5, c = 10;
    printf("a = %d b = %d c = %d\n", a, b, c);
    if (a < b)
    {
        printf("a minore di b\n");
    }
    if (a > b)
    {
        printf("a maggiore di b\n");
    }
    if (a < b + c)
    {
        printf("a minore della somma di b con c\n");
    }
    if (a > b && a > c)
    {
        printf("a maggiore di b e c\n");
    }
    if (a < b || a < c)
    {
        printf("a minore di uno o entrambi tra b e c\n");
    }
    //Attenzione: in C ogni cosa diversa da zero è vera
    if (a)
    {
        printf("a diverso da zero\n");
    }
    if (!a)
    {
        printf("a uguale zero\n");
    }
    if (a == 0) //equivalente alla precedente
    {
        printf("a uguale zero\n");
    }
    //Errore tipico
    if (a = b) //Il valore di verità di un assegnamento è il valore assegnato
    {
        printf("diventa vero o falso in base al valore di b\n");
    }
    //Errore un po' meno tipico
    if (a != c)
    {
        printf("corretto a diverso da b\n");
    }
    if (a =! c)
    {
        printf("sbagliato a diverso da b\n");
    }
    printf("a è diventato %d\n", a);
    return 0;
}
