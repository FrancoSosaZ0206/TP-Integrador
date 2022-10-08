#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

VehiculoPtr crearVehiculoPorDefecto(); ///Crea un vehículo de forma rápida con datos predeterminados.
VehiculoPtr crearVehiculoGenerico(); ///Crea un vehículo de forma rápida con datos aleatorios ///BROKEN
ListaPtr crearListaClientesGenerico(); ///Crea una lista con clientes predeterminados
ListaPtr crearListaVehiculosGenerico(); ///Crea una lista con vehiculos predeterminados
ListaPtr crearListaRepartosPorDefecto(); ///Crea una lista de repartos con elementos predeterminados
ListaPtr crearListaChoferesGenerico(); ///Crea una lista de choferes predeterminados
ListaPtr crearListaPaquetesGenerico(); ///Crea una lista de paquetes predeterminado

#endif // TEST_H_INCLUDED
