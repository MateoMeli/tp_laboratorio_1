
/*brief recibe un puntero a linked list y un path de un archivo y lo abre y lo carga desde una lectura en modo texto a la linkedlist
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/*brief recibe un puntero a linked list y un path de un archivo y lo abre y lo carga desde una lectura en modo binario a la linkedlist
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/*brief agrega a la linked list un empleado verificado y cargado
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/*brief pregunta que dato se quiere modificar del empleado si es que existe y lo edita en la linked list
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/*brief pide el id de un empleado y lo borra de la linked list
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/*brief imprime todos los empleados existentes en forma de lista que esten en el linkedlist
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/*brief ordena los empleados por sueldo de forma ascendente o descendente
 *
 */
int controller_sortEmployeeSueldo(LinkedList* pArrayListEmployee);

/*brief guarda en un archivo en modo texto el linkedlist completo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/*brief guarda en un archivo en modo binario el linkedlist completo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


