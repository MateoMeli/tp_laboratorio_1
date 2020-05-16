/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Arrayemployees.h"
#include <string.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 1000

int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmpleados[CANTIDAD_EMPLEADOS];
	int opcion;
	int idNuevoEmpleado;
	char nombreAux[100];
	char apellidoAux[100];
	float salarioAux;
	int sectorAux;
	int idEmpleadoModificacion;
	int idEmpleadoModificacion2;
	int opcionModificar;
	char nombreModificado[100];
	char apellidoModificado[100];
	float salarioModificado;
	int sectorModificado;
	int idEmpleadoBaja;
	int idEmpleadoBaja2;
	int flagOpcion1 = 0;
	int opcionInforme;
	int orden;
	float promedio;
	int superan;
	float total;

	initEmployees(arrayEmpleados, CANTIDAD_EMPLEADOS);

	do {
		if (!utn_getNumero(&opcion, "\n\n***EMPLEADOS***\n\n"
				"1.Altas\n"
				"2.Modificar\n"
				"3.Baja\n"
				"4.Informes\n"
				"5.Salir\n", "Error Reingrese\n", 1, 5, 2)) {
			if (opcion != 1 && flagOpcion1 == 0) {
				printf("Primero ingrese empleados.\n");
				opcion = 0;

			}
			if (opcion == 1) {
				flagOpcion1 = 1;
			}
			switch (opcion) {
			case 1:
				if (!findEmptyIndex(&idNuevoEmpleado, arrayEmpleados,
				CANTIDAD_EMPLEADOS)) {
					if (!utn_getNombre(nombreAux, 51, "Nombre: ",
							"Nombre invalido\n", 2)
							&& !utn_getNombre(apellidoAux, 51, "Apellido: ",
									"Apellido invalido\n", 2)
							&& !utn_getNumeroFlotante(&salarioAux, "Salario: ",
									"Salario invalido 1 a 100.000\n", 1, 100000,
									2)
							&& !utn_getNumero(&sectorAux, "Sector: ",
									"Sector inexistente", 1, 4, 2)) {

						if (!addEmployee(arrayEmpleados, CANTIDAD_EMPLEADOS,
								idNuevoEmpleado, nombreAux, apellidoAux,
								salarioAux, sectorAux)) {
							printf("Agregado con exito.\n");
						}
					}
				} else {
					printf(
							"Error al buscar id vacio o el array esta completo\n");
				}
				break;
			case 2:
				if (!utn_getNumero(&idEmpleadoModificacion,
						"Ingrese el Id del empleado a modificar: ",
						"No es valido o no existe reintente.\n", 1, 1000, 2)) {
					idEmpleadoModificacion2 = findEmployeeById(arrayEmpleados,
					CANTIDAD_EMPLEADOS, idEmpleadoModificacion);
					printf(
							"El empleado elegido es: ID:%d--Nombre:%s--Apellido:%s\n",
							arrayEmpleados[idEmpleadoModificacion2].id,
							arrayEmpleados[idEmpleadoModificacion2].name,
							arrayEmpleados[idEmpleadoModificacion2].lastName);
					if (!utn_getNumero(&opcionModificar,
							"Que desea modificar?\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n",
							"Opciones del 1 al 4", 1, 4, 2)) {
						switch (opcionModificar) {
						case 1:
							if (!utn_getNombre(nombreModificado, 51,
									"Nombre nuevo: ", "Nombre invalido", 2)) {
								strncpy(
										arrayEmpleados[idEmpleadoModificacion2].name,
										nombreModificado, 51);
								printf("Modificado con exito.\n");
								if (!printEmployee(arrayEmpleados,
								CANTIDAD_EMPLEADOS,
										arrayEmpleados[idEmpleadoModificacion2].id)) {
								}

							}
							break;
						case 2:
							if (!utn_getNombre(apellidoModificado, 51,
									"Apellido nuevo: ", "Apellido invalido\n",
									2)) {
								strncpy(
										arrayEmpleados[idEmpleadoModificacion2].lastName,
										apellidoModificado, 51);
								printf("Modificado con exito.\n");
								if (!printEmployee(arrayEmpleados,
								CANTIDAD_EMPLEADOS,
										arrayEmpleados[idEmpleadoModificacion2].id)) {
								}

							}
							break;
						case 3:
							if (!utn_getNumeroFlotante(&salarioModificado,
									"Nuevo salario: ", "Salario invalido \n", 1,
									100000, 2)) {
								arrayEmpleados[idEmpleadoModificacion2].salary =
										salarioModificado;
								printf("Modificado con exito.\n");
								if (!printEmployee(arrayEmpleados,
								CANTIDAD_EMPLEADOS,
										arrayEmpleados[idEmpleadoModificacion2].id)) {
								}
							}
							break;
						case 4:
							if (!utn_getNumero(&sectorModificado,
									"Nuevo sector: ", "Sector invalido 1 a 4\n",
									1, 4, 2)) {
								arrayEmpleados[idEmpleadoModificacion2].sector =
										sectorModificado;
								printf("Modificado con exito.\n");
								if (!printEmployee(arrayEmpleados,
								CANTIDAD_EMPLEADOS,
										arrayEmpleados[idEmpleadoModificacion2].id)) {
								}
							}
							break;
						}
					}
				}
				break;
			case 3:
				if (!utn_getNumero(&idEmpleadoBaja,
						"Ingrese el ID del empleado a dar de baja: ",
						"ID invalido 1 a 1000", 1, 1000, 2)) {
					idEmpleadoBaja2 = findEmployeeById(arrayEmpleados,
							CANTIDAD_EMPLEADOS, idEmpleadoBaja);
					if (!printEmployee(arrayEmpleados, CANTIDAD_EMPLEADOS,
							arrayEmpleados[idEmpleadoBaja2].id)) {
						if (removeEmployee(arrayEmpleados, CANTIDAD_EMPLEADOS,
								arrayEmpleados[idEmpleadoBaja2].id) == 0) {
							printf("Empleado eliminado correctamente.\n");
						}

					} else {
						printf("ID no registrado.\n");
					}
				}
				break;
			case 4:
				if (!utn_getNumero(&opcionInforme,
						"1.Empleados ordenados por apellido y sector.\n2.Total y promedio de los salarios y cantidad que superan el promedio.\n",
						"Opcion invalida 1 o 2.\n", 1, 2, 2)) {
					switch (opcionInforme) {
					case 1:
						if (!utn_getNumero(&orden,
								"1.Ascendente\n2.Descendente\n",
								"Opcion Invalida.\n", 1, 2, 2)) {
							switch (orden) {
							case 1:
								if (!sortEmployees(arrayEmpleados,
										CANTIDAD_EMPLEADOS, 1)) {
									if (!printEmployees(arrayEmpleados,
											CANTIDAD_EMPLEADOS)) {
									}
								}
								break;
							case 2:
								if (!sortEmployees(arrayEmpleados,
										CANTIDAD_EMPLEADOS, 0)) {
									if (!printEmployees(arrayEmpleados,
											CANTIDAD_EMPLEADOS)) {
									}
								}
								break;
							}
						}
						break;
					case 2:
						salarySort(arrayEmpleados, CANTIDAD_EMPLEADOS, &promedio, &total, &superan);
						printf("El total de los salarios es %f.\nEl promedio de los salarios es %f.\nY %d empleado/s supera/n el promedio.\n",
								total, promedio, superan);
						break;
					}
				}
				break;
			}

		}
	} while (opcion != 5);

	return 0;
}
