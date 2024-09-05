#include <stdio.h>
#include "menu.h"

int menu()
{
    int scelta,i;
    
    printf("-------------------------------------------------\n");
    printf("PROGRAMMA PER LA GESTIONE DI CALL CENTER\n\n");
    printf("1. Accoda un cliente \n");
    printf("2. Servi clienti\n");
    printf("3. Libera un operatore\n");
    printf("4. Stampa i prossimi clienti in attesa per ogni coda\n");
    printf("0. EXIT\n\n");
    printf("-------------------------------------------------\n");
    printf("Selezionare la scelta [0-4]: ");
    scanf("%d", &scelta);
    while((scelta<0)||(scelta>4)){
       printf("ERRORE! valore non consentito\n");                        
       printf("Selezionare la scelta [0-4]: ");
       scanf("%d", &scelta);
    }
    fflush(stdin);
    return scelta;

   pause();
}

void clear_screen()
{
//   system("CLS");
}

void pause()
{
//   system("pause");
}
