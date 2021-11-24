#include <stdio.h>
#include <string.h>

void parola_lunga(char s[], char p[])
{
    int inizio = 0, fine = 0;
    int inizio_max = inizio, fine_max = fine;
    for (int i = 0; s[i] != '\0' ; ++i) {
        fine = i;
        if (s[i] == ' ')
        {
            int lunghezza_attuale = fine - inizio;
            if (lunghezza_attuale > (fine_max - inizio_max))
            {
                inizio_max = inizio;
                fine_max = fine;
            }
            inizio = i + 1;
            fine = i + 1;
        }
    }
    printf("%d %d\n",inizio_max, fine_max );
    int k = 0;
    for (int i = inizio_max; i < fine_max ; ++i) {
        p[k] = s[i];
        k++;
    }
    p[k] = '\0';
}

int main() {
    char s[] = "ciao a tutti i presenti in aula e a casa o nella propria villa imperiale";
    char s_spazio[100];
    strncpy(s_spazio, s, 100);
    strncat(s_spazio, " ", 100);
    char p[100];
    parola_lunga(s_spazio, p);
    printf("%s\n", p);
    return 0;
}
