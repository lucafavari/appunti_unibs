#include <stdio.h>

int main() {
    float base, altezza;
    float perimetro, area;
    printf("Inserisci la base e l'altezza: ");
    scanf("%f", &base);
    scanf("%f", &altezza);
    perimetro = 2*base + 2*altezza;
    area = base * altezza;
    printf("Il perimetro vale %f mentre l'area vale %f\n",
           perimetro, area);
    return 0;
}
