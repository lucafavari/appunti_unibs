#include <stdio.h>
#include <stdlib.h>

#define N 10000

int main()
{
    int v[N];
    int quanti_valori;
    printf("Quanti valori vuoi inserire (massimo 100)? ");
    scanf("%d", &quanti_valori);
    for (int i = 0; i < quanti_valori; i++)
    {
        printf("Inserisci il valore numero %d: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("Stampa\n");
    for (int i = 0; i < quanti_valori; i++)
        if (v[i] % 2 == 0)
            printf("v[%d] = %d\n", i, v[i]);
    for (int i = 0; i < quanti_valori; i++)
        if (v[i] % 2 == 1)
            printf("v[%d] = %d\n", i, v[i]);
    return 0;
}
