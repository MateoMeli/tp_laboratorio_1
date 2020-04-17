#include <stdlib.h>
#include <stdio.h>
#include "FuncionesUtn.h"

/*
 * brief pide un numero al usuario lo valida y lo almacena en una variable
 * parameter pResultado puntero a la variable donde se va a almacenar el numero pedido
 * parameter mensaje es el mensaje con el que pide el numero
 * parameter mensajeError es el mensaje con el que pide el reingreso en caso de encontrar error en la validacion
 * parameter minimo es el valor minimo que se toma como valido en este ingreso
 * parameter maximo es el valor maximo que se toma como valido en este ingreso
 * parameter reintentos es el numero de reintentos a darle al usuario en caso de error
 * return 0 si sale bien -1 si sale mal
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int ret = -1;
	int num;
	while (reintentos > 0) {
		printf(mensaje);
		scanf("%d", &num);
		if (num <= maximo && num >= minimo) {
			break;
		}
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

/*
 * brief pide un numero float al usuario lo valida y lo almacena en una variable
 * parameter pResultado puntero a la variable donde se va a almacenar el numero pedido
 * parameter mensaje es el mensaje con el que pide el numero
 * parameter mensajeError es el mensaje con el que pide el reingreso en caso de encontrar error en la validacion
 * parameter minimo es el valor minimo que se toma como valido en este ingreso
 * parameter maximo es el valor maximo que se toma como valido en este ingreso
 * parameter reintentos es el numero de reintentos a darle al usuario en caso de error
 * return 0 si sale bien -1 si sale mal
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int ret;
	float num;
	while (reintentos > 0) {
		printf(mensaje);
		scanf("%f", &num);
		if (num <= maximo && num >= minimo) {
			break;
		}
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

/*
 * brief pide un caracter al usuario lo valida y lo almacena en una variable
 * parameter pResultado puntero a la variable donde se va a almacenar el caracter pedido
 * parameter mensaje es el mensaje con el que pide el caracter
 * parameter mensajeError es el mensaje con el que pide el reingreso en caso de encontrar error en la validacion
 * parameter minimo es el valor minimo que se toma como valido en este ingreso
 * parameter maximo es el valor maximo que se toma como valido en este ingreso
 * parameter reintentos es el numero de reintentos a darle al usuario en caso de error
 * return 0 si sale bien -1 si sale mal
 */
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos) {

	int retorno = -1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

