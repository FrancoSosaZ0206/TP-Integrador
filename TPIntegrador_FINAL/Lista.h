#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdbool.h>
#include "util.h"
#include "TDANodo.h"


/* �C�mo est� compuesta una lista?
        Como una Pila.

Entonces, �cual es la diferencia?
    La implementacion de las primitivas. En una lista,
podemos obtener, setear o remover cualquiera de los elementos.
Tambien podemos elegir entre obtener el primer nodo o el resto.
Podemos pensarlo como que una lista tiene un t�tulo (primer nodo, cabecera)
Y una serie de �tems (el resto de nodos)

En una pila, todo eso no se puede hacer, porque est� pensada para poner y
sacar las cosas en un orden determinado: LIFO (Last In, First Out). */


typedef struct Lista
{
    PtrNodo primero;
} Lista;
typedef Lista* ListaPtr;

const void* FinLista; //en Lista.c se define como NULL

/** OPERACI�N: construccion (constructor)
PRECONDICI�N: la lista no debe haber sido creada.
POSTCONDICI�N: lista queda creada vac�a y preparada para ser usada.
PAR�METROS: ninguno
DEVUELVE: puntero a la lista creada. */
ListaPtr crearLista();

/** OPERACI�N: destruccion (destructor)
PRECONDICI�N: la lista debe haber sido creada y sus nodos eliminados.
POSTCONDICI�N: se reclama la memoria de lista.
PAR�METROS:
    - lista: puntero a la lista a destruir
    - remover: indica si se deben remover los nodos antes de reclamar memoria
DEVUELVE: FinLista. */
ListaPtr destruirLista(ListaPtr lista,bool remover);

/** OPERACI�N: verificaci�n de estado
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: ninguna
PAR�METROS:
    - Puntero a la lista que se desea saber si se encuentra vac�a
DEVUELVE: true si la lista se encuentra vac�a (ListaPtr=FinLista), false de lo contrario. */
bool listaVacia(ListaPtr lista);


/** OPERACI�N: obtenci�n del dato
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se obitiene el dato en la posicion solicitada
PAR�METROS:
    - lista: puntero a la lista
posicion: Entero indicando la posici�n solicitada. 0 la primera
          Si la posici�n no existe, devuelve FinLista
DEVUELVE: puntero al dato obtenido o FinLista. */
PtrDato getDatoLista(ListaPtr lista,int posicion);

/** OPERACI�N: obtenci�n del dato de la primera posici�n
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se obitiene el dato en la primera posicion. Si la lista esta vac�a
DEVUELVE: FinLista
PAR�METROS:
    - lista: puntero a la lista
DEVUELVE: puntero al dato de la cabecera. */
PtrDato getCabecera(ListaPtr lista); //obtiene el 1er nodo (cabecera) de la lista

/** OPERACI�N: obtenci�n de la cola de la lista (sin el primer nodo)
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se obtiene el resto de la lista
PAR�METROS:
    - lista: puntero a la lista
DEVUELVE: puntero al resto de la lista. */
ListaPtr getResto(ListaPtr lista);

/** OPERACI�N: obtenci�n de la longitud de la lista
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se obtiene la longitud de la lista
PAR�METROS:
    - lista: puntero a la lista
DEVUELVE: puntero al resto de la lista. */
int longitudLista(ListaPtr lista);

/** OPERACI�N: agregado antes de la cabecera
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se agrega el dato antes de la cabecera de la lista
PAR�METROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
DEVUELVE: true si pudo agregar, false de lo contrario. */
void agregarDatoLista(ListaPtr lista, PtrDato dato);

/** OPERACI�N: agrega un dato al final de una lista
PRECONDICI�N: la lista debe haber sido creada con crearLista
POSTCONDICI�N: Se inserta el dato luego del �ltimo nodo de la lista
PAR�METROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
DEVUELVE: nada. */
void agregarDatoAlFinalDeLista(ListaPtr lista, PtrDato dato);

/** OPERACI�N: inserci�n en lista
PRECONDICI�N: la lista debe haber sido creada.
POSTCONDICI�N: Se inserta el dato despues de la posici�n indicada
PAR�METROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
    - posici�n: posici�n luego de la que se desea insertar el dato. Si la posici�n no
                existe, devuelve false
DEVUELVE: true si pudo insertar, false de lo contrario. */
bool insertarDatoLista(ListaPtr lista,PtrDato dato,int posicion);

/** OPERACI�N: agregado de una lista al final de otra
PRECONDICI�N: estaLista y otraLista deben haber sido creadas usando crearLista.
POSTCONDICI�N: Se agrega otraLista luego del ultimo nodo de estaLista
PAR�METROS:
    - estaLista: puntero a la lista a la que se agregar�
    - otraLista: puntero a la lista que se agregar�
DEVUELVE: nada. */
void agregarLista(ListaPtr estaLista,ListaPtr otraLista);

/** OPERACI�N: remoci�n
PRECONDICI�N: la lista debe haber sido creada y tener al menos un elemento.
POSTCONDICI�N: Se remueve el nodo de posici�n
PAR�METROS:
    - lista: puntero a la lista
    - posicion: posici�n del nodo a remover. Si no existe, no se remueve
           y devuelve FinLista
DEVUELVE: puntero al dato removido de la lista. */
PtrDato removerDeLista(ListaPtr lista, int posicion);


#endif // LISTA_H_INCLUDED
