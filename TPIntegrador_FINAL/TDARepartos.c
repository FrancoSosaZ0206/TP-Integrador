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
    reparto->paquetes=destruirPila(reparto->paquetes);

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
    mostrarFecha(getFechaSalida(reparto));
    mostrarFecha(getFechaRetorno(reparto));
    //char *strFecha;
    //traerFechaYHora(getFechaSalida(reparto),strFecha);
    //printf("Fecha de Salida: %s\n",strFecha);
    //traerFechaYHora(getFechaRetorno(reparto),strFecha);
    //printf("Fecha de Retorno: %s\n",strFecha);
    int i=0;
    while(i<longitudLista(reparto->listaPaquetes)){
        printf("Paquete nro: %d\n\n",i);
        mostrarPaquete(getDatoLista(reparto->listaPaquetes,i++));
    }

    /*int cantPaq=longitudPila(getPaquetesReparto(reparto));
    PaquetePtr paqueteAux;
    PaquetePtr paquetes[cantPaq];
    for(int i=0;i<cantPaq;i++){
        printf("%d. ",i+1);
        paquetes[i]=(PaquetePtr)desapilar(getPaquetesReparto(reparto));
        mostrarPaquete(paquetes[i]);
    }
    for(int i=0;i<cantPaq;i++)
        apilar(getPaquetesReparto(reparto),(PaquetePtr)paquetes[cantPaq-i]);*/
}

void mostrarPaquetesListaReparto(RepartoPtr reparto){
    for(int i=0;i<longitudLista(getListaPaquetesReparto(reparto));i++){
        printf("Paquete NRO: %d\n", i);
        mostrarPaquete(getDatoLista(getListaPaquetesReparto(reparto),i));
    }
}

bool buscarChoferRepartos(CentroLogisticoPtr centroLogistico, CuilPtr cuil){
    bool encontrado=false;
    for(int i=0;i<longitudLista(getRepartos(centroLogistico,true));i++)
        if(strcmp(getCuil(cuil),getCuil(getCuilPersona(getDatoLista(getChoferes(centroLogistico),i))))==0)
            encontrado=true;
    return encontrado;
}

bool buscarvehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente){
    bool encontrado=false;
    for(int i=0;i<longitudLista(getVehiculos(centroLogistico));i++)
        if(strcmp(patente,getPatente(getDatoLista(getVehiculos(centroLogistico),i)))==0)
           encontrado=true;
    return encontrado;
}
