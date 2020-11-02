#include <stdio.h>
#include <stdlib.h>



double delta(double a, double b, double c)
{
    return b*b - 4*a*c;
}

void secondo_grado(double a, double b, double c, //input
                   double *x1, double *x2)//output
{
    *x1 = (-b + sqrt(delta(a,b,c)))/(2*a);
    *x2 = (-b - sqrt(delta(a,b,c)))/(2*a);
}

int main()
{
    double a = 2, b = 7, c = -3;
    double x1, x2;
    if (delta(a,b,c) >= 0){
        secondo_grado(a, b, c, &x1, &x2);
        printf("Le soluzioni sono %f e %f\n", x1, x2);
    }
    else
        printf("L'equazione non ha soluzione nei reali.\n");
    return 0;
}
