#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrayemployees.h"
#include "utn.h"

//Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
//(isEmpty) en TRUE en todas las posiciones del array.
int initEmployees(Employee *list, int len) {
	int i;
	for (i = 0; i < len; i++) {
		list[i].isEmpty = EMPTY;

	}
	printf("Array inicializado correctamente\n\n");
	return 0;
}
//Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
//posición libre.
int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int retorno = -1;
	if (list[id].isEmpty == EMPTY) {
		list[id].id = id + 1;
		printf("ID: %d\n", list[id].id);
		strncpy(list[id].name, name, 51);
		strncpy(list[id].lastName, lastName, 51);
		list[id].salary = salary;
		list[id].sector = sector;
		list[id].isEmpty = OCCUPIED;
		retorno = 0;
	}
	return retorno;
}
//Busca un empleado recibiendo como parámetro de búsqueda su Id.
int findEmployeeById(Employee *list, int len, int id) {
	int i;
	int retorno = -1;
	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			retorno = i;
			break;
		}
	}
	return retorno;
}
//Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
int removeEmployee(Employee *list, int len, int id) {
	int i;
	int retorno = -1;

	for (i = 0; i < len; i++) {
		if (list[i].id == id && list[id].isEmpty == OCCUPIED) {
			list[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}

	return retorno;
}
//Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
int sortEmployees(Employee *list, int len, int order) {
	int i;
	Employee buffer;
	int retorno = -1;
	int flagSwap;
	if (list != NULL && len >= 0) {
		retorno = 0;
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (order == 0) {
					if (list[i].sector > list[i + 1].sector
							|| (list[i].sector == list[i + 1].sector
									&& strcmp(list[i].lastName,
											list[i + 1].lastName) > 0)) {
						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i + 1];
						list[i + 1] = buffer;
					}
				} else if (order == 1) {
					if (list[i].sector > list[i + 1].sector
							|| (list[i].sector == list[i + 1].sector
									&& strcmp(list[i].lastName,
											list[i + 1].lastName) < 0)) {
						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i + 1];
						list[i + 1] = buffer;
					}
				}

			}
			len--;
		} while (flagSwap);
	}

	return retorno;
}
//Imprime el array de empleados de forma encolumnada
int printEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == OCCUPIED) {
			printf(
					"ID: %d---Nombre: %s---Apellido: %s---Salario: %.2f---Sector: %d\n",
					list[i].id, list[i].name, list[i].lastName, list[i].salary,
					list[i].sector);
			retorno = 0;
		}
	}

	return retorno;
}

int findEmptyIndex(int *pIndex, Employee *list, int len) {
	int i;
	int retorno = -1;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == EMPTY) {
			retorno = 0;
			*pIndex = i;
			break;
		}
	}
	return retorno;
}

int printEmployee(Employee *list, int len, int id) {
	int i;
	int retorno = -1;
	for (i = 0; i < len; i++) {
		if (list[i].id == id && list[i].isEmpty == OCCUPIED) {
			printf(
					"ID:%d---Nombre:%s---Apellido:%s---Salario:%.2f---Sector:%d\n",
					list[i].id, list[i].name, list[i].lastName, list[i].salary,
					list[i].sector);
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int salarySort(Employee* list, int len, float* promedio, float* total, int* superan)
{
	int i;
	int contador = 0;
	int contadorSuperan = 0;
	float promedioActual;
	float acumulador;

	for(i = 0; i < len; i ++)
	{
		if(list[i].isEmpty == OCCUPIED)
		{
			acumulador = acumulador + list[i].salary;
			contador++;
		}
	}

	*promedio = acumulador/contador;
	*total = acumulador;
	promedioActual = acumulador/contador;
	for(i = 0; i < len; i ++)
	{
		if(list[i].isEmpty == OCCUPIED)
		{
			if(list[i].salary > promedioActual)
			{
				contadorSuperan ++;
			}
		}
	}
	*superan = contadorSuperan;

	return 0;
}
