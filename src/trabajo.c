/*
 * trabajo.c
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "tipo.h"
#include "notebook.h"
#include "tomarDatos.h"

#include "validaciones.h"



int inicializarTrabajo(eTrabajo trabajo[],int tam){

	int todoOk=0;

	if(trabajo!=NULL&&tam>0)
	{
		for(int i = 0;i<tam;i++){
		trabajo[i].isEmpty = 1;
		todoOk=1;
		}
	}

	return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajo[],int tam){

	int indice = -1;
	for(int i=0;i<tam;i++){
		if(trabajo[i].isEmpty){
			indice=i;
			break;
		}
	}
	return indice;
}
int altaTrabajo(eTrabajo trabajo[],int tam,eNotebook lista[],eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int tam_lis,eServicio listaServicio[],eFecha fecha[],eCliente cliente[],int tam_cli,int* pId){

	int todoOk=0;
    int indice;
    int auxInt;
    eTrabajo auxTrabajo;
	if(lista!=NULL&&tam>0&&trabajo!=NULL&&listaMarca!=NULL&&tam_mar>0&&listaTipo!=NULL&&tam_lis>0&&listaServicio!=NULL&&fecha!=NULL&&cliente!=NULL&&tam_cli>0){

		printf("*** Alta Trabajo***\n\n");

		indice =buscarLibreTrabajo(trabajo,tam);

		if (indice==-1||lista->isEmpty==1||listaServicio->isEmpty==0){
			 printf("Primero debe ingresar notebooks y servicios \n");
		}else{

			auxTrabajo.id= *pId;
			(*pId)++;
			mostrarNotebooks(lista,tam,listaMarca,tam_mar,listaTipo,tam_lis,cliente,tam_cli);
			fflush(stdin);
			utn_getNumero(&auxInt,"ingrese ID de la notebook \n","error ingrese ID  \n", 100, 1003, 3 );
			auxTrabajo.idNotebook=auxInt;
			for(int i = 0;i<4;i++){
			listarServicios(listaServicio[i]);
			}
			utn_getNumero(&auxInt,"ingrese ID del servicio \n","error ingrese ID \n", 20000, 20003, 3 );
			auxTrabajo.idServicio = auxInt;

			utn_getNumero(&auxInt,"ingrese dia\n","error ingrese ID \n", 1, 31, 3 );
			auxTrabajo.fecha.dia=auxInt;
			utn_getNumero(&auxInt,"ingrese mes\n","error ingrese ID \n", 1, 12, 3 );
			auxTrabajo.fecha.mes=auxInt;
			utn_getNumero(&auxInt,"ingrese año\n","error ingrese ID \n", 1990, 2100, 3 );
			auxTrabajo.fecha.anio=auxInt;

			auxTrabajo.isEmpty=0;

			trabajo[indice] = auxTrabajo;

			todoOk=1;
		}
	}

	return todoOk;
}


void mostrarTrabajo(eTrabajo t,int tam,eNotebook lista[],eServicio listaServicio[]){

	char note[20];
	char servicio[20];

	convertirIdNotebook(lista, tam, t.idNotebook, note);
	convertirIdServicio(listaServicio,tam,t.idServicio,servicio);


	printf("%d|",t.id);
	printf("%10s|",note);
	printf("%10s |",servicio);
	printf(" %d/%d/%d |\n",t.fecha.dia,t.fecha.mes,t.fecha.anio);

}

int mostrarTrabajos(eTrabajo trabajos[],int tam,eNotebook lista[],eServicio listaServicio[] ){

	int flag=1;

	int todoOk = 0;

			if(lista !=NULL&&tam>0&&trabajos!=NULL&&listaServicio!=NULL){

				printf("   *** Lista de trabajos ***\n");
				printf("----------------------------------------\n");
				printf(" id  |  NoteBook  |  Servicio | Fecha  |\n");
				printf("----------------------------------------\n\n");
				for (int i = 0;i<tam ;i++)
				{

					if(!trabajos[i].isEmpty){
					mostrarTrabajo(trabajos[i],tam,lista,listaServicio);
					flag=0;
					}
				}
				if (flag){
					printf("no hay trabajos para mostrar \n\n");
				}
				todoOk=1;
			}else{
				printf("primero ingrese un trabajo\n");
			}

			return todoOk;
}

