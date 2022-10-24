#include <stdio.h>

int main() {
    int mese = 1, giorno = 4;
    int giorni_del_mese;
    /*printf("Inserisci il mese e il giorno di partenza: ");
    scanf("%d", &mese);
    scanf("%d", &giorno);*/
    if (mese == 2){
        giorni_del_mese = 28;
    }
    else if (mese == 11 || mese == 4 || mese == 6 || mese == 9){
        giorni_del_mese = 30;
    }
    else{
        giorni_del_mese = 31;
    }
    //Oppure usando il costrutto switch
    switch (mese) {
        case 2:
            giorni_del_mese = 28;
            break;
        case 11:
        case 4:
        case 6:
        case 9:
            giorni_del_mese = 30;
            break;
        default:
            giorni_del_mese = 31;
    }
    for (int i = 1; i < giorno; ++i) {
        printf("    ");
    }

    for (int i = 1; i <= giorni_del_mese; ++i) {
        printf("%4d", i);
        if ((i + giorno - 1) % 7 == 0)
            printf("\n");
    }
    return 0;
}
