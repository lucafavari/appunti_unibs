#include <iostream>
#include <string.h>

int distanza_hamming(char s[], char t[])
{
    if (strlen(s) != strlen(t))
        return -1;
    int conta = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != t[i])
            conta++;
    }
    return conta;
}

int main() {
    char s[20], t[20];
    printf("Inserisci due stringhe di uguale lunghezza: ");
    scanf("%s", s);
    scanf("%s", t);
    printf("La distanza di Hamming vale: %d", distanza_hamming(s, t));
    return 0;
}
