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

/// @brief
///
/// @param listaMascotas
/// @param listaTipos
/// @param listaColores
/// @param tamMascotas
/// @param tamTipos
/// @param tamColores
/// @return
int imprimirMascotasColor(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[],
		int tamMascotas,int tamTipos,int tamColores);

/// @brief
///
/// @param listaMascotas
/// @param tamMascotas
/// @param altas
/// @return
int promedioDeVacunaciones(eMascota listaMascotas[],int tamMascotas,int altas);

/// @brief
///
/// @param listaMascotas
/// @param tamMascotas
/// @return
int informarMenorMascota(eMascota listaMascotas[],int tamMascotas);

/// @brief
///
/// @param listaMascotas
/// @param listaTipos
/// @param listaColores
/// @param tamMascotas
/// @param tamTipos
/// @param tamColores
/// @return
int cantidadColorYtipo(eMascota listaMascotas[],eTipo listaTipos[],eColor listaColores[],int tamMascotas,int tamTipos,int tamColores);

/// @brief
///
/// @param listaMascotas
/// @param listaColores
/// @param tamMascotas
/// @param tamColores
/// @return
int cantidadColores(eMascota listaMascotas[],eColor listaColores[],int tamMascotas,int tamColores);


