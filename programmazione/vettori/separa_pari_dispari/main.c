#include <stdio.h>

#define MAX_VALORI 100

int main() {
    int valori[MAX_VALORI];
    int N;
    printf("Inserisci il numero di valori: ");
    scanf("%d", &N);
    //scanf("%d", &valori); Non ha senso
    for (int i = 0; i < N ; i++)
    {
        printf("Inserisci il valore %d:", i + 1);
        scanf("%d", &valori[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (valori[i] % 2 == 0)
            printf("%d\n", valori[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (valori[i] % 2 != 0)
            printf("%d\n", valori[i]);
    }
    return 0;
}
