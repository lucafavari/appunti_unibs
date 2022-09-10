#include <stdio.h>

#define M 4
#define N 5
#define P 3

void prodotto(int A[][N], int B[][P], int C[][P], int m, int n, int p)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int A[M][N], B[N][P], C[M][P];

    return 0;
}
