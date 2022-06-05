#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	char id[21];
	char nombre[51];
	char apellido[51];
	char precio[21];
	char codigoDeVuelo[4];
	char tipoPasajero[20];
	int retorno= 0;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%s\n",nombre);
		while(!feof(pFile))
		{
		   if(fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n] \n",id,nombre,apellido,precio,tipoPasajero,codigoDeVuelo) == 6)
		   {
			   pPasajero = Passenger_newParametros(id,nombre,apellido,precio,tipoPasajero,codigoDeVuelo);

			   if(pPasajero!=NULL)
			   {
				   ll_add(pArrayListPassenger,pPasajero);
			   }

		   }
		   else
		   {
			   break;
		   }

		}//fin while
		retorno = 1;

	}//fin ifs

	//fclose(pFile);

return retorno;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	int devolucion;
	int retorno = 0;

	fseek(pFile,33,SEEK_SET);
	while(!feof(pFile))
	{
		pPasajero = Passenger_new();

		if(pPasajero!=NULL)
		{
			devolucion = fread(pPasajero,sizeof(Passenger),1,pFile);
			if(devolucion != 1)
			{
				break;
			}
			ll_add(pArrayListPassenger,pPasajero);
		}

		retorno = 1;
	}//fin while

	//fclose(pFile);

return retorno;
}
