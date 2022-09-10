#include <iostream>

void secondo_grado(double a, double b, double c,
                   double *x1, double *x2)
{

}

int main() {
    double a = 1, b = 7, c = 2;
    double x1, x2;
    secondo_grado(a, b, c, &x1, &x2);
    printf("Le due soluzioni sono: %lf %lf",
           x1, x2);
    return 0;
}
