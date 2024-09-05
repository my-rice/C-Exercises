#ifndef INFO_H
#define INFO_H

#define MAXTEL 11
#define MAXCHAR 21


/*Definzione della struttura per l'informazione*/
struct SInfo {
  char telefono [MAXTEL]; //Codice Fiscale del Paziente
  char cognome[MAXCHAR];     //Cognome del Paziente
  char nome[MAXCHAR];        //Nome del Paziente
};

/*Definizione del tipo per l'informazione*/
typedef struct SInfo TInfo;

/*Legge da tastiera i dati dell'info. Restituisce l'info letta*/
TInfo read_info();


/*Stampa l'informazione*/
void print_info(TInfo x);

#endif
