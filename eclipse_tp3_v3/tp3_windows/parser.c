#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	FILE* pArchivoAux;
	Employee* empleadoAux;// nunca habia usado tantas veces la palabr Aux jeje
	int deteccion=-1;
	char idAux[64];
	char nombreAux[128];
	char horasAux[64];
	char sueldoAux[64];

	if(pFile!=NULL && pArrayListEmployee)
	{
		pArchivoAux=fopen(pFile,"r");
		if(pArchivoAux!=NULL && fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
		{

			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
				{
					empleadoAux=employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
					if(empleadoAux!=NULL)
					{
						deteccion=0;
						ll_add(pArrayListEmployee, empleadoAux);
						employee_setId(empleadoAux, atoi(idAux));
					}
					else
					{
						employee_delete(empleadoAux);
						break;
					}
				}
			}while(!feof(pFile));
		}

	}


    return deteccion;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int deteccion=-1;

	Employee* pEmpleadoAuxiliar;

	if(pArrayListEmployee!=NULL && pFile!=NULL)
	{
		do{
			pEmpleadoAuxiliar=employee_new();
			if(fread(pEmpleadoAuxiliar,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, pEmpleadoAuxiliar);
				deteccion=0;
			}
			else
			{
				employee_delete(pEmpleadoAuxiliar);
				break;
			}




		}while(feof(pFile)==0);
	}
    return deteccion;
}
