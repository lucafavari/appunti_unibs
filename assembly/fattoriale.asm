/A*B

/((N*(N-1))*(N-2))*(N-3)

/Registro per contenere N
INP R0, 2
/Registro che rappresenta A nella moltiplicazione elementare
MOV R1, #1
/Registro che rappresenta B nella moltiplicazione elementare
MOV R2, R0
CICLO:
	CMP R2, #0
	BEQ FINE
	/Singola mol
	tiplicazione
	MOV R3, #0
	MOV R4, R2
	CICLO_MOLTIPLICATIVO:
		CMP R4, #0
		BEQ AGGIORNA
		ADD R3, R3, R1
		SUB R4, R4, #1
		B CICLO_MOLTIPLICATIVO
	AGGIORNA:
	MOV R1, R3
	SUB R2, R2, #1
	B CICLO
FINE: 
	OUT R1, 4
	HALT
	
	
	
