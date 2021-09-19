#include <stdio.h>
#include <stdlib.h>

#define N 30

//Esempio per far vedere come usare le funzioni di libreria
//per il confronto e l'assegnamento (copia) tra stringhe
//ad esempio nel contesto dell'ordinamento di stringhe
void bubble_sort(char v[][N], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (strncmp(v[j - 1], v[j], N) > 0)
            {
                char temp[N];
                strncpy(temp, v[j-1], N);
                strncpy(v[j-1], v[j], N);
                strncpy(v[j], temp, N);
            }
    }
}



int main()
{
    char stringhe[3][N];
    strncpy(stringhe[0], "cammello", N);
    strncpy(stringhe[1], "lince", N);
    strncpy(stringhe[2], "aquila", N);
    for (int i = 0; i < 3; i++)
        printf("stringhe[%d] = %s\n", i, stringhe[i]);
    bubble_sort(stringhe, 3);
    for (int i = 0; i < 3; i++)
        printf("stringhe[%d] = %s\n", i, stringhe[i]);

    return 0;
}
