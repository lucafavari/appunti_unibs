#include <stdio.h>

void codifica(char originale[], char compressa[])
{
    int posizione = 0;
    for (int i = 0; originale[i] != '\0' ; ++i) {
        int conta = 1;
        while (conta < 9 && originale[i] == originale[i+1]) {
            conta++;
            i++;
        }
        if (conta == 1)
        {
            compressa[posizione] = originale[i];
            posizione++;
        }
        else
        {
            compressa[posizione] = '0' + conta;
            posizione++;
            compressa[posizione] = originale[i];
            posizione++;
        }
    }
    compressa[posizione] = '\0';
}

int main() {
    char s1[] = "dddd";
    char s2[] = "abcdef";
    char s3[] = "fffffffffffffffyyyggggggrrabc";
    char compressa[100];
    codifica(s3, compressa);
    printf("%s\n", compressa);
    return 0;
}
