#include <stdio.h>

int main() {
    int N;
    printf("Inserisci un numero > 1: ");
    scanf("%d", &N);
    int primo = 1;
    for (int i = 2; i < N/2; i++)
    {
        if (N % i == 0){
            primo = 0;
            break; //altra possibilità bruttina i = N/2;
        }
    }
    if (primo == 1)
        printf("Il numero è primo\n");
    else
        printf("Il numero non è primo\n");
    return 0;
}
