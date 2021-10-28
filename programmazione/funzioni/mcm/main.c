#include <stdio.h>

int MCD_euclide(int a, int b)
{
    int resto;
    resto = a % b;
    while (resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

int mcm(int a, int b)
{
    int multiplo_a = a, multiplo_b = b;
    while (multiplo_a != multiplo_b)
    {
        if (multiplo_a < multiplo_b)
            multiplo_a += a;
        else
            multiplo_b += b;
    }
    return multiplo_a;
}

int mcm_euclide(int a, int b)
{
    return (a * b)/ MCD_euclide(a, b);
}

int main() {
    int n = 9, m = 12;
    printf("Il mcm vale %d\n", mcm(n, m));
    printf("Il mcm vale %d\n", mcm_euclide(n, m));
    return 0;
}
