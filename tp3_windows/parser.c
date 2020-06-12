#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxId[50];
	char auxNombre[128];
	char auxHorasTrabajadas[50];
	char auxSueldo[50];
	char buffer[200];
	int flag = 0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(flag == 0)
			{
				fscanf(pFile,"%[^\n]",buffer);
				flag = 1;
			}
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo) == 4)
			{
				Employee* aux = employee_new();
				if(!employee_setId(aux, atoi(auxId)) && !employee_setNombre(aux, auxNombre) && !employee_setHorasTrabajadasTxt(aux, auxHorasTrabajadas)
									&& !employee_setSueldoTxt(aux, auxSueldo))
				{
					ll_add(pArrayListEmployee, aux);
					retorno = 0;
				}
			}



		}while(!feof(pFile));

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer[128];
	char* encabezado = "id,nombre,horasTrabajadas,sueldo\n";
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* aux = employee_new();
	int flag = 0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(flag == 0)
			{
				fread(buffer, sizeof(encabezado), 1, pFile);
				flag = 1;
			}

			if(fread(aux, sizeof(Employee), 1, pFile) == 1)
			{
				employee_getId(aux, &auxId);
				employee_getNombre(aux, auxNombre);
				employee_getHorasTrabajadas(aux, &auxHorasTrabajadas);
				employee_getSueldo(aux, &auxSueldo);
				Employee* auxFinal = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				ll_add(pArrayListEmployee, auxFinal);
				retorno = 0;
			}

		}while(!feof(pFile));
	}
    return retorno;
}







