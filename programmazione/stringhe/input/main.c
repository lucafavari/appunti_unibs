#include <stdio.h>

int main() {
    char s1[20], s2[20];
    int n;
    printf("Inserisci una parola: ");
    //scanf("%s", s1);
    scanf("%d", &n);

    fgets(s2, 20, stdin);
    printf("%d %s", n, s2);
    return 0;
}
