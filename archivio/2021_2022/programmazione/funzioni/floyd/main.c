#include <stdio.h>

void floyd(int N)
{
    int numeri = 1;
    int numero = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < numeri; j++)
        {
            printf("%4d", numero);
            numero++;
        }
        numeri++;
        printf("\n");
    }
}

int main() {
    floyd(5);
    return 0;
}
