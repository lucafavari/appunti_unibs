/Scrivere il programma Assembly che legge due 
/numeri da input, ne fa il prodotto e lo stampa in
/output.

/Leggo il primo numero in input
INP R0, 2
/Leggo il secondo numero in input
INP R1, 2
/Uso R2 per salvare il risultato della moltiplicazione
MOV R2, #0
CICLO:
CMP R1, #0
BEQ FINE
ADD R2, R2, R0
SUB R1, R1, #1
B CICLO
FINE:
OUT R2, 4
HALT






