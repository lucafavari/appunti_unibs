#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, S, K;
    //Input dal server, senza istruzioni per l'utente
    scanf("%d", &N);
    scanf("%d", &M);
    //elaborazione
    S = N + M;
    if (S % 2 == 0)
        K = N*M;
    else
        K = N - M;
    //output
    printf("%d %d\n", S, K);
    return 0;
}
