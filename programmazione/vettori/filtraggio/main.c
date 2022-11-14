#include <stdio.h>

#define MAX 100


int main() {
    float valori[MAX], valori_filtrati[MAX];
    int N, k = 3;
    printf("Quanti valori vuoi inserire: ");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        printf("Inserisci il %d° valore:", i + 1);
        scanf("%f", &valori[i]);
    }
    for (int i = 0; i < N; ++i) {
        //Nell'ipotesi di k = 1 sarebbe così, ignorando l'uscita dal vettore
        //valori_filtrati[i] = (valori[i-1] + valori[i] + valori[i+1])/3;
        valori_filtrati[i] = 0;
        int quanti = 0;
        for (int j = i - k; j <= i + k ; ++j) {
            if (j >= 0 && j < N) {
                valori_filtrati[i] += valori[j];
                quanti++;
            }
        }
        valori_filtrati[i] /= quanti;
    }
    return 0;
}
