#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArch = fopen(path, "r");
	if(path != NULL && pArrayListEmployee != NULL && pArch != NULL)
	{
		retorno = parser_EmployeeFromText(pArch, pArrayListEmployee);

	}
	if(retorno == 0)
	{
		fclose(pArch);
		return retorno;
	}else{
		printf("Error al cargar desde el texto\n");
		fclose(pArch);
		return -1;
	}

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArch = fopen(path, "rb");
	if(path != NULL && pArch != NULL && pArrayListEmployee != NULL)
	{
		retorno = parser_EmployeeFromBinary(pArch, pArrayListEmployee);
	}
	if(retorno == 0)
	{
		fclose(pArch);
		return retorno;
	}else
	{
		printf("Error al cargar desde el binario\n");
		fclose(pArch);
		return -1;
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		Employee* this = employee_add();
		ll_add(pArrayListEmployee, this);
		retorno = 0;
		printf("Agregado con exito.\n");
	}else{
		printf("Error al agregar.\n");
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idComparar;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	Employee* auxEmployee;
	int idIngresado;
	int opcion;
	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese el id a modificar: ");
		if(getInt(&idIngresado) == 0)
		{
			for(i = 0;  i < ll_len(pArrayListEmployee); i ++)
			{
				auxEmployee = ll_get(pArrayListEmployee, i);
				if(auxEmployee != NULL)
				{
					employee_getId(auxEmployee, &idComparar);
					if(idIngresado == idComparar)
					{
						if(!utn_getNumero(&opcion,"1.Modificar Nombre.\n2.Modificar Horas.\n3.Modificar Sueldo.\n", "Error 1 a 4.\n", 1, 4, 2))
						{
							switch(opcion)
							{
							 	 case 1:
							 		 if(!utn_getNombre(auxNombre, 128, "Ingrese nuevo nombre: ", "Error reintente.\n", 2))
							 		 {
							 			 employee_setNombre(auxEmployee, auxNombre);
							 			 printf("Modificacion exitosa.\n");
							 		 }
							 		 break;
							 	 case 2:
							 		 if(!utn_getNumero(&auxHoras, "Ingrese la nueva cantidad de horas: ", "Error 1 a 1000.\n", 1, 1000, 2))
							 		 {
							 			 employee_setHorasTrabajadas(auxEmployee, auxHoras);
							 			 printf("Modificacion exitosa.\n");
							 		 }
							 		 break;
							 	 case 3:
							 		 if(!utn_getNumero(&auxSueldo, "Ingrese el nuevo sueldo: ", "Error 1000 a 1000000.\n", 1000, 1000000, 2))
							 		 {
							 			 employee_setSueldo(auxEmployee, auxSueldo);
							 			 printf("Modificacion exitosa.\n");
							 		 }
							 		 break;

							}
						}

					}else{
						printf("El id no existe.\n");
						break;
					}
				}

			}
		}

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idComparar;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	char confirma;
	Employee* auxEmployee;
	int idIngresado;
	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese el id a borrar: ");
		if(getInt(&idIngresado) == 0)
		{
			for(i = 0;  i < ll_len(pArrayListEmployee); i ++)
			{
				auxEmployee = ll_get(pArrayListEmployee, i);
				if(auxEmployee != NULL)
				{
					employee_getId(auxEmployee, &idComparar);
					if(idIngresado == idComparar)
					{
						employee_getNombre(auxEmployee, auxNombre);
						employee_getHorasTrabajadas(auxEmployee, &auxHoras);
						employee_getSueldo(auxEmployee, &auxSueldo);
						printf("Id: %d Nombre: %s Horas: %d Sueldo: %d.\n", idComparar, auxNombre, auxHoras, auxSueldo);
						printf("Seguro desea eliminar esta persona? s/n\n");
						scanf("%c", &confirma);
						if(confirma == 's')
						{
							employee_delete(auxEmployee);
							ll_remove(pArrayListEmployee, i);
							printf("Borrado con exito.\n");
							retorno = 0;
						}else
						{
							printf("No se borro\n");

						}

						break;
					}else{
						printf("El id no existe.\n");
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int id;
	int retorno = -1;
	char nombre[200];
	int horasTrabajadas;
	int sueldo;
	Employee* aux;
	if(pArrayListEmployee != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i ++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				employee_getId(aux,&id);
				employee_getNombre(aux, nombre);
				employee_getHorasTrabajadas(aux, &horasTrabajadas);
				employee_getSueldo(aux, &sueldo);
				printf("Id: %5d Nombre: %12s Horas Trabajadas: %5d Sueldo: %d\n", id, nombre, horasTrabajadas, sueldo);
				retorno = 0;
			}

		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployeeSueldo(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int asODes;
	int orden;
	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&asODes,"Ordenar: 1.Ascendente\n2.Descendente\n", "Error 1 o 2\n", 1, 2, 2))
		{
			if(asODes == 1)
			{
				orden = 1;
			}else
			{
				orden = 0;
			}
			ll_sort(pArrayListEmployee, employee_sortSueldo, orden);
			retorno = 0;
			printf("EPICO BRO\n");
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int flag = 0;
	FILE* pArchivo = fopen(path, "w");
	Employee* aux;
	char auxId[20];
	char auxNombre[128];
	char auxHoras[20];
	char auxSueldo[20];
	if(path != NULL && pArrayListEmployee != NULL && pArchivo != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i ++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				if(flag == 0)
				{
					fprintf(pArchivo ,"id,nombre,horasTrabajadas,sueldo\n");
					flag = 1;
				}
				employee_getIdTxt(aux, auxId);
				employee_getNombre(aux, auxNombre);
				employee_getHorasTrabajadasTxt(aux, auxHoras);
				employee_getSueldoTxt(aux, auxSueldo);
				fprintf(pArchivo,"%s,%s,%s,%s\n", auxId, auxNombre, auxHoras, auxSueldo);
				retorno = 0;

			}
		}
		if(retorno == 0)
		{
			printf("Cargado correctamente\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int flag = 0;
	char* encabezado = "id,nombre,horasTrabajadas,sueldo\n";
	FILE* pArchivo = fopen(path, "wb");
	Employee* aux;
	if(path != NULL && pArrayListEmployee != NULL && pArchivo != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i ++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				if(flag == 0)
				{
					fwrite(encabezado, sizeof(encabezado), 1,pArchivo);
					flag = 1;
				}
				fwrite(aux, sizeof(Employee), 1, pArchivo);
				retorno = 0;
			}
		}
		if(retorno == 0)
		{
			printf("Cargado correctamente\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

