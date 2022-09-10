#include <stdio.h>

int main() {
    float sconto, costo;
    float totale;
    int quantita;
    printf("Inserisci il costo unitario");
    scanf("%f", &costo);
    printf("Inserisci lo sconto: ");
    scanf("%f", &sconto);
    printf("Inserisci la quantità: ");
    scanf("%d", &quantita);
    if (quantita > 10)
    {
        totale = costo * quantita - costo * quantita * sconto/100;
    }
    else
    {
        totale = costo * quantita;
    }
    printf("Il totale da pagare è: %.2f", totale);
    return 0;
}
