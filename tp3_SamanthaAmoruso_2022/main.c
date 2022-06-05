#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "funciones.h"

int main()
{
	setbuf(stdout,NULL);
	int resultado = 0;
	char seguir;

    LinkedList* pArrayListPassenger = ll_newLinkedList();

    do{

        switch(menuOpciones())
        {
            case 1:
            	resultado = controller_loadFromText("data.csv", pArrayListPassenger);
				if(resultado == 1)
				{
					printf("Archivo cargado con exito\n");
				}
				else
				{
					printf("Error en la carga del archivo\n");
				}
            break;

            case 2:
            	resultado = controller_loadFromBinary("dataBIN.bin",pArrayListPassenger);
				if(resultado == 1)
				{
				   printf("Archivo cargado con exito\n");
				}
				else
				{
				   printf("Error en la carga del archivo\n");
				}
            break;

            case 3:
            	resultado = controller_addPassenger(pArrayListPassenger);
				if(resultado == 1)
				{
				   printf("pasajero agregado\n");
				}
				else
				{
				   printf("Error al agregar el pasajero\n");
				}
            break;

            case 4:
            	resultado = controller_editPassenger(pArrayListPassenger);
				if(resultado == 1)
				{
					printf("pasajero editado\n");
				}
				else
				{
					printf("Error al editar el pasajero\n");
				}
            break;

            case 5:
            	resultado = controller_removePassenger(pArrayListPassenger);
				if(resultado == 1)
				{
					printf("pasajero eliminado de la lista\n ");
				}
				else
				{
				   printf("Error, no se pudo eliminar el pasajero\n");
				}
            break;

            case 6:
            	resultado = controller_ListPassenger(pArrayListPassenger);
				if(resultado != 1)
				{
				  printf("No se puede mostrar la lista\n");
				}
            break;

            case 7:
            	resultado = controller_sortPassenger(pArrayListPassenger);
				controller_ListPassenger(pArrayListPassenger);
				//if(resultado != 1)
				//{
				  // printf("Error al ordenar la lista\n");
				//}
            break;

            case 8:
            	resultado = controller_saveAsText("data.csv",pArrayListPassenger);
				if(resultado == 1)
				{
				  printf ("Archivo guardado con exito\n");
				}
				else
				{
				  printf("Error en el guardado del archivo\n");
				}
            break;

            case 9:
            	resultado = controller_saveAsBinary("dataBIN.bin",pArrayListPassenger);
				if(resultado == 1)
				{
				   printf("Archivo guardado con exito\n");
				}
				else
				{
					printf("Error en el guardado del archivo\n");
				}
            break;

            case 10:
            	printf("Si desea seguir escribe S sino N: \n");
				fflush(stdin);
				scanf("%c", &seguir);
            break;

            default:
            	printf("opcion equivocada, elija una opcion del 1 al 10: \n");
			break;

        }//FIN SWTICH

    }while (seguir!='n');//fin del while

    ll_deleteLinkedList(pArrayListPassenger);

return 0;
}//fin main

