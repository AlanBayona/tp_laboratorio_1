/*
 * Employee.h
 *
 *  Created on: 8 oct 2021
 *      Author: cesar
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int   id;
	char  name[51];
	char  lastName[51];
	float salary;
	int   sector;
	int   isEmpty;//1=ocupado y 0=vacio

}Employee;

void seeMenu();
int initEmployees(Employee list[], int len);



//Funciones de la parte ALTA
int printEmployees(Employee list[], int len);
int findEmpty(Employee list[], int len);
int addEmployeesAux(Employee* list);
int addEmployee(Employee list[], int len, int id, char* name,char* lastName,float salary,int sector);
int crearId(void);

//Funciones para modificar

int findEmployeeById(Employee* list, int len,int id);


//Funciones para la baja

int removeEmployee(Employee* list, int len, int id);


//funciones Informe

int contadorDeSueldosFueraDelPromedio(Employee list[], int len, float promedioReferencial);
int employee_ordenarPorNombre(Employee list[],int len);
int contadorDeSalarios(Employee list[], int length);
float acumuladorDeSalarios(Employee list[], int length);
int modifyEmployeebyId(Employee* list, int len, int id, int option);


#endif /* ARRAYEMPLOYEES_H_ */
