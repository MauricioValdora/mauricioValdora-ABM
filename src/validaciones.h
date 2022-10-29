/*
 * validaciones.h
 *
 *  Created on: Oct 21, 2022
 *      Author: mauriciov
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int myGets(char* cadena,int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int isValidNombre(char *pBuffer, int limite);
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int getString(char *pBuffer, int limite);
int input_GetFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries);
int getFloat(float* pResult);
int esFlotante(char *str) ;
#endif /* VALIDACIONES_H_ */
