#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDARepartos.h"
#include "TDACentroLogistico.h"
#include "util.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados)
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);
    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaPersonas=listaPersonas;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartosAbiertos=listaRepartosAbiertos;
    centroLogistico->listaRepartosCerrados=listaRepartosCerrados;
    return centroLogistico;
}

CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro logístico con un nombre y listas vacías.
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);
    centroLogistico->listaPaquetes=crearLista();
    centroLogistico->listaPersonas=crearLista();
    centroLogistico->listaVehiculos=crearLista();
    centroLogistico->listaRepartosAbiertos=crearLista();
    centroLogistico->listaRepartosCerrados=crearLista();
    return centroLogistico;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    destruirStringDinamico(centroLogistico->nombre);
    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);
    centroLogistico->listaRepartosCerrados=destruirLista(centroLogistico->listaRepartosCerrados,true);
    free(centroLogistico);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->nombre;
}

ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaPaquetes;
}

ListaPtr getPersonas(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaPersonas;
}

ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaVehiculos;
}

ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		return centroLogistico->listaRepartosAbiertos;
	else
		return centroLogistico->listaRepartosCerrados;
}

ListaPtr getRepartosAbiertos(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaRepartosAbiertos;
}

ListaPtr getRepartosCerrados(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaRepartosCerrados;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre)
{
    strcpy(centroLogistico->nombre,nombre);
}

void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes)
{
    centroLogistico->listaPaquetes=listaPaquetes;
}

void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas)
{
    centroLogistico->listaPersonas=listaPersonas;
}

void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos)
{
    centroLogistico->listaVehiculos=listaVehiculos;
}

void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		centroLogistico->listaRepartosAbiertos = repartos;
	else
		centroLogistico->listaRepartosCerrados = repartos;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE MOSTRADO POR PANTALLA///
///-----------------------------------------------------------------------------------------------------------///

void mostrarPaquetes(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));
    int i=0;
    printf("\nLISTA DE PAQUETES: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);
        mostrarPaquete((PaquetePtr)getCabecera(listaAux));
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    listaAux = destruirLista(listaAux,false);
    printf("\n");
}

void mostrarPersonas(CentroLogisticoPtr centroLogistico,int modo)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    int i=0;
    switch(modo)
    {
    case 1:
        printf("\nLISTA DE CHOFERES: \n\n");
        break;
    case 2:
        printf("\nLISTA DE CLIENTES: \n\n");
        break;
    case 3:
        printf("\nLISTA DE PERSONAS: \n\n");
        break;
    }
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        switch(modo)
        {
        case 1: //Filtra por chofer
            if(getEsChofer(personaAux))
            {
                printf("%d. ",i+1);
                mostrarPersona(personaAux);
            }
            break;
        case 2: //Filtra por cliente
            if(!getEsChofer(personaAux))
            {
                printf("%d. ",i+1);
                mostrarPersona(personaAux);
            }
            break;
        case 3: //Sin filtro - Muestra todas las personas
            printf("%d. ",i+1);
            mostrarPersona(personaAux);
            break;
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarVehiculos(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    int i=0;
    printf("\nLISTA DE VEHICULOS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);
        mostrarVehiculo((VehiculoPtr)getCabecera(listaAux));
        listaAux=getResto(listaAux);
        i++;
    }
    ListaPtr ListaDestruir = listaAux;
    listaAux = getResto(listaAux);
    ListaDestruir = destruirLista(ListaDestruir, false);
    i++;
    printf("\n");
}

void mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    int i=0;
    VehiculoPtr vehiculoAux;
    printf("\nLISTA DE VEHICULOS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("\n NUMERO %d. \n",i+1);
        vehiculoAux=(VehiculoPtr)getCabecera(listaAux);
        if(!buscarVehiculo(centroLogistico,getPatente(vehiculoAux)))
        {
            mostrarVehiculo(vehiculoAux);
        }
        listaAux=getResto(listaAux);
        i++;
    }
    ListaPtr ListaDestruir = listaAux;
    listaAux = getResto(listaAux);
    ListaDestruir = destruirLista(ListaDestruir, false);
    i++;
    printf("\n");
}

void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    listaAux=getPersonas(centroLogistico);
    PersonaPtr personaAux;
    CuilPtr cuilPersona;
    int i=0;
    while(!listaVacia(listaAux))
    {
        personaAux=(PersonaPtr)getCabecera(listaAux);
        cuilPersona=getCuilPersona(personaAux);
        if(getEsChofer(personaAux))
        {
            if(!buscarChoferRepartos(centroLogistico,getCuil(cuilPersona)))
            {
                printf("\n%d.",i+1);
                mostrarPersona(personaAux);
            }
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n\n");
}

void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    listaAux=getPaquetes(centroLogistico);
    int i=0;
    PaquetePtr paqueteAux;
    while(!listaVacia(listaAux))
    {
        paqueteAux=(PaquetePtr)getCabecera(listaAux);
        if(!buscarPaquete(centroLogistico,getID(paqueteAux)))
        {
            limpiarBufferTeclado();
            printf("\n %d. ",i+1);
            mostrarPaquete(paqueteAux);
        }
        listaAux=getResto(listaAux);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n\n");
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    ListaPtr listaAux=crearLista();
	if(esRepartoAbierto)
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
	else
        printf("\nLISTA DE REPARTOS CERRADOS (*): \n\n");

    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

    int i=0;
    while(!listaVacia(listaAux))
    {
        printf("\n\n%d. ",i+1);
        RepartoPtr repartoAux = (RepartoPtr) getCabecera(listaAux);
        mostrarRepartoSinPaquetes(repartoAux);
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void filtrarPorFechaSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,FechaPtr fechaSalida)
{
    ///ordenarRepartos(centroLogistico,esRepartoAbierto,1);
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

    printf("\n LISTA DE REPARTOS ");
    if(esRepartoAbierto)
        printf("ABIERTOS ");
    else
        printf("CERRADOS ");
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux=getCabecera(listaAux);
        int diaDeReparto[3];
        calcularDiferenciaFechas(getFechaSalida(repartoAux),fechaSalida,diaDeReparto); /**getDia(getFechaSalida((RepartoPtr)getCabecera(listaAux))*/
        bool condicion=diaDeReparto[0]==0;
        ///CONDICION: "si SOLAMENTE el día JULIANO del reparto (dia, mes y año) coincide con el de la fecha recibida..."
        if(condicion)
            mostrarRepartoSinPaquetes(repartoAux);
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

///filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));
    switch(estado)
    {
    case 0:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'EN DEPOSITO': \n\n");
        break;
    case 1:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'EN CURSO': \n\n");
        break;
    case 2:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'RETIRADO': \n\n");
        break;
    case 3:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'ENTREGADO': \n\n");
        break;
    case 4:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'DEMORADO': \n\n");
        break;
    case 5:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'SUSPENDIDO': \n\n");
        break;
    default:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'ERROR': \n\n");
        break;
    }

    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);
        if(getEstado(paqueteAux)==estado)
            mostrarPaquete(paqueteAux);
        listaAux=getResto(listaAux);
    }
    ListaPtr ListaDestruir = listaAux;
    listaAux = getResto(listaAux);
    ListaDestruir = destruirLista(ListaDestruir, false);
    printf("\n");
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE BUSQUEDA DE DATOS EN LAS LISTAS///
///-----------------------------------------------------------------------------------------------------------///


bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);

        if(getID(paqueteAux)==ID)
        {
            match=true;
            mostrarPaquete(paqueteAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.
    return match;
}

bool buscarPersona(CentroLogisticoPtr centroLogistico,char* cuilBuscar,bool esChofer)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(strcmp(getCuil(getCuilPersona(personaAux)),cuilBuscar)==0 && getEsChofer(personaAux)==esChofer)
        {
            match=true;
            mostrarPersona(personaAux); //mostramos solo si el cuil y esChofer coinciden
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}

bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    while(!listaVacia(listaAux))
    {
        VehiculoPtr vehiculoAux=(VehiculoPtr)getCabecera(listaAux);
        if(strcmp(getPatente(vehiculoAux),patente)==0)
        {
            match=true;
            mostrarVehiculo(vehiculoAux); //mostramos si las patentes coinciden, es decir, si strcmp da cero.
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}

bool buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        VehiculoPtr vehiculoAux=getVehiculo((RepartoPtr)getCabecera(listaAux));
        if(strcmp(getPatente(vehiculoAux),patente)==0)
            match=true;
        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.
    return match;
}

bool buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuilBuscar)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=getChofer((RepartoPtr)getCabecera(listaAux));
        if(strcmp(getCuil(getCuilPersona(personaAux)),cuilBuscar)==0 && getEsChofer(personaAux)==true)
            match=true;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.
    return match;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE AGREGADO A LAS LISTAS///
///-----------------------------------------------------------------------------------------------------------///


void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete)
{
    agregarDatoLista(centroLogistico->listaPaquetes,(PaquetePtr)paquete);
}

void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona)
{
    agregarDatoLista(centroLogistico->listaPersonas,(PersonaPtr)persona);
}

void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo)
{
    agregarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo);
}

void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		agregarDatoLista(getRepartos(centroLogistico,true), reparto);
	else
		agregarDatoLista(getRepartos(centroLogistico,false), reparto);
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE INSERCION DE LAS LISTAS///
///-----------------------------------------------------------------------------------------------------------///

bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion)
{
    return insertarDatoLista(centroLogistico->listaPaquetes,(PaquetePtr)paquete,posicion);
}

bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion)
{
    return insertarDatoLista(centroLogistico->listaPersonas,(PersonaPtr)persona,posicion);
}

bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion)
{
    return insertarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo,posicion);
}

///SOLO PARA REPARTOS ABIERTOS
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion)
{
    return insertarDatoLista(centroLogistico->listaRepartosAbiertos,(RepartoPtr)reparto,posicion);
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE ELIMINACION DE LAS LISTAS///
///-----------------------------------------------------------------------------------------------------------///

PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (PaquetePtr)removerDeLista(centroLogistico->listaPaquetes,posicion);
}

PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (PersonaPtr)removerDeLista(centroLogistico->listaPersonas,posicion);
}

VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (VehiculoPtr)removerDeLista(centroLogistico->listaVehiculos,posicion);
}

RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion,bool esRepartoAbierto)
{
    if(esRepartoAbierto)
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosAbiertos,posicion);
    else
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosCerrados,posicion);
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE VALIDACION///
///-----------------------------------------------------------------------------------------------------------///

bool esPaqueteExistente(CentroLogisticoPtr centroLogistico, PaquetePtr paquete)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
        if(paquetesIguales(paqueteAux,paquete))
            match=true;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return match;
}

///devuelve true si la persona que le ingresamos tiene el mismo cuil que una de las personas, false si no
bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(personasIguales(personaAux,persona))
            match=true;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return match;
}

bool esVehiculoExistente(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculo)
{
    bool match=false;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));

    while(!listaVacia(listaAux))
    {
        VehiculoPtr vehculoAux = (VehiculoPtr)getCabecera(listaAux);
        if(vehiculosIguales(vehculoAux,vehiculo))
            match=true;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    return match;
}

bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto,bool esRepartoAbierto)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux=(RepartoPtr)getCabecera(listaAux);
        bool condicion = fechasIguales(getFechaSalida(repartoAux),getFechaSalida(reparto));
        condicion = condicion && personasIguales(getChofer(repartoAux),getChofer(reparto));
///Un chofer puede tener varios repartos asignados, pero no en el mismo día. Por eso,
///Condición: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
        if(condicion)
            match=true;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    return match;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE ORDENAMIENTO///
///-----------------------------------------------------------------------------------------------------------///

void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modoOrdenamiento, int modoMostrado)
{
    int n=longitudLista(getPersonas(centroLogistico));
    PersonaPtr personas[n];
    PersonaPtr personaAux;
    bool condicion;
    ///Primero, vaciamos la lista en el vector
    for(int i=0;i<n;i++)
    {
        personas[i]=getDatoLista(getPersonas(centroLogistico),i);
    }
    ///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            switch(modoOrdenamiento)
            {
            case 1:
                condicion = strcmp(getNombre(personas[i]),getNombre(personas[j])) > 0;
                break;
                ///condición: "Si el apellido de la persona en j va después del de la persona en j+1..."
            case 2:
                condicion = strcmp(getApellido(personas[i]),getApellido(personas[j])) > 0;
                ///condición: "Si el apellido de la persona en j va después del de la persona en j+1..."
                break;
            case 3:
                condicion = strcmp(getCuil(getCuilPersona(personas[i])),getCuil(getCuilPersona(personas[j]))) > 0;
                ///condición: "Si el Cuil de la persona en j van después de los de la persona en j+1..."
                break;
            case 4:
                break;
            }
            if(condicion)
            {
                ///Hago un swap
                personaAux=personas[i];
                personas[i]=personas[j];
                personas[j]=personaAux;
            }
        }
    }
    ///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
    {
        switch(modoMostrado)
        {
        case 1:
            if(getEsChofer(personas[i]))
            {
                printf("\n%d. ",i+1);
                mostrarPersona(personas[i]);
            }
            break;
        case 2:
            if(!getEsChofer(personas[i]))
            {
                printf("\n%d. ",i+1);
                mostrarPersona(personas[i]);
            }
            break;
        case 3:
            printf("\n%d. ",i+1);
            mostrarPersona(personas[i]);
            break;
        }
    }
    printf("\n\n");
    system("pause");
}

void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getVehiculos(centroLogistico));
    VehiculoPtr vehiculos[n];
    VehiculoPtr vehiculoAux;
    bool condicion=false;
    ///Primero, vaciamos la lista en el vector
    for(int i=0;i<n;i++)
    {
        vehiculos[i]=getDatoLista(getVehiculos(centroLogistico),i);
    }
    ///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            switch(modo)
            {
            case 1:
                condicion = strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[j])) > 0;
                ///condición: "Si la marca de vehiculos[j] es posterior a la de vehiculos[j+1]..."
                break;
            case 2:
                condicion = condicion && strcmp(getModelo(vehiculos[i]),getModelo(vehiculos[j])) > 0;
                ///condición: "Si la marca Y modelo de vehiculos[j] son posteriores a los de vehiculos[j+1]..."
                break;
            case 3:
                condicion = getTipoVehiculo(vehiculos[i]) > getTipoVehiculo(vehiculos[j]);
                ///condición: "Si el tipo, la marca Y el modelo de vehiculos[j] son posteriores a los de vehiculos[j+1]..."
                break;
            case 4:
                break;
            }
            if(condicion)
            {
                ///Hago un swap
                vehiculoAux=vehiculos[i];
                vehiculos[i]=vehiculos[j];
                vehiculos[j]=vehiculoAux;
            }
        }
    }
    ///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
    {
        printf("\n%d. ", i+1);
        mostrarVehiculo(vehiculos[i]);
    }
    system("pause");
}

void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getPaquetes(centroLogistico));
    PaquetePtr paquetes[n];
    PaquetePtr paqueteAux;
    bool condicion;
    int diferenciaFechas[3];
    ///Primero, vaciamos la lista en el vector
    for(int i=0;i<n;i++)
    {
        paquetes[i]=getDatoLista(getPaquetes(centroLogistico),i);
    }
    ///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            switch(modo)
            {
            case 1:
                condicion = getID(paquetes[i]) > getID(paquetes[j]);
                ///condicion de la bandera: "Si el ID de paquetes[j] es mayor al de paquetes[j+1]..."
                break;
            case 2:
                calcularDiferenciaFechas(getFechaEntrega(paquetes[j]),getFechaEntrega(paquetes[j]),diferenciaFechas);
                condicion = diferenciaFechas[0]>=0 || diferenciaFechas[1]>=0 || diferenciaFechas[2]>0;
                ///condicion de la bandera: "Si la fecha de entrega de paquetes[j] es mayor a la de paquetes[j+1]..."
                break;
            case 3:
                condicion = getEstado(paquetes[i]) > getEstado(paquetes[j]);
                break;
            case 4:
                break;
                ///NO REQUIERE CLÁUSULA "DEFAULT"
            }
            if(condicion)
            {
                ///Hago un swap
                paqueteAux=paquetes[i];
                paquetes[i]=paquetes[j];
                paquetes[j]=paqueteAux;
            }
        }
    }
    ///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0;i<n;i++)
    {
        printf("\n %d. ", i+1);
        mostrarPaquete(paquetes[i]);
    }
    system("pause");
}

void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo)
{
    limpiarBufferTeclado();
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    RepartoPtr repartos[n];
    RepartoPtr repartoAux;
    bool condicion=false;
    int diferenciaFechaSalida[3];
    int diferenciaFechaRetorno[3];
    int diferenciaNombres=0;
    int diferenciaApellidos=0;

    ListaPtr listaAuxiliar=getRepartos(centroLogistico,esRepartoAbierto);
    ///Primero, vaciamos la lista en el vector
    for(int i=0;i<n;i++)
    {
        repartos[i]=getDatoLista(listaAuxiliar,i);
    }
    ///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            switch(modo)
            {
            case 1:
                calcularDiferenciaFechas(getFechaSalida(repartos[i]),getFechaSalida(repartos[j]),diferenciaFechaSalida);
                condicion = (diferenciaFechaSalida[0]>=0 && (diferenciaFechaSalida[1]>=0 || diferenciaFechaSalida[2]>0));
                ///condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida de reparto[j] es posterior a la de repartos[j+1]..."
                break;
            case 2:
                calcularDiferenciaFechas(getFechaRetorno(repartos[i]),getFechaRetorno(repartos[j]),diferenciaFechaRetorno);
                condicion = diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0;
                ///condicion: "Ya sea en dias, horas o minutos, si fechaDeRetorno de reparto[j] es posterior a la de repartos[j+1]..."
                break;
            case 3:
                calcularDiferenciaFechas(getFechaSalida(repartos[i]),getFechaSalida(repartos[j]),diferenciaFechaSalida);
                condicion = (diferenciaFechaSalida[0]>0 && (diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0)); //agrego la condicion de fechaSalida
                calcularDiferenciaFechas(getFechaRetorno(repartos[i]),getFechaRetorno(repartos[j]),diferenciaFechaRetorno);
                condicion = condicion && (diferenciaFechaRetorno[0]>0 && (diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0)); //sumo la condicion de fechaRetorno
                ///condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida *Y* fechaDeRetorno de reparto[j] son posteriores a las de repartos[j+1]..."
                break;
            case 4:
                condicion = strcmp(getNombre(getChofer(repartos[i])),getNombre(getChofer(repartos[j]))) > 0;
                ///condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
                break;
            case 5:
                condicion = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[j]))) > 0;
                ///condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
                break;
            case 6:
                diferenciaApellidos = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[j])));
                condicion = diferenciaApellidos >= 0;
                diferenciaNombres = strcmp(getNombre(getChofer(repartos[i])),getNombre(getChofer(repartos[j])));
                condicion = condicion && diferenciaNombres > 0;
                ///condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van después de los del chofer del reparto en j+1..."
                break;
            }
            if(condicion)
            {
                ///Hago un swap
                repartoAux=repartos[i];
                repartos[i]=repartos[j];
                repartos[j]=repartoAux;
            }
        }
    }
    ///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    printf("\n\n\n\t LISTA DE REPARTOS ORDENADA \n\n");
    for(int i=0; i<n; i++)
    {
        printf("\n\n %d. ", i+1);
        mostrarRepartoSinPaquetes(repartos[i]);
    }
    system("pause");
}
