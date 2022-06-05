#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* pPasajero;
	pPasajero = malloc(sizeof(Passenger));
	if(pPasajero == NULL)
	{
			printf("No hay espacio suficiente en memoria\n");
			return 0;
	}
	else
	{
		Passenger_setId(pPasajero, 100);
		Passenger_setNombre(pPasajero, " ");
		Passenger_setApellido(pPasajero, " ");
		Passenger_setPrecio(pPasajero, 0);
		Passenger_setTipoPasajero(pPasajero, 0);
		Passenger_setCodigoVuelo(pPasajero, " ");
	}

return pPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellido,char* precio,char* tipoPasajeroStr, char* codigoVuelo)
{
	Passenger* pPasajero;
	int flag = 0;
	pPasajero = Passenger_new();

	if(pPasajero != NULL)
	{
		 if(Passenger_setId(pPasajero, atoi(idStr)) == 1 &&
			Passenger_setNombre(pPasajero, nombreStr)==1 &&
			Passenger_setApellido(pPasajero, apellido)==1 &&
			Passenger_setPrecio(pPasajero,atof(precio)) == 1 &&
			Passenger_setTipoPasajero(pPasajero, atoi(tipoPasajeroStr))==1 &&
			Passenger_setCodigoVuelo(pPasajero, codigoVuelo)==1 )
		   {
			   flag = 1;
		   }

		   if(flag == 0)
		   {
				printf("Ocurrio un error al crear el pasajero esta funcion es passenger_new parametros\n");
				printf("%d", Passenger_setId(pPasajero, atoi(idStr)));
				printf("%d", Passenger_setNombre(pPasajero, nombreStr));
				printf("%d", Passenger_setApellido(pPasajero, apellido));
				printf("%d", Passenger_setPrecio(pPasajero, atof(precio)));
				printf("%d", Passenger_setTipoPasajero(pPasajero, atoi(tipoPasajeroStr)));
				printf("%d\n", Passenger_setCodigoVuelo(pPasajero, codigoVuelo));

		   }

	}//fin if

return pPasajero;
}

void Passenger_delete(Passenger* p)
{
	free(p);
}

int Passenger_setId(Passenger* this,int id)
{
	int todoOk = 0;
	if(this !=NULL && id > 0)
	{
	   this->id = id;
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk = 0;
	if(this !=NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}

return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk= 0;
	if(this !=NULL && nombre != NULL)
	{
	   strcpy(this->nombre, nombre);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this !=NULL && nombre != NULL)
	{
	   strcpy(nombre,this->nombre);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk= 0;
	if(this !=NULL && apellido != NULL)
	{
	   strcpy(this->apellido, apellido);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this !=NULL && apellido != NULL)
	{
	   strcpy(apellido,this->apellido);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk= 0;
	if(this !=NULL && codigoVuelo != NULL)
	{
	   strcpy(this->codigoVuelo, codigoVuelo);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this !=NULL && codigoVuelo != NULL)
	{
	   strcpy(codigoVuelo,this->codigoVuelo);
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = 0;
	if(this !=NULL && tipoPasajero > 0)
	{
	   this->tipoPasajero = tipoPasajero;
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = 0;
	if(this !=NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk = 1;
	}

return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;
	if(this !=NULL && precio > 0)
	{
	   this->precio = precio;
	   todoOk = 1;
	}

return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;
	if(this !=NULL && precio != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}

return todoOk;
}

int Passenger_CompareByName(void* pasajero1, void* pasajero2)
{
    int resultado;
    Passenger* auxiliar1 = NULL;
    Passenger* auxiliar2 = NULL;

    if(pasajero1 != NULL && pasajero2 != NULL)
    {
       auxiliar1 = (Passenger*) pasajero1;
       auxiliar2 = (Passenger*) pasajero2;
       resultado = strcmp(auxiliar1->nombre, auxiliar2->nombre);
    }
    return resultado;
}

int Passenger_CompareByApellido(void* pasajero1, void* pasajero2)
{
    int resultado;
    Passenger* auxiliar1 = NULL;
    Passenger* auxiliar2 = NULL;

    if(pasajero1 != NULL && pasajero2 != NULL)
    {
       auxiliar1 = (Passenger*) pasajero1;
       auxiliar2 = (Passenger*) pasajero2;
       resultado = strcmp(auxiliar1->apellido, auxiliar2->apellido);
    }

return resultado;
}

int Passenger_CompareBycodigoDeVuelo(void* pasajero1, void* pasajero2)
{
    int resultado;
    Passenger* auxiliar1 = NULL;
    Passenger* auxiliar2 = NULL;

    if(pasajero1 != NULL && pasajero2 != NULL)
    {
       auxiliar1 = (Passenger*) pasajero1;
       auxiliar2 = (Passenger*) pasajero2;
       resultado = strcmp(auxiliar1->codigoVuelo, auxiliar2->codigoVuelo);
    }

return resultado;
}

int Passenger_CompareById(void* pasajero1, void* pasajero2)
{
    int resultado;
    Passenger* auxiliar1 = NULL;
    Passenger* auxiliar2 = NULL;

    if(pasajero1 != NULL && pasajero2 != NULL)
    {
       auxiliar1 = (Passenger*) pasajero1;
       auxiliar2 = (Passenger*) pasajero2;
       if(auxiliar1->id > auxiliar2->id)
    {
        resultado = 1;
    }
    else
    {
        if(auxiliar1->id < auxiliar2->id)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}
