#ifndef TDAPERSONA_H_INCLUDED
#define TDAPERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDADomicilio.h"
#include "TDACuil.h"

typedef struct Persona
{
    char *nombre;
    char *apellido;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    bool esChofer; //la persona es un chofer si da verdadero, de lo contrario es un cliente.
} Persona;

typedef Persona* PersonaPtr;

//PRIMITIVAS

/** OPERACI�N de creacion de persona (construccion)
PRECONDICI�N: la persona no debe haber sido creada
POSTCONDICI�N: se crea una estructura persona con los datos recibidos.
PAR�METROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - domicilio: estructura representando el domicilio de la persona
    - cuil: estructura representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer);

Creador especial que solo recibe datos primitivos.
PRECONDICI�N: la persona no debe haber sido creada
POSTCONDICI�N: se crea una estructura persona con los datos recibidos.
PAR�METROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - calle: string representando la calle del domicilio
    - altura: entero representando la altura de la calle
    - localidad: entero representando la localidad del domicilio
    - cuil: string representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer);

/** OPERACI�N de destruccion de la persona (destructora)
PRECONDICI�N: la persona recibida debi� haber sido creada con crearPersona o crearPersonaDirect.
POSTCONDICI�N: se destruye la persona recibida con sus datos
PAR�METROS:
    - persona: puntero a la estructura persona que se quiere destruir.
DEVUELVE: NULL. */
PersonaPtr destruirPersona(PersonaPtr persona);





void setNombre(PersonaPtr persona, char *nombre);
/** OPERACI�N: asigna el nombre
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: agrega el valor de nombre a la estructura Persona
PAR�METROS: persona(puntero a la estructura persona), nombre(string que representa el nuevo nombre)

DEVUELVE: nada

void setApellido(PersonaPtr persona, char *apellido);
/** OPERACI�N: asigna el apellido
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: agrega el valor de apellido a la estructura Persona
PAR�METROS: persona(puntero a la estructura persona), apellido(string que representa el nuevo apellido)

DEVUELVE: nada

void setDomicilio(PersonaPtr persona, DomicilioPtr domicilio); //en TDADomicilio solo se puede setear cada campo de struct Domicilio
/** OPERACI�N: asigna el domicilio
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: agrega el valor de domicilio a la estructura Persona
PAR�METROS: persona(puntero a la estructura persona), domicilio(string que representa el nuevo domicilio)

DEVUELVE: nada

void setCuilPersona(PersonaPtr persona, CuilPtr cuil); ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
/** OPERACI�N: asigna el cuil
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: agrega el valor de cuil a la estructura Persona
PAR�METROS: persona(puntero a la estructura persona), cuil(string que representa el nuevo cuil)

DEVUELVE: nada

void setEsChofer(PersonaPtr persona, bool esChofer); //pondremos true or false, o bien 1 o 0 dependiendo de si queremos que sea chofer o no.
/** OPERACI�N: determina si es chofer
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: agrega el valor true or false dependiendo de si es chofer o no
PAR�METROS: persona(puntero a la estructura persona), esChofer(bool que representa el nuevo valor)

DEVUELVE: nada





char *getNombre(PersonaPtr persona);
/** OPERACI�N: obtiene el nombre asignado de la persona
PRECONDICI�N: la estructura Persona debe tener un nombre asignado
POSTCONDICI�N: muestra el nombre obtenido
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: char

char *getApellido(PersonaPtr persona);
/** OPERACI�N: obtiene el apellido asignado de la persona
PRECONDICI�N: la estructura Persona debe tener un apellido asignado
POSTCONDICI�N: muestra el apellido obtenido
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: char

DomicilioPtr getDomicilio(PersonaPtr persona);
/** OPERACI�N: obtiene el domicilio asignado de la persona
PRECONDICI�N: la estructura Persona debe tener un domicilio asignado
POSTCONDICI�N: muestra el domicilio obtenido
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: char

CuilPtr getCuilPersona(PersonaPtr persona); ///NUEVO NOMBRE PARA NO CONFUNDIR CON GETCUIL DEL TDA CUIL
/** OPERACI�N: obtiene el cuil asignado de la persona
PRECONDICI�N: la estructura Persona debe tener un cuil asignado
POSTCONDICI�N: muestra el cuil obtenido
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: char

bool getEsChofer(PersonaPtr persona);
/** OPERACI�N: obtiene el valor asignado de esChofer para determinar si lo es o no
PRECONDICI�N: esChofer en la estructura Persona debe tener un valor booleano asignado
POSTCONDICI�N: muestra el valor obtenido
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: booleano representando el tipo de persona que es (chofer=true,cliente=false)

///Especiales

void mostrarPersona(PersonaPtr persona);
/** OPERACI�N: muestra la persona
PRECONDICI�N: estructura Persona debe tener todos los campos asignado
POSTCONDICI�N: devuelve los valores de persona
PAR�METROS: persona(puntero a la estructura persona)

DEVUELVE: todos los datos de Persona

bool personasIguales(PersonaPtr persona1,PersonaPtr persona2);
/** OPERACI�N: verifica si dos personas son iguales.
PRECONDICI�N: Ambas personas deben haber sido creadas.
POSTCONDICI�N: chequea si las estructuras son id�nticas en cuil
PAR�METROS:
    - persona1: puntero a la estructura a verificar.
    - persona2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos en cuil, false de lo contrario. */

PersonaPtr copiarPersona(PersonaPtr personaOriginal); ///NUEVA - Orientada para la funcion copiarLista
/*  OPERACI�N: crea una copia de una persona
PRECONDICI�N: personaOriginal debe haber sido creada previamente
POSTCONDICI�N: duplica los contenidos de la persona en una nueva
PAR�METROS:
    - personaOriginal: puntero a la persona de la que se quiere hacer una copia
DEVUELVE: puntero a la copia de la persona creada. */


#endif // TDAPERSONA_H_INCLUDED
