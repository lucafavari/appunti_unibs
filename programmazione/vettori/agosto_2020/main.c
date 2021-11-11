#include <stdio.h>
#include <stdlib.h>

#define N 10

int mediano_ordinamento(int v[], int n)
{
    //Ordinamento con selection sort
    for (int i = 0; i < n - 1; ++i) {
        int indice_minimo = i;
        for (int j = i + 1; j < n; ++j) {

            if (v[j] < v[indice_minimo])
            {
                indice_minimo = j;
            }
        }
        int temp = v[i];
        v[i] = v[indice_minimo];
        v[indice_minimo] = temp;
    }
    return v[(n-1)/2];
}

int mediano_eliminazione(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int indice_massimo = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] > v[indice_massimo]) {
                indice_massimo = j;
            }
        }
        if (i <= (n-1)/2)
            v[indice_massimo] = -1;
        else
            return v[indice_massimo];
    }


}

int main() {
    int v[N];
    for (int i = 0; i < N; ++i) {
        v[i] = rand()%100 + 1;
        printf("%d  ", v[i]);
    }
    int mediano1 = mediano_ordinamento(v, N);
    int mediano2 = mediano_eliminazione(v, N);
    printf("\nIl mediano fatto con il primo modo vale %d, con il secondo %d\n",
           mediano1, mediano2);
    return 0;
}
