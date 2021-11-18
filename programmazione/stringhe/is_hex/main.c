#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cifra_hex(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'F')
        return 1;
    if (c >= 'a' && c <= 'f')
        return 1;
    return 0;
}

int is_hex(char s[])
{
    int n = strlen(s);
    if (n < 3 || n > 10)
        return 0;
    if (s[0] != '0')
        return 0;
    if (s[1] != 'x' && s[1] != "X")
        return 0;
    //Versione alternativa
    //if (tolower(s[1]) != 'x')
    //    return 0;
    for (int i = 2; i < n; ++i) {
        if (cifra_hex(s[i]) == 0) // if (!cifra_hex(s[i]))
            return 0;
    }
    return 1;
}

int main() {
    //printf("%d %c",c , c );
    char s[] = "0xFF11";
    char t[] = "FFFF";
    if (is_hex(s) == 1)
        printf("La stringa %s è in esadecimale\n", s);
    else
        printf("La stringa %s non è in esadecimale\n", s);
    if (is_hex(t) == 1)
        printf("La stringa %s è in esadecimale\n", t);
    else
        printf("La stringa %s non è in esadecimale\n", t);
    return 0;
}
