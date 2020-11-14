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

int ricerca_binaria(int v[], int n, int cercato)
{
    int a = 0, b = n - 1;
    int m = (a + b)/2;
    while(a <= b)
    {
        if (v[m] == cercato)
            return m;
        else if (v[m] < cercato)
            a = m + 1;
        else
            b = m - 1;
        m = (a + b)/2;
    }
    return -1;
}

void inserimento_inizio(int v[], int n, int valore)
{
    for (int i = n; i > 0; i--)
        v[i] = v[i - 1];
    v[0] = valore;
}

int inserimento_posizione(int v[], int n, int valore, int pos)
{
    if (pos < 0 || pos > n)
        return -1;
    for (int i = n; i > pos; i--)
        v[i] = v[i - 1];
    v[pos] = valore;
    return pos;
}

int elimina_posizione(int v[], int n, int pos)
{
    if (pos < 0 || pos >= n)
        return -1;
    for (int i = pos; i < n - 1; i++)
        v[i] = v[i + 1];
    //return 1;
    //return pos;
    return n - 1;
}

void bubble_sort(int v[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (v[j - 1] > v[j])
            {
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
    }

}

void selection_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos_minimo = i;
        for (int j = i; j < n; j++)
            if (v[j] < v[pos_minimo])
                pos_minimo = j;
        int temp = v[i];
        v[i] = v[pos_minimo];
        v[pos_minimo] = temp;
    }

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

    elimina_posizione(v, elementi, 3);
    elementi--;
    stampa_vettore(v, elementi);

    printf("Bubblesort\n");
    bubble_sort(v, elementi);
    stampa_vettore(v, elementi);

    printf("Selectionsort\n");
    riempi_casuale(v, elementi);
    stampa_vettore(v, elementi);
    selection_sort(v,elementi);
    stampa_vettore(v, elementi);

    int d = ricerca_binaria(v, elementi, 10);
    if (d == -1)
        printf("Non trovato\n");
    else
        printf("Trovato in posizione %d\n", d);

    d = ricerca_binaria(v, elementi, 6270);
    if (d == -1)
        printf("Non trovato\n");
    else
        printf("Trovato in posizione %d\n", d);

    return 0;
}
