/*
Esempio della conversione Farenheit Celsius e viceversa
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scelta;
    float C , F;
    printf("Vuoi una conversione da Celsius a Fahrenheit(1) "
           "o da Fahrenheit a Celsius(2)\n");
    scanf("%d", &scelta);
    if (scelta == 1)
    {
        printf("Inserisci la temperatura in Celsius: ");
        scanf("%f", &C);
        F = (C*9)/5 + 32.0;
        printf("In Fahrenheit: %f\n", F);
    }
    else if(scelta == 2)
    {
        printf("Inserisci la temperatura in Fahrenheit: ");
        scanf("%f", &F);
        C = (F - 32.0)*5/9;
        printf("In Fahrenheit: %f\n", C);
    }
    else
    {
        printf("Attenzione: dovevi inserire 1 o 2.");
    }
    return 0;
}
