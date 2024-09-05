#include <stdio.h>
#include <stdlib.h>
#include "gestione_clienti.h"


/*La funzione restituisce 1 se il cliente viene accodato, 0 se non c'� spazio nella
  coda di interesse. (La funzione viene gi� fornita)*/
int accoda_cliente(TQueue *tariffe, TQueue *traffico, TQueue *promozioni)
{
   TInfo info;
   int richiesta;

   info = read_info();
   do
   {
     printf ("Tipologia di informazione\n");
     printf ("1. Informazioni sui piani tariffari\n");
     printf ("2. Informazioni sul traffico telefonico\n");
     printf ("3. Informazioni sulle promozioni\n");
     scanf("%d", &richiesta);
   } while (richiesta < 1 || richiesta >3);
   if (richiesta == 1)
   {
      if (queue_full (*tariffe)== true)
         return 0;
      enqueue (tariffe, info);
      return 1;
   }

   if (richiesta == 2)
   {
      if (queue_full (*traffico)== true)
         return 0;
      enqueue (traffico, info);
      return 1;
   }

   if (richiesta == 3)
   {
      if (queue_full (*promozioni)== true)
         return 0;
      enqueue (promozioni, info);
      return 1;
   }
}


/*La funzione, verifica, per ogni coda se l'operatore � libero. Nel caso di operatore
  libero viene servito il prossimo cliente in attesa nella opportuna coda. � possibile
  servire contemporaneamente pi� clienti accodati  in code diverse. Se il cliente viene
  servito la variabile relativa all'operatore viene messa a false. La funzione restituisce
  1 se viene servito un unico cliente, 2 se ne vengono serviti due, 3 se ne vengono
  serviti tre, 0 se non viene servito alcun cliente.*/
int servi_clienti (TQueue *tariffe, TQueue *traffico, TQueue *promozioni, bool *op_tariffe_libero, bool *op_traffico_libero, bool *op_promozioni_libero)
{
    int sum = 0;
    if(*op_tariffe_libero && (!queue_empty(*tariffe))){
        TInfo cliente_tariffe = dequeue (tariffe);
        *op_tariffe_libero = false;
        sum++;
    }
    if(*op_traffico_libero && (!queue_empty(*traffico))){
        TInfo cliente_traffico = dequeue (traffico);
        *op_traffico_libero = false;
        sum++;
    }
    if(*op_promozioni_libero && (!queue_empty(*promozioni))){
        TInfo cliente_promozioni = dequeue (promozioni);
        *op_promozioni_libero = false;
        sum++;
    }
    return sum;
}


/*La funzione richiede inizialmente l'operatore da liberare, se l'operatore � occupato
  pone il valore della variabile relativa a quel operatore a true e restituisce 1,
  se l'operatore � libero restituisce 0.*/
int libera_operatore (bool *op_tariffe_libero, bool *op_traffico_libero, bool *op_promozioni_libero)
{
    int op;
    printf ("Quale operatore vuoi liberare?(1=op_tariffe,2=traffico,3=promozioni\n");
    scanf("%d",&op);
    
    if(op==1){
        if(*op_tariffe_libero == true){
            return 0;
        }else{
            *op_tariffe_libero = true;
            return 1;
        }   
    }else if(op==2){
        if(*op_traffico_libero == true){
            return 0;
        }else{
            *op_traffico_libero = true;
            return 1;
        }
    }else if(op==3){
        if(*op_promozioni_libero == true){
            return 0;
        }else{
            *op_promozioni_libero = true;
            return 1;
        }
    }else
        printf("Errore\n");
    
}


/*La funzione stampa per ogni coda il prossimo cliente da servire, se non ci sono
  clienti da servire viene stampato un opportuno messaggio di coda vuota.*/
void stampa_prossimi_clienti(TQueue tariffe, TQueue traffico, TQueue promozioni)
{
    if(queue_empty(tariffe)){
        printf("tariffe: coda vuota\n");
    }else{
        print_info(tariffe.info[tariffe.head]);
        printf("\n");
    }
    
    if(queue_empty(traffico)){
        printf("traffico: coda vuota\n");
    }else{
        print_info(traffico.info[traffico.head]);
        printf("\n");
    }
    
    if(queue_empty(promozioni)){
        printf("promozioni: coda vuota\n");
    }else{
        print_info(promozioni.info[promozioni.head]);
        printf("\n");    
    }
}




