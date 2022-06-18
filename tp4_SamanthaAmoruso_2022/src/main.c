/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "mascotas.h"

int main(void)
{
	setbuf(stdout,NULL);

	eMascota mascota1 = {1264,"Marquitos",'m',2};
	eMascota mascota2 = {1123,"Lucrecia",'h',1};
	eMascota mascota3 = {1866,"Anastacia",'h',5};
	eMascota mascota4 = {1312,"Cinthia",'h',10};
	eMascota mascota5 = {1942,"Milo",'m',6};
	eMascota mascota6 = {1614,"Sebastian",'m',1};

	int tam;
	int isEmpty;
	eMascota* puntero;
	int indice;
	int auxiliar;

	LinkedList* lista = ll_newLinkedList();

	ll_add(lista,&mascota1);
	ll_add(lista,&mascota2);
	ll_add(lista,&mascota3);
	ll_add(lista,&mascota4);
	ll_add(lista,&mascota5);
	ll_add(lista,&mascota6);

    tam= ll_len(lista);
	printf("---- Uso de ll_len ----\n");
	printf("Me devuelve el tamanio de la lista\n");
	printf("Tengo %d perros\n", tam);
	printf("\n");

	printf("---- Uso de ll_get ----\n");
	printf("Dentro de la funcion mostrar uso get para tomar cada elemento\n");
	mostrarMascotas(lista);
	printf("\n");

	LinkedList* hembras = ll_filter(lista,filterHembras);
	printf("---- Uso de ll_filter ----\n");
	printf("Uso la funcion filter para devolver una lista de los elementos que cumplan una condicion, en este caso, hembras\n");
	mostrarMascotas(hembras);
	printf("\n");

	ll_remove(lista,1);
	printf("---- Uso de ll_remove ----\n");
	printf("Saco el elemento del indice 1 de la lista\n");
	mostrarMascotas(lista);
	printf("\n");

	puntero = &mascota1;
	indice =  ll_indexOf(lista,puntero);
	printf("---- Uso de ll_indexOf ----\n");
	printf("Determina el indice donde esta ubicado un elemento en la lista\n");
	printf("El indice donde esta marquitos es %d \n ", indice);
	auxiliar = ll_contains(lista,puntero);
	printf("\n");

	printf("---- Uso de ll_contains ----\n");
	printf("Determino si la lista contiene un elemento\n");
	printf("La lista contiene a marquitos, entonces el valor q devuelve contains es %d \n ", auxiliar);
	printf("\n");

	isEmpty = ll_isEmpty(lista);
	printf("--- Uso de ll_isEmpty ----\n");
	printf("Deterimno si la lista esta vacia, o no lo esta\n");
	printf("El valor de isEmpty es %d porque la lista no esta vacia\n ", isEmpty);
	printf("\n");

	LinkedList* sublista = ll_subList(lista,1,3);
	printf("---- Uso de ll_sublist ----\n");
	printf("Creo una sublista con solo los elementos entre los indices 1 y 3\n");
	mostrarMascotas(sublista);
	printf("\n");

	printf("---- Uso de ll_containsAll ----\n");
	auxiliar = ll_containsAll(lista,sublista);
	printf("Determino si una lista esta incluida en otra\n");
	printf("El valor de containsAll es %d porque la sublista esta incluida en la lista\n ", auxiliar);
	printf("\n");

	LinkedList* listaClon = ll_clone(lista);
	printf("---- Uso de ll_clone ----\n");
	printf("Creo una lista clon de otra\n");
	mostrarMascotas(listaClon);
	printf("\n");

	ll_sort(lista,mascota_CompareByEdad,1);
	printf("---- Uso de ll_sort ----\n");
	printf("Ordeno la lista, en este caso por la edad y en forma descendente\n");
	mostrarMascotas(lista);
	eMascota mascota7 = {1327,"claudio",'m',8};
	puntero = &mascota7;
	ll_push(lista,4,puntero);
	printf("\n");

	printf("---- Uso de ll_push ----\n");
	printf("Agrego un elemento en la lista, en el indice 4\n");
	mostrarMascotas(lista);
	ll_pop(lista,4);
	printf("\n");

	printf("---- Uso de ll_pop ----\n");
	printf("Saco un elemento de la lista, del indice 4\n");
	mostrarMascotas(lista);
	printf("\n\n");

	ll_set(lista,0,puntero);
	printf("---- Uso de ll_set ----\n");
	printf("Reemplazo el elemento que estaba en el indice 0 por el nuevo elemento\n");
	mostrarMascotas(lista);
	ll_clear(lista);
	isEmpty = ll_isEmpty(lista);
	printf("---- Uso de ll_clear ----\n");
	printf("El valor de isEmpty es %d porque la lista ahora esta vacia\n ", isEmpty);

	ll_deleteLinkedList(lista);

	//startTesting(1);  // ll_newLinkedList
	//startTesting(2);  // ll_len
	//startTesting(3);  // getNode - test_getNode
	//startTesting(4);  // addNode - test_addNode
	//startTesting(5);  // ll_add
	//startTesting(6); // ll_get
	//startTesting(7);  // ll_set
	//startTesting(8);  // ll_remove
	//startTesting(9);  // ll_clear
	//startTesting(10); // ll_deleteLinkedList
	//startTesting(11); // ll_indexOf
	//startTesting(12); // ll_isEmpty
	//startTesting(13); // ll_push
	//startTesting(14); // ll_pop
	//startTesting(15); // ll_contains
	//startTesting(16); // ll_containsAll
	//startTesting(17); // ll_subList
	//startTesting(18); // ll_clone
	//startTesting(19); // ll_sort

return 0;
}

