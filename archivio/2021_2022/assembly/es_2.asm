	/Registro che memorizza l'indirizzo di memoria 
	/da cui partire
	MOV R0, #64
	/Registro che memorizza l'indirizzo di memoria
	/a cui fermarsi
	MOV R1, #78
	/Registro che memorizza l'indirizzo iniziale del
	/secondo intervallo
	MOV R2, #100
CICLO:
	CMP R0, R1
	BGT FINE
	LDR R3, [R0]
	STR R3, [R2]
	ADD RO, RO, #1
	ADD R2, R2, #1
	B CICLO
FINE:
	HALT
