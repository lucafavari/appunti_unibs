#include <stdio.h>
#include <stdlib.h>

int random(int a, int b)
{
    return rand()%(b - a) + a;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int a = random(1,101);
        printf("%d\n", a);
    }
    return 0;
}
