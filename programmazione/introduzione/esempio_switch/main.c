#include <stdio.h>

int main() {
    int scelta, a = 6, b = 3;
    printf("Scegli: \n 1) Somma\n 2)Differenza\n"
           " 3) Prodotto\n 4) Rapporto\n");
    scanf("%d", &scelta);
    switch (scelta) {
        case 1:
            printf("%d\n", a + b);
            break;
        case 2:
            printf("%d\n", a - b);
            break;
        case 3:
            printf("%d\n", a * b);
            break;
        case 4:
            printf("%d\n", a / b);
            break;
        default:
            printf("Hai fatto una scelta sbagliata\n");
    }
    return 0;
}
