/*
 * caracteristicas.c
 *
 *  Created on: 19 oct. 2022
 *      Author: leandro
 */
#include "caracteristicas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int imprimirTipos(eTipo lista[],int tam)
{
	int retorno = -1;

	if(lista != NULL && tam>0)
	{
		printf("**TIPOS DE MASCOTA**");
		printf("\n---------------");
		printf("\n| TIPO |  ID  |");
		printf("\n---------------");
		for(int i=0;i<tam;i++)
		{
			printf("\n|%-6s| %d |",lista[i].descripcion,lista[i].id);
			printf("\n---------------");
		}
		retorno = 0;
	}
	return retorno;
}

int imprimirColores(eColor lista[],int tam)
{
	int retorno = -1;

	if(lista != NULL && tam>0)
	{
		printf("\n**COLORES**");
		printf("\n---------------");
		printf("\n| TIPO |  ID  |");
		printf("\n---------------");
		for(int i=0;i<tam;i++)
		{
			printf("\n|%-6s| %d |",lista[i].nombreColor,lista[i].id);
			printf("\n---------------");
		}
		retorno = 0;
	}

	return retorno;
}

int obtenerTipo(eTipo listaTipos[],int tamTipos,char*descripcion,int id)
{
	int retorno = -1;

	if(listaTipos!=NULL && descripcion!=NULL)
	{
		for(int i=0;i<tamTipos;i++)
		{
			if(listaTipos[i].id==id)
			{
				strcpy(descripcion,listaTipos[i].descripcion);
				retorno = 0;
			}

		}

	}

	return retorno;
}

int obtenerColor(eColor listaColores[],int tamColores, char*descripcion,int id)
{
	int retorno = -1;

	if(listaColores!=NULL && descripcion!=NULL)
	{
		for(int i=0;i<tamColores;i++)
		{
			if(listaColores[i].id==id)
			{
				strcpy(descripcion,listaColores[i].nombreColor);
				retorno = 0;
			}

		}

	}

	return retorno;
}



