/*
 * ArrayPassenger.h
 *
 *  Created on: 17 abr. 2022
 *      Author: User
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}ePasajero;


#endif /* ARRAYPASSENGER_H_ */

int menu();

int inicializarPasajeros(ePasajero listaDePasajeros[], int tam);

int buscarLibre(ePasajero listaDePasajeros[], int tam);

int buscarPasajero(ePasajero listaDePasajeros[], int tam, int identificador);

int printPassengers(ePasajero listaDePasajeros[], int tam);

int sonLetras(char cadena[]);

int addPassenger(ePasajero listaDePasajeros[], int tam, int* identificador, char nombre[], char apellido[], float precio, char codigoVuelo[], int tipoPasajero);

int modificarPasajero(ePasajero listaDePasajeros[], int tam);

int removePassenger(ePasajero listaDePasajeros[], int tam);

int findPassengersById(ePasajero listaDePasajeros[], int tam, int id);

int sortPassengers(ePasajero listaDePasajeros[], int tam, int orden);

int mostrarPrecios(ePasajero listaDePasajeros[], int tam);

float sumarPreciosYPromediar(ePasajero listaDePasajeros[], int tam);

void superanPrecioPromedio(ePasajero listaDePasajeros[], int tam, float promedio);


