#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
    float v[N];
    int n;
    printf("Dimmi quanti valori vuoi inserire: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("IN: ");
        scanf("%f", &v[i]);
    }
    //Calcolo la media
    float somma = 0;
    for (int i = 0; i < n; i++)
        somma += v[i];
    float media = somma / n;
    //Conto quanti sono maggiori della media
    int contatore = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > media)
            contatore++;
    //Stampo i valori maggiori della media
    printf("Ci sono %d elementi maggiori della media e sono\n", contatore);
    for (int i = 0; i < n; i++)
        if (v[i] > media)
            printf("%.2f ", v[i]);
    return 0;
}
