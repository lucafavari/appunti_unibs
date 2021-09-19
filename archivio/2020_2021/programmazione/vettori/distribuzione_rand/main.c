#include <stdio.h>
#include <stdlib.h>

#define N 100
#define N_LANCI 1000000

//Funzione per il lancio di n dadi ognuno con k facce
int lancia_dadi(int n, int k)
{
    int somma = 0;
    for (int i = 0; i < n; i++)
        somma += rand()%k + 1;
    return somma;
}

int main()
{
    int conteggio[N];
    srand(time(NULL));
    //Primo esperimento, verifichiamo se il lancio di un dado da 6 è equo
    for (int i = 0; i < N; i++)
        conteggio[i] = 0;
    for (int i = 0; i < N_LANCI; i++)
    {
        int lancio = lancia_dadi(3, 10);
        /*Se non ci fossero stati i vettori
        if (lancio == 1)
            a++;
        if (lancio == 2)
            b++;
        */
        conteggio[lancio]++;
    }
    for (int i = 3; i <= 30; i++)
        printf("La faccia con %d è uscita %d volte\n",
               i, conteggio[i]);

    return 0;
}
