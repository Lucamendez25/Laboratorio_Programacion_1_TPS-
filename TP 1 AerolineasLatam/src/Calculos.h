/*
 * Calculos.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Luca
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float descuentoDebito10(int a);
///Trae un valor int
///@param "a" es el número que le envio del precio(aerolineas/latam)
/// @param el valor, se multiplica por 0.10
///@return devuelve un float, con el valor, más un 10%

float interes25Credito(int a);
//////Trae un valor int
///@param  "a" es el número que le envio del precio(aerolineas/latam)
///@param el valor, se multiplica por 0.25.
/// @return devuelve float, con el valor, más un 25%.

double bitCoin(int a);
///Trae un valor int
///@param "a" es el número que le envio del precio(aerolineas/latam)
/// @param el valor entero, se divide por el precio del valor del bitcoin(4606954.55 = 1bitcoin)
/// @return devuelve un float, con el precio pasado a bitcoin.


float costoKm(int a,int b);
///Trae dos valores int
///@param a seria el precio(aerolineas/latam), y "b" serian los kilometros
/// @param hace la division precio/Kilometros.
///@return devuelve un float, con el precio por kilometro,


float diferenciaAerolineasLatam(int a, int b);
///Trae dos valores int
///@param a seria el precio de Aerolineas, y b el precio de Latam
/// @param se restan los dos
///@return devuelve la diferencia que hay entre los dos valores


#endif /* CALCULOS_H_ */

