/*
 * notebook.c
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "tomarDatos.h"
#include "tipo.h"

#define TAM 3

int convertirIdNotebook(eNotebook lista[], int tam,int idNotebook, char notebook[]) {
	int todoOk = 0;
	if (lista != NULL && tam > 0 && notebook != NULL) {

		for (int i = 0; i < tam; i++) {
			if (lista[i].id == idNotebook) {

				strcpy(notebook,lista[i].modelo );
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

int ordenarNotebooks(eNotebook lista[], int tam, eMarca listaMarca[], int tam_mar){

	eNotebook aux;
	int todoOk = 0;
	char marcaUno[20];
	char marcaDos[20];

	if(lista != NULL && tam > 0 && listaMarca != NULL && tam_mar > 0){
		for(int i = 0; i < tam-1; i++){
			for(int j = i+1; j < tam; j++){
				convertirIdMarca(listaMarca, tam, lista[i].idMarca, marcaUno);
				convertirIdMarca(listaMarca, tam, lista[j].idMarca, marcaDos);
				if( (strcmp(marcaUno, marcaDos) == 0 && lista[i].precio<lista[j].precio)|| strcmp(marcaUno, marcaDos) > 0){
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int notebooksMasBaratas(eNotebook lista[], int tam) {
	int todoOk = 0;
	float menorPrecio;

	if (lista != NULL && tam > 0) {

		printf("  ***notebook mas barata***   \n");
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam; j++) {
				if (i==0||(!lista[j].isEmpty
						&& lista[j].precio < lista[i].precio)){
					menorPrecio = lista[j].precio;
				}
			}
		}


		for (int i = 0; i < tam; i++) {
			if (menorPrecio == lista[i].precio) {
				printf("la notebook mas barata es %s con un precio de %f\n", lista[i].modelo,menorPrecio);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarNotebookListadasPorMarca(eNotebook lista[], int tam, eTipo listaTipo[], int lis_tam, eMarca listaMarca[], int tam_mar,eCliente cliente[],int tam_cli){
	int todoOk = 0;
	int compaq=1000;
	int asus=1001;
	int acer=1002;
	int hp=1003;

	char descripcionCompaq[20];
	char descripcionAsus[20];
	char descripcionAcer[20];
	char descripcionHp[20];


	if (lista != NULL && tam > 0 && listaTipo != NULL && lis_tam > 0 && listaMarca != NULL && tam_mar > 0) {
		printf("\n*****  MOSTRAR NOTEBOOKS POR MARCA  *****\n\n");
		fflush(stdin);
		convertirIdMarca(listaMarca, tam, compaq, descripcionCompaq);
		printf("\nnotebooks de marca %s :\n", descripcionCompaq);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idMarca == compaq) {
				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}
		convertirIdMarca(listaMarca, tam, asus, descripcionAsus);
		printf("\nnotebooks de marca %s :\n", descripcionAsus);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idMarca == asus) {
				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}convertirIdMarca(listaMarca, tam, acer, descripcionAcer);
		printf("\nnotebooks de marca %s :\n", descripcionAcer);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idMarca == acer) {
				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}convertirIdMarca(listaMarca, tam, hp, descripcionHp);
		printf("\nnotebooks de marca %s :\n", descripcionHp);
		for (int i = 0; i < tam; i++) {
			if (lista[i].idMarca == hp) {
				mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			}
		}
		todoOk=1;
	}

	return todoOk;
}

int cantidadNoteTipoMarcaSeleccionada(eNotebook lista[], int tam) {
	int todoOk = 0;
	int contador=0;

	if (lista != NULL && tam > 0 ) {
		printf("***Cantidad de notebooks de la marca HP y el tipo NORMALITA ***   \n\n");

			for (int j = 0; j < tam; j++) {
				if (!lista[j].isEmpty&&lista[j].idMarca ==1003&& lista[j].idTipo==5003) {
					contador++;
				}
			}

			printf("Cantidad de notebooks: %d\n", contador);
		todoOk = 1;
	}
	return todoOk;
}

int marcaMasElegidaPorCliente(eNotebook lista[], int tam,eMarca listaMarca[],int tam_mar) {

		int todoOk = 0;
		int contadores[] = { 0, 0, 0, 0};
		int mayor;

		if (lista != NULL && tam > 0 && listaMarca != NULL && tam_mar > 0) {

			printf("  ***MARCA MAS COMPRADA***   \n");
			for (int i = 0; i < tam_mar; i++) {
				for (int j = 0; j < tam; j++) {
					if (!lista[j].isEmpty
							&& lista[j].idMarca == listaMarca[i].id) {
						contadores[i]++;
					}
				}
			}

			for (int i = 0; i < tam_mar; i++) {
				if (i == 0 || contadores[i] > mayor) {
					mayor = contadores[i];
				}
			}

			for (int i = 0; i < tam_mar; i++) {
				if (contadores[i] == mayor) {
					printf("La marca mas comprada es %s\n", listaMarca[i].descripcion);
				}
			}
			todoOk = 1;
		}
		return todoOk;
}
