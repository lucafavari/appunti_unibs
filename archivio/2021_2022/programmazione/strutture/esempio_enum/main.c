#include <stdio.h>

typedef enum{
    VERDE,
    GIALLO,
    ROSSO
} Colore;

void avanza(Colore *c)
{
    if (*c == VERDE)
        *c = GIALLO;
    else if (*c == GIALLO)
        *c = ROSSO;
    else
        *c = VERDE;
}

void stampa(Colore c)
{
    if (c == VERDE)
        printf("VERDE");
    else if (c == GIALLO)
        printf("GIALLO");
    else
        printf("ROSSO");
}

int main() {
    Colore c;
    c = VERDE;
    avanza(&c);
    stampa(c);
    return 0;
}
