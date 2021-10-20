#include <stdio.h>
#include <math.h>

int main() {
    //Variabili per l'input
    float v_0, alfa;
    float x = 0, y = 0, t = 0;
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v_0);
    printf("Inserisci l'angolo in radianti: ");
    scanf("%f", &alfa);
    float v_0x, v_0y;
    v_0x = cos(alfa) * v_0;
    v_0y = sin(alfa) * v_0;
    do {
        printf("t: %.1f x: %.2f, y: %.2f\n", t, x, y);
        t += 0.1;
        x = v_0x * t;
        y = v_0y* t - 0.5 * 9.81 * t * t;
    }while (y > 0);
    return 0;
}
