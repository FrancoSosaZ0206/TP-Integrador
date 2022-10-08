#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

VehiculoPtr crearVehiculoPorDefecto(); ///Crea un veh�culo de forma r�pida con datos predeterminados.
VehiculoPtr crearVehiculoGenerico(); ///Crea un veh�culo de forma r�pida con datos aleatorios ///BROKEN
ListaPtr crearListaClientesGenerico();
ListaPtr crearListaVehiculosGenerico();
ListaPtr crearListaRepartosPorDefecto();
ListaPtr crearListaChoferesGenerico();
ListaPtr crearListaPaquetesGenerico();

#endif // TEST_H_INCLUDED
