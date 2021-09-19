#include <stdio.h>
#include <stdlib.h>

#define N 100

//Quella tipica che useremo
int somma(int v[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}

int somma_p(int *v, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += *(v + i);
    return s;
}

int somma_pp(int *v, int n)
{
    int s = 0;
    int *p;
    for ( p = v; p < v + n; p++)
        s += *p;
    return s;
}


int main()
{
    int a[N], s;
    for(int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    s = somma(a , N);
    printf("%d\n", s);
    int *p;
    p = &a[0];
    //p++; //p = p + 1;
    //printf("%d\n", *p);

    s = somma_p(p + 10 , N - 10);
    printf("%d\n", s);

    return 0;
}
