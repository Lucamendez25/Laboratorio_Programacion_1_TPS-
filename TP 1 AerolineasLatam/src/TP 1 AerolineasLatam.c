/*
 ============================================================================
 Name        : TP.c
 Author      : Luca Méndez
 Version     : División K
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */


#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"



int main(void)
{
	setbuf(stdout, NULL);
	//KILOMETROS
	int kilometros;
	//PRECIOS AEROLINEAS/LATAM
	int precioAerolineas;
	int precioLatam;

	//CALCULOS:
	//AEROLINEAS
	float aerolineasTarjetaDebito;
	float aerolineasTarjetaCredito;
	double aerolineasBitcoin;
	float aerolineasPrecioKm;
	//LATAM
	float latamTarjetaDebito;
	float latamTarjetaCredito;
	double latamBitCoin;
	float latamPrecioKm;
	//DIFERENCIA ENTRE LOS DOS
	float diferencia;

	//BANDERAS
	int banderaKilometros;
	int banderaEmpresasVuelo;
	int banderaPreciosIngresados;
	int banderaCalculosForzados;

	//INICIALIZACIONES
	banderaKilometros=0;
	banderaEmpresasVuelo=0;
	banderaPreciosIngresados=0;
	banderaCalculosForzados=0;

	int opcion;
	do
	{
		printf( "1. Ingresar kilometros: \n"
				"2. Ingresar precio vuelos: \n"
				"-Precio vuelo Aerolineas: \n"
				"-Precio vuelo Latam: \n"
				"3. Calcular todos los costos: \n"
				"a)Tarjeta de débito (descuento 10%c)\n"
				"b)Tarjeta de crédito (interés 25%c)\n"
				"c)Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
				"d)Mostrar precio por km (precio unitario)\n"
				"e)Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n"
				"4. Informar resultados \n"
				"5. Carga forzada de datos\n"
				"6. Salir\n"
				"¿Qué opción elige?:", 37, 37);//fin print (menu principal
			scanf("%d", &opcion);


			switch(opcion)
			{
				case 1:
					printf("Ingrese kilometros: ");
					scanf("%d", &kilometros);

					while(kilometros<1)
					{
						printf("Error, ingrese una cantidad de kilometros válida: ");
						scanf("%d", &kilometros);
					}

					banderaKilometros = 1; //Ingresaron kilometros
					banderaCalculosForzados=0;

					printf("================================================\n");
					printf("=======Kilometros ingresados correctamente.=======\n");
					printf("================================================\n");
					system("pause");


					break;
				case 2:
					printf("Ingrese precio Aerolineas: ");
					scanf("%d",&precioAerolineas);

					while(precioAerolineas<1)
					{
						printf("Error ingrese precio Aerolineas válido: ");
						scanf("%d",&precioAerolineas);
					}


					printf("Ingrese precio Latam: ");
					scanf("%d",&precioLatam);

					while(precioLatam<1)
					{
						printf("Error ingrese precio Latam válido: ");
						scanf("%d",&precioLatam);
					}

					banderaEmpresasVuelo = 1;
					banderaCalculosForzados = 0;

					printf("================================================\n");
					printf("========Precios ingresados correctamente.=======\n");
					printf("================================================\n");
					system("pause");


					break;
				case 3:
					if( banderaCalculosForzados == 1 ||(banderaKilometros == 1 && banderaEmpresasVuelo == 1))
					{
						//AEROLINEAS
						aerolineasTarjetaDebito = precioAerolineas - descuentoDebito10(precioAerolineas);
						aerolineasTarjetaCredito= precioAerolineas + interes25Credito(precioAerolineas);
						aerolineasBitcoin = bitCoin(precioAerolineas);
						aerolineasPrecioKm = costoKm(precioAerolineas, kilometros);

						//LATAM
						latamTarjetaDebito = precioLatam - descuentoDebito10(precioLatam);
						latamTarjetaCredito =precioLatam + interes25Credito(precioLatam);
						latamBitCoin = bitCoin(precioLatam);
						latamPrecioKm = costoKm(precioLatam, kilometros);

						//COMPARACION
						diferencia = diferenciaAerolineasLatam(precioAerolineas, precioLatam);

						banderaPreciosIngresados=1;

						printf("================================================\n");
						printf("============Datos calculados correctamente.=======\n");
						printf("================================================\n");
						system("pause");

					}
					else
					{

						printf("================================================\n");
						printf("============Faltan datos por ingresar.==========\n");
						printf("================================================\n");
						system("pause");
					}
					break;
				case 4:
					if(banderaPreciosIngresados==1)
					{
						printf("\nKilomtros: %d km\n\n"
								"Aerolíneas:\n"
								"a) Precio con tarjeta de débito: %.2f\n"
								"b) Precio con tarjeta de crédito: %.2f\n"
								"c) Precio pagando con bitcoin: %.20lf\n"
								"d) Precio unitario:%.2f\n\n"
								"Latam:\n"
								"a) Precio con tarjeta de débito: %.2f\n"
								"b) Precio con tarjeta de crédito: %.2f\n"
								"c) Precio pagando con bitcoin : %.20lf\n"
								"d) Precio unitario: %.2f\n\n"
								"La diferencia de precio es : %.2f\n", kilometros,aerolineasTarjetaDebito, aerolineasTarjetaCredito, aerolineasBitcoin,
								aerolineasPrecioKm, latamTarjetaDebito, latamTarjetaCredito, latamBitCoin, latamPrecioKm, diferencia);
						system("pause");
					}
					else
					{
						printf("=================================================================================\n");
						printf("===Error, no se encontraron resultados para calcular o no se ingresaron datos.===\n");
						printf("=================================================================================\n");
						system("pause");

					}

					break;

				case 5:
					kilometros = 7090;
					precioAerolineas=162965;
					precioLatam=159339;
					banderaCalculosForzados=1;
					printf("================================================\n");
					printf("============Datos forzados correctamente.=======\n");
					printf("================================================\n");
					system("pause");
					break;

				case 6:
					printf("=================================================\n");
					printf("=========Cerrando programa, Hasta luego!==========\n");
					printf("=================================================\n");
					system("pause");

					break;

				default:

					printf("================================================\n");
					printf("=========Error, esa opcion no es valida.==========\n");
					printf("================================================\n");
					system("pause");

					break;
			}//FIN DEL SWITCH



	}while(opcion!=6);



	return EXIT_SUCCESS;
}//FIN DE LA FUNCION....
