#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"



/// ///////////////////////////////CREACI�N DE DATOS POR DEFECTO///////////////////////////////////// ///
/*                          Se crea en base a un �nico dato por defecto                                */

/*---------------------------------------------------------------------------------------------------*/
CuilPtr crearCuilPorDefecto(); ///NO BORRAR: Ya no se guardar�n en archivos aparte,
DomicilioPtr crearDomicilioPorDefecto(); ///pero es posible que sigan teniendo utilidad.
FechaPtr crearFechaPorDefecto();
/*---------------------------------------------------------------------------------------------------*/
PaquetePtr crearPaquetePorDefecto();
PersonaPtr crearPersonaPorDefecto(bool esChofer);
VehiculoPtr crearVehiculoPorDefecto(); //Crea un veh�culo de forma r�pida con datos predeterminados.
RepartoPtr crearRepartoPorDefecto(bool esRepartoAbierto);

CentroLogisticoPtr crearTodoPorDefecto(); //Crea un centro logistico llamando a las otras funciones

/// ///////////////////////////////CREACI�N DE DATOS GEN�RICOS///////////////////////////////////// ///
/*              Se crea aleatoriamente en base a una mini-base de datos por defecto                  */

/*---------------------------------------------------------------------------------------------------*/
CuilPtr crearCuilGenerico(); ///NO BORRAR: Ya no se guardar�n en archivos aparte,
DomicilioPtr crearDomicilioGenerico(); ///pero es posible que sigan teniendo utilidad.
FechaPtr crearFechaGenerica();
/*---------------------------------------------------------------------------------------------------*/
PaquetePtr crearPaqueteGenerico();
PersonaPtr crearPersonaGenerica(bool esChofer);
VehiculoPtr crearVehiculoGenerico(); //Crea un veh�culo de forma r�pida con datos predeterminados.
RepartoPtr crearRepartoGenerico(); //solo se crean repartos abiertos.

ListaPtr crearListaRepartosGenerica(bool esRepartoAbierto); //Hecha por Gast�n
ListaPtr crearListaVehiculosGenerico();
ListaPtr crearListaPaquetesGenerico();
ListaPtr crearListaPersonasGenerica();
ListaPtr crearListaRepartosPorDefecto();
void verificacion(bool resultado);

#endif // TEST_H_INCLUDED
