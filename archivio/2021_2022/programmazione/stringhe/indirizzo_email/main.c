#include <stdio.h>
#include <ctype.h>
#include <string.h>

int conta_carattere(char s[], char c)
{
    int totale = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c)
            totale++;
    }
    return totale;
}

int cerca_carattere(char s[], char c)
{
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int prima_parte(char s[])
{
    int posizione = cerca_carattere(s, '@');
    if (posizione == 0)
        return 0;
    if (s[0] >= 'A' && s[0] <= 'Z')
        return 1;
    if (s[0] >= 'a' && s[0] <= 'z')
        return 1;
    //if (isalpha(s[0]))
    //    return 1;
    return 0;
}

int seconda_parte(char s[])
{
    int posizione = cerca_carattere(s, '@');
    if (strlen(s) - posizione < 3)
        return 0;
    if (conta_carattere(&s[posizione + 1], '.') != 1)
        return 0;
    if (s[posizione+1] == '.' || s[strlen(s) - 1] == '.')
        return 0;
    int posizione_punto = cerca_carattere(&s[posizione + 1], '.');
    if ((strlen(s) - posizione - 1) - posizione_punto - 1 <= 1 ||
        (strlen(s) - posizione - 1) - posizione_punto - 1> 3)
        return 0;
    return 1;
}

int main() {
    char email[] = "alessandro.bugatti@unibs.com";
    if (conta_carattere(email, '@') != 1 || !prima_parte(email) || !seconda_parte(email))
        printf("L'email non è valido\n");
    else
        printf("L'email è valido\n");
    return 0;
}
