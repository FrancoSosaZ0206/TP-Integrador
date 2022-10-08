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
#include "TDACentroLogistico.h"

RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr listaPaquetes)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));
    ListaPtr listaAux = crearLista();
    listaAux = listaPaquetes;
    reparto->chofer=chofer;
    reparto->vehiculo=vehiculo;
    reparto->fechaSalida=fechaSalida;
    reparto->fechaRetorno=fechaRetorno;
    reparto->listaPaquetes=listaAux;
    return reparto;
}
RepartoPtr destruirReparto(RepartoPtr reparto)
{ //liberamos la memoria de todos los campos que hayan sido reservados dinamicamente con sus respectivas funciones. En este caso, son todos los campos.
/**Como el chofer y vehiculo se los pasamos como punteros, destruirlos acá ocasionaría que se eliminen tambien del centro logistico.
No queremos eso, así que simplemente no las destruimos.*/
    reparto->fechaSalida=destruirFecha(reparto->fechaSalida);
    reparto->fechaRetorno=destruirFecha(reparto->fechaRetorno);
    reparto->listaPaquetes=destruirLista(reparto->listaPaquetes,true);
    free(reparto);
    return NULL;
}
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
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

ListaPtr getListaPaquetesReparto(RepartoPtr reparto){
    return reparto->listaPaquetes;
}

void setListaPaquetesReparto(RepartoPtr reparto, ListaPtr paquetes){
    reparto->listaPaquetes = paquetes;
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

int CantidadEntregas(RepartoPtr reparto) //devuelve cantidad de paquetes que contiene el reparto
{
    return longitudLista(getListaPaquetesReparto(reparto));
}
void mostrarReparto(RepartoPtr reparto){
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    mostrarFecha(getFechaSalida(reparto));
    mostrarFecha(getFechaRetorno(reparto));
    mostrarPaquetesListaReparto(reparto);
}

void mostrarPaquetesListaReparto(RepartoPtr reparto){
    for(int i=0;i<longitudLista(getListaPaquetesReparto(reparto));i++)
        printf("%d.",i),mostrarPaquete(getDatoLista(getListaPaquetesReparto(reparto),i));
}

