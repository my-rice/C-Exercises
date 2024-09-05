#include <stdlib.h>
#include <malloc.h>

#include "info.h"
#include "queue.h"


void queue_init(TQueue *q)
{

   q->head = 0;
   q->tail = 0;

}


TInfo dequeue (TQueue *q)
{
   TInfo info;

   info = q->info[q->head];
   q->head = (q->head+1)%SIZE;

   return info;
}

bool queue_empty (TQueue q)
{
   if (q.head == q.tail)
      return true;
   else
      return false;
}


/*Inserire qui le funzioni richieste*/
void enqueue (TQueue *q, TInfo info)
{
    if(queue_full(*q)){
        return;
    }
    q->tail = (q->tail+1)%SIZE;
    q->info[q->tail] = info;
}

bool queue_full (TQueue q)
{
    if ((q.tail+1)%SIZE ==q.head)
      return true;
    else
      return false;
}
