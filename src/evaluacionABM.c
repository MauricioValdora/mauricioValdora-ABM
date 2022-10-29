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
#include "notebook.h"
#include "validaciones.h"
#include "tomarDatos.h"
#include "marca.h"
#include "tipo.h"
#include "trabajo.h"
#include "servicio.h"
#include "cliente.h"



#define TAM 8
#define TAM_MAR 4
#define LIS_TAM 4
#define TAM_TRA 4
#define TAM_SER 4
#define TAM_TIP 4
#define TAM_CLI 8



int main(void) {

	setbuf(stdout,NULL);
	char respuesta='n';
	int id = 100;
	int idTrabajo =200;

	eNotebook lista[TAM]={
			{100,"la mejor",1003,5003,300.22,0,1},
			{101,"normalita",1003,5001,344.76,0,2},
			{102,"el mounstro",1002,5001,588.55,0,3},
			{103,"la loca",1003,5003,123.2,0,4},
			{104,"destructora",1000,5000,300.22,0,5},
			{105,"indistrial",1001,5001,344.76,0,6},
			{106,"androide",1002,5002,1000.55,0,7},
			{107,"amapola robot",1003,5003,123.2,0,8}

	};
	eTrabajo trabajo[TAM_TRA];
	eFecha fecha[TAM_TRA];
	eCliente cliente[TAM_CLI]={
			{1,"pepe",'m'},
			{2,"julia",'f'},
			{3,"ernesto",'m'},
			{4,"priscila",'f'},
			{5,"carolina",'f'},
			{6,"leonardo",'m'},
			{7,"antonela",'f'},
			{8,"stephania",'f'}
	};


	eMarca listaMarca[TAM_MAR] = {
				{1000,"Compaq"},
				{1001,"Asus"},
				{1002,"Acer"},
				{1003,"HP"}
		};
	eServicio listaServicio[TAM_SER] = {
					{20000,"Bateria",2250,1},
					{20001,"Display",2250,1},
					{20002,"Teclado",4400,1},
					{20003,"Fuente",5600,1}
		};

	eTipo listaTipo[TAM_TIP] = {
					{5000,"Gamer"},
					{5001,"Disenio"},
					{5002,"Ultrabook"},
					{5003,"Normalita"}
		};

	//inicializarNote(lista,TAM);
	inicializarTrabajo(trabajo,TAM_TRA);
	do{
		switch(menu()){
		case 'a':altaNotebook(lista,TAM,listaMarca,listaTipo,&id);
		break;
		case 'b':modificarNotebook(lista,TAM,listaMarca,TAM_MAR,listaTipo,LIS_TAM,cliente,TAM_CLI);
		break;
		case 'c':bajaNotebook(lista,TAM,listaMarca,TAM_MAR,listaTipo,LIS_TAM,cliente,TAM_CLI);
		break;
		case 'd':
			ordenarNotebooks(lista,TAM,listaMarca,TAM_MAR);
			mostrarNotebooks(lista,TAM,listaMarca,TAM_MAR,listaTipo,LIS_TAM,cliente,TAM_CLI);
		break;
		case 'e': for(int i=0;i<TAM_MAR;i++){
			listarMarca(listaMarca[i]);
		}

		break;
		case 'f':for(int i=0;i<TAM_TIP;i++){
			listadorDeTipos(listaTipo[i]);
		}
		break;
		case 'g':for(int i=0;i<TAM_SER;i++){
			listarServicios(listaServicio[i]);
		}
		break;
		case 'h':altaTrabajo(trabajo,TAM,lista,listaMarca,TAM_MAR,listaTipo,LIS_TAM,listaServicio,fecha,cliente,TAM_CLI,&idTrabajo);
		break;
		case 'i':mostrarTrabajos(trabajo,TAM_TRA,lista,listaServicio);
			break;
		case 'k':printf("seguro que quiere salir\nIngrese -s- o -n-\n");
			fflush(stdin);
			scanf("%c",&respuesta);
		while(respuesta!='s'&&respuesta!='n'){
			printf("ingrese -s- para salir o -n- cancelar la salida");
			fflush(stdin);
			scanf("%c",&respuesta);
		}
		if(respuesta=='s'){
			printf("Muchas gracias por usar la app :)");
		}
		break;
		case 'j':switch(menuInformes()){
		case 'a':mostrarNotbookTipo(lista,TAM,listaTipo,LIS_TAM,listaMarca,TAM_MAR,cliente,TAM_CLI);
		break;
		case 'b':mostrarNotebookMarcaSeleccionada(lista,TAM,listaTipo,LIS_TAM,listaMarca,TAM_MAR,cliente,TAM_CLI);
		break;
		case 'c':notebooksMasBaratas(lista,TAM);
		break;
		case 'd':mostrarNotebookListadasPorMarca(lista,TAM,listaTipo,LIS_TAM,listaMarca,TAM_MAR,cliente,TAM_CLI);
		break;
		case 'e':cantidadNoteTipoMarcaSeleccionada(lista,TAM);
		break;
		case 'f':marcaMasElegidaPorCliente(lista,TAM,listaMarca,TAM_MAR);
		break;
		case 'g':printf("\n\n");
		break;
		default: printf("opcion invalida!!!\n");
		break;
		}
		break;
		default: printf("opcion invalida!!!\n");
		break;
		}
	}while(respuesta=='n');

	return EXIT_SUCCESS;
}
