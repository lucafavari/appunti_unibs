#include <stdio.h>
#include <stdlib.h>

#define N 10

int pozzi_presenti(float m[][N], int n)
{
    int contatore = 0;
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < N - 1; j++)
        {
            //Controllo se m[i][j] è un pozzo
            int flag = 0;
            for (int r = -1; r <= 1; r++)
                for (int s = -1; s <= 1; s++)
                    if (m[i+r][j+s] <= m[i][j])
                        flag++;
            if (flag == 1)
                contatore++;
        }
    return contatore;
}

int main()
{
    float m[N][N];
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
    {
        printf("Inserisci il valore in posizione %d,%d:",
               i+1, j+1);
        scanf("%f", &m[i][j]);
    }
    printf("Nella matrice inserita ci sono %d pozzi\n",
           pozzi_presenti(m, N));
    return 0;
}
