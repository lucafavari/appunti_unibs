#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, a, b, c;
    printf("Inserisci un numero positivo");
    scanf("%d", &N);
    //rand produce un numero pseudocasuale potenzialmente grande
    //per ricondurlo nell'intervallo di interesse si usa l'operatore %
    //per stabilire il numero di possibilità e poi, eventualmente,
    //si somma o sottrae la quantità corretta per ottenere l'intervallo
    //desiderato
    a = rand()%100 + 1;
    b = rand()%100 + 1;
    c = rand()%100 + 1;
    printf("%d\n%d\n%d\n", a, b, c);
    int contatore = 3;
    while ((a + b + c) % N == 0)
    {
        int nuovo = rand()%100 + 1;
        printf("%d\n", nuovo);
        contatore++;
        c = b;
        b = a;
        a = nuovo;
    }
    printf("I numeri casuali generati sono %d\n", contatore);
    return 0;
}
