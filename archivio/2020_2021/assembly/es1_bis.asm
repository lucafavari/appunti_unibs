/ Scrivere il programma Assembly che inizializza 
/un’area (contigua) della memoria centrale con i 
/naturali che costituiscono la tabellina del numero N, con N richiesto all'utente, in
/ modo che la prima parola dell’area da 
/inizializzare abbia indirizzo 100.

/Uso R0 per memorizzare l'indirizzo corrente
MOV R0, #100
/Uso R1 come contatore del numero di operazioni che devo fare
MOV R1, #10
/Uso R3 per memorizzare il numero N inserito dall'utente
INP R3, 2
/Uso R2 per contenere il risultato corrente
MOV R2, R3

CICLO:
CMP R1, #0
BEQ FINE
STR R2, [R0]    /Scrive nell'area di memoria richiesta
ADD R0, R0, #1 /Aggiorna l'indirizzo per la prossima istruzione
ADD R2, R2, R3 /Somma R3 in R2 per il nuovo valore della tabellina
SUB R1, R1, #1 /Decrementa il contatore
B CICLO
FINE:
HALT






