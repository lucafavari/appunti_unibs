#include <stdio.h>

int main() {
    int a, b;
    printf("Inserisci un valore intero: ");
    scanf("%d", &a);
    printf("Inserisci un valore intero: ");
    scanf("%d", &b);
    //Output con printf
    //Stampa di stringhe costanti
    printf("Stringa costante\n"); //\n sequenza di 'a capo'
    //Stampa di variabili
    printf("Il valore di a è %d\n", a); //%d è il segnaposto per valori interi
    //Si possono stampare anche più variabili nella stessa printf
    printf("La somma di %d con %d risulta %d", a, b, a + b);

    float c, d;
    printf("Inserisci un numero con virgola: ");
    scanf("%f", &c);
    printf("Inserisci un numero con la virgola: ");
    scanf("%f", &d);
    printf("Hai inserito %f e %f\n", c, d);

    return 0;
}
