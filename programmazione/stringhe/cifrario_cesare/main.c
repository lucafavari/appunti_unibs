#include <stdio.h>

int is_char(char c){
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

char my_tolower(char c){
    if (c >= 'A' && c <= 'Z'){
        c = c - 'A' + 'a';
    }
    return c;
}

void pulisci(char s[]){
    int j = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (is_char(s[i]) == 1){ //isalpha
            s[j] = my_tolower(s[i]); //tolower
            j++;
        }
    }
    s[j] = '\0';
}


/**
 *
 * @param s Testo in chiaro
 * @param chiave Di quante posizioni in avanti devo modificare il carattere
 */


char codifica_carattere(char s, int chiave){
    return (((s - 'a') + chiave) % 26) + 'a';
}

void codifica_cesare(char s[], int chiave){
    for (int i = 0; s[i] != '\0' ; ++i) {
        s[i] = codifica_carattere(s[i], chiave);
    }
}

char decodifica_carattere(char c, int chiave){
    return ((c - 'a') - chiave + 26) % 26 + 'a';
}

void decodifica_cesare(char s[], int chiave)
{
    for (int i = 0; s[i] != '\0' ; ++i) {
        s[i] = decodifica_carattere(s[i], chiave);
    }
}

int main() {
    char chiaro[] = "Attacchiamo all'alba";
    pulisci(chiaro);
    printf("%s\n",chiaro);
    codifica_cesare(chiaro, 3);
    printf("%s\n", chiaro);
    decodifica_cesare(chiaro, 3);
    printf("%s\n", chiaro);
    return 0;
}
