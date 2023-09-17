#include <stdio.h>

int main() {
    for(int i = 0; //Inizializzazione
        i < 10; //condizione
        ++i) //incremento (o decremento)
    {
        //printf("%d\n", i);
        printf("Ciao\n");
    }
    //while equivalente
    int i = 0;
    while (i < 10){
        printf("Ciao");
        ++i; //Come ultima istruzione prima di iniziare da capo
    }
    return 0;
}
