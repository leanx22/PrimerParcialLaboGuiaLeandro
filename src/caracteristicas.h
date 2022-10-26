/*
 * caracteristicas.h
 *
 *  Created on: 19 oct. 2022
 *      Author: leandro
 */

#ifndef CARACTERISTICAS_H_
#define CARACTERISTICAS_H_

typedef struct{
	int id;//comienza en 1000
	char descripcion[20];

}eTipo;

typedef struct{
	int id;//comienza en 5000
	char nombreColor[20];

}eColor;

#endif /* CARACTERISTICAS_H_ */

/// @brief Funcion que imprime en formato tabla todos los Tipos de mascotas disponibles.
///
/// @param lista Array de mascotas.
/// @param tam tamanio del array.
/// @return Retorna 0 si pudo imprimir tod OK o -1 en caso de error.
int imprimirTipos(eTipo lista[],int tam);

/// @brief Funcion creada para obtener un tipo por medio de su ID.
///
/// @param listaTipos Array de tipos de mascotas.
/// @param tamTipos Tamanio del array.
/// @param descripcion Puntero a variable donde se guardara el resultado obtenido.
/// @param id ID del tipo de mascota que se quiera obtener.
/// @return Retorna 0 si tod0 OK o -1 en caso de error.
int obtenerTipo(eTipo listaTipos[],int tamTipos,char*descripcion,int id);

/// @brief Funcion que muestra en formato tabla todos los colores disponibles y sus respectivos ID.
///
/// @param lista Array de colores.
/// @param tam Tamanio del array.
/// @return Retorna 0 si se pudo imprimir tod0 OK  o -1 en caso de error.
int imprimirColores(eColor lista[],int tam);

/// @brief Funcion creada para obtener la descripcion de un color por su ID.
///
/// @param listaColores Array de colores.
/// @param tamColores Tamanio del array colores.
/// @param descripcion Puntero a variable donde se guardara la descripcion obtenida.
/// @param id ID por el cual se buscara la descripcion correspondiente.
/// @return Retorna 0 si tod0 OK o -1 en caso de error.
int obtenerColor(eColor listaColores[],int tamColores, char*descripcion,int id);
