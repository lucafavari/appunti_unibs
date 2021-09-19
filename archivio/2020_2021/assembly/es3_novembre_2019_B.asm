/Il registro R0 viene usato per memorizzare il numero N
INP R0, 2
/Inizializzo il registro R1 che conterrà il massimo
MOV R1, #0
/Leggo nel registro R2 il primo valore della sequenza
/R2 poi verrà usato per memorizzare il precedente
INP R2, 2
/Decremento il contatore poichè una lettura è già stata fatta
SUB R0, R0, #1

CICLO:
CMP R0, #0
BEQ FINE
/Leggiamo il numero attuale e lo memorizziamo in R3
INP R3, 2
/Preparo il contatore R0 per il giro successivo
SUB R0, R0, #1
/Calcolo la distanza e la memorizzo in R4
SUB R4, R3, R2
/Aggiorno R2 per il prossimo giro
MOV R2, R3
/Confronto la differenza con il massimo corrente
CMP R4, R1
BGT MASSIMO
B CICLO
MASSIMO:
/Sostuisco il vecchio massimo con quello appena trovato
MOV R1, R4
B CICLO
FINE:
HALT








