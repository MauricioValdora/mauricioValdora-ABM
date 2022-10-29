/*
 * tomarDatos.h
 *
 *  Created on: Oct 21, 2022
 *      Author: mauriciov
 */

#ifndef TOMARDATOS_H_
#define TOMARDATOS_H_
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "cliente.h"


/// @return la opcion del menu elegida por el usuario
int menu();

/// @param lista estructura de notebooks
/// @param tam el tamaño
/// @return inicializa en 1 el campo isEmpry
int inicializarNote(eNotebook lista[],int tam);

/// @param lista estructura notebook
/// @param tam el tamaño
/// @return retorna el numero de indice o -1 si no hay lugar para un nuevo notebook
int buscarLibre(eNotebook lista[],int tam);

/// @param lista estructura lista
/// @param tam el tamaño
/// @param listaMarca estructura ed la marca
/// @param listaTipo estructura del tipo
/// @param pId ingresa por parametro el ID de la notebook
/// @return 1 si salio bien o 0 si no se pudo concretar
int altaNotebook(eNotebook lista[],int tam,eMarca listaMarca[],eTipo listaTipo[],int* pId);

/// @param n ingresa la estructura
/// @param tam el tamaño
/// @param listaMarca la marca
/// @param tam_mar el tamaño de la marca
/// @param listaTipo la estructura tipo
/// @param lis_tam el tamaño de la lista
/// @param cliente la estructura cliente
/// @param tam_cli el tamaño del cliente
void mostrarNotebook(eNotebook n,int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli);

/// @param lista la estructura notebook
/// @param tam el tamaño
/// @param listaMarca la estructura de la marca
/// @param tam_mar el tamaño de la marca
/// @param listaTipo la estructura del tipo
/// @param tam_lis el tamaño de la lista
/// @param cliente el cliente
/// @param tam_cli el tamaño del cliente
/// @return retorna 1 si esta todo bien sino 0
int mostrarNotebooks(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int tam_lis,eCliente cliente[],int tam_cli);

/// @param lista estructura de ls notebooks
/// @param tam el tamaño
/// @param id el id que se quiere encontrar
/// @return -1 si ese id no esta en el sistema o sino el indice donde esta ese id
int buscarNotebook(eNotebook lista[],int tam,int id);

/// @return la respuesta del usuario
int menuModificacion();

/// @param lista estructura notebooks
/// @param tam tamaño
/// @param listaMarca estructura de la marca
/// @param tam_mar el tamaño de la marca
/// @param listaTipo la estructura del tipo
/// @param lis_tam el tamaño de la lista
/// @param cliente estructura del cliente
/// @param tam_cli el tamaño del cliente
/// @return 1 si salio todo bien o 0 si no
int modificarNotebook(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli);

/// @param lista estructura de notebooks
/// @param tam el tamaño de la lista
/// @param listaMarca la estructura de la marca
/// @param tam_mar el tamaño de la marca
/// @param listaTipo la estructura del tipo
/// @param lis_tam el tamaño del tipo
/// @param cliente el cliente
/// @param tam_cli el tamaño del cliente
/// @return 1 si la baja fue exitosa o 0 si no se pudo efectuar
int bajaNotebook(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli);

/// @param lista estructura notebook
/// @param tam el tamaño de la estructura de las notebooks
/// @param listaTipo la estructura del tipo
/// @param lis_tam el tamaño
/// @param listaMarca la estructura de la marca
/// @param tam_mar el tamaño
/// @param cliente la estructura cliente
/// @param tam_cli el tamaño de la estructura cliente
/// @return muesta las notebooks ordenadas por marca retorna 1 en el caso que se pudo o 0 en el caso contrario
int mostrarNotebookListadasPorMarca(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli);

/// @param lista se ingresa la estructura
/// @param tam el tamaño de la lista
/// @param listaTipo la estructura del tipo
/// @param lis_tam el tamaño de la lista de tipos
/// @param listaMarca la estructura marca
/// @param tam_mar el ramaño de la estructura marca
/// @param cliente la estructura cliente
/// @param tam_cli el tamaño del cliente
/// @return muestra la cantidad de  notebook de la marca hp y normalita
int mostrarNotebookMarcaSeleccionada(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli);

int menuInformes();

#endif /* TOMARDATOS_H_ */
