#include <stdio.h>
#include <stdlib.h>

int collatz(int n)
{
    int l = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3*n + 1;
        l++;
    }
    return l;
}

int main()
{
    int N;
    int contatore = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int numero;
        scanf("%d", &numero);
        if (collatz(numero) >= 20)
            contatore++;
    }
    printf("%d\n", contatore );
    return 0;
}
