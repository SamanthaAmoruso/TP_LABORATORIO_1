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
	printf(" 3. Calcular todas las operaciones:\n");
	printf(" - Latam:\n");
	printf(" - Precio con tarjeta de débito:\n");
	printf(" - Precio con tarjeta de crédito:\n");
	printf(" - Precio pagando con bitcoin:\n");
	printf(" - Precio unitario:\n");
	printf(" - Aerolíneas:\n");
	printf(" - Precio con tarjeta de débito:\n");
	printf(" - Precio con tarjeta de crédito:\n");
	printf(" - Precio pagando con bitcoin:\n");
	printf(" - Precio unitario:\n");
	printf(" - La diferencia de precio es:\n");
	printf(" 4. Informar resultados:\n");
	printf(" 5. Carga forzada de datos:\n");
	printf(" 6. Salir:\n");

	scanf("%d", &opcion);
	return opcion;
}//fin llave

float totalKm(float kilometros)
{
	float resultado;
	resultado = kilometros;
	return resultado;

}//fin llave

float precioTotalAerolineas(float precioAerolineas)
{
	float resultado;
	resultado = precioAerolineas;
	return resultado;
}//fin llave

float precioAerolineasDebito(float precioAerolineas)
{
	return precioAerolineas - (precioAerolineas * 10 / 100) ;
}//fin llave

float precioAerolineasCredito(float precioAerolineas)
{
	return (precioAerolineas * 25 / 100) + precioAerolineas;
}//fin llave

float precioAerolineasPorKm(float precioAerolineas, float kilometros)
{
	float resultado;
	resultado = kilometros / precioAerolineas;
	return resultado;
}//fin llave

float precioAerolineasBitcoin(float precioAerolineas)
{
	float bitcoin = 4606954.55;
	float resultado;
	resultado = bitcoin / precioAerolineas;
	return resultado;
}//fin llave

//-----------------------------------------------------------------------//

float precioTotalLatam(float precioLatam)
{
	float resultado;
	resultado = precioLatam;
	return resultado;
}//fin llave

float precioLatamDebito(float precioLatam)
{
	return precioLatam - (precioLatam * 10 / 100) ;
}//fin llave

float precioLatamCredito(float precioLatam)
{
	return (precioLatam * 25 / 100) + precioLatam;
}//fin llave

float precioLatamPorKm(float precioLatam, float kilometros)
{
	float resultado;
	resultado = kilometros / precioLatam;
	return resultado;
}//fin llave


float precioLatamBitcoin(float precioLatam)
{
	float bitcoin = 4606954.55;
	float resultado;
	resultado = bitcoin / precioLatam;
	return resultado;
}//fin llave

float precioAerolineasDiferenciaPrecio(float precioAerolineas, float precioLatam)
{
	return precioAerolineas - precioLatam;
}//fin llave

// ------------------------------------------------------------------------------------------------------//

float totalKmFozado(float kilometroForzado)
{
	float resultado;
	resultado = kilometroForzado;
	return resultado;
}//fin llave

float precioForzadoLatam(float preciosForzadoLatam)
{
	float resultado;
	resultado = preciosForzadoLatam;
	return resultado;
}//fin llave

float precioLatamDebitoForzado(float preciosForzadoLatam)
{
	return preciosForzadoLatam - (preciosForzadoLatam * 10 / 100) ;
}//fin llave

float precioLatamCreditoForzado(float preciosForzadoLatam)
{
	return (preciosForzadoLatam * 25 / 100) + preciosForzadoLatam;
}//fin llave

float precioLatamPorKmForzado(float preciosForzadoLatam, float kilometroForzado)
{
	float resultado;
	resultado = kilometroForzado / preciosForzadoLatam;
	return resultado;
}//fin llave

float precioLatamBitcoinForzado(float preciosForzadoLatam)
{
	float bitcoin = 4606954.55;
	float resultado;
	resultado = bitcoin / preciosForzadoLatam;
	return resultado;
}//fin llave

float precioAerolineasDiferenciaPrecioForzado(float precioForzadoAerolineas, float preciosForzadoLatam)
{
	return precioForzadoAerolineas - preciosForzadoLatam;
}//fin llave

//-------------------------------------------//

float precioForzadoAerolinea(float precioForzadoAerolineas)
{
	float resultado;
	resultado = precioForzadoAerolineas;
	return resultado;
}//fin llave

float precioAerolineasDebitoForzado(float precioForzadoAerolineas)
{
	return precioForzadoAerolineas - (precioForzadoAerolineas * 10 / 100) ;
}//fin llave

float precioAerolineasCreditoForzado(float precioForzadoAerolineas)
{
	return (precioForzadoAerolineas * 25 / 100) + precioForzadoAerolineas;
}//fin llave

float precioAerolineasPorKmForzado(float precioForzadoAerolineas, float kilometroForzado)
{
	float resultado;
	resultado = kilometroForzado / precioForzadoAerolineas;
	return resultado;
}//fin llave

float precioAerolineasBitcoinForzado(float precioForzadoAerolineas)
{
	float bitcoin = 4606954.55;
	float resultado;
	resultado = bitcoin / precioForzadoAerolineas;
	return resultado;
}//fin llave

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
