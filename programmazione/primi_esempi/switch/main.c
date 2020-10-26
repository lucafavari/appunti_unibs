#include <stdio.h>
#include <stdlib.h>

//Esempio di utilizzo dello switch

int main()
{
    int giorno;
    printf("Inserisci il giorno della settimana in formato numerico: ");
    scanf("%d", &giorno);
    switch(giorno)
    {
    case 1:
        printf("Lunedì\n");
        break;
    case 2:
        printf("Martedì\n");
        break;
    //....
    default:
        printf("Il numero inserito non è corretto\n");
    }
    //Struttura equivalente con if
    if (giorno == 1)
        printf("Lunedì\n");
    else if (giorno == 2)
        printf("Martedì\n");
    //...
    else
        printf("Il numero inserito non è corretto\n");

    return 0;
}












