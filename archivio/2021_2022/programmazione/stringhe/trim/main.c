/*
 * Ad esempio la stringa "   alessandro bugatti  " deve diventare
 * "alessandro bugatti"
 */

#include <stdio.h>
#include <string.h>

#define N 100

//Prima versione con stringa d'appoggio
void trim_semplice(char s[])
{
    char appoggio[N];
    int inizio = 0;
    while(s[inizio] == ' ') inizio++;
    int fine = strlen(s) - 1;
    while (s[fine] == ' ') fine--;
    int k = 0;
    for (int i = inizio; i <= fine; ++i) {
        appoggio[k] = s[i];
        k++;
    }
    appoggio[k] = '\0';
    //printf("%s\n", appoggio);
    int i = 0;
    for (i = 0; appoggio[i] != '\0'; ++i) {
        s[i] = appoggio[i];
    }
    s[i] = '\0';
}

int main() {
    char s[] = "   alessandro bugatti   ";
    trim_semplice(s);
    printf("%s\n", s);
    return 0;
}
