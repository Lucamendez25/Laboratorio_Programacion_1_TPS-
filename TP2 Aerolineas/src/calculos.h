/*
 * calculos.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luca
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define A 10


typedef struct
{
	int typePassenger;
	char descripcion[21];
}eTipoPasajero;

typedef struct
{
	int statusFlight;
	char descripcion[21];
}eEstadoVuelo;


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;//ESTADO
}ePassenger;
/** \brief Inicializa el valor vacio en la estructura de pasajeros
 *
 * \param ePassenger[]
 * \param int
 * \return int
 *
 */
int iniciarPasajeros(ePassenger[], int);

/** \brief Muestra el menu principal
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void menuPasajeros(ePassenger[], int);

/** \brief Permite el agregado de datos de un pasajero
 *
 * \return sEmpleado
 *
 */
ePassenger agregarPasajeros();

/** \brief Submenu que muestra los informes disponibles
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void subMenuInformes(ePassenger[],int);

/** \brief Carga de un valor numerico el ID de forma automatica
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
int cargarIDs (void);

/** \brief Busca aquellos espacios en los que se pueda cargar algun dato
 *
 * \param ePassenger[]
 * \param int
 * \return int
 *
 */

int buscarLibre(ePassenger[],int);

/** \brief Permite la carga de datos siempre y cuando el valor se haya devuelto vacio
 *
 * \param ePassenger[]
 * \param int
 * \return int
 *
 */
void cargarLibre (ePassenger[],int );

/** \brief Corrección del string de nombre corrigiendo minusculas y mayusculas
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void correccionNombres(ePassenger[], int);

/** \brief Corrección del string de apellidos corrigiendo minusculas y mayusculas
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void correccionApellidos(ePassenger[], int);

/** \brief Muestra los datos de un pasajero
 *
 * \param ePassenger
 * \return void
 *
 */
void mostrarPasajero(ePassenger);

/** \brief Por medio de una iteración permite mostrar un listado de todos los pasajeros cargados
 *
 * \param ePassenger
 * \param int
 * \return void
 *
 */
void mostrarPasajeros(ePassenger[], int);

/** \brief Permite la modificacion de algun valor en los datos del pasajero por medio de su ID
 *
 * \param ePassenger[]
 * \param void
 * \return int
 *
 */
void modificarValor (ePassenger[], int);

//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////HARDCODEAR/////////////////////////////////////////////
void harcodearPasajeros(ePassenger[],int );

/** \brief Permite la dada de baja de algun pasajero previamente registrado
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void darBaja (ePassenger[], int );

/** \brief Ordena alfabeticamente por apellido
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */
void ordenarApellidos(ePassenger [],int );

/** \brief Calcula la suma y el promedio de los pasajes
 *
 * \param ePassenger[]
 * \param int
 * \return float
 *
 */
float calcularPromedio(ePassenger  [], int );

/** \brief Compara el precio del pasaje de cada pasajero con el promedio
 *
 * \param ePassenger[]
 * \param int
 * \return void
 *
 */

void compararPrecios (ePassenger [], int );

/** \brief Valida que el nombre ingresado posea unicamente caracteres del tipo letra
 *
 * \param ePassenger
 * \return void
 *
 */
void validarNombre (ePassenger pasajero);

/** \brief  Valida que el apellido ingresado posea unicamente caracteres del tipo letra
 *
 * \param ePassenger
 * \return void
 *
 */
void validarApellido (ePassenger pasajero);

/** \brief Valida en una cadena de caracteres que todos los valores sean numericos y los devuelve como un entero
 *
 * \param char []
 * \return int
 *
 */
int validarNumero (char []);

#endif /* CALCULOS_H_ */
