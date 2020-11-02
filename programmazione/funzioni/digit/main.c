#include <stdio.h>
#include <stdlib.h>

int cifre(int n)
{
    int contatore = 0;
    while (n > 0){
        n /= 10; //n = n / 10;
        contatore++;
    }
    return contatore;
}

int digit(int n, int k)
{
    if (k <= 0 || k > cifre(n))
        return -1;
    int cifra;
    for (int i = 0; i < k; i++)
    {
        cifra = n%10;
        n /= 10;
    }
    return cifra;
}

int main()
{
    printf("%d\n", digit(12745, 3)); //Stampa 7
    printf("%d\n", digit(12745, 4)); //Stampa 2
    printf("%d\n", digit(12745, 7)); //Stampa -1
    return 0;
}
