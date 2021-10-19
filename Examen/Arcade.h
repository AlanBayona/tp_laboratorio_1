/*
 * Arcade.h
 *
 *  Created on: 19 oct. 2021
 *      Author: alanb
 */

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct{
		char nacionalidad[51];
		int sonido;
		int cant_jugadores;
		int fichasMaxima;
		int idSalon;
		char nombreDelJuego[51];
		int id;
		int isEmpty; //0=libre 1=ocupado

} eArcade;






//funcion de inicio
int initArcade(eArcade listado[], int len);//completa


//funciones de ALTA
int validarId(eSalon list[], int len, int id);//completa
int agregarArcade(eArcade list[], eSalon listado[], int lenSalon, int lenArcade);// completa

//funciones de modificacion
int imprimirArrayArcade(eArcade list[], int len);
int imprimirSoloArrayArcades(eArcade list[], int len);

//BAJA
int removerArcade(eArcade list[], int lenArcade);


#endif /* ARCADE_H_ */
