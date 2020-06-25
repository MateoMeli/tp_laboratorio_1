#ifndef ARTICULO_H_
#define ARTICULO_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	int id;
	char articulo[100];
	int precio;
	char medida[20];
	int rubroId;
}eArticulo;

eArticulo* articulo_new();

eArticulo* articulo_newParametros(int id, char* articulo, float precio, char* medida, int rubroId);

int articulo_getId(eArticulo* this, int* id);
int articulo_setId(eArticulo* this, int id);

int articulo_getArticulo(eArticulo* this, char* nomArticulo);
int articulo_setArticulo(eArticulo* this, char* nomArticulo);

int articulo_getPrecio(eArticulo* this, int* precio);
int articulo_setPrecio(eArticulo* this, int precio);

int articulo_getMedida(eArticulo* this, char* medida);
int articulo_setMedida(eArticulo* this, char* medida);

int articulo_getRubroId(eArticulo* this, int* rubroId);
int articulo_setRubroId(eArticulo* this, int rubroId);

void articulo_descuentos(void*);
int articulo_sortArticulo(void* p1, void* p2);

#endif /* ARTICULO_H_ */
