#include <stdio.h>

#define DELTA_L 1

int main() {
    float lunghezza, larghezza; //espresse in millimetri
    float latoCorrente, latoMassimo, volumeMassimo;
    printf("Inserisci la lunghezza della lastra: ");
    scanf("%f", &lunghezza);
    printf("Inserisci la larghezza della lastra: ");
    scanf("%f", &larghezza);
    float minimoDimensione;
    if (lunghezza < larghezza){
        minimoDimensione = lunghezza;
    }
    else{
        minimoDimensione = larghezza;
    }
    latoCorrente = 0;
    volumeMassimo = 0;
    latoMassimo = 0;
    while(latoCorrente * 2 < minimoDimensione){
        latoCorrente += DELTA_L;
        float volumeCorrente = (lunghezza - 2 * latoCorrente) *
                (larghezza - 2 * latoCorrente) * latoCorrente;
        if (volumeCorrente > volumeMassimo){
            volumeMassimo = volumeCorrente;
            latoMassimo = latoCorrente;
        }
    }
    printf("Il lato che produce il volume massimo è %f e produce un volume di %f",
           latoMassimo, volumeMassimo);
    return 0;
}
