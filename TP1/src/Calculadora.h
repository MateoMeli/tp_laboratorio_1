#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/*
 * brief recibe dos float para sumarlos
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la suma
 * parameter numero1 primer numero float a sumar
 * parameter numero2 segundo numero float a sumar
 * return 0 si la suma salio bien
 */
int suma(float*, float, float);

/*
 * brief recibe dos float para restarle el segundo al primero
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la resta
 * parameter numero1 primer numero float
 * parameter numero2 segundo numero float a restar
 * return 0 si la resta salio bien
 */
int resta(float*, float, float);

/*
 * brief recibe dos float para hacer una division del primero por el segundo
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la division
 * parameter numero1 float dividendo
 * parameter numero2 float divisor
 * return 0 si la division es posible
 */
int division(float*, float, float);

/*
 * brief recibedos float para multiplicarlos
 * parameter pResultado es el puntero a float donde se va a almacenar el resultado de la multiplicacion
 * parameter numero1 primer numero
 * parameter numero2 segundo numero
 * return 0 si la multiplicacion salio bien
 */
int multiplicacion(float*, float, float);

/*
 * brief recibe un float y realiza si factorial
 * parameter num el numero a factorializar
 * return si es 0 num era 0 o negativo y si es !=0 es el resultado del factorial
 */
float factorial(float);

#endif /* CALCULADORA_H_ */
