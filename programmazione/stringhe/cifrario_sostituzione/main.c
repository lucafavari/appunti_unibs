#include <stdio.h>
#include <stdlib.h>

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

char cifra_carattere(char c, char *chiave)
{
    return chiave[c - 'a'];
}

void cifra(char *chiara, char *cifrata, char *chiave)
{
    int i;
    //Ciclo tipico che itera su ogni carattere di una stringa
    for (i = 0; chiara[i] != '\0'; i++)
    {
        cifrata[i] = cifra_carattere(chiara[i], chiave);
    }
    cifrata[i] = '\0';
}

char decifra_carattere(char c, char *chiave)
{
    int indice;
    for (int i = 0; i < 26 /*oppure chiave[i] != '\0' */; i++)
        if (c == chiave[i])
        {
            indice = i;
            break;
        }
    return 'a' + indice;
}

void decifra(char *cifrata, char *chiara, char *chiave)
{
    int i;
    //Ciclo tipico che itera su ogni carattere di una stringa
    for (i = 0; cifrata[i] != '\0'; i++)
    {
        chiara[i] = decifra_carattere(cifrata[i], chiave);
    }
    chiara[i] = '\0';
}

#define N 100

int main()
{
    char chiave[] = "rtazxcvyuioplkjhqwegfdsbnm";
    char chiaro[N], cifrato[N], decifrato[N];
    printf("Cifrario a sostituzione. Inserisci la frase da codificare: ");
    //Si suppone che la frase in input sia senza spazi e con solo minuscole
    //scanf("%s", chiaro);
    //Faccio inserire all'utente quello che vuole
    fgets(chiaro, N, stdin);
    printf("La frase in chiaro prima della \"pulizia\" era: %s\n", chiaro);
    pulisci(chiaro);
    cifra(chiaro, cifrato, chiave);
    printf("La frase in chiaro era: %s\n", chiaro);
    printf("La frase cifrata diventa: %s\n", cifrato);
    decifra(cifrato, decifrato, chiave);
    printf("La frase decifrata diventa: %s\n", decifrato);
    return 0;
}
