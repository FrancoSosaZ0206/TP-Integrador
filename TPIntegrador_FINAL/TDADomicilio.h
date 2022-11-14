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

/** OPERACI�N: CREACION
/PRECONDICI�N: LAS VARIABLES DEBEN HABER SIDO DECLARADAS
POSTCONDICI�N: CREA EN MEMORIA DINAMICA UN DOMICILIO CON LOS
 VALORES ENTREGADOS
PAR�METROS:
 PUNTERO A CHAR [LA CALLE DE LA DIRECCION]
 ENTERO [LA ALTURA DE LA DIRECCION]
 PUNTERO A CHAR [EL MUNICIPIO DE LA DIRECCION]
DEVUELVE: PUNTERO A DOMICILIO
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

/** OPERACI�N: DESTRUCCION
/PRECONDICI�N: DOMICILIO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: LIBERA EN MEMORIA DINAMICA LOS ELEMENTOS DE DOMICILIO
PAR�METROS:
 PUNTERO A DOMICILIO [A LIBERAR]
DEVUELVE: NULL. */
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);

void setCalle(DomicilioPtr domicilio,char *calle);
/** OPERACI�N: asigna la calle
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: agrega el valor de la calle a la estructura Domicilio
PAR�METROS: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)

DEVUELVE: nada

void setAltura(DomicilioPtr domicilio,int altura);
/** OPERACI�N: asigna la altura
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: agrega el valor de la altura a la estructura Domicilio
PAR�METROS: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)

DEVUELVE: nada

void setLocalidad(DomicilioPtr domicilio,char *localidad);
/** OPERACI�N: asigna la localidad
PRECONDICI�N: la estructura Domicilio debe haberse creado
POSTCONDICI�N: agrega el valor de la localidad a la estructura Domicilio
PAR�METROS: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)

DEVUELVE: nada

char *getCalle(DomicilioPtr domicilio);
/** OPERACI�N: obtiene la calle asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una calle asignada
POSTCONDICI�N: muestra la calle obtenida
PAR�METROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: char

int getAltura(DomicilioPtr domicilio);
/** OPERACI�N: obtiene la altura asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una altura asignada
POSTCONDICI�N: muestra la altura obtenida
PAR�METROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: int

char *getLocalidad(DomicilioPtr domicilio);
/** OPERACI�N: obtiene la localidad asignada del domicilio
PRECONDICI�N: la estructura Domicilio debe tener una localidad asignada
POSTCONDICI�N: muestra la localidad obtenida
PAR�METROS: Domicilio(puntero a la estructura Domicilio)

DEVUELVE: char

void mostrarDomicilio(DomicilioPtr domicilio);
/** OPERACI�N: muestra el domicilio
PRECONDICI�N: estructura Domicilio debe tener todos los campos asignado
POSTCONDICI�N: devuelve los valores de domicilio
PAR�METROS: domicilio(puntero a la estructura domicilio)

DEVUELVE: todos los datos de Domicilio

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);
/** OPERACI�N: verifica si dos domicilios son iguales.
PRECONDICI�N: Ambos domicilios deben haber sido creados.
POSTCONDICI�N: chequea si las estructuras son id�nticas en calle, altura y localidad
PAR�METROS:
    - domicilio1: puntero a la estructura a verificar.
    - domicilio2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos, false de lo contrario. */


#endif // TDADOMICILIO_H_INCLUDED
