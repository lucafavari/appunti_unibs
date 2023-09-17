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

char codifica_carattere(char c, char chiave[]){
    return chiave[c - 'a'];
}

void codifica_sostituzione(char s[], char chiave[]){
    for (int i = 0; s[i] != '\0' ; ++i) {
        s[i] = codifica_carattere(s[i], chiave);
    }
}

char decodifica_carattere(char c, char chiave[]){
    int pos;
    for (int i = 0; i < 26; ++i) {
        if (chiave[i] == c){
            pos = i;
        }
    }
    return 'a' + pos;
    /*for (int i = 0; i < 26; ++i) {
        if (chiave[i] == c)
            return 'a' + i;
    }*/
}

void decodifica_sostituzione(char s[], char chiave[]){
    for (int i = 0; s[i] != '\0' ; ++i) {
        s[i] = decodifica_carattere(s[i], chiave);
    }
}

int main() {
    char chiave[] = "frkqwetyuiopasdghjlmnbvcxz";
    char chiaro[] = "Attacchiamo al tramonto";
    pulisci(chiaro);
    printf("%s\n", chiaro);
    codifica_sostituzione(chiaro, chiave);
    printf("%s\n", chiaro);
    decodifica_sostituzione(chiaro, chiave);
    printf("%s\n", chiaro);
    return 0;
}
