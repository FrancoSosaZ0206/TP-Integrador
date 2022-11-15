#ifndef TDANODO_H_INCLUDED
#define TDANODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                    INTERFAZ DEL TDA NODO

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef void* PtrDato;

typedef struct Nodo
{
    PtrDato dato;
    struct Nodo* sgte;
} Nodo;
typedef Nodo* PtrNodo;

const void* SinNodoSgte;


///CREACION Y DESTRUCCION

/** OPERACI�N: construccion (constructor)
PRECONDICI�N: El nodo no debe haberse creado
POSTCONDICI�N: Se crea el nodo con null en PtrDato y SinNodoSgte en sgte
PAR�METROS: ninguno
DEVUELVE: puntero al nodo creado. */
PtrNodo crearNodo(PtrDato dato);

/** OPERACI�N: destruccion (destructor)
PRECONDICI�N: El nodo debe haberse creado
POSTCONDICI�N: Se Libera la memoria del nodo eliminado
PAR�METROS:
    - puntero al nodo a eliminar
DEVUELVE: NULL. */
PtrNodo destruirNodo(PtrNodo nodo);

/** OPERACI�N: establecimiento de datos
PRECONDICI�N: nodo creado con crearNodo()
POSTCONDICI�N: almacena el dato proporcionado en el nodo apuntado por ptrNodo.
PAR�METROS:
    - ptrNodo: puntero al nodo
    - PtrDato: Puntero al dato a almacenar
DEVUELVE: NULL. */
void setDato(PtrNodo nodo,PtrDato dato);

/** OPERACI�N: obtenci�n de datos
PRECONDICI�N: nodo creado con crearNodo()
POSTCONDICI�N: obtiene el dato almacenado en el nodo apuntado por ptrNodo.
PAR�METROS:
    - ptrNodo: puntero al nodo
DEVUELVE: puntero al dato almacenado. */
PtrDato getDato(PtrNodo nodo);

/** OPERACI�N: establecimiento del siguiente nodo
PRECONDICI�N: esteNodo creado con crearNodo()
POSTCONDICI�N: se establece el nodo siguiente al actual
PAR�METROS:
    - esteNodo: puntero al nodo
DEVUELVE: NULL. */
void setSiguiente(PtrNodo esteNodo,PtrNodo siguienteNodo);

/** OPERACI�N: obtenci�n del siguiente nodo
PRECONDICI�N: esteNodo creado con crearNodo()
POSTCONDICI�N: se obtiene el nodo siguiente al actual
PAR�METROS:
    - nodo: puntero al nodo
DEVUELVE: NULL. */
PtrNodo getSiguiente(PtrNodo nodo);

#endif // TDANODO_H_INCLUDED
