#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef WIN32
#define PAUSE system("pause>nul|set/p = Premere un tasto per lanciare il dado...");
#else
#define PAUSE system("read -p 'Premere INVIO per lanciare il dado...' continue");
#endif // WIN32

/**
 * Simula il lancio di un dado a n facce
 * @param n Numero di facce
 * @return Valore prodotto dal lancio del dado
 */
int dado(int n){
    return rand()%n + 1;
}

/**
 * Simula il lancio di due dadi da 6
 * @return
 */
int due_dadi(){
    return dado(6) + dado(6);
    //return rand()%11 + 2; NO
}

int main() {
    int lancio, scelta, credito = 1000, giocata;
    srand(time(NULL));
    do {
        printf("QUanto vuoi puntare? ");
        scanf("%d", &giocata);
        PAUSE
        lancio = due_dadi();
        printf("Primo lancio %d\n", lancio);
        if (lancio == 7 || lancio == 11) {
            printf("Hai vinto\n");
            credito += giocata;
        } else if (lancio == 2 || lancio == 3 || lancio == 12) {
            printf("Hai perso\n");
            credito -= giocata;
        } else {
            int target = lancio;
            PAUSE
            lancio = due_dadi();
            printf("Lancio: %d\n", lancio);
            while (lancio != 7 && lancio != target) {
                PAUSE
                lancio = due_dadi();
                printf("Lancio: %d\n", lancio);
            }
            if (lancio == 7) {
                printf("Hai perso\n");
                credito -= giocata;
            } else {
                printf("Hai vinto\n");
                credito += giocata;
            }
        }
        printf("Il tuo credito residuo è : %d", credito);
        printf("Vuoi continuare? (1 - continua, 2 - termina\n");
        scanf("%d", &scelta);
    }while(scelta == 1);
    return 0;
}
