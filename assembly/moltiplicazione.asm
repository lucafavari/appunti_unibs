	/Fa la moltiplicazione tra due numeri inseriti
	/dall'utente
	/Faccio inserire a
	INP R0, 2
	/Faccio inserire b
	INP R1, 2
	/Inizializzo il risultato a zero nel registro R2
	MOV R2, #0
CICLO:	
	CMP R1, #0
	BEQ FINE
	SUB R1, R1, #1
	ADD R2, R2, R0
	B CICLO
FINE:
	OUT R2, 4
	HALT
