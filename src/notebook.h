/*
 * notebook.h
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_
#include "marca.h"






typedef struct{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;
	int idCliente;
}eNotebook;

#endif /* NOTEBOOK_H_ */
/// @param lista se ingresa la estructura
/// @param tam un tamaño
/// @param idNotebook el id que se busca
/// @param notebook retorna por puntero el nombre de la descripcion
/// @return retorna 1 si salio todo bien o 0 si no se complreto la accion
int convertirIdNotebook(eNotebook lista[], int tam,int idNotebook, char notebook[]) ;


/// @param lista se ingresa la estructura
/// @param tam un tamaño
/// @param listaMarca la estructura de marca para swapear
/// @param tam_mar se ingresa el tamaño de la marca
/// @return 1 si esta todo bien 0 si no
int ordenarNotebooks(eNotebook lista[], int tam, eMarca listaMarca[], int tam_mar);

/// @param lista se ingresa estructura de notebook
/// @param tam el tamaño
/// @return  cual es la notebook mas barata
int notebooksMasBaratas(eNotebook lista[], int tam) ;

/// @param lista se ingresa estructura
/// @param tam un tamaño
/// @return cantidad de notebook de marca hp y normalita
int cantidadNoteTipoMarcaSeleccionada(eNotebook lista[], int tam) ;

/// @param lista se ingresa estructura
/// @param tam un tamaño
/// @param listaMarca la estrucutra de la marca
/// @param tam_mar el tmaaño de la marca
/// @return la marca mas elegida
int marcaMasElegidaPorCliente(eNotebook lista[], int tam,eMarca listaMarca[],int tam_mar);
