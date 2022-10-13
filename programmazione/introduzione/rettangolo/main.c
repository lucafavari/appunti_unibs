#include <stdio.h>
/*
 Questo è il primo programma
 che utilizza un costrutto di sequenza
 */

int main() {
    //Variabili di input
    //Rappresentano la base e l'altezza di un rettangolo
    float base, altezza;
    //Variabili di output
    float perimetro, area;
    printf("Inserisci il valore della base: ");
    scanf("%f", &base);
    printf("Inserisci il valore dell'altezza: ");
    scanf("%f", &altezza);
    //Elaborazione
    perimetro = (base + altezza) * 2;
    area = base * altezza;
    printf("Il perimetro vale %f e l'area vale %f\n", perimetro, area);


    return 0;
}
