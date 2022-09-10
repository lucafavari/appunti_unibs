#include <stdio.h>

/*
ss_
s/s\
/sss\
|sss|
|sss|
\sss/
s\s/
ss_
*/

void capsula(int N)
{
    int spazi_iniziali, spazi_centrali = 1;
    spazi_iniziali = N;
    //Punta della capsula
    for(int i = 0; i < spazi_iniziali; i++)
        printf(" ");
    printf("_\n");
    //Stampa della parte superiore
    spazi_iniziali--;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < spazi_iniziali; j++)
            printf(" ");
        printf("/");
        for (int j = 0; j < spazi_centrali; j++)
            printf(" ");
        printf("\\\n");
        spazi_iniziali--;
        spazi_centrali += 2;
    }
    spazi_iniziali = 0;
    spazi_centrali = spazi_centrali - 2;
    //Stampa della parte centrale
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < spazi_centrali; j++)
            printf(" ");
        printf("|\n");
    }
}

int main() {
    capsula(1);

    return 0;
}
