/*
 * cliente.c
 *
 *  Created on: Oct 28, 2022
 *      Author: mauriciov
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int convertirIdCliente(eCliente cliente[], int tam,int idCliente, char nombre[]) {
	int todoOk = 0;
	if (cliente != NULL && tam > 0 && cliente != NULL) {

		for (int i = 0; i < tam; i++) {
			if (cliente[i].id == idCliente) {

				strcpy(nombre, cliente[i].nombre);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
