#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
}Data;

typedef struct{
    char nome[50];
    char cognome[50];
    int punteggio;
    int ranking;
    Data data_di_nascita;
} Tennista;

void stampa(Tennista t)
{
    printf("Informazioni su %s %s\n",t.nome, t.cognome);
    printf("Punteggio: %d\t\t\tRanking: %d\n", t.punteggio, t.ranking);
}

void incrementa_punteggio(Tennista *t, int p)
{
    t->punteggio += p;
}

void stampa_partecipanti(Tennista t[], int n)
{
    printf("Lista partecipanti\n");
    for (int i = 0; i < n; i++)
        stampa(t[i]);
}

Tennista testa_di_serie(Tennista t[], int n)
{
    Tennista migliore = t[0];
    for (int i = 0; i < n; i++)
        if (t[i].punteggio > migliore.punteggio)
            migliore = t[i];
    return migliore;
}

//Dato l'elenco dei partecipanti e il cognome di un giocatore
//incrementa il punteggio di una certa quantità
void incrementa_punteggio_vittoria(Tennista t[], int n,
                                   char giocatore[], int p)
{
    for (int i = 0; i < n; i++)
        if (strncmp(t[i].cognome, giocatore, 50) == 0)
            //incrementa_punteggio(&t[i], p);
            t[i].punteggio += p;
}

int main()
{
    Tennista a;
    a.punteggio = 5854;
    a.ranking = 5;
    a.data_di_nascita.giorno = 22;
    strncpy(a.nome, "Roger", 50);
    strncpy(a.cognome, "Federer", 50);
    stampa(a);
    incrementa_punteggio(&a, 250);
    stampa(a);

    Tennista tennisti[100];
    int numero_tennisti = 0;
    tennisti[numero_tennisti] = a;
    numero_tennisti++;

    a.punteggio = 9754;
    a.ranking = 2;
    strncpy(a.nome, "Rafael", 50);
    strncpy(a.cognome, "Nada", 50);
    tennisti[numero_tennisti] = a;
    numero_tennisti++;

    incrementa_punteggio(&tennisti[1],500);

    stampa_partecipanti(tennisti, numero_tennisti);
    printf("La testa di serie del torneo è: \n");
    stampa(testa_di_serie(tennisti, numero_tennisti));
    incrementa_punteggio_vittoria(tennisti, numero_tennisti, "Nadal", 100);
    stampa(testa_di_serie(tennisti, numero_tennisti));
    return 0;
}
