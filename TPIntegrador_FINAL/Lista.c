#include <stdbool.h>
#include "util.h"
#include "TDANodo.h"
#include "Lista.h"

const void* FinLista=NULL;

//declarada acá porque no es parte de la interfaz
PtrNodo getNodoLista(ListaPtr lista, int posicion);

ListaPtr crearLista()
{
    ListaPtr lista=(ListaPtr)obtenerMemoria(sizeof(Lista));
    lista->primero=0;
    return lista;
}

ListaPtr destruirLista(ListaPtr lista,bool remover)
{
    if(remover)
        while(!listaVacia(lista))
            removerDeLista(lista,0);

    free(lista);
    return 0; //no estaba en la implementacion del profe. Supongo que va, pero si no funca probamos sacandola
}

bool listaVacia(ListaPtr lista)
{
    return (lista->primero==0);
}



PtrNodo getNodoLista(ListaPtr lista, int posicion)
{//funcion auxiliar para getDatoLista, no está en la interfaz de Lista.h
    PtrNodo nodo=lista->primero;
    int posicionActual=0;
    if(nodo!=0)
    {
        while(posicionActual<posicion && getSiguiente(nodo)!=0)
        {
            posicionActual++;
            nodo=getSiguiente(nodo);
        }
    }
    return nodo;
}

PtrDato getDatoLista(ListaPtr lista,int posicion)
{
    PtrDato dato=0;
    PtrNodo nodo=getNodoLista(lista,posicion);
    if(nodo!=0)
    {
        dato=getDato(nodo);
    }
    return dato; //devuelve NULL (0) si no se pudo obtener el dato
}

PtrDato getCabecera(ListaPtr lista)
{
    PtrDato dato=0;
    if(lista->primero!=0)
    {
        dato=getDato(lista->primero);
    }
    return dato;
}

ListaPtr getResto(ListaPtr lista)
{
    ListaPtr resto=crearLista();
    if(lista->primero!=0)
    {
        resto->primero=getSiguiente(lista->primero);
    }
    return resto;
}



int longitudLista(ListaPtr lista)
{
    int longitud=0;
    PtrNodo nodo=lista->primero;
    while(nodo!=0)
    {
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

void agregarDatoLista(ListaPtr lista,PtrDato dato)
{
    PtrNodo nuevoNodo=crearNodo(dato);
    setSiguiente(nuevoNodo,lista->primero); //Hace esto: nuevoNodo->sgte=lista->primero;
    lista->primero=nuevoNodo; //cambiamos la cabecera para que apunte a nuevoNodo.
}// don't worry. En la linea anterior ya los vinculamos entre sí con setSiguiente, así que nada se pierde.

void agregarDatoAlFinalDeLista(ListaPtr lista,PtrDato dato)
{
    PtrNodo nuevoNodo=crearNodo(dato);
    PtrNodo ultNodo=getNodoLista(lista,longitudLista(lista)); //obtenemos el último nodo de la lista
    setSiguiente(ultNodo,nuevoNodo); //ponemos el nuevo nodo como siguiente del último
}



bool insertarDatoLista(ListaPtr lista,PtrDato dato,int posicion)
{ //recordamos: inserta el dato DESPUES de la posicion. NOTA: Lo hace 2 posiciones después.
    PtrNodo nodo=getNodoLista(lista,posicion); //obtiene el nodo DE LA POSICION PEDIDA
    bool resultado=false;
    if(nodo!=0)
    {
        PtrNodo nuevoNodo=crearNodo(dato); //el nuevo dato precisa un nodo para ser insertado a la lista
        setSiguiente(nuevoNodo,getSiguiente(nodo)); //el nodo siguiente a nodo (siguiente del siguiente) es ahora el siguiente al nuevo
        setSiguiente(nodo,nuevoNodo); //el nuevo nodo es ahora el siguiente al nodo en la posicion indicada (otra vez: DESPUES de la posicion).
        resultado=true;
    }
    return resultado;
}
/*En otras palabras, lo que se hace es:
1. Obtener el nodo en la posicion que se pide.
2. Crear un nuevo nodo, y linkearlo con el siguiente a ese.
3. Linkear el nodo en la posicion que se pide con el nuevo, que está en la siguiente.
De esta manera, vemos que se termina insertando el dato en la posicion siguiente a la que se pide.
Q: ¿Por qué? ¿Por qué no simplemente en la posicion que se pide?
R: Porque no tenemos funciones que nos permitan hacer eso. Para ello, deberíamos hacer algo que nos permita
obtener el nodo ANTERIOR al de la posicion que se pide, y dado que los nodos de una lista simplemente enlazada como esta
solo apuntan a su SIGUIENTE, obtener el ANTERIOR simplemente no es posible. Para hacer eso, deberíamos implementar una
lista DOBLEMENTE ENLAZADA, en la cual cada nodo TAMBIEN APÚNTA AL ANTERIOR. Tendríamos una funcion getAnterior(nodo) y sería
más intuitivo y fácil de insertar. Pero en una lista como esta, se puede hacer solo de esta manera.
*/
void agregarLista(ListaPtr estaLista,ListaPtr otraLista)
{
    if(estaLista->primero==0)
        estaLista->primero=otraLista->primero;
    else
    {
        PtrNodo nodo=estaLista->primero;
        while(getSiguiente(nodo)!=0)
            nodo=getSiguiente(nodo);
        setSiguiente(nodo,otraLista->primero);
    }
}



PtrDato removerDeLista(ListaPtr lista, int posicion)
{
    PtrDato dato=NULL;
    PtrNodo nodoEliminar=NULL;
    if(lista->primero!=0)
    {
        if(posicion==0)
        {
            nodoEliminar=lista->primero;
            dato=getDato(nodoEliminar);
            lista->primero=getSiguiente(lista->primero);
            destruirNodo(nodoEliminar);
        }
        else
        {
            PtrNodo nodo=getNodoLista(lista,posicion-1);
            if(nodo!=0)
            {
                nodoEliminar=getSiguiente(nodo);
                if(nodoEliminar!=0)
                {
                    dato=getDato(nodoEliminar);
                    setSiguiente(nodo,getSiguiente(nodoEliminar));
                    destruirNodo(nodoEliminar);
                }
            }
        }
    }
    return dato;
}
