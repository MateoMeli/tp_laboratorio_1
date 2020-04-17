#include <stdio.h>
#include <stdlib.h>
#include "FuncionesUtn.h"
#include "Calculadora.h"

/*
 * brief recibe dos float para sumarlos
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la suma
 * parameter numero1 primer numero float a sumar
 * parameter numero2 segundo numero float a sumar
 * return 0 si la suma salio bien
 */
int suma(float* pResultado, float numero1, float numero2)
{

	*pResultado = numero1 + numero2;
	return 0;
}


/*
 * brief recibe dos float para restarle el segundo al primero
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la resta
 * parameter numero1 primer numero float
 * parameter numero2 segundo numero float a restar
 * return 0 si la resta salio bien
 */
int resta(float* pResultado, float num1, float num2)
{
	*pResultado = num1 - num2;
	return 0;
}


/*
 * brief recibe dos float para hacer una division del primero por el segundo
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la division
 * parameter numero1 float dividendo
 * parameter numero2 float divisor
 * return 0 si la division es posible
 */
int division(float* pResultado, float num1, float num2)
{
	int retorno = -1;
	if(num2 == 0)
	{
		printf("Division anulada. No se puede dividir por cero.\n");
		retorno = -1;
	} else {
		*pResultado = num1 / num2;
		retorno = 0;
	}
	return retorno;

}

/*
 * brief recibedos float para multiplicarlos
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la multiplicacion
 * parameter numero1 primer numero
 * parameter numero2 segundo numero
 * return 0 si la multiplicacion salio bien
 */
int multiplicacion(float* pResultado, float num1, float num2)
{
	*pResultado = num1 * num2;
	return 0;
}


/*
 * brief recibe un float y realiza si factorial
 * parameter num el numero a factorializar
 * return si es 0 num era 0 o negativo y si es !=0 es el resultado del factorial
 */
float factorial(float num)
{
	float resp;
	if(num <= 0)
	{
		return 0;
	}
	if(num==1){
		return 1;
	}
	resp = num * factorial(num-1);
	return resp;
}


