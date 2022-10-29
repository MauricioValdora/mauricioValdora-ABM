/*
 * servicio.h
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;
	char descripcion[20];
	int precio;
	int isEmpty;
}eServicio;



#endif /* SERVICIO_H_ */

int convertirIdServicio(eServicio servicios[], int tam,int idServicio, char servicio[]) ;
void listarServicios(eServicio s );
