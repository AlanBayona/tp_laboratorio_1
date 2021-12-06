/*
 * Employee.c
 *
 *  Created on: 8 oct 2021
 *      Author: cesar
 */
/*
int   id;
	char  name[51];
	char  lastName[51];
	float salary;
	int   sector;
	int   isEmpty;*/
#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"


int initEmployees(Employee list[], int len)
{
	int deteccion;
	deteccion=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			list[i].isEmpty=0;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}


//Funciones del ALTA


int addEmployee(Employee list[], int len, int id, char* name,char* lastName,float salary,int sector)
{
	int check;
	int index;
	check=-1;
	puts("Antes de las condiones");
	printf("\nDentro de addEMployee\n");
	if(list!=NULL && len>0 && id>=0 && name!=NULL && lastName!=NULL && salary>0 && sector>0)
	{
		printf("\nEntro\n");
		index=findEmpty(list, len);
		if(index>=0)
		{
			printf("\nIndex: %d\n", index);
			list[index].id=id;
			strncpy(list[index].lastName, lastName, 51);
			strncpy(list[index].name, name, 51);
			list[index].salary=salary;
			list[index].sector=sector;
			list[index].isEmpty=1;
			check=0;
		}
	}

	return check;
}








int addEmployeesAux(Employee listEmployee[], int len)
{
	int deteccion=-1;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int idAux;
	int index;
		if(listEmployee!=NULL && len>0)
		{puts("Ingreso hasta aca");
			if(pedir_texto(nameAux, "Ingrese el nombre del empleado que va ingresar\n", "ERROR. Ingrese un nombre", 3)==0)
			{
				if(pedir_texto(lastNameAux, "Ingrese el apellido del empleado\n", "ERROR. Que esta haciendo?", 3)==0)
				{
					if(pedirTipoFloat(&salaryAux, "Ingrese el salario del empleado\n", "ERROR. Use numero reales, porfavor", 0, 99999, 2)==0)
					{
						if(pedirTipoInt(&sectorAux, "Ingrese el sector del gil laburante.\n", "ERROR. Sector invalido\n", 0, 3, 2)==0)
						{
							if((idAux=crearId())>0)
							{
								index=findEmpty(listEmployee, len);
								if(index>=0)
								{
									deteccion=addEmployee(listEmployee, len, idAux, nameAux, lastNameAux, salaryAux, sectorAux);
								}
							}
						}
					}
				}
			}
		}

	return deteccion;
}




/*
 *brief Esta funcion cumple con el trabajo de imprimir
 * /param Recibe un array de la entidad Employee y el largo del vector.
 * return Devuelve un 0 si salio bien y un -1 si salio mal.
 */

int printEmployees(Employee list[], int len)
{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && len>0)
	{
		printf("\tLista del ID:\n");
		for(int i=0; i< len; i++)
		{
			if(list[i].isEmpty==1)
			{
				printf("* ID: %d\n", list[i].id);
				printf("\tName: %s\n",list[i].name);
				printf("\tLastName: %s\n",list[i].lastName);
				printf("\tSalary: %f\n",list[i].salary);
				printf("\tSector: %d\n",list[i].sector);
			}
		}
		deteccion=0;
	}

	return deteccion;
}




int verificarSiArrayEstaVacio(Employee list[], int len)
{
	int index;
	index=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				index=i;
				break;
			}
		}
	}



	return index;
}












int findEmpty(Employee list[], int len)
{
	int index;
	index=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				index=i;
				break;
			}
		}
	}



	return index;
}




//funciones Modificacion

int modifyEmployeebyId(Employee* list, int len, int id, int option)
{
	int check;
	int indexEmployee;
	char nombreAux[51];
	char apellidoAux[51];
	float salarioAux;
	int sectorAux;

	check=-1;


		if(list!=NULL && len>0)
		{
			indexEmployee=findEmployeeById(list, len, id);
			switch(option)
			{
			  case 1:
				 if(pedir_texto(nombreAux, "ingrese el nuevo nombre el empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee].name, nombreAux, 51);
				 }
				 else
				 {
					 check=-1;
				 }
				 break;
			  case 2:
				 if(pedir_texto(apellidoAux, "ingrese el nuevo apellido del empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee].lastName, apellidoAux, 51);
				 }
				 else
				 {
				 	 check=-1;
				 }
				 break;
			  case 3:
				  if(pedirTipoFloat(&salarioAux, "Ingrese le nuevo salario del empleado", "ERROR. VOLVIENDO AL MENU...", 0, 9999999, 1)==0)
				  {
					  list[indexEmployee].salary=salarioAux;
				  }
				  else
				  {
					  check=-1;
				  }
				  break;
			  case 4:
				  if(pedirTipoInt(&sectorAux, "Ingrese el sector en cual sera movido el empleado", "ERROR", 0, 6, 1)==0)
				  {
					  list[indexEmployee].sector=sectorAux;
				  }
				  else
				  {
					  check=-1;
				  }
				  break;
			  case 5:
				  check=1;
				  break;

			}

		}



	return check;
}


int findEmployeeById(Employee* list, int len,int id)
{
  int index;
  index=-1;

		  if(list!=NULL && len>0 && id>0 && id>=0)
		  {
			  for(int i=0; i<len; i++)
			  {
				  if(list[i].id==id)
				  {
					  index=i;
					  break;
				  }
			  }
		  }
		  	 return index;
}



//funcion de BAJA


int removeEmployee(Employee* list, int len, int id)
{
	int check;
	check=-1;
		if(list!=NULL && len>0 && id>=0)
		{
			for(int i=0; i<len; i++)
			{
				if(list[i].id==id && list[i].isEmpty==1)
				{
					list[i].isEmpty=0;
					check=0;
					break;
				}
			}
		}



	return check;
}



//funciones de los INFORMES

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int employee_ordenarPorNombre(Employee list[],int len)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee buffer;
	if(list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(list[i].name,list[i+1].name,51) > 0)
				{

					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return respuesta;
}





int contadorDeSalarios(Employee list[], int length)
{
	int contador_salarios;
	contador_salarios=0;

	if(list!=NULL && length>0)
	{
		for(int i=0; i< length; i++)
		{
			if(list[i].isEmpty==1)
			{
				contador_salarios++;
			}
		}

	}
	else
	{
		contador_salarios=-1;
	}

	return contador_salarios;
}


float acumuladorDeSalarios(Employee list[], int length)
{
	float acumulador_salarios;
	acumulador_salarios=0;

	if(list!=NULL && length>0)
	{
		for(int i=0; i< length; i++)
		{
			if(list[i].isEmpty==1)
			{
				acumulador_salarios+=list[i].salary;
			}
		}
	}
	else
	{
		acumulador_salarios=-1;
	}

	return acumulador_salarios;
}






int contadorDeSueldosFueraDelPromedio(Employee list[], int len, float promedioReferencial)
{
	int cont_empleadosFueraDelPromedio;
		if(list!=NULL && len>0)
		{
			for(int i=0; i< len; i++)
			{
				if(list[i].isEmpty==1 && list[i].salary > promedioReferencial)
				{
					cont_empleadosFueraDelPromedio++;
				}
			}
		}
		else
		{
			cont_empleadosFueraDelPromedio=-1;
		}

		return cont_empleadosFueraDelPromedio;
}








/*
 * \brief es un menu estandar que uso
 */

void seeMenu(){

	puts("\n ======================== BIENVENIDO =========================");
	puts("*                                                              *");
	printf("*---------------\t\tMENU\t\t---------------*\n");
	puts("* OPCIONES:                                                    *");
	puts("*  1. ALTA.                                                    *");
	puts("*\t2. MODIFICAR.                                           *");//un \t equivale a 7 asteriscos(*)
	puts("*\t\t3. BAJA.                                       *");
	puts("*\t\t\t4. INFORMAR.                           *");
	puts("************************ ..:5) Salir:.. ************************");
}



//aca iran las funciones static







