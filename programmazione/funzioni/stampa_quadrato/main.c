#include <stdio.h>
#include <stdlib.h>

void stampa_quadrato(int N, char c)
{
    if (N == 1)
    {
        printf("%c", c);
        return;
    }
    for (int j = 0; j < N; j++)
        printf("%c", c);
    printf("\n");
    //Questo ciclo compone il quadrato, la parte "cava"
    for (int i = 0; i < N - 2; i++)
    {
        //Stampa il primo delimitatore, il bordo sinistro
        printf("%c", c);
        //stampa una serie di spazi che sono la parte vuota interna
        for (int j = 0; j < N - 2; j++)
            printf(" ");
        //Stampa il secondo delimitatore, il bordo destro
        printf("%c\n", c);
    }
    for (int j = 0; j < N; j++)
        printf("%c", c);
    printf("\n");
}

int main()
{
    stampa_quadrato(40, 'a');
    return 0;
}
