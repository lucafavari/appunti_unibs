#include <stdio.h>

int main() {
    int n, k;
    int fn, fk, fn_k;
    int coefficiente;
    printf("Inserisci il valore di n: ");
    scanf("%d", &n);
    printf("Inserisci il valore di k: ");
    scanf("%d", &k);
    //Primo modo, più semplice
    fn = 1;
    for (int i = 1; i <= n; i++)
        fn = fn * i;  //fn *= i;
    fk = 1;
    for (int i = 1; i <= k; i++)
        fk = fk * i;
    fn_k = 1;
    for (int i = 1; i <= n - k; i++)
        fn_k = fn_k * i;
    coefficiente = fn / (fk * fn_k);
    //Secondo modo, più efficiente, più complesso
    fn = fk = fn_k = 1;
    for (int i = 1; i <= n; i++)
    {
        fn = fn * i;
        if (i == k)
            fk = fn;
        if (i == n - k)
            fn_k = fn;
    }
    coefficiente = fn / (fk * fn_k);
    printf("Il coefficiente binomiale di %d su %d vale %d\n",
           n, k, coefficiente);
    return 0;
}
