#include <stdio.h>
#include <string.h>

int conta_parole(char s[], char p[])
{
    int totale = 0;
    int lunghezza_parola = strlen(p);
    for (int i = 0; s[i + lunghezza_parola] != '\0' ; ++i) {
        int conta = 0;
        for (int j = 0; j < lunghezza_parola; ++j) {
            if (p[j] == s[i+j])
                conta++;
        }
        if (conta == lunghezza_parola)
            totale++;
    }
    return totale;
}

int trova_occorrenze(char v[][100], int righe, char p[])
{
    int totale = 0;
    for (int i = 0; i < righe; ++i) {
        totale += conta_parole(v[i], p);
    }
    return totale;
}

int main() {
    //Questo può essere pensato come un vettore di 3 stringhe
    //ognuna delle quali è composta al massimo da 99 caratteri
    char vettore[3][100];
    //Copia la stringa ciao a tutti all'interno della seconda riga della
    //matrice
    strncpy(vettore[1], "ciao a tutti", 99);
    printf("%s\n", vettore[1]);

    char v[][100] = {
            "la mia macchina è verde e va veloce",
            "ieri ho pescato una verdesca",
            "verde come il latte, verde come il sangue"
    };
    printf("%d\n", conta_parole(v[0], "verde"));
    printf("%d\n", trova_occorrenze(v, 3, "verde"));

    return 0;
}
