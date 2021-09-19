#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, somma = 0;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            somma += i;
    if (somma == N)
        printf("SI\n");
    else
        printf("NO\n");
    return 0;
}
