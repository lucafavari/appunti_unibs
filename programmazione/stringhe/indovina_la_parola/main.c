#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char parole[120000][50];

//Lettura da file, solo per questo esercizio, non fa parte del programma
//da studiare
int parola_solo_minuscole(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] < 'a' || s[i] > 'z')
            return 0;
    }
    return 1;
}

int leggi_file(char nomefile[])
{
    FILE *f = fopen(nomefile, "r");
    if (f == NULL)
        return -1;
    char parola[50];
    int contatore = 0;
    while (fgets(parola, 49, f) != NULL) {
        parola[strlen(parola) - 1] = '\0';
        if (parola_solo_minuscole(parola)) {
            strncpy(parole[contatore], parola, 49);
            contatore++;
        }
    }
    return contatore;
}

int parola_indovinata(char s[])
{
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == '_')
            return 0;
    }
    return 1;
}

int controlla(char segreta[], char c, char indovinata[])
{
    int conta = 0;
    for (int i = 0; segreta[i] != '\0'; ++i) {
        if (segreta[i] == c)
        {
            indovinata[i] = c;
            conta++;
        }
    }
    return conta;
}

int presente(char s[], char c)
{
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == c)
            return 1;
    }
    return 0;
}

int main() {
    int parole_lette = leggi_file("italian.txt");
    char segreta[100];
    char indovinata[100];
    char lettere_provate[100];
    int n_lettere = 0;
    //Facciamo scegliere al computer una parola casuale
    int estratta;
    estratta = (rand()*0xFFFF + rand()) % parole_lette;
    strncpy(segreta, parole[estratta], 99);
    printf("La parola estratta dal computer è la seguente: %s\n", segreta);
    //Preparo la stringa che conterrà la parola parzialmente indovinata
    int i;
    for (i = 0; i < strlen(segreta); ++i) {
        indovinata[i] = '_';
    }
    indovinata[i] = '\0';
    printf("La stringa con i tuoi tentativi adesso è così: %s\n", indovinata);
    //printf("Nel file ci sono %d parole valide\n", parole);
    int tentativi = 0;
    while(parola_indovinata(indovinata) == 0 && tentativi < 8)
    {
        char c;
        printf("Inserisci la lettera che vuoi: ");
        scanf("%c", &c);
        //Serve solo a eliminare il \n dal buffer di lettura

        while(presente(lettere_provate, c))
        {
            scanf("%c", &c);
            printf("Attenzione, questa lettera l'avevi già provata, inseriscine un'altra: ");
            scanf("%c", &c);

        }
        //Serve solo a eliminare il \n dal buffer di lettura

        lettere_provate[n_lettere] = c;
        n_lettere++;
        lettere_provate[n_lettere] = '\0';
        int risultato = controlla(segreta, c, indovinata);
        scanf("%c", &c);
        if (risultato != 0){
            printf("Bravo, la lettera è presente.\n%s\n", indovinata);
        }
        else{
            printf("Attenzione, la lettera non è presente, riprova\n");
            printf("%s\n", indovinata);
            tentativi++;
        }
        printf("Finora hai provato le seguenti lettere: %s\n", lettere_provate);
        printf("Numero tentativi: %d\n", tentativi);
    }

    return 0;
}
