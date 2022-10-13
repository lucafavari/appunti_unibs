#include <stdio.h>

int main() {
    //Variabili di input
    float acquisto;
    //Variabile di output
    float commissioni = 39;
    printf("Inserisci il valore di acquisto: ");
    scanf("%f", &acquisto);
    if (acquisto < 2500){
        commissioni += 30 + 0.017 * acquisto;
    }
    else if (acquisto < 6250){
        commissioni += 56 + 0.0066 * acquisto;
    }
    else if (acquisto < 20000){
        commissioni += 76 + 0.0034 * acquisto;
    }
    else{
        commissioni += 100 + 0.0022 * acquisto;
    }
    printf("Le commissioni per l'acquisto di %f euro sono %f euro.\n",
           acquisto, commissioni);
    return 0;
}
