#include <stdio.h>
#include <stdlib.h>

float prodotto_scalare(float v1[], float v2[], int n)
{
    float ris = 0;
    for (int i = 0; i < n; i++)
        ris += v1[i] * v2[i];
    return ris;
}

int main()
{
    //Dichiarazione comoda per gli esempi
    float a[] = {1.2, 3.45, 7.9}, b[] = {3.5, -4.56, 9.32};
    printf("%f", prodotto_scalare(a, b, 3));
    return 0;
}
