#include <stdio.h>

void elimina_caratteri(char originale[], char filtrato[], int n)
{
    int k = 0;
    for (int i = 0; originale[i] != '\0'; ++i) {
        int trovato = 0;
        for (int j = 0; j < k; j++)
        {
            if (filtrato[j] == originale[i])
                trovato = 1;
        }
        if (!trovato) // if (trovato == 0)
        {
            filtrato[k] = originale[i];
            k++;
        }
        if (k == n)
        {
            filtrato[k] = '\0';
            return;
        }
    }
    filtrato[k] = '\0';
}

int main() {
    char s[] = "Questo corso insegna a programmare";
    char t[200];
    elimina_caratteri(s, t, 100);
    printf("%s\n", t);
    return 0;
}
