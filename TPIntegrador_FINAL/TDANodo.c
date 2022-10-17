#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "TDANodo.h"

const void* SinNodoSgte=NULL;

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE CREACION///
///-----------------------------------------------------------------------------------------------------------///
PtrNodo crearNodo(PtrDato dato)
{
    PtrNodo nodo=(PtrNodo)obtenerMemoria(sizeof(Nodo));
    nodo->dato=dato;
    nodo->sgte=0;
    return nodo;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

PtrNodo destruirNodo(PtrNodo nodo)
{
    //la destruccion del dato queda por cuenta del usuario (en main)
    free(nodo);
    return 0;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setDato(PtrNodo nodo,PtrDato dato)
{
    nodo->dato=dato;
}

void setSiguiente(PtrNodo esteNodo,PtrNodo siguienteNodo)
{
    esteNodo->sgte=siguienteNodo;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

PtrDato getDato(PtrNodo nodo)
{
    return nodo->dato;
}

PtrNodo getSiguiente(PtrNodo nodo)
{
    return nodo->sgte;
}
