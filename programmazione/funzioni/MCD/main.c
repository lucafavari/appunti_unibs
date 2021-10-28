#include <stdio.h>

int MCD(int a, int b)
{
    int divisore;
    if (a < b)
        divisore = a;
    else
        divisore = b;
    for (int i = divisore; i > 0; i--)
        if (a % i == 0 && b % i == 0)
            return i;

}

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

int main() {
    int n = 12, m = 15;
    printf("Il MCD vale %d\n", MCD(n, m));
    printf("Il MCD vale %d\n", MCD_euclide(n, m));
    return 0;
}
