#include <stdio.h>
#include <stdlib.h>

#define MAX 100;

typedef struct{
    char nome[100];
    char codice[100];
    float costo;
    float sconto; //intendo un valore compreso tra 0 e 1
} Prodotto;

typedef struct{
    Prodotto prodotto;
    int qta;
} ProdottoInCarrello;

typedef struct{
    ProdottoInCarrello prodotti[MAX];
    int prodotti_presenti;
} Carrello;

float costo_totale(Carrello c)
{
    float totale = 0;
    for (int i = 0; i < c.prodotti_presenti; i++)
        totale += c.prodotti[i].prodotto.costo *
            (1 - c.prodotti[i].prodotto.sconto) *
            c.prodotti[i].qta;
    return totale;
}

int rimuovi(Carrello *c, Prodotto p)
{
    for (int i = 0; i < c->prodotti_presenti; i++)
        if (strncmp(c->prodotti[i].prodotto.codice,
                    p.codice) == 0)
    {
        for (int j = i; j < c->prodotti_presenti - 1; j++)
            c->prodotti[j] = c->prodotti[j+1];
        c->prodotti_presenti--;
        return 1;
    }
    return 0;
}

int aggiungi(Carrello *c, Prodotto p)
{
    if (c->prodotti_presenti == MAX)
        return 0;
    for (int i = 0; i < c->prodotti_presenti; i++)
        if (strncmp(c->prodotti[i].prodotto.codice,
                    p.codice) == 0)
    {
        c->prodotti[i].qta++;
        return 1;
    }
    c->prodotti[c->prodotti_presenti] = p;
    c->prodotti_presenti++;
}

int main()
{
    Carrello c;
    Prodotto p;
    c.prodotti_presenti = 0;
    //....
    rimuovi(&c, p);
    return 0;
}
