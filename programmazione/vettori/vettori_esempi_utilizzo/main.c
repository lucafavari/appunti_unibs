#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
    //Dichiaro un vettore di N elementi
    int v[N];
    //Azzero tutti gli elementi, se serve
    for (int i = 0; i < N; i++)
        v[i] = 0;
    //Attenzione, così è un errore
    //v = 0;
    int i;
    //Si permette all'utente di inserire un indice
    //in modo da vedere "al volo" l'effetto dell'inserimento
    //di valori out of bounds
    printf("Inserisci un intero: ");
    scanf("%d", &i);
    v[i] = 67;
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);

    return 0;
}
