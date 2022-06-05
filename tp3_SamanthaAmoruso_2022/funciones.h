#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

/** \brief Valida si un numero flotante tiene coma (o es entero)
 *
 * \param Un numero float
 * \return Un entero, si es entero devuelve 1 y si tiene coma devuelve 0
 **/
int esEntero(float);

/** \brief Valida si un numero esta dentro de un rango
 *
 * \param Un entero, el numero a validar
 * \param Un entero, el valor maximo del rango
 * \param Un entero, el valor minimo del rango
 * \return Un entero, si el numero esta dentro del devuelve el numero
 **/
int validacionDeNumero(int numero,int maximo, int minimo);

/** \brief Valida si una variable de caracter esta dentro de un rango
 *
 * \param Un char, la letra
 * \param Un char, el valor maximo del rango
 * \param Un char, el valor minimo del rango
 * \return Un char devuelve la letra si esta dentro del rango
 **/
char validacionDeLetra(char letra, char maximo, char minimo);

/** \brief Muestra un mensaje, pide al usuario ingresar un numero y lo devuelve
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 * \return Un entero, el numero ingresado por el usuario
 **/
int obtenerNumero(char[]);

/** \brief Muestra un mensaje, pide al usuario ingresar un caracter y lo devuelve
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 * \return Un char, el que fue ingresado por el usuario
 **/
char obtenerCaracter(char[]);

/** \brief Obtiene una cadena y verifica que no tenga numeros
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 * \param Un puntero a char, donde se guarda lo ingresado por el usuario
 * \return Un entero, 0 si la cadena tiene numeros o 1 si no tiene numeros
 **/
int obtenerCadena(char mensaje[],char cadena[]);

/** \brief Muestra por pantalla un menu de opciones
 *
 * \return Devuelve la opcion elegida por el usuario
 **/
int menuOpciones();

/**
 * @fn la funcion son letras marca si ingreso letras
 * @brief te confirma si lo ingresado son letras o numeros
 *
 * @param el char de cadena
 * return -1 si son letras y 1 si son numeros
 */
int sonLetras(char cadena[]);


#endif /* FUNCIONES_H_ */
