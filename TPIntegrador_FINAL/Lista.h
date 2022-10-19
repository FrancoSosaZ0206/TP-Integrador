#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdbool.h>
#include "util.h"
#include "TDANodo.h"
/*
Como est� compuesta una lista?
Como una Pila.
Entonces, �cual es la diferencia?
La implementacion de las primitivas. En una lista,
podemos obtener, setear o remover cualquiera de los elementos.
Tambien podemos elegir entre obtener el primer nodo o el resto.
Podemos pensarlo como que una lista tiene un t�tulo (primer nodo, cabecera)
Y una serie de �tems (el resto de nodos)

En una pila, todo eso no se puede hacer, porque est� pensada para poner y
sacar las cosas en un orden determinado: LIFO (Last In, First Out)
*/
typedef struct Lista
{
    PtrNodo primero;
} Lista;
typedef Lista* ListaPtr;

const void* FinLista; //en Lista.c se define como NULL

// Operaci�n de construccion (constructor)
// Precondici�n: la lista no debe haber sido creada.
// Postcondici�n: lista queda creada vac�a y preparada para ser usada.
// Par�metros:
//  Ninguna
// Devuelve puntero a la lista creada
ListaPtr crearLista();


//remover: indica si hay que remover los nodos antes de reclamar memoria.
// Operaci�n de destruccion (destructor)
// Precondici�n: la lista debe haber sido creada y sus nodos eliminados.
// Postcondici�n: se reclama la memoria de lista.
// Par�metros:
//  lista: puntero a la lista a destruir
//  remover: indica si se deben remover los nodos antes de reclamar
// Devuelve FinLista
ListaPtr destruirLista(ListaPtr lista,bool remover);

//se devuelve true si la lista est� vac�a
// Operaci�n de verificaci�n de estado
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: ninguna
// Par�metros:
//  Puntero a la lista que se desea saber si se encuentra vac�a
// Devuelve true si la lista se encuentra vac�a (ListaPtr=FinLista), false de otro modo
bool listaVacia(ListaPtr lista);

// Operaci�n de obtenci�n del dato
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se obitiene el dato en la posicion solicitada
// Par�metros:
// lista: puntero a la lista
// posicion: Entero indicando la posici�n solicitada. 0 la primera
// Si la posici�n no existe, devuelve FinLista
// Devuelve puntero al dato obtenido o FinLista
PtrDato getDatoLista(ListaPtr lista,int posicion);

// Operaci�n de obtenci�n del dato de la primera posici�n
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se obitiene el dato en la primera posicion. Si la lista esta vac�a
// devuelve FinLista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al dato de la cabecera
//obtiene el 1er nodo (cabecera) de la lista
PtrDato getCabecera(ListaPtr lista);

// Operaci�n de obtenci�n de la cola de la lista (sin el primer nodo)
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se obtiene el resto de la lista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
ListaPtr getResto(ListaPtr lista);

// Operaci�n de obtenci�n de la longitud de la lista
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se obtiene la longitud de la lista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
int longitudLista(ListaPtr lista);

//agrega un dato al principio de la lista
// Operaci�n de agregado antes de la cabecera
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se agrega el dato antes de la cabecera de la lista
// Par�metros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
// Devuelve true si pudo agregar, false de lo contrario
void agregarDatoLista(ListaPtr lista, PtrDato dato);

//agrega un dato al final de la lista
// Operaci�n de inserci�n en lista
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se inserta el dato despues de la posici�n indicada
// Par�metros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
//  posici�n: posici�n luego de la que se desea insertar el dato. Si la posici�n no
//            existe, devuelve false
void agregarDatoAlFinalDeLista(ListaPtr lista, PtrDato dato);

//inserta el dato despu�s de la posici�n indicada. Devuelve true si se pudo, y false si no.
// Operaci�n de inserci�n en lista
// Precondici�n: la lista debe haber sido creada.
// Postcondici�n: Se inserta el dato despues de la posici�n indicada
// Par�metros:
//  lista: puntero a la lista
//  dato: puntero al dato a insertar
//  posici�n: posici�n luego de la que se desea insertar el dato. Si la posici�n no
//            existe, devuelve false
// Devuelve true si pudo insertar, false de lo contrario
bool insertarDatoLista(ListaPtr lista,PtrDato dato,int posicion);

//concatena una lista al final de otra.
//Precondici�n: deben haberse creado dos listas usando crearLista
// Operaci�n de agregado de una lista al final de otra
// Precondici�n: estaLista y otraLista deben haber sido creadas.
// Postcondici�n: Se agrega otraLista luego del ultimo nodo de estaLista
// Par�metros:
//  estaLista: puntero a la lista a la que se agregar�
//  otraLista: puntero a la lista que se agregar�
// No devuelve valores
void agregarLista(ListaPtr estaLista,ListaPtr otraLista);

// Operaci�n de remoci�n
// Precondici�n: la lista debe haber sido creada y tener al menos un elemento.
// Postcondici�n: Se remueve el nodo de posici�n
// Par�metros:
//  lista: puntero a la lista
//  posicion: posici�n del nodo a remover. Si no existe, no se remueve
//            y devuelve FinLista
// Devuelve puntero al dato removido de la lista
PtrDato removerDeLista(ListaPtr lista, int posicion);

//FUNCI�N De verificacion
//PRECONDICI�N: la lista a evaluar debe estar definida y creada en memoria dinamica
//POSTCONDICI�N: verifica que el numero pasado no supere los parametros de la lista
// devuelve true si esta dentro de los parametros, false si esta fuera
//PAR�METROS: puntero a la lista a evaluar
// el numero a evaluar
//DEVUELVE: booleano.
bool verificarLimiteLista(ListaPtr listaEvaluar, int numeroEvaluar);

#endif // LISTA_H_INCLUDED
