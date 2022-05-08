/*
 * status.h
 *
 *  Created on: 1 may. 2022
 *      Author: User
 */

#ifndef STATUS_H_
#define STATUS_H_

typedef struct
{
	int id;
	char descripcion[20];
	int isEmpty;
}eStatus;


#endif /* STATUS_H_ */

int listarStatus(eStatus status[], int tam);
/**
 * @fn mostrar status de vuelo
 * @brief muestra una lista con los status de vuelo
 *
 * @param el array de lista de status
 * @param  el tamaño del array de status
 * @return 1 si mostro la lista y 0 si hubo error
 */

int cargarDescripcionStatus(eStatus status[], int tam, int id, char descripcion[]);
/** @brief Carga en una cadena de caracteres el nombre del status
 *
 * @param El array de la aerolinea
 * @param Un entero, el tamaño del array de la aerolinea
 * @param Un entero, el numero de id del pasajero
 * @param La cadena de caracteres donde se escribe el nombre del status de vuelo
 *
 */
