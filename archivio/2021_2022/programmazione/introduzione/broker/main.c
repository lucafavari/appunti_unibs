#include <stdio.h>

int main() {
    float investimento;
    float commissione;
    printf("Inserisci i soldi investiti: ");
    scanf("%f", &investimento);
    if (investimento < 2500)
        commissione = 30 + 0.017 * investimento;
    else if (investimento < 6250)
        commissione = 53 + 0.0066 * investimento;
    else if (investimento < 20000)
        commissione = 76 + 0.0034 * investimento;
    else
        commissione = 100 + 0.0022 * investimento;
    if (commissione < 39)
        commissione = 39;
    printf("La commissione sarà di %f euro\n",
           commissione);

    return 0;
}
