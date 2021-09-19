#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
    float valori[N], appoggio[N];
    int k;
    //Input
    printf("Che finestra di filtraggio desideri? ");
    scanf("%d", &k);
    for(int i = 0; i < N; i++)
    {
        //printf("Inserisci un valore: ");
        //scanf("%d", &valori[i]);
        //oppure
        valori[i] = rand()%100;
    }
    //Prima del filtraggio
    for (int i = 0; i < N; i++)
        printf("%.2f ", valori[i]);
    printf("\n");
    //Filtraggio
    for (int i = 0; i < N; i++)
    {
        float media = 0;
        int contatore = 0;
        for (int j = i - k; j <= i + k; j++)
            if (j >= 0 && j < N)
            {
                media += valori[j];
                contatore++;
            }
        media /= contatore;
        appoggio[i] = media;
    }
    //Si rimettono i valori filtrati nel vettore originale
    for (int i = 0; i < N; i++)
        valori[i] = appoggio[i];
    //Dopo del filtraggio
    for (int i = 0; i < N; i++)
        printf("%.2f ", valori[i]);
    printf("\n");


    return 0;
}
