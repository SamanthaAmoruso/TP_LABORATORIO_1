#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
/** \brief Crea un espacio en memoria dinámica para la estructura pasajero
 *
 * \return Puntero al pasajero
 **/

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellido,char* precio,char* tipoPasajeroStr,
		char* codigoVuelo);

/** \brief Crea un espacio en memoria dinámica para la estructura pasajero, pasandole los parámetros que quiero agregar
 *
 * \param Un puntero a char, el id
 * \param Un puntero a char,el nombre
 * \param Un puntero a char, tipoPasajero
 * \param Un puntero a char, el precio
 * \param Un puntero a char, el codigoVuelo
 * \param Un puntero a char, el apellido

 * \return Puntero al pasajero creado
 **/

void Passenger_delete(Passenger* p);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_CompareByName(void* pasajero1, void* pasajero2);
int Passenger_CompareById(void* pasajero1, void* pasajero2);
int Passenger_CompareByApellido(void* pasajero1, void* pasajero2);
int Passenger_CompareBycodigoDeVuelo(void* pasajero1, void* pasajero2);



#endif /* PASSENGER_H_ */
