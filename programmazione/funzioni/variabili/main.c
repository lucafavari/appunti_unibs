#include <stdio.h>

void scambio (int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
/**
 * Effettua lo scambio di due variabili
 * @param a L'indirizzo di memoria della prima variabile
 * @param b L'indirizzo di memoria della seconda variabile
 */
void scambio_vero(int *a, int *b){
    //Questa scrittura va letta come assegna a temp il valore
    //contenuto all'indirizzo memorizzato dentro a
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 7;
    int *c;
    c = &a;
    *c = b;
    printf("%d\n", a);
    c = &b;
    a = 6;
    a = &b;
    printf("%d %p\n", a, a);

    //Usando il simbolo & davanti a una variabile si intende di leggere il
    //suo indirizzo
    scambio_vero(&a, &b);
    printf("%d %d", a, b);
    printf("indirizzo di a: %p\n indirizzo di b: %p", &a, &b);
    return 0;
}
