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

///Operación: CREACION
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

//Operación: asigna la calle
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la calle a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la calle(string que representa la nueva calle)
//
//Devuelve: nada
void setCalle(DomicilioPtr domicilio,char *calle);

//Operación: asigna la altura
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la altura a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la altura(string que representa la nueva altura)
//
//Devuelve: nada
void setAltura(DomicilioPtr domicilio,int altura);

//Operación: asigna la localidad
//Precondición: la estructura Domicilio debe haberse creado
//Postcondición: agrega el valor de la localidad a la estructura Domicilio
//Parámetros: persona(puntero a la estructura persona), la localidad(string que representa la nueva localidad)
//
//Devuelve: nada
void setLocalidad(DomicilioPtr domicilio,char *localidad);

//Operación: obtiene la calle asignada del domicilio
//Precondición: la estructura Domicilio debe tener una calle asignada
//Postcondición: muestra la calle obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char
char *getCalle(DomicilioPtr domicilio);

//Operación: obtiene la altura asignada del domicilio
//Precondición: la estructura Domicilio debe tener una altura asignada
//Postcondición: muestra la altura obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: int
int getAltura(DomicilioPtr domicilio);

//Operación: obtiene la localidad asignada del domicilio
//Precondición: la estructura Domicilio debe tener una localidad asignada
//Postcondición: muestra la localidad obtenida
//Parámetros: Domicilio(puntero a la estructura Domicilio)
//
//Devuelve: char
char *getLocalidad(DomicilioPtr domicilio);

//Operación: muestra el domicilio
//Precondición: estructura Domicilio debe tener todos los campos asignado
//Postcondición: devuelve los valores de domicilio
//Parámetros: domicilio(puntero a la estructura domicilio)
//
//Devuelve: todos los datos de Domicilio
void mostrarDomicilio(DomicilioPtr domicilio);

//Operación: verifica si dos domicilios son iguales.
//Precondición: Ambos domicilios deben haber sido creados.
//Postcondición: chequea si las estructuras son idénticas en calle, altura y localidad
//Parámetros:
//  domicilio1: puntero a la estructura a verificar.
//  domicilio2: puntero a la estructura a verificar.
//Devuelve: true si son idénticos, false de lo contrario.
bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2);



#endif // TDADOMICILIO_H_INCLUDED
