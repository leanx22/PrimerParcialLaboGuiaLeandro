/*
 * informes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: leandro
 */

#include "informes.h"
#include "caracteristicas.h"
#include "arrayMascotas.h"
#include "utn.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int imprimirMascotasColor(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[], int tamMascotas,int tamTipos,int tamColores)
{
	int retorno = -1;
	int idColor;

	char descripcionTipos[25];
	char descripcionColor[25];

	if(listaMascotas!=NULL && listaTipos!=NULL && listaColores!=NULL && tamMascotas>0 && tamTipos>0 && tamColores>0)
	{
		system("CLS");
		imprimirColores(listaColores,tamColores);
		if(utn_pedirInt(&idColor,"\n>Ingrese el ID del color de las mascotas que se quiere listar: ",
				"\n[!]Error, reingrese.",5000,5004,3)==0)
		{
			printf("\n-------------------------MASCOTAS-------------------------**");
			printf("\n|  ID  |  TIPO  |   NOMBRE   | EDAD | VACUNADO |  COLOR  |");
			for(int i=0;i<tamMascotas;i++)
			{
				if(listaMascotas[i].isEmpty==0 && listaMascotas[i].idColor == idColor)
				{
					obtenerTipo(listaTipos,tamTipos,descripcionTipos,listaMascotas[i].idTipo);
					obtenerColor(listaColores,tamColores,descripcionColor,listaMascotas[i].idColor);
					printf("\n| %-4d | %-6s | %-10s | %-4d | %-8c | %-7s |",listaMascotas[i].id,descripcionTipos,listaMascotas[i].nombre,listaMascotas[i].edad,listaMascotas[i].vacunado,descripcionColor);
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

int promedioDeVacunaciones(eMascota listaMascotas[],int tamMascotas, int altas)
{
	int retorno = -1;
	int cVacunados=0;
	float promedio;
	float porcentaje;

	if(listaMascotas!=NULL && tamMascotas>0 && altas>0)
	{
		for(int i=0;i<tamMascotas;i++)
		{
			if(listaMascotas[i].vacunado == 's')
			{
				cVacunados++;
			}
		}

		promedio = cVacunados/altas;
		porcentaje = promedio*100;
		system("CLS");
		printf("\n|>La cantidad total de mascotas es de: %d.",altas);
		printf("\n|>De esa cantidad %d estan vacunados.",cVacunados);
		printf("\n|>Por lo que el PROMEDIO DE MASCOTAS VACUNADAS es de: %.1f",promedio);
		printf("\n|>El PORCENTAJE es de %.2f porciento.",porcentaje);
		retorno = 0;
	}

	return retorno;
}

int informarMenorMascota(eMascota listaMascotas[],int tamMascotas)
{
	int retorno = -1;
	int flagPrimero = 0;
	int menorEdad=0;
	char nombre[20];
	//eMascota aux;

	if(listaMascotas!=NULL && tamMascotas>0)
	{

		for(int i=0;i<tamMascotas;i++)
		{
			if(listaMascotas[i].isEmpty==0)
			{
				if(flagPrimero==0)
				{
					menorEdad = listaMascotas[i].edad;
					strcpy(nombre,listaMascotas[i].nombre);
					flagPrimero=1;
				}

				if(menorEdad>listaMascotas[i].edad)
				{
					menorEdad = listaMascotas[i].edad;
					strcpy(nombre,listaMascotas[i].nombre);
				}
			}
		}

		system("CLS");
		printf("La mascota de menor edad es %s con %d anios de edad!.",nombre,menorEdad);
		retorno = 0;
	}

	return retorno;
}

int cantidadColorYtipo(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[],int tamMascotas,int tamTipos,int tamColores)
{
	int retorno = -1;
	int idTipo;
	int idColor;

	int contador=0;
	char descripcionTipo[25];
	char descripcionColor[25];

	if(listaMascotas!=NULL && listaTipos!=NULL && listaColores!=NULL && tamMascotas>0 && tamTipos>0 && tamColores>0)
	{
		system("CLS");
		if(	imprimirTipos(listaTipos,tamTipos)==0 &&
			utn_pedirInt(&idTipo,"\n>Ingrese ID del TIPO a imprimir: ","\n[!]Error, reintente.",1000,1004,3)==0 &&
			imprimirColores(listaColores,tamColores)==0 &&
			utn_pedirInt(&idColor,"\n>Ingrese ID del COLOR a imprimir: ","\n[!]Error, reintente.",5000,5004,3)==0)
		{
			for(int i=0;i<tamMascotas;i++)
			{
				if(listaMascotas[i].isEmpty==0 && listaMascotas[i].idTipo == idTipo && listaMascotas[i].idColor == idColor)
				{
					contador++;
				}
			}

			if(contador>0)
			{
				system("CLS");
				obtenerTipo(listaTipos,tamTipos,descripcionTipo,idTipo);
				obtenerColor(listaColores,tamColores,descripcionColor,idColor);
				printf("La cantidad de mascotas tipo %s de color %s es de: %d",descripcionTipo,descripcionColor,contador);
			}else
			{
				system("CLS");
				printf("\n[!]No hay mascotas que cumplan con esas caracteristicas!.");
			}

			retorno = 0;
		}
	}

	return retorno;
}

int cantidadColores(eMascota listaMascotas[],eColor listaColores[],int tamMascotas,int tamColores)
{
	int retorno =-1;
	int cNegro =0;
	int cBlanco =0;
	int cRojo =0;
	int cGris =0;
	int cAzul =0;

	if(listaMascotas!=NULL && listaColores!=NULL && tamMascotas>0 && tamColores>0)
	{
		for(int i=0;i<tamMascotas;i++)
		{
			switch(listaMascotas[i].idColor)
			{
			case 5000:
				cNegro++;
				break;
			case 5001:
				cBlanco++;
				break;
			case 5002:
				cRojo++;
				break;
			case 5003:
				cGris++;
				break;
			case 5004:
				cAzul++;
				break;
			}

		}

		if(cNegro>cBlanco && cNegro>cRojo && cNegro>cGris && cNegro>cAzul)
		{
			system("CLS");
			printf("\nEl color con mas mascotas es el negro, con %d.",cNegro);
		}
		else if(cBlanco>cRojo && cBlanco>cGris && cBlanco>cAzul)
		{
			system("CLS");
			printf("\nEl color con mas mascotas es el blanco, con %d.",cBlanco);
		}
		else if(cRojo>cGris && cRojo>cAzul)
		{
			system("CLS");
			printf("\nEl color con mas mascotas es el rojo, con %d.",cRojo);
		}
		else if(cGris>cAzul)
		{
			system("CLS");
			printf("\nEl color con mas mascotas es el gris, con %d.",cGris);
		}else{
			system("CLS");
			printf("\nEl color con mas mascotas es el azul, con %d.",cAzul);
		}

		retorno =0;

	}

	return retorno;
}
