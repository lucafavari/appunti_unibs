#include <stdio.h>
#include <stdlib.h>

typedef enum{
    DRAMMATICO,
    COMMEDIA,
    GIALLO
} Genere;

typedef struct{
    char titolo[100];
    Genere genere;
    float costo;
} Film;

typedef struct{
    char nome[100];
    char cognome[100];
    Film noleggiati[100];
    int quanti_noleggiati;
    float credito;
} Cliente;

int noleggio_possibile(Cliente c, Film f)
{
    if (c.credito < f.costo)
        return 0;
    for (int i = 0; i < c.quanti_noleggiati; i++)
        if (strncmp(c.noleggiati[i].titolo, f.titolo, 100) == 0)
            return 0;
    return 1;
}

int noleggia(Cliente *c, Film f)
{
    if (noleggio_possibile(*c, f) == 0)
        return 0;
    c->noleggiati[c->quanti_noleggiati] = f;
    c->quanti_noleggiati++;
    c->credito -= f.costo;
}

Genere genere_preferito(Cliente c)
{
    /*
    int v[3] = {0};
    for (int i = 0; i < c.quanti_noleggiati; i++)
        v[c.noleggiati[i].genere]++;

    int massimo = v[0];
    int indice = 0;
    for (int i = 1; i < 3; i++)
        if (v[i] > massimo)
        {
            massimo = v[i];
            indice = i;
        }
    return indice;
    */
    int a = 0,b = 0,c = 0;
    for (int i = 0; i < c.quanti_noleggiati; i++)
        if (c.noleggiati[i].genere == DRAMMATICO)
            a++;
        else if (c.noleggiati[i].genere == COMMEDIA)
            b++;
        else
            c++;
    if (a > b && a > c)
        return DRAMMATICO;
    if (b > a && b > c)
        return COMMEDIA;
    if (c > a && c > b)
        return GIALLO;
}

int main()
{

    return 0;
}








