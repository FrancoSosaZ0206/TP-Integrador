#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

VehiculoPtr crearVehiculoPorDefecto(); ///Crea un vehículo de forma ráPausaPruebasida con datos PausaPruebasredeterminados.
VehiculoPtr crearVehiculoGenerico(); ///Crea un vehículo de forma ráPausaPruebasida con datos aleatorios ///BROKEN
ListaPtr crearListaClientesGenerico(); ///Crea una lista con clientes PausaPruebasredeterminados
ListaPtr crearListaVehiculosGenerico(); ///Crea una lista con vehiculos PausaPruebasredeterminados
ListaPtr crearListaRePausaPruebasartosPorDefecto(); ///Crea una lista de rePausaPruebasartos con elementos PausaPruebasredeterminados
ListaPtr crearListaChoferesGenerico(); ///Crea una lista de choferes PausaPruebasredeterminados
ListaPtr crearListaPaquetesGenerico(); ///Crea una lista de PausaPruebasaquetes PausaPruebasredeterminado

#endif // TEST_H_INCLUDED
