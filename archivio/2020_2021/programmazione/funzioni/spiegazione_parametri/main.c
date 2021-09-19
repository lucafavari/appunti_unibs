#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>

int maggiore(int a, int b)//Firma della funzione
{
    printf("Funzione: Indirizzo di a: %p, indirizzo %p\n", &a, &b);
    printf("Funzione: Valore contenuto in a: %d Valore contenuto in b: %d\n",
           a, b);
    if (a > b)
        return a;
    else
        return b;
}

void scambio_finto(int a, int b)
{
    int temp;
    printf("Funzione: Indirizzo di a: %p, indirizzo %p\n", &a, &b);

    printf("Funzione: Valore contenuto in a: %d Valore contenuto in b: %d\n",a, b);
    temp = a;
    a = b;
    b = temp;
    printf("Funzione: Valore contenuto in a: %d Valore contenuto in b: %d\n",a,b);

}

void scambio(int* a, int *b)
{
    int temp;
    printf("Funzione: Indirizzo di a: %p, indirizzo %p\n", &a, &b);
    printf("Funzione: Valore contenuto in a: %p Valore contenuto in b: %p\n",a, b);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("Funzione: Valore contenuto in a: %p Valore contenuto in b: %p\n",a, b);
    printf("Funzione: Valore contenuto in a: %d Valore contenuto in b: %d\n",a,b);

}

int main()
{
    int a = 5, b = 7;
    //printf("Il maggiore tra %d e %d vale %d\n", a, b, maggiore(b,a));
    printf("Main: Indirizzo di a: %p, indirizzo %p\n", &a, &b);
    printf("Prima - Main: Valore contenuto in a: %d Valore contenuto in b: %d\n",
           a, b);
    scambio(&a, &b);
    printf("Dopo - Main: Valore contenuto in a: %d Valore contenuto in b: %d\n",
           a, b);

    return 0;
}


