#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#include <ctype.h>

int esEntero(float A)
{
   int X;
   int esEntero;

   X=A;
   if(A-X==0)
   {
       esEntero = 1;
   }
    else
    {
        esEntero = 0;
    }
    return esEntero;
}

int validacionDeNumero(int numero,int minimo, int maximo)
{
    int i;

    i=numero;

    while(minimo>numero||numero>maximo)
    {
        printf("Error, numero fuera de rango, reingresar: ");
        scanf("%d",&i);
        numero = i;
    }

    return i;
}

char validacionDeLetra(char letra, char maximo, char minimo)
{
    int auxLetra;
    int auxMaximo;
    int auxMinimo;

    auxLetra = letra;
    auxMaximo = maximo;
    auxMinimo = minimo;

    while(auxMinimo>auxLetra||auxLetra>auxMaximo)
    {
        printf("Error, la letra no es la correcta, Reingresar: ");
        fflush(stdin);
        scanf("%c",&letra);
        auxLetra = letra;
    }
    return auxLetra;
}

int obtenerNumero(char mensaje[])
{
    int numero;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

char obtenerCaracter(char mensaje[])
{
    char caracter;

    printf("%s", mensaje);
    scanf("%c",&caracter);
    return caracter;
}

int obtenerCadena(char mensaje[],char cadena[])
{
    char string[30];

    printf("%s: ",mensaje);
    fflush(stdin);
    fgets(string,50,stdin);
    strtok(string,"\n");
    fflush(stdin);
    for(int i=0;i<50;i++)
        {
            if((string[i]== '0'||string[i]== '1'||string[i]== '2'||string[i]== '3'||string[i]== '4'||string[i]== '5'||string[i]== '6'
               ||string[i]== '7'||string[i]== '8'||string[i]== '9'))
            {
                printf("el string contiene numeros\n");
                return 0;
            }
        }
    strcpy(cadena,string);
    return 1;
}


int menuOpciones()
{
    int opcion;

    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de pasajero\n");
    printf("4. Modificar datos de pasajero\n");
    printf("5. Baja de pasajero\n");
    printf("6. Listar pasajero\n");
    printf("7. Ordenar pasajero\n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
    printf("10.Salir \n");
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\nIngrese Una Opcion: ");
	scanf("%d", &opcion);

return opcion;
}


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
}
