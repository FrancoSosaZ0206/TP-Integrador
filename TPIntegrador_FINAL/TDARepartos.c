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

void setChofer(RepartoPtr reparto,PersonaPtr chofer)
{
    setNombre(reparto->chofer,chofer->nombre);
    setApellido(reparto->chofer,chofer->apellido);
    setDomicilio(reparto->chofer,chofer->domicilio);
    setCuilPersona(reparto->chofer,chofer->cuil);
    setEsChofer(reparto->chofer,chofer->esChofer);
}
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo)
{
    setTipoVehiculo(reparto->vehiculo,vehiculo->tipo);
    setMarca(reparto->vehiculo,vehiculo->marca);
    setModelo(reparto->vehiculo,vehiculo->modelo);
    setPatente(reparto->vehiculo,vehiculo->patente);
}
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida)
{
    setDiaJuliano(reparto->fechaSalida,fechaSalida->diaJuliano);
    setHora(reparto->fechaSalida,fechaSalida->hora);
    setMinuto(reparto->fechaSalida,fechaSalida->minuto);
}
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno)
{
    setDiaJuliano(reparto->fechaRetorno,fechaRetorno->diaJuliano);
    setHora(reparto->fechaRetorno,fechaRetorno->hora);
    setMinuto(reparto->fechaRetorno,fechaRetorno->minuto);
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
    char strFecha[18];
    traerFechaYHora(getFechaSalida(reparto),strFecha);
    printf("Fecha de Salida: %s\n",strFecha);
    traerFechaYHora(getFechaRetorno(reparto),strFecha);
    printf("Fecha de Retorno: %s\n",strFecha);

    int cantPaq=longitudPila(getPaquetesReparto(reparto));
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
    char strFecha[18];
    traerFechaYHora(getFechaSalida(reparto),strFecha);
    printf("Fecha de Salida: %s\n",strFecha);
    traerFechaYHora(getFechaRetorno(reparto),strFecha);
    printf("Fecha de Retorno: %s\n",strFecha);
}

///---------------------------------------Funciones de validación------------------------------------------------

bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete) ///NUEVA
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

RepartoPtr copiarReparto(RepartoPtr repartoOriginal) ///NUEVA
{
/// Antes de crear la copia del reparto, copiaremos todos sus campos
//Copiamos el chofer
    PersonaPtr copiaChofer = copiarPersona(getChofer(repartoOriginal));
//Copiamos el vehiculo
    VehiculoPtr copiaVehiculo = copiarVehiculo(getVehiculo(repartoOriginal));
//Copiamos las fechas de salida y retorno
    FechaPtr fechaSalidaOriginal = getFechaSalida(repartoOriginal);
    FechaPtr copiaFechaSalida = crearFechaDirect(getDiaJuliano(fechaSalidaOriginal),getHora(fechaSalidaOriginal),getMinuto(fechaSalidaOriginal));

    FechaPtr fechaRetornoOriginal = getFechaRetorno(repartoOriginal);
    FechaPtr copiaFechaRetorno = crearFechaDirect(getDiaJuliano(fechaRetornoOriginal),getHora(fechaRetornoOriginal),getMinuto(fechaRetornoOriginal));
///Copiamos la Pila de paquetes: ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PilaPtr pilaPaquetesOriginal = getPaquetesReparto(repartoOriginal);
    PilaPtr copiaPilaPaquetes = crearPila();
/// Primero, los copiamos uno por uno.
    int n=longitudPila(pilaPaquetesOriginal);
    PaquetePtr paquetesOriginales[n];
    PaquetePtr copiaPaquetes[n];
    for(int i=0;i<n;i++)
    {
        paquetesOriginales[i] = desapilar(pilaPaquetesOriginal);
        copiaPaquetes[i] = copiarPaquete(paquetesOriginales[i]);
    }
/// Luego, los volvemos a poner en sus respectivas pilas
    for(int i=n;i>0;i--)
    {
        apilar(pilaPaquetesOriginal,paquetesOriginales[i]);
        apilar(copiaPilaPaquetes,copiaPaquetes[i]);
    }
/// Finalmente, creamos y retornamos la copia del reparto, en una sola linea.
    return crearReparto(copiaChofer,copiaVehiculo,copiaFechaSalida,copiaFechaRetorno,copiaPilaPaquetes);
}
