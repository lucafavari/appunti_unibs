#include <stdio.h>
#include <stdlib.h>

//Algoritmo di complessità lineare
void stampa(int v[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%4d", v[i]);
    }
    printf("\n");
}

int ricerca(int v[], int n, int cercato)
{
    for (int i = 0; i < n; ++i) {
        if (v[i] == cercato)
            return i;
    }
    return -1;
}

void inserisci_inizio(int v[], int n, int valore)
{
    for (int i = n - 1; i >= 0; --i) {
        v[i+1] = v[i];
    }
    v[0] = valore;
}

void inserisci_in_posizione(int v[], int n, int valore, int pos)
{
    for (int i = n - 1; i >= pos; --i) {
        v[i+1] = v[i];
    }
    v[pos] = valore;
}

void ordinamento_selection(int v[], int n)
{
    for (int i = 0; i < n; i++) {
        int indice_minore = i;
        for (int j = i; j < n; ++j) {
            if (v[j] < v[indice_minore])
                indice_minore = j;
        }
        int temp = v[i];
        v[i] = v[indice_minore];
        v[indice_minore] = temp;
    }
}

int main() {
    int v[] = {12, 34, 9, 27, 11, 31, 53, 2};
    int v2[10];
    for (int i = 0; i < 8; ++i) {
        v2[i] = rand()%100;
    }
    int n_elementi_v2 = 8;
    stampa(v, 8);
    stampa(v2, n_elementi_v2);
    printf("Il numero 53 si trova in posizione %d\n", ricerca(v, 8, 53));
    printf("Il numero 14 si trova in posizione %d\n", ricerca(v, 8, 14));
    inserisci_inizio(v2, n_elementi_v2, 110);
    n_elementi_v2++;
    stampa(v2, n_elementi_v2);
    inserisci_in_posizione(v2, n_elementi_v2, 400, 4);
    n_elementi_v2++;
    stampa(v2, n_elementi_v2);
    ordinamento_selection(v2, n_elementi_v2);
    stampa(v2, n_elementi_v2);
    return 0;
}
