#include <stdio.h>
#include <string.h>

#define MAX_STUDENTI 100

typedef struct {
    int g;
    int m;
    int a;
}Data;

typedef struct {
    char nome[100];
    Data data_registrazione;
    int voto;
}Esame;

typedef struct {
    char matricola[10];
    char nome[50];
    char cognome[50];
    Esame esami[100];
    int n_esami_passati;
    float media;
}Studente;

int aggiungi_studente(Studente v[], int n_studenti, Studente a)
{
    v[n_studenti] = a;
    n_studenti++;
    return n_studenti;
}

int ricerca_per_matricola(Studente v[], int n_studenti, char matricola[])
{
    for (int i = 0; i < n_studenti; ++i) {
        if (strncmp(v[i].matricola, matricola, 9) == 0)
            return i;
    }
    return -1;
}

int ricerca_per_cognome(Studente v[], int n_studenti, char cognome[])
{
    for (int i = 0; i < n_studenti; ++i) {
        if (strncmp(v[i].cognome, cognome, 49) == 0)
            return i;
    }
    return -1;
}

void aggiungi_esame(Studente *s, Esame e)
{
    s->esami[s->n_esami_passati] = e;

    float somma;
    somma = s->media * s->n_esami_passati;
    somma += e.voto;
    s->media = somma/(s->n_esami_passati + 1);
    s->n_esami_passati++;
}

int esame_passato(Studente s, char nome_esame[])
{
    for (int i = 0; i < s.n_esami_passati; ++i) {
        if (strncmp(s.esami[i].nome, nome_esame, 99) == 0)
            return 1;
    }
    return 0;
}

void stampa_elenco_esame(Studente v[], int n_studenti, char nome_esame[])
{
    for (int i = 0; i < n_studenti; ++i) {
        if (esame_passato(v[i], nome_esame) == 1)
            printf("%s %s %s\n", v[i].matricola,
                   v[i].cognome, v[i].nome);
    }
}

void stampa_studente(Studente s)
{
    printf("Matricola: %s\n Nominativo: %s %s\n",
           s.matricola, s.nome, s.cognome);
    if (s.n_esami_passati == 0)
        printf("Non sono ancora stati segnati esami\n");
    else
        for (int i = 0; i < s.n_esami_passati; ++i) {
            printf("%s: voto %d, in data %d/%d/%d\n",
                   s.esami[i].nome, s.esami[i].voto,
                   s.esami[i].data_registrazione.g,
                   s.esami[i].data_registrazione.m,
                   s.esami[i].data_registrazione.a);
        }
}

void stampa_studenti_ordinati_cognome(Studente s[], int n_studenti)
{
    int minimo_trovato;
    for (int i = 0; i < n_studenti; ++i) {
        minimo_trovato = i;
        for (int j = i + 1; j < n_studenti; ++j) {
            if (strncmp(s[j].cognome, s[minimo_trovato].cognome, 49) < 0)
                minimo_trovato = j;
        }
        Studente temp = s[i];
        s[i] = s[minimo_trovato];
        s[minimo_trovato] = temp;
    }
    for (int i = 0; i < n_studenti; ++i) {
        stampa_studente(s[i]);
    }

}


void menu()
{
    printf("1 - Aggiungi un nuovo studente\n");
    printf("2 - Aggiungi un esame a uno studente\n");
    printf("3 - Stampa gli esami di uno studente\n");
    printf("4 - Stampa gli studenti che hanno passato un certo esame\n");
    printf("99 - Stampa tutti gli studenti\n");
    printf("0 - Chiudi il programma");
}

int main() {
    Data d = {1, 12, 2021};
    Esame e = {
            "Elementi di Informatica",
            {24, 1, 2021},
            30
    };
    Esame esami[] ={
            {
                    "Elementi di Informatica",
                    {24, 1, 2021},
                    30
            },
            {
                    "Analisi",
                    {20, 1, 2021},
                    30
            }
    };
    Studente s = {
            "77777",
            "Giorgietta",
            "Nusini",
            {
                    {
                            "Elementi di Informatica",
                            {24, 1, 2021},
                            30
                    },
                    {
                        "Analisi",
                        {20, 1, 2021},
                        30
                    }
            },
            2,
            30
    };

    Studente studenti[MAX_STUDENTI];
    int n_studenti = 0;
    Studente temp;
    int scelta;
    char nome_esame[100];
    n_studenti = aggiungi_studente(studenti, n_studenti, s);
    menu();
    scanf("%d", &scelta);
    while(scelta != 0)
    {
        switch (scelta) {
            case 1:
                printf("Matricola: ");
                scanf("%s", temp.matricola);
                printf("Nome: ");
                scanf("%s", temp.nome);
                printf("Cognome: ");
                scanf("%s", temp.cognome);
                temp.n_esami_passati = 0;
                n_studenti = aggiungi_studente(studenti,n_studenti, temp);
                break;
            case 2:
                printf("Ricerca per matricola (1) o per cognome (2)?\n");
                int tipo, studente;
                scanf("%d", &tipo);
                if (tipo == 1){
                    char matricola[10];
                    printf("Inserisci la matricola: ");
                    scanf("%s", matricola);
                    studente = ricerca_per_matricola(studenti, n_studenti,
                                                     matricola);
                }
                else
                {
                    char cognome[10];
                    printf("Inserisci il cognome: ");
                    scanf("%s", cognome);
                    studente = ricerca_per_cognome(studenti, n_studenti,
                                                     cognome);
                }
                if (studente == -1)
                    printf("Studente inesistente\n");
                else{
                    printf("Inserisci il nome dell'esame: ");
                    scanf("%s", &e.nome);
                    printf("Inserisci il voto: ");
                    scanf("%d", &e.voto);
                    printf("Inserisci giorno, mese e anno: ");
                    scanf("%d", &e.data_registrazione.g);
                    scanf("%d", &e.data_registrazione.m);
                    scanf("%d", &e.data_registrazione.a);
                    aggiungi_esame(&studenti[studente], e);
                }
                break;
            case 3:
                printf("Ricerca per matricola (1) o per cognome (2)?\n");
                scanf("%d", &tipo);
                if (tipo == 1){
                    char matricola[10];
                    printf("Inserisci la matricola: ");
                    scanf("%s", matricola);
                    studente = ricerca_per_matricola(studenti, n_studenti,
                                                     matricola);
                }
                else
                {
                    char cognome[10];
                    printf("Inserisci il cognome: ");
                    scanf("%s", cognome);
                    studente = ricerca_per_cognome(studenti, n_studenti,
                                                   cognome);
                }
                if (studente == -1)
                    printf("Studente inesistente\n");
                else
                    stampa_studente(studenti[studente]);
                break;
            case 4:
                printf("Inserisci il nome dell'esame: ");
                scanf("%s", nome_esame);
                stampa_elenco_esame(studenti, n_studenti, nome_esame);
                break;
            case 99:
                for (int i = 0; i < n_studenti; ++i) {
                    stampa_studente(studenti[i]);
                }
                break;
        }
        menu();
        scanf("%d", &scelta);
    }
    return 0;
}
