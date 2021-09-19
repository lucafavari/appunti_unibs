#include <stdio.h>
#include <stdlib.h>

//Copia src in dest
void my_string_copy(char *dest, char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

//Ritorna 0 se sono la stessa stringha
//Ritorna -1 se la prima stringa è minore della seconda
//cioè in ordine alfabetico viene prima
//Ritorna 1 se la prima stringa è maggiore della seconda
int my_string_compare(char *dest, char *src)
{
    int i;
    for (i = 0; dest[i] != '\0' && src[i] != '\0'; i++)
        if (dest[i] != src[i])
        {
            if (dest[i] < src[i])
                return -1;
            if (dest[i] > src[i])
                return 1;
        }
    if (dest[i] == '\0' && src[i] == '\0')
        return 0;
    if (dest[i] < src[i])
        return -1;
    if (dest[i] > src[i])
        return 1;
}

void my_string_concat(char *dest, char *src)
{
    int i;
    //Ci portiamo in fondo a dest con l'indice i
    for (i = 0; dest[i] != '\0'; i++);
    int i_src = 0;
    //Scorriamo tutta src con l'indice i_src e copiamo
    //tutti i caratteri in src all'interno di dest
    //partendo dalla posizione del terminatore
    //trovata in precedenza
    for(;src[i_src] != '\0'; i_src++)
    {
        dest[i] = src[i_src];
        i++;
    }
    dest[i] = '\0';
}

int my_string_length(char *src)
{
    int i = 0;
    while (src[i++]);

    //while (src[i] != '\0') i++;
    //for (i = 0; src[i] != '\0'; i++);
    return i - 1;
}

#define N 100

int main()
{
    char s1[] = "Ciao a tutti, benvenuti alla lezione";
    char s2[N];
    char s3[N];
    //s2 = s1; //NO
    //my_string_copy(s2, s1);
    strncpy(s3, s1, N);
    s3[N-1] = '\0';
    printf("%s \n%s\n%s", s1, s1, s3);
    /*
    if (s1 == s2) //NO
    {
        printf("Contengono lo stesso valore");
    }
    if (s1 < s2) // NO
    {
        printf("s1 in ordine alfabetico viene prima di s2");
    }
    s1 = s1 + s2; //Concatenzione NO
    */

    char prima[] = "Casale";
    char seconda[] = "casa";
    printf("\n\n\nIl risultato del confronto vale %d",
           my_string_compare(prima, seconda));

    char risultato[N];
    my_string_copy(risultato, "Ciao");
    my_string_concat(risultato, " a tutti da ");
    my_string_concat(risultato, seconda);

    printf("\n\nLa concatenazione produce: %s\n", risultato);
    int lunghezza = my_string_length(risultato);
    printf("\nLa lunghezza della stringa \"%s\" è : %d",
           risultato, lunghezza);
    printf("\nLa lunghezza della stringa \"%s\" è : %d",
           risultato, strlen(risultato));
    return 0;
}


