#include <stdio.h>
#include <stdlib.h>

/*
 * Una variabile per il turno
 * Una struttura che rappresenta i mazzi dei giocatori, delle carte da pescare e delle carte scartate
 * Una struttura per la carta, con la possibilità di rappresentare anche le azioni
 * Un enum per rappresentare le azioni
 * Una funzione per creare un mazzo di carte da Uno
 * Una funzione per mescolare il mazzo
 * Una funzione per pescare una carta dal mazzo
 * Una funzione controlla carta che riceve la carta precedente e la carta che si vuole giocare
 * Una funzione scarta per scartare la carta e una funzione per metterla in cima al mazzo delle scartate
 * Una funzione applica effetti per applicare gli effetti delle carte azioni
 */

typedef enum{
    NORMALE,
    CAMBIA_GIRO,
    SALTA,
    PESCA_DUE
} Tipo_carta;

typedef struct {
    int valore;
    char colore;
    Tipo_carta tipo;
} Carta;

typedef struct {
    Carta carte[112];
    int quante;
} Mazzetto;

void crea_mazzo(Mazzetto *m)
{
    char colori[] = "brvg";
    m->quante = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            m->carte[m->quante].valore = j;
            m->carte[m->quante].colore = colori[i];
            m->carte[m->quante].tipo = NORMALE;
            m->quante++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 10; ++j) {
            m->carte[m->quante].valore = j;
            m->carte[m->quante].colore = colori[i];
            m->carte[m->quante].tipo = NORMALE;
            m->quante++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            //Crea le carte cambia giro
            m->carte[m->quante].colore = colori[i];
            m->carte[m->quante].tipo = CAMBIA_GIRO;
            m->quante++;
            //Crea le carte salta turno
            m->carte[m->quante].colore = colori[i];
            m->carte[m->quante].tipo = SALTA;
            m->quante++;
            //Crea le carte pesca due
            m->carte[m->quante].colore = colori[i];
            m->carte[m->quante].tipo = PESCA_DUE;
            m->quante++;

        }
    }
}

void mescola_mazzo(Mazzetto *m)
{
    for (int i = 0; i < 10000; ++i) {
        int a = rand()%m->quante;
        int b = rand()%m->quante;
        Carta temp = m->carte[a];
        m->carte[a] = m->carte[b];
        m->carte[b] = temp;
    }
}

void stampa_carta(Carta c)
{
    if (c.tipo == NORMALE)
        printf("[ %d %c ]", c.valore, c.colore);
    if (c.tipo == CAMBIA_GIRO)
        printf("[ () %c ]", c.colore);
    if (c.tipo == SALTA)
        printf("[ >> %c]", c.colore);
    if (c.tipo == PESCA_DUE)
        printf("[ XX %c]", c.colore);
}

void stampa_mazzetto(Mazzetto m)
{
    for (int i = 0; i < m.quante; ++i) {
        stampa_carta(m.carte[i]);
    }
}

//Serve per pescare una carta dal mazzo
Carta pesca_carta(Mazzetto *m)
{
    Carta temp = m->carte[m->quante - 1];
    m->quante--;
    return temp;
}

//Serve per aggiungere una carta alla mano del giocatore
void dai_carta(Mazzetto *m, Carta c)
{
    m->carte[m->quante] = c;
    m->quante++;
}

//Serve per scartare una carta in una specifica posizione
Carta butta_carta(Mazzetto *m, int posizione)
{
    Carta temp = m->carte[posizione];
    for (int i = posizione; i < m->quante - 1 ; ++i) {
        m->carte[i] = m->carte[i+1];
    }
    m->quante--;
    return temp;
}

int controlla(Mazzetto m, Carta c)
{
    for (int i = 0; i < m.quante; ++i) {
        if (c.colore == m.carte[i].colore)
            return 1;
        if (c.tipo == NORMALE && c.valore == m.carte[i].valore)
            return 1;
    }
    return 0;
}

int main() {
    Mazzetto mazzo;
    crea_mazzo(&mazzo);
    //stampa_mazzetto(mazzo);
    mescola_mazzo(&mazzo);
    //stampa_mazzetto(mazzo);

    int turno = 0;
    int incrementa = 1;
    Mazzetto scarti;
    scarti.quante = 0;
    Mazzetto giocatori[30];
    int n_giocatori = 5;
    for (int i = 0; i < n_giocatori; ++i) {
        for (int j = 0; j < 7; ++j) {
            Carta c = pesca_carta(&mazzo);
            dai_carta(&giocatori[i], c);
        }
    }
    dai_carta(&scarti, pesca_carta(&mazzo));
    //printf("\n");
    //stampa_mazzetto(giocatori[0]);
    while(rand())
    {
        printf("\nTurno del giocatore %d\n", turno + 1);
        stampa_mazzetto(giocatori[turno]);
        if (controlla(giocatori[turno], scarti.carte[scarti.quante - 1]) == 1)
        {
            int scelta;
            printf("\n");
            stampa_carta(scarti.carte[scarti.quante - 1]);
            printf("\nQuale carta vuoi giocare? (1 - %d)", giocatori[turno].quante);
            scanf("%d", &scelta);
            Carta c = butta_carta(&giocatori[turno], scelta - 1);
            dai_carta(&scarti, c);
            //Controlla gli effetti della carta tirata
            if (c.tipo == CAMBIA_GIRO){
                incrementa = -incrementa;
            }
            else if (c.tipo == SALTA){
                incrementa *= 2;
            }
            else if (c.tipo == PESCA_DUE)
            {
                int prossimo = (n_giocatori + turno + incrementa) % (n_giocatori);
                Carta uno = pesca_carta(&mazzo);
                Carta due = pesca_carta(&mazzo);
                dai_carta(&giocatori[prossimo], uno);
                dai_carta(&giocatori[prossimo], due);
            }

        }
        else{
            dai_carta(&giocatori[turno], pesca_carta(&mazzo));
        }
        turno = (n_giocatori + turno + incrementa) % (n_giocatori);
        if (incrementa == 2)
            incrementa = 1;
        if (incrementa == -2)
            incrementa = -1;
    }
    return 0;
}
