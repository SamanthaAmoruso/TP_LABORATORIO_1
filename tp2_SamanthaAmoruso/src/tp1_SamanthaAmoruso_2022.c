/*
 ============================================================================
 Name        : tp1_SamanthaAmoruso_2022.c
 Author      : SAMI
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp1_SamanthaAmoruso_2022.h"

int main()
{
	setbuf(stdout,NULL);

	char seguir ='s';
	int bandera1 = 0;
	int bandera2 = 0;
	int bandera3 = 0;
	int bandera4 = 0;
	int bandera5 = 0;
	float kilometros = 0;
	float precioLatam = 0;
	float precioAerolineas = 0;

	float xKilometro;
	float xPrecioAerolinea;
	float xPrecioAerolineaCredito;
	float xPrecioAerolineaDebito;
	float xPrecioAerolineaBitcoin;
	float xPrecioAerolineaKm;
	float xPrecioAerolineaDiferencia;

	float xPrecioLatam;
	float xPrecioLatamCredito;
	float xPrecioLatamDebito;
	float xPrecioLatamBitcoin;
	float xPrecioLatamKm;

	float kilometroForzado = 7090;
	float precioForzadoAerolineas = 162965;
	float preciosForzadoLatam = 159339;

	float xKilometroForzado;
	float xPrecioForzadoLatam;
	float xPrecioLatamCreditoForzado;
	float xPrecioLatamDebitoForzado;
	float xPrecioLatamBitcoinForzado;
	float xPrecioLatamKmForzado;

	float xPrecioforzadoAerolinea;
	float xPrecioAerolineaCreditoForzado;
	float xPrecioAerolineaDebitForzadoo;
	float xPrecioAerolineaBitcoinForzado;
	float xPrecioAerolineaKmForzado;
	float xPrecioAerolineaDiferenciaForzado;

	int verificacion;
	char cadena[50];

	do
	{
		switch(menu())
		{
		 	 case 1:
			 printf("Ingrese los kilometros: ");
			 fflush(stdin);
			 gets(cadena);

			 verificacion = sonLetras(cadena);
			 while (verificacion == 1)
			 {
				printf("no ingresaste numeros, reingrese kilometros: \n");
				fflush(stdin);
				gets(cadena);
				verificacion = sonLetras(cadena);
			 }
			 printf("Los kilometros que usted ingreso son: %s\n", cadena);

			 kilometros = atof(cadena);
			 bandera1=1;
			 break; //fin del case 1

			 case 2:
			 if (bandera1==0)
			 {
				printf("\n error,no ingresaste Kilometros\n");
			 }
			 else
			 {
				 printf("\n Ingrese el precio de su vuelo Aerolineas: ");
				 fflush(stdin);
				 gets(cadena);

				 verificacion = sonLetras(cadena);
				 while (verificacion == 1)
				 {
					printf("no ingresaste numeros, reingrese el precio de su vuelo Aerolineas: \n");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);
				 }
				 printf("El precio de su vuelo aerolineas es de: %s\n",cadena);
				 precioAerolineas = atof(cadena);

				 printf("\n Ingrese el precio de su vuelo de latam: ");
				 fflush(stdin);
				 gets(cadena);

				 verificacion = sonLetras(cadena);
				 while (verificacion == 1)
				 {
					printf("no ingresaste numeros, reingrese el precio de su vuelo de latam: \n");
					fflush(stdin);
					gets(cadena);
					verificacion = sonLetras(cadena);
				 }
				 printf("El precio de su vuelo latam es de: %s\n",cadena);
				 precioLatam = atof(cadena);
				 bandera2=1;
			 }
			 break; //fin del case 2

			 case 3:
			 if (bandera1==1 && bandera2==1)
			 {
				xKilometro = totalKm(kilometros);
				xPrecioAerolinea = precioTotal(precioAerolineas);
				xPrecioAerolineaCredito = precioConCredito(precioAerolineas);
				xPrecioAerolineaDebito = precioConDebito(precioAerolineas);
				xPrecioAerolineaBitcoin = precioConBitcoin (precioAerolineas);
				xPrecioAerolineaKm = precioPorKm(precioAerolineas, kilometros);

				xPrecioLatam = precioTotal(precioLatam);
				xPrecioLatamCredito = precioConCredito(precioLatam);
				xPrecioLatamDebito = precioConDebito(precioLatam);
				xPrecioLatamBitcoin = precioConBitcoin (precioLatam);
				xPrecioLatamKm = precioPorKm(precioLatam, kilometros);
				xPrecioAerolineaDiferencia = preciosConDiferencia(precioAerolineas, precioLatam);

				//xPrecioLatam = precioTotalLatam(precioLatam);
				//xPrecioLatamCredito = precioLatamCredito(precioLatam);
				//xPrecioLatamDebito = precioLatamDebito(precioLatam);
				//xPrecioLatamBitcoin = precioLatamBitcoin(precioLatam);
				//xPrecioLatamKm = precioLatamPorKm(precioLatam, kilometros);

				printf("\nYa se calcularon todos los costos\n");
				bandera3=1;
			 }// fin del if del case 3
			 else if(bandera1==0)
			 {
				printf("\n error,no ingresaste kilometros");
			 }
			 if (bandera2==0)
			 {
				printf("\n error,no ingresaste el precio de aerolineas y latam\n");
			 }
			 break; // fin del case 3

			 case 4:
			 if (bandera1==1 && bandera2==1 && bandera3==1)
			 {
				printf("KMS ingresados: %.2f", xKilometro);
				printf("\n Latam: %.2f",xPrecioLatam);
				printf("\n Precio con tarjeta de débito: %.2f",xPrecioLatamDebito);
				printf("\n Precio con tarjeta de crédito: %.2f",xPrecioLatamCredito);
				printf("\n Precio pagando con bitcoin: %.11f BTC",xPrecioLatamBitcoin); //puse %.11f para el btc, ya que comprobado en la calculadora, con menos de 11 digitos la cuenta no da bien.
				printf("\n Precio unitario: %.2f",xPrecioLatamKm);

				printf("\n\n Aerolinea: %.2f",xPrecioAerolinea);
				printf("\n Precio con tarjeta de débito: %.2f",xPrecioAerolineaDebito);
				printf("\n Precio con tarjeta de crédito: %.2f",xPrecioAerolineaCredito);
				printf("\n Precio pagando con bitcoin: %.11f BTC",xPrecioAerolineaBitcoin); //puse %.11f para el btc, ya que comprobado en la calculadora, con menos de 11 digitos la cuenta no da bien.
				printf("\n Precio unitario: %.2f",xPrecioAerolineaKm);
				printf("\n La diferencia de precio es: %.2f\n",xPrecioAerolineaDiferencia);
				bandera4=1;
			 }

			 if(bandera1==0)
			 {
				printf("error,no ingresaste kilometros\n");
			 }

			 if (bandera2==0)
			 {
				printf("error,no ingresaste el precio aerolineas y latam\n");
			 }

			 if (bandera3==0)
			 {
				printf("error,no calculaste los costos\n");
			 }
			 break;//fin case 4

			 case 5:
		     if(bandera1==0 && bandera2==0 && bandera3==0 && bandera4==0)
		     {
		    	xKilometroForzado = totalKm(kilometroForzado);
				xPrecioForzadoLatam = precioTotal(preciosForzadoLatam);
				xPrecioLatamCreditoForzado = precioConCredito(preciosForzadoLatam);
				xPrecioLatamDebitoForzado = precioConDebito(preciosForzadoLatam);
				xPrecioLatamBitcoinForzado = precioConBitcoin(preciosForzadoLatam);
				xPrecioLatamKmForzado = precioPorKm(kilometroForzado,preciosForzadoLatam);


				xPrecioforzadoAerolinea = precioTotal(precioForzadoAerolineas);
				xPrecioAerolineaCreditoForzado = precioConCredito(precioForzadoAerolineas);
				xPrecioAerolineaDebitForzadoo = precioConDebito(precioForzadoAerolineas);
				xPrecioAerolineaBitcoinForzado = precioConBitcoin(precioForzadoAerolineas);
				xPrecioAerolineaKmForzado = precioPorKm(kilometroForzado,precioForzadoAerolineas);
				xPrecioAerolineaDiferenciaForzado = preciosConDiferencia(precioForzadoAerolineas,preciosForzadoLatam);

				printf("KMS ingresados: %.2f", xKilometroForzado);
				printf("\n Latam: %.2f",xPrecioForzadoLatam);
				printf("\n Precio con tarjeta de débito: %.2f",xPrecioLatamDebitoForzado);
				printf("\n Precio con tarjeta de crédito: %.2f",xPrecioLatamCreditoForzado);
				printf("\n Precio pagando con bitcoin: %.11f BTC",xPrecioLatamBitcoinForzado);
				printf("\n Precio unitario: %f",xPrecioLatamKmForzado);

				printf("\n\n Aerolinea: %.2f",xPrecioforzadoAerolinea);
				printf("\n Precio con tarjeta de débito: %.2f",xPrecioAerolineaDebitForzadoo);
				printf("\n Precio con tarjeta de crédito: %.2f",xPrecioAerolineaCreditoForzado);
				printf("\n Precio pagando con bitcoin: %.11f BTC",xPrecioAerolineaBitcoinForzado);
				printf("\n Precio unitario: %f",xPrecioAerolineaKmForzado);
				printf("\n La diferencia de precio es: %.2f\n",xPrecioAerolineaDiferenciaForzado);
				bandera5=1;
		     }//fin if

		     if(bandera1 == 1)
		     {
		    	printf("no se puede hacer los valores forzados ya que ingresaste kilometros\n");
		     }

		     if(bandera2 == 1)
		     {
		    	 printf("no se puede hacer los valores forzados ya que ingresaste un precio para Aerolineas y latam\n");
		     }

		     if(bandera3==1)
		     {
		    	 printf("no se puede hacer los valores forzados ya que calculaste las operaciones elegidas\n");
		     }

		     if (bandera4==1)
		     {
		    	 printf("no se puede hacer los valores forzados ya que mostraste las operaciones elegidas\n");
		     }
			 break;//fin case 5


			case 6:
			if (bandera1 == 0)
			{
				printf("\nseguro que quiere salir? ya que usted no ingreso kilometros");
			}

			if (bandera2 == 0)
			{
				printf("\nseguro que quiere salir? ya que usted no ingreso el precio de aerolineas y latam");
			}

			if (bandera3 == 0)
			{
				printf("\nseguro que quiere salir? ya que usted no realizo los calculos");
			}

			if (bandera4 == 0)
			{
				printf("\nseguro que quiere salir? ya que usted no informo los resultados");
			}

			if(bandera5==0)
			{
				printf("\nseguro que quiere salir? ya que usted no probo los valores forzados");
			}

			printf("\nSi desea seguir dentro del programa escriba s sino n: ");
			fflush(stdin);
			scanf("%c", &seguir);
			break; // fin del case 6

			default:
			printf("\nError solo puede ingresar un numero del 1 al 6 \n");
			fflush(stdin);
			break; // fin del default

		}//fin switch

		system("pause");

	}while (seguir == 's');// fin del do while

return 0;
}//fin main
