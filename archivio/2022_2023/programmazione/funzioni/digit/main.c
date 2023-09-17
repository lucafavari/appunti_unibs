#include <stdio.h>

int n_cifre(int n){
    int cifre = 0;
    while (n > 0){
        n /= 10;
        cifre++;
    }
    return cifre;
}

int k_esima(int n, int k){
    //Controllo del numero di cifra corretto 0 <= k < cifre di n
    if (k <= 0 || k > n_cifre(n)){
        return -1;
    }
    int risultato;
    //Estraiamo la k-esima cifra a partire da destra
    for (int i = 1; i <= k; ++i) {
        risultato = n % 10;
        n /= 10;
    }
    return risultato;
}

int main() {
    printf("%d\n", k_esima(12345, 2));
    printf("%d\n", k_esima(12345, 8));
    return 0;
}
