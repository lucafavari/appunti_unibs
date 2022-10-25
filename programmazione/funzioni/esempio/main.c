#include <stdio.h>

/**
 *
 * @param a Parametro formale
 * @param b Parametro formale
 * @return
 */
int maggiore(int a, int b){
    /*if (a > b){
        return a;
    }
    else{
        return b;
    }
    if (a > b)
        return a;
    return b;*/
    int maggiore;
    if (a > b){
        maggiore = a;
    }
    else
    {
        maggiore = b;
    }
    return maggiore;
}

/**
 * Funzione d'esempio che fa un certo numero di saluti
 * @param numero_saluti Numero di ripetizioni
 */
void saluti(int numero_saluti){
    for (int i = 0; i < numero_saluti; ++i) {
        printf("ciao\n");
    }
}

int main(void) {
    int c, d, e;
    c = 5;
    d = 7;
    e = 9;
    int m = maggiore(c, d);
    printf("Il maggiore è :%d\n", m);
    m = maggiore (d, c);
    printf("Il maggiore è ; %d\n", m);
    m = maggiore (c, c);
    printf("Il maggiore è ; %d\n", m);

    printf("Il maggiore è : %d\n", maggiore(d, e));
    m = maggiore(c, maggiore(d, e));
    saluti(10);
    return 0;
}
