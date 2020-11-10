#include <stdio.h>
#include <stdlib.h>

#define N 100

void riempi_casuale(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = rand();
}

void stampa_vettore(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int ricerca_esaustiva(int v[], int n, int cercato)
{
    for (int i = 0; i < n; i++)
        if (v[i] == cercato)
            return i;
    return -1;
}

void inserimento_inizio(int v[], int n, int valore)
{
    for (int i = n; i > 0; i--)
        v[i] = v[i - 1];
    v[0] = valore;
}

void inserimento_posizione(int v[], int n, int valore, int pos)
{
    if (pos < 0 || pos > n)
        return;
    for (int i = n; i > pos; i--)
        v[i] = v[i - 1];
    v[pos] = valore;
}


int main()
{
    int v[N];
    riempi_casuale(v, N);
    v[N/2] = 99999;
    stampa_vettore(v, N);
    int trovato = ricerca_esaustiva(v, N, 99999);
    if (trovato >= 0)
        printf("Il numero di trova in posizione %d\n", trovato + 1);
    else
        printf("Non trovato\n");
    trovato = ricerca_esaustiva(v, N, -42);
    if (trovato >= 0)
        printf("Il numero di trova in posizione %d\n", trovato + 1);
    else
        printf("Non trovato\n");

    //Uso solo i primi elementi del vettore
    int elementi;
    printf("Inserisci gli elementi validi del vettore: ");
    scanf("%d", &elementi);
    riempi_casuale(v, elementi);
    stampa_vettore(v, elementi);
    inserimento_inizio(v,elementi, 100);
    elementi++;
    inserimento_inizio(v,elementi, 101);
    elementi++;
    stampa_vettore(v, elementi);
    inserimento_posizione(v, elementi, 999999, 7);
    elementi++;
    stampa_vettore(v, elementi);
    return 0;
}
