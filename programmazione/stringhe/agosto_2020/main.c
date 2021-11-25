#include <stdio.h>
#include <string.h>

int stampa_riga(char s[])
{
    int fine = 60;
    if (strlen(s) < 60)
    {
        printf("%s\n", s);
        return -1;
    }
    while(s[fine] != ' ')
        fine--;
    for (int i = 0; i < fine; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
    return fine + 1;
}

void stampa(char s[])
{
    int lunghezza = stampa_riga(s);
    int inizio = lunghezza;
    while(lunghezza != -1)
    {
        //lunghezza = stampa_riga(&s[inizio]); equivalente
        lunghezza = stampa_riga(s + inizio);
        inizio += lunghezza;
    }
}

int main() {
    char s[] = "Scrivere un programma che faccia inserire all'utente una stringa di testo, su un'unica riga, di lunghezza al massimo 1000 caratteri e che, successivamente, la ristampi a video dandole una formattazione a bandiera con una lunghezza massima di ogni singola riga di 60 caratteri.";
    stampa(s);

    return 0;
}
