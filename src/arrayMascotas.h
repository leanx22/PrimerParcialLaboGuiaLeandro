/*
 * arrayMascotas.h
 *
 *  Created on: 19 oct. 2022
 *      Author: leandro
 */
#include "caracteristicas.h"
//#include "serviciosVet.h"
#ifndef ARRAYMASCOTAS_H_
#define ARRAYMASCOTAS_H_

typedef struct{
	int idCliente;
	char nombre[20];
	char sexo[10];

}eCliente;

typedef struct{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int idCliente;
	int edad;
	char vacunado;
	int isEmpty;

}eMascota;

#endif /* ARRAYMASCOTAS_H_ */

/// @brief Funcion encargada de inicializar el array de mascotas con su campo isEmpty en 1.
///
/// @param lista Array de mascotas.
/// @param tam Tamanio del array de mascotas.
/// @return Retorna 0 si tod0 OK o -1 en caso de error.
int inicializarMascotas(eMascota lista[], int tam);

/// @brief Funcion encargada del alta y validacion de las mascotas
///
/// @param lista Array de mascotas.
/// @param listaTipos Array de tipos de mascota.
/// @param listaColores Array de los colores disponibles.
/// @param tam Tamanio del array mascotas.
/// @param tamTipos Tamanio del array de tipos.
/// @param tamColores Tamanio del array de colores.
/// @param ids Puntero a variable que controla los ID de las mascotas.
/// @param cAltas Se usa de flag para controlar la cantidad de altas.
/// @return si la mascota se agrego ok 0, -1 en caso de error.
int nuevaMascota(eMascota lista[],eTipo listaTipos[],eColor listaColores[], int tam,
		int tamTipos,int tamColores,int*ids,int*cAltas,eCliente listaClientes[],int tamClientes);


/// @brief Funcion encargada de buscar un indice libre en el array de mascotas.
///
/// @param lista Array de mascotas.
/// @param tam Tamanio del array de mascotas.
/// @return Retorna el indice libre encontrado, en caso de no haber espacio retorna -1.
int buscarLibre(eMascota lista[],int tam);

/// @brief  Funcion encargada de dar de baja a la mascota cambiando el valor isEmpty.
///
/// @param lista Array de mascotas.
/// @param tam Tamanio del array de mascotas.
/// @param altas Puntero a variable que controla la cantidad de altas(utilizado como flag).
/// @return 0 si ok -1 si hay error
int bajaMascota(eMascota lista[],int tam,int*altas);

/// @brief  Esta funcion busca el indice que le corresponde al ID dado.
///
/// @param lista Array de mascotas.
/// @param tam Tamanio del array de mascotas.
/// @param idBusqueda ID del cual se desea saber su indice.
/// @return retorna el indice correspondiente al ID, en caso de no enctontrarlo retorna -1.
int buscarIndicexId(eMascota lista[],int tam,int idBusqueda);

/// @brief Funcion encargada de la modificacion de la mascota.
///
/// @param lista Array de mascotas.
/// @param listaTipos Array de los tipos de mascota disponible.
/// @param tam Tamanio del array de mascotas.
/// @param tamTipos Tamanio del array de los Tipos de mascota.
/// @return 0 si se modifico ok -1 en caso de error
int modificarMascota(eMascota lista[],eTipo listaTipos[],int tam,int tamTipos);

/// @brief Esta funcion ordena y luego lista a las mascotas por tipo, y en caso de ser iguales por nombre.
///
/// @param lista Array de mascotas.
/// @param listaTipos Array de tipos de mascota disponible.
/// @param tam Tamanio del array de mascotas.
/// @param tamTipos Tamanio del array de los tipos de mascota.
/// @param listaColores Array de colores disponibles.
/// @param tamColores Tamanio del array de colores.
/// @return 0 si ok -1 si hay error
int listarMascotas(eMascota lista[],eTipo listaTipos[],int tam,int tamTipos,eColor listaColores[],int tamColores,
		eCliente listaClientes[],int tamClientes);




