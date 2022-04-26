/*
 * ArrayPassenger.c
 *
 *  Created on: 17 abr. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VACIO 0
#define OCUPADO 1
#include "ArrayPassenger.h"

int menu ()
{
	fflush(stdin);
    int opcion;

    printf(" 1.Alta de un pasajero\n");
    printf(" 2.Modificacion de un pasajero\n");
    printf(" 3.Baja de un pasajero\n");
    printf(" 4.Informar sobre los pasajeros \n");
    printf(" 5.Salir del menu\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

    fflush(stdin);

    return opcion;

}// fin del menu

int inicializarPasajeros(ePasajero listaDePasajeros[], int tam)
{
   int retorno = 0;
   if(listaDePasajeros != NULL && tam > 0)
   {
	   for(int i= 0; i < tam; i++)
	   {
		   listaDePasajeros[i].isEmpty = VACIO;
		   retorno = 1;
	   }// fin del for

   }// fin del if

   return retorno;
}// fin de inicializar pasajeros

int buscarLibre(ePasajero listaDePasajeros[], int tam)
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

int buscarPasajero(ePasajero listaDePasajeros[], int tam, int identificador)
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

int printPassengers(ePasajero listaDePasajeros[], int tam)
{
	int retorno = -1;

	if(listaDePasajeros != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		 {
			if(listaDePasajeros[i].isEmpty == OCUPADO)
			{
				printf("%d %s %s %.2f %s %d \n ", listaDePasajeros[i].id,
											   listaDePasajeros[i].nombre,
											   listaDePasajeros[i].apellido,
											   listaDePasajeros[i].price,
											   listaDePasajeros[i].flycode,
											   listaDePasajeros[i].typePassenger);
				retorno = 1;
			}// fin del if

		 }// fin del for

	}// fin del if del NULL

return retorno;
} // fin de mostrar Pasajeros

int addPassenger(ePasajero listaDePasajeros[], int tam, int* identificador, char nombre[], char apellido[], float precio, char codigoVuelo[], int tipoPasajero)
{
	int todoOk = -1;
	int verificacion;
	char cadena[50];
    int libre;

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

					printf("Ingrese un tipo de pasajero\n");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);
					while (verificacion == 1)
					{

						printf("no ingresaste numeros, reingrese tipo del pasajero: \n");
						gets(cadena);
						verificacion = sonLetras(cadena);
					}
                    listaDePasajeros[i].typePassenger = atoi(cadena);


				listaDePasajeros[libre].id = *identificador;
				(*identificador) ++;

				listaDePasajeros[i].isEmpty = OCUPADO;
				printf("\ningresaste correctamente al pasajero\n\n");
				todoOk = 0;
				break;
			}// fin del if bebe

		}// fin del for

    }// fin del if madre
    else
    {
    	printf("\nUsted llego al limite de pasajeros que puede ingresar \n");
    }

return todoOk;
}// fin de cargar pasajeros

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

int modificarPasajero(ePasajero listaDePasajeros[], int tam)
{
	   int modificacion;
	   int indice = -1;
 	   int verificacion;
 	   char cadena[50];
 	   int banderaPasajero = -1;
       int auxiliarModif = 0;

      printPassengers(listaDePasajeros, tam);
	  printf("ingrese el id del pasajero que desea modificar: \n");
	  scanf("%d", &auxiliarModif);
	  if (auxiliarModif > tam)
	  {
		  printf("el id supera el tamaño, ingrese nuevamente\n ");
		  banderaPasajero=1;
	  }

	  if (auxiliarModif <= tam)
	  {
		  for (int i = 0; i < tam; i++)
		  {
			  if(listaDePasajeros[i].id == auxiliarModif && listaDePasajeros[i].isEmpty == OCUPADO)
			  {
				  printf("ID encontrada ");
				  banderaPasajero=0;
				  break;
			  }//fin if
			  else
			  {
				  printf("no hay pasajero con esta id\n");
				  break;
			  }

		  }// fin del for

	  }// fin del if

	  if (banderaPasajero == 0)
	  {
		  printf("\nIngrese lo que quiere modificar de ese pasajero: \n 1.nombre\n 2.apellido\n 3.precio\n 4.codigo de vuelo\n 5.tipo de pasajeros\n");
		  scanf("%d%*c", &modificacion);

		  switch(modificacion)
		  	  {
		  		  case 1:
		  			printf("Ingrese el nuevo nombre:\n ");
		  			fflush(stdin);
		  			gets(cadena);
					verificacion = sonLetras(cadena);

		  			for(int i = 0 ; i < tam ; i++)
		  			{
		  				while (verificacion == -1 || strlen(cadena) > 51)
						{
							printf("no ingresaste letras o el nombre fue muy largo, reingrese el Nombre: \n");
							fflush(stdin);
							gets(cadena);
							verificacion = sonLetras(cadena);
						}
		  				if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarModif)
		  				{
		  					strcpy(listaDePasajeros[i].nombre, cadena);
		  					indice = 1;
		  					break;
		  				}


		  			 }// fin del for
		  			printf("asi quedo editado su pasajero:\n ");
		  			printPassengers(listaDePasajeros, tam);
		  		  break;

		  		  case 2:
		  			printf("Ingrese el nuevo apellido: \n");
		  			fflush(stdin);
		  			gets(cadena);
					verificacion = sonLetras(cadena);

		  			for(int i = 0 ; i < tam ; i++)
		  			{
		  				while (verificacion == -1 || strlen(cadena) > 51)
						{
							printf("no ingresaste letras o el apellido fue muy largo, reingrese el Apellido: \n");
							fflush(stdin);
							gets(cadena);
							verificacion = sonLetras(cadena);
						}
		  				if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarModif)
		  				{
		  					strcpy(listaDePasajeros[i].apellido, cadena);
		  					indice = 1;
		  					break;
		  				}

		  			 }// fin del for
		  			printf("asi quedo editado su pasajero: \n");
		  			printPassengers(listaDePasajeros, tam);
		  		  break;

		  		  case 3:
		  			  printf("ingrese el nuevo precio: \n");
		  			  fflush(stdin);
					  gets(cadena);
					  verificacion = sonLetras(cadena);

		  			  for(int i = 0 ; i < tam ; i++)
		  			  {
		  				 while (verificacion == 1)
						 {
							printf("no ingresaste numeros, reingrese precio: \n");
							gets(cadena);
							verificacion = sonLetras(cadena);
						 }
		  				 if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarModif)
		  				 {
		  					listaDePasajeros[i].price = atof(cadena);
		  					indice = 1;
		  					break;
		  				 }


		  			  }// fin del for
		  			  printf("asi quedo editado su pasajero: \n ");
		  			  printPassengers(listaDePasajeros, tam);
		  		  break;

		  		  case 4:
		  			printf("Ingrese el nuevo codigo de vuelo:\n ");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);

					for(int i = 0 ; i < tam ; i++)
					{
						while (verificacion == -1 || strlen(cadena) > 10)
						{
							printf("no ingresaste letras o su codigo fue muy largo, reingrese el codigo de vuelo: \n");
							fflush(stdin);
							gets(cadena);
							verificacion = sonLetras(cadena);
						}
						if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarModif)
						{
							strcpy(listaDePasajeros[i].flycode, cadena);
							indice = 1;
							break;
						}


					 }// fin del for
					printf("asi quedo editado su pasajero:\n ");
					printPassengers(listaDePasajeros, tam);
		  		  break;

		  		  case 5:
		  			printf("ingrese el nuevo tipo de pasajero: \n");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);

					  for(int i = 0 ; i < tam ; i++)
					  {
						 while (verificacion == 1)
						 {
							printf("no ingresaste numeros, reingrese el tipo de pasajero: \n");
							gets(cadena);
							verificacion = sonLetras(cadena);
						 }
						 if(listaDePasajeros[i].isEmpty!= VACIO && listaDePasajeros[i].id == auxiliarModif)
						 {
							listaDePasajeros[i].typePassenger = atoi(cadena);
							indice = 1;
							break;
						 }


					  }// fin del for
				   printf("asi quedo editado su pasajeros: \n ");
				   printPassengers(listaDePasajeros, tam);
		  		  break;

		  		  default:
		  			  printf("opcion invalida, pruebe una opcion del 1 al 5\n");
		  		  break;
		  	  }// fin del switch

	  }// fin del if de banderaPasajero

return indice;
} //fin de modificar pasajero


int removePassenger(ePasajero listaDePasajeros[], int tam)
{
	int todoOk = -1;
	int auxiliarBaja =0;
	if(listaDePasajeros != NULL && tam > 0)
	{
		printPassengers(listaDePasajeros, tam);
		printf("Ingrese el ID del pasajero que desea dar de baja: ");
		scanf("%d", &auxiliarBaja);
		if (auxiliarBaja > tam)
		{
		  printf("el id supera el tamaño maximo, ingrese nuevamente\n ");
		}

		if (auxiliarBaja <= tam)
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

	}// fin if NULL

return todoOk;
}// fin de baja del pasajero


int findPassengersById(ePasajero listaDePasajeros[], int tam, int id)
{
    int indice = -1;
    if(listaDePasajeros != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            if(listaDePasajeros[i].id == id)
            {
                indice = i;
                break;
            }//fin if

        }//fin for

    }//fin if NULL

return indice;
}//fin findPassengersByid

int sortPassengers(ePasajero listaDePasajeros[], int tam, int orden)
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
					if (listaDePasajeros[i].typePassenger == listaDePasajeros[j].typePassenger || (listaDePasajeros[i].typePassenger > listaDePasajeros[j].typePassenger) || strcmp(listaDePasajeros[i].apellido,listaDePasajeros[j].apellido) >= 0 )
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
					if(strcmp(listaDePasajeros[i].apellido, listaDePasajeros[j].apellido) < 0 || (strcmp(listaDePasajeros[i].apellido, listaDePasajeros[j].apellido) ==0 && listaDePasajeros[i].typePassenger < listaDePasajeros[j].typePassenger))
					{

					   auxiliarPasajero = listaDePasajeros[i];
					   listaDePasajeros[i] = listaDePasajeros[j];
					   listaDePasajeros[j] = auxiliarPasajero;
					   todoOk = 0;
					}// fin del if

				}// segundo for

    		  }// primer for

		}// fin del orden 0

    }// fin del if que pone !=NULL

return todoOk;
}// fin de la funcion ordenarPasajeros

int mostrarPrecios(ePasajero listaDePasajeros[], int tam)
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

float sumarPreciosYPromediar(ePasajero listaDePasajeros[], int tam)
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

void superanPrecioPromedio(ePasajero listaDePasajeros[], int tam, float promedio)
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

