/*
 ============================================================================
 Name        : SegundoParcialMeli.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"


int main(void) {
	setbuf(stdout, NULL);
	LinkedList* listaArticulos = ll_newLinkedList();
	controllerMenu(listaArticulos);
	return 0;
}
