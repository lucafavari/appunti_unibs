#include <stdio.h>

int bisestile(int a){
    if (a % 400 == 0)
        return 1;
    if (a % 100 == 0)
        return 0;
    if (a % 4 == 0)
        return 1;
    return 0;
}

int giorni_del_mese(int m, int a){
    switch (m) {
        case 2:
            return 28 + bisestile(a);
        case 11:
        case 4:
        case 6:
        case 9:
            return 30;
        default:
            return 31;
    }
}

int giorni_mese(int m, int a){
    int giorni = 0;
    for (int i = 1; i < m; ++i) {
        giorni += giorni_del_mese(m, a);
    }
    return giorni;
}

int giorni_anno(int a){
    //int giorni = (a - 1970) * 365;
    int giorni = 0;
    for (int i = 1970; i < a ; ++i) {
        giorni += 365 + bisestile(a);
    }
    return giorni;
}

int numero_giorni(int a, int m, int g){
    return giorni_anno(a) + giorni_mese(m, a) + g;
}

int differenza_date(int a1, int m1, int g1, int a2, int m2, int g2){
    return numero_giorni(a1, m1, g1) - numero_giorni(a2, m2, g2);
}

int main() {
    printf("%d\n", differenza_date(2022, 11, 7, 2022, 3, 13));
    return 0;
}
