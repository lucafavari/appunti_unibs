	/Registro che contiene il valore n1 letto in input
	INP R0, 2
	/Registro che contiene il valore n2 letto in input
	INP R1, 2
	/Registro che contiene l'indirizzo iniziale della memoria
	MOV R2, #20
	/Controlliamo che R0 > R1, altrimenti li scambiamo
	CMP R0, R1
	BGT SCAMBIA
	B CICLO
SCAMBIA:
	MOV R3, R0
	MOV R0, R1
	MOV R1, R3
CICLO:
	CMP R0, R1
	BGT FINE
	STR R0, [R2]
	ADD R0, R0, #1
	ADD R2, R2, #1
	B CICLO
FINE:
	HALT







