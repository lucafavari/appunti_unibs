#include <stdio.h>
#include <string.h>

#define NUMERO_LETTERE 26

void crea_tavola(char m[][NUMERO_LETTERE + 1]){
    char inizio = 'a';
    for (int i = 0; i < NUMERO_LETTERE; ++i) {
        for (int j = 0; j < NUMERO_LETTERE; ++j) {
            m[i][j] = (inizio - 'a' + j) % NUMERO_LETTERE + 'a';
        }
        m[i][26] = '\0';
        inizio++;
    }
}

char codifica_carattere(char tavola[][NUMERO_LETTERE + 1], char c, char posizione){
    char ch = tavola[posizione - 'a'][c - 'a'];
    return ch;
}

void codifica_vigenere(char tavola[][NUMERO_LETTERE + 1], char chiaro[], char chiave[])
{
    int indice_chiave = 0;
    for (int i = 0; chiaro[i] != '\0'; ++i) {
        chiaro[i] = codifica_carattere(tavola, chiaro[i],chiave[indice_chiave]);
        indice_chiave = (indice_chiave + 1) % strlen(chiave);
    }
}

int main() {
    char tavola[NUMERO_LETTERE][NUMERO_LETTERE + 1];
    char chiaro[] = "ciaoatutti";
    char chiave[] = "sole";
    crea_tavola(tavola);
    for (int i = 0; i < 26; ++i) {
//        for (int j = 0; j < 26; ++j) {
//            printf("%c", tavola[i][j]);
//        }
//        printf("\n");
        printf("%s\n", tavola[i]);
    }
    printf("Prima della cifratura: %s\n", chiaro);
    codifica_vigenere(tavola, chiaro, chiave);
    printf("Dopo la cifratura: %s\n", chiaro);
    return 0;
}
