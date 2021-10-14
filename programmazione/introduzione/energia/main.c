#include <stdio.h>

/*Direttiva al preprocessore
che definisce un valore che deve rimanere
costante per tutto il programma*/
#define GRAVITY 9.81

int main() {
    float m, v0, h0, t;
    float v, h, e_cinetica, e_potenziale;
    //Possibile, ma non robusto
    //float g = 9.81;
    printf("Inserisci la massa: ");
    scanf("%f", &m);
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v0);
    printf("Inserisci l'altezza iniziale: ");
    scanf("%f", &h0);
    printf("Inserisci il tempo: ");
    scanf("%f", &t);
    v = v0 - GRAVITY * t; //viene calcolata la velocità
    h = h0 + v0 * t - 0.5 * GRAVITY * t * t;
    e_cinetica = 0.5 * m * v * v;
    e_potenziale = m * GRAVITY * h;
    printf("L'energia cinetica vale: %f\n", e_cinetica);
    printf("L'energia potenziale vale: %f\n", e_potenziale);
    return 0;
}
