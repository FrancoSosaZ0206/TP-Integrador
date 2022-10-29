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
    bool RepartoDiario;
} Persona;

typedef Persona* PersonaPtr;

//PRIMITIVAS

//Operacion de creacion de persona (construccion)
//PRECONDICION: la persona no debe haber sido creada
//POSTCONDICION: se crea una estructura persona con los datos recibidos.
//PARAMETROS:
//  nombre: string representando el nombre
//  apellido: string representando el apellido
//  domicilio: estructura representando el domicilio de la persona
//  cuil: estructura representando el cuil de la persona
//  esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
//Devuelve puntero a la persona creada
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer);

//Creador especial que solo recibe datos primitivos.
//PRECONDICION: la persona no debe haber sido creada
//POSTCONDICION: se crea una estructura persona con los datos recibidos.
//PARAMETROS:
//  nombre: string representando el nombre
//  apellido: string representando el apellido
//  calle: string representando la calle del domicilio
//  altura: entero representando la altura de la calle
//  localidad: entero representando la localidad del domicilio
//  cuil: string representando el cuil de la persona
//  esChofer: booleana que indica si se trata es un chofer(true) o cliente (false)
//Devuelve puntero a la persona creada
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer);

//Operacion de destruccion de la persona (destructora)
//PRECONDICION: la persona recibida debi� haber sido creada con crearPersona o crearPersonaDirect.
//POSTCONDICION: se destruye la persona recibida con sus datos
//PARAMETROS:
//  persona: puntero a la estructura persona que se quiere destruir.
//Devuelve NULL
PersonaPtr destruirPersona(PersonaPtr persona);





void setNombre(PersonaPtr persona, char *nombre);
//Operaci�n: asigna el nombre
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor de nombre a la estructura Persona
//Par�metros: persona(puntero a la estructura persona), nombre(string que representa el nuevo nombre)
//
//Devuelve: nada

void setApellido(PersonaPtr persona, char *apellido);
//Operaci�n: asigna el apellido
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor de apellido a la estructura Persona
//Par�metros: persona(puntero a la estructura persona), apellido(string que representa el nuevo apellido)
//
//Devuelve: nada

void setDomicilio(PersonaPtr persona, DomicilioPtr domicilio); //en TDADomicilio solo se puede setear cada campo de struct Domicilio
//Operaci�n: asigna el domicilio
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor de domicilio a la estructura Persona
//Par�metros: persona(puntero a la estructura persona), domicilio(string que representa el nuevo domicilio)
//
//Devuelve: nada

void setCuilPersona(PersonaPtr persona, CuilPtr cuil); ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
//Operaci�n: asigna el cuil
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor de cuil a la estructura Persona
//Par�metros: persona(puntero a la estructura persona), cuil(string que representa el nuevo cuil)
//
//Devuelve: nada

void setEsChofer(PersonaPtr persona, bool esChofer); //pondremos true or false, o bien 1 o 0 dependiendo de si queremos que sea chofer o no.
//Operaci�n: determina si es chofer
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor true or false dependiendo de si es chofer o no
//Par�metros: persona(puntero a la estructura persona), esChofer(bool que representa el nuevo valor)
//
//Devuelve: nada



//Operaci�n: determina si realizo el reparto diario
//Precondici�n: la estructura Persona debe haberse creado
//Postcondici�n: agrega el valor false, cuando se crea se inicia en falso
//Par�metros: persona(puntero a la estructura persona), RepartoDiario(bool que representa el nuevo valor)
//Devuelve: nada
void setRepartoDiario(PersonaPtr persona, bool RepartoDiario);




char *getNombre(PersonaPtr persona);
//Operaci�n: obtiene el nombre asignado de la persona
//Precondici�n: la estructura Persona debe tener un nombre asignado
//Postcondici�n: muestra el nombre obtenido
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: char

char *getApellido(PersonaPtr persona);
//Operaci�n: obtiene el apellido asignado de la persona
//Precondici�n: la estructura Persona debe tener un apellido asignado
//Postcondici�n: muestra el apellido obtenido
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: char

DomicilioPtr getDomicilio(PersonaPtr persona);
//Operaci�n: obtiene el domicilio asignado de la persona
//Precondici�n: la estructura Persona debe tener un domicilio asignado
//Postcondici�n: muestra el domicilio obtenido
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: char

CuilPtr getCuilPersona(PersonaPtr persona); ///NUEVO NOMBRE PARA NO CONFUNDIR CON GETCUIL DEL TDA CUIL
//Operaci�n: obtiene el cuil asignado de la persona
//Precondici�n: la estructura Persona debe tener un cuil asignado
//Postcondici�n: muestra el cuil obtenido
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: char

bool getEsChofer(PersonaPtr persona);
//Operaci�n: obtiene el valor asignado de esChofer para determinar si lo es o no
//Precondici�n: esChofer en la estructura Persona debe tener un valor booleano asignado
//Postcondici�n: muestra el valor obtenido
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: booleano representando el tipo de persona que es (chofer=true,cliente=false)



//Operaci�n: obtiene el valor asignado de RepartoDiario para determinar si lo realizo o no
//Precondici�n: persona debe haber sido creado en memoria dinamica con crearPersona
//Postcondici�n: muestra el valor obtenido
//Par�metros: persona(puntero a la estructura persona)
//Devuelve: booleano representando si ya concreto su reparto diario(Realizado=true,No Realizado=false)
bool getRepartoDiario(PersonaPtr persona);


///Especiales

void mostrarPersona(PersonaPtr persona);
//Operaci�n: muestra la persona
//Precondici�n: estructura Persona debe tener todos los campos asignado
//Postcondici�n: devuelve los valores de persona
//Par�metros: persona(puntero a la estructura persona)
//
//Devuelve: todos los datos de Persona

bool personasIguales(PersonaPtr persona1,PersonaPtr persona2);
//Operaci�n: verifica si dos personas son iguales.
//Precondici�n: Ambas personas deben haber sido creadas.
//Postcondici�n: chequea si las estructuras son id�nticas en cuil
//Par�metros:
//  persona1: puntero a la estructura a verificar.
//  persona2: puntero a la estructura a verificar.
//Devuelve: true si son id�nticos en cuil, false de lo contrario.

#endif // TDAPERSONA_H_INCLUDED
