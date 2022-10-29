/*
 * cliente.h
 *
 *  Created on: Oct 28, 2022
 *      Author: mauriciov
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


typedef struct{
	int id;
	char nombre[20];
	char sexo;
}eCliente;

#endif /* CLIENTE_H_ */
/// @param cliente estructura cliente
/// @param tam el tamaño
/// @param idCliente el id que se busca
/// @param nombre devuelve por parametro el nombre del cliente
/// @return 1 si fue exitosa o 0 si no
int convertirIdCliente(eCliente cliente[], int tam,int idCliente, char nombre[]) ;
