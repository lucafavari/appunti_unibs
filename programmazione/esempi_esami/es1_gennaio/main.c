#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int N;
    printf("Inserisci un valore intero, escluso lo zero: ");
    scanf("%d", &N);
    while (N == 0)
    {
        printf("Reinserisci il valore: ");
        scanf("%d", &N);
    }
    int v[MAX];
    for (int i = 0; i < MAX; i++)
    {
        if (N > 0)
            v[i] = rand()%(N+1);
        else
            v[i] = -rand()%(-N + 1);
    }
    int contatore = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = i + 1; j < MAX; j++)
            if (v[i] + v[j] == N)
                contatore++;
    printf("Ci sono %d coppie di numeri la cui somma è %d",
           contatore, N);
    return 0;
}







