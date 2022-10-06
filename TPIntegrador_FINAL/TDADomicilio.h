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
//Operaci�n: asigna la calle
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la calle a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)
//
//Devuelve: nada

void setAltura(DomicilioPtr domicilio,int altura);
//Operaci�n: asigna la altura
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la altura a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)
//
//Devuelve: nada

void setLocalidad(DomicilioPtr domicilio,char *localidad);
//Operaci�n: asigna la localidad
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la localidad a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)
//
//Devuelve: nada

char *getCalle(DomicilioPtr domicilio);
//Operaci�n: obtiene la calle asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una calle asignada
//Postcondici�n: muestra la calle obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char

int getAltura(DomicilioPtr domicilio);
//Operaci�n: obtiene la altura asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una altura asignada
//Postcondici�n: muestra la altura obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: int

char *getLocalidad(DomicilioPtr domicilio);
//Operaci�n: obtiene la localidad asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una localidad asignada
//Postcondici�n: muestra la localidad obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char

void mostrarDomicilio(DomicilioPtr domicilio);
//Operaci�n: muestra el domicilio
//Precondici�n: estructura Domicilio debe tener todos los campos asignado
//Postcondici�n: devuelve los valores de domicilio
//Par�metros: domicilio(puntero a la estructura domicilio)
//
//Devuelve: todos los datos de Domicilio

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);
//Operaci�n: verifica si dos domicilios son iguales.
//Precondici�n: Ambos domicilios deben haber sido creados.
//Postcondici�n: chequea si las estructuras son id�nticas en calle, altura y localidad
//Par�metros:
//  domicilio1: puntero a la estructura a verificar.
//  domicilio2: puntero a la estructura a verificar.
//Devuelve: true si son id�nticos, false de lo contrario.


#endif // TDADOMICILIO_H_INCLUDED
