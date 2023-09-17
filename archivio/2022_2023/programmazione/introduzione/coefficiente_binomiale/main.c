#include <stdio.h>

int main() {
    int n = 5, k = 2; //Valori di esempio
    int f_n, f_k, f_n_k;
    int coefficiente;
    f_n = f_k = f_n_k = 1;
    for (int i = 1; i <= n ; ++i) {
        f_n *= i;
    }
    for (int i = 1; i <= k; ++i) {
        f_k *= i;
    }
    for (int i = 1; i <= n - k; ++i) {
        f_n_k *= i;
    }
    coefficiente = f_n / (f_k * f_n_k);
    printf("Il coefficiente binomiale di %d su %d vale %d", n, k, coefficiente);
    return 0;
}
