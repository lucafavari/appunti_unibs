#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int main() {
    char s[] = "Ciao   ;   mondo buongiorno";
    pulisci(s);
    printf("%s\n", s);
    return 0;
}
