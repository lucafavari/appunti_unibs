#include <stdio.h>
#include <string.h>

/**
 * Verifica se è presente una sola chiocciola
 * @param mail la stringa da verificare
 * @return la posizione della chiocciola se ce n'è una sola
 * altrimenti -1 se non ce n'è nessuna o sono troppe
 */
int chiocciola(char mail[]){
    int conta = 0;
    int pos = 0;
    for (int i = 0; mail[i] != '\0'; ++i) {
        if (mail[i] == '@'){
            conta++;
            pos = i;
        }
    }
    if (conta == 1){
        return pos;
    }
    return -1;
}

int lettera(char c){
    if ((c >= 'A' && c <= 'Z') || (c >='a' && c <= 'z'))
        return 1;
    return 0;
}

/**
 * Cerca il punto nella stringa e ritorna la posizione o -1
 * @param s Stringa in cui cercare
 * @return La posizione se è presente un solo punto, altrimenti -1
 */
int punto(char s[]){
    int pos = 0, conta = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == '.'){
            pos = i;
            conta++;
        }
    }
    if (conta == 1){
        return pos;
    }
    return -1;
}

int indirizzo_valido(char mail[]){
    //Regola 1
    if (chiocciola(mail) == -1)
        return 0;
    //Regola 2
    int posizione_chiocciola = chiocciola(mail);
    //La prima parte non contiene niente
    if (posizione_chiocciola == 0)
        return 0;
    if (!lettera(mail[0]))
        return 0;
    if (punto(&mail[posizione_chiocciola]) == -1)
        return 0;
    int posizione_punto = punto(&mail[posizione_chiocciola]);
    //Se il punto è subito dopo la @ non va bene
    if (posizione_punto == 1)
        return 0;
    //Se il punto è in ultima posizione non va bene
    if (posizione_punto == strlen(&mail[posizione_chiocciola]) - 1)
        return 0;
    //Da completare
    return 1;


}


int main() {

    return 0;
}
