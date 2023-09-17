#include <stdio.h>

int main() {
    int N = 5;
    //printf("Inserisci il numero di onde: ");
    //scanf("%d", &N);
    //Prima riga
    for (int i = 0; i < N; ++i) {
        printf(" _    ");
    }
    printf("\n");
    //Seconda riga
    for (int i = 0; i < N; ++i) {
        printf("/ \\   ");
    }
    printf("\n");
    //Terza riga
    for (int i = 0; i < N; ++i) {
        printf("   \\_/");
    }
    printf("\n");
    return 0;
}
