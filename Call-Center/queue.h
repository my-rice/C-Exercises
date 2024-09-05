#ifndef QUEUE_H
#define QUEUE_H

#include "info.h"
#include "bool.h"

#define SIZE 3

/*Definizione della struttura della coda*/
struct SQueue {
   TInfo info[SIZE];
   int head;
   int tail;
};

/*Definizione del tipo nodo*/
typedef struct SQueue TQueue;

/*Inizializza la coda*/
void queue_init(TQueue *q);

/*Accoda un elemento*/
void enqueue (TQueue *q, TInfo info);

/*Elimina un elemento dalla coda*/
TInfo dequeue (TQueue *q);

/*Verifica che la coda sia vuota. Restituisce true se la coda � vuota, false altrimenti*/
bool queue_empty (TQueue q);

/*Verifica che la coda sia piena. Restituisce true se la coda � piena, false altrimenti*/
bool queue_full (TQueue q);


#endif
