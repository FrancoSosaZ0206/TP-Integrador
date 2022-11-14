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

/** OPERACIÓN de creacion de persona (construccion)
PRECONDICIÓN: la persona no debe haber sido creada
POSTCONDICIÓN: se crea una estructura persona con los datos recibidos.
PARÁMETROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - domicilio: estructura representando el domicilio de la persona
    - cuil: estructura representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer);

Creador especial que solo recibe datos primitivos.
PRECONDICIÓN: la persona no debe haber sido creada
POSTCONDICIÓN: se crea una estructura persona con los datos recibidos.
PARÁMETROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - calle: string representando la calle del domicilio
    - altura: entero representando la altura de la calle
    - localidad: entero representando la localidad del domicilio
    - cuil: string representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer);

/** OPERACIÓN de destruccion de la persona (destructora)
PRECONDICIÓN: la persona recibida debió haber sido creada con crearPersona o crearPersonaDirect.
POSTCONDICIÓN: se destruye la persona recibida con sus datos
PARÁMETROS:
    - persona: puntero a la estructura persona que se quiere destruir.
DEVUELVE: NULL. */
PersonaPtr destruirPersona(PersonaPtr persona);





void setNombre(PersonaPtr persona, char *nombre);
/** OPERACIÓN: asigna el nombre
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: agrega el valor de nombre a la estructura Persona
PARÁMETROS: persona(puntero a la estructura persona), nombre(string que representa el nuevo nombre)

DEVUELVE: nada

void setApellido(PersonaPtr persona, char *apellido);
/** OPERACIÓN: asigna el apellido
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: agrega el valor de apellido a la estructura Persona
PARÁMETROS: persona(puntero a la estructura persona), apellido(string que representa el nuevo apellido)

DEVUELVE: nada

void setDomicilio(PersonaPtr persona, DomicilioPtr domicilio); //en TDADomicilio solo se puede setear cada campo de struct Domicilio
/** OPERACIÓN: asigna el domicilio
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: agrega el valor de domicilio a la estructura Persona
PARÁMETROS: persona(puntero a la estructura persona), domicilio(string que representa el nuevo domicilio)

DEVUELVE: nada

void setCuilPersona(PersonaPtr persona, CuilPtr cuil); ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
/** OPERACIÓN: asigna el cuil
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: agrega el valor de cuil a la estructura Persona
PARÁMETROS: persona(puntero a la estructura persona), cuil(string que representa el nuevo cuil)

DEVUELVE: nada

void setEsChofer(PersonaPtr persona, bool esChofer); //pondremos true or false, o bien 1 o 0 dependiendo de si queremos que sea chofer o no.
/** OPERACIÓN: determina si es chofer
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: agrega el valor true or false dependiendo de si es chofer o no
PARÁMETROS: persona(puntero a la estructura persona), esChofer(bool que representa el nuevo valor)

DEVUELVE: nada





char *getNombre(PersonaPtr persona);
/** OPERACIÓN: obtiene el nombre asignado de la persona
PRECONDICIÓN: la estructura Persona debe tener un nombre asignado
POSTCONDICIÓN: muestra el nombre obtenido
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: char

char *getApellido(PersonaPtr persona);
/** OPERACIÓN: obtiene el apellido asignado de la persona
PRECONDICIÓN: la estructura Persona debe tener un apellido asignado
POSTCONDICIÓN: muestra el apellido obtenido
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: char

DomicilioPtr getDomicilio(PersonaPtr persona);
/** OPERACIÓN: obtiene el domicilio asignado de la persona
PRECONDICIÓN: la estructura Persona debe tener un domicilio asignado
POSTCONDICIÓN: muestra el domicilio obtenido
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: char

CuilPtr getCuilPersona(PersonaPtr persona); ///NUEVO NOMBRE PARA NO CONFUNDIR CON GETCUIL DEL TDA CUIL
/** OPERACIÓN: obtiene el cuil asignado de la persona
PRECONDICIÓN: la estructura Persona debe tener un cuil asignado
POSTCONDICIÓN: muestra el cuil obtenido
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: char

bool getEsChofer(PersonaPtr persona);
/** OPERACIÓN: obtiene el valor asignado de esChofer para determinar si lo es o no
PRECONDICIÓN: esChofer en la estructura Persona debe tener un valor booleano asignado
POSTCONDICIÓN: muestra el valor obtenido
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: booleano representando el tipo de persona que es (chofer=true,cliente=false)

///Especiales

void mostrarPersona(PersonaPtr persona);
/** OPERACIÓN: muestra la persona
PRECONDICIÓN: estructura Persona debe tener todos los campos asignado
POSTCONDICIÓN: devuelve los valores de persona
PARÁMETROS: persona(puntero a la estructura persona)

DEVUELVE: todos los datos de Persona

bool personasIguales(PersonaPtr persona1,PersonaPtr persona2);
/** OPERACIÓN: verifica si dos personas son iguales.
PRECONDICIÓN: Ambas personas deben haber sido creadas.
POSTCONDICIÓN: chequea si las estructuras son idénticas en cuil
PARÁMETROS:
    - persona1: puntero a la estructura a verificar.
    - persona2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos en cuil, false de lo contrario. */

PersonaPtr copiarPersona(PersonaPtr personaOriginal); ///NUEVA - Orientada para la funcion copiarLista
/*  OPERACIÓN: crea una copia de una persona
PRECONDICIÓN: personaOriginal debe haber sido creada previamente
POSTCONDICIÓN: duplica los contenidos de la persona en una nueva
PARÁMETROS:
    - personaOriginal: puntero a la persona de la que se quiere hacer una copia
DEVUELVE: puntero a la copia de la persona creada. */


#endif // TDAPERSONA_H_INCLUDED
