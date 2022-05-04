/*
 * tp1_AmorusoSamantha_2022.c
 *
 *  Created on: 3 abr. 2022
 *      Author: User
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tp1_SamanthaAmoruso_2022.h"

int menu()
{
	int opcion;
	printf(" 1. Ingresar kilometros:\n");
	printf(" 2. Ingresar el precio de aerolinea y latam\n");
	printf(" 3. Calcular todos los costos:\n");
	printf(" 4. Informar resultados:\n");
	printf(" 5. Carga forzada de datos:\n");
	printf(" 6. Salir:\n");

	scanf("%d", &opcion);
	return opcion;
}//fin

float totalKm(float kilometros)
{
	float resultado;
	resultado = kilometros;
	return resultado;

}//fin

float precioTotal(float precio)
{
	float resultado;
	resultado = precio;
	return resultado;
}//fin

float precioConDebito(float precio)
{
	return precio - (precio * 10 / 100) ;
}//fin

float precioConCredito(float precio)
{
	return (precio * 25 / 100) + precio;
}//fin

float precioPorKm(float precio, float kilometros)
{
	float resultado;
	resultado = kilometros / precio;
	return resultado;
}//fin

float precioConBitcoin(float precio)
{
	float bitcoin = 4606954.55;
	float resultado;
	resultado = precio / bitcoin;
	return resultado;
}//fin

float preciosConDiferencia(float precioAerolineas, float precioLatam)
{
	return precioAerolineas - precioLatam;
}//fin

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

//-----------------------------------------------------------------------//
