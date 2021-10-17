/*
 * Inputs.h
 *
 *  Created on: 11 oct 2021
 *      Author: cesar
 */

#ifndef INPUTS_H_
#define INPUTS_H_




int myGets(char cadena[], int len);
int pedirTipoInt(int* pResultado, char* mensaje, char* mensajeError, int  minimo, int maximo, int reintentos);
int pedirTipoFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int pedir_texto(char cadenaDeCaracteres[], char* mensaje, int reintentos);
int pedirDireccion(char cadenaDeCaracteres[], char* mensaje, char mensajeError, int reintentos);
int pedirCorreo(char cadenaDeCaracteres[], char* mensaje, char mensajeError, int reintentos);



#endif /* INPUTS_H_ */
