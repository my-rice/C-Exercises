#ifndef GESTIONE_CLIENTI_H
#define GESTIONE_CLIENTI_H

#include <stdio.h>
#include "bool.h"
#include "queue.h"

/*La funzione restituisce 1 se il cliente viene accodato, 0 se non c'� spazio nella
  coda di interesse. (La funzione viene gi� fornita)*/
int accoda_cliente(TQueue *tariffe, TQueue *traffico, TQueue *promozioni);


/*La funzione, verifica, per ogni coda se l'operatore � libero. Nel caso di operatore
  libero viene servito il prossimo cliente in attesa nella opportuna coda. � possibile
  servire contemporaneamente pi� clienti accodati  in code diverse. Se il cliente viene
  servito la variabile relativa all'operatore viene messa a false. La funzione restituisce
  1 se viene servito un unico cliente, 2 se ne vengono serviti due, 3 se ne vengono
  serviti tre, 0 se non viene servito alcun cliente.*/
int servi_clienti (TQueue *tariffe, TQueue *traffico, TQueue *promozioni, bool *op_tariffe_libero, bool *op_traffico_libero, bool *op_promozioni_libero);


/*La funzione richiede inizialmente l'operatore da liberare, se l'operatore � occupato
  pone il valore della variabile relativa a quel operatore a true e restituisce 1,
  se l'operatore � libero restituisce 0.*/
int libera_operatore (bool *op_tariffe_libero, bool *op_traffico_libero, bool *op_promozioni_libero);


/*La funzione stampa per ogni coda il prossimo cliente da servire, se non ci sono
  clienti da servire viene stampato un opportuno messaggio di coda vuota.*/
void stampa_prossimi_clienti(TQueue tariffe, TQueue traffico, TQueue promozioni);


#endif
