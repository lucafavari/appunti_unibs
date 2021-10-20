#include <stdio.h>

int main() {
    int mese, giorno;
    int giorni_nel_mese;
    printf("Inserisci il mese: ");
    scanf("%d" , &mese);
    printf("Inserisci il giorno (1 - lun, ..., 7 dom): ");
    scanf("%d", &giorno);
    if (mese == 2)
        giorni_nel_mese = 28;
    else if (mese == 11 || mese == 4 || mese == 6 ||
                mese == 9)
        giorni_nel_mese = 30;
    else
        giorni_nel_mese = 31;
    for (int i = 1; i < giorno; i++)
        printf("    ");
    for (int i = 1; i <= giorni_nel_mese; i++)
    {
        printf("%4d", i);
        if ((i + giorno - 1) % 7 == 0)
            printf("\n");

    }
    return 0;
}
