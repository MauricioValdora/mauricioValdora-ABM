/*
 * tomarDatos.h
 *
 *  Created on: Oct 21, 2022
 *      Author: mauriciov
 */

#ifndef TOMARDATOS_H_
#define TOMARDATOS_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	char descripcion[20];
}eMarca;

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

typedef struct{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	int precio;
	int isEmpty;
}eNotebook;

typedef struct{
	int id;
	char descripcion[20];
	int precio;
	int isEmpty;
}eServicio;

typedef struct{
	int id;
	int idNote;
	int idServicio;
	int fecha;
	int isEmpty;
}eTrabajo;

int menu();
int inicializarNote(eNotebook lista[],int tam);
int buscarLibre(eNotebook lista[],int tam);
int altaNotebook(eNotebook lista[],int tam,int* pId);
void mostrarNotebook(eNotebook n,int tam);
int mostrarNotebooks(eNotebook lista[],int tam);
int buscarNotebook(eNotebook lista[],int tam,int id);
int menuModificacion();
int modificarNotebook(eNotebook lista[],int tam);
int bajaNotebook(eNotebook lista[],int tam);
int ordenarNotebooks(eNotebook lista[],int tam);
void listarMarca(eMarca m);
void listadorDeTipos(eTipo t );
void listarServicios(eServicio s );
int inicializarTrabajo(eTrabajo listaTrabajo[],int tam);
int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tam);
int altaTrabajo(eTrabajo listaTrabajo[],int tam,int* pId);



#endif /* TOMARDATOS_H_ */
