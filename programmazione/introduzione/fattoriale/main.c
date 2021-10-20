#include <stdio.h>

int main() {
    int N, fattoriale = 1;
    printf("Inserisci un numero positivo: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        fattoriale = fattoriale * i;
    }
    printf("IL fattoriale di %d vale %d", N, fattoriale);
    //Ciclo equivalente con un while
    fattoriale = 1;
    int i = 1;
    while (i <= N)
    {
        fattoriale = fattoriale * i;
        i++;
    }
    printf("IL fattoriale di %d vale %d", N, fattoriale);

    return 0;
}
