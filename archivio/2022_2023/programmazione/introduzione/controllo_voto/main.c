#include <stdio.h>

int main() {
    //Variabile di input
    int voto;
    //Variabile di output
    int errori = 0;
    do {
        printf("Inserisci il voto: ");
        scanf("%d", &voto);
        errori++;
    }while(voto < 1 || voto > 10);//Attenzione al ; in fondo
    //oppure posso controllare se non ha fatto giusto
    // !(voto >= 1 && voto <= 10)
    printf("Hai fatto %d errori prima di inserire un voto corretto\n", errori - 1);
    return 0;
}
