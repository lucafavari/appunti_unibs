	/Registro che contiene il valore attuale della
	/tabellina
	MOV R0, #5
	/Registro che contiene l'indirizzo da cui partire
	MOV R1, #100
	/Registro contatore dei cicli
	MOV R2, #0
CICLO:
	CMP R2, #10
	BEQ FINE
	STR R0, [R1]
	ADD R0, R0, #5
	ADD R1, R1, #1
	ADD R2, R2, #1
	B CICLO
FINE:
	HALT
