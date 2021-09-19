#include <stdio.h>
#include <stdlib.h>

int MCD(int a, int b)
{
    int divisore;
    if (a < b)
        divisore = a;
    else
        divisore = b;
    for (int i = divisore; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
}

void somma(int n1, int d1, int n2, int d2, int *nr, int *dr)
{
    *nr = n1*d2 + n2*d1;
    *dr = d1*d2;
    int temp = MCD (*nr, *dr);
    *nr = *nr / temp;
    *dr = *dr / temp;
}

int main()
{
    printf("%d\n", MCD(15, MCD(3, 9)));
    int nr, dr;
    somma(1, 2, 1, 3, &nr, &dr);
    printf("%d/%d\n", nr, dr);
    somma(nr, dr, 3, 4, &nr, &dr);
    printf("%d/%d\n", nr, dr);
    return 0;
}
