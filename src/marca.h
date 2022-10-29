/*
 * marca.h
 *
 *  Created on: Oct 25, 2022
 *      Author: mauriciov
 */

#ifndef MARCA_H_
#define MARCA_H_
/*
#include "notebook.h"
#include "tipo.h"
*/


typedef struct{
	int id;
	char descripcion[20];
}eMarca;




#endif /* MARCA_H_ */
/// @param listaMarca se ingresa la estructura marca
/// @param tam el tamaño
/// @param idMarca el id de la marca que se busca
/// @param marca retorna por puntero el nombre de la marca
/// @return 1 si salio todo bien o 0 si hubo un error
int convertirIdMarca(eMarca listaMarca[], int tam,int idMarca, char marca[]) ;

/// @param m se le ingresa la estructura marca y la muesta
void listarMarca(eMarca m);

//int mostrarNotebookMarcaSeleccionada(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar);
