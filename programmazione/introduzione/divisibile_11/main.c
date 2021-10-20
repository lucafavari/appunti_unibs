#include <stdio.h>

int main() {
    int N, somma_pari, somma_dispari;
    int pari = 1;
    printf("Inserisci il numero: ");
    scanf("%d", &N);
    do{
        somma_dispari = 0;
        somma_pari = 0;
        while ( N > 0)
        {
            int cifra = N % 10;
            if (pari == 1)
            {
                somma_pari += cifra;
                pari = 0;
            }
            else
            {
                somma_dispari += cifra;
                pari = 1;
            }
            N = N / 10;
        }
        int differenza = somma_pari - somma_dispari;
        if (differenza < 0)
            differenza = -differenza;
        N = differenza;
    }while (N > 10);

    if (N == 0)
        printf("Il numero è divisibile per 11\n");
    else
        printf("Il numero non è divisibile per 11\n");
    return 0;
}
