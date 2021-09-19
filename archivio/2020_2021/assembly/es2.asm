/ Scrivere il programma Assembly che copia l’area 
/di memoria la cui prima parola ha indirizzo 64 e 
/la cui ultima parola ha indirizzo 78 nell’area 
/di memoria la cui prima parola ha indirizzo 100.

/Memorizzo in R0 l'indirizzo di partenza della sorgente
MOV R0, #64
/Memorizzo in R1 l'indirizzo di arrivo della sorgente
MOV R1, #78
/Memorizzo in R2 l'indirizzo di partenza della destinazione
MOV R2, #100
CICLO:
CMP R0, R1
BGT FINE
LDR R4, [R0] /Legge la sorgente in R4
STR R4, [R2] /Copia il valore di R4 nella destinazione
ADD R0, R0, #1
ADD R2, R2, #1
B CICLO
FINE:
HALT













