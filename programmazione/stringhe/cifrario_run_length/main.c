#include <stdio.h>
#include <stdlib.h>

//Funzione che fa la codifica RLE
void rle(char *originale, char *compressa)
{
    int corrente = 0;
    int contatore = 1;
    int i;
    for (i = 1; originale[i] != '\0'; i++)
    {
        if (originale[i - 1] == originale[i])
            contatore++;
        if (originale[i - 1] != originale[i])
        {
            if (contatore == 1){
                compressa[corrente] = originale[i - 1];
                corrente++;
            }
            else
            {
                compressa[corrente] = contatore + '0';
                compressa[corrente + 1] = originale[i - 1];
                corrente+=2;
            }
            contatore = 1;
        }
        if (contatore == 9)
        {
            compressa[corrente] = '9';
            compressa[corrente + 1] = originale[i - 1];
            corrente += 2;
            contatore = 1;
        }
    }
    if (contatore == 1)
        {
            compressa[corrente] = originale[i - 1];
            corrente++;
        }
    else
        {
            compressa[corrente] = contatore + '0';
            compressa[corrente + 1] = originale[i - 1];
            corrente+=2;
        }
    compressa[corrente] = '\0';
}

void rle_inversa(char *compressa, char *originale)
{
    int corrente = 0;
    for (int i = 0; compressa[i] != '\0'; i++)
    {
        if (compressa[i] >= 'a' && compressa[i] <= 'z')
        {
            originale[corrente] = compressa[i];
            corrente++;
        }
        else
        {
            for (int j = 0; j < compressa[i] - '0'; j++)
                originale[corrente + j] = compressa[i + 1];
            corrente += (compressa[i] - '0');
            i++;
        }
    }
    originale[corrente] = '\0';
}

#define N 100

int main()
{
    char originale[] = "ddddabdddfgtddddoooodddd";
    char compressa[N], decompressa[N];
    rle(originale, compressa);
    printf("La stringa compressa diventa: %s\n", compressa);
    rle_inversa(compressa, decompressa);
    printf("La stringa orginale dopo la decompressione ritorna: %s", decompressa);
    return 0;
}
