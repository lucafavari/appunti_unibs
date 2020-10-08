/Scrivere il programma Assembly che prende ogni 
/intero nell’area di memoria la cui prima parola 
/ha indirizzo 64 e la cui ultima parola ha 
/indirizzo 88 e ne copia il valore a partire 
/dall'area che inizia all'indirizzo 100. Il valore
/ copiato deve essere diminuito di una quantità 
/pari alla posizione del numero da copiare, cioè 
/il primo numero copiato sarà diminuito di 1, il 
/secondo di 2, ecc.

/Questa volta il controllo viene fatto in coda

/Indirizzo di partenza
MOV R0, #64
/Indirizzo di arrivo
MOV R1, #88
/Indirizzo di destinazione
MOV R2, #100
/Valore da sottrarre
MOV R3, #1
CICLO:

LDR R4, [R0]
SUB R4, R4, R3
STR R4, [R2]
ADD R0, R0, #1
ADD R2, R2, #1
ADD R3, R3, #1

CMP R0, R1
BLT CICLO
BEQ CICLO
HALT
















