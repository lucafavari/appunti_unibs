#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int a, int b)
{
    return rand() % (b - a) + a;
}

int un_dado()
{
    return random(1, 7);
}

int due_dadi()
{
    return un_dado() + un_dado();
}

int main() {
    //Istruzione per inizializzare il seme del generatore
    //di numeri casuali
    srand(time(NULL));
    int lancio, target, lettura, scelta;
    printf("Gioco del craps\n");
    do{
        printf("--- Nuova partita ---\n");
        printf("Inserisci 1 per lanciare i dadi: ");
        scanf("%d", &lettura);
        lancio = due_dadi();
        printf("Hai lanciato i dadi e hai ottenuto: %d\n",
               lancio);
        if (lancio == 7 || lancio == 11)
            printf("Hai vinto\n");
        else if (lancio == 2 || lancio == 3 ||
                lancio == 12)
            printf("Hai perso\n");
        else
        {
            target = lancio;
            printf("Inserisci 1 per lanciare i dadi: ");
            scanf("%d", &lettura);
            lancio = due_dadi();
            printf("Hai lanciato i dadi e hai ottenuto: %d\n",
                   lancio);
            while (lancio != 7 && lancio != target)
            {
                printf("Inserisci 1 per lanciare i dadi: ");
                scanf("%d", &lettura);
                lancio = due_dadi();
                printf("Hai lanciato i dadi e hai ottenuto: %d\n",
                       lancio);

            }
            if (lancio == target)
                printf("Hai vinto\n");
            else
                printf("Hai perso\n");
        }
        printf("Vuoi fare una nuova partita?\n"
               "Inserisci 1 per continuare, 0 per finire: ");
        scanf("%d", &scelta);
    }while(scelta == 1);

    return 0;

}
