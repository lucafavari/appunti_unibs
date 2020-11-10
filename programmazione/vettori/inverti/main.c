#include <stdio.h>
#include <stdlib.h>

void inverti(int v[], int n)
{
    for (int i = 0; i < n/2; i++)
    {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

int main()
{
    int v[] = {13, 7, 21, -2, 4};
    for(int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    inverti(v, 5);
    printf("\nDopo l'inversione\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    return 0;
}
