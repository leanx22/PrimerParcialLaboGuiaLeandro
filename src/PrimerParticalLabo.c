/*
 ============================================================================
 Name        : PrimerParticalLabo.c
 Author      : Guia Leandro
 Version     :
 Copyright   :
 Description : Primer parcial de laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayMascotas.h"
#include "caracteristicas.h"
#include "utn.h"
#include "serviciosVet.h"
#include "informes.h"

#define TAM 300
#define CANT_TIPOS 5
#define CANT_COLORES 5
#define CANT_SERVICIOS 3
#define CANT_TRABAJOS 300
#define CANT_CLIENTES 5


int main(void)
{
	setbuf(stdout,NULL);

	int idMascotas = 100;
	int idTrabajos = 1000;
	int altas = 0;

	int continuar = 1;
	int opcion;

	eMascota listaMascotas[TAM];
	inicializarMascotas(listaMascotas,TAM);

	eTrabajo listaTrabajos[TAM];
	inicializarTrabajos(listaTrabajos,CANT_TRABAJOS);

	eTipo listaTipos[CANT_TIPOS] =
	{{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};

	eColor listaColores[CANT_COLORES] =
	{{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};

	eServicio listaServicios[CANT_SERVICIOS] =
	{{20000,"Corte",450},{20001,"Desparasitado",800},{20002,"Castrado",600}};

	eCliente listaClientes[CANT_CLIENTES] =
	{{10,"Cristian","Masculino"},{11,"Esteban","Masculino"},{12,"Maria","Femenino"},{13,"Leandro","Masculino"},{14,"Tomas","Masculino"}};

	do{
		system("CLS");
		printf("**MENU PRINCIPAL**"
				"\n1)Alta mascota."
				"\n2)Modificar mascota."
				"\n3)Baja de mascota."
				"\n4)Listar mascotas.(+DUENIO)"
				"\n5)Listar tipos."
				"\n6)Listar colores."
				"\n7)Listar servicios."
				"\n8)Alta trabajo."
				"\n9)Listar trabajos."
				"\n----------INFORMES-----------"
				"\n10)Listar mascotas por color."
				"\n11)Promedio de mascotas vacunadas."
				"\n12)La mascota con menor edad."
				"\n13)Cantidad de mascotas de COLOR Y TIPO X."
				"\n14)El color con mas mascotas."
				"\n15)Salir.");

		if(utn_pedirInt(&opcion,">Ingrese una opcion: ","\n[!]Error, no es una opcion valida.",1,15,99)==0)
		{
			switch(opcion)
			{
			case 1:
				//Alta de mascotas.
				if(nuevaMascota(listaMascotas,listaTipos,listaColores,TAM,CANT_TIPOS,CANT_COLORES,&idMascotas,&altas,listaClientes,CANT_CLIENTES)==0)
				{
					printf("\n[>]Mascota agregada de manera correcta!\n");
					system("PAUSE");
				}else
				{
					printf("\n[!]Ocurrio un error al intentar agregar a la mascota!\n");
					system("PAUSE");
				}
				break;
			case 2:
				//Modificar mascota.
				if(altas>0 && modificarMascota(listaMascotas,listaTipos,TAM,CANT_TIPOS)==0)
				{
					printf("\nMascota actualizada correctamente!\n");
					system("PAUSE");
				}else
				{
					printf("\nNo se encuentra la mascota o no hay mascotas cargadas\n");
					system("PAUSE");
				}
				break;
			case 3:
				//Baja de mascotas.
				if(altas>0 && bajaMascota(listaMascotas,TAM,&altas)==0)
				{
					printf("\nEliminado OK!\n");
					system("PAUSE");
				}else
				{
					printf("\nNo se pudo encontrar el id ingresado, no hay mascotas cargadas o el usuario cancelo la operacion!\n");
					system("PAUSE");
				}
				break;
			case 4:
				//Listar mascotas.
				if(altas>0 && listarMascotas(listaMascotas,listaTipos,TAM,CANT_TIPOS,listaColores,CANT_COLORES,listaClientes,CANT_CLIENTES)==0)
				{
					printf("\n");
					system("PAUSE");
				}else
				{
					printf("\nNo se puede imprimir!.");
					system("PAUSE");
				}
				break;
			case 5:
				//Listar Tipos.
				imprimirTipos(listaTipos,CANT_TIPOS);
				printf("\n");
				system("PAUSE");
				break;
			case 6:
				//Listar colores.
				imprimirColores(listaColores,CANT_COLORES);
				printf("\n");
				system("PAUSE");
				break;
			case 7:
				//Listar servicios.
				listarServicios(listaServicios,CANT_SERVICIOS);
				printf("\n");
				system("PAUSE");
				break;
			case 8:
				//Alta trabajo.
				if(altas>0 &&
					nuevoTrabajo(&idTrabajos,listaMascotas,listaServicios,listaTrabajos,TAM,CANT_SERVICIOS,CANT_TRABAJOS)==0)
				{
					system("CLS");
					printf("\n[>]El trabajo se aniadio de manera correcta!.\n");
					system("PAUSE");
				}else
				{
					printf("\n[!]No hay mascotas cargadas o hubo un error en la carga del trabajo!");
					system("PAUSE");
				}
				break;
			case 9:
				listarTrabajos(listaTrabajos,listaServicios,CANT_TRABAJOS,CANT_SERVICIOS);
				printf("\n");
				system("PAUSE");
				//listar trabajos.
				break;
			case 10:
				if(altas>0)
				{
					imprimirMascotasColor(listaMascotas,listaTipos,listaColores,TAM,CANT_TIPOS,CANT_COLORES);
					printf("\n");
					system("PAUSE");
				}else{
					printf("\n[!]No hay mascotas cargadas!");
					printf("\n");
					system("PAUSE");
				}
				break;
			case 11:
				if(promedioDeVacunaciones(listaMascotas,TAM,altas)!=0)
				{
					printf("\n[!]Ocurrio un error al imprimir o todavia no hay mascotas cargadas!");
					system("PAUSE");
				}
				printf("\n");
				system("PAUSE");
				break;
			case 12:
				if(altas>0)
				{
					informarMenorMascota(listaMascotas,TAM);
					printf("\n");
					system("PAUSE");
				}else
				{
					printf("\n[!]Error!, no hay altas.");
					printf("\n");
					system("PAUSE");
				}
				break;
			case 13:
				if(altas>0)
				{
					cantidadColorYtipo(listaMascotas,listaTipos,listaColores,TAM,CANT_TIPOS,CANT_COLORES);
					printf("\n");
					system("PAUSE");
				}else{
					printf("[!]Aun no se realizaron altas!.");
					printf("\n");
					system("PAUSE");
				}
				break;
			case 14:
				if(altas>0)
				{
					cantidadColores(listaMascotas,listaColores,TAM,CANT_COLORES);
					printf("\n");
					system("PAUSE");
				}else{
					printf("\n[!]Aun no se realizaron altas!\n");
					system("PAUSE");
				}
				break;
			case 15:
				//Salir.
				continuar = 0;
				break;
			}
		}

	}while(continuar == 1);

	return EXIT_SUCCESS;
}
