/**
 * L'idea di questo cifrario a sostituzione è rappresentare
 * la chiave come una stringa di lettere "mescolate"
 * "qwertyuiopasdfghjklzxcvbnm"
 */

#include <stdio.h>

#define ALFABETO "abcdef...";

char cifra_carattere(char c, char chiave[])
{
    char alfabeto[] = ALFABETO;
    return chiave[c - 'a'];
}

int main() {

    printf("Hello, World!\n");
    return 0;
}
