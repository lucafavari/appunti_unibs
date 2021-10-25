#include <stdio.h>
#include <stdlib.h>

int random(int a, int b)
{
    return rand() % (b - a) + a;
}

int main() {
    for (int i = 0; i < 50; i++)
        printf("%d ", random(2,20));
    return 0;
}
