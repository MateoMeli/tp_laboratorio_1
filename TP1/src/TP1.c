/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "FuncionesUtn.h"
#include "Calculadora.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float num1 = 0;
	float num2 = 0;
	int respuesta1;
	int respuesta2;
	float resultSuma;
	float resultResta;
	float resultDivision;
	float resultMultiplicacion;
	float resultFac1;
	float resultFac2;
	int divisionOk;
	int flag1 = 0;
	int flag2 = 0;

	do {
		printf("***********Calculadora*************\n");
		printf("1.Ingresar 1er operando (A = %.3f)\n", num1);
		printf("2.Ingresar 2do operando (B = %.3f)\n", num2);
		printf("3.Calcular todas las operaciones.\n");
		printf("a) Calcular la suma (A + B)\n");
		printf("b) Calcular la resta (A - B)\n");
		printf("c) Calcular la division (A / B)\n");
		printf("d) Calcular la multiplicación (A * B)\n");
		printf("e) Calcular el factorial (A!) (B!)\n");
		printf("4. Informar resultados\n");
		printf("5.Salir.\n");
		printf("Elija la opcion deseada: ");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {

		case 1:
			if ((respuesta1 = utn_getFloat(&num1, "\nIngrese el primer numero deseado: ", "Error reingrese\n",-99999, 99999, 3)) != 0) {
				printf("Denegado\n");
			} else {
				flag1 = 1;
			}
			break;
		case 2:
			if ((respuesta2 = utn_getFloat(&num2, "\nIngrese el segundo numero deseado: ", "Error reingrese\n",-99999, 99999, 3)) != 0) {
				printf("Denegado\n");
			} else {
				flag2 = 1;
			}
			break;
		case 3:
			if (flag1 == 0 || flag2 == 0) {
				printf("No puede continuar si no ingresa numeros.\n");
				break;
			} else {
				suma(&resultSuma, num1, num2);
				resta(&resultResta, num1, num2);
				divisionOk = division(&resultDivision, num1, num2);
				multiplicacion(&resultMultiplicacion, num1, num2);
				resultFac1 = factorial(num1);
				resultFac2 = factorial(num2);
				printf("***OPERACIONES REALIZADAS CON EXITO***\n");
				break;
			}
		case 4:
			if (flag1 == 0 || flag2 == 0) {
				printf("No puede continuar si no ingresa numeros.\n");
				break;
			} else {
				printf("El resultado de %.3f + %.3f es %.3f.\n", num1, num2,resultSuma);
				printf("El resultado de %.3f - %.3f es %.3f.\n", num1, num2,resultResta);
				if (divisionOk == 0) {
					printf("El resultado de %.3f / %.3f es %.3f.\n", num1, num2,resultDivision);
				} else {
					printf("No se puede mostrar el resultado de la division debido a que ingreso cero como segundo numero.\n");
				}
				printf("El resultado de %.3f * %.3f es %.3f.\n", num1, num2,resultMultiplicacion);
				if (resultFac1 == 0) {
					printf("Esta calculadora no realiza factoriales de numeros negativos o de cero.\n");
				} else {
					printf("El factorial de %.3f es %.3f.\n", num1, resultFac1);
				}
				if (resultFac2 == 0) {
					printf("Esta calculadora no realiza factoriales de numeros negativos o de cero.\n");
				} else {
					printf("El factorial de %.3f es %.3f.\n", num2, resultFac2);
				}


				break;
			}

		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}
