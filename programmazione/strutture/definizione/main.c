#include <stdio.h>
#include <math.h>
#include <string.h>
//Creo una variabile di nome punto che può essere usata dove serve
struct {
    float x;
    float y;
}punto;

//Crea un nuovo tipo di dato
typedef struct {
    float x;
    float y;
}Punto2D;

//Struttura annidata
typedef struct {
    Punto2D v1;
    Punto2D v2;
    Punto2D v3;
} Triangolo;

float distanza(Punto2D p1, Punto2D p2)
{
    float d;
    float c1 = p1.x - p2.x;
    float c2 = p1.y - p2.y;
    d = sqrt(c1*c1 + c2*c2);
    return d;
}

Punto2D punto_medio(Punto2D a, Punto2D b)
{
    Punto2D m;
    //m = (a +b)/2; NO
    m.x = (a.x + b.x)/2;
    m.y = (a.y + b.y)/2;
    return m;
}

typedef struct{
    int giorno;
    int mese;
    int anno;
}Data;

typedef struct{
    char nome[50];
    char cognome[50];
    char matricola[20];
    Data data_di_nascita;
}Studente;

int main(){
    punto.x = 3;
    //NOn si può fare
    //Punto2D.x = 2;
    //int = 7;
    Punto2D a;
    int b;
    a.x = 2.3;
    a.y = 3.4;
    //Assegnamento
    Punto2D c;
    c = a;
    //Non si possono usare direttamente gli operatori aritmetici
    c = c + a; //NO
    //NOn si possono usare gli operatori di confronto
    if (c < a) //NO
        {

        }
    //Se vogliamo usare degli operatori possiamo farlo a livello degli attributi
    //elementari
    c.x = c.x + a.x;
    //Poligono a 5 lati
    Punto2D pentagono[5];
    int vettore[5];
    Punto2D *d;
    d = &a;
    c.x = a.x; //notazione puntata per le variabili
    c.x = d->x; //notazione freccia per i puntatori a variabili
    Triangolo t;
    t.v1 = a;
    t.v2 = c;
    t.v3.x = 1.5;
    float distanza_punti = distanza(a, c);
    Punto2D m = punto_medio(a, c);
    Studente s;
    strncpy(s.nome,"Andrea",49);
    s.data_di_nascita.giorno = 12;
    s.data_di_nascita.mese = 12;
    s.data_di_nascita.anno = 2001;
    Data oggi;
    oggi.giorno = 29;
    oggi.mese = 11;
    oggi.anno = 2021;
    s.data_di_nascita = oggi;
    s.data_di_nascita.anno = 2001;
    return 0;
}
