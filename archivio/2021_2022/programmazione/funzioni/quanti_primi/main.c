#include <stdio.h>
#include <math.h>

//Funzione che verifica se una certa affermazione è
//vera o falsa
//Tipicamente in C si fa una funzione che ritorna 0
//per indicare falso e 1 per indicare vero
int primo(int n)
{
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}


int main() {
    int a, b;
    printf("Inserisci gli estremi dell'intervallo: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int contatore = 0;
    for (int i = a; i < b; i++){
        if (primo(i) == 1)
            contatore++;
    }
    printf("Il numero di numeri primi compresi nell'intervallo vale: %d",
               contatore);
    return 0;
}
