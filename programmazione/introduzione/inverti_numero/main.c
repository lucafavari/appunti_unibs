#include <stdio.h>

int main() {
    int N;
    printf("Inserisci un numero positivo: ");
    scanf("%d", &N);
    while(N > 0){
        printf("%d", N % 10);
        N /= 10;
    }
    return 0;
}
