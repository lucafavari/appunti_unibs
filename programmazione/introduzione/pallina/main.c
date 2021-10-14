#include <stdio.h>

int main() {
    float altezza;
    int rimbalzi = 0;
    printf("Inserisci l'altezza in metri: ");
    scanf("%f", &altezza);
    //Converto l'altezza in millimetri
    altezza = altezza * 1000;
    while (altezza > 1)
    {
        altezza = altezza * 0.99;
        // oppure
        // altezza *= 0.99;
        //rimbalzi = rimbalzi + 1;
        rimbalzi++;
    }
    printf("I rimbalzi fatti prima di fermarsi sono: %d",
           rimbalzi);
    return 0;
}
