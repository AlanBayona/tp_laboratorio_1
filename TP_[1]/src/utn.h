/*
 * utn.h
 *
 *  Created on: 24 sep. 2021
 *      Author: alanb
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError);
int sumarFlotante(float numero_uno, float numero_dos);
float restarFlotante(float uno, float dos);
float multiplicarFlotante(float uno, float dos);
float factorizarFlotante(float num_variable);
int divirFlotante(float* pResultado, float dividiendo, float divisor);

#endif /* UTN_H_ */
