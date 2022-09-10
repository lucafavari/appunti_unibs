#include <stdio.h>

#define MAX 10000

int main() {
    int crivello[MAX];
    int n;
    printf("Inserisci fino a dove vuoi trovare i numeri primi: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        crivello[i] = 1;
    for (int i = 2; i < n; i++)
    {
        if (crivello[i] == 1)
        {
            for ( int j = i + i; j < n; j += i)
                crivello[j] = 0;
        }
    }
    for (int i = 2; i < n; i++)
        if (crivello[i] == 1)
            printf("%d ", i);
    return 0;
}
