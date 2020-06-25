#include <stdlib.h>
#include <stdio.h>
#include "Articulo.h"
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"

static int getString(char *cadena, int longitud);

int controllerMenu(LinkedList* listaArticulos)
{
	int retorno = -1;
	int opcion;
	do{
		if(!utn_getNumero(&opcion, "1.Cargar el archivo\n2.Listar articulos\n3.Ordenar por nombre\n4.Aplicar descuentos\n5.Guardar en archivo con descuentos\n6.Salir\n",
				"Error 1 a 6", 1, 6, 3))
		{
			retorno = 0;
			switch(opcion)
			{
				case 1:
					if(!controller_parserFromText(listaArticulos)){printf("Cargado correctamente\n");}
					break;
				case 2:
					controller_listArticulos(listaArticulos);
					break;
				case 3:
					if(!controller_sortByArticulo(listaArticulos)){printf("Ordenados\n");}
					break;
				case 4:
					if(!controller_aplicarDescuentos(listaArticulos)){printf("Descuentos Aplicados\n");}
					break;
				case 5:
					if(!controller_saveAsText(listaArticulos)){printf("Guardado\n");}
					break;
			}
		}
	}while(opcion != 6);

	return retorno;
}

int controller_parserFromText(LinkedList *listaArticulos) {
	int retorno = -1;
	char path[100];
	printf("Ingrese la ruta o el nombre del archivo: ");
	if (!getString(path, 100)) {
		FILE *pFile = fopen(path, "r");
		if (path != NULL && listaArticulos != NULL && pFile != NULL) {
			retorno = parser_articulosFromText(pFile, listaArticulos);

		}
		if (retorno == 0) {
			fclose(pFile);
			return retorno;
		}
	} else {
		printf("Error con el archivo.\n");
		retorno = -1;
	}
	return retorno;
}

int parser_articulosFromText(FILE *pFile, LinkedList *listaArticulos) {
	int retorno = -1;
	int flag = 0;
	char auxId[20];
	char auxArticulo[100];
	char auxPrecio[20];
	char auxMedida[20];
	char auxRubroId[20];
	char buffer[200];
	if (pFile != NULL && listaArticulos != NULL) {
		do {
			if (flag == 0) {
				fscanf(pFile, "%[^\n]", buffer);
				flag = 1;
			}
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,
					auxArticulo, auxMedida, auxPrecio, auxRubroId) == 5) {
				eArticulo *aux = articulo_new();
				if (!articulo_setId(aux, atoi(auxId))
						&& !articulo_setArticulo(aux, auxArticulo)
						&& !articulo_setMedida(aux, auxMedida)
						&& !articulo_setPrecio(aux, atoi(auxPrecio))
						&& !articulo_setRubroId(aux, atoi(auxRubroId))) {
					ll_add(listaArticulos, aux);
					retorno = 0;
				}
			}

		} while (!feof(pFile));

	}

	return retorno;
}

int controller_listArticulos(LinkedList *listaArticulos) {
	int i;
	int retorno = -1;
	int auxId;
	char auxArticulo[100];
	char auxMedida[20];
	int auxPrecio;
	int auxRubro;
	eArticulo *aux;
	if (listaArticulos != NULL) {
		for (i = 0; i < ll_len(listaArticulos); i++) {
			aux = ll_get(listaArticulos, i);
			if (aux != NULL) {
				retorno = 0;
				articulo_getId(aux, &auxId);
				articulo_getArticulo(aux, auxArticulo);
				articulo_getMedida(aux, auxMedida);
				articulo_getPrecio(aux, &auxPrecio);
				articulo_getRubroId(aux, &auxRubro);
				switch (auxRubro) {
				case 1:
					printf(
							"Id: %5d Articulo: %50s Medida: %20s Precio: %5d Rubro: %20s\n",
							auxId, auxArticulo, auxMedida, auxPrecio,
							"CUIDADO DE ROPA");
					break;
				case 2:
					printf(
							"Id: %5d Articulo: %50s Medida: %20s Precio: %5d Rubro: %20s\n",
							auxId, auxArticulo, auxMedida, auxPrecio,
							"LIMPIEZA Y DESINFECCION");
					break;
				case 3:
					printf(
							"Id: %5d Articulo: %50s Medida: %20s Precio: %5d Rubro: %20s\n",
							auxId, auxArticulo, auxMedida, auxPrecio,
							"CUIDADO PERSONAL E HIGIENE");
					break;
				case 4:
					printf(
							"Id: %5d Articulo: %50s Medida: %20s Precio: %5d Rubro: %20s\n",
							auxId, auxArticulo, auxMedida, auxPrecio,
							"CUIDADO DEL AUTOMOTOR");
					break;
				}
			}
		}
	}
	return retorno;
}

static int getString(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096]; // *****************************

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_sortByArticulo(LinkedList *listaArticulos) {
	int retorno = -1;
	if (listaArticulos != NULL) {
		ll_sort(listaArticulos, articulo_sortArticulo, 1);
		retorno = 0;
	}
	return retorno;
}

int controller_aplicarDescuentos(LinkedList *listaArticulos) {
	int retorno = -1;
	if (listaArticulos != NULL) {
		ll_map(listaArticulos, articulo_descuentos);
		retorno = 0;
	}
	return retorno;
}

int controller_saveAsText(LinkedList *listaArticulos) {
	int retorno = -1;
	int i;
	int flag = 0;
	FILE *pArchivo = fopen("mapeado.csv", "w");
	eArticulo *aux;
	int auxId;
	char auxArticulo[100];
	char auxMedida[20];
	int auxPrecio;
	int auxRubro;
	if (listaArticulos != NULL && pArchivo != NULL) {
		for (i = 0; i < ll_len(listaArticulos); i++) {
			aux = ll_get(listaArticulos, i);
			if (aux != NULL) {
				if (flag == 0) {
					fprintf(pArchivo, "id,articulo,medida,precio,rubroId\n");
					flag = 1;
				}
				articulo_getId(aux, &auxId);
				articulo_getArticulo(aux, auxArticulo);
				articulo_getMedida(aux, auxMedida);
				articulo_getPrecio(aux, &auxPrecio);
				articulo_getRubroId(aux, &auxRubro);
				fprintf(pArchivo, "%d,%s,%s,%d,%d\n", auxId, auxArticulo, auxMedida, auxPrecio, auxRubro);
				retorno = 0;

			}
		}
		if (retorno == 0) {
			printf("Cargado correctamente\n");
		}
	}
	fclose(pArchivo);
	return retorno;
}

