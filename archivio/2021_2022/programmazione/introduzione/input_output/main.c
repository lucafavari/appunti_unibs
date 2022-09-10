#include <stdio.h>

int main() {
    int a, b, c;
    printf("Inserisci il primo numero: ");
    //Leggo un intero da tastiera e lo inserisco in a
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    c = a + b;
    printf("Il risultato della somma tra %d e %d vale %d",
           a ,b , c);

    return 0;
}
