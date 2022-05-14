/*
 ============================================================================
 Name        : TP2.c
 Author      : Luca Méndez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#define A 10
int main(void)
{

	setbuf(stdout, NULL);
	ePassenger listadoMain[A];
	iniciarPasajeros (listadoMain, A);
	harcodearPasajeros(listadoMain, A);
    menuPasajeros(listadoMain,A);

	return 0;
}
