#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDAFechaYHora.h"
#include "TDAPaquetes.h"
#include "Lista.h"
#include "Pila.h"
#include "TDARepartos.h"

RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));

    reparto->chofer=chofer;
    reparto->vehiculo=vehiculo;
    reparto->fechaSalida=fechaSalida;
    reparto->fechaRetorno=fechaRetorno;
    reparto->paquetes=paquetes;

    return reparto;
}

RepartoPtr destruirReparto(RepartoPtr reparto)
{ //liberamos la memoria de todos los campos que hayan sido reservados dinamicamente con sus respectivas funciones. En este caso, son todos los campos.
/**Como el chofer y vehiculo se los pasamos como punteros, destruirlos acá ocasionaría que se eliminen tambien del centro logistico.
No queremos eso, así que simplemente no las destruimos.*/
    reparto->fechaSalida=destruirFecha(reparto->fechaSalida);
    reparto->fechaRetorno=destruirFecha(reparto->fechaRetorno);
    reparto->paquetes=destruirPila(reparto->paquetes);

    free(reparto);

    return NULL;
}
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes)
{
    RepartoPtr reparto=crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    return reparto;
}
RepartoPtr cerrarReparto(RepartoPtr reparto)
{
    reparto=destruirReparto(reparto);
    return reparto;
}

PersonaPtr getChofer(RepartoPtr reparto)
{
    return reparto->chofer;
}
VehiculoPtr getVehiculo(RepartoPtr reparto)
{
    return reparto->vehiculo;
}
FechaPtr getFechaSalida(RepartoPtr reparto)
{
    return reparto->fechaSalida;
}
FechaPtr getFechaRetorno(RepartoPtr reparto)
{
    return reparto->fechaRetorno;
}
PilaPtr getPaquetesReparto(RepartoPtr reparto)
{
    return reparto->paquetes;
}

void setChofer(RepartoPtr reparto,PersonaPtr chofer)
{
    reparto->chofer=chofer;
}
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo)
{
    reparto->vehiculo=vehiculo;
}
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida)
{
    reparto->fechaSalida=fechaSalida;
}
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno)
{
    reparto->fechaRetorno=fechaRetorno;
}

void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete) //agrega un paquete a la pila de paquetes
{ //antes de hacer nada, debemos comprobar que haya algun dato en la pila. Sino, creamos la pila y le insertamos el dato.
    if(pilaVacia(getPaquetesReparto(reparto)))
        reparto->paquetes=crearPila();
    else
    {
        printf("\n\nERROR: PILA YA CREADA.\n\n");
        exit(1);
    }
    apilar(reparto->paquetes,(PaquetePtr)paquete);
}
PaquetePtr descargarPaquete(RepartoPtr reparto) //elimina el ultimo paquete agregado de la pila. Devuelve el paquete eliminado.
{
    PaquetePtr paquete;
    if(!pilaVacia(getPaquetesReparto(reparto)))
        paquete=(PaquetePtr)desapilar(reparto->paquetes);
    else
    {
        printf("\n\nERROR: NO SE PUEDE ELIMINAR ELEMENTOS PORQUE LA PILA YA ESTA VACIA.\n\n");
        exit(1);
    }
    return paquete;
}
int cantidadPaquetes(RepartoPtr reparto) //devuelve cantidad de paquetes que contiene el reparto
{
    return longitudPila(getPaquetesReparto(reparto));
}

void mostrarReparto(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    char *strFecha;
    traerFechaYHora(getFechaSalida(reparto),strFecha);
    printf("Fecha de Salida: %s\n",strFecha);
    traerFechaYHora(getFechaRetorno(reparto),strFecha);
    printf("Fecha de Retorno: %s\n",strFecha);

    int cantPaq=longitudPila(getPaquetesReparto(reparto));
    PaquetePtr paqueteAux;
    PaquetePtr paquetes[cantPaq];

    for(int i=0;i<cantPaq;i++)
    {
        printf("%d. ",i+1);
        paquetes[i]=(PaquetePtr)desapilar(getPaquetesReparto(reparto));
        mostrarPaquete(paquetes[i]);
    }
    for(int i=0;i<cantPaq;i++)
        apilar(getPaquetesReparto(reparto),(PaquetePtr)paquetes[cantPaq-i]);
}
void mostrarRepartoSinPaquetes(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    char *strFecha;
    traerFechaYHora(getFechaSalida(reparto),strFecha);
    printf("Fecha de Salida: %s\n",strFecha);
    traerFechaYHora(getFechaRetorno(reparto),strFecha);
    printf("Fecha de Retorno: %s\n",strFecha);
}

///---------------------------------------Funciones de validación------------------------------------------------

bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete); ///NUEVA
{
    bool match = false;

    int n=cantidadPaquetes(reparto);
    PaquetePtr paquetes[n]; ///Acá definieron una lista, lo cual era erróneo puesto que los paquetes de un reparto se almacenan en una pila.
///Además, manejar las verificaciones con un vector es más fácil.

    for(int i=0;i<n;i++)
    { ///paquetes obtiene los paquetes del reparto, almacenandolos en c/u de sus posiciones.
        paquetes[i]=descargarPaquete(reparto);

        if(paquetesIguales(paquetes[i],paquete))
            match = true;
    }
    for(int i=n;i>0;i--) ///Antes de obtener el siguiente reparto, reinsertamos los paquetes en el reparto.
        cargarPaquete(reparto,paquetes[i]); ///El for va de n hasta 0 para mantener el orden original de los paquetes como estaban en la pila.

    return match;
}
