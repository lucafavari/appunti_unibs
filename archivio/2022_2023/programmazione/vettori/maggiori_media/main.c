#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //Dimensione di memoria allocata per il vettore

int main() {
    float valori[MAX], media = 0;
    int N; //Quanti valori effettivamente si vogliono usare
    printf("Quanti elementi vuoi inserire (<= 100): ");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        //printf("Inserisci un valore: ");
        //scanf("%f", &valori[i]);
        valori[i] = rand()/100.0;
        media += valori[i];
    }
    media /= N;
    int quanti = 0;
    for (int i = 0; i < N; ++i) {
        if (valori[i] > media){
            quanti++;
        }
    }
    printf("La media vale %f e il numero di valori maggiori della media è %d\n",
           media, quanti);
    printf("Elenco dei valori maggiori della media\n");
    for (int i = 0; i < N; ++i) {
        if (valori[i] > media){
            printf("%5.2f\n", valori[i]);
        }
    }
    return 0;
}
