/Scrivere il programma Assembly che legge due 
/numeri da input, ne fa il prodotto e lo stampa in
/output. Inoltre deve essere 'ottimizzato' per 
/usare il minore dei due come contatore dei cicli

/Leggo il primo numero in input
INP R0, 2
/Leggo il secondo numero in input
INP R1, 2
/Faccio un confronto per assicurarmi che il più
/piccolo si trovi in R1
CMP R0, R1
BGT MOLTIPLICA
BEQ MOLTIPLICA
/NO!!!!!
/MOV R0, R1
/MOV R1, R0
MOV R3, R0 /R3 funge da registro di appoggio
MOV R0, R1
MOV R1, R3
MOLTIPLICA:
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






