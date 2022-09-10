#include <stdio.h>

int main() {
    int N;
    printf("Inserisci il valore di N: ");
    scanf("%d", &N);

    //Disegno di un quadrato di lato N
    printf("Quadrato\n");
    for (int i = 0; i < N; i++)
    {
        //Disegno una linea di lunghezza N
        for (int j = 0; j < N; j++)
            printf("*");
        printf("\n");
    }
    //Disegno di una cornice quadrata di lato N >= 3
    printf("Cornice\n");
    //Disegno una linea di lunghezza N
    for (int i = 0; i < N; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < N - 2; i++)
    {
        //Disegno una linea di lunghezza N vuota all'interno
        printf("*");
        for (int j = 0; j < N - 2; j++)
            printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < N; i++)
        printf("*");
    printf("\n");

    //Disegno di un triangolo rettangolo
    printf("Triangolo rettangolo\n");
    int lunghezza = 1;
    for (int i = 0; i < N; i++)
    {
        //Disegno una linea di lunghezza variabile
        for (int j = 0; j < lunghezza; j++)
            printf("*");
        printf("\n");
        lunghezza++;
    }

    //Disegno di un quadrato "bicolore"
    printf("Quadrato bicolore\n");
    int l_asterischi = 1;
    int l_croci = N - 1;

    for (int i = 0; i < N; i++)
    {
        //Disegno una linea di lunghezza variabile
        for (int j = 0; j < l_asterischi; j++)
            printf("*");
        for (int j = 0; j < l_croci; j++)
            printf("+");
        printf("\n");
        l_asterischi++;
        l_croci--;
    }

    //Disegna un rombo, da adattare il valore di N per seguire le specifiche dell'esercizio
    printf("Rombo\n");
    lunghezza = 1;
    int spazi_iniziali = N - 1;
    for (int i = 0; i < N; i++)
    {
        //Disegno gli spazi iniziali per "deformare" correttamente il triangolo
        for (int j = 0; j < spazi_iniziali; j++)
            printf(" ");
        //Disegno una linea di lunghezza variabile
        for (int j = 0; j < lunghezza; j++)
            printf("*");
        printf("\n");
        lunghezza += 2;
        spazi_iniziali--;
    }
    //Da completare con la parte sotto del rombo
    return 0;
}
