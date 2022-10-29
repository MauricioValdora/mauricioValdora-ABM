/*
 * tipo.h
 *
 *  Created on: Oct 25, 2022
 *      Author: mauriciov
 */

#ifndef TIPO_H_
#define TIPO_H_
#include "marca.h"
#include "notebook.h"
#include "cliente.h"




typedef struct{
	int id;
	char descripcion[20];
}eTipo;


#endif /* TIPO_H_ */
/// @param listaTipo se ingresa la estuctura tipo
/// @param tam el tamaño
/// @param idTipo el id del tipo que queremos buscar
/// @param puntero que devuelve el nombre del tipo
/// @return retorna 1 si saio todo bien o 0 el caso contrario
int convertirIdTipo(eTipo listaTipo[], int tam,int idTipo, char tipo[]) ;

///lista todos los tipos
void listadorDeTipos(eTipo t );

/// @param lista se ingresa la estructura
/// @param tamvel tamaño
/// @param listaTipo la estructura del tipo
/// @param lis_tam el tamaño de la lista
/// @param listaMarca la estructura de la marca
/// @param tam_mar el tamaño de la marca
/// @param cliente la estructura cliente
/// @param tam_cli el tamaño del cliente
/// @return retorna notebook de el tipo que selecciona el ususario
int mostrarNotbookTipo(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli);
