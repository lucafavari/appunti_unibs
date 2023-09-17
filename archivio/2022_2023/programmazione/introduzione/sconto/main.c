#include <stdio.h>

int main() {
    //Variabili di input
    float costoUnitario;
    int quantita;
    //Variabile di output
    float costoTotale;
    //Variabile d'appoggio
    float sconto = 0;
    //Input di quantità e costo
    printf("Inserisci il costo: ");
    scanf("%f", &costoUnitario);
    printf("Inserisci la quantità: ");
    scanf("%d", &quantita);
    /* Prima versione con if-else
    if (quantita > 10){
        costoTotale = costoUnitario * quantita * 0.9;
    }
    else{
        costoTotale = costoUnitario * quantita;
    }*/
    if (quantita > 10){
        sconto = 0.1;
    }
    /* Soluzione abominevole con il ramo vero vuoto
    if (quantita <= 10){

    }
    else
    {
        sconto = 0.1;
    }
    */
    costoTotale = costoUnitario * quantita * (1 - sconto);
    printf("Per il tuo acquisto dovrai pagare %f euro\n", costoTotale);
    return 0;
}
