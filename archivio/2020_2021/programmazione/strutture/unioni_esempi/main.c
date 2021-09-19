#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    float b;
    double c;
} Struttura;

typedef union{
    int a;
    float b;
    double c;
} Unione;

typedef union{
    struct{
        unsigned char byte4;
        unsigned char byte3;
        unsigned char byte2;
        unsigned char byte1;
    }bytes;
    unsigned char vbytes[4];
    unsigned int dword;
}HW_register;

int main()
{
    printf("Dimensione della struttura %d\n", sizeof(Struttura));
    printf("Dimensione dell'unione %d\n", sizeof(Unione));
    Unione u;
    Struttura s;
    s.a = 10;
    s.b = 1.3;
    s.c = 4.5;
    printf("Struttura a: %d, b: %f, c: %f\n", s.a, s.b, s.c);
    u.a = 10;
    u.b = 1.3;
    u.c = 4.465846583649856325;
    printf("Unione a: %d, b: %f, c: %f\n", u.a, u.b, u.c);
    HW_register reg;
    reg.dword = 0xff32567d;
    printf("Nel registro ho inserito il valore %x\n", reg.dword);
    reg.bytes.byte1 = 0x11;
    printf("Nel registro ho inserito il valore %x\n", reg.dword);
    reg.vbytes[0] = 0x22;
    printf("Nel registro ho inserito il valore %x\n", reg.dword);
    reg.dword = 0;
    printf("Nel registro ho inserito il valore %x\n", reg.dword);
    return 0;
}
