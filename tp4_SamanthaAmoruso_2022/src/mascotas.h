#include "../inc/LinkedList.h"
//#include "linkedList.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct{
          int id;
          char nombre[20];
          char sexo;
          int edad;
}eMascota;

void mostrarMascotas(LinkedList* list);
void mostrarMascota(eMascota* m);
int filterHembras(void* pElement);
int filterCachorros(void* pElement);
int mascota_CompareByEdad(void* m1, void* m2);

#endif // MASCOTA_H_INCLUDED
