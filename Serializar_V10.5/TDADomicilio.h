#ifndef TDADOMICILIO_H_INCLUDED
#define TDADOMICILIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                INTERFAZ DEL TDA DOMICILIO

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Domicilio
{
    char *calle;
    int altura;
    char *localidad;
} Domicilio;
typedef Domicilio* DomicilioPtr;


///CREACION Y DESTRUCCION

/** OPERACIÓN: creacion (constructora)
PRECONDICIÓN: ninguna
POSTCONDICIÓN: crea un domicilio en memoria dinámica con los parámetros recibidos
PARÁMETROS:
    - calle: string representando la calle del domicilio
    - altura: entero representando la altura del domicilio
    - localidad: string representando la localidad del domicilio
DEVUELVE: puntero al domicilio creado. */
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

/** OPERACIÓN: destrucción (destructora)
PRECONDICIÓN: domicilio debe haberse creado con crearDomicilio
POSTCONDICIÓN: libera la memoria reservada para el domicilio
PARÁMETROS:
    - domicilio: puntero al domicilio a destruir
DEVUELVE: NULL. */
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);


///SETTERS

/** OPERACIÓN: asigna la calle
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: domicilio cambia con la nueva calle
PARÁMETROS:
    - domicilio: puntero al domicilio a setear
    - calle: string que representa la nueva calle
DEVUELVE: nada. */
void setCalle(DomicilioPtr domicilio,char *calle);

/** OPERACIÓN: asigna la altura
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: domicilio cambia con la nueva altura
PARÁMETROS:
    - domicilio: puntero al domicilio a setear
    - altura: entero que representa la nueva altura
DEVUELVE: nada. */
void setAltura(DomicilioPtr domicilio,int altura);

/** OPERACIÓN: asigna la localidad
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: domicilio cambia con la nueva localidad
PARÁMETROS:
    - domicilio: puntero al domicilio a setear
    - localidad: string que representa la nueva localidad
DEVUELVE: nada. */
void setLocalidad(DomicilioPtr domicilio,char *localidad);


///GETTERS

/** OPERACIÓN: obtiene la calle asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una calle asignada
POSTCONDICIÓN: se obtiene la calle
PARÁMETROS:
    - domicilio: puntero al domicilio del que obtener la calle
DEVUELVE: string representando la calle del domicilio. */
char *getCalle(DomicilioPtr domicilio);

/** OPERACIÓN: obtiene la altura asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una altura asignada
POSTCONDICIÓN: se obtiene la altura
PARÁMETROS:
    - domicilio: puntero al domicilio del que obtener la altura
DEVUELVE: entero representando la altura de la calle. */
int getAltura(DomicilioPtr domicilio);

/** OPERACIÓN: obtiene la localidad asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una localidad asignada
POSTCONDICIÓN: se obtiene la localidad
PARÁMETROS:
    - domicilio: puntero al domicilio del que obtener la localidad
DEVUELVE: string representando la localidad del domicilio. */
char *getLocalidad(DomicilioPtr domicilio);


///OPERACIONES ESPECIALES

/** OPERACIÓN: muestra un domicilio
PRECONDICIÓN: domicilio debe haberse creado con crearDomicilio
POSTCONDICIÓN: muestra el domicilio por pantalla
PARÁMETROS:
    - domicilio: puntero al domicilio a mostrar
DEVUELVE: nada. */
void mostrarDomicilio(DomicilioPtr domicilio);

/** OPERACIÓN: revisa si dos domicilios son iguales.
PRECONDICIÓN: Ambos domicilios deben haber sido creados.
POSTCONDICIÓN: chequea si las estructuras son idénticas en calle, altura y localidad
PARÁMETROS:
    - domicilio1: puntero a la estructura a verificar.
    - domicilio2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos, false de lo contrario. */
bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);


#endif // TDADOMICILIO_H_INCLUDED
