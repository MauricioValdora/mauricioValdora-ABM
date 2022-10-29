/*
 * servicio.c
 *
 *  Created on: Oct 26, 2022
 *      Author: mauriciov
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"



int convertirIdServicio(eServicio servicios[], int tam,int idServicio, char servicio[]) {
	int todoOk = 0;
	if (servicios != NULL && tam > 0 && servicios != NULL) {

		for (int i = 0; i < tam; i++) {
			if (servicios[i].id == idServicio) {

				strcpy(servicio,servicios[i].descripcion );
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

void listarServicios(eServicio s ){

	printf("ID:%d ",s.id);
	printf("  %10s",s.descripcion);
	printf("Precio:$%d\n",s.precio);

}

