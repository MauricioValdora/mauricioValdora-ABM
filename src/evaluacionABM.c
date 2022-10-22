/*
 ============================================================================
 Name        : evaluacionABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "tomarDatos.h"

#define TAM 4

int main(void) {
	setbuf(stdout,NULL);
	char respuesta='n';
	int id = 100;
	int idTrabajo =200;
	eNotebook lista[TAM];
	eTrabajo listaTrabajo[TAM];



	eMarca listaMarca[TAM] = {
			{1000,"Compaq"},
			{1001,"Asus"},
			{1002,"Acer"},
			{1003,"HP"}
	};
	eTipo listaTipo[TAM] = {
				{5000,"Gamer"},
				{5001,"Disenio"},
				{5002,"Ultrabook"},
				{5003,"Normalita"}
	};
	eServicio listaServicio[TAM] = {
				{20000,"Bateria",2250},
				{20001,"Display",2250},
				{20002,"Teclado",4400},
				{20003,"Fuente",5600}
	};
	inicializarNote(lista,TAM);
	inicializarTrabajo(listaTrabajo,TAM);
	do{
		switch(menu()){
		case 'a':altaNotebook(lista,TAM,&id);
		break;
		case 'b':modificarNotebook(lista,TAM);
		break;
		case 'c':bajaNotebook(lista,TAM);
		break;
		case 'd':
				ordenarNotebooks(lista, TAM),
				mostrarNotebooks(lista,TAM);
		break;
		case 'e': for(int i=0;i<TAM;i++){
			listarMarca(listaMarca[i]);
		}

		break;
		case 'f':for(int i=0;i<TAM;i++){
			listadorDeTipos(listaTipo[i]);
		}

		break;
		case 'g':for(int i=0;i<TAM;i++){
			listarServicios(listaServicio[i]);
		}
		break;
		case 'h':altaTrabajo(listaTrabajo,TAM,&idTrabajo);
		break;
		case 'j':printf("seguro que quiere salir");
		fflush(stdin);
		scanf("%c",&respuesta);
		break;
		default: printf("opcion invalida!!!\n");
		break;
		}
	}while(respuesta=='n');


	printf("%d",listaMarca->id);
	return EXIT_SUCCESS;
}
