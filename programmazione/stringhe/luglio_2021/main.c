#include <stdio.h>
#include <string.h>

int vocale(char c)
{
    if (c == 'a' || c == 'e' ||
            c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

void elimina_vocali(char s[])
{
    int inizio = 0, fine = strlen(s) - 1;
    while(vocale(s[inizio]))
        inizio++;
    if (inizio == fine + 1)
    {
        s[0] = '\0';
        return;
    }
    while(vocale(s[fine]))
        fine--;
    int k = 0;
    for (int i = inizio; i <= fine ; ++i) {
        s[k] = s[i];
        k++;
    }
    s[k] = '\0';
}

int main() {
    char s[] = "inizio";
    char t[] = "programma";
    char v[] = "aia";
    elimina_vocali(s);
    elimina_vocali(t);
    elimina_vocali(v);
    printf("s = %s, t = %s, v = %s\n", s, t, v);

    return 0;
}
