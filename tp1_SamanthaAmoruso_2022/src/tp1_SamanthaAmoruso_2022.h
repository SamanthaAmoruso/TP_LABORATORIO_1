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

/** @brief muestra los kilometros
 *
 * @return devuelve los kilometros que se puso
 */
float totalKm(float kilometros);

/** @brief muestra el precio de aerolinea con descuento
 *
 * @return devuelve el descuento de la aerolinea
 */
float precioConDebito(float precio);

/** @brief muestra el precio de aerolinea con aumento del 25
 *
 * @return devuelve el aumento de la aerolinea
 */
float precioConCredito(float precio);

/** @brief muestra el valor unitario de la aerolinea
 *
 * @return devuelve el valor unitario
 */
float precioPorKm(float precio, float kilometros);

/** @brief muestra el valor de la aerolinea pagada el btc
 *
 * @return devuelve lo que vale en btc
 */
float precioConBitcoin(float precio);


//-------------------------------------------------------//
float precioTotalLatam(float precioLatam);

float precioLatamDebito(float precioLatam);

float precioLatamCredito(float precioLatam);

float precioLatamPorKm(float precioLatam, float kilometros);

float precioLatamBitcoin(float precioLatam);

float preciosConDiferencia(float precioAerolineas, float precioLatam);

//---------------------------------------------//

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

float precioTotal(float precio);
/** @brief muestra el precio de aerolinea/latam/forzado
 *
 * @return devuelve el precio de correspondiente.
 */
