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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));

    reparto->chofer=chofer;
    reparto->vehiculo=vehiculo;
    reparto->fechaSalida=fechaSalida;
    reparto->fechaRetorno=fechaRetorno;
    reparto->paquetes=paquetes;

    return reparto;
}

RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
{
    RepartoPtr reparto=crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    return reparto;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

RepartoPtr destruirReparto(RepartoPtr reparto)
{
//liberamos la memoria de todos los campos que hayan sido reservados dinamicamente con sus respectivas funciones. En este caso, son todos los campos.
/**Como el chofer y vehiculo se los pasamos como punteros, destruirlos acá ocasionaría que se eliminen tambien del centro logistico.
No queremos eso, así que simplemente no las destruimos.*/
    reparto->fechaSalida=destruirFecha(reparto->fechaSalida);
    reparto->fechaRetorno=destruirFecha(reparto->fechaRetorno);
    reparto->paquetes=destruirLista(reparto->paquetes,true);

    free(reparto);

    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

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

ListaPtr getPaquetesReparto(RepartoPtr reparto)
{
    return reparto->paquetes;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE OPERACIONES CON REPARTO///
///-----------------------------------------------------------------------------------------------------------///

void mostrarReparto(RepartoPtr reparto)
{
    int i = 0;
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("\nFECHA DE SALIDA: ");
    mostrarFecha(getFechaSalida(reparto));
    printf("\nFECHA DE RETORNO: ");
    mostrarFecha(getFechaRetorno(reparto));
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPaquetesReparto(reparto));
    PaquetePtr PaqueteAuxiliar;
    while(!listaVacia(ListaAuxiliar))
    {
        printf("\n %d. ", i+1);
        PaqueteAuxiliar = getCabecera(ListaAuxiliar);
        mostrarPaquete(PaqueteAuxiliar);
        ListaAuxiliar = getResto(ListaAuxiliar);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    printf("\n");
}

void mostrarRepartoSinPaquetes(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("\nFECHA DE SALIDA: ");
    mostrarFecha(getFechaSalida(reparto));
    printf("\nFECHA DE RETORNO: ");
    mostrarFecha(getFechaRetorno(reparto));
}

void mostrarPaquetesReparto(RepartoPtr reparto)
{
    int i = 0;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPaquetesReparto(reparto));
    PaquetePtr PaqueteAuxiliar;
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteAuxiliar = (PaquetePtr)getCabecera(ListaAuxiliar);
        printf("\n %d. ", i+1);
        mostrarPaquete(PaqueteAuxiliar);
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    printf("\n");
}

bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2) ///NUEVA
{
    bool condicion = personasIguales(getChofer(reparto1),getChofer(reparto2));
    condicion = condicion && vehiculosIguales(getVehiculo(reparto1),getVehiculo(reparto2));
    condicion = condicion && fechasIguales(getFechaSalida(reparto1),getFechaSalida(reparto2));
    condicion = condicion && fechasIguales(getFechaRetorno(reparto1),getFechaRetorno(reparto2));

    bool pilasIguales=false; //para los paquetes;
    int n=longitudLista(getPaquetesReparto(reparto1))-longitudLista(getPaquetesReparto(reparto2));
    if(n<0)
        n=longitudLista(getPaquetesReparto(reparto2));
    else if(n==0) //si tienen la misma cantidad de paquetes, usamos cualquiera de las dos
        n=longitudLista(getPaquetesReparto(reparto1));
    else //if(n>0)
        n=longitudLista(getPaquetesReparto(reparto1));
    PaquetePtr paqueteAux1;
    PaquetePtr paqueteAux2;
    for(int i=0;i<n;i++)
    {
        paqueteAux1=getDatoLista(getPaquetesReparto(reparto1),i);
        paqueteAux2=getDatoLista(getPaquetesReparto(reparto2),i);
        if(paquetesIguales(paqueteAux1,paqueteAux2))
            pilasIguales=true;
    }
    return condicion && pilasIguales;
}

void verificacionPaquetesCurso(ListaPtr ListaPaquetes)
{
    int EstadoPaquete = 0;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, ListaPaquetes);
    PaquetePtr PaqueteAuxiliar;
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteAuxiliar = (PaquetePtr)getCabecera(ListaAuxiliar);
        EstadoPaquete = getEstado(PaqueteAuxiliar);
        if(EstadoPaquete != 3)
        {
            ///LOS DEVOLVEMOS AL DEPOSITO
            setEstado(PaqueteAuxiliar, 0);
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        destruirLista(ListaDestruir, false);
    }
    destruirLista(ListaAuxiliar, false);
}
