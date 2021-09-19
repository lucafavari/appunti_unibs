/*
Crea una tavola pitagorica
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_tabelline;

    printf("Inserisci di quanti numeri vuoi sapere la tabellina: ");
    scanf("%d", &n_tabelline);
    printf("Tavola pitagorica\n");
    for (int n = 1; n <= n_tabelline; n++)
    {
        for (int i = 1; i <= n_tabelline; i++)
        {
            int risultato = n * i;
            printf("%4d", risultato);
        }
        printf("\n");
    }

    return 0;
}
