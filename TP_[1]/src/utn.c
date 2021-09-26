/*
 * utn.c
 *
 *  Created on: 24 sep. 2021
 *      Author: alanb
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * Cambie la funcion que nos dieron en clase.
 * hace casi lo mismo, esta es algo menos compleja.
 * */
int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError)
{
	//hace lo mismo que la funcion que se dio en clases, pero no queria un limite de numeros
	int retorno;
	float flotante_ingresado;
	retorno=-1;

	//para mostrar una falla usare un -1
	while(retorno==-1)
	{
			if(pResultado!=NULL && mensaje!= NULL && mensajeError != NULL)
			{
			printf("%s", mensaje);
			scanf("%f", &flotante_ingresado);
			if(flotante_ingresado>=0 || flotante_ingresado<=0)
			{
				*pResultado=flotante_ingresado;
				//Use un cero como valor de confirmacion de que todo esta bien.
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


/*
 * Funcion que utilizo para sumar, muy simple
 * */

int sumarFlotante(float numero_uno, float numero_dos)
{
	float resultado;

		resultado= numero_uno + numero_dos;

	return resultado;
}

/*
 * la funcion que uso para restar.
 * */

float restarFlotante(float uno, float dos)
{
	float resolucion;

	resolucion = uno - dos;

	return resolucion;
}

/*
 * el numero ingresado debe ser positivo y !=0
 * o mejor dicho   x > 1
 * */
float factorizarFlotante(float num_variable)
{
	//inicialice en 1 para evitar hacer un calculo en vano
	float resultado=1;
	//de esta manera no entrara. posterior puse una condicion para los ceros.
	//esta en el main.
	 while(num_variable >1)
	 {
		resultado*=num_variable;
		num_variable--;
	 }

	 return resultado;
}


/*
 * la funcion solo retornara el resultado, sin alguna validacion.
 *  El unico problema que tendria seria cuando ingrese un valor diferente
 *  de un number.
 * */
float multiplicarFlotante(float uno, float dos)
{
	int resultado;

	resultado=uno * dos;

	return resultado;
}

/*
 *	En esta funcion fue creada solo para la calculadora.
 *
 *	va a retornar la informacion de si la situacion esta bien o esta mal
 * */

int divirFlotante(float* pResultado, float dividiendo, float divisor)
{//si el dato del resultado es de tipo float debe ir el tipo como float aca.
	int informacion;
	float resolucion;
	//recuerda que debes poner una variables
	//compruebo si la operacion hay un cero dividiendo.
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
