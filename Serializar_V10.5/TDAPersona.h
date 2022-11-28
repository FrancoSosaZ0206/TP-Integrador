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

///CREACI�N Y DESTRUCCI�N

/** OPERACI�N: creaci�n de persona (constructora)
PRECONDICI�N: la persona no debe haber sido creada
POSTCONDICI�N: se crea una estructura persona con los datos recibidos.
PAR�METROS:
    - nombre: string representando el nombre
    - apellido: string representando el apellido
    - domicilio: estructura representando el domicilio de la persona
    - cuil: estructura representando el cuil de la persona
    - esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
DEVUELVE: puntero a la persona creada. */
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer);

/** OPERACI�N: creador especial que solo recibe datos primitivos.
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
DEVUELVE: puntero a la persona creada. */
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer);

/** OPERACI�N: destruccion de la persona (destructora)
PRECONDICI�N: la persona recibida debi� haber sido creada con crearPersona o crearPersonaDirect.
POSTCONDICI�N: se libera la memoria reservada para la persona
PAR�METROS:
    - persona: puntero a la estructura persona que se quiere destruir.
DEVUELVE: NULL. */
PersonaPtr destruirPersona(PersonaPtr persona);


///SETEAR

/** OPERACI�N: asigna el nombre
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: persona cambia con el nuevo nombre
PAR�METROS:
    - persona: puntero a la persona a setear el apellido
    - nombre: string representando el nuevo nombre
DEVUELVE: nada. */
void setNombre(PersonaPtr persona, char *nombre);

/** OPERACI�N: asigna el apellido
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: persona cambia con el nuevo apellido
PAR�METROS:
    - persona: puntero a la persona a setear el apellido
    - apellido: string representando el nuevo apellido
DEVUELVE: nada. */
void setApellido(PersonaPtr persona, char *apellido);

/** OPERACI�N: asigna el domicilio
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: persona cambia con el nuevo domicilio
PAR�METROS:
    - persona: puntero a la persona a setear el domicilio
    - domicilio: puntero al nuevo domicilio
DEVUELVE: nada. */
void setDomicilio(PersonaPtr persona, DomicilioPtr domicilio);

/** OPERACI�N: asigna el cuil
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: persona cambia con el nuevo cuil
PAR�METROS:
    - persona: puntero a la persona a setear el cuil
    - cuil: puntero al nuevo cuil
DEVUELVE: nada. */
void setCuilPersona(PersonaPtr persona, CuilPtr cuil);

/** OPERACI�N: asigna una nueva clase de persona
PRECONDICI�N: la estructura Persona debe haberse creado
POSTCONDICI�N: persona cambia con el nuevo valor de esChofer
PAR�METROS:
    - persona: puntero a la persona a setear la clase
    - esChofer: booleano representando la nueva clase de persona
DEVUELVE: nada. */
void setEsChofer(PersonaPtr persona, bool esChofer);


///GETTERS

/** OPERACI�N: obtiene el nombre asignado a la persona
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: se obtiene el nombre de la persona
PAR�METROS:
    - persona: puntero a la persona de la que obtener el nombre
DEVUELVE: string representando el nombre de la persona. */
char *getNombre(PersonaPtr persona);

/** OPERACI�N: obtiene el apellido asignado a la persona
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: se obtiene el apellido de la persona
PAR�METROS:
    - persona: puntero a la persona de la que obtener el apellido
DEVUELVE: string representando el apellido de la persona. */
char *getApellido(PersonaPtr persona);

/** OPERACI�N: obtiene el domicilio asignado a la persona
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: se obtiene el domicilio de la persona
PAR�METROS:
    - persona: puntero a la persona de la que obtener el cuil
DEVUELVE: puntero al TDA Domicilio de la persona. */
DomicilioPtr getDomicilio(PersonaPtr persona);

/** OPERACI�N: obtiene el cuil asignado a la persona
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: se obtiene el cuil de la persona
PAR�METROS:
    - persona: puntero a la persona de la que obtener el cuil
DEVUELVE: puntero a TDA Cuil de la persona. */
CuilPtr getCuilPersona(PersonaPtr persona);

/** OPERACI�N: obtiene el tipo de persona como booleano
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: se obtiene la clase de persona contenida en esChofer
PAR�METROS:
    - persona: puntero a la persona de la que obtener la clase
DEVUELVE: booleano indicando si se trata de un chofer (true) o un cliente (false). */
bool getEsChofer(PersonaPtr persona);


///ESPECIALES

/** OPERACI�N: muestra la persona
PRECONDICI�N: persona debe haberse creado
POSTCONDICI�N: imprime los datos de una persona por pantalla
PAR�METROS:
    - persona: puntero a la persona a mostrar
DEVUELVE: todos los datos de Persona. */
void mostrarPersona(PersonaPtr persona);

/** OPERACI�N: verifica si dos personas son iguales.
PRECONDICI�N: Ambas personas deben haber sido creadas.
POSTCONDICI�N: chequea si las estructuras son id�nticas en cuil
PAR�METROS:
    - persona1: puntero a la estructura a verificar.
    - persona2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos en cuil, false de lo contrario. */
bool personasIguales(PersonaPtr persona1,PersonaPtr persona2);

/** OPERACI�N: crea una copia de una persona (Orientada a la funcion copiarLista)
PRECONDICI�N: personaOriginal debe haber sido creada previamente
POSTCONDICI�N: duplica los contenidos de la persona en una nueva
PAR�METROS:
    - personaOriginal: puntero a la persona de la que se quiere hacer una copia
DEVUELVE: puntero a la copia de la persona creada. */
PersonaPtr copiarPersona(PersonaPtr personaOriginal);


#endif // TDAPERSONA_H_INCLUDED
