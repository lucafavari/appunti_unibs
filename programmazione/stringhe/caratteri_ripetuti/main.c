#include <stdio.h>

/**
 *
 * @param s stringa da pulire
 * @param t stringa ripulita dalle ripetizioni
 * @param n numero massimo di caratteri che può accogliere t
 */
void elimina_ripetizioni(char s[], char t[], int n){
    int j = 0;
    //Costruiamo un vettore di supporto per indicare le ripetizioni
    int caratteri[127];
    for (int i = 0; i < 127; ++i) {
        caratteri[i] = 0;
    }
    //Nella condizione del for verifichiamo di fermarsi quando s "finisce"
    //oppure quando j diventa = a n
    for (int i = 0; s[i] != '\0' && j < n; ++i) {
        if (caratteri[s[i]] == 0){
            t[j] = s[i];
            j++;
            caratteri[s[i]] = 1;
        }
    }
    t[j] = '\0';
}

int main() {
    char s[] = "Attacchiamo all'alba di domani";
    char t[100];
    elimina_ripetizioni(s, t, 99);
    printf("%s\n", t);
    return 0;
}
