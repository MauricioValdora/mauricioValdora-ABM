/*
 * tipo.c
 *
 *  Created on: Oct 25, 2022
 *      Author: mauriciov
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "tipo.h"
#include "notebook.h"
#include "tomarDatos.h"







int convertirIdTipo(eTipo listaTipo[], int tam,int idTipo, char tipo[]) {
	int todoOk = 0;
	if (listaTipo != NULL && tam > 0 && tipo != NULL) {

		for (int i = 0; i < tam; i++) {
			if (listaTipo[i].id == idTipo) {

				strcpy(tipo, listaTipo[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

void listadorDeTipos(eTipo t ){

	printf("ID:%d ",t.id);
	printf("  %-10s\n",t.descripcion);

}

int mostrarNotbookTipo(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli){
	int todoOk = 0;
	int tipo;
	char descripcionTipo[20];

	if (lista != NULL && tam > 0 && listaTipo != NULL && lis_tam > 0 && listaMarca != NULL && tam_mar > 0) {
		printf("\n*****  MOSTRAR NOTEBOOKS DE UN TIPO  *****\n\n");
		fflush(stdin);
		utn_getNumero(&tipo,"ingrese que tipo de notebooks que quiere ver\n5000:gamer\n5001:diseño\n5002:ultrabook\n5003:normalita\n","Error ingrese una de las opciones\n", 5000, 5003, 3 );
		convertirIdTipo(listaTipo, tam, tipo, descripcionTipo);
		printf("\n notebooks del tipo %s :\n", descripcionTipo);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idTipo == tipo) {

				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}
		todoOk=1;
	}

	return todoOk;
}
