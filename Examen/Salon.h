/*
 * Salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: alanb
 */

#ifndef SALON_H_
#define SALON_H_

typedef struct{
	char nombre[51];
	char direccion[51];
	int tipo;
	int id;
	int isEmpty;//0=vacio && 1=ocupado


}eSalon;


int buscarSalonVacio(eSalon list[], int len);
int buscarPorId(eSalon list[], int len,int id);
int imprimirArraySalones(eSalon list[], int len);//perteneciente al punto 3
int verificarSalones(eSalon list[], int len);

//funciones de Alta
int initSalon(eSalon list[], int len);
int agregarSalon(eSalon list[], int len);


//funciones de la modificacion

//funciones de la BAJA
int removerSalon(eSalon list[], int len);


#endif /* SALON_H_ */
