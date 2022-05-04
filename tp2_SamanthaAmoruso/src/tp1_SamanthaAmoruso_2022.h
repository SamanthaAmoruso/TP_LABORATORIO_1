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

/**@fn float totalKm(float)
 * @brief muestra los kilometros
 *
 * @return devuelve los kilometros que se puso
 */
float totalKm(float kilometros);

/**@fn float precioConDebito(float)
 * @brief muestra el precio de aerolinea con descuento
 *
 * @return devuelve el descuento de la aerolinea
 */
float precioConDebito(float precio);

/**@fn float precioConCredito(float)
 * @brief muestra el precio de aerolinea con aumento del 25
 *
 * @return devuelve el aumento de la aerolinea
 */
float precioConCredito(float precio);

/**@fn float precioPorKm(float,float)
 * @brief muestra el valor unitario de la aerolinea
 *
 * @return devuelve el valor unitario
 */
float precioPorKm(float precio, float kilometros);

/**@fn float precioConBitcoin(float)
 * @brief muestra el valor de la aerolinea pagada el btc
 *
 * @return devuelve lo que vale en btc
 */
float precioConBitcoin(float precio);

/**@fn float precionConDiferencia(float,float)
 * @brief muestra la diferencia de precios entre vuelos
 *
 * @return devuelve la diferencia de precios.
 */
float preciosConDiferencia(float precioAerolineas, float precioLatam);

/**
 * @fn funcion son letras marca si ingreso letras
 * @brief te confirma si lo ingresado son letras o numeros
 *
 * @param el char de cadena
 * return -1 si son letras y 1 si son numeros
 */
int sonLetras(char cadena[]);

/**@fn esta funcion muestra el precio ingresado
 * @brief muestra el precio de aerolinea/latam/forzado
 *
 * @return devuelve el precio de correspondiente.
 */
float precioTotal(float precio);

