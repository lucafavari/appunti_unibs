#include <stdio.h>
#include <stdlib.h>

#define N 100

int carattere_valido(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

char minuscolo(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}


void pulisci(char *s)
{
    int i, k = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (carattere_valido(s[i]))
        {
            s[k] = minuscolo(s[i]);
            k++;
        }
    }
    s[k] = '\0';
}

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

char decifra_carattere(char c, int n)
{
    return (((c - 'a') - n) + 26) % 26 + 'a';
}

void decifra(char *cifrata, char *chiaro, int chiave)
{
    int i;
    //Ciclo tipico che itera su ogni carattere di una stringa
    for (i = 0; cifrata[i] != '\0'; i++)
    {
        chiaro[i] = decifra_carattere(cifrata[i], chiave);
    }
    chiaro[i] = '\0';
}

#define CHIAVE 3

int main()
{
    char chiaro[N], cifrato[N], decifrato[N];
    printf("Inserisci la frase da codificare: ");
    //Si suppone che la frase in input sia senza spazi e con solo minuscole
    //scanf("%s", chiaro);
    //Faccio inserire all'utente quello che vuole
    fgets(chiaro, N, stdin);
    printf("La frase in chiaro prima della \"pulizia\" era: %s\n", chiaro);
    pulisci(chiaro);
    cifra(chiaro, cifrato, CHIAVE);
    printf("La frase in chiaro era: %s\n", chiaro);
    printf("La frase cifrata diventa: %s\n", cifrato);
    decifra(cifrato, decifrato, CHIAVE);
    printf("La frase decifrata diventa: %s\n", decifrato);

    return 0;
}
