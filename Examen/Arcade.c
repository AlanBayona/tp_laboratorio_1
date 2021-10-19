#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Arcade.h"

#define MONO 1 // y riel=riel
#define ESTEREO 2
#define LIBRE 0
#define OCUPADO 1


static void mostrarRelacionPorId(eSalon list[], int len, int idABuscar);
//funcion de inicio


int initArcade(eArcade listado[], int len)
{
	int deteccion;
	deteccion=-1;
	if(listado!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			listado[i].isEmpty=0;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}








/*
 * ebref Esta funcion cumple con el trabajo de imprimir
 * parametros Recibe un array de la entidad Employee y el largo del vector.
 * return Devuelve un 0 si salio bien y un -1 si salio mal.
 */



int imprimirSoloArrayArcades(eArcade list[], int len)
{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && len>0)
	{
		printf("\n\t\tLista de los Arcade:\n");
		for(int i=0; i< len; i++)
		{
			if(list[i].isEmpty==1)
			{

				printf("\t\tID: %d\n",list[i].id);
				printf("\tNacionalidad: %s\n",list[i].nacionalidad);
				printf("\tNombre del juego: %s\n",list[i].nombreDelJuego);
				printf("\tCantidad de jugadores: %d\n",list[i].cant_jugadores);
				printf("\tCantidad de fichas maxima: %d\n",list[i].fichasMaxima);
				if(list[i].sonido==MONO)
				{
					printf("\tTipo de sonido: Mono\n");
				}
				else
				{
					puts("\tTipo de sonido: Estereo\n");
				}
			}
		}
		deteccion=0;
	}

	return deteccion;
}





int imprimirArrayArcade(eArcade listadoArcades[], eSalon listadoSalones[], int lenArcade, int lenSalon)
{
	int deteccion;
	deteccion=-1;

	if(listadoSalones!=NULL && lenArcade>0 && listadoArcades!=NULL && lenSalon>0)
	{
		printf("\n\t\tLista de los Arcade:\n");
		for(int i=0; i< lenArcade; i++)
		{
			if(listadoArcades[i].isEmpty==1)
			{

				printf("\t\tID: %d\n",listadoArcades[i].id);
				printf("\tNacionalidad: %s\n",listadoArcades[i].nacionalidad);
				printf("\tNombre del juego: %s\n",listadoArcades[i].nombreDelJuego);
				printf("\tCantidad de jugadores: %d\n",listadoArcades[i].cant_jugadores);
				printf("\tCantidad de fichas maxima: %d\n",listadoArcades[i].fichasMaxima);
				if(listadoArcades[i].sonido==MONO)
				{
					printf("\tTipo de sonido: Mono\n");
				}
				else
				{
					puts("\tTipo de sonido: Estereo\n");
				}
				mostrarRelacionPorId(listadoSalones, lenSalon, listadoArcades[i].idSalon);
			}
		}
		deteccion=0;
	}

	return deteccion;
}




static void mostrarRelacionPorId(eSalon list[], int len, int idABuscar)
{
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1 && list[i].id==idABuscar)
		{
			printf("\n\tNombre: %s\n",list[i].nombre);
			printf("\tDireccion: %s\n",list[i].direccion);
			if(list[i].tipo==1)
			{
				printf("\tTipo: Shopping\n");
			}
			else
			{
				puts("\tTipo: Local\n");
			}
		}
	}
}









//ALTA

int agregarArcade(eArcade list[], eSalon listado[], int lenSalon, int lenArcade)
{
	int deteccion;
	int index;
	eArcade arcadeAux;

	deteccion=-1;
	if(list!=NULL && lenArcade>0)
	{
		index=buscarSalonVacio(list, lenArcade);
		if(index>=0){
			if(pedir_texto(&arcadeAux.nacionalidad, "Ingrese la nacionadad del juego:\n", "ERROR. Intente de nuevo\n", 2)==0)
			{
				if(pedirDireccion(&arcadeAux.nombreDelJuego, "Ingrese el nombre del juego:\n", "ERROR tipo A. fallo en el nombre del juego\n", 2)==0)
				{
					if(pedirTipoInt(&arcadeAux.sonido, "\tIngrese tipo de sonido:\n1-Mono\n2-Estereo\n", "ERROR A\n", 1, 2, 3)==0)
					{
						if(pedirTipoInt(&arcadeAux.cant_jugadores,"\nCantidad de juegadores: ", "Error tipo A\n",1,6,3)==0)
						{
							if(pedirTipoInt(&arcadeAux.fichasMaxima, "\nIngrese la cantidad de fichas maximo que admite: ","ERROR tipo A", 1, 99, 3)==0)
							{
								if(pedirTipoInt(&arcadeAux.idSalon, "\nIngrese el id del cual pertenece este ARCADE: ", "Perdon, el id ingre", 1, 999, 2)==0)
								{
									if(validarId(listado, lenSalon, arcadeAux.idSalon)>0)
									{
										arcadeAux.id=crearId();
										if(arcadeAux.id>0)
										{
											strncpy(list[index].nacionalidad, arcadeAux.nacionalidad, 51);
										    strncpy(list[index].nombreDelJuego, arcadeAux.nombreDelJuego, 51);
										    list[index].cant_jugadores=arcadeAux.cant_jugadores;
										    list[index].fichasMaxima=arcadeAux.fichasMaxima;
										    list[index].idSalon=arcadeAux.idSalon;
									        list[index].sonido=arcadeAux.sonido;
											list[index].id=arcadeAux.id;
											list[index].isEmpty=OCUPADO;

									//	printf("\n*ID: %d - Nombre: %s - Direccion: %s\n", salonAux.id, salonAux.nombre, salonAux.direccion);
										   deteccion=0;
										}
									} else{puts("salio mal la funcion que creaste. revisa a funcion de alta");}//recordar borrar
								}

							}
						}
					}
				}
			}
		}
	}


	return deteccion;

}


int validarId(eSalon list[], int len, int id)
{
	int deteccion;
	deteccion=-1;

			if(list!=NULL && len>0 && id>0)
			  {
				  for(int i=0; i<len; i++)
				  {
					  if(list[i].id==id)
					  {
						  deteccion=i;
						  break;
					  }
				  }
			  }



	return deteccion;
}


//BAJA
/*
 *\brief esta funcion hace la baja logica de un arcade
 *\param pido una array de una entidad, en este casi eArcade y su largo, siendo lenArcade
 *\return Devuelve -1 si hubo algun inconveniente y 0 si la funcion cumplio su objetivo
 */
int removerArcade(eArcade list[], int lenArcade)
{
	int deteccion;
	int idBuscado;
	int opcion;
	deteccion=-1;
		if(list!=NULL && lenArcade>0)
		{
			if(pedirTipoInt(&idBuscado, "Ingrese el id que desee remover", "Invalido", 0, 999, 1)==0)
			{
				for(int i=0; i<lenArcade; i++)
				{
					if(list[i].id==idBuscado && list[i].isEmpty==1)
					{
						if(pedirTipoInt(&opcion, "\n\tSeguro que desea borrar el Arcade?\n1-SI, MI REY.\n2-NO, ABORTE LA DECISION.\n", "Estas pendejo! solo hay dos optiones\n", 1, 2, 99)==0)
						{
							if(opcion==1)
							{
								list[i].isEmpty=0;
								deteccion=0;
								break;
							}
							else
							{
								deteccion=1;
								break;
							}
						}
					}
				}
			}
		}



	return deteccion;
}




