/*
 * La stringa da codificare contiene solo lettere dell'alfabeto inglese
 * minuscole
 *
 */

#include <stdio.h>

char cifra_carattere(char c, int n)
{
    return ((c - 'a') + n)%26 + 'a';
}

char cifra_carattere_senza_inglesi(char c, int n)
{
    char alfabeto[] = "abcdefghilmnopqrstuvz";

}

void cifra_cesare(char chiaro[], char cifrato[], int chiave)
{
    int i;
    for (i = 0; chiaro[i] != '\0'; ++i) {
        cifrato[i] = cifra_carattere(chiaro[i], chiave);
    }
    //"Chiudo" la mia stringa con il terminatore
    cifrato[i] = '\0';
}

char decifra_carattere(char c, int n)
{
    return ((c - 'a') - n + 26)%26 + 'a';
}

void decifra_cesare(char chiaro[], char cifrato[], int chiave)
{
    int i;
    for (i = 0; cifrato[i] != '\0'; ++i) {
        chiaro[i] = decifra_carattere(cifrato[i], chiave);
    }
    //"Chiudo" la mia stringa con il terminatore
    chiaro[i] = '\0';
}

int main() {
    char chiaro[] = "zucca";
    char cifrato[100];
    char decifrato[100];
    cifra_cesare(chiaro, cifrato, 10);
    printf("Chiaro: %s\n", chiaro);
    printf("Cifrato: %s\n", cifrato);
    decifra_cesare(decifrato, cifrato, 10);
    printf("Chiaro: %s\n", decifrato);
    printf("Cifrato: %s\n", cifrato);

    return 0;
}
