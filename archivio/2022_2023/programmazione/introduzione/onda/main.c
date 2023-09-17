#include <stdio.h>

int main() {
    //Variabile di input
    float altezza;
    //Variabile di output
    int km = 0; //contatore
    printf("Inserisci l'altezza dell'onda in metri: ");
    scanf("%f", &altezza);
    while(altezza > 0.01){
        altezza *= 0.9;
        km++;
    }
    printf("L'onda sparisce dopo %d chilometri\n", km);
    return 0;
}
