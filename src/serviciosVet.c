/*
 * serviciosVet.c
 *
 *  Created on: 25 oct. 2022
 *      Author: leandro
 */
#include "serviciosVet.h"
#include "caracteristicas.h"
#include "arrayMascotas.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int listarServicios(eServicio lista[],int tam)
{
	int retorno = -1;
	if(lista != NULL && tam > 0)
	{
		//system("CLS");
		printf("\n|>SERVICIOS<|\n");
		printf("|  ID  | DESCRIPCION | PRECIO |\n");
		for(int i=0;i<tam;i++)
		{
			printf("|%6d|%-13s| %.2f |\n",lista[i].id,lista[i].descripcion,lista[i].precio);
		}
		retorno = 0;
	}
	return retorno;
}

int inicializarTrabajos(eTrabajo lista[], int tam)
{
	int retorno = -1;

	if(lista != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].isEmpty = 1;
		}
	}

	return retorno;
}

int buscarTrabajoLibre(eTrabajo lista[],int tam,int* pIndiceLibre)
{
	int retorno = -1;
	if(lista != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==1)
			{
				*pIndiceLibre = i;
				retorno =0;
				break;
			}
		}
	}

	return retorno;
}

int nuevoTrabajo(int*id, eMascota listaMascotas[],
		eServicio listaServicios[],eTrabajo listaTrabajos[],int tamMascotas,int tamServicio,int tamTrabajo)
{
	int retorno = -1;
	int idMascota;
	int indiceLibreTrabajo;
	int servicio;

	int dia,mes,anio;

	if(id != NULL && listaMascotas!=NULL && listaServicios!=NULL && listaTrabajos!=NULL && tamMascotas>0 &&
			tamServicio>0 && tamTrabajo>0)
	{
		system("CLS");
		if(utn_pedirInt(&idMascota,"\n>Ingrese el ID de la mascota: ","\n[!]Error, reintente!.",100,9999,3)==0 &&
			buscarIndicexId(listaMascotas,tamMascotas,idMascota)!=1 &&
			//Si buscar indice me devuelve un indice valido es porque existe el ID.
			buscarTrabajoLibre(listaTrabajos,tamTrabajo,&indiceLibreTrabajo)==0)
			//Si buscarTrabajo retorna 0, es porque hay lugares disponibles.
		{
			listaTrabajos[indiceLibreTrabajo].idMascota = idMascota;
			listarServicios(listaServicios,tamServicio);
			if(utn_pedirInt(&servicio,"\n>ID del servicio deseado: ","\n[!]Error, reintente.",20000,20002,3)==0 &&
					utn_pedirInt(&dia,"\n>Ingrese el dia: ","\n[!]Error, reintente!",1,31,3)==0 &&
					utn_pedirInt(&mes,"\n>Ingrese el mes: ","\n[!]Error, reintente!",1,12,3)==0 &&
					utn_pedirInt(&anio,"\n>Ingrese el anio: ","\n[!]Error, reintente!",2022,3099,3)==0)
			{
				listaTrabajos[indiceLibreTrabajo].idServicio = servicio;
				listaTrabajos[indiceLibreTrabajo].fecha.dia = dia;
				listaTrabajos[indiceLibreTrabajo].fecha.mes = mes;
				listaTrabajos[indiceLibreTrabajo].fecha.anio = anio;

				*id += 1;
				listaTrabajos[indiceLibreTrabajo].id = *id;
				listaTrabajos[indiceLibreTrabajo].isEmpty=0;
				retorno = 0;
			}
		}

	}


	return retorno;
}

int obtenerDescServicio(eServicio listaServicio[], int tamServicio, char*resultado, int id)
{
	int retorno = -1;

	if(listaServicio!=NULL && tamServicio>0 && resultado!=NULL)
	{
		for(int i=0;i<tamServicio;i++)
		{
			if(listaServicio[i].id==id)
			{
				strcpy(resultado,listaServicio[i].descripcion);
				retorno = 0;
			}

		}

	}

	return retorno;
}

int listarTrabajos(eTrabajo listaTrabajos[],eServicio listaServicios[],int tamTrabajos,int tamServicios)
{
	int retorno = -1;
	char descripcion[25];

	if(listaTrabajos!=NULL && tamTrabajos>0)
	{
		printf("\n|>LISTA DE TRABAJOS<|");
		printf("\n|  ID  |  ID MASCOTA  |     SERVICIO    |   FECHA    |\n");
		for(int i=0;i<tamTrabajos;i++)
		{
			if(listaTrabajos[i].isEmpty==0)
			{
			obtenerDescServicio(listaServicios,tamServicios,descripcion,listaTrabajos[i].idServicio);
			printf("| %-4d | %12d | %-15s | %d/%d/%d |\n",listaTrabajos[i].id,listaTrabajos[i].idMascota,descripcion,
					listaTrabajos[i].fecha.dia,listaTrabajos[i].fecha.mes,listaTrabajos[i].fecha.anio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int obtenerNombreCliente(eCliente listaClientes[],int tamClientes,char*resultado,int id)
{
	int retorno = -1;

	if(listaClientes!=NULL && tamClientes>0)
	{
		for(int i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].idCliente == id)
			{
				strcpy(resultado,listaClientes[i].nombre);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int imprimirClientes(eCliente listaClientes[],int tamClientes)
{
	int retorno = -1;
	char nombre[20];

	if(listaClientes!=NULL && tamClientes>0)
	{
		system("CLS");
		printf("--LISTADO DE CLIENTES--");
		printf("\n| ID | NOMBRE | SEXO |\n");
		for(int i=0;i<tamClientes;i++)
		{
			obtenerNombreCliente(listaClientes,tamClientes,nombre,listaClientes[i].idCliente);
			printf("| %-4d | %15s | %9s |\n",listaClientes[i].idCliente,nombre,listaClientes[i].sexo);
		}
		printf("\n");
		system("PAUSE");
		retorno=0;
	}

	return retorno;
}
