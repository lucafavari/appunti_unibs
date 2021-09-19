/ Scrivere il programma Assembly che verifica se 
/il numero naturale che si trova nella cella di 
/memoria 100 è divisibile esattamente per il 
/numero che si trova nella cella 101: se è 
/divisibile deve scrivere il valore 1 nella cella 
/di memoria 102, altrimenti il valore 2.

/ Leggo la cella di memoria 100 e la inserisco in R0
/ Dividendo
LDR R0, 100
/ Leggo la cella di memoria 101 e la inserisco in R1
/ Divisore
LDR R1, 101
CICLO:
CMP R0, R1
BLT USCITA_CICLO
SUB R0, R0, R1 / R0 = R0 - R1
B CICLO
USCITA_CICLO:
CMP R0, #0
BNE NON_DIVISIBILE
MOV R2, #1
B FINE
NON_DIVISIBILE:
MOV R2, #2
FINE:
STR R2, 102
HALT