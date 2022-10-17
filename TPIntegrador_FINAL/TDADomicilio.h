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

///Operaci�n: CREACION
///PRECONDICION: CALLE Y LOCALIDAD DEBEN SER DECLARADAS COMO STRINGS
/// LA ALTURA DEBE SER DECLARADA COMO ENTERO
///POSTCONDICION: CREA EN MEMORIA DINAMICA LA ESTRUCTURA DOMICILIO
/// CON LOS DATOS ENTREGADOS, LOS MISMOS TAMBIEN CREADOS EN MEMORIA DINAMICA
///PARAMETROS:
///1. STRING REPRESENTANDO LA CALLE
///2. ENTERO REPRESENTANDO LA ALTURA
///3. STRING REPRESENTANDO LA LOCALIDAD
///DEVUELVE: PUNTERO A ESTRUCTURA DOMICILIO CREADA EN MEMORIA DINAMICA
DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad);

///OPERACION: CREACION
///PRECONDICION: LA ESTRUCTURA DOMICILIO DEBE HABER SIDO CREADA EN MEMORIA DINAMICA
///POSTCONDICION: LIBERA LA MEMORIA DINAMICA LA ESTRUCTURA DOMICILIO
///PARAMETROS: PUNTERO A LA ESTRUCTURA DOMICILIO EN MEMORIA DINAMICA
///DEVUELVE: NULL
DomicilioPtr destruirDomicilio(DomicilioPtr domicilio);

//Operaci�n: asigna la calle
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la calle a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)
//
//Devuelve: nada
void setCalle(DomicilioPtr domicilio,char *calle);

//Operaci�n: asigna la altura
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la altura a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)
//
//Devuelve: nada
void setAltura(DomicilioPtr domicilio,int altura);

//Operaci�n: asigna la localidad
//Precondici�n: la estructura Domicilio debe haberse creado
//Postcondici�n: agrega el valor de la localidad a la estructura Domicilio
//Par�metros: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)
//
//Devuelve: nada
void setLocalidad(DomicilioPtr domicilio,char *localidad);

//Operaci�n: obtiene la calle asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una calle asignada
//Postcondici�n: muestra la calle obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char
char *getCalle(DomicilioPtr domicilio);

//Operaci�n: obtiene la altura asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una altura asignada
//Postcondici�n: muestra la altura obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: int
int getAltura(DomicilioPtr domicilio);

//Operaci�n: obtiene la localidad asignada del domicilio
//Precondici�n: la estructura Domicilio debe tener una localidad asignada
//Postcondici�n: muestra la localidad obtenida
//Par�metros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char
char *getLocalidad(DomicilioPtr domicilio);

//Operaci�n: muestra el domicilio
//Precondici�n: estructura Domicilio debe tener todos los campos asignado
//Postcondici�n: devuelve los valores de domicilio
//Par�metros: domicilio(puntero a la estructura domicilio)
//
//Devuelve: todos los datos de Domicilio
void mostrarDomicilio(DomicilioPtr domicilio);

//Operaci�n: verifica si dos domicilios son iguales.
//Precondici�n: Ambos domicilios deben haber sido creados.
//Postcondici�n: chequea si las estructuras son id�nticas en calle, altura y localidad
//Par�metros:
//  domicilio1: puntero a la estructura a verificar.
//  domicilio2: puntero a la estructura a verificar.
//Devuelve: true si son id�nticos, false de lo contrario.
bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);



#endif // TDADOMICILIO_H_INCLUDED
