#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    char s1[30];
    //scanf("%s",s1);
    fgets(s1, 29, stdin);
    puts(s1);

    printf("%s\n", s1);

    return 0;
}
