/Scrivo in memoria a partire dall'indirizzo 50
/i primi N numeri di Fibonacci

	/Faccio inserire N
	INP R0, 2
	/Registro per memorizzare l'indirizzo dove scrivere in memoria
	MOV R1, #52
	/Registro per contenere l'ultimo valore calcolato prima di quello attuale
	MOV R2, #1
	/Registro per contenere il penultimo valore calcolato prima di quello attuale
	MOV R3, #0
CICLO:
	CMP R0, #0
	BEQ FINE
	ADD R4, R3, R2
	STR R4, [R1]
	SUB R0, R0, #1
	MOV R3, R2
	MOV R2, R4
	ADD R1, R1, #1
	B CICLO
FINE: 
	HALT
	
	
	
	
	
	
