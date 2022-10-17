#include <stdio.h>

int main() {
    //Conterrà la scelta del tipo di conversione
    int scelta;
    float celsius, fahrenheit;
    printf("1) Conversione Celsius -> Fahrenheit\n");
    printf("2) Conversione Fahrenheit -> Celsius\n");
    scanf("%d", &scelta);
    if (scelta == 1){
        printf("Inserisci i gradi Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = celsius * 9.0 / 5.0 + 32.0;
        printf("%f gradi Celsius corrispondono a %f gradi Fahrenheit\n",
               celsius, fahrenheit);
    }
    else{
        printf("Inserisci i gradi Fahrenheit: ");
        scanf("%f", & fahrenheit);
        celsius = 5.0 * fahrenheit / 9.0 - 32.0;
        printf("%f gradi Fahreneit corrispondono a %f gradi Celsius\n",
               fahrenheit, celsius);
    }
    return 0;
}
