#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"



/// ///////////////////////////////CREACIÓN DE DATOS POR DEFECTO///////////////////////////////////// ///
/*                          Se crea en base a un único dato por defecto                                */

CuilPtr crearCuilPorDefecto();
DomicilioPtr crearDomicilioPorDefecto();
FechaPtr crearFechaPorDefecto();

PaquetePtr crearPaquetePorDefecto();
PersonaPtr crearPersonaPorDefecto(bool esChofer);
VehiculoPtr crearVehiculoPorDefecto(); //Crea un vehículo de forma rápida con datos predeterminados.
RepartoPtr crearRepartoPorDefecto(); //solo se crean repartos abiertos.


/// ///////////////////////////////CREACIÓN DE DATOS GENÉRICOS///////////////////////////////////// ///
/*              Se crea aleatoriamente en base a una mini-base de datos por defecto                  */


CuilPtr crearCuilGenerico();
DomicilioPtr crearDomicilioGenerico();
FechaPtr crearFechaGenerica();

PaquetePtr crearPaqueteGenerico();
PersonaPtr crearPersonaGenerica(bool esChofer);
VehiculoPtr crearVehiculoGenerico(); //Crea un vehículo de forma rápida con datos predeterminados.
RepartoPtr crearRepartoGenerico(); //solo se crean repartos abiertos.


#endif // TEST_H_INCLUDED
