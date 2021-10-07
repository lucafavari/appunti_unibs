	/Leggo il valore di A dalla memoria
	LDR R0, 100
	/Leggo il valore di B dalla memoria
	LDR R1, 101
	/Metto i valori costanti 1 e 2 dentro R2 e R3
	MOV R2, #1
	MOV R3, #2
CICLO:
	CMP R0, R1
	BLT FINE
	SUB R0, R0, R1
	B CICLO
FINE:
	CMP R0, #0
	BEQ UNO
	STR R3, 102
	B DUE
UNO:
	STR R2, 102
DUE:	
	HALT
	
	
	
	
	
	
	
	
