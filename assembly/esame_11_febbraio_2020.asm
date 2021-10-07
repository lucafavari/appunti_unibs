/Esercizio del tema d'esame
/Registro che contiene l'indirizzo di partenza
MOV R0, #100
/Registro che contiene l'indirizzo finale
MOV R1, #150
/Registri che contengono i valori da stampare
MOV R3, #0
MOV R4, #1
MOV R5, #2
CICLO:
	CMP R0, R1
	BGT FINE
	LDR R2, [R0]
	CMP R2, #50
	BLT ZERO
	CMP R2, #100
	BGT DUE
	OUT R4, 4
	B PREPARA
ZERO:
	OUT R3, 4
	B PREPARA
DUE:
	OUT R5, 4
PREPARA:	
	ADD R0, R0, #1
	B CICLO
FINE:
	HALT
