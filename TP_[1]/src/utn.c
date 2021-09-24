/*
 * utn.c
 *
 *  Created on: 24 sep. 2021
 *      Author: alanb
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError)
{
	int retorno;
	float flotante_ingresado;
	retorno=-1;


	while(retorno==-1)
	{
			if(pResultado!=NULL && mensaje!= NULL && mensajeError != NULL)
			{
			printf("%s", mensaje);
			scanf("%f", &flotante_ingresado);
			if(flotante_ingresado>=0 || flotante_ingresado<=0)
			{
				*pResultado=flotante_ingresado;
				retorno=0;
				break;
			}else
			{
				printf("%s", mensajeError);
				break;
			}
		}
	}

	return retorno;
}

int sumarFlotante(float numero_uno, float numero_dos)
{
	float resultado;

		resultado= numero_uno + numero_dos;

	return resultado;
}

float restarFlotante(float uno, float dos)
{
	float resolucion;

	resolucion = uno - dos;

	return resolucion;
}

float factorizarFlotante(float num_variable)
{

	float resultado=1;
	 while(num_variable >1)
	 {
		resultado*=num_variable;
		num_variable--;
	 }

	 return resultado;
}

float multiplicarFlotante(float uno, float dos)
{
	int resultado;

	resultado=uno * dos;

	return resultado;
}

int divirFlotante(float* pResultado, float dividiendo, float divisor)
{//si el dato del resultado es de tipo float debe ir el tipo como float aca.
	int informacion;
	float resolucion;
	//recuerda que debes poner una variables
	if(divisor==0){
		informacion=-1;
	} else {
	resolucion= dividiendo / divisor;
	(*pResultado)=resolucion;//recuerda que debo hacer este proceso
	//tendre que averiguar si se puefe jugar con la sintaxis
	informacion=1;
	}
	return informacion;

}
