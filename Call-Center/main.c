#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "queue.h"
#include "menu.h"
#include "gestione_clienti.h"

int main()
{
    int scelta,accoda,libera;
    TQueue tariffe, traffico, promozioni;
    queue_init(&tariffe);
    queue_init(&traffico);
    queue_init(&promozioni);
    
    bool op_tariffe_libero;
    bool op_traffico_libero;
    bool op_promozioni_libero;
    op_tariffe_libero = true;
    op_traffico_libero = true;
    op_promozioni_libero = true;
    
    /* Scelta della funzione per gestire l'archivio */
    
     scelta= 1;
     
      while(scelta=menu()){
        switch(scelta){
            case 1:
                accoda = accoda_cliente(&tariffe, &traffico, &promozioni);
                if(accoda==1)
                    printf("cliente accodato correttamente\n");
                else
                    printf("coda piena\n");

                break;
            case 2:
                printf("N Clienti soddisfatti: %d\n",servi_clienti (&tariffe, &traffico, &promozioni, &op_tariffe_libero, &op_traffico_libero, &op_promozioni_libero));

                break;
            case 3:
                libera = libera_operatore (&op_tariffe_libero, &op_traffico_libero, &op_promozioni_libero);
                if(libera==1)
                    printf("operatore liberato correttamente\n");
                else
                    printf("operatore occupato\n");
                break;
            case 4:
                stampa_prossimi_clienti(tariffe, traffico, promozioni);
                break;
        }
    }
}   
