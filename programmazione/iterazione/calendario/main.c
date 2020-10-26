#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mese, giorno, giorni_del_mese;
    printf("Inserisci il mese: ");
    scanf("%d", &mese);
    printf("Inserisci il giorno: ");
    scanf("%d", &giorno);
    if (mese == 2)
        giorni_del_mese = 28;
    else if (mese == 4 || mese == 6 ||
             mese == 9 || mese == 11)
        giorni_del_mese = 30;
    else
        giorni_del_mese = 31;
    for (i = 1; i < giorno; i++)
        printf("   ");
    for (int i = 1 + giorno; i < giorni_del_mese + giorno; i++)
    {
        printf("%3d", i - giorno);
        if ((i - 1) % 7 == 0)
            printf("\n");
    }

    return 0;
}
