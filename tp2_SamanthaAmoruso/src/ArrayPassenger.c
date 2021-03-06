/*
 * ArrayPassenger.c
 *
 *  Created on: 17 abr. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VACIO 0
#define OCUPADO 1
#include "ArrayPassenger.h"
#include "status.h"
#include "Funciones.h"

int inicializarPasajeros(ePasajero* listaDePasajeros, int tam)
{
   int retorno = 0;
   if(listaDePasajeros != NULL && tam > 0)
   {
	   for(int i= 0; i < tam; i++)
	   {
		   listaDePasajeros[i].isEmpty = VACIO;
	   }// fin del for
	   retorno = 1;

   }// fin del if

   return retorno;
}// fin de inicializar pasajeros

int buscarLibre(ePasajero* listaDePasajeros, int tam)
{
	int lugarLibre =-1;
	if(listaDePasajeros != NULL && tam > 0)
	{
		for(int i=0; i < tam; i++)
		{
			if(listaDePasajeros[i].isEmpty == VACIO)
			{
				lugarLibre = i;
				break;
			}// fin del if

		}// fin del for

	}// fin del if

return lugarLibre;
}// fin de buscar libre

int buscarPasajero(ePasajero* listaDePasajeros, int tam, int identificador)
{
	int indice = -1;
	if (listaDePasajeros != NULL && tam > 0)
	{
	   for (int i=0; i< tam; i++)
	   {
		   if (listaDePasajeros[i].id && listaDePasajeros[i].isEmpty)
		   {
			   indice = i;
			   break;
		   }// fin del if

	   }// fin del for

	}// fin del if
 return indice;
} // fin de buscaPasajero

void printPassenger(ePasajero unPasajero, int tam, eStatus status[], int tams)
{
	char auxiliarChar[15];
	char auxiliarCharDos[15];

	mostrarTipoPasajero(unPasajero.typePassenger , auxiliarChar);
    //mostrarStatusVuelo(listaDePasajeros[i].statusFlight,auxiliarCharDos);
	cargarDescripcionStatus(status, tams,unPasajero.statusFlight, auxiliarCharDos);

	printf("%2d %8s %10s %10.2f %10s %7d %s %5d %s\n ", unPasajero.id,
			unPasajero.nombre,
			unPasajero.apellido,
		    unPasajero.price,
			unPasajero.flycode,
			unPasajero.typePassenger,
		    auxiliarChar,
			unPasajero.statusFlight,
	        auxiliarCharDos);
}

int printPassengers(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams)
{
	int retorno = -1;

	if(listaDePasajeros != NULL && tam > 0 && status !=NULL && tams > 0)
	{
		 printf("-------------------------- LISTA DE PASAJEROS ---------------------------------\n");
	     printf("ID   Nombre    Apellido    Precio    flycode    typePassenger  statusVuelo \n");
	     printf("-------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++)
		 {
			if(listaDePasajeros[i].isEmpty == OCUPADO)
			{
				printPassenger(listaDePasajeros[i],tam, status,tams);
				retorno = 1;
			}// fin del if

		 }// fin del for

	}// fin del if del NULL
	else
	{
		printf("no se puede mostrar la lista\n");
	}

return retorno;
} // fin de mostrar Pasajeros

int addPassenger(ePasajero* listaDePasajeros, int tam, int* identificador, char nombre[], char apellido[], float precio, char codigoVuelo[], int tipoPasajero, int statusVuelo)
{
	int todoOk = -1;
	int verificacion;
	char cadena[100];
    int libre;
    int aux=0;

    libre = buscarLibre(listaDePasajeros, tam);

    if(listaDePasajeros != NULL && tam > 0 && libre > -1)
    {
    	for(int i = 0; i<tam; i++)
    	{
			if(listaDePasajeros[i].isEmpty == VACIO)
			{
					printf("ingrese nombre: ");
				    fflush(stdin);
				    gets(cadena);
					verificacion = sonLetras(cadena);

				    while (verificacion == -1 || strlen(cadena) > 51)
				    {
						printf("no ingresaste letras o el nombre fue muy largo, reingrese el Nombre: \n");
						fflush(stdin);
						gets(cadena);
						verificacion = sonLetras(cadena);
				    }
					strcpy(listaDePasajeros[i].nombre, cadena);

				    printf("ingrese su Apellido: ");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);
					while (verificacion == -1 || strlen(cadena) > 51)
					{
						printf("no ingresaste letras o el apellido fue muy largo, reingrese el apellido: \n");
						fflush(stdin);
						gets(cadena);
						verificacion = sonLetras(cadena);
					}
					strcpy(listaDePasajeros[i].apellido, cadena);

					printf("Ingrese Precio: ");
					fflush(stdin);
                    gets(cadena);

                    verificacion = sonLetras(cadena);
                    while (verificacion == 1)
                    {
                    	printf("no ingresaste numeros, reingrese Precio: \n");
                    	gets(cadena);
                    	verificacion = sonLetras(cadena);
                    }
                    listaDePasajeros[i].price = atof(cadena);

					printf("Ingrese un codigo de vuelo: ");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);
					while (verificacion == -1 || strlen(cadena) > 10)
					{

						printf("no ingresaste letras o fue un codigo muy largo, reingrese codigo de vuelo: \n");
						gets(cadena);
						verificacion = sonLetras(cadena);
					}
					strcpy(listaDePasajeros[i].flycode, cadena);

					printf("Ingrese un tipo de pasajero, 1)menor , 2)adulto, 3)Jubilado\n");
					fflush(stdin);
					scanf("%d",&aux);
					while(aux < 0 || aux > 3)
					{
					   printf("Error,reIngrese una Aerolinea :1)menor , 2)adulto, 3)Jubilado\n");
					   fflush(stdin);
					   scanf("%d", &aux);
					}
					listaDePasajeros[i].typePassenger = aux;

					printf("ingrese status del vuelo. 1. para Activo, 2. para Demorado y 3. para Cancelado\n");
					fflush(stdin);
					scanf("%d",&aux);
					while(aux < 0 || aux > 3)
					{
					   printf("Error,reIngrese status del vuelo. 1. para vuelo activo, 2 para demorado y 3 para cancelado\n");
					   fflush(stdin);
					   scanf("%d", &aux);
					}
					listaDePasajeros[i].statusFlight = aux;

					listaDePasajeros[libre].id = *identificador;
					(*identificador) ++;

				listaDePasajeros[i].isEmpty = OCUPADO;
				printf("\ningresaste correctamente al pasajero\n\n");
				todoOk = 0;
				break;

			}// fin del if del vacio

		}// fin del for

    }// fin del if del null
    else
    {
    	printf("\nUsted llego al limite de pasajeros que puede ingresar \n");
    }

return todoOk;
}// fin de cargar pasajeros


int modificarPasajero(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams)
{
	   int modificacion;
	   int indice = -1;
 	   int verificacion;
 	   char cadena[100];
       int auxiliarModif = 0;
       int indexEncontrado;
       char salirr;

      if (listaDePasajeros != NULL && tam > 0 && status !=NULL && tams > 0)
      {
		  printPassengers(listaDePasajeros, tam, status , tams);
		  printf("ingrese el id del pasajero que desea modificar: \n");
		  scanf("%d", &auxiliarModif);

		  indexEncontrado = findPassengersById(listaDePasajeros, tam, auxiliarModif);

			  if (indexEncontrado >= 0 && indexEncontrado < tam && listaDePasajeros[indexEncontrado].isEmpty == OCUPADO)
			  {
				  do
				  {
					  modificacion = menuModificaciones();

					  switch(modificacion)
					  {
					      case 1:
					    	  printf("Ingrese el nuevo nombre:\n ");
					    	  fflush(stdin);
					    	  gets(cadena);
					    	  verificacion = sonLetras(cadena);

							  while (verificacion == -1 || strlen(cadena) > 51)
							  {
								  printf("no ingresaste letras o el nombre fue muy largo, reingrese el Nombre: \n");
								  fflush(stdin);
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  strcpy(listaDePasajeros[indexEncontrado].nombre, cadena);
								  indice = 1;
							  }
						  break;

					      case 2:
							  printf("Ingrese el nuevo apellido: \n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == -1 || strlen(cadena) > 51)
							  {
								  printf("no ingresaste letras o el apellido fue muy largo, reingrese el Apellido: \n");
								  fflush(stdin);
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  strcpy(listaDePasajeros[indexEncontrado].apellido, cadena);
								  indice = 1;
							  }
						  break;

					      case 3:
							  printf("ingrese el nuevo precio: \n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == 1)
							  {
								  printf("no ingresaste numeros, reingrese precio: \n");
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  listaDePasajeros[indexEncontrado].price = atof(cadena);
								  indice = 1;
							  }
						  break;

					      case 4:
							  printf("Ingrese el nuevo codigo de vuelo:\n ");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == -1 || strlen(cadena) > 10)
							  {
								  printf("no ingresaste letras o su codigo fue muy largo, reingrese el codigo de vuelo: \n");
								  fflush(stdin);
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  strcpy(listaDePasajeros[indexEncontrado].flycode, cadena);
								  indice = 1;
							  }
						 break;

					      case 5:
							  printf("ingrese el nuevo tipo de pasajero: \n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == 1)
							  {
								  printf("no ingresaste numeros, reingrese el tipo de pasajero: \n");
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  listaDePasajeros[indexEncontrado].typePassenger = atoi(cadena);
								  indice = 1;
							  }
						  break;

					      case 6:
							  printf("ingrese el nuevo status flight: \n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == 1)
							  {
								  printf("no ingresaste numeros, reingrese el tipo de pasajero: \n");
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDePasajeros[indexEncontrado].isEmpty!= VACIO && listaDePasajeros[indexEncontrado].id == auxiliarModif)
							  {
								  listaDePasajeros[indexEncontrado].statusFlight = atoi(cadena);
								  indice = 1;
							  }
							  break;

					      case 7:
							  printf("si desea Salir escribe S sino N: \n");
							  fflush(stdin);
							  scanf("%c", &salirr);
						  break;

					  default:
						  printf("opcion invalida, pruebe una opcion del 1 al 7\n");
						  break;
					  }// fin del switch
					  if(modificacion<1 || modificacion >6)
					  {
						  printf("Asi quedo editado el pasajero\n\n");
						  printf("-------------------------- LISTA DE PASAJEROS ---------------------------------\n");
						  printf("ID   Nombre    Apellido    Precio    flycode    typePassenger  statusVuelo \n");
						  printf("-------------------------------------------------------------------------------\n");
						  printPassenger(listaDePasajeros[indexEncontrado], tam, status, tams);
						  printf("\n\n");
					  }//fin if

				  }while(salirr != 's');

			  }// fin del if
			  else
			  {
				  printf("no se encontro la ID\n");
			  }

      }//fin if null

return indice;
} //fin de modificar pasajero


int removePassenger(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams)
{
	int todoOk = -1;
	int auxiliarBaja =0;
	int indexEncontrado;
	if(listaDePasajeros != NULL && tam > 0)
	{
		printPassengers(listaDePasajeros, tam, status, tams);
		printf("Ingrese el ID del pasajero que desea dar de baja: ");
		scanf("%d", &auxiliarBaja);

		indexEncontrado = findPassengersById(listaDePasajeros, tam, auxiliarBaja);

		  if (indexEncontrado >= 0 && indexEncontrado < tam && listaDePasajeros[indexEncontrado].isEmpty == OCUPADO)
		  {
			 for(int i = 0 ; i < tam ; i++)
			 {

				if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarBaja)
				{
					listaDePasajeros[i].isEmpty= VACIO;
					printf("se dio de baja con exito a su pasajero\n");
					todoOk = 0;

				}// fin del if

			 }// fin del for

		} //fin if auxiliarBaja
	    else
	    {
		  printf("id no encontrada\n\n");
	    }

	}// fin if NULL

return todoOk;
}// fin de baja del pasajero


int findPassengersById(ePasajero* listaDePasajeros, int tam, int id)
{
    int indice = -1;
    if(listaDePasajeros != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            if(listaDePasajeros[i].id == id && listaDePasajeros[i].isEmpty == OCUPADO)
            {
                indice = i;
                break;
            }//fin if

        }//fin for

    }//fin if NULL

return indice;
}//fin findPassengersByid

int sortPassengers(ePasajero* listaDePasajeros, int tam, int orden)
{
    int todoOk = 0;
    ePasajero auxiliarPasajero;

    if(listaDePasajeros !=NULL && tam > 0)
    {
    	if (orden == 1) // ascendente
    	{
    		for (int i = 0; i < tam - 1; i++)
    		{
    			for (int j = i + 1; j < tam; j++)
				{
					if (strcmp(listaDePasajeros[i].apellido,listaDePasajeros[j].apellido) >=0 ||
						(strcmp(listaDePasajeros[i].apellido,listaDePasajeros[j].apellido) ==0 &&
						(listaDePasajeros[i].typePassenger > listaDePasajeros[j].typePassenger)))
					{
						   auxiliarPasajero = listaDePasajeros[i];
						   listaDePasajeros[i] = listaDePasajeros[j];
						   listaDePasajeros[j] = auxiliarPasajero;
						   todoOk = 1;
					}// fin del if

				}// fin del segundo for

    		}// fin del primer for

    	}// fin del orden 1

    	if (orden == 0) // descendente
    	{
    		for(int i= 0; i < tam -1; i++)
			{
				for(int j= i+1; j < tam; j++)
				{
					if(strcmp(listaDePasajeros[i].apellido, listaDePasajeros[j].apellido) <=0 ||
					  (strcmp(listaDePasajeros[i].apellido, listaDePasajeros[j].apellido) ==0 &&
					  (listaDePasajeros[i].typePassenger < listaDePasajeros[j].typePassenger)))
					{

					   auxiliarPasajero = listaDePasajeros[i];
					   listaDePasajeros[i] = listaDePasajeros[j];
					   listaDePasajeros[j] = auxiliarPasajero;
					   todoOk = 0;
					}// fin del if

				}// segundo for

    		  }// primer for

		}// fin del orden 0

    }// fin del if !=NULL

return todoOk;
}// fin de la funcion ordenarPasajeros

int mostrarPrecios(ePasajero* listaDePasajeros, int tam)
{
	int retorno =0;

	if(listaDePasajeros != NULL && tam > 0)
	{
		printf("\nmuestra los Precios de vuelo de los Pasajeros\n");
		for(int i=0; i<tam; i++)
		 {
			if(listaDePasajeros[i].isEmpty > 0)
			{
				printf("%.2f\n ", listaDePasajeros[i].price);
				retorno = 1;
			}// fin del if

		 }// fin del for

	}// fin del if

return retorno;
} // fin de mostrar precio

float sumarPreciosYPromediar(ePasajero* listaDePasajeros, int tam)
{
    int contador= 0;
    float acumulador = 0;
    float promedio = 0;
	if(listaDePasajeros != NULL && tam > 0)
	{
		for (int i = 0; i<tam; i++)
		{
			if(listaDePasajeros[i].isEmpty > 0)
			{
			    acumulador = acumulador + listaDePasajeros[i].price;
                contador++;
			}// fin del if

		}// fin del for

		promedio = acumulador / contador;
		printf("la suma de los precios es de %.2f y el promedio es de %.2f\n", acumulador, promedio);

	}// fin del if

return promedio;
}// fin de la funcion sumar precios y promediar

void superanPrecioPromedio(ePasajero* listaDePasajeros, int tam, float promedio)
{
	if(listaDePasajeros != NULL && tam > 0)
	{
		    printf("\n--------- Pasajeros que superan el Precio promedio ------------\n ");
			for (int i = 0; i<tam; i++)
			{
				if(listaDePasajeros[i].isEmpty > 0)
				{
				    if(listaDePasajeros[i].price >= promedio )
				    {
				        printf("esta persona llamada %s supera el Precio promedio porque su vuelo sale %.2f\n", listaDePasajeros[i].nombre,listaDePasajeros[i].price);
				    }//fin del if chiquito

				}// fin del if grande

			}// fin del for

	}// fin del if de !=NULL

}// fin de la funcion

void mostrarTipoPasajero(int idTipoPasajero, char nombre[15])
{
    char tipoPasajero[3][15] = {"Menor", "Adulto", "Jubilado"};

    if((idTipoPasajero > 0 && idTipoPasajero < 4) && nombre != NULL)
    {
    	idTipoPasajero = idTipoPasajero -1;
        strcpy(nombre, tipoPasajero[idTipoPasajero]);
    }//fin if

}//fin void

int sortPassengersByCode(ePasajero* listaDePasajeros, int tam,eStatus status[], int tams, int orden)
{
	int todoOk = 0;
	ePasajero auxiliarPasajero;

	if(listaDePasajeros !=NULL && tam > 0 && status !=NULL && tams > 0)
	{
		for (int i = 0; i < tam - 1; i++)
		{
			for (int j = i + 1; j < tam; j++)
			{
				if(strcmp(listaDePasajeros[i].flycode, listaDePasajeros[j].flycode) > 0 && orden == 1)
				{
					auxiliarPasajero = listaDePasajeros[i];
					listaDePasajeros[i] = listaDePasajeros[j];
					listaDePasajeros[j] = auxiliarPasajero;
					todoOk = 1;

				}//fin del otro if
				else if (strcmp(listaDePasajeros[i].flycode, listaDePasajeros[j].flycode) < 0 && orden == 0)
				{
					auxiliarPasajero = listaDePasajeros[i];
					listaDePasajeros[i] = listaDePasajeros[j];
					listaDePasajeros[j] = auxiliarPasajero;
					todoOk = 1;

				}

			}//fin segundo for

		}//fin primer for

		for (int i = 0; i < tam; i++)
		{
			if(listaDePasajeros[i].statusFlight == 1  && listaDePasajeros[i].isEmpty == OCUPADO )
			{
				printPassenger(listaDePasajeros[i],tam, status,tams);

			}
		}

	}//fin validacion Null

return todoOk;
}//fin de la funcion

int harcodearPasajeros(ePasajero listaDePasajeros[], int tam , int cant, int* pId)
{
    int contador=-1;
    int iPasajero=0;

    int ids[10]={1,2,3,4,5,6,7,8,9,10};

    char nombres[10][25]={
    	"Juan",
    	"Daniela",
    	"Lucia",
    	"Mauro",
    	"Diego",
    	"Juana",
    	"Miguel",
    	"Luciano",
    	"Stacy",
    	"Analia"
    };

    char apellidos[10][25]={
    	"Gutierrez",
    	"Alvarez",
    	"Romero",
    	"Uzuca",
    	"Maradona",
    	"Manso",
    	"Hernandez",
    	"Pereyra",
    	"Malibu",
    	"Falconeri"
    };

    float prices[10]={30000.00, 23000.00, 20000.00, 105050.00, 85000.00, 110000.00, 50000.00, 92000.00, 67000.00, 72150.00};

    char flyCodes[10][20]={
    		"ascdsdg",
    		"dfkszzas",
    		"ldfsdfnz",
    		"zisdtye",
    		"pseddfh",
    		"axsaery",
    		"dlfjdfa",
    		"kisdsgg",
    	    "basFefg",
    		"jsdgqsw",
    };

    int typePassengers[10]={1, 3, 1, 1, 2, 2, 3, 1, 3, 2};

    int statusFlighs[10]={1, 1, 1, 2, 2, 1, 3, 1, 3, 1};

    if(listaDePasajeros!=NULL && tam>0 && cant>=0 && cant<=tam && pId!=NULL)
    {
    	contador=1;
        for(int i=0;i<cant;i++)
        {
        	iPasajero= findPassengersById(listaDePasajeros,tam ,ids[i]);

        	if(iPasajero==-1)
            {
        		iPasajero= buscarLibre(listaDePasajeros, tam);
            }
        	listaDePasajeros[iPasajero].id=ids[i];
			strcpy(listaDePasajeros[iPasajero].nombre, nombres[i]);
			strcpy(listaDePasajeros[iPasajero].apellido, apellidos[i]);
			listaDePasajeros[iPasajero].price=prices[i];
			strcpy(listaDePasajeros[iPasajero].flycode, flyCodes[i]);
			listaDePasajeros[iPasajero].typePassenger=typePassengers[i];
			listaDePasajeros[iPasajero].statusFlight=statusFlighs[i];
			listaDePasajeros[iPasajero].isEmpty= OCUPADO;
			contador++;
        }//fin for

    }//fin if null

    return contador;
}
