/*
 * status.h
 *
 *  Created on: 2 may. 2022
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

int cargarDescripcionStatus(eStatus status[], int tam, int id, char descripcion[]);
