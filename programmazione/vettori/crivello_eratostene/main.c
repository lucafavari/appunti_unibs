#include <stdio.h>

#define MAX 1000

//I vettori globali non hanno un limite nella dimensione, MAX può essere grande
// "a piacere" con i limiti dettati dalla memoria RAM
int crivello[MAX];

int main() {
   //Inizializzo il vettore come se intendessi che tutti i numeri sono primi
   //Uso l'indice del vettore come valore del numero, cioè se crivello[2] = 1
   //si intende che il numero 2 è primo, se crivello[10] = 0 vuol dire che
   //il numero 10 non è primo
    for (int i = 0; i < MAX; ++i) {
        crivello[i] = 1;
    }
    for (int i = 2; i < MAX ; ++i) {
        //Se il numero i attuale è primo, cioè la sua casella contiene 1
        if (crivello[i] == 1){
            //Elimino tutti i suoi multipli
            for (int j = i + i; j < MAX; j += i) {
                crivello[j] = 0;
            }
        }
    }
    int numero_colonne = 10;
    int colonna = 0;
    for (int i = 2; i < MAX; ++i) {
        if (crivello[i] == 1){
            printf("%4d", i);
            colonna++;
            if (colonna == numero_colonne)
            {
                printf("\n");
                colonna = 0;
            }

        }
    }
    return 0;
}
