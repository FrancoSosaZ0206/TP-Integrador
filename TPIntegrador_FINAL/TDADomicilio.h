#ifndef TDADOMICILIO_H_INCLUDED
#define TDADOMICILIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Domicilio
{
    char *calle;
    int altura;
    char *localidad;
} Domicilio;
typedef Domicilio* DomicilioPtr;

/** OPERACIÓN: CREACION
/PRECONDICIÓN: LAS VARIABLES DEBEN HABER SIDO DECLARADAS
POSTCONDICIÓN: CREA EN MEMORIA DINAMICA UN DOMICILIO CON LOS
 VALORES ENTREGADOS
PARÁMETROS:
 PUNTERO A CHAR [LA CALLE DE LA DIRECCION]
 ENTERO [LA ALTURA DE LA DIRECCION]
 PUNTERO A CHAR [EL MUNICIPIO DE LA DIRECCION]
DEVUELVE: PUNTERO A DOMICILIO
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

/** OPERACIÓN: DESTRUCCION
/PRECONDICIÓN: DOMICILIO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICIÓN: LIBERA EN MEMORIA DINAMICA LOS ELEMENTOS DE DOMICILIO
PARÁMETROS:
 PUNTERO A DOMICILIO [A LIBERAR]
DEVUELVE: NULL. */
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);

void setCalle(DomicilioPtr domicilio,char *calle);
/** OPERACIÓN: asigna la calle
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: agrega el valor de la calle a la estructura Domicilio
PARÁMETROS: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)

DEVUELVE: nada

void setAltura(DomicilioPtr domicilio,int altura);
/** OPERACIÓN: asigna la altura
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: agrega el valor de la altura a la estructura Domicilio
PARÁMETROS: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)

DEVUELVE: nada

void setLocalidad(DomicilioPtr domicilio,char *localidad);
/** OPERACIÓN: asigna la localidad
PRECONDICIÓN: la estructura Domicilio debe haberse creado
POSTCONDICIÓN: agrega el valor de la localidad a la estructura Domicilio
PARÁMETROS: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)

DEVUELVE: nada

char *getCalle(DomicilioPtr domicilio);
/** OPERACIÓN: obtiene la calle asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una calle asignada
POSTCONDICIÓN: muestra la calle obtenida
PARÁMETROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: char

int getAltura(DomicilioPtr domicilio);
/** OPERACIÓN: obtiene la altura asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una altura asignada
POSTCONDICIÓN: muestra la altura obtenida
PARÁMETROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: int

char *getLocalidad(DomicilioPtr domicilio);
/** OPERACIÓN: obtiene la localidad asignada del domicilio
PRECONDICIÓN: la estructura Domicilio debe tener una localidad asignada
POSTCONDICIÓN: muestra la localidad obtenida
PARÁMETROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: char

void mostrarDomicilio(DomicilioPtr domicilio);
/** OPERACIÓN: muestra el domicilio
PRECONDICIÓN: estructura Domicilio debe tener todos los campos asignado
POSTCONDICIÓN: devuelve los valores de domicilio
PARÁMETROS: domicilio(puntero a la estructura domicilio)

DEVUELVE: todos los datos de Domicilio

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);
/** OPERACIÓN: verifica si dos domicilios son iguales.
PRECONDICIÓN: Ambos domicilios deben haber sido creados.
POSTCONDICIÓN: chequea si las estructuras son idénticas en calle, altura y localidad
PARÁMETROS:
    - domicilio1: puntero a la estructura a verificar.
    - domicilio2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos, false de lo contrario. */


#endif // TDADOMICILIO_H_INCLUDED
