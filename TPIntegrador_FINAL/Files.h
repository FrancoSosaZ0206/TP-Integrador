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

/** NUEVA - OPERACIÓN: guarda un paquete en un archivo de texto
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se serializa la lista de paquetes del centro a un archivo de texto en un formato
               visualmente agradable, cómodo para la lectura
PARÁMETROS:
    - c: puntero al centro logístico del que serializar la lista de paquetes
DEVUELVE: booleano indicando si se tuvo éxito (true), false si hubo un problema. */
bool serializarPaquetes(CentroLogisticoPtr c);

/** NUEVA - OPERACIÓN: abre un paquete en un archivo de texto
PRECONDICIÓN: c debe haberse DECLARADO.
POSTCONDICIÓN: se deserializa una lista de paquetes de un archivo de texto al centro
PARÁMETROS:
    - c: puntero al centro logístico al que deserializar la lista de paquetes
DEVUELVE: booleano indicando si se tuvo éxito (true), false si hubo un problema. */
bool deserializarPaquetes(CentroLogisticoPtr c);



#endif // FILES_H_INCLUDED
