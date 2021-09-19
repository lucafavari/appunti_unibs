#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

int massimo(int m[][M], int n)
{
    int max = m[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < M; j++)
            if (m[i][j] > max)
                max = m[i][j];
    return max;
}



int main()
{
    int m[N][M - 2];
    m[0][0] = 12;
    m[0][1] = 33;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M - 2; j++)
            m[i][j] = i*20 + 5*j;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 2; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("m[1][1] = %d\n", m[1][1]);
    printf("m[0][5] = %d\n", m[0][5]);
    printf("m[3][2] = %d\n", m[3][2]);
    printf("m[-1][5] = %d\n", m[-1][5]);
    //printf("m[100000][5] = %d\n", m[100000][5]);
    int max = massimo(m , 3);
    printf("Massimo della matrice: %d", max);
    return 0;
}
