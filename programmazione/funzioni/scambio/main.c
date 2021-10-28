#include <stdio.h>

//Versione intermedia, solo la variabile passata
//per indirizzo tramite puntatore verrà modificata
void scambio(int *a, int b)
{
    int temp = *a;
    *a = b;
    b = temp;
}

int main() {
    int a = 5, b = 7;
    scambio(&a, b);
    printf("%d %d\n", a, b);
    return 0;
}
