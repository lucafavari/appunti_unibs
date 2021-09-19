#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 //Da spiegare
#define DELTA_T 0.01

int main()
{
    float alfa, vel_iniziale;
    float x = 0, y = 0, vx, vy, t = 0;
    //float DELTA_T = 0.01;
    printf("Inserisci l'angolo alfa in gradi: ");
    scanf("%f", &alfa);
    //Conversione in radianti
    alfa = alfa/180*3.14;
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &vel_iniziale);
    vx = vel_iniziale*cos(alfa);
    vy = vel_iniziale*sin(alfa);
    do
    {
        printf("La posizione del proiettile all'istante %f vale (%f, %f)\n",
               t, x, y);
        t = t + DELTA_T;
        x = x + vx*DELTA_T;
        y = vy*t - 0.5*G*t*t;
    }while(y > 0);
    return 0;
}
