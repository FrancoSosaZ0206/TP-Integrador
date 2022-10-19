#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdbool.h>
#include "util.h"
#include "TDANodo.h"
/*
Como está compuesta una lista?
Como una Pila.
Entonces, ¿cual es la diferencia?
La implementacion de las primitivas. En una lista,
podemos obtener, setear o remover cualquiera de los elementos.
Tambien podemos elegir entre obtener el primer nodo o el resto.
Podemos pensarlo como que una lista tiene un título (primer nodo, cabecera)
Y una serie de ítems (el resto de nodos)

En una pila, todo eso no se puede hacer, porque está pensada para poner y
sacar las cosas en un orden determinado: LIFO (Last In, First Out)
*/
typedef struct Lista
{
    PtrNodo primero;
} Lista;
typedef Lista* ListaPtr;

const void* FinLista; //en Lista.c se define como NULL

// Operación de construccion (constructor)
// Precondición: la lista no debe haber sido creada.
// Postcondición: lista queda creada vacía y preparada para ser usada.
// Parámetros:
//  Ninguna
// Devuelve puntero a la lista creada
ListaPtr crearLista();


//remover: indica si hay que remover los nodos antes de reclamar memoria.
// Operación de destruccion (destructor)
// Precondición: la lista debe haber sido creada y sus nodos eliminados.
// Postcondición: se reclama la memoria de lista.
// Parámetros:
//  lista: puntero a la lista a destruir
//  remover: indica si se deben remover los nodos antes de reclamar
// Devuelve FinLista
ListaPtr destruirLista(ListaPtr lista,bool remover);

//se devuelve true si la lista está vacía
// Operación de verificación de estado
// Precondición: la lista debe haber sido creada.
// Postcondición: ninguna
// Parámetros:
//  Puntero a la lista que se desea saber si se encuentra vacía
// Devuelve true si la lista se encuentra vacía (ListaPtr=FinLista), false de otro modo
bool listaVacia(ListaPtr lista);

// Operación de obtención del dato
// Precondición: la lista debe haber sido creada.
// Postcondición: Se obitiene el dato en la posicion solicitada
// Parámetros:
// lista: puntero a la lista
// posicion: Entero indicando la posición solicitada. 0 la primera
// Si la posición no existe, devuelve FinLista
// Devuelve puntero al dato obtenido o FinLista
PtrDato getDatoLista(ListaPtr lista,int posicion);

// Operación de obtención del dato de la primera posición
// Precondición: la lista debe haber sido creada.
// Postcondición: Se obitiene el dato en la primera posicion. Si la lista esta vacía
// devuelve FinLista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al dato de la cabecera
//obtiene el 1er nodo (cabecera) de la lista
PtrDato getCabecera(ListaPtr lista);

// Operación de obtención de la cola de la lista (sin el primer nodo)
// Precondición: la lista debe haber sido creada.
// Postcondición: Se obtiene el resto de la lista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
ListaPtr getResto(ListaPtr lista);

// Operación de obtención de la longitud de la lista
// Precondición: la lista debe haber sido creada.
// Postcondición: Se obtiene la longitud de la lista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
int longitudLista(ListaPtr lista);

//agrega un dato al principio de la lista
// Operación de agregado antes de la cabecera
// Precondición: la lista debe haber sido creada.
// Postcondición: Se agrega el dato antes de la cabecera de la lista
// Parámetros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
// Devuelve true si pudo agregar, false de lo contrario
void agregarDatoLista(ListaPtr lista, PtrDato dato);

//agrega un dato al final de la lista
// Operación de inserción en lista
// Precondición: la lista debe haber sido creada.
// Postcondición: Se inserta el dato despues de la posición indicada
// Parámetros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
//  posición: posición luego de la que se desea insertar el dato. Si la posición no
//            existe, devuelve false
void agregarDatoAlFinalDeLista(ListaPtr lista, PtrDato dato);

//inserta el dato después de la posición indicada. Devuelve true si se pudo, y false si no.
// Operación de inserción en lista
// Precondición: la lista debe haber sido creada.
// Postcondición: Se inserta el dato despues de la posición indicada
// Parámetros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
//  posición: posición luego de la que se desea insertar el dato. Si la posición no
//            existe, devuelve false
// Devuelve true si pudo insertar, false de lo contrario
bool insertarDatoLista(ListaPtr lista,PtrDato dato,int posicion);

//concatena una lista al final de otra.
//Precondición: deben haberse creado dos listas usando crearLista
// Operación de agregado de una lista al final de otra
// Precondición: estaLista y otraLista deben haber sido creadas.
// Postcondición: Se agrega otraLista luego del ultimo nodo de estaLista
// Parámetros:
//  estaLista: puntero a la lista a la que se agregará
//  otraLista: puntero a la lista que se agregará
// No devuelve valores
void agregarLista(ListaPtr estaLista,ListaPtr otraLista);

// Operación de remoción
// Precondición: la lista debe haber sido creada y tener al menos un elemento.
// Postcondición: Se remueve el nodo de posición
// Parámetros:
//  lista: puntero a la lista
//  posicion: posición del nodo a remover. Si no existe, no se remueve
//            y devuelve FinLista
// Devuelve puntero al dato removido de la lista
PtrDato removerDeLista(ListaPtr lista, int posicion);

//FUNCIÓN De verificacion
//PRECONDICIÓN: la lista a evaluar debe estar definida y creada en memoria dinamica
//POSTCONDICIÓN: verifica que el numero pasado no supere los parametros de la lista
// devuelve true si esta dentro de los parametros, false si esta fuera
//PARÁMETROS: puntero a la lista a evaluar
// el numero a evaluar
//DEVUELVE: booleano.
bool verificarLimiteLista(ListaPtr listaEvaluar, int numeroEvaluar);

#endif // LISTA_H_INCLUDED
