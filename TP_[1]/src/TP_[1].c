/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"

#define ESPACIO  6

int main(void) {
	setbuf(stdout, NULL);
	float operador_unoDeIngreso;
	float operador_dosDeIngreso;
	int opcion;
	float division;
	float todosLosResultados[ESPACIO];

	do{
	puts("\n =========== BIENVENIDO A LA CALCULADORA DE ALAN UwU ===========");
	puts("*                                                              *");
	printf("*---------------\t\tMENU\t\t---------------*\n");
	puts("* OPCIONES:                                                    *");
	puts("*  1. Ingresar 1er operando                                    *");
	puts("*\t2. Ingresar 2do operando                               *");//un \t equivale a 7 asteriscos(*)
	puts("*\t\t3. Calcular todas las operaciones              *");
	puts("*\t\t\t4. Informar resultados                 *");
	puts("************************ ..:5) Salir:.. ************************");
	scanf("%d", &opcion);

	switch (opcion)
	{
		case 1:
			if( utn_getFlotante(&operador_unoDeIngreso, "Ingrese el primer operando: ", "ERROR. Intente de nuevo. ")==0)
			{
				printf("\nOperador guardado y es el: %f", operador_unoDeIngreso);
				printf("\nVolviendo al MENU de incio....");
			} else {
				printf("\nParametros ingresados mal. VOLVIENDO AL MENU DE INCIO.");
			}
			break;
		case 2:
			if( utn_getFlotante(&operador_dosDeIngreso, "Ingrese el segundo operando: ", "ERROR. Intente de nuevo. ")==0)
						{
							printf("\nOperador guardado y es el: %f", operador_dosDeIngreso);
							printf("\nVolviendo al MENU de incio....");
						} else {
							printf("\nParametros ingresados mal. VOLVIENDO AL MENU DE INCIO.\n");
						}
						break;
		case 3:
			/*if(operador_unoDeIngreso != && operador_dosDeIngreso!=NULL)
			{
				puts("Operandos incompletos. recuerde ingresarlos.");
				break;
			} else
			{*/
				todosLosResultados[0]=sumarFlotante(operador_unoDeIngreso, operador_dosDeIngreso);
				todosLosResultados[1]=restarFlotante(operador_unoDeIngreso, operador_dosDeIngreso);
				todosLosResultados[2]=multiplicarFlotante(operador_unoDeIngreso, operador_dosDeIngreso);
					if(operador_unoDeIngreso > 0 && operador_dosDeIngreso > 0 )
					{
					todosLosResultados[4]=factorizarFlotante(operador_unoDeIngreso);
					todosLosResultados[5]=factorizarFlotante(operador_dosDeIngreso);
					} else {
					todosLosResultados[4]=0;
					todosLosResultados[5]=0;
					}

				if(divirFlotante(&division, operador_unoDeIngreso, operador_dosDeIngreso)==1)
				{
					todosLosResultados[3]=division;
				}
				break;
		//	}
		case 4:
			puts("Los resultados son:");
			for(int i=0; i<=5; i++){
				if(i==0){
					printf("Suma: %f\n", todosLosResultados[i]);
				} else if(i==1){
					printf("Resta: %f\n", todosLosResultados[i]);
				} else if(i==2){
					printf("Multiplicacion: %f\n", todosLosResultados[i]);
				} else if(i==3 && divirFlotante(&division, operador_unoDeIngreso, operador_dosDeIngreso)==1){
					printf("Division: %f\n", todosLosResultados[i]);
				} else if(i==4 && operador_unoDeIngreso !=0){
					printf("Factorizacion del 1er operando es: %f\n", todosLosResultados[i]);
				} else if(i==5 && operador_dosDeIngreso !=0){
					printf("Factorizacion del 2do operando es: %f\n", todosLosResultados[i]);
				} else {
					puts("NO SE PUDO FACTORIZAR");
				}

			}
			break;





	}

	}while(opcion!=5);
	printf("Adios!");
	return EXIT_SUCCESS;
}

