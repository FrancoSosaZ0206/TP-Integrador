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

/** OPERACI�N: creacion (constructora)
PRECONDICI�N: ninguna
POSTCONDICI�N: crea un domicilio en memoria din�mica con los par�metros recibidos
PAR�METROS:
    - calle: string representando la calle del domicilio
    - altura: entero representando la altura del domicilio
    - localidad: string representando la localidad del domicilio
DEVUELVE: puntero al domicilio creado. */
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

/** OPERACI�N: destrucci�n (destructora)
PRECONDICI�N: domicilio debe haberse creado con crearDomicilio
POSTCONDICI�N: libera la memoria reservada para el domicilio
PAR�METROS:
    - domicilio: puntero al domicilio a destruir
DEVUELVE: NULL. */
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);


///SETTERS

/** OPERACI�N: asigna la calle
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: domicilio cambia con la nueva calle
PAR�METROS:
    - domicilio: puntero al domicilio a setear
    - calle: string que representa la nueva calle
DEVUELVE: nada. */
void setCalle(DomicilioPtr domicilio,char *calle);

/** OPERACI�N: asigna la altura
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: domicilio cambia con la nueva altura
PAR�METROS:
    - domicilio: puntero al domicilio a setear
    - altura: entero que representa la nueva altura
DEVUELVE: nada. */
void setAltura(DomicilioPtr domicilio,int altura);

/** OPERACI�N: asigna la localidad
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: domicilio cambia con la nueva localidad
PAR�METROS:
    - domicilio: puntero al domicilio a setear
    - localidad: string que representa la nueva localidad
DEVUELVE: nada. */
void setLocalidad(DomicilioPtr domicilio,char *localidad);


///GETTERS

/** OPERACI�N: obtiene la calle asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una calle asignada
POSTCONDICI�N: se obtiene la calle
PAR�METROS:
    - domicilio: puntero al domicilio del que obtener la calle
DEVUELVE: string representando la calle del domicilio. */
char *getCalle(DomicilioPtr domicilio);

/** OPERACI�N: obtiene la altura asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una altura asignada
POSTCONDICI�N: se obtiene la altura
PAR�METROS:
    - domicilio: puntero al domicilio del que obtener la altura
DEVUELVE: entero representando la altura de la calle. */
int getAltura(DomicilioPtr domicilio);

/** OPERACI�N: obtiene la localidad asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una localidad asignada
POSTCONDICI�N: se obtiene la localidad
PAR�METROS:
    - domicilio: puntero al domicilio del que obtener la localidad
DEVUELVE: string representando la localidad del domicilio. */
char *getLocalidad(DomicilioPtr domicilio);


///OPERACIONES ESPECIALES

/** OPERACI�N: muestra un domicilio
PRECONDICI�N: domicilio debe haberse creado con crearDomicilio
POSTCONDICI�N: muestra el domicilio por pantalla
PAR�METROS:
    - domicilio: puntero al domicilio a mostrar
DEVUELVE: nada. */
void mostrarDomicilio(DomicilioPtr domicilio);

/** OPERACI�N: revisa si dos domicilios son iguales.
PRECONDICI�N: Ambos domicilios deben haber sido creados.
POSTCONDICI�N: chequea si las estructuras son id�nticas en calle, altura y localidad
PAR�METROS:
    - domicilio1: puntero a la estructura a verificar.
    - domicilio2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos, false de lo contrario. */
bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);


#endif // TDADOMICILIO_H_INCLUDED
