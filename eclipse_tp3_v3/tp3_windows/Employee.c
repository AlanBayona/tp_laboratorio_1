#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"

//funciones static
static int isValidNombre(char* nombre);
static int isValidSueldo(int sueldo);
static int isValidId(int id);


//funciones normales
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* this = employee_new();
	int idAux;
	int horasTrabajadasAux;
	int sueldoAux;
	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL)
	{
		idAux=atoi(idStr);
		horasTrabajadasAux=atoi(horasTrabajadasStr);
		sueldoAux=atoi(sueldoStr);
		if(!employee_setNombre(this, nombreStr) && !employee_setId(this, idAux) && !employee_setHorasTrabajadas(this, horasTrabajadasAux) && !employee_setSueldo(this, sueldoAux))
		{
			puts("Salio bien el newParametros");
		}
		else
		{
		employee_delete(this);
		this=NULL;
		}
	}

	return this;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}

}

int employee_setId(Employee* this,int id)
{
	int deteccion= -1;
	static int maximoId= -1;
	if(this!=NULL && isValidId(id)==0)
	{
		deteccion=0;
		if(id<0)
		{
			maximoId++;
			this->id=maximoId;
		}
		else
		{
			if(id>maximoId)
			{
				maximoId=id;
				this->id=id;
			}
		}
	}
	return deteccion;
}


int employee_getId(Employee* this,int* id)
{
	int deteccion=-1;
	if(this!=NULL && id>0)
	{
		deteccion=0;
		*id=this->id;
	}
	return deteccion;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int deteccion=-1;
	if(this!=NULL && nombre!=NULL && isValidNombre(nombre)==0)
	{
		deteccion=0;
		strcpy(this->nombre, nombre);
	}
	return deteccion;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int deteccion=-1;
	if(this !=NULL && nombre!=NULL)
	{
		deteccion=0;
		strcpy(nombre, this->nombre);
	}
	return deteccion;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int deteccion=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		deteccion=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return deteccion;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int deteccion=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		deteccion=0;
		*horasTrabajadas=this->horasTrabajadas;
	}
	return deteccion;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int deteccion=-1;
	if(this!=NULL && sueldo>=0 && isValidSueldo(sueldo))
	{
		deteccion=0;
		this->sueldo=sueldo;
	}
	return deteccion;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int deteccion=-1;
	if(this!=NULL && sueldo>0)
	{
		deteccion=0;
		*sueldo=this->sueldo;
	}
	return deteccion;
}






static int isValidNombre(char* nombre)
{
	int deteccion;
		deteccion=-1;
		if(nombre!=NULL && strlen(nombre)>0)
		{
			for(int i=0; nombre[i]!='\0'; i++)
			{

					if((nombre[i]>='a' && nombre[i]<='z')||(nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==164)//donde 48=0 y 57=9 en ascii
					{
							deteccion=0;
							puts("Salio bien");
					}
					else
					{
						deteccion=-1;
						puts("\nSalio mal, en funcion validarTexto\n");
						break;
					}

			}
		}
		return deteccion;
}



static int isValidSueldo(int sueldo)
{
	int deteccion=-1;
		if(sueldo>0)
		{
			deteccion=0;
		}

		return deteccion;
}

static int isValidId(int id)
{
	int deteccion=-1;
		if( id>=0)
		{
			deteccion=0;
		}

		return deteccion;
}







int OrdenarPorNombre(void* empleadoAnterior, void* empleadoPosterior)
{
	int ordenamiento=-4;
	Employee* empleadoAux=(Employee*)empleadoAnterior;
	Employee* empleadoAux2=(Employee*)empleadoPosterior;

	if(empleadoAux!=NULL && empleadoAux2!=NULL)
	{
		ordenamiento=stricmp(empleadoAux2->nombre, empleadoAux2->nombre);
	}



	return ordenamiento;
}

int OrdenarPorSueldo(void* empleadoAnterior, void* empleadoPosterior)
{
	int retorno=0;
	Employee* empleadoAux=(Employee*)empleadoAnterior;
	Employee* empleadoAux2=(Employee*)empleadoPosterior;

	if(empleadoAux->sueldo!=empleadoAux2->sueldo)
	{
		if(empleadoAux->sueldo>empleadoAux2->sueldo)
		{
			retorno=1;
		}
		else if(empleadoAux->sueldo<empleadoAux2->sueldo)
		{
			retorno=-1;
		}
	}



	return retorno;
}

int OrdenarPorHora(void* empleadoAnterior, void* empleadoPosterior)
{
	int retorno=0;
	Employee* empleadoAux=(Employee*)empleadoAnterior;
	Employee* empleadoAux2=(Employee*)empleadoPosterior;

	if(empleadoAux->horasTrabajadas!=empleadoAux2->horasTrabajadas)
	{
		if(empleadoAux->horasTrabajadas>empleadoAux2->horasTrabajadas)
		{
			retorno=1;
		}
		else if(empleadoAux->horasTrabajadas<empleadoAux2->horasTrabajadas)
		{
			retorno=-1;
		}
	}



	return retorno;
}


