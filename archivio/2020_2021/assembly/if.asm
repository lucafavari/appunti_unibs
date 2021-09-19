/Esempio dell'if
/R1 contiene il valore della cella di memoria 100
LDR R1, 100
/R2 contiene il valore della cella di memoria 101
LDR R2, 101
CMP R1, R2
BGT salto
HALT
salto:
SUB R3, R1, R2
STR R3, 103
HALT
