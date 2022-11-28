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

/** OPERACIÓN: construccion (constructor)
PRECONDICIÓN: El nodo no debe haberse creado
POSTCONDICIÓN: Se crea el nodo con null en PtrDato y SinNodoSgte en sgte
PARÁMETROS: ninguno
DEVUELVE: puntero al nodo creado. */
PtrNodo crearNodo(PtrDato dato);

/** OPERACIÓN: destruccion (destructor)
PRECONDICIÓN: El nodo debe haberse creado
POSTCONDICIÓN: Se Libera la memoria del nodo eliminado
PARÁMETROS:
    - puntero al nodo a eliminar
DEVUELVE: NULL. */
PtrNodo destruirNodo(PtrNodo nodo);

/** OPERACIÓN: establecimiento de datos
PRECONDICIÓN: nodo creado con crearNodo()
POSTCONDICIÓN: almacena el dato proporcionado en el nodo apuntado por ptrNodo.
PARÁMETROS:
    - ptrNodo: puntero al nodo
    - PtrDato: Puntero al dato a almacenar
DEVUELVE: NULL. */
void setDato(PtrNodo nodo,PtrDato dato);

/** OPERACIÓN: obtención de datos
PRECONDICIÓN: nodo creado con crearNodo()
POSTCONDICIÓN: obtiene el dato almacenado en el nodo apuntado por ptrNodo.
PARÁMETROS:
    - ptrNodo: puntero al nodo
DEVUELVE: puntero al dato almacenado. */
PtrDato getDato(PtrNodo nodo);

/** OPERACIÓN: establecimiento del siguiente nodo
PRECONDICIÓN: esteNodo creado con crearNodo()
POSTCONDICIÓN: se establece el nodo siguiente al actual
PARÁMETROS:
    - esteNodo: puntero al nodo
DEVUELVE: NULL. */
void setSiguiente(PtrNodo esteNodo,PtrNodo siguienteNodo);

/** OPERACIÓN: obtención del siguiente nodo
PRECONDICIÓN: esteNodo creado con crearNodo()
POSTCONDICIÓN: se obtiene el nodo siguiente al actual
PARÁMETROS:
    - nodo: puntero al nodo
DEVUELVE: NULL. */
PtrNodo getSiguiente(PtrNodo nodo);

#endif // TDANODO_H_INCLUDED
