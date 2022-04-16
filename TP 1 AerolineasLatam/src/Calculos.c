/*
 * Calculos.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Luca
 */
#include <stdio.h>
#include <stdlib.h>
float descuentoDebito10(int a)
{
	float descuento;
	descuento = (float) a * 0.10;

	return descuento;
}//DESCUENTO

float interes25Credito(int a)
{
	float interes;
	interes = (float) a * 0.25;
	return interes;
}//INTERES

double bitCoin(int a)
{
	double bitCoin;
	bitCoin =(float) a*1/4606954.55;
	return bitCoin;
}//BITCOIN

float costoKm(int a, int b)
{
	float resultado;
	resultado=(float)a/b;
	return resultado;
}

float diferenciaAerolineasLatam(int a, int b)
{
	int diferencia;

	diferencia = a-b;

	return diferencia;
}


