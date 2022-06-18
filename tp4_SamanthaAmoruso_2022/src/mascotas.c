#include "mascotas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMascotas(LinkedList* list)
{
   int tam;
   if(list != NULL)
   {
       tam = ll_len(list);
       printf(" ID NOMBRE SEXO EDAD-------\n");
       for(int i= 0; i < tam; i++)
       {
          mostrarMascota((eMascota*) ll_get(list,i));
       }
       printf("\n");
   }
}

void mostrarMascota(eMascota* m)
{
    if(m != NULL)
    {
        printf("%d  %10s  %c %d\n", m->id, m->nombre, m->sexo, m->edad);
    }
}

int filterHembras(void* pElement)
{
    int retorno = 0;
    eMascota* auxiliar = NULL;
    auxiliar = (eMascota*) pElement;
    if(auxiliar->sexo == 'h')
    {
        retorno = 1;
    }
    return retorno;
}

int filterCachorros(void* pElement)
{
    int retorno = 0;
    eMascota* auxiliar = NULL;
    auxiliar = (eMascota*) pElement;
    if(auxiliar->edad < 2)
    {
        retorno = 1;
    }
    return retorno;
}

int mascota_CompareByEdad(void* m1, void* m2)
{
    int resultado;
    eMascota* auxiliar1 = NULL;
    eMascota* auxiliar2 = NULL;

    if(m1 != NULL && m2 != NULL)
    {
       auxiliar1 = (eMascota*) m1;
       auxiliar2 = (eMascota*) m2;
       if(auxiliar1->edad > auxiliar2->edad)
    {
        resultado = 1;
    }
    else
    {
        if(auxiliar1->edad < auxiliar2->edad)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

