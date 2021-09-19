#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define PAUSE system("pause>nul|set/p = Premere un tasto per lanciare il dado...");
#else
    #define PAUSE system("read -p 'Premere INVIO per lanciare il dado...' continue");
#endif // WIN32


int un_dado()
{
    return rand()%6 + 1;
}

int due_dadi()
{
    return un_dado() + un_dado();
}

int main()
{
    int lancio, target;
    srand(time(NULL));
    printf("GIOCO DEL CRAPS\n");
    PAUSE
    lancio = due_dadi();
    printf("\nIl primo lancio vale: %d\n", lancio);
    if (lancio == 7 || lancio == 11)
        printf("Hai vinto al primo colpo\n");
    else if (lancio == 2 || lancio == 3 || lancio == 12)
        printf("Accipicchia, hai perso al primo lancio\n");
    else
    {
        target = lancio;
        while(1)
        {
            PAUSE
            lancio = due_dadi();
            printf("\nHai tirato il valore: %d\n", lancio);
            if ( lancio == target )
            {
                printf("Hai vinto tu\n");
                break;
            }
            if ( lancio == 7)
            {
                printf("Hai perso\n");
                break;
            }
        }
    }
    return 0;
}







