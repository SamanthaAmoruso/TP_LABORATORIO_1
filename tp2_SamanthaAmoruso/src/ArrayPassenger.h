/*
 * ArrayPassenger.h
 *
 *  Created on: 17 abr. 2022
 *      Author: User
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float price;
	char flycode[10];
	int typePassenger; //1) menor, 2) adulto, 3) anciano
	int statusFlight; //1) activo, 2)cancelado, 3)demorado
	int isEmpty;

}ePasajero;

int menu();
/** @brief  Muestra el menu para la modificacion de pasajeros
 *
 * @return Devuelve un entero, el numero que se muestra en el menu de pasajeros
 */

int inicializarPasajeros(ePasajero* listaDePasajeros, int tam);
/**
 * @fn esta funcion inicializa al pasajero
 * @brief al inicializarlo ya sabemos que tenemos un pasajero en lista
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 1 si inicializo y 0 si no se pudo
 */

int buscarLibre(ePasajero* listaDePasajeros, int tam);
/**
 * @fn esta funcion hace la busqueda de un lugar libre para ingresar pasajeros
 * @brief busca si hay espacios libres para ingresar mas pasajeros
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @param el puntero a lugarlibre
 * @return i si encuentra libres y -1 si hubo error
 */

int buscarPasajero(ePasajero* listaDePasajeros, int tam, int identificador);
/**
 * @fn esta funcion busca un pasajero
 * @brief busca al pasajero
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @param el identificador de los pasajeros
 * @return i si pudo buscar el pasajero y -1 si hubo error
 */
int printPassengers(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams);
/**
 * @fn mostrar pasajeros
 * @brief muestra una lista con los pasajeros
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 1 si mostro la lista y 0 si hubo error
 */

int sonLetras(char cadena[]);
/**
 * @fn la funcion son letras marca si ingreso letras
 * @brief te confirma si lo ingresado son letras o numeros
 *
 * @param el char de cadena
 * return -1 si son letras y 1 si son numeros
 */

int addPassenger(ePasajero* listaDePasajeros, int tam, int* identificador, char nombre[], char apellido[], float precio, char codigoVuelo[], int tipoPasajero,  int statusVuelo);
/**
 * @fn esta funcion hace cargar a los pasajeros
 * @brief muestra una lista con los pasajeros que se cargaron
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @param el identificador de los pasajeros
 * @return -1 para el error, 0 todoOK
 */

int modificarPasajero(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams);
/**
 * @fn esta funcion modifica a los pasajeros
 * @brief muestra una lista con los pasajeros y busca el id del que sera modificado
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 1 si mostro la lista y -1 si hubo error
 */

int removePassenger(ePasajero* listaDePasajeros, int tam, eStatus status[], int tams);
/**
 * @fn baja pasajero
 * @brief da de baja al id seleccionado del pasajero
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return -1 el error, 0 todoOk
 */

int findPassengersById(ePasajero* listaDePasajeros, int tam, int id);
/**
 * @fn encontrar pasajeros por el id
 * @brief esta funcion recorre el array en busca del id del pasajero
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return -1 para el error, 0 esta todook
 */

int sortPassengers(ePasajero* listaDePasajeros, int tam, int orden);
/**
 * @fn ordena a los pasajeros alfabeticamente por apellido y por tipoPasajero
 * @brief esta funcion ordena alfabeticamente a los pasajeros segun lo solicitado.
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 1 si mostro la lista y 0 si hubo error
 */

int mostrarPrecios(ePasajero* listaDePasajeros, int tam);
/**
 * @fn muestra los precios de cada pasajero
 * @brief esta funcion muestra los salarios de todos los pasajeros ingresados.
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 0 si mostro la lista y 1 si hubo error
 */

float sumarPreciosYPromediar(ePasajero* listaDePasajeros, int tam);
/**
 * @fn suma los precios y los promedia
 * @brief esta funcion suma los salarios de los pasajeros y saca su promedio
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return promedio
 */

void superanPrecioPromedio(ePasajero* listaDePasajeros, int tam, float promedio);
/**
 * @fn muestra los que superan el precio promedio
 * @brief esta funcion muestra desde el promedio cuales pasajeros tienen un salario mejor al promedio
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return nada porque es void
 */

void mostrarTipoPasajero(int idTipoPasajero, char nombre[15]);
/**
 * @fn muestra los tipos de pasajeros
 * @brief Muestra la descripcion de los tipos de pasajeros
 *
 * @param El id del pasajero, un entero
 * @param un array de caracteres para guardar la descripcion
 *
 */

int sortPassengersByCode(ePasajero* listaDePasajeros, int tam,eStatus status[], int tams, int orden);
/**
 * @fn ordena a los pasajeros por codigo de vuelo y status activos
 * @brief esta funcion ordena asc o desc a los pasajeros segun lo solicitado.
 *
 * @param el array de lista de pasajeros
 * @param  el tamaño del array de pasajeros
 * @return 1 si mostro la lista y 0 si hubo error
 */

void printPassenger(ePasajero unPasajero, int tam, eStatus status[], int tams);
/**
 * @fn mostrar pasajero
 * @brief muestra un pasajero
 *
 * @param el array de lista de pasajero
 * @param  el tamaño del array de pasajero
 * @return 1 si mostro la lista y 0 si hubo error
 */

#endif /* ARRAYPASSENGER_H_ */
