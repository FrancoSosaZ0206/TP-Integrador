#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                INTERFAZ DE ARCHIVOS

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

///                                                 OPERACIONES


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                                  ESCRITURA

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ///


///---------------------------------------------------------------------------------------------------------------

/// Guardado general






/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                                   LECTURA
//                                 Se reutilizan las estructuras creadas en main.c
/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///




///---------------------------------------------------------------------------------------------------------------

/// Apertura general




///*************************************************************************************************************


///                                         Especiales - Ayudantes

/** NUEVA - OPERACI�N: guarda un paquete en un archivo de texto
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se serializa la lista de paquetes del centro a un archivo de texto en un formato
               visualmente agradable, c�modo para la lectura
PAR�METROS:
    - c: puntero al centro log�stico del que serializar la lista de paquetes
DEVUELVE: booleano indicando si se tuvo �xito (true), false si hubo un problema. */
bool serializarPaquetes(CentroLogisticoPtr c);

/** NUEVA - OPERACI�N: abre un paquete en un archivo de texto
PRECONDICI�N: c debe haberse DECLARADO.
POSTCONDICI�N: se deserializa una lista de paquetes de un archivo de texto al centro
PAR�METROS:
    - c: puntero al centro log�stico al que deserializar la lista de paquetes
DEVUELVE: booleano indicando si se tuvo �xito (true), false si hubo un problema. */
bool deserializarPaquetes(CentroLogisticoPtr c);



#endif // FILES_H_INCLUDED
