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

/** OPERACIÓN: crea una lista de repartos por defecto
PRECONDICIÓN: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICIÓN: agrega un conjunto de repartos abiertos por defecto a la lista del centro.
               también añade al centro los parámetros que componen dichos repartos.
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
DEVUELVE: nada. */
void crearListaRepartosDefecto(CentroLogisticoPtr c);

/** OPERACIÓN: crea una lista de paquetes genérica
PRECONDICIÓN: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICIÓN: crea una lista de paquetes genérica
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
DEVUELVE: nada. */
void crearListaPaquetesGenerico(CentroLogisticoPtr c);

/** OPERACIÓN: crea una lista de personas genéricas
PRECONDICIÓN: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICIÓN: crea una lista de personas genéricas
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
DEVUELVE: nada. */
void crearListaPersonasGenerica(CentroLogisticoPtr c);

/** OPERACIÓN: crea una lista de personas genéricos de clase a elegir
PRECONDICIÓN: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICIÓN: crea una lista de clientes genéricos cuyo tipo está indicado por el parámetro booleano recibido
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
    - esChofer: booleano indicando si se quiere crear choferes (true) o clientes (false)
DEVUELVE: nada. */
void crearPersonasGenericasEspecificas(CentroLogisticoPtr c,bool esChofer);

/** OPERACIÓN: crea una lista de vehiculos genéricos
PRECONDICIÓN: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICIÓN: crea una lista de vehiculos genéricos
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
DEVUELVE: nada. */
void crearListaVehiculosGenerico(CentroLogisticoPtr c);

/** OPERACIÓN: crea un centro logístico por defecto
PRECONDICIÓN: ninguna
POSTCONDICIÓN: crea un centro logístico con datos por defecto
PARÁMETROS:
    - c: puntero al centro logístico donde agregar los datos
DEVUELVE: puntero al centro logistico creado. */
CentroLogisticoPtr crearCentroLogisticoDefecto();


#endif // TEST_H_INCLUDED
