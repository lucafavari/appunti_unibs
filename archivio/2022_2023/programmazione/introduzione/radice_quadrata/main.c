#include <stdio.h>
#include <math.h>

//Valore che va a definire la precisione
#define EPSILON 0.000001

int main() {
    //Variabile di input, il valore di cui si vuole conoscere la radice
    double n;
    //Variabili di lavoro
    double a, b, medio;
    printf("Inserisci il valore di cui vuoi sapere la radice: ");
    scanf("%lf", &n);
    //Inizializzo l'intervallo dove si troverà la radice
    a = 0;
    b = n;

    while (b - a > EPSILON){
        medio = (a + b)/2;
        if (medio * medio > n){
            b = medio;
        }
        else{
            a = medio;
        }
    }
    printf("La radice di %lf è %.10lf\n", n, medio);
    printf("La radice di %lf è %.10lf\n", n, sqrt(n));

    return 0;
}
