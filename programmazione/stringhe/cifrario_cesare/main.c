#include <stdio.h>
#include <stdlib.h>

#define N 100

char cifra_carattere(char c, int n)
{
    return (((c - 'a') + n) % 26) + 'a';
}

//Nel caso del cifrario storico di Cesare chiave = 3
void cifra(char *chiaro, char *cifrata, int chiave)
{
    int i;
    //Ciclo tipico che itera su ogni carattere di una stringa
    for (i = 0; chiaro[i] != '\0'; i++)
    {
        cifrata[i] = cifra_carattere(chiaro[i], chiave);
    }
    cifrata[i] = '\0';
}

int main()
{
    char chiaro[N], cifrato[N];
    printf("Inserisci la frase da codificare: ");
    //Si suppone che la frase in input sia senza spazi e con solo minuscole
    scanf("%s", chiaro);
    cifra(chiaro, cifrato, 3);
    printf("La frase in chiaro era: %s\n", chiaro);
    printf("La frase cifrata diventa: %s\n", cifrato);
    return 0;
}
