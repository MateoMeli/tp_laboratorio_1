#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*brief devuelve un puntero a employee con memoria dinamica asignada
 *
 */
Employee* employee_new();

/*brief recibe todos los parametros de un empleado del tipo de dato de cada campo
 *
 *return retorna el puntero a un empleado cargado en todos sus campos creado en memoria dinamica
 */
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr);

/* brief recibe todos los parametros de un empleado pero todos los datos los recibe como cadenas de caracteres y los transforma para completar los campos
 *
 *return el puntero a un empleado creado en memoria dinamica con todos sus campos cargados
 */
Employee* employee_newParametrosString(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/*brief pide los datos necesarios para el ingreso de un empleado y lo agrega a la linked list
 *
 *return devuelve el puntero a ese empleado
 */
Employee* employee_add();

/* brief libera la memoria del empleado recibido por parametro
 *
 */
int employee_delete(Employee* this);

/*brief recibe dos punteros a dos empleados para compararlos por su sueldo
 *
 *retorna 1 si el primero es mayor que el segundo y -1 si es menor
 */
int employee_sortSueldo(void*, void*);

/*brief recibe el puntero a un alumno y el id a agregarle y comprueba los existentes para seguir una linea adecuada
 *
 */
int employee_setId(Employee* this,int id);

/*brief retorna en la variable id el valor del id del empleado pasado
 *
 */
int employee_getId(Employee* this,int* id);

/*brief retorna en la variable id el valor del id del empleado pasado pero como cadena de caracteres
 *
 */
int employee_getIdTxt(Employee* this,char* id);

/*brief recibe el puntero a un empleado y una cadena de caracteres y se la agrega en el campo empleado
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/*brief retorna en la variable nombre el valor del campo nombre del empleado pasado
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/*brief recibe el puntero a un alumno y las horas trabajadas a agregarle
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/*brief recibe el puntero a un alumno y las horas trabajadas a agregarle como cadena de caracteres
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);

/*brief retorna en la variable horasTrabajadas el valor del campo horasTrabajadas del empleado pasado
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/*brief retorna en la variable horasTrabajadas el valor del campo horasTrabajadas en cadena de caracteres del empleado pasado
 *
 */
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);

/*brief recibe el puntero a un alumno y el sueldo a agregarle
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/*brief recibe el puntero a un alumno y el sueldo a agregarle pero como cadena de caracteres
 *
 */
int employee_setSueldoTxt(Employee* this,char* sueldo);

/*brief retorna en la variable sueldo el valor del campo sueldo del empleado pasado
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/*brief retorna en la variable sueldo el valor del campo sueldo del empleado pasado pero como cadena de caracteres
 *
 */
int employee_getSueldoTxt(Employee* this,char* sueldo);
#endif // employee_H_INCLUDED
