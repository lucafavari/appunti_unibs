#include <stdio.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
    //Letture prese da 10 sensori una volta al minuto
    //durante tutta una giornata
    float sensori[10][1440];
}Dati_giornalieri;

float media_sensore_riferimento(Dati_giornalieri *d, int n)
{
    float media = 0;
    for (int i = 0; i < 1440; ++i) {
        media += d->sensori[n][i];
    }
    return media / 1440;
}

float media_sensore_copia(Dati_giornalieri d, int n)
{
    float media = 0;
    for (int i = 0; i < 1440; ++i) {
        media += d.sensori[n][i];
    }
    return media / 1440;
}

void annulla_letture_sensore(Dati_giornalieri *a, int n)
{
    for (int i = 0; i < 1440; ++i) {
        a->sensori[n][i] = 0;
    }
}

int main() {
    Dati_giornalieri a;
    //Input
    float media = media_sensore_copia(a, 2);
    media = media_sensore_riferimento(&a, 2);
    return 0;
}
