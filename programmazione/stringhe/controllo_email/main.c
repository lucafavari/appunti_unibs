#include <stdio.h>
#include <stdlib.h>

#define N 50

int quanti_caratteri(char *s, char c)
{
    int contatore = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            contatore++;
    return contatore;
}

int posizione_carattere(char *s, char c)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return i;
    return -1;
}

int indirizzo_valido(char *s)
{
    if (quanti_caratteri(s, '@') != 1)
        return 0;
    int posizione = posizione_carattere(s, '@');
    //printf("Nella stringa %s la chiocciola si trova in %d posizione\n",
    //       s, posizione);
    char prima_parte[N];
    char seconda_parte[N];
    strncpy(prima_parte, s, posizione);
    prima_parte[posizione] = '\0';
    //printf("prima parte %s\n", prima_parte);
    strncpy(seconda_parte, &s[posizione + 1], N);
    //printf("seconda parte %s\n", seconda_parte);
    if (strlen(prima_parte) == 0)
        return 0;
    if (!isalpha(prima_parte[0]))
        return 0;
    //printf("Ci sono %d punti nella seconda parte\n",
    //       quanti_caratteri(seconda_parte, '.'));
    if (quanti_caratteri(seconda_parte, '.') != 1)
        return 0;
    if (seconda_parte[0] == '.' ||
        seconda_parte[strlen(seconda_parte) - 1] == '.')
        return 0;
    return 1;
}

int indirizzi_validi(char indirizzi[][N], int n)
{
    int contatore = 0;
    for (int i = 0; i < n; i++)
        if (indirizzo_valido(indirizzi[i]) == 1)
            contatore++;
    return contatore;
}

int main()
{
    char indirizzi[][N] = {
        "ale@unibs.it",
        "geppo@unipiit",
        "gina@uni@it"
    };
    for (int i = 0; i < 3; i++ )
        printf("L'indirizzo %s contiente %d chiocciole\n",
               indirizzi[i], quanti_caratteri(indirizzi[i], '@'));
    printf("Nel vettore di stringhe si trovano %d indirizzi validi\n",
           indirizzi_validi(indirizzi, 3));
    return 0;
}
