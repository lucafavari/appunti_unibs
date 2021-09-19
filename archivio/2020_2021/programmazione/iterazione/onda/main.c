#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altezza;
    int kilometri = 0;
    printf("Inserisci l'altezza dell'onda in metri: ");
    scanf("%f", &altezza);
    while(altezza >= 0.01)
    {
        kilometri++; //kilometri = kilometri + 1;
        //Errore che a volte trovo
        //kilometri + 1;
        altezza = altezza * 0.9;
        //altezza *= 0.9;
    }
    printf("Prima di sparire l'onda ha percorso %d kilometri\n",
           kilometri);
    return 0;
}
