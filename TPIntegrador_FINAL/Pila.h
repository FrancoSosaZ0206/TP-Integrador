#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDANodo.h"

typedef struct Pila{
    PtrNodo primero;      // puntero al primer nodo de la pila
} Pila;

typedef Pila* PilaPtr;

// Terminador de pila. En Pila.c se define como NULL;
const void* FinPila;

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

// Operación de construccion (constructor)
// Precondición: la pila no debe haber sido creada.
// Postcondición: píla queda creada vacía y preparada para ser usada.
// Parámetros:
//  Ninguno
// Devuelve puntero a la pila creada
PilaPtr crearPila();

// Operación de destruccion (destructor)
// Precondición: la pila debe haber sido creada.
// Postcondición: la pila queda vacía y la memoria que ocupaba se libera
// Parámetros:
//  Ninguna
// Devuelve NULL
PilaPtr destruirPila(PilaPtr pila);

// Operación de verificación de estado
// Precondición: la pila debe haber sido creada.
// Postcondición: ninguna
// Parámetros:
//  pila: Puntero a la pila que se desea saber si se encuentra vacía
// Devuelve true si la pila se encuentra vacía (primero=FinPila), false de otro modo
bool pilaVacia(PilaPtr pila);

// Operación de obtención de la longitud de la pila
// Precondición: la pila debe haber sido creada.
// Postcondición: Se obtiene la longitud de la pila (si vacía =0)
// Parámetros:
//  pila: puntero a la pila
// Devuelve longitud de la pila
int longitudPila(PilaPtr pila);

// Operación de agregado a pila
// Precondición: la pila debe haber sido creada.
// Postcondición: Se inserta el dato antes de la primera posición
// Parámetros:
//  pila: puntero a la pila
//  dato: puntero al dato a insertar
// No devuelve nada.
void apilar(PilaPtr pila, PtrDato dato);

// Operación de eliminacion del ultimo nodo de la pila
// Precondición: la pila debe haber sido creada.
// Postcondición: ninguna.
// Parámetros:
//  pila: puntero a la pila
// Devuelve puntero al ultimo dato de la pila.
PtrDato desapilar(PilaPtr pila);

// Operación de obtencion del primer dato de la pila.
// Precondición: la pila debe haber sido creada.
// Postcondición: ninguna.
// Parámetros:
//  pila: puntero a la pila
// Devuelve puntero al primer dato de la pila sin desapilar.
PtrDato primeroPila(PilaPtr pila);


#endif // PILA_H_INCLUDED
