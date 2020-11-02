#include <stdio.h>
#include <stdlib.h>

//Ritorna 1 se è bisestile, 0 altrimenti
int bisestile(int a)
{
    if (a % 400 == 0)
        return 1;
    if (a % 100 == 0)
        return 0;
    if (a % 4 == 0)
        return 1;
    return 0;
}


int giorni_anno(int a)
{
    int giorni = 0;
    for (int i = 1900; i < a; i++)
        giorni += 365 + bisestile(i);
    return giorni;
}



//Ritorna i giorni del mese m dell'anno a
int giorni_del_mese( int m, int a)
{
    if (m == 2)
        return 28 + bisestile(a);
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
        return 31;
}

//Ritorna il numero di giorni dall'inizio dell'anno
//sommando i giorni di ogni mese
int giorni_mese(int m, int a)
{
    int giorni = 0;
    for (int i = 1; i < m; i++)
        giorni += giorni_del_mese(i, a);
    return giorni;
}

int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2)
{
   // 2-11-2020
   int giorni_prima_data = g1 + giorni_mese(m1, a1) + giorni_anno(a1);
   int giorni_seconda_data = g2 + giorni_mese(m2, a2) + giorni_anno(a2);
   return giorni_prima_data - giorni_seconda_data;
}


int main()
{
    int d;
    d = differenza_date(2, 11, 2020, 27, 10, 2020);
    printf("La differenza vale %d\n", d);
    d = differenza_date(2, 11, 2020, 2, 11, 2020);
    printf("La differenza vale %d\n", d);
    //Questa si può verificare con la calcolatrice di Windows
    //il risultato è effettivamente 7188
    d = differenza_date(2, 11, 2020, 27, 2, 2001);
    printf("La differenza vale %d\n", d);
    return 0;
}
