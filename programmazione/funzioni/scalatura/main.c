#include <stdio.h>
#include <stdlib.h>

//Prima versione con puntatore
void scalatura(double *d, double f)
{
    *d = *d * f;
}

//Seconda versione senza puntatore
double scalatura_normale(double n, double f)
{
    return n * f;
}


int main()
{
    double n, f;
    printf("Inserisci il valore: ");
    scanf("%lf", &n);
    printf("Inserisci il valore di scalatura: ");
    scanf("%lf", &f);
    scalatura(&n, f);
    printf("Il valore scalato diventa %f", n);
    printf("Inserisci il valore: ");
    scanf("%lf", &n);
    printf("Inserisci il valore di scalatura: ");
    scanf("%lf", &f);
    double s = scalatura_normale(n, f);
    printf("Il valore scalato diventa %f", s);
    return 0;
}
