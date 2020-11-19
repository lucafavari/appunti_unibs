#include <stdio.h>
#include <stdlib.h>

#define N 16
/**
Funzione che ha lo scopo di mostrare una stringa dall'inizio alla fine,
anche oltre il terminatore
Il primo parametro è il nome della stringa, solo per chiarezza nella stampa
Il secondo parametro è la stringa da stampare
Il terzo parametro è la lunghezza in memoria della stringa, non quella del
suo contenuto, che si ferma al terminatore
*/
void stampa_vettore_di_caratteri(char *nome, char *s, int n)
{
    printf("\nStampa tutto il vettore %s\n", nome);
    for (int i = 0; i < n; i++)
        printf("   %c",s[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%4d",s[i]);
    printf("\n");
}

int main()
{
    char s1[N], s2[N];
    char temp;

    printf("Inserisci una stringa con la scanf: ");
    scanf("%s", s1);

    printf("Inserisci una stringa con la fgets: ");
    fgets(s2, N, stdin);

    stampa_vettore_di_caratteri("s1", s1, N);
    stampa_vettore_di_caratteri("s2", s2, N);

    printf("s1: %s\n", s1);
    printf("s2: %s a\n", s2);

    puts(s1);
    puts(s2);

    //Differenza tra leggere in numero come intero o come stringa di cifre
//    int a;
//    char s[N];
//    printf("Inserisci un numero: ");
//    fgets(s, N, stdin);
//    printf("Inserisci un numero: ");
//    scanf("%d", &a);
//    printf("%s %d\n", s, a);
//    int b = a + 2;
    return 0;
}
