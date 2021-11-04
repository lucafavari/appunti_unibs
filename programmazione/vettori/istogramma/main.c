#include <stdio.h>

void disegna_istogramma(int v[], int n, int max)
{
    int massimo = v[0];
    for (int i = 0; i < n; ++i) {
        if (v[i] > massimo)
            massimo = v[i];
    }
    double f = max / massimo;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)(v[i] * f); ++j) {
            printf("*");
        }
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
