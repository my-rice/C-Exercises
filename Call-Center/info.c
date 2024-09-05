#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "info.h"

TInfo read_info()
{
   TInfo info;

   do
   {
     printf ("Numero di telefono del cliente ");
     scanf ("%s", info.telefono);
   }
   while (strlen(info.telefono)!=MAXTEL-1);

   do
   {
     printf ("Inserisci il cognome del cliente ");
     scanf ("%s", info.cognome);
   }
   while (strlen(info.cognome)>MAXCHAR-1);

   do
   {
     printf ("Inserisci il nome del cliente ");
     scanf ("%s", info.nome);
   }
   while (strlen(info.nome)>MAXCHAR-1);

   return info;
}


void print_info(TInfo x)
{
   printf ("%11s  %21s  %21s", x.telefono, x.cognome, x.nome);
   printf("\n");
}


