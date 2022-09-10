#include <stdio.h>
#include <math.h>

int main() {
    int giocatore1, giocatore2, vantaggi1, vantaggi2;
    giocatore1 = giocatore2 = 0;
    vantaggi1 = vantaggi2 = 0;
    printf("ATP Anversa Game Manager\n");
    do{
        int vince;
        printf("%d - %d\n", giocatore1, giocatore2);
        printf("Inserisci il giocatore che ha fatto il punto (1 o 2): ");
        scanf("%d", &vince);
        if (vince == 1)
        {
            if (giocatore1 == 0 || giocatore1 == 15)
                giocatore1 += 15;
            else if (giocatore1 == 30)
                giocatore1 += 10;
            else
                giocatore1 += 1;
        }
        if (vince == 2)
        {
            if (giocatore2 == 0 || giocatore2 == 15)
                giocatore2 += 15;
            else if (giocatore2 == 30)
                giocatore2 += 10;
            else
                giocatore2 += 1;
        }

    }while(!(giocatore1 > 40 || giocatore2 > 40 ||
            (giocatore1 == 40 && giocatore2 == 40)));
    if (giocatore1 == 41)
    {
        printf("Vince il giocatore 1\n");
        return 0;
    }
    if (giocatore2 == 41)
    {
        printf("Vince il giocatore 2\n");
        return 0;
    }
    do{
        if (vantaggi1 == vantaggi2)
            printf("Vantaggio pari\n");
        else if (vantaggi1 > vantaggi2)
            printf("Vantaggio giocatore 1\n");
        else
            printf("Vantaggio giocatore 2\n");
        int vince;
        printf("Inserisci il giocatore che ha fatto il punto (1 o 2): ");
        scanf("%d", &vince);
        if (vince == 1)
            vantaggi1++;
        else
            vantaggi2++;

    }while(abs(vantaggi1 - vantaggi2) < 2);
    if (vantaggi1 > vantaggi2)
        printf("Ha vinto il giocatore 1\n");
    else
        printf("Ha vinto il giocatore 2\n");
    return 0;
}
