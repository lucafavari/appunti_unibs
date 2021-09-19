/Carico l'indirizzo di partenza nel registro R0
MOV R0, #100
/Carico l'indirizzo di arrivo nel registro R1
MOV R1, #150
/Carico il valore ASCII del punto nel registro R2
MOV R2, #46
/Carico il valore ASCI della linea nel registro R3
MOV R3, #45
/Carico il valore ASCII dello spazio nel registro R4
MOV R4, #32

/Inizio del ciclo di lettura
CICLO:
CMP R0, R1
BGT FINE
/Carico il valore nella posizione attuale della memoria all'interno di R5
    LDR R5, [R0]
/Incremento il valore dell'indirizzo di lettura per preparare il prossimo ciclo    
    ADD R0, R0, #1
/Verifico se il valore letto è uno 0, se sì stampo un punto, altrimenti vado avanti    
    CMP R5, #0
    BNE LINEA
    OUT R2, 7
/Riparto dall'inizio del ciclo
    B CICLO
LINEA:
    CMP R5, #1
    BNE SPAZIO
    OUT R3, 7
    B CICLO
SPAZIO:
    OUT R4, 7
    B CICLO
FINE:
HALT