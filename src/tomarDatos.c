/*
 * tomarDatos.c
 *
 *  Created on: Oct 21, 2022
 *      Author: mauriciov
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tomarDatos.h"
#include "validaciones.h"
#include "notebook.h"
#include "servicio.h"
#include "validaciones.h"



int menu(){

	char opcion;

	printf("   ******MENU******\n\n");
	printf(" A-Alta notebooks.\n");
	printf(" B-modificar notebooks.\n");
	printf(" C-baja notebooks.\n");
	printf(" D-lista notebooks.\n");
	printf(" E-listar marcas.\n");
	printf(" F-listar tipos.\n");
	printf(" G-listar servicios.\n");
	printf(" H-alta trabajo.\n");
	printf(" I-listar trabajo.\n");
	printf(" J-Sub menu de informes.\n");
	printf(" K-Salir.\n");
	fflush(stdin);
	scanf("%c",&opcion);

	return opcion;

}
int inicializarNote(eNotebook lista[],int tam){

	int todoOk=0;

	if(lista!=NULL&&tam>0)
	{
		for(int i = 0;i<tam;i++){
		lista[i].isEmpty = 1;
		todoOk=1;
		}
	}

	return todoOk;
}

int buscarLibre(eNotebook lista[],int tam){

	int indice = -1;
	for(int i=0;i<tam;i++){
		if(lista[i].isEmpty){
			indice=i;
			break;
		}
	}
	return indice;
}
int altaNotebook(eNotebook lista[],int tam,eMarca listaMarca[],eTipo listaTipo[],int* pId){

	int todoOk=0;
    int indice;
    int auxInt;
    float precio;
    char auxCadena[50];
    eNotebook auxNote;
	if(lista!=NULL&&tam>0&&listaMarca!=NULL&&listaTipo!=NULL){

		printf("*** Alta Notebook***\n\n");

		indice =buscarLibre(lista,tam);

		if (indice==-1){
			 printf("no hay lugar\n");
		}else{

			auxNote.id= *pId;
			(*pId)++;

			utn_getNombre( auxCadena, 50,"ingrese nombre del modelo \n", "error ingrese nombre nuevamente \n",3 );
			strcpy(auxNote.modelo,auxCadena);

			for(int i=0;i<4;i++){
				listarMarca(listaMarca[i]);
			}
			utn_getNumero(&auxInt,"ingrese numero de id de la marca \n","error \n", 1000, 1003, 3 );
			auxNote.idMarca = auxInt;

			for(int i=0;i<4;i++){
			listadorDeTipos(listaTipo[i]);
			}
			utn_getNumero(&auxInt,"ingrese numero de id del tipo \n","error \n", 5000, 5003, 3 );
			auxNote.idTipo = auxInt;

			input_GetFloat( &precio, "Ingrese precio", "error ingrese el precio nuevamente", 1, 1000000,3);
			auxNote.precio = precio;


			auxNote.isEmpty=0;

			lista[indice] = auxNote;

			todoOk=1;
		}
	}

	return todoOk;
}

void mostrarNotebook(eNotebook n,int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli){

	char tipo[20];
	char marca[20];
	char nombre[20];

	convertirIdMarca(listaMarca, tam, n.idMarca, marca);
	convertirIdTipo(listaTipo, tam, n.idTipo, tipo);
	convertirIdCliente(cliente,tam,n.idCliente,nombre);


	printf("%d|",n.id);
	printf("%-10s|",n.modelo);
	printf("%10s |",marca);
	printf(" %-10s| ",tipo);
	printf("%.2f| ",n.precio);
	printf("%s\n",nombre);

}

int mostrarNotebooks(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int tam_lis,eCliente cliente[],int tam_cli){

	int flag=1;

	int todoOk = 0;

			if(lista !=NULL&&tam>0&&listaMarca!=NULL&&tam_mar>0&&listaTipo!=NULL&&tam_lis>0&&cliente!=NULL&&tam_cli>0){

				printf("   *** Lista de notebooks ***\n");
				printf("----------------------------------------------------------\n");
				printf(" id  |  modelo  |  idMarca | idTipo  |  precio | Cliente |\n");
				printf("----------------------------------------------------------\n\n");
				for (int i = 0;i<tam ;i++)
				{

					if(!lista[i].isEmpty){
					mostrarNotebook(lista[i],tam,listaMarca,tam_mar,listaTipo,tam_lis,cliente,tam_cli);
					flag=0;
					}
				}
				if (flag){
					printf("no hay notebooks para mostrar \n\n");
				}
				todoOk=1;
			}

			return todoOk;
}
int buscarNotebook(eNotebook lista[],int tam,int id){

	int indice = -1;
	for(int i=0;i<tam;i++){
		if(!lista[i].isEmpty&&lista[i].id==id){
			indice=i;
			break;
		}
	}
	return indice;

}

int menuModificacion(){

	int opcion;

	printf(" 1-precio \n");
	printf(" 2-tipo\n");
	printf(" 3-salir\n");
	scanf("%d",&opcion);

	return opcion;

}
int modificarNotebook(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli){

	int todoOk=0;
	int indice;
	int id;
	char confirma;
	float precio;
	int auxTipo;
	//int auxPrecio;
	//eNotebook auxNotebook;

	if(lista!=NULL&&tam>0&&lista->isEmpty==0){

		printf("   ***Modificar notebook***\n\n");
		mostrarNotebooks(lista,tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
		printf(" ingrese id: ");
		scanf("%d",&id);
		indice = buscarNotebook(lista,tam,id);
		if (indice==-1){
			printf("El id %d no esta registrado en el sistema \n",id);
		}else{
			mostrarNotebook(lista[indice],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			printf("confirma modificacion?:");
			fflush(stdin);
			scanf("%c",&confirma);
			if(confirma=='s'){
				switch(menuModificacion()){
				case 1:
					fflush(stdin);
					input_GetFloat( &precio, "Ingrese nuevo precio", "error ingrese el precio nuevamente", 1, 1000000,3);
					lista[indice].precio = precio;
					break;
				case 2:
					fflush(stdin);
					for(int i=0;i<tam_mar;i++){
					listadorDeTipos(listaTipo[i]);}
					utn_getNumero(&auxTipo,"ingrese nuevo numero de id del tipo \n","error \n", 5000, 5003, 3 );
					lista[indice].idTipo = auxTipo;
					break;
				case 3:
					printf("quiere cancelar la modificacion?\n");
					fflush(stdin);
					scanf("%c",&confirma);
				if(confirma=='s'){
					printf("modificacion cancelada\n");
				};
					break;
				default:
					printf("opcion invalida!!!\n");
				}
				todoOk=1;
			}
		}
	}else{
		printf("para modificar primedo debe ingresar alguna notebook\n");
	}

	return todoOk ;
}
int bajaNotebook(eNotebook lista[],int tam,eMarca listaMarca[],int tam_mar,eTipo listaTipo[],int lis_tam,eCliente cliente[],int tam_cli){

	int todoOk=0;
	int indice;
	int id;
	char confirma;

	if(lista!=NULL&&tam>0&&lista->isEmpty==0){

		printf("   ***Baja Notebook***\n\n");
		if(mostrarNotebooks(lista,tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli)){

		printf(" Ingrese el ID del que quiere eliminar: \n");
		scanf("%d",&id);
		indice = buscarNotebook(lista,tam,id);
		if (indice==-1){
			printf("El ID %d no esta registrado en el sistema \n",id);
		}else{
			fflush(stdin);
			mostrarNotebook(lista[indice],tam,listaMarca,tam_mar,listaTipo,lis_tam,cliente,tam_cli);
			printf("confirma baja \n");
			fflush(stdin);
			scanf("%c",&confirma);
			if(confirma=='s'){
				lista[indice].isEmpty=1;
				todoOk=1;
			}else{
				printf("Baja cancelada por el usuario\n");
			}
		}
	}

	}else{
		printf("primero ingrese una notebook\n");
	}

	return todoOk ;
}
int menuInformes(){


	char respuesta;
	printf("           *** menu de informes***\n\n");
	printf(" A-mostrar las notebooks por tipo seleccionado por usuario.\n");
	printf(" B-Mostrar notebooks de una marca seleccionada por el usuario.\n");
	printf(" C-informar notebooks mas baratas .\n");
	printf(" D-notebooks separadas por marca.\n");
	printf(" E-notebooks de una marca seleccionada.\n");
	printf(" F-Mostrar marca mas elegida por los clientes.\n");
	printf(" G-Volver al menu principal.\n");
	fflush(stdin);
	scanf("%c",&respuesta);

	return respuesta;
}






