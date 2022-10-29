/*
 * trabajo.h
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
#include "marca.h"
#include "tipo.h"




typedef struct{

	int id;
	int idNotebook;
	int idServicio;
	int isEmpty;
	eFecha fecha;

}eTrabajo;


#endif /* TRABAJO_H_ */
///  @param trabajo estructura trabajo
/// @param tam el tamaño
/// @return inicializa el campo isEmpty en 1
int inicializarTrabajo(eTrabajo trabajo[],int tam);

/// @param trabajo se ingresa estructura trabajo
/// @param tam el tamaño
/// @return retorna el indice si encontro algun espacio parra un nuevo trabajo o -1 si no hay lugar
int buscarLibreTrabajo(eTrabajo trabajo[],int tam);

/// @param trabajo estructura trabajo
/// @param tam tamaño
/// @param lista estructura de notebooks
/// @param listaMarca estructura de marca
/// @param tam_mar tamaño de la marca
/// @param listaTipo la estructura del tipo
/// @param tam_lis el tamaño del tipo
/// @param listaServicio la estructura servicio
/// @param fecha estructura fecha
/// @param cliente estructrura cliente
/// @param tam_cli tamaño del cliente
/// @param pId el puntero del id de la notebook
/// @return 1 si fue exitoso 0 el caso contrario
int altaTrabajo(eTrabajo trabajo[],int tam,eNotebook lista[],eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int tam_lis,eServicio listaServicio[],eFecha fecha[],eCliente cliente[],int tam_cli,int* pId);

/// @param t estructura trabajo
/// @param tam el tamaño
/// @param lista estructura notebook
/// @param listaServicio estructura servicio
/// muestra un trabajo
void mostrarTrabajo(eTrabajo t,int tam,eNotebook lista[],eServicio listaServicio[]);

/// @param trabajos estructura trabajo
/// @param tam el tamaño
/// @param lista estructura notebooks
/// @param listaServicio estructura se servicios
/// @return muesta todos los trabajos
int mostrarTrabajos(eTrabajo trabajos[],int tam,eNotebook lista[],eServicio listaServicio[] );
