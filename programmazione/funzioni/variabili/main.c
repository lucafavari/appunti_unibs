#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int c = 13;
int a = 76;

void f(int a)
{
    printf("%d\n", a);
}

int main()
{
    int a = 5, b = 7;
    for (int i = 0; i < a; i++)
        printf("%d\n", i);
    printf("%d %d %d\n", a, b, c);
    f(66);
    return 0;
}



