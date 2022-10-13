#include <stdio.h>

int main() {
    //Dichiarazione di variabile
    int distanza;
    //Dichiarazione e inizializzazione di variabile
    int altezza = 13;
    //Dichiarazione di più variabili sulla stessa riga
    int a, b;
    float area = 13.24;
    double perimetro = 23.45;
    char c = 'a';
    long long int numero_grande = 3473648237648736LL;
    unsigned int u = -123; //NO
    int reale = 12.34; //La parte decimale viene troncata
    //int 1utente; nome non valido
    //int numero utente; non si possono usare gli spazi
    //Se servono si fa così
    int numero_utente;
    a = 5;
    b = 7;
    int d = a + b;
    d = a % b;
    float f = 2.34;
    d = a + f;
    float g = a + f;
    int conta = 0;
    conta = conta + 1;
    //Equivalente alla scrittura sopra, ma più idiomatico
    conta++;
    int accumulatore = 0;
    int lato = 3;
    accumulatore = accumulatore + lato;
    //Equivalente alla scrittura sopra, ma più idiomatico
    accumulatore += lato;
    //Casting esplicito, senza il risultato sarebbe 0
    float h = (float)a / b;
    return 0;
}
