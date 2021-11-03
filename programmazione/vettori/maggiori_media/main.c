#include <stdio.h>

#define MAX 100

int main() {
    float valori[MAX];
    int N;
    printf("Inserisci quanti numeri vuoi: ");
    scanf("%d", &N);
    float media = 0;
    for (int i = 0; i < N ; i++)
    {
        printf("Inserisci un valore: ");
        scanf("%f", &valori[i]);
        media += valori[i];
    }
    media /= N;
    printf("La media vale %f\n", media);
    int quanti = 0;
    for (int i = 0; i < N; i++)
    {
        if (valori[i] > media)
            quanti++;
    }
    printf("I valori maggiori della media sono: %d\n",
           quanti);
    for (int i = 0; i < N; i++)
        if (valori[i] > media)
            printf("%f\n", valori[i]);
    return 0;
}
