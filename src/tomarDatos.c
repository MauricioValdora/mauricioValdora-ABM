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
	printf(" J-Salir.\n");

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
int altaNotebook(eNotebook lista[],int tam,int* pId){

	int todoOk=0;
    int indice;
    int auxInt;
    char auxCadena[50];
    eNotebook auxNote;
	if(lista!=NULL&&tam>0){

		printf("*** Alta Notebook***\n\n");

		indice =buscarLibre(lista,tam);

		if (indice==-1){
			 printf("no hay lugar\n");
		}else{

			auxNote.id= *pId;
			(*pId)++;

			utn_getNombre( auxCadena, 50,"ingrese nombre del modelo \n", "error ingrese nombre nuevamente \n",3 );
			strcpy(auxNote.modelo,auxCadena);

			utn_getNumero(&auxInt,"ingrese numero de id de la marca \n","error \n", 1, 100, 3 );
			auxNote.idMarca = auxInt;

			utn_getNumero(&auxInt,"ingrese numero de id del tipo \n","error \n", 1, 100, 3 );
			auxNote.idTipo = auxInt;

			utn_getNumero(&auxInt,"ingrese el precio \n","error \n", 1, 100, 3 );
			auxNote.idTipo = auxInt;


			auxNote.isEmpty=0;

			lista[indice] = auxNote;

			todoOk=1;
		}
	}

	return todoOk;
}

void mostrarNotebook(eNotebook n,int tam){

	printf("%d|",n.id);
	printf("%-10s|",n.modelo);
	printf("%10d |",n.idMarca);
	printf(" %-10d| ",n.idTipo);
	printf("%-10d| \n",n.precio);

}

int mostrarNotebooks(eNotebook lista[],int tam){

	int flag=1;

	int todoOk = 0;

			if(lista !=NULL&&tam>0){

				printf("   *** Lista de notebooks ***\n");
				printf("-------------------------------------------------\n");
				printf(" id  |  modelo  |  idMarca | idTipo  |  precio |\n");
				printf("-------------------------------------------------\n\n");
				for (int i = 0;i<tam ;i++)
				{

					if(!lista[i].isEmpty){
					mostrarNotebook(lista[i],tam);
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
	printf(" 3-tipo\n");
	scanf("%d",&opcion);

	return opcion;

}
int modificarNotebook(eNotebook lista[],int tam){

	int todoOk=0;
	int indice;
	int id;
	char confirma;
	int auxTipo;
	int auxPrecio;
	eNotebook auxNotebook;

	if(lista!=NULL&&tam>0){

		printf("   ***Modificar notebook***\n\n");
		printf(" ingrese id: ");
		scanf("%d",&id);
		indice = buscarNotebook(lista,tam,id);
		if (indice==-1){
			printf("El id %d no esta registrado en el sistema \n",id);
		}else{
			mostrarNotebook(lista[indice],tam);
			printf("confirma modificacion?:");
			fflush(stdin);
			scanf("%c",&confirma);
			if(confirma=='s'){
				switch(menuModificacion()){
				case 1:	printf("ingrese nuevo precio");
				scanf("%d",&auxPrecio);
				auxNotebook.precio = auxPrecio;
				break;
				case 2:utn_getNumero(&auxTipo,"ingrese nuevo numero de id del tipo \n","error \n", 1, 100, 3 );
				auxNotebook.idTipo = auxTipo;
				break;
				case 3:printf("quiere cancelar la modificacion?\n");
				fflush(stdin);
				scanf("%c",&confirma);
				if(confirma=='s'){
					printf("modificacion cancelada");
				};
				break;
				default:
					printf("opcion invalida!!!");
				}
				todoOk=1;
			}
		}
	}

	return todoOk ;
}
int bajaNotebook(eNotebook lista[],int tam){

	int todoOk=0;
	int indice;
	int id;
	char confirma;

	if(lista!=NULL&&tam>0){

		printf("   ***Baja jugador***\n\n");
		if(mostrarNotebooks(lista,tam)){

		printf(" Ingrese el ID del que quiere eliminar: \n");
		scanf("%d",&id);
		indice = buscarNotebook(lista,tam,id);
		if (indice==-1){
			printf("El ID %d no esta registrado en el sistema \n",id);
		}else{
			fflush(stdin);
			mostrarNotebook(lista[indice],tam);
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

	}

	return todoOk ;
}
int ordenarNotebooks(eNotebook lista[],int tam){
int todoOk=0;
eNotebook auxNotebook;

if(lista!=NULL&&tam>0){
	for(int i=0;i<tam-1;i++){
		for(int j = i+1;j<tam;j++){
			if(lista[i].idMarca>lista[j].idMarca||(lista[i].precio==lista[j].precio)){
				auxNotebook = lista[i];
				lista[i]=lista[j];
				lista[j]=auxNotebook;
			}
		}
	}
}
return todoOk;
}


void listadorDeTipos(eTipo t ){

	printf("ID:%d-",t.id);
	printf("Descripcion:%-10s\n",t.descripcion);

}
void listarMarca(eMarca m ){
	printf("ID:%d-",m.id);
	printf("Descripcion:%-10s\n",m.descripcion);

}
void listarServicios(eServicio s ){
	printf("ID:%d-",s.id);
	printf("Descripcion:%10s",s.descripcion);
	printf("Precio:$%d\n",s.precio);


}



int inicializarTrabajo(eTrabajo listaTrabajo[],int tam){

	int todoOk=0;

	if(listaTrabajo!=NULL&&tam>0)
	{
		for(int i = 0;i<tam;i++){
		listaTrabajo[i].isEmpty = 1;
		todoOk=1;
		}
	}

	return todoOk;
}

int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tam){

	int indice = -1;
	for(int i=0;i<tam;i++){
		if(listaTrabajo[i].isEmpty){
			indice=i;
			break;
		}
	}
	return indice;
}
int altaTrabajo(eTrabajo listaTrabajo[],int tam,int* pId){

	int todoOk=0;
    int indice;
    int auxInt;
    eTrabajo auxTrabajo;
	if(listaTrabajo!=NULL&&tam>0){

		printf("*** Alta de trabajo***\n\n");

		indice =buscarLibreTrabajo(listaTrabajo,tam);

		if (indice==-1){
			 printf("no hay lugar\n");
		}else{

			auxTrabajo.id= *pId;
			(*pId)++;


			utn_getNumero(&auxInt,"ingrese numero de id de notebook \n","error \n", 1, 100, 3 );
			auxTrabajo.idNote = auxInt;

			utn_getNumero(&auxInt,"ingrese numero de id del servicio \n","error \n", 1, 100, 3 );
			auxTrabajo.idServicio = auxInt;

			utn_getNumero(&auxInt,"ingrese el fecha \n","error \n", 1, 100, 3 );
			auxTrabajo.fecha = auxInt;


			auxTrabajo.isEmpty=0;

			listaTrabajo[indice] = auxTrabajo;

			todoOk=1;
		}
	}

	return todoOk;
}
