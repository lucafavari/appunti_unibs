#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int fattoriale(int n)
{
    long long int f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    return f;
}

double potenza(double base, int esp)
{
    double risultato = 1;
    for (int i = 0; i < esp; i++)
        risultato = risultato * base;
    return risultato;
}

double seno(double x, int n_termini)
{
    int segno = 1;
    double sommatoria = 0;
    for(int n = 0; n < n_termini; n++)
    {
        //sommatoria += (double)segno/fattoriale(2*n + 1)*potenza(x, 2*n + 1);
        //sommatoria += potenza(x, 2*n + 1)*segno/fattoriale(2*n + 1);
        sommatoria += segno*potenza(x, 2*n + 1)/fattoriale(2*n + 1);
        segno = -segno;
    }
    return sommatoria;
}

int main()
{
    printf("%lld\n", fattoriale(20));
    printf("%f\n", potenza(0.78, 3));
    printf("%f\n", seno(0.474552, 10));
    printf("%f\n", sin(0.474552));
    return 0;
}
