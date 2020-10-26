#include <stdio.h>
#include <stdlib.h>

int primo(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

//l'intervallo è [inizio, fine)
//Se l'intervallo non è corretto, cioè inizio > fine
//la funzione ritorna 0
int quanti_primi(int inizio, int fine)
{
    int contatore = 0;
    for (int i = inizio; i < fine; i++)
        if (primo(i) == 1)
            contatore++;
    return contatore;
}


int main()
{
    printf("%d\n", quanti_primi(1,1000));
    return 0;
}
