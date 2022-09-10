	/FAccio inserire la base
	INP R0, 2
	/Faccio inserire l'altezza
	INP R1, 2
	/Calcolo il perimetro e lo inserisco
	/nel registro R2
	MOV R2, #0 /inizializza a zero R2
	ADD R2, R0, R0
	ADD R3, R1, R1
	ADD R4, R2, R3
	OUT R4, 7
	HALT
