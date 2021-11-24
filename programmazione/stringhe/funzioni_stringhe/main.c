#include <stdio.h>
#include <string.h>

void my_strcpy(char dest[], char src[])
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char s[100];
    char t[100];
    //Copia tra stringhe, equivalente dell'assegnamento per le variabili
    //"normali"
    //t = s; NO
    //strcpy(t,s);
    strncpy(s, "Hello world", 100);
    strncpy(t, s, 5); //L'eventuale necessità di terminare la stringa,
    //in caso che n sia minore della lunghezza di s, rimane al programmatore
    t[5] = '\0';
    printf("%s\n", t);

    //Sembra corretta, ma non si ottengono i risultati desiderati
    /*if (s < t)
    {

    }*/
    strncpy(t, "Ciao mondo", 20);
    //Se s > t ritorna un valore > 0
    //Se s < t ritorna un valore < 0
    //Se sono uguali ritorna 0
    //strncpy(t, s, 20);
    if (strncmp(s, t, 100) > 0)
        printf("La stringa %s è maggiore di %s\n", s, t);
    else if (strncmp(s,t, 100) < 0)
        printf("La stringa %s è minore di %s\n ", s, t);
    else if (strncmp(s, t, 100) == 0)
        printf("Sono uguali");

    char r[100];
    //r = s + t;
    //s = s + " " + t;
    strncat(s, " ", 100);
    strncat(s, t, 100);
    printf("La concatenazione diventa %s\n", s);
    my_strcpy(r, s);
    printf("%s\n", r);
    return 0;
}
