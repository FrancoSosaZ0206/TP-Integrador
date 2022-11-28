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

/** OPERACI�N: crea una lista de repartos por defecto
PRECONDICI�N: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICI�N: agrega un conjunto de repartos abiertos por defecto a la lista del centro.
               tambi�n a�ade al centro los par�metros que componen dichos repartos.
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
DEVUELVE: nada. */
void crearListaRepartosDefecto(CentroLogisticoPtr c);

/** OPERACI�N: crea una lista de paquetes gen�rica
PRECONDICI�N: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICI�N: crea una lista de paquetes gen�rica
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
DEVUELVE: nada. */
void crearListaPaquetesGenerico(CentroLogisticoPtr c);

/** OPERACI�N: crea una lista de personas gen�ricas
PRECONDICI�N: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICI�N: crea una lista de personas gen�ricas
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
DEVUELVE: nada. */
void crearListaPersonasGenerica(CentroLogisticoPtr c);

/** OPERACI�N: crea una lista de personas gen�ricos de clase a elegir
PRECONDICI�N: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICI�N: crea una lista de clientes gen�ricos cuyo tipo est� indicado por el par�metro booleano recibido
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
    - esChofer: booleano indicando si se quiere crear choferes (true) o clientes (false)
DEVUELVE: nada. */
void crearPersonasGenericasEspecificas(CentroLogisticoPtr c,bool esChofer);

/** OPERACI�N: crea una lista de vehiculos gen�ricos
PRECONDICI�N: c debe haberse creado (de preferencia, con crearCtroLogRapido()).
POSTCONDICI�N: crea una lista de vehiculos gen�ricos
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
DEVUELVE: nada. */
void crearListaVehiculosGenerico(CentroLogisticoPtr c);

/** OPERACI�N: crea un centro log�stico por defecto
PRECONDICI�N: ninguna
POSTCONDICI�N: crea un centro log�stico con datos por defecto
PAR�METROS:
    - c: puntero al centro log�stico donde agregar los datos
DEVUELVE: puntero al centro logistico creado. */
CentroLogisticoPtr crearCentroLogisticoDefecto();


#endif // TEST_H_INCLUDED
