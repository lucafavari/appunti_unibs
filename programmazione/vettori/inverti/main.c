#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void inverti(int v[], int n)
{
    for (int i = 0; i < n/2; i++)
    {
        int temp;
        temp = v[i];
        v[i] = v[n - 1 -i];
        v[n -1 -i] = temp;
    }
}

void stampa_vettore(int v[], int n)
{
    printf("{ %d", v[0]);
    for(int i = 1; i < n; i++)
        printf(", %d", v[i]);
    printf("}\n"); //[ 1, 2, 3]
}

int main() {
    int vettore[MAX];
    int n = 7;
    for (int i = 0; i < n; i++)
        vettore[i] = rand()%10;
    stampa_vettore(vettore, n);
    inverti(vettore, n);
    stampa_vettore(vettore, n);
    return 0;
}
