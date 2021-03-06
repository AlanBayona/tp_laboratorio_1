/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "ArrayEmployees.h"

#define LEN 1000
#define INTENTOS 999


int main(void) {
	setbuf(stdout, NULL);
	int option;
	int contadorAux;
	float promedioSalario;
	float salarioTotal;
	int idAux;
	Employee employeesList[LEN]={{12,"Alan","Auget",3.1415,4,1},{13,"Hobbs","Maru",30.9,2,1}};
	initEmployees(employeesList, LEN);

	do{

		seeMenu();

		pedirTipoInt(&option, "\n", "Opcion invalida", 0, 6, INTENTOS);

		switch(option)
		{
		case 1:

			if(addEmployeesAux(employeesList, LEN)==0)
			{
				puts("Guardando...");
			}
			break;
		case 2:
			if(verificarSiArrayEstaVacio(employeesList, LEN)<0)
			{
				puts("Maquina por aca me avisan que no ingresaste nada.");
				puts("Asi que, para el lobby...");
				break;
			}
			else
			{
				printEmployees(employeesList, LEN);
				if(pedirTipoInt(&idAux, "Elija el ID del empleado que desee modificar", "DEJE DE TRATAR DE BUGGEARME!!", 0, 1000000, 3)==0)
				{
					if(pedirTipoInt(&option, "\tBienvanido a modificar campos.\n1-MOD: nombre/name\n2-MOD: Apellido/lastName\n3-MOD: Salario/salary\n4-MOD:Sector\nSALIR- USE: 5\n", "OPCION INVALIDA", 0, 6, 2)==0)
					{
						if(modifyEmployeebyId(employeesList, LEN, idAux, option)!=0)
						{
							if(option==5)
							{
								puts("Regresando al menu principal");
								option=0;
							}
							else
							{
								puts("Intentos agotados.");
								puts("Volviendo al menu....");

							}
						}
						else
						{
							printf("El empleado con el ID: %d. Fue actualizado", idAux);
						}

					}
				}
			}
			break;
		case 3:
						if(verificarSiArrayEstaVacio(employeesList, LEN)<0)
						{
							puts("Maquina por aca me avisan que no ingresaste nada.");
							puts("Asi que, para el lobby...");
							break;
						}
						else
						{
							printEmployees(employeesList, LEN);
							if(pedirTipoInt(&idAux, "Elija el ID del empleado que desee modificar", "DEJE DE TRATAR DE BUGGEARME!!", 0, 1000000, 3)==0)
							{
								if(removeEmployee(employeesList, LEN, idAux)==0)
								{
									puts("La baja del empleado se realizo con exito");
								}
								else
								{
									printf("EL ID: %d ya no existe",idAux);
								}
							}
						}
			break;
		case 4:

			if(verificarSiArrayEstaVacio(employeesList, LEN)<0)
			{
				puts("Maquina por aca me avisan que no ingresaste nada.");
					puts("Asi que, para el lobby...");
						break;
			}
			else
			{
					if(pedirTipoInt(&option, "\tInforme\n1-Lista de empleados en orden alfabetico y por sector.\n2-Informe de salarios\n", "DEJE DE BUSCAR ERRORES", 0, 3, 1)==0)
					{
						if(option==1)
						{
							if(employee_ordenarPorNombre(employeesList, LEN)==0)
							{
								printEmployees(employeesList, LEN);
							}
						}
						else if(option==2)
						{
							contadorAux=contadorDeSalarios(employeesList, LEN);
							salarioTotal=acumuladorDeSalarios(employeesList, LEN);
							promedioSalario=salarioTotal / contadorAux;
							printf("Total del salario es: %f\n", salarioTotal);
							printf("Promedio del salario: %f\n", promedioSalario);
							printf("Cantidad de empleados que supera el promedio son: %d", contadorDeSueldosFueraDelPromedio(employeesList, LEN, promedioSalario));
						}
					}
			}
			break;
		case 5:
			puts("\nADIOS");
			break;

	printEmployees(employeesList, LEN);

		}

	}while(option!=5);

	return EXIT_SUCCESS;
}
