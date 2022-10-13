#include <stdio.h>

int main() {
    int n, fattoriale = 1;
    printf("Inserisci il valore di n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        fattoriale *= i;
    }
    printf("Il fattoriale di %d è %d\n", n, fattoriale);
    return 0;
}
