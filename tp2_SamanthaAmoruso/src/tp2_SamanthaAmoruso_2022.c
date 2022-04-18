/*
 ============================================================================
 Name        : tp2_SamanthaAmoruso_2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define T 200
#include "ArrayPassenger.h"

int main(void)
{
	setbuf(stdout,NULL);
	fflush(stdin);

	char seguir = 's';
	ePasajero listaDePasajeros[T];
	ePasajero auxiliar;
	int identificador = 1;
	int bandera1 = 0;
	int opcion;
	int devolucionDeInicializarPasajeros;

	devolucionDeInicializarPasajeros = inicializarPasajeros(listaDePasajeros, T);
	if(devolucionDeInicializarPasajeros == 1)
	{
		printf("-----------------------------------------\n");
		printf("- - Sistema inicializado exitosamente - -\n");
		printf("-----------------------------------------\n");
	}// fin del if
	else
	{
		printf("-----------------------------------------\n");
		printf("- - El sistema no pudo inicializarse - - \n");
		printf("-----------------------------------------\n");
	}// fin del else

	do{

		switch(menu())
		{
			case 1:
				addPassenger(listaDePasajeros, T, &identificador, auxiliar.nombre, auxiliar.apellido,
						    auxiliar.price , auxiliar.flycode, auxiliar.typePassenger);
				bandera1=1;
			break;

			case 2:
				if (bandera1==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					modificarPasajero(listaDePasajeros, T);
				}
			break;

			case 3:
				if (bandera1==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					removePassenger(listaDePasajeros , T);
				}
			break;

			case 4:
				if (bandera1==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					printf("1) listado de pasajeros ordenados alfabeticamente por apellido ascendente y tipo de pasajero\n");
					printf("2) listado de pasajeros ordenados alfabeticamente por apellido descendente y tipo de pasajero\n");
					printf("3) para obtener un informe sobre los Precios\n");
					printf("4) Para obtener un listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVOS' ");
					scanf("%d", &opcion);
					switch(opcion)
					{
						case 1:
							printf("muestra los pasajeros sin ordenar\n");
							printPassengers(listaDePasajeros, T);
							sortPassengers(listaDePasajeros, T, 1);
							printf("muestra los pasajeros ordenados de forma ascendente\n");
							printPassengers(listaDePasajeros, T);
						break;

						case 2:
							printf("muestra los pasajeros sin ordenar\n");
							printPassengers(listaDePasajeros, T);
							sortPassengers(listaDePasajeros, T, 0);
							printf("muestra los pasajeros ordenados de forma descendente\n");
							printPassengers(listaDePasajeros, T);
						break;

						case 3:
							mostrarPrecios(listaDePasajeros,T);
							superanPrecioPromedio(listaDePasajeros, T,sumarPreciosYPromediar(listaDePasajeros, T) );
						break;

						case 4:

						break;

						default:
							printf("opcion equivocada, elija una opcion del 1 al 4: \n");
						break;
					}//fin swtich

				}//fin else
		    break;

			case 5:
				if (bandera1 == 0)
				{
					printf("¿seguro que desea salir? ya que usted no ingreso Pasajeros\n");
				}
				printf("si desea seguir escribe S sino N: \n");
				fflush(stdin);
				scanf("%c", &seguir);
		    break;

			default:
				printf("opcion equivocada, elija una opcion del 1 al 5: \n");
			break;
		}//fin de switch

	}while (seguir=='s');//fin del while

return 0;
}//fin del main
