#include <stdio.h>
#include <stdlib.h>

/*
    1234
    primo passaggio estrarre il 4
    secondo passaggio estrarre il 3 e "aggiungerlo" al 4 per
    formare il 43
    terzo passaggio estrarre il 2 e "aggiungerlo" al 43 per
    formare il 432
    ultimo passaggio estrarre l'1 e "aggiungerlo" al 432 per
    formare il 4321
*/

int main()
{
    int N, inverso = 0; //Spiegare l'inizializzazione
    printf("Inserisci il numero da invertire: ");
    scanf("%d", &N);
    //printf("Valore iniziale casuale di inverso: %d\n", inverso);
    while(N > 0)
    {
        int cifra = N%10; // il simbolo % è il resto della divisione intera
        //Esempio 13%4 = 1
        printf("%d", cifra);
        inverso = inverso*10 + cifra;
        N = N/10;
    }
    printf("L'inverso è : %d\n", inverso);
    return 0;
}
