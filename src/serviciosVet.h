/*
 * serviciosVet.h
 *
 *  Created on: 25 oct. 2022
 *      Author: leandro
 */
#include "arrayMascotas.h"
#ifndef SERVICIOSVET_H_
#define SERVICIOSVET_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id; //Comienza en 2000
	char descripcion[25];
	float precio;
}eServicio;

typedef struct{
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* SERVICIOSVET_H_ */

/// @brief Funcion que lista todos los servicios disponibles en formato de tabla
///
/// @param lista Lista de servicios.
/// @param tam Tamanio del array de la lista de servicios.
/// @return La funcion retorna 0 si tod OK o -1 en caso de error generico (NULL en puntero o tam 0).
int listarServicios(eServicio lista[],int tam);

/// @brief Funcion encargada de inicializar el array de trabajos
/// estableciendo el campo isEmpty en 1.
/// @param lista Array de la lista trabajos.
/// @param tam Tamanio del array trabajos.
/// @return La funcion retorna 0 si tod OK o -1 en caso de error generico.
int inicializarTrabajos(eTrabajo lista[], int tam);

/// @brief Esta funcion busca un indice del array donde isEmpty sea = 1
/// y retorna por medio del puntero ese indice.
/// @param lista Lista de trabajo.
/// @param tam tamanio del array trabajos.
/// @param pIndiceLibre Puntero a variable donde se guardara el indice libre que se encontro.
/// @return la funcion retorna 0 si tod OK o -1 en caso de error generico o no encontrar un lugar libre.
int buscarTrabajoLibre(eTrabajo lista[],int tam,int* pIndiceLibre);

/// @brief Funcion encargada de dar de alta nuevos trabajos.
///
/// @param id Puntero al controlador de ID de trabajos.
/// @param listaMascotas Array de mascotas.
/// @param listaServicios Array de servicios.
/// @param listaTrabajos Array de trabajos.
/// @param tamMascotas Tamanio del array.
/// @param tamServicio Tamanio del array.
/// @param tamTrabajo Tamanio del array.
/// @return Retorna 0 si se pudo hacer el alta correctamente o -1 en caso de error en la carga de datos.
int nuevoTrabajo(int*id, eMascota listaMascotas[],
		eServicio listaServicios[],eTrabajo listaTrabajos[],int tamMascotas,int tamServicio,int tamTrabajo);

/// @brief Funcion encargada de listar todos los trabajos.
///
/// @param listaTrabajos Array de trabajos.
/// @param listaServicios Array de servicios.
/// @param tamTrabajos Tamanio del array.
/// @param tamServicios Tamanio del array.
/// @return Retorna 0 si tod OK o -1 en caso de error.
int listarTrabajos(eTrabajo listaTrabajos[],eServicio listaServicios[],int tamTrabajos,int tamServicios);

/// @brief Funcion utilizada para obtener la descripcion de un servicio por medio de su ID.
///
/// @param listaServicio Array de servicios.
/// @param tamServicio Tamanio del array de servicios.
/// @param resultado Puntero a variable donde se guardara la descripcion obtenida.
/// @param id
/// @return Retorna 0 si tod OK o -1 en caso de error generico(NULL en los punteros).
int obtenerDescServicio(eServicio listaServicio[], int tamServicio, char*resultado,int id);

/// @brief
///
/// @param listaClientes
/// @param tamClientes
/// @param resultado
/// @param id
/// @return
int obtenerNombreCliente(eCliente listaClientes[],int tamClientes,char*resultado,int id);

/// @brief
///
/// @param listaClientes
/// @param tamClientes
/// @return
int imprimirClientes(eCliente listaClientes[],int tamClientes);
