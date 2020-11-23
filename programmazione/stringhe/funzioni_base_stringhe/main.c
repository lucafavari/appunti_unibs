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

int my_string_compare(char *dest, char *src)
{
    for (int i = 0; dest[i] != '\0' && src[i] != '\0'; i++)
        if (dest[i] != src[i])
        {
            if (dest[i] < src[i])
                return -1;
            if (dest[i] > src[i])
                return +1;
        }
    return 0;
}

#define N 10

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

    char prima[] = "asa";
    char seconda[] = "Casa";
    printf("\n\n\nIl risultato del confronto vale %d",
           my_string_compare(prima, seconda));
    return 0;
}


