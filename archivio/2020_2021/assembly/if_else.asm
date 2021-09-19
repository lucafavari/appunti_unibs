/Scrivere il programma Assembly che confronta il 
/valore di due numeri naturali che si trovano rispettivamente nelle aree di memoria 100 e 101: se il primo è maggiore del secondo scrive la differenza nell'area di memoria 103, altrimenti scrive la differenza fra il secondo e il primo nell'area di memoria 104.

/R1 contiene il valore della cella di memoria 100
LDR R1, 100
/R2 contiene il valore della cella di memoria 101
LDR R2, 101

CMP R1, R2
BGT salto
SUB R3, R2, R1
STR R3, 104
B fine
salto:
SUB R3, R1, R2
STR R3, 103
fine:
HALT







