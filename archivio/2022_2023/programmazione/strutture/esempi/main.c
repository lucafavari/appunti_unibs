#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definisco un nuovo tipo di dato a disposizione di qualsiasi parte del programma
typedef struct {
    float x;
    float y;
} Punto2D;

typedef struct {
    Punto2D v1;
    Punto2D v2;
    Punto2D v3;
} Triangolo;

typedef struct{
  Punto2D vertici[5];
} Pentagono;

#define MAX_VERTICI 100

typedef struct {
    Punto2D vertici[MAX_VERTICI];
    int n_vertici;
} Poligono;

float distanza(Punto2D p1, Punto2D p2){
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y - p2.y, 2));
}

float calcola_perimetro(Poligono p){
    float perimetro = 0;
    for (int i = 0; i < p.n_vertici; ++i) {
        Punto2D a = p.vertici[i];
        Punto2D b = p.vertici[(i+1)%p.n_vertici];
        perimetro += distanza(a, b);
    }
}

Punto2D punto_medio(Punto2D p1, Punto2D p2){
    Punto2D medio;
    //medio = (p1 + p2)/2;
    medio.x = (p1.x + p2.x)/2;
    medio.y = (p1.y + p2.y)/2;
    return medio;
}

typedef struct {
    Punto2D p1;
    Punto2D p2;
}RettangoloOrientato;

float calcola_perimetro_rettangolo(RettangoloOrientato r){
    float base = r.p1.x - r.p2.x;
    float altezza = r.p1.y - r.p2.y;
    return base * 2 + altezza * 2;
}

int main() {
    //Definisco delle variabili locali fatte in un certo modo
    struct {
        float x;
        float y;
    } p, r;//Nome della variabile di tipo struttura appena definita
    p.x = 7.4;//Si legge: il valore 7.4 viene assegnato all'attributo x di p
    p.y = 4.3;
    //Così non si può fare p = 7.4;
    //Anche per l'IO si ragiona in termini degli attributi elementari
    //scanf("%", &p); No, perchè la scanf dovrebbe "conoscere" la lettera da usare
    // dopo la %, cosa chiaramente impossibile perchè è un dato inventato da noi
    //scanf("%f", &p.x);
    //scanf("%f", &p.y);

    //printf("x:%f y:%f ", p.x, p.y);

    //Da qui usiamo la struttura generale definita all'inizio del programma
    //Dichiaro una variabile di tipo Punto2D
    Punto2D p1, p2;
    p1.x = p1.y = 1;
    //Tutte le operazioni relazionali non sono valide per le strutture
    //if (p1 > p2) NO
    //L'unica operazione elementare valida tra strutture è la copia
    p2 = p1;
    printf("p1: %f, %f  p2:%f, %f\n", p1.x, p1.y, p2.x, p2.y);
    Triangolo t;
    t.v1.x = 1.2;
    t.v1.y = 2.4;
    t.v2 = p1;
    t.v3.x = 3.4;
    t.v3.y = 7.8;

    Pentagono pentagono;

    for (int i = 0; i < 5; ++i) {
        pentagono.vertici[i].x = rand()%100;
        pentagono.vertici[i].y = rand()%100;
    }
    float perimetro = 0;
    //Calcolo il perimetro di questo ipotetico pentagono
    for (int i = 0; i < 5; ++i) {
        perimetro += sqrt((pentagono.vertici[i].x - pentagono.vertici[(i+1)%5].x)
                * (pentagono.vertici[i].x - pentagono.vertici[(i+1)%5].x) +
                (pentagono.vertici[i].y - pentagono.vertici[(i+1)%5].y) *
                (pentagono.vertici[i].y - pentagono.vertici[(i+1)%5].y)
                );
    }
    for (int i = 0; i < 5; ++i) {
        Punto2D a = pentagono.vertici[i];
        Punto2D b = pentagono.vertici[(i+1)%5];
        perimetro += distanza(a,b);
    }

    Poligono dodecagono;
    dodecagono.n_vertici = 12;
    for (int i = 0; i < dodecagono.n_vertici; ++i) {
        dodecagono.vertici[i].x = rand()%100;
        dodecagono.vertici[i].y = rand()%100;
    }
    perimetro = calcola_perimetro(dodecagono);
    Punto2D p3 = punto_medio(p1,p2);
    return 0;
}
