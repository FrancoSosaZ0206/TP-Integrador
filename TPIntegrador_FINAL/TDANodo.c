#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "TDANodo.h"

const void* SinNodoSiguiente=NULL;

PtrNodo crearNodo(PtrDato dato)
{
    PtrNodo nodo=(PtrNodo)obtenerMemoria(sizeof(Nodo));
    nodo->dato=dato;
    nodo->sgte=0;
    return nodo;
}

PtrNodo destruirNodo(PtrNodo nodo)
{//la destruccion del dato queda por cuenta del usuario (en main)
    free(nodo);
    return 0;
}

void setDato(PtrNodo nodo,PtrDato dato)
{
    nodo->dato=dato;
}

PtrDato getDato(PtrNodo nodo)
{
    return nodo->dato;
}

/*Precondición: Deben haberse creado 2 nodos con crearNodo*/
/*Postcondición: Vinculamos los nodos asignando el nuevo en el campo sgte del primero.*/
void setSiguiente(PtrNodo esteNodo,PtrNodo siguienteNodo)
{
    esteNodo->sgte=siguienteNodo;
}

PtrNodo getSiguiente(PtrNodo nodo)
{
    return nodo->sgte;
}
