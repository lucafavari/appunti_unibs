	/Tema d'esame
	/Registro che contiene N
	INP R0, 2
	/Registro che contiene K
	INP R1, 2
	/Registro che contiene la somma
	MOV R2, #0
	/Registro che contiene il valore del multiplo corrente
	MOV R3, R1
CICLO:
	CMP R0, #0
	BEQ FINE
	/Ciclo interno per il controllo dell'unità
	/Registro temporaneo per evitare di perdere
	/il valore contenuto in R3
	MOV R4, R3
	CICLO_INTERNO:
		CMP R4, #4
		BEQ SOMMA
		BLT PROCEDI 
		SUB R4, R4, #10
		B CICLO_INTERNO
	/Sommo il multiplo corrente
	SOMMA:
	ADD R2, R2, R3
	/Preparo il prossimo multiplo di K
	PROCEDI:
	ADD R3, R3, R1
	SUB R0, R0, #1
	B CICLO
FINE:
	OUT R2, 4
	HALT
	
	
	
	
	
	
	
	
	
	
