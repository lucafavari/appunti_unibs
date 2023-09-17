#include <stdio.h>
#include <math.h>

#define G 9.81
#define DELTA_T 0.05

int main() {
    float v0, alfa;
    float x, y, t;
    float v0x, v0y;
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v0);
    printf("Inserisci l'angolo di partenza: ");
    scanf("%f", &alfa);
    v0x = cos(alfa) * v0;
    v0y = sin(alfa) * v0;
    t = 0;
    x = y = 0;
    do {
        printf("x: %f, y: %f\n", x, y);
        t += DELTA_T;
        x = v0x * t;
        y = v0y * t - 0.5 * G * t * t;
    }while(y > 0);
    printf("Il tempo di volo del proiettile è di circa %f secondi\n",
           t);
    return 0;
}
