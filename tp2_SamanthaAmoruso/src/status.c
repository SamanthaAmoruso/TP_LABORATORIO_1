/*
 * status.c
 *
 *  Created on: 2 may. 2022
 *      Author: User
 */

#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listarStatus(eStatus status[], int tam)
{
	int todoOk = 0;

	if (status != NULL && tam > 0)
	{
		printf("   *** Lista de Sectores  ***\n");
		printf("  Id    Descripcion\n");
		printf("-----------------------\n");
		for (int i = 0; i < tam; i++)
		{
			printf("   %4d    %10s\n", status[i].id, status[i].descripcion);
		}
		printf("\n\n");

		todoOk = 1;
	} //fin if
	return todoOk;
}

int cargarDescripcionStatus(eStatus status[], int tam, int id,char descripcion[])
{
	int todoOk = 0;

	if (status != NULL && tam > 0 && id >= 1 && id <= 3 && descripcion != NULL)
	{
		for (int i = 0; i < tam; i++)
		{

			if (status[i].id == id)
			{
				strcpy(descripcion, status[i].descripcion);
				break;
			}

		} //fin for

		todoOk = 1;

	} //fin if
	return todoOk;
}
