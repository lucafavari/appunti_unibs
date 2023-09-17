#include <stdio.h>

int main() {
    //Selezione a una via (if)
    int a = 20;
    if (a > 5 && a < 15){
        printf("a è compresa tra 5 e 15, estremi esclusi\n");
    }
    //Selezione a due vie (if - else)
    if (a > 10){
        printf("a è maggiore di 10");
    }
    else{
        printf("a è minore o uguale a 10");
    }
    //Selezione a più vie
    if (a < 0){
        printf("a è minore di 0\n");
    }
    else if (a >= 0 && a < 10){
        printf("a è compreso tra 0 e 10\n");
    }
    else{
        printf("a è maggiore o uguale a 10");
    }
    return 0;
}
