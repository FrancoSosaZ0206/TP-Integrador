#ifndef TDAPERSONA_H_INCLUDED
#define TDAPERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDADomicilio.h"
#include "TDACuil.h"

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                    INTERFAZ DEL TDA PERSONA

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Persona
{
    char *nombre;
    char *apellido;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    bool esChofer; //true=chofer, false=cliente.
} Persona;

typedef Persona* PersonaPtr;

///CREACIÓN Y DESTRUCCIÓN

/** OPERACIÓN: creación de persona (constructora)
PRECONDICIÓN: la persona no debe haber sido creada
POSTCONDICIÓN: se crea una estructura persona con los datos recibidos.
PARÁMETROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - domicilio: estructura representando el domicilio de la persona
    - cuil: estructura representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada. */
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer);

/** OPERACIÓN: creador especial que solo recibe datos primitivos.
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
DEVUELVE: puntero a la persona creada. */
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer);

/** OPERACIÓN: destruccion de la persona (destructora)
PRECONDICIÓN: la persona recibida debió haber sido creada con crearPersona o crearPersonaDirect.
POSTCONDICIÓN: se libera la memoria reservada para la persona
PARÁMETROS:
    - persona: puntero a la estructura persona que se quiere destruir.
DEVUELVE: NULL. */
PersonaPtr destruirPersona(PersonaPtr persona);


///SETEAR

/** OPERACIÓN: asigna el nombre
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: persona cambia con el nuevo nombre
PARÁMETROS:
    - persona: puntero a la persona a setear el apellido
    - nombre: string representando el nuevo nombre
DEVUELVE: nada. */
void setNombre(PersonaPtr persona, char *nombre);

/** OPERACIÓN: asigna el apellido
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: persona cambia con el nuevo apellido
PARÁMETROS:
    - persona: puntero a la persona a setear el apellido
    - apellido: string representando el nuevo apellido
DEVUELVE: nada. */
void setApellido(PersonaPtr persona, char *apellido);

/** OPERACIÓN: asigna el domicilio
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: persona cambia con el nuevo domicilio
PARÁMETROS:
    - persona: puntero a la persona a setear el domicilio
    - domicilio: puntero al nuevo domicilio
DEVUELVE: nada. */
void setDomicilio(PersonaPtr persona, DomicilioPtr domicilio);

/** OPERACIÓN: asigna el cuil
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: persona cambia con el nuevo cuil
PARÁMETROS:
    - persona: puntero a la persona a setear el cuil
    - cuil: puntero al nuevo cuil
DEVUELVE: nada. */
void setCuilPersona(PersonaPtr persona, CuilPtr cuil);

/** OPERACIÓN: asigna una nueva clase de persona
PRECONDICIÓN: la estructura Persona debe haberse creado
POSTCONDICIÓN: persona cambia con el nuevo valor de esChofer
PARÁMETROS:
    - persona: puntero a la persona a setear la clase
    - esChofer: booleano representando la nueva clase de persona
DEVUELVE: nada. */
void setEsChofer(PersonaPtr persona, bool esChofer);


///GETTERS

/** OPERACIÓN: obtiene el nombre asignado a la persona
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: se obtiene el nombre de la persona
PARÁMETROS:
    - persona: puntero a la persona de la que obtener el nombre
DEVUELVE: string representando el nombre de la persona. */
char *getNombre(PersonaPtr persona);

/** OPERACIÓN: obtiene el apellido asignado a la persona
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: se obtiene el apellido de la persona
PARÁMETROS:
    - persona: puntero a la persona de la que obtener el apellido
DEVUELVE: string representando el apellido de la persona. */
char *getApellido(PersonaPtr persona);

/** OPERACIÓN: obtiene el domicilio asignado a la persona
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: se obtiene el domicilio de la persona
PARÁMETROS:
    - persona: puntero a la persona de la que obtener el cuil
DEVUELVE: puntero al TDA Domicilio de la persona. */
DomicilioPtr getDomicilio(PersonaPtr persona);

/** OPERACIÓN: obtiene el cuil asignado a la persona
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: se obtiene el cuil de la persona
PARÁMETROS:
    - persona: puntero a la persona de la que obtener el cuil
DEVUELVE: puntero a TDA Cuil de la persona. */
CuilPtr getCuilPersona(PersonaPtr persona);

/** OPERACIÓN: obtiene el tipo de persona como booleano
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: se obtiene la clase de persona contenida en esChofer
PARÁMETROS:
    - persona: puntero a la persona de la que obtener la clase
DEVUELVE: booleano indicando si se trata de un chofer (true) o un cliente (false). */
bool getEsChofer(PersonaPtr persona);


///ESPECIALES

/** OPERACIÓN: muestra la persona
PRECONDICIÓN: persona debe haberse creado
POSTCONDICIÓN: imprime los datos de una persona por pantalla
PARÁMETROS:
    - persona: puntero a la persona a mostrar
DEVUELVE: todos los datos de Persona. */
void mostrarPersona(PersonaPtr persona);

/** OPERACIÓN: verifica si dos personas son iguales.
PRECONDICIÓN: Ambas personas deben haber sido creadas.
POSTCONDICIÓN: chequea si las estructuras son idénticas en cuil
PARÁMETROS:
    - persona1: puntero a la estructura a verificar.
    - persona2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos en cuil, false de lo contrario. */
bool personasIguales(PersonaPtr persona1,PersonaPtr persona2);

/** OPERACIÓN: crea una copia de una persona (Orientada a la funcion copiarLista)
PRECONDICIÓN: personaOriginal debe haber sido creada previamente
POSTCONDICIÓN: duplica los contenidos de la persona en una nueva
PARÁMETROS:
    - personaOriginal: puntero a la persona de la que se quiere hacer una copia
DEVUELVE: puntero a la copia de la persona creada. */
PersonaPtr copiarPersona(PersonaPtr personaOriginal);


#endif // TDAPERSONA_H_INCLUDED
