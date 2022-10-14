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

RepartoPtr crearRepartoNuevo(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));
    reparto->chofer=chofer;
    reparto->vehiculo=vehiculo;
    reparto->fechaSalida=fechaSalida;
    reparto->fechaRetorno=fechaRetorno;
    reparto->listaPaquetes=paquetes;
    return reparto;
}

RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes)
{
    RepartoPtr reparto=crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
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
ListaPtr getListaPaquetesReparto(RepartoPtr reparto)
{
    return reparto->listaPaquetes;
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
    printf("FECHA DE SALIDA: \n");
    mostrarFecha(getFechaSalida(reparto));
    printf("FECHA DE RETORNO: \n");
    mostrarFecha(getFechaRetorno(reparto));
    int cant=0;
    PaquetePtr paquetes[20];
    PilaPtr pila=crearPila();
    pila=getPaquetesReparto(reparto);
    while(!pilaVacia(pila))
    {
        paquetes[cant]=(PaquetePtr)desapilar(pila);
        mostrarPaquete(paquetes[cant]);
        cant++;
    }
    for(int i=cant;i>0;i--)
    {
        apilar(pila,(PaquetePtr)paquetes[i]);
    }
}

void mostrarRepartoNuevo(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("FECHA DE SALIDA: \n");
    mostrarFecha(getFechaSalida(reparto));
    printf("FECHA DE RETORNO: \n");
    mostrarFecha(getFechaRetorno(reparto));
}

void mostrarRepartoSinPaquetes(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("FECHA DE SALIDA: \n");
    mostrarFecha(getFechaSalida(reparto));
    printf("FECHA DE RETORNO: \n");
    mostrarFecha(getFechaRetorno(reparto));
}

///---------------------------------------Funciones de validación------------------------------------------------
///NUEVA
bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete)
{
    bool match = false;
    int n=cantidadPaquetes(reparto);
    PaquetePtr paquetes[n];
    ///Acá definieron una lista, lo cual era erróneo puesto que los paquetes de un reparto se almacenan en una pila.
    ///Además, manejar las verificaciones con un vector es más fácil.
    for(int i=0;i<n;i++)
    {
        ///paquetes obtiene los paquetes del reparto, almacenandolos en c/u de sus posiciones.
        paquetes[i]=descargarPaquete(reparto);
        if(paquetesIguales(paquetes[i],paquete))
            match = true;
    }
    ///Antes de obtener el siguiente reparto, reinsertamos los paquetes en el reparto
    for(int i=n;i>0;i--)
        cargarPaquete(reparto,paquetes[i]);
    ///El for va de n hasta 0 para mantener el orden original de los paquetes como estaban en la pila.
    return match;
}

bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2) ///NUEVA
{
    PilaPtr pilaAux1=crearPila();
    PilaPtr pilaAux2=crearPila();

    bool condicion = personasIguales(getChofer(reparto1),getChofer(reparto2));
    condicion = condicion && vehiculosIguales(getVehiculo(reparto1),getVehiculo(reparto2));
    condicion = condicion && fechasIguales(getFechaSalida(reparto1),getFechaSalida(reparto2));
    condicion = condicion && fechasIguales(getFechaRetorno(reparto1),getFechaRetorno(reparto2));

    bool pilasIguales=false; //para los paquetes;
    int n=cantidadPaquetes(reparto1)-cantidadPaquetes(reparto2);
    if(n<0)
        n=cantidadPaquetes(reparto2);
    else if(n==0) //si tienen la misma cantidad de paquetes, usamos cualquiera de las dos
        n=cantidadPaquetes(reparto1);
    else //if(n>0)
        n=cantidadPaquetes(reparto1);
    PaquetePtr paqueteAux1;
    PaquetePtr paqueteAux2;
    for(int i=0;i<n;i++)
    {
        paqueteAux1=descargarPaquete(reparto1);
        paqueteAux2=descargarPaquete(reparto2);
        if(paquetesIguales(paqueteAux1,paqueteAux2))
            pilasIguales=true;
    }
    for(int i=0;i<n;i++)
    {
        cargarPaquete(reparto1,(PaquetePtr)desapilar(pilaAux1));
        cargarPaquete(reparto2,(PaquetePtr)desapilar(pilaAux2));
    } ///Las pilas no las destruimos.

    return condicion && pilasIguales;
}
