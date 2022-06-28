#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#define OCUPADO 1

int sonLetras(char cadena[])
{
    int todoOk= -1;
    int longitud = strlen(cadena);

      for(int i= 0; i < longitud; i++)
      {
          if((cadena[i] > 64 && cadena[i] < 91) || (cadena[i] > 96 && cadena[i] < 123))
          {
              todoOk= 1;
          }// fin del if

      }// fin del for

// devuelve 1 si son letras, devuelve -1 si son numeros

return todoOk;
}// fin de la funcion sonLetras

int menu ()
{
    int opcion;

    printf(" 1.Alta de un pasajero\n");
    printf(" 2.Modificacion de un pasajero\n");
    printf(" 3.Baja de un pasajero\n");
    printf(" 4.Informar sobre los pasajeros \n");
    printf(" 5.Alta harcodeo\n");
    printf(" 6.Salir del menu\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

return opcion;
}// fin del menu

int menuModificaciones()
{
    int opcion;

    printf(" 1.Modificar nombre\n");
    printf(" 2.Modificar apellido\n");
    printf(" 3.Modificar precio\n");
    printf(" 4.Modificar flycode \n");
    printf(" 5.Modificar type pasajero\n");
    printf(" 6.Modificar status flight\n");
    printf(" 7.Salir\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

return opcion;
}
