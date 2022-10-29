/*
 * marca.c
 *
 *  Created on: Oct 25, 2022
 *      Author: mauriciov
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "notebook.h"
#include "tipo.h"
#include "validaciones.h"
#include "tomarDatos.h"


#define TAM 4




int convertirIdMarca(eMarca listaMarca[], int tam,int idMarca, char marca[]) {
	int todoOk = 0;
	if (listaMarca != NULL && tam > 0 && marca != NULL) {

		for (int i = 0; i < tam; i++) {
			if (listaMarca[i].id == idMarca) {

				strcpy(marca, listaMarca[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
void listarMarca(eMarca m ){
	printf("ID:%d ",m.id);
	printf("  %-10s\n",m.descripcion);

}

int mostrarNotebookMarcaSeleccionada(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli){
	int todoOk = 0;
	int marca;
	char descripcionTipo[20];

	if (lista != NULL && tam > 0 && listaTipo != NULL && lis_tam > 0 && listaMarca != NULL && tam_mar > 0) {
		printf("\n*****  MOSTRAR NOTEBOOKS DE UNA MARCA  *****\n\n");
		fflush(stdin);
		utn_getNumero(&marca,"ingrese que tipo de notebooks que quiere ver\n1000:Compaq\n1001:Asus\n1002:Acer\n1003:HP\n","Error ingrese una de las opciones\n", 1000, 1003, 3 );
		convertirIdMarca(listaMarca, tam, marca, descripcionTipo);
		printf("\nnotebooks de marca %s :\n", descripcionTipo);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idMarca == marca) {

				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}
		todoOk=1;
	}

	return todoOk;
}


