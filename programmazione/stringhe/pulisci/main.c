#include <stdio.h>
#include <string.h>
#include <ctype.h>

void pulisci(char s[]){
    int j = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z')){
            s[j] = tolower(s[i]);
            j++;
        }
    }
    s[j] = '\0';
}

int main() {
    char s[] = "Ciao      mondo buongiorno";
    pulisci(s);
    printf("%s\n", s);
    return 0;
}
