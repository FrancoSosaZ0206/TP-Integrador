#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "TDANodo.h"
#include "Util.h"

int longitudPilaAyudante(PtrNodo nodo, int longitud);

PilaPtr crearPila(){
    PilaPtr pila=(PilaPtr)obtenerMemoria(sizeof(Pila));
    pila->primero=0;
    return pila;
}

PilaPtr destruirPila(PilaPtr pila){
    // desapilamos cada uno de los nodos para eliminarlos. Si habian datos a eliminar,
    // eso es responsabilidad del usuario
    while(!pilaVacia(pila)){
        desapilar(pila);
    }

    free(pila);

    return NULL;
}

bool pilaVacia(PilaPtr pila){
    return (pila->primero==0);
}

int longitudPila(PilaPtr pila){
    // la longitud es cuantos nodos hay en la pila. Para saberlo, hay que recorrerla
    int longitud=0;
    PtrNodo nodo=pila->primero;
    while(nodo!=0){
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

void apilar(PilaPtr pila, PtrDato dato){
    // creamos un nodo, le asignamos el dato y lo ponemos al frente de la pila
    if(pila!=NULL){
        PtrNodo nodo=crearNodo(dato);
        setDato(nodo,dato);
        setSiguiente(nodo,pila->primero);
        pila->primero=nodo;
    }
}

PtrDato desapilar(PilaPtr pila){
    PtrDato dato=NULL;
    if(!pilaVacia(pila)){
        PtrNodo nodo=pila->primero;
        pila->primero=getSiguiente(nodo);
        dato=getDato(nodo);
        nodo=destruirNodo(nodo);
    }
    return dato;
}

PtrDato primeroPila(PilaPtr pila){
    // devuelve el dato de la primera posición de la pila
    // pero sin desapilarlo
    PtrDato dato=NULL;
    if(!pilaVacia(pila)){
        PtrNodo nodo=pila->primero;
        dato=getDato(nodo);
    }
    return dato;
}
