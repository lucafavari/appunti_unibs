#include <stdio.h>

int main() {
    int N = 4;
    //Input
    int asterischi = 1;
    int spazi = N - 1;
    //Triangolo superiore
    for (int j = 0; j < N - 1; ++j) {
        for (int i = 0; i < spazi; ++i) {
            printf(" ");
        }
        for (int i = 0; i < asterischi; ++i) {
            printf("*");
        }
        printf("\n");
        asterischi += 2;
        spazi--;
    }
    //Riga centrale
    for (int i = 0; i < asterischi; ++i) {
        printf("*");
    }
    printf("\n");
    asterischi -= 2;
    spazi++;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < spazi; ++j) {
            printf(" ");
        }
        for (int j = 0; j < asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        asterischi -= 2;
        spazi++;
    }
    return 0;
}
