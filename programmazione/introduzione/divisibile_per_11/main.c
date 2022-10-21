#include <stdio.h>
#include <math.h>

int main() {
    int N = 122;
    int sommaPari, sommaDispari;
    do {
        int flag = 0;
        sommaPari = sommaDispari = 0;
        while (N > 0) {
            int cifra = N % 10;
            if (flag == 0) {
                sommaDispari += cifra;
                flag = 1;
            } else {
                sommaPari += cifra;
                flag = 0;
            }
            N /= 10;
        }
        N = abs(sommaDispari - sommaPari);
//        if (sommaPari - sommaDispari > 0){
//            N = sommaPari - sommaDispari;
//
//        }
//        else{
//            N = sommaDispari - sommaPari;
//        }

    }while(N > 10);
    if (N == 0){
        printf("Divisibile per 11\n");
    }
    else{
        printf("Non divisibile per 11\n");
    }
    return 0;
}
