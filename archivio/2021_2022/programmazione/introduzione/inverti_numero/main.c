#include <stdio.h>

int main() {
    int N, N_inverso = 0;
    printf("Inserisci un numero positivo: ");
    scanf("%d", &N);
    while (N > 0)
    {
        if (N % 10 != 0)
            printf("%d", N % 10);
        N_inverso = N_inverso * 10 + N % 10;
        N = N / 10;
    }
    printf("\n%d\n", N_inverso);
    return 0;
}
