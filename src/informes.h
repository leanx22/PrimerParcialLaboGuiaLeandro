/*
 * informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: leandro
 */
#include "arrayMascotas.h"
#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */

/// @brief Funcion que imprime las mascotas de x color.
///
/// @param listaMascotas Array de mascotas.
/// @param listaTipos Array de tipos de mascota.
/// @param listaColores Array de colores
/// @param tamMascotas tamanio del array
/// @param tamTipos tamanio del array
/// @param tamColores tamanio del array
/// @return retorna 0 si OK o -1 en caso de error.
int imprimirMascotasColor(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[],
		int tamMascotas,int tamTipos,int tamColores);

/// @brief Funcion que calcula el promedio y porcentaje de las mascotas vacunadas.
///
/// @param listaMascotas Array de mascotas
/// @param tamMascotas tamanio del array
/// @param altas Contador de las altas totales.
/// @return retorna 0 si OK o -1 en caso de error.
int promedioDeVacunaciones(eMascota listaMascotas[],int tamMascotas,int altas);

/// @brief Funcion que informa el nombre y la edad de la mascota mas pequenia.
///
/// @param listaMascotas array de mascotas.
/// @param tamMascotas tamanio del array
/// @return retorna -1 si hay error o 0 si OK.
int informarMenorMascota(eMascota listaMascotas[],int tamMascotas);

/// @brief Funcion que informa la cantidad de mascotas que cumplen con las caracteristicas dadas.
///
/// @param listaMascotas array de mascotas
/// @param listaTipos array de tipos
/// @param listaColores array de colores
/// @param tamMascotas tamanio del array
/// @param tamTipos tamanio del array
/// @param tamColores tamanio del array
/// @return retorna 0 si OK o 01 en caso de error.
int cantidadColorYtipo(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[],int tamMascotas,int tamTipos,int tamColores);

/// @brief Funcion que informa sobre el color con mas cantidad de mascotas.
///
/// @param listaMascotas array de mascotas
/// @param listaColores array de colores
/// @param tamMascotas tamanio del array
/// @param tamColores tamanio del array
/// @return retorna 0 si OK o -1 en caso de error.
int cantidadColores(eMascota listaMascotas[],eColor listaColores[],int tamMascotas,int tamColores);


