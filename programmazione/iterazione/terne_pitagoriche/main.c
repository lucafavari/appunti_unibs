#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int contatore = 0;
    printf("Inserisci il valore massimo: ");
    scanf("%d", &N);
    for (int a = 1; a <= N; a++)
    {
        for (int b = a + 1; b <= N; b++)
        {
            for (int c = b + 1; c <= N; c++)
            {
                if (a*a + b*b == c*c)
                    //printf("%d %d %d\n", a, b, c);
                    contatore++;
            }
        }
    }
    printf("Il numero di terne pitagoriche i cui elementi sono minori di %d vale %d",
           N, contatore);
    return 0;
}
