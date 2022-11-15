#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDANodo.h"

typedef struct Pila
{ // puntero al primer nodo de la pila
    PtrNodo primero;
} Pila;

typedef Pila* PilaPtr;

// Terminador de pila. En Pila.c se define como NULL;
const void* FinPila;

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/** OPERACIÓN: construccion (constructor)
PRECONDICIÓN: la pila no debe haber sido creada.
POSTCONDICIÓN: píla queda creada vacía y preparada para ser usada.
PARÁMETROS: ninguno
DEVUELVE: puntero a la pila creada. */
PilaPtr crearPila();

/** OPERACIÓN: destruccion (destructor)
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: la pila queda vacía y la memoria que ocupaba se libera
PARÁMETROS: ninguno
DEVUELVE: NULL. */
PilaPtr destruirPila(PilaPtr pila);

/** OPERACIÓN: verificación de estado
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: ninguna
PARÁMETROS:
    - pila: Puntero a la pila que se desea saber si se encuentra vacía
DEVUELVE: true si la pila se encuentra vacía (primero=FinPila), false de otro modo. */
bool pilaVacia(PilaPtr pila);

/** OPERACIÓN: obtención de la longitud de la pila
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: Se obtiene la longitud de la pila (si vacía =0)
PARÁMETROS:
    - pila: puntero a la pila
DEVUELVE: longitud de la pila. */
int longitudPila(PilaPtr pila);

/** OPERACIÓN: agregado a pila
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: Se inserta el dato antes de la primera posición
PARÁMETROS:
    - pila: puntero a la pila
    - dato: puntero al dato a insertar
DEVUELVE: nada. */
void apilar(PilaPtr pila, PtrDato dato);

/** OPERACIÓN: eliminacion del ultimo nodo de la pila
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: ninguna.
PARÁMETROS:
    - pila: puntero a la pila
DEVUELVE: puntero al ultimo dato de la pila. */
PtrDato desapilar(PilaPtr pila);

/** OPERACIÓN: obtencion del primer dato de la pila.
PRECONDICIÓN: la pila debe haber sido creada.
POSTCONDICIÓN: ninguna.
PARÁMETROS:
    - pila: puntero a la pila
DEVUELVE: puntero al primer dato de la pila sin desapilar. */
PtrDato primeroPila(PilaPtr pila);


#endif // PILA_H_INCLUDED
