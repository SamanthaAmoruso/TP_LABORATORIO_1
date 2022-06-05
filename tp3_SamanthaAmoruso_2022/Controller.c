#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "funciones.h"
#include "Controller.h"

int controller_setId(LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
    int tamanio;
    int mayor;
    int idObtenido;
    int auxiliarResultado;
    if(pArrayListPassenger != NULL)
    {
        tamanio = ll_len(pArrayListPassenger);
        if(tamanio == 0)
        {
           auxiliarResultado = 100;
        }
        else
        {
            for(int i=0;i<tamanio;i++)
            {
            	pPasajero = ll_get(pArrayListPassenger,i);
            	Passenger_getId(pPasajero,&idObtenido);
                if(i==0 || idObtenido>mayor)
                {
                  mayor = idObtenido;
                  auxiliarResultado = mayor + 1;
                }

             }//fin for

        }//fin else

    }  //fin del if
    else
    {
        auxiliarResultado = 100;
    }
return auxiliarResultado;
}


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	ll_clear(pArrayListPassenger);
	pFile = fopen(path,"r");
	int auxiliarRetorno = 1;

	if(pArrayListPassenger != NULL)
	{
		if(pFile == NULL)
		{
			printf("No se encontro el archivo en loadFromText porque pfile es null\n");
			auxiliarRetorno = 0;
		}
		parser_PassengerFromText(pFile,pArrayListPassenger);

	}//fin if
	else
	{
		printf("Error en la lista\n");
		auxiliarRetorno = 0;
	}
	fclose(pFile);

return auxiliarRetorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	ll_clear(pArrayListPassenger);
	pFile = fopen(path,"rb");
	int auxiliarRetorno = 1;

	if(pArrayListPassenger != NULL)
	{
		if(pFile == NULL)
		{
			printf("No se encontro el archivo\n");
			auxiliarRetorno = 0;
		}
		parser_PassengerFromBinary(pFile,pArrayListPassenger);
		fclose(pFile);
		auxiliarRetorno = 1;
	}
	else
	{
		printf("Error en la lista");
		auxiliarRetorno =  0;
	}
	return auxiliarRetorno;
}


int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	int id = 0;
	char nombre[50];
	char apellido[50];
	float precio;
	char cadena[60];
	char codigoDeVuelo[20];
	int tipoPasajero;
	int todoOk = 0;
	int verificacion;

	pPasajero = (Passenger*)Passenger_new();
	if(pPasajero == NULL)
	{
		printf("No hay suficiente espacio en memoria para guardar un pasajero\n");
	}
	else
	{
		printf("ingrese nombre: ");
		fflush(stdin);
		gets(nombre);
		verificacion = sonLetras(nombre);
		while (verificacion == -1 || strlen(nombre) > 50)
		{
			printf("no ingresaste letras o el nombre fue muy largo, reingrese el Nombre: \n");
			fflush(stdin);
			gets(nombre);
			verificacion = sonLetras(nombre);
		}
		Passenger_setNombre(pPasajero,nombre);

		printf("ingrese su Apellido: ");
		fflush(stdin);
		gets(apellido);
		verificacion = sonLetras(apellido);
		while (verificacion == -1 || strlen(apellido) > 50)
		{
			printf("no ingresaste letras o el apellido fue muy largo, reingrese el apellido: \n");
			fflush(stdin);
			gets(apellido);
			verificacion = sonLetras(apellido);
		}
		Passenger_setApellido(pPasajero,apellido);

		printf("Ingrese precio: ");
		fflush(stdin);
		gets(cadena);
		verificacion = sonLetras(cadena);
		while (verificacion == 1)
		{
			printf("error, Ingrese precio con numeros: \n");
			fflush(stdin);
			gets(cadena);
			verificacion = sonLetras(cadena);
		}
		precio = atof(cadena);
		Passenger_setPrecio(pPasajero,precio);

		printf("ingrese tipo pasajero: \n");
		fflush(stdin);
		gets(cadena);
		verificacion = sonLetras(cadena);
		while (verificacion == 1)
		{
			printf("error, Ingrese tipo de pasajero con numeros: \n");
			fflush(stdin);
			gets(cadena);
			verificacion = sonLetras(cadena);

		}
		tipoPasajero = atoi(cadena);
		Passenger_setTipoPasajero(pPasajero,tipoPasajero);


		printf("Ingrese un codigo de vuelo: ");
		fflush(stdin);
		gets(codigoDeVuelo);
		verificacion = sonLetras(codigoDeVuelo);
		while (verificacion == -1 || strlen(codigoDeVuelo) > 4)
		{

			printf("no ingresaste letras o fue un codigo muy largo, reingrese codigo de vuelo: \n");
			fflush(stdin);
			gets(codigoDeVuelo);
			verificacion = sonLetras(codigoDeVuelo);
		}
		Passenger_setCodigoVuelo(pPasajero,codigoDeVuelo);

        id = controller_setId(pArrayListPassenger);
		Passenger_setId(pPasajero,id);

		ll_add(pArrayListPassenger,pPasajero);

		todoOk = 1;

	}//fin else

return todoOk;
}

int controller_getIndexById(LinkedList* pArrayListPassenger,int idBuscado)
{
	Passenger* pPasajero;
    int tamanio;
    int idObtenido;
    int auxiliarRetorno = -1;

    tamanio = ll_len(pArrayListPassenger);
    for(int i=0;i<tamanio;i++)
    {
    	pPasajero = ll_get(pArrayListPassenger,i);
    	Passenger_getId(pPasajero,&idObtenido);
        if(idObtenido == idBuscado)
        {
            auxiliarRetorno = i;
        }

    }
    return auxiliarRetorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	int id;
	int indice = -1;
	int continuar = 1;
	int opcion;
	int nuevoNumero;
	char nuevaCadena[128];
	int todoOk= 0;
	int verificacion;

	controller_ListPassenger(pArrayListPassenger);
	while(indice == -1)
	{
		id = obtenerNumero("\nIngrese el id del pasajero que quiere modificar");
		indice = controller_getIndexById(pArrayListPassenger,id);
		if(indice == -1)
		{
			printf("El id ingresado es incorrecto\n");
			indice = -1;
		}
		else
			break;
	}
	pPasajero = ll_get(pArrayListPassenger,indice);
	while(continuar == 1)
	{
		opcion = obtenerNumero("Ingrese 1 para modificar nombre\n "
							   "Ingrese 2 para modificar codigo de vuelo\n "
							   "Ingrese 3 para modificar el precio\n"
							   "Ingrese 4 para modificar el tipo de pasajero\n"
							   "Ingrese 5 para editar el apellido\n");

		switch(opcion)
		{
		case 1:
			printf("ingrese nuevo nombre: ");
			fflush(stdin);
			gets(nuevaCadena);
			verificacion = sonLetras(nuevaCadena);

			while (verificacion == -1 || strlen(nuevaCadena) > 51)
			{
				printf("no ingresaste letras o el nombre fue muy largo, reingrese el Nombre: \n");
				fflush(stdin);
				gets(nuevaCadena);
				verificacion = sonLetras(nuevaCadena);
			}
			Passenger_setNombre(pPasajero,nuevaCadena);
			todoOk = 1;
			break;
		case 2:
			printf("ingrese nuevo codigo de vuelo: ");
			fflush(stdin);
			gets(nuevaCadena);
			verificacion = sonLetras(nuevaCadena);

			while (verificacion == -1 || strlen(nuevaCadena) > 20)
			{
				printf("no ingresaste letras o el codigo fue muy largo, reingrese el codigo de vuelo: \n");
				fflush(stdin);
				gets(nuevaCadena);
				verificacion = sonLetras(nuevaCadena);
			}
			Passenger_setCodigoVuelo(pPasajero,nuevaCadena);
			break;
		case 3:
			printf("ingrese nuevo precio: ");
			fflush(stdin);
			gets(nuevaCadena);
			verificacion = sonLetras(nuevaCadena);

			while (verificacion == 1 )
			{
				printf("no ingresaste numeros, reingrese precio: \n");
				fflush(stdin);
				gets(nuevaCadena);
				verificacion = sonLetras(nuevaCadena);
			}
			nuevoNumero = atof(nuevaCadena);
			Passenger_setPrecio(pPasajero,nuevoNumero);
			todoOk = 1;
			break;
		case 4:
			printf("ingrese un nuevo tipo de pasajero: ");
			fflush(stdin);
			gets(nuevaCadena);
			verificacion = sonLetras(nuevaCadena);

			while (verificacion == 1 )
			{
				printf("no ingresaste numeros, reingrese tipo de pasajero: \n");
				fflush(stdin);
				gets(nuevaCadena);
				verificacion = sonLetras(nuevaCadena);
			}
			nuevoNumero = atoi(nuevaCadena);
			Passenger_setTipoPasajero(pPasajero,nuevoNumero);
		break;

		case 5:
			printf("ingrese nuevo Apellido: ");
			fflush(stdin);
			gets(nuevaCadena);
			verificacion = sonLetras(nuevaCadena);
			while (verificacion == -1 || strlen(nuevaCadena) > 51)
			{
				printf("no ingresaste letras o el apellido fue muy largo, reingrese el apellido: \n");
				fflush(stdin);
				gets(nuevaCadena);
				verificacion = sonLetras(nuevaCadena);
			}
			Passenger_setApellido(pPasajero,nuevaCadena);
			todoOk = 1;
		break;

		default:
			printf("elija una opcion del 1 al 5\n");
		break;
		}
		continuar = obtenerNumero("Desea modificar otro dato?\n1.SI 2.NO");
	}

	return todoOk;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int indice = -1;
	int continuar = 1;
	int todoOk = 0;

	controller_ListPassenger(pArrayListPassenger);
	while(continuar == 1)
	{
		while(indice == -1)
		{
			id = obtenerNumero("Ingrese el numero de id del pasajero que desea borrar");
			indice = controller_getIndexById(pArrayListPassenger,id);
			if(indice == -1)
			{
				printf("El id ingresado es incorrecto\n");
			}
			else
				continue;
		}
		ll_remove(pArrayListPassenger,indice);
		todoOk = 1;
		continuar = obtenerNumero("Desea borrar otro pasajero?\n 1.SI 2.NO");
		if(continuar==1)
		{
			indice = -1;
		}
		else
			break;
	}

	return todoOk;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxpPasajero;
	int tamanio;
	int id;
	char nombre[51];
	char apellido[51];
	char codigoVuelo[4];
	int tipoPasajero;
	float precio;
	int todoOk = 0;

	if(pArrayListPassenger != NULL)
	{
		printf(" ID    NOMBRE  APELLIDO  PRECIO $ TIPOPASAJERO  CODIGOVUELO\n");
		tamanio = ll_len(pArrayListPassenger);
		for(int i=0;i< tamanio;i++)
		{
			auxpPasajero = ll_get(pArrayListPassenger,i);
			Passenger_getId(auxpPasajero,&id);
			Passenger_getNombre(auxpPasajero,nombre);
			Passenger_getApellido(auxpPasajero,apellido);
			Passenger_getPrecio(auxpPasajero,&precio);
			Passenger_getTipoPasajero(auxpPasajero,&tipoPasajero);
			Passenger_getCodigoVuelo(auxpPasajero,codigoVuelo);

			printf("%2d  %10s %8s %.2f  %4d  %12s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo);
			todoOk = 1;
		}

	}//fin if
return todoOk;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;
	int upOrDown;
	int todoOk= 0;

	opcion = obtenerNumero("Ingrese 1 si desea ordenar por nombre\n "
						   "Ingrese 2 si desea ordenar por ID\n "
						   "Ingrese 3 si desea ordenar por apellido\n"
						   "Ingrese 4 si desea orndear por precio\n"
						   "Ingrese 5 si desea ordenar por tipo de pasajero\n"
						   "Ingrese 6 si desea ordenar por codigo de vuelo\n ELECCION: ");
	opcion = validacionDeNumero(opcion,1,6);
	upOrDown = obtenerNumero("Ingrese 0 para ordenar de forma descendente\n Ingrese 1 para ordenar de forma ascendente\n ELECCION: ");
	upOrDown = validacionDeNumero(upOrDown,0,1);
	switch(opcion)
	{
		case 1:
			ll_sort(pArrayListPassenger,Passenger_CompareByName,upOrDown);
			todoOk = 1;
		break;

		case 2:
			ll_sort(pArrayListPassenger,Passenger_CompareById,upOrDown);
			todoOk = 1;
		break;

		case 3:
			ll_sort(pArrayListPassenger,Passenger_CompareByApellido,upOrDown);
		break;

		case 6:
			ll_sort(pArrayListPassenger,Passenger_CompareBycodigoDeVuelo,upOrDown);
		break;


		default:
			printf("elija una opcion del 1 al 6\n");
		break;
	}

return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* auxpPasajero;
	int tamanio;
	char nombre[51];
	char apellido[51];
	char codigoVuelo[4];
	int id;
	int tipoPasajero;
	float precio;
	int auxiliarRetorno;

	if(pArrayListPassenger == NULL)
	{
		printf("Direccion de memoria de la lista incorrecta");
		auxiliarRetorno = 0;
	}

	if(pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo en saveAsText porque pfile es null\n");
			auxiliarRetorno = 0;
		}
		else
		{
			tamanio = ll_len(pArrayListPassenger);
			fprintf(pFile,"id,nombre,apellido,precio,tipoPasajero,codigoVuelo\n");
			for(int i=0;i<tamanio;i++)
			{
				auxpPasajero = (Passenger*)ll_get(pArrayListPassenger,i);
				Passenger_getId(auxpPasajero, &id);
				Passenger_getNombre(auxpPasajero,nombre);
				Passenger_getApellido(auxpPasajero,apellido);
				Passenger_getPrecio(auxpPasajero, &precio);
				Passenger_getTipoPasajero(auxpPasajero,&tipoPasajero);
				Passenger_getCodigoVuelo(auxpPasajero, codigoVuelo);
				fprintf(pFile,"%d, %s, %s, %.2f, %d, %s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo);
			}//fin for

		}//fin else
		fclose(pFile);
		auxiliarRetorno = 1;
	}
return auxiliarRetorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* auxpPasajero;
	int tamanio;
	int i;
	char cabecera[70]={"id,nombre,apellido,precio,tipoPasajero,codigoVuelo\n"};
	int auxiliarRetorno;

	    if(pArrayListPassenger == NULL)
	    {
	        printf("Direccion de memoria de la lista incorrecta");
	        auxiliarRetorno = 0;
	    }

	    if(pArrayListPassenger != NULL)
	    {
	    pFile = fopen(path,"wb");
	    if(pFile == NULL)
	    {
	        printf("No se pudo abrir el archivo\n");
	        auxiliarRetorno = 0;
	    }
	    else
	    {
	        fwrite(cabecera,sizeof(char[33]),1,pFile);
	        tamanio = ll_len(pArrayListPassenger);
	        for(i=0;i<tamanio;i++)
	        {
	        	auxpPasajero = (Passenger*)ll_get(pArrayListPassenger,i);
	                fwrite(auxpPasajero,sizeof(Passenger),1,pFile);
	        }
	    }
	    fclose(pFile);
	    auxiliarRetorno = 1;
	    }
	    return auxiliarRetorno;

}
