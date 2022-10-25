#include <stdio.h>
#include <math.h>

int primo(int n){
    for (int i = 2; i <=sqrt(n) ; ++i) {
            if (n % i == 0)
                return 0;
    }
    return 1;
}

/**
 * Conta quanti sono i numeri primi compresi tra inizio e fine inclusi
 * @param inizio
 * @param fine
 * @return
 */
int quanti_primi(int inizio, int fine){
    int quanti = 0;
    for (int i = inizio; i <= fine ; ++i) {
        if (primo(i))
            quanti++;
    }
    return quanti;
}

int main() {
    int i = 50, f = 10000;
    printf("I numeri primi compresi tra %d e %d sono %d\n", i, f,
           quanti_primi(i, f));
    return 0;
}
