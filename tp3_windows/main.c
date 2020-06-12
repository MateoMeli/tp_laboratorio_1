#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(!utn_getNumero(&option, "1.Cargar archivo en modo texto\n2.Cargar archivo modo binario\n3.Alta empleado\n4.Modificar empleado\n5.Baja empleado\n"
    			"6.Listar empleados\n7.Ordenar empleados por sueldo\n8.Guardar en archivo modo texto\n9.Guardar en archivo modo binario\n10.Salir\n", "Error, 1 a 10",
				1, 10, 3))
    	{
    		switch(option)
    		{
    			case 1:
    				if(controller_loadFromText("data.csv",listaEmpleados) == 0)
    				{
    					printf("Cargados correctamente.\n");
    				}
    		        break;
    			case 2:
    				if(controller_loadFromBinary("dataBin.csv", listaEmpleados) == 0)
    				{
    					printf("Cargados correctamente.\n");
    				}
    				break;
    			case 3:
    				controller_addEmployee(listaEmpleados);
    				break;
    			case 4:
    				controller_editEmployee(listaEmpleados);
    				break;
    			case 5:
    				controller_removeEmployee(listaEmpleados);
    				break;
    			case 6:
    				controller_ListEmployee(listaEmpleados);
    				break;
    			case 7:
    				controller_sortEmployee(listaEmpleados);
    				break;
    			case 8:
    				controller_saveAsText("data.csv", listaEmpleados);
    				break;
    			case 9:
    				controller_saveAsBinary("dataBin.csv", listaEmpleados);
    				break;
    		}
    	}
    }while(option != 10);

    return 0;
}
