#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct {
    int x;
    int y;
} Punto2D;

typedef struct{
    Punto2D a;
    Punto2D b;
    Punto2D c;
} Triangolo;

float distanza(Punto2D a, Punto2D b)
{
    return sqrt(pow(a.x - b.x, 2) +
                pow(a.y - b.y, 2));
}

Punto2D punto_medio(Punto2D a, Punto2D b)
{
    Punto2D t;
    t.x = (a.x + b.x)/2;
    t.y = (a.y + b.y)/2;
    return t;
}

typedef struct {
    float a;
    float b;
    float c;
} Coefficienti;

typedef struct{
    float x1;
    float x2;
} Soluzioni;

double delta(Coefficienti coeff)
{
    return coeff.b*coeff.b - 4*coeff.a*coeff.c;
}

Soluzioni secondo_grado(Coefficienti *coeff)
{
    Soluzioni temp;
    temp.x1 = - coeff->b + sqrt(delta(*coeff))/(2*coeff->a);
    temp.x2 = - coeff->b - sqrt(delta(*coeff))/(2*coeff->a);
    return temp;
}

void azzera_coefficienti(Coefficienti *coeff)
{
    //(*coeff).a = (*coeff).b = (*coeff).c = 0;
    coeff->a = coeff->b = coeff->c = 0;
}

int main()
{
    /*int x[N];
    int y[N];
    int forza[N];
    ...
    float distanza = sqrt(pow(x[0] - x[1], 2)
                          + pow(y[0] - y[1], 2));

    Punto2D p;
    printf("Inserisci il valore x di p: ");
    scanf("%d", &p.x);
    printf("Inserisci il valore y di p: ");
    scanf("%d", &p.y);
    printf("IL punto p ha le coordinate: (%d, %d)\n",
           p.x, p.y);
    //float distanza = sqrt(pow(p.x - r.x,2) +
    //                      pow(p.y - r.y, 2));
    Punto2D v[N];
    //....
    float d = distanza(v[0], v[1]);
    */
    Coefficienti coefficienti;
    coefficienti.a = 10;
    coefficienti.b = 20;
    coefficienti.c = 1;
    Soluzioni s = secondo_grado(&coefficienti);
    printf("Le due soluzioni sono x1: %f e x2: %f\n",
           s.x1, s.x2);
    Coefficienti coefficienti2 = coefficienti;
    s = secondo_grado(&coefficienti2);
    printf("Le due soluzioni sono x1: %f e x2: %f\n",
           s.x1, s.x2);
    azzera_coefficienti(&coefficienti);
    printf("I coefficienti sono: %f %f %f\n",
           coefficienti.a, coefficienti.b, coefficienti.c);

    Triangolo t;
    t.a.x = 1;
    t.a.y = 12;
    t.b.x = 22;
    t.b.y = 34;
    t.c.x = 11;
    t.c.y = 9;

    float perimetro = distanza(t.a, t.b) +
        distanza(t.b, t.c) + distanza(t.a, t.c);
    return 0;
}






