/*
 * tp1_SamanthaAmoruso_2022.h
 *
 *  Created on: 3 abr. 2022
 *      Author: User
 */

#ifndef TP1_SAMANTHAAMORUSO_2022_H_
#define TP1_SAMANTHAAMORUSO_2022_H_

#endif /* TP1_SAMANTHAAMORUSO_2022_H_ */

#include <stdio.h>
#include <stdlib.h>


/** @brief  Muestra el menu
 *
 * @return Devuelve un entero, el numero que se muestra en el menu de la calculadora
 */
int menu();

float totalKm(float kilometros);

float precioTotalAerolineas(float precioAerolineas);

float precioAerolineasDebito(float precioAerolineas);

float precioAerolineasCredito(float precioAerolineas);

float precioAerolineasPorKm(float precioAerolineas, float kilometros);

float precioAerolineasBitcoin(float precioAerolineas);

float precioTotalLatam(float precioLatam);

float precioLatamDebito(float precioLatam);

float precioLatamCredito(float precioLatam);

float precioLatamPorKm(float precioLatam, float kilometros);

float precioLatamBitcoin(float precioLatam);

float precioAerolineasDiferenciaPrecio(float precioAerolineas, float precioLatam);




float totalKmFozado(float kilometroForzado);

float precioForzadoLatam(float preciosForzadoLatam);

float precioLatamDebitoForzado(float preciosForzadoLatam);

float precioLatamCreditoForzado(float preciosForzadoLatam);

float precioLatamPorKmForzado(float preciosForzadoLatam, float kilometroForzado);

float precioLatamBitcoinForzado(float preciosForzadoLatam);

//----------------------------------------//

float precioForzadoAerolinea(float precioForzadoAerolineas);

float precioAerolineasDebitoForzado(float precioForzadoAerolineas);

float precioAerolineasCreditoForzado(float precioForzadoAerolineas);

float precioAerolineasPorKmForzado(float precioForzadoAerolineas, float kilometroForzado);

float precioAerolineasBitcoinForzado(float precioForzadoAerolineas);

float precioAerolineasDiferenciaPrecioForzado(float precioForzadoAerolineas, float preciosForzadoLatam);

int sonLetras(char cadena[]);
/**
 * @fn funcion son letras marca si ingreso letras
 * @brief te confirma si lo ingresado son letras o numeros
 *
 * @param el char de cadena
 * return -1 si son letras y 1 si son numeros
 */
