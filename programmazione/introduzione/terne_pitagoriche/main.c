#include <stdio.h>

int main() {
    int N;
    printf("Inserisci il valore di N: ");
    scanf("%d", &N);
    //Input
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = j + 1; k <= N; k++)
            {
                if (i*i + j*j == k*k)
                    printf("%d %d %d\n", i, j, k);
            }
        }

    }
    return 0;
}
