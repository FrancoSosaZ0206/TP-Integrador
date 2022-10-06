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


DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);

void setCalle(DomicilioPtr domicilio,char *calle);
//Operación: asigna la calle
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la calle a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)
//
//Devuelve: nada

void setAltura(DomicilioPtr domicilio,int altura);
//Operación: asigna la altura
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la altura a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)
//
//Devuelve: nada

void setLocalidad(DomicilioPtr domicilio,char *localidad);
//Operación: asigna la localidad
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la localidad a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)
//
//Devuelve: nada

char *getCalle(DomicilioPtr domicilio);
//Operación: obtiene la calle asignada del domicilio
//Precondición: la estructura Domicilio debe tener una calle asignada
//Postcondición: muestra la calle obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char

int getAltura(DomicilioPtr domicilio);
//Operación: obtiene la altura asignada del domicilio
//Precondición: la estructura Domicilio debe tener una altura asignada
//Postcondición: muestra la altura obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: int

char *getLocalidad(DomicilioPtr domicilio);
//Operación: obtiene la localidad asignada del domicilio
//Precondición: la estructura Domicilio debe tener una localidad asignada
//Postcondición: muestra la localidad obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char

void mostrarDomicilio(DomicilioPtr domicilio);
//Operación: muestra el domicilio
//Precondición: estructura Domicilio debe tener todos los campos asignado
//Postcondición: devuelve los valores de domicilio
//Parámetros: domicilio(puntero a la estructura domicilio)
//
//Devuelve: todos los datos de Domicilio

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);
//Operación: verifica si dos domicilios son iguales.
//Precondición: Ambos domicilios deben haber sido creados.
//Postcondición: chequea si las estructuras son idénticas en calle, altura y localidad
//Parámetros:
//  domicilio1: puntero a la estructura a verificar.
//  domicilio2: puntero a la estructura a verificar.
//Devuelve: true si son idénticos, false de lo contrario.


#endif // TDADOMICILIO_H_INCLUDED
