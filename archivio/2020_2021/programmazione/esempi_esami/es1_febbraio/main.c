#include <stdio.h>
#include <stdlib.h>

#define LUNGHEZZA 1000

int parolindroma(char frase[])
{
    int appoggio[LUNGHEZZA/2];
    int parole = 0;
    int contatore = 0;
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == ' ')//quello è uno spazio
        {
            appoggio[parole] = contatore;
            contatore = 0;
            parole++;
        }
        else
            contatore++;

    }
    appoggio[parole] = contatore;
    //for (int i = 0; i <= parole; i++)
    //    printf("%d ", appoggio[i]);
    int i = 0, j = parole;
    while (i < j)
    {
        if (appoggio[i] != appoggio[j])
            return 0;
        i++;
        j--;
    }
    return 1;

}

int main()
{
    char frase[] = "Oggi piove poco per fortuna";
    if (parolindroma(frase))
        printf("Parolindroma");
    else
        printf("Non parolindroma");
    return 0;
}
