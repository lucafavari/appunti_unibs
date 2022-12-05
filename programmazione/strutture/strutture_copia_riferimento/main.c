#include <stdio.h>
/*
#define N 10

typedef struct {
    char video[N][N];
}Video;

typedef struct {
    int x;
    int y;
    Video v;
}Punto_v1;

typedef struct {
    int x;
    int y;
    Video *v;
}Punto_v2;

void stampa_video(Video *v){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c", v->video[i][j]);
        }
        printf("\n");
    }
}

void set_punto(Punto_v2 *p){
    p->v->video[p->x][p->y] = 'x';
}

int main() {
    Punto_v1 p1, p2;
    p1.x = 7;
    p1.y = 5;
    Video v;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            v.video[i][j] = 'o';
        }
    }
    p1.v = v;
    //set_punto(&p1);
    //stampa_video(p1.v);
    p2 = p1;
    //stampa_video(p2.v);
    p2.x = 2;
    //set_punto(&p2);
    //stampa_video(p2.v);
    //stampa_video(p1.v);

    Punto_v2 p3, p4;
    p3.x = 7;
    p3.y = 7;
    p3.v = &v;
    //stampa_video(*p3.v);
    set_punto(&p3);
    stampa_video(p3.v);
    p4 = p3;
    p4.x = 3;
    p4.y = 2;
    set_punto(&p4);
    stampa_video(p4.v);
    stampa_video(p3.v);

    return 0;
}*/

/** Esempio di passaggio di parametro per copia e indirizzo
 * e conseguenze in termini di copia piuttosto che di riferimento
 *
 */

#define H 5
#define W 5

typedef struct{
    char m[H][W];
} Schermo;

typedef struct {
    int x;
    int y;
    Schermo s;
}OggettoV1;

typedef  struct{
    int x;
    int y;
    Schermo *s;
}OggettoV2;

void stampa_schermo(Schermo s){
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            printf("%c", s.m[i][j]);
        }
        printf("\n");
    }
}

void metti_a_schermo(OggettoV1 o){
    o.s.m[o.x][o.y] = 'x';
}

//Il passaggio per indirizzo in questo caso è obbligatorio
//perchè si vuole modificare l'oggetto passato
void metti_a_schermo_per_indirizzo(OggettoV1 *o){
    o->s.m[o->x][o->y] = 'x';
}

void metti_a_schermoV2(OggettoV2 *o) {
    o->s->m[o->x][o->y] = 'x';
}

int main(){
    OggettoV1 o1, o2;
    o1.x = 2;
    o1.y = 3;
    Schermo schermo;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            schermo.m[i][j] = '.';
        }
    }
    o1.s = schermo;
    //stampa_schermo(schermo);
    //stampa_schermo(o1.s);
    //Attenzione che schermo e o1.s, pur essendoci l'assegnamento,
    //sono due cose diverse
    //La chiamata di questa funzione lavora su una copia di o1,
    //quindi lo schermo non si aggiorna;
    //metti_a_schermo(o1);
    //stampa_schermo(o1.s);
    metti_a_schermo_per_indirizzo(&o1);
    //stampa_schermo(o1.s);
    o2 = o1;
    //stampa_schermo(o2.s);
    o2.x = 4;
    o2.y = 1;
    metti_a_schermo_per_indirizzo(&o2);
    //stampa_schermo(o2.s);
    //stampa_schermo(o1.s);
    //stampa_schermo(schermo);
    OggettoV2 o3,o4;
    o3.x = 2;
    o3.y = 2;
    o3.s = &schermo;
    metti_a_schermoV2(&o3);
    //stampa_schermo(schermo);
    o4 = o3;
    o4.x = 1;
    o4.y = 1;
    metti_a_schermoV2(&o4);
    //stampa_schermo(schermo);
    stampa_schermo(*o3.s);
    return 0;
}