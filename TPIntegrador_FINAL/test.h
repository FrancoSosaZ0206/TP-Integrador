#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                        INTERFAZ DE FUNCIONES EN FASE DE TESTEO

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE REPARTOS CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr crearListaRepartosDefecto();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE PAQUETES CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr crearListaPaquetesGenerico();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE PERSONAS CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr crearListaPersonasGenerica();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE CLIENTES CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr clientesGenericos();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE CHOFERES CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr choferesGenericos();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UNA LISTA DE VEHICULOS CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A LISTA. */
ListaPtr crearListaVehiculosGenerico();

/** OPERACIÓN: CREACION
PRECONDICIÓN: NINGUNA
POSTCONDICIÓN: CREA UN CENTRO LOGISTICO CON DATOS POR DEFECTO
PARÁMETROS: NINGUNO
DEVUELVE: PUNTERO A CENTRO LOGISTICO. */
CentroLogisticoPtr crearCentroLogisticoDefecto();


#endif // TEST_H_INCLUDED
