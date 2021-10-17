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


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int check;
	int index;
	check=-1;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary!=NULL && sector>0)
	{
		index=findEmpty(&list, len);
		if(index>0)
		{
			list->id[index]=id;
			strncpy(list->lastName[index], lastName, 51);
			strncpy(list->lastName[index], lastName, 51);
			list->salary[index]=salary;
			list->sector[index]=sector;
			check=0;
		}
	}

	return check;
}








int addEmployeesAux(Employee* list)
{
	int deteccion;
	Employee listaAuxiliar;
		if(list!=NULL)
		{
			if(pedir_texto(&listaAuxiliar.name, "Ingrese el nombre del empleado que va ingresar", "ERROR. Ingrese un nombre", 3)==0)
			{
				if(pedir_texto(&listaAuxiliar.lastName, "Ingrese el apellido del empleado", "ERROR. Que esta haciendo?", 3)==0)
				{
					if(PedirTipoFloat(listaAuxiliar.salary, "Ingrese el salario del empleado", "ERROR. Use numero reales, porfavor", 0.0, 999999, 2)==0)
					{
						if(PedirTipoInt(listaAuxiliar.sector, "Ingrese el sector del gil laburante.", "ERROR. Sector invalido", 0, 3, 2))
						{
							if((listaAuxiliar.id=crearId())>0)
							{
								strncpy(list->lastName, listaAuxiliar.lastName, 51);
								strncpy(list->name, listaAuxiliar.name, 51);
								list->salary=listaAuxiliar.salary;
								list->sector=listaAuxiliar.sector;
								list->id=listaAuxiliar.id;
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

int printEmployees(Employee* list, int length)

{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && length>0)
	{
		printf("\tLista del ID:\n");
		for(int i=0; i< length; i++)
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
	char nombreAux[len];
	char apellidoAux[len];
	float salarioAux;
	int sectorAux;

	check=-1;


		if(list!=NULL && len>0)
		{
			indexEmployee=findEmployeeById(&list, len, id);
			switch(option)
			{
			  case 1:
				 if(pedir_texto(&nombreAux, "ingrese el nuevo nombre el empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee]->name, nombreAux, len);
				 }
				 else
				 {
					 check=-1;
				 }
				 break;
			  case 2:
				 if(pedir_texto(&apellidoAux, "ingrese el nuevo apellido del empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee]->lastName, apellidoAux, len);
				 }
				 else
				 {
				 	 check=-1;
				 }
				 break;
			  case 3:
				  if(pedirTipoFloat(&salarioAux, "Ingrese le nuevo salario del empleado", "ERROR. VOLVIENDO AL MENU...", -999999999999.999999, 9999999.9999999, 1)==0)
				  {
					  list[indexEmployee]->salary=salarioAux;
				  }
				  else
				  {
					  check=-1;
				  }
				  break;
			  case 4:
				  if(pedirTipoInt(&sectorAux, "Ingrese el sector en cual sera movido el empleado", "ERROR", 0, 6, 1)==0)
				  {
					  list[indexEmployee]->sector=sectorAux;
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

		  if(list!=NULL && len>0 && id>0 && id!=NULL)
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
		if(list!=NULL && len>0 && id!=NULL)
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
	int sectorMax;
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






int crearId(void)
{
  static int numeroMagico;
	numeroMagico=0;
		numeroMagico++;

	return numeroMagico;
}
