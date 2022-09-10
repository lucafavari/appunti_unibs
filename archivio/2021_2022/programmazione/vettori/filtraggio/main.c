#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    float numeri[MAX];
    int N, k;
    printf("Inserisci quanti valori vuoi: ");
    scanf("%d", &N);
    //Al posto dell'input dell'utente, per velocizzare
    //l'esecuzione, produciamo numeri casuali
    for (int i = 0; i < N; i++)
        numeri[i] = rand()/100.0;
    printf("Dimmi la dimensione della finestra di filtraggio: ");
    scanf("%d", &k);
    float numeri_filtrati[MAX];
    for (int i = 0; i < N; i++)
        numeri_filtrati[i] = numeri[i];
    for (int i = k; i < N - k; i++)
    {
        float media = 0;
        for (int j = i - k; j < i + k + 1; j++)
            media += numeri[j];
        media /= (k*2 + 1);
        numeri_filtrati[i] = media;
    }
    for (int i = 0; i < N; i++)
        printf("%7.2f -> %7.2f\n", numeri[i],
               numeri_filtrati[i]);
    return 0;
}
