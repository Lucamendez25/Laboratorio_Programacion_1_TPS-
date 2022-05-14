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
	eTipoPasajero tipoPasajero[3]={{1, "1era clase"}, {2, "2da clase"}, {3, "3ra clase"}};
	ePassenger listadoMain[A];
	iniciarPasajeros (listadoMain, A);
	harcodearPasajeros(listadoMain, A);
    menuPasajeros(listadoMain,A);

	return 0;
}
