#include <stdio.h>

void run_length(char originale[], char codificata[]){
    int conta = 1, j = 0;
    for (int i = 0; originale[i] != '\0' ; ++i) {
        if (originale[i] == originale[i+1]){
            conta++;
            if (conta == 9) {
                codificata[j] = '9';
                j++;
                codificata[j] = originale[i];
                j++;
                conta = 1;
            }
        }
        else{
            if (conta == 1){//Caso in cui la lettera in posizione i-esima non ha ripetizion
                codificata[j] = originale[i];
                j++;
            }
            //Siamo all'interno di una ripetizione
            else {
                    codificata[j] = conta + '0';
                    j++;
                    codificata[j] = originale[i];
                    j++;
                    conta = 1;
                }
        }
    }
    codificata[j] = '\0';
}

int main() {
    char s1[] = "dddd";
    char s2[] = "affggg";
    char s3[] = "ffffffffffffff";
    char risultato[100];
    run_length(s1, risultato);
    printf("%s -> %s\n", s1, risultato);
    run_length(s2, risultato);
    printf("%s -> %s\n", s2, risultato);
    run_length(s3, risultato);
    printf("%s -> %s\n", s3, risultato);
    return 0;
}
