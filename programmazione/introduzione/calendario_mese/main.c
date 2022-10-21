#include <stdio.h>

int main() {
    int mese, giorno;
    int giorni_del_mese;
    printf("Inserisci il mese e il giorno di partenza: ");
    scanf("%d", &mese);
    scanf("%d", &giorno);
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
    return 0;
}
