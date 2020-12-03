#include <stdio.h>
#include <stdlib.h>

typedef enum{
    ORDINARIO,
    ASSOCIATO,
    RICERCATORE
} Tipo;

typedef struct{
    char nome[50];
    char cognome[50];
    Tipo tipo;
} Docente;

int main()
{
    Docente d;
    //....
    if (d.tipo == ORDINARIO)
        printf("Il tuo stipendio è 6000 euro.\n");
    if (d.tipo == ASSOCIATO)
        printf("Il tuo stipendio è 4000 euro.\n");
    if (d.tipo == RICERCATORE)
        printf("Il tuo stipendio è 2000 euro.\n");
    printf("%d, %d, %d\n", ORDINARIO, ASSOCIATO, RICERCATORE);
    return 0;
}
