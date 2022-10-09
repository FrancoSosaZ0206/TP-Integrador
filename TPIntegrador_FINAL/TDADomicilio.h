#ifndef TDADOMICILIO_H_INCLUDED
#define TDADOMICILIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Domicilio
{
    char *calle;
    int altura;
    char *localidad;
} Domicilio;
typedef Domicilio* DomicilioPtr;

//operacion creacion
//precondicion: Domicilio debe haber sido creado en memoria dinamica
//postcondicion: crea un domicilio en memoria dinamica
//patametros: calle, altura, localidad
//devuelve puntero a domicilio
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

//operacion creacion
//precondicion: Domicilio debe haber sido creado en memoria dinamica
//postcondicion: libera la memoria dinamica de domicilio
//patametros: puntero a domicilio
//devuelve nulo
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


#endif // TDADOMICILIO_H_INCLUDED
