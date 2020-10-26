#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int j = 0; j < 2; j++)
    {
        printf("ciclo esterno n. %d :", j+1);
        for(int i = 0; i < 10; i++)
        {
            if (i == 5)
                continue;
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
