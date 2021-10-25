#include <stdio.h>
#include <math.h>

//Supponiamo che l'esponente sia positivo
double potenza(double base, int esponente)
{
    double valore = 1;
    for (int i = 0; i < esponente; i++)
        valore *= base;
    return valore;
}

int fattoriale(int n)
{
    if (n == 0)
        return 1;
    int valore = 1;
    for (int i = 1; i <= n; i++)
        valore *= i;
    return valore;
}

int main() {
    //Piccolo test per verificare se la funzione potenza è corretta
    //printf("%lf", potenza(2.3, 3));
    //printf("%d", fattoriale(0));
    int n;
    double x;
    printf("Inserisci il valore dell'angolo (in radianti): ");
    scanf("%lf", &x);
    printf("Inserisci il numero di termini della serie: ");
    scanf("%d", &n);
    double sommatoria = 0;
    for (int i = 0; i < n; i++)
    {
        sommatoria += potenza(-1, i) / fattoriale(2*i + 1)*
                potenza(x, 2*i + 1);
    }
    printf("Il calcolo fatto con la serie con i primi %d termini risulta: %lf\n",
           n, sommatoria);
    printf("Il risultato con la funzione di libreria invece vale: %lf",
           sin(x));
    return 0;
}
