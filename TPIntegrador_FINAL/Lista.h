#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdbool.h>
#include "util.h"
#include "TDANodo.h"


/* ¿Cómo está compuesta una lista?
        Como una Pila.

Entonces, ¿cual es la diferencia?
    La implementacion de las primitivas. En una lista,
podemos obtener, setear o remover cualquiera de los elementos.
Tambien podemos elegir entre obtener el primer nodo o el resto.
Podemos pensarlo como que una lista tiene un título (primer nodo, cabecera)
Y una serie de ítems (el resto de nodos)

En una pila, todo eso no se puede hacer, porque está pensada para poner y
sacar las cosas en un orden determinado: LIFO (Last In, First Out). */


typedef struct Lista
{
    PtrNodo primero;
} Lista;
typedef Lista* ListaPtr;

const void* FinLista; //en Lista.c se define como NULL

/** OPERACIÓN: construccion (constructor)
PRECONDICIÓN: la lista no debe haber sido creada.
POSTCONDICIÓN: lista queda creada vacía y preparada para ser usada.
PARÁMETROS: ninguno
DEVUELVE: puntero a la lista creada. */
ListaPtr crearLista();

/** OPERACIÓN: destruccion (destructor)
PRECONDICIÓN: la lista debe haber sido creada y sus nodos eliminados.
POSTCONDICIÓN: se reclama la memoria de lista.
PARÁMETROS:
    - lista: puntero a la lista a destruir
    - remover: indica si se deben remover los nodos antes de reclamar memoria
DEVUELVE: FinLista. */
ListaPtr destruirLista(ListaPtr lista,bool remover);

/** OPERACIÓN: verificación de estado
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: ninguna
PARÁMETROS:
    - Puntero a la lista que se desea saber si se encuentra vacía
DEVUELVE: true si la lista se encuentra vacía (ListaPtr=FinLista), false de lo contrario. */
bool listaVacia(ListaPtr lista);


/** OPERACIÓN: obtención del dato
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se obitiene el dato en la posicion solicitada
PARÁMETROS:
    - lista: puntero a la lista
posicion: Entero indicando la posición solicitada. 0 la primera
          Si la posición no existe, devuelve FinLista
DEVUELVE: puntero al dato obtenido o FinLista. */
PtrDato getDatoLista(ListaPtr lista,int posicion);

/** OPERACIÓN: obtención del dato de la primera posición
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se obitiene el dato en la primera posicion. Si la lista esta vacía
DEVUELVE: FinLista
PARÁMETROS:
    - lista: puntero a la lista
DEVUELVE: puntero al dato de la cabecera. */
PtrDato getCabecera(ListaPtr lista); //obtiene el 1er nodo (cabecera) de la lista

/** OPERACIÓN: obtención de la cola de la lista (sin el primer nodo)
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se obtiene el resto de la lista
PARÁMETROS:
    - lista: puntero a la lista
DEVUELVE: puntero al resto de la lista. */
ListaPtr getResto(ListaPtr lista);

/** OPERACIÓN: obtención de la longitud de la lista
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se obtiene la longitud de la lista
PARÁMETROS:
    - lista: puntero a la lista
DEVUELVE: puntero al resto de la lista. */
int longitudLista(ListaPtr lista);

/** OPERACIÓN: agregado antes de la cabecera
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se agrega el dato antes de la cabecera de la lista
PARÁMETROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
DEVUELVE: true si pudo agregar, false de lo contrario. */
void agregarDatoLista(ListaPtr lista, PtrDato dato);

/** OPERACIÓN: agrega un dato al final de una lista
PRECONDICIÓN: la lista debe haber sido creada con crearLista
POSTCONDICIÓN: Se inserta el dato luego del último nodo de la lista
PARÁMETROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
DEVUELVE: nada. */
void agregarDatoAlFinalDeLista(ListaPtr lista, PtrDato dato);

/** OPERACIÓN: inserción en lista
PRECONDICIÓN: la lista debe haber sido creada.
POSTCONDICIÓN: Se inserta el dato despues de la posición indicada
PARÁMETROS:
    - lista: puntero a la lista
    - dato: puntero al dato a insertar
    - posición: posición luego de la que se desea insertar el dato. Si la posición no
                existe, devuelve false
DEVUELVE: true si pudo insertar, false de lo contrario. */
bool insertarDatoLista(ListaPtr lista,PtrDato dato,int posicion);

/** OPERACIÓN: agregado de una lista al final de otra
PRECONDICIÓN: estaLista y otraLista deben haber sido creadas usando crearLista.
POSTCONDICIÓN: Se agrega otraLista luego del ultimo nodo de estaLista
PARÁMETROS:
    - estaLista: puntero a la lista a la que se agregará
    - otraLista: puntero a la lista que se agregará
DEVUELVE: nada. */
void agregarLista(ListaPtr estaLista,ListaPtr otraLista);

/** OPERACIÓN: remoción
PRECONDICIÓN: la lista debe haber sido creada y tener al menos un elemento.
POSTCONDICIÓN: Se remueve el nodo de posición
PARÁMETROS:
    - lista: puntero a la lista
    - posicion: posición del nodo a remover. Si no existe, no se remueve
           y devuelve FinLista
DEVUELVE: puntero al dato removido de la lista. */
PtrDato removerDeLista(ListaPtr lista, int posicion);


#endif // LISTA_H_INCLUDED
