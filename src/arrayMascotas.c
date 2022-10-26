/*
 * arrayMascotas.c
 *
 *  Created on: 19 oct. 2022
 *      Author: leandro
 */
#include "arrayMascotas.h"
#include "caracteristicas.h"
#include "serviciosVet.h"
#include "utn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int inicializarMascotas(eMascota lista[], int tam)
{
	int retorno = -1;

	if(lista != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarLibre(eMascota lista[],int tam)
{
	int retorno = -1;

	if(lista!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}

	}

	return retorno;
}

int nuevaMascota(eMascota lista[],eTipo listaTipos[],eColor listaColores[],
		int tam,int tamTipos,int tamColores,int*ids,int*cAltas,eCliente listaClientes[],int tamClientes)
{
	int retorno = -1;

	int indice;
	char nombre[20];
	int tipo;
	int color;
	int edad;
	int idCliente;
	char vacunado;

	if(lista != NULL && listaTipos!=NULL && listaColores!=NULL && ids!=NULL)
	{
		system("CLS");
		if(utn_getStr(nombre,"\n>Ingrese el nombre de la mascota: ","\n[!]Error, reintente.",20,3)==0 &&
			imprimirTipos(listaTipos,tamTipos)==0 &&
			utn_pedirInt(&tipo,"\n>Ingrese el tipo de mascota: ","\n[!]Error, fuera de rango.",1000,1004,3)==0 &&
			imprimirColores(listaColores,tamColores)==0 &&
			utn_pedirInt(&color,"\n>Ingrese el color: ","\n[!]Error, fuera de rango.",5000,5004,3)==0 &&
			utn_pedirInt(&edad,"\nIngrese la edad de la mascota: ","\n[!]Error, reintente.",1,200,3)==0 &&
			imprimirClientes(listaClientes,tamClientes)==0 &&
			utn_pedirInt(&idCliente,"\nIngrese la id del duenio: ","\nError! reintente.",10,14,3)==0)
		{
			printf("\n>La mascota esta vacunada(s/n): ");
			fflush(stdin);
			vacunado = getchar();
			while(vacunado!='s' && vacunado!='n')
			{
				printf("\n>Error!, reintente. La mascota esta vacunada(s/n): ");
				fflush(stdin);
				vacunado = getchar();
			}

			indice = buscarLibre(lista,tam);
			if(indice!=-1)
			{
				strcpy(lista[indice].nombre,nombre);
				//strcpy(lista[indice].vacunado,vacunado);
				lista[indice].vacunado = vacunado;
				lista[indice].idTipo = tipo;
				lista[indice].idColor = color;
				lista[indice].edad = edad;
				lista[indice].idCliente = idCliente;
				lista[indice].id = *ids;
				lista[indice].isEmpty=0;
				*ids += 1;
				*cAltas+=1;
				printf("\nID DE LA MASCOTA: %d",lista[indice].id);
				retorno = 0;
			}

		}

	}

	return retorno;
}

int buscarIndicexId(eMascota lista[],int tam, int idBusqueda)
{
	int retorno = -1;

	if(lista!=NULL && tam>0 && idBusqueda>99)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].id == idBusqueda && lista[i].isEmpty != 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int bajaMascota(eMascota lista[],int tam,int*altas)
{
	int retorno = -1;
	int idBusqueda;
	int indice;
	char nombre[20];
	char respuesta;

	if(lista!=NULL && tam>0)
	{
		utn_pedirInt(&idBusqueda,"\nIngrese ID a eliminar: ","\nError, reingrese.",100,9999,3);
		indice = buscarIndicexId(lista,tam,idBusqueda);
		if(indice!=-1)
		{
			strcpy(nombre,lista[indice].nombre);
			printf("\nEliminar a %s?(s = confirmar/pulse otra tecla para cancelar)",nombre);
			fflush(stdin);
			respuesta = getchar();
			if(respuesta=='s')
			{
				lista[indice].isEmpty=1;
				*altas -=1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int modificarMascota(eMascota lista[],eTipo listaTipos[],int tam,int tamTipos)
{
	int retorno = -1;
	int opcion;
	int idBusqueda;
	int indice;

	int tipo;
	char vacunado;

	char descripcionTipo[20];

	if(lista!=NULL && listaTipos!=NULL)
	{
		system("CLS");
		utn_pedirInt(&idBusqueda,"\nIndice a modificar: ","\nError, fuera de rango!",100,99999,3);
		indice = buscarIndicexId(lista,tam,idBusqueda);
		if(indice !=-1)
		{
			printf("\n**MODIFICACION**");
			obtenerTipo(listaTipos,tamTipos,descripcionTipo,lista[indice].idTipo);
			printf("-->DATOS ACTUALES"
					"\nNOMBRE: %s"
					"\nTIPO: %s"
					"\nVACUNADO: %c",lista[indice].nombre,descripcionTipo,lista[indice].vacunado);
			utn_pedirInt(&opcion,"\n1)Modificar tipo.\n2)Modificar vacunacion.\n>Ingrese una opcion: ","\nError, reintente!",1,2,99);
			if(opcion==1)
			{
				imprimirTipos(listaTipos,tamTipos);
				utn_pedirInt(&tipo,"\n>Ingrese el nuevo tipo de mascota: ","\n[!]Error, fuera de rango.",1000,1004,99);
				lista[indice].idTipo = tipo;
				retorno = 0;
			}else
			{
				printf("\n>La mascota esta vacunada(s/n): ");
				fflush(stdin);
				vacunado = getchar();
				while(vacunado!='s' && vacunado!='n')
				{
					printf("\n>Error!, reintente. La mascota esta vacunada(s/n): ");
					fflush(stdin);
					vacunado = getchar();
				}

				lista[indice].vacunado = vacunado;
				retorno = 0;
			}

			retorno = 0;
		}

	}

	return retorno;
}

int listarMascotas(eMascota lista[],eTipo listaTipos[],int tam,int tamTipos,eColor listaColores[],int tamColores,
		eCliente listaClientes[],int tamClientes)
{
	int retorno = -1;
	eMascota aux;
	char descripcionTipos[20];
	char descripcionColor[20];
	char nombreDuenio[20];

	if(lista!=NULL && listaTipos!=NULL)
	{
		system("CLS");

		for(int i=0;i<tam;i++)
		{
			for(int j=1;j<tamTipos;j++)
			{
				if(lista[i].idTipo>lista[j].idTipo)
				{
					aux = lista[j];
					lista[j] = lista[i];
					lista[i] = aux;
				}
				if(lista[i].idTipo == lista[j].idTipo && strcmp(lista[i].nombre,lista[j].nombre)>0)
				{
					aux = lista[j];
					lista[j] = lista[i];
					lista[i] = aux;
				}
			}
		}
		printf("\n**MASCOTAS**");
		printf("\n|  ID  |  TIPO  |   NOMBRE   | EDAD | VACUNADO |  COLOR  | NOMBRE DUENIO |");
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==0)
			{
				obtenerTipo(listaTipos,tamTipos,descripcionTipos,lista[i].idTipo);
				obtenerColor(listaColores,tamColores,descripcionColor,lista[i].idColor);
				obtenerNombreCliente(listaClientes,tamClientes,nombreDuenio,lista[i].idCliente);
				printf("\n| %-4d | %-6s | %-10s | %-4d | %-8c | %-7s | %15s |",lista[i].id,descripcionTipos,lista[i].nombre,
						lista[i].edad,lista[i].vacunado,descripcionColor,nombreDuenio);
			}
		}
		retorno = 0;
	}

	return retorno;
}
