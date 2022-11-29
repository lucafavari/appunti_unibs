#include <stdio.h>

int main() {
    char inizio = 'a';
    for (int i = 0; i < 26; ++i) {

        for (int j = 0; j < 26; ++j) {
            printf("%c", ((inizio - 'a' + j) % 26) + 'a');
        }
        printf("\n");
        inizio++;
    }


    return 0;
}
