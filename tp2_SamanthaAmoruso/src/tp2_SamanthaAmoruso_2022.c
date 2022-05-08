/*
 ============================================================================
 Name        : tp2_SamanthaAmoruso_2022.c
 Author      : Sami
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define T 2000
#define TAMS 3
#include "ArrayPassenger.h"

int main()
{
	setbuf(stdout,NULL);
	fflush(stdin);

	char seguir;
	ePasajero listaDePasajeros[T];
	ePasajero auxiliar;
	eStatus status[TAMS] =
	{
	        {1, "Activo"},
	        {2, "Demorado"},
	        {3, "Cancelado"}
	};

	int identificador = 1;
	int bandera1 = 0;
	int banderaHarcodeo=0;
	int opcion;
	int devolucionDeInicializarPasajeros;
	int pId=1;

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
				if(banderaHarcodeo==0)
				{
				addPassenger(listaDePasajeros, T, &identificador, auxiliar.nombre, auxiliar.apellido,
						    auxiliar.price, auxiliar.flycode, auxiliar.typePassenger, auxiliar.statusFlight);

				bandera1=1;
				}
				else
				{
					printf("no puede ingresar pasajeros porque los acabas de harcodear\n");
				}
			break;

			case 2:
				if (bandera1==0 && banderaHarcodeo==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					modificarPasajero(listaDePasajeros, T, status, TAMS);
				}
			break;

			case 3:
				if (bandera1==0 && banderaHarcodeo==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					removePassenger(listaDePasajeros , T, status, TAMS);
				}
			break;

			case 4:
				if (bandera1==0 && banderaHarcodeo==0)
				{
					printf("\n error,no ingresaste Pasajeros\n\n");
				}
				else
				{
					printf("1) Listado de pasajeros ordenados alfabeticamente por apellido ascendente y tipo de pasajero\n");
					printf("2) Listado de pasajeros ordenados alfabeticamente por apellido descendente y tipo de pasajero\n");
					printf("3) Para obtener un informe sobre los Precios\n");
					printf("4) Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVOS' de forma ascendente\n");
					printf("5) Listado de los pasajeros por codigo de vuelo y estados de vuelo activos de forma descendente \n");
					scanf("%d", &opcion);
					switch(opcion)
					{
						case 1:
							printf("muestra los pasajeros sin ordenar\n");
							printPassengers(listaDePasajeros, T, status, TAMS);
							sortPassengers(listaDePasajeros, T, 1);
							printf("muestra los pasajeros ordenados de forma ascendente\n");
							printPassengers(listaDePasajeros, T, status, TAMS);
						break;

						case 2:
							printf("muestra los pasajeros sin ordenar\n");
							printPassengers(listaDePasajeros, T, status, TAMS);
							sortPassengers(listaDePasajeros, T, 0);
							printf("muestra los pasajeros ordenados de forma descendente\n");
							printPassengers(listaDePasajeros, T, status, TAMS);
						break;

						case 3:
							mostrarPrecios(listaDePasajeros,T);
							superanPrecioPromedio(listaDePasajeros, T,sumarPreciosYPromediar(listaDePasajeros, T) );
						break;

						case 4:
							printf("muestra los pasajeros ordenados de forma Ascendente\n");
							sortPassengersByCode(listaDePasajeros, T, status, TAMS, 1);
						break;

						case 5:
							printf("muestra los pasajeros ordenados de forma Descendente\n");
							sortPassengersByCode(listaDePasajeros, T, status, TAMS, 0);
						break;

						default:
							printf("opcion equivocada, elija una opcion del 1 al 5: \n");
						break;
					}//fin swtich

				}//fin else
		    break;

			case 5:
				if(bandera1==0)
				{
					harcodearPasajeros(listaDePasajeros,T , 10, &pId);
					printf("usted ha harcodeado correctamente\n");
					banderaHarcodeo=1;
				}
				else
				{
					printf("No se pueden harcodear pasajeros porque ya los ingreso manualmente\n");
				}
			break;

			case 6:
				if (bandera1 == 0 || banderaHarcodeo==0)
				{
					printf("¿seguro que desea salir? ya que usted no ingreso Pasajeros o no los harcodeo\n");
				}
				printf("Si desea seguir escribe S sino N: \n");
				fflush(stdin);
				scanf("%c", &seguir);
		    break;

			default:
				printf("opcion equivocada, elija una opcion del 1 al 6: \n");
			break;
		}//fin de switch

	}while (seguir!='n');//fin del while

return 0;
}//fin del main
