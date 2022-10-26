#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
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


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre)
{
    char* nombreDinamico = (char*)obtenerMemoria(sizeof(char)*strlen(nombre)+1);
    strcpy(nombreDinamico, nombre);
    centroLogistico->nombre = nombreDinamico;
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
    int i=1;
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
                printf("%d. ",i);
                mostrarPersona(personaAux);
            }
            break;
        case 2: //Filtra por cliente
            if(!getEsChofer(personaAux))
            {
                printf("%d. ",i);
                mostrarPersona(personaAux);
            }
            break;
        case 3: //Sin filtro - Muestra todas las personas
            printf("%d. ",i);
            mostrarPersona(personaAux);
            break;
        }
        i++;
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
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
        printf("\n\n");
        listaAux=getResto(listaAux);
        i++;
    }
    ListaPtr ListaDestruir = listaAux;
    listaAux = getResto(listaAux);
    ListaDestruir = destruirLista(ListaDestruir, false);
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
        vehiculoAux=(VehiculoPtr)getCabecera(listaAux);
        if(!buscarVehiculoRepartos(centroLogistico,getPatente(vehiculoAux)))
        {
            printf("\n NUMERO %d. \n",i+1);
            mostrarVehiculo(vehiculoAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));
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
                if(!getRepartoDiario(personaAux))
                {
                    printf("\n\n NUMERO %d. \n\n", i+1);
                    mostrarPersona(personaAux);
                }
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
    agregarLista(listaAux, getPaquetes(centroLogistico));
    int i=0;
    PaquetePtr paqueteAux;
    while(!listaVacia(listaAux))
    {
        paqueteAux=(PaquetePtr)getCabecera(listaAux);
        if(getEstado(paqueteAux) == 0)
        {
            printf("\n NUMERO %d. \n",i+1);
            mostrarPaquete(paqueteAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n\n");
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    ListaPtr listaAux=crearLista();
	if(esRepartoAbierto)
    {
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
    }
	else
    {
        printf("\nLISTA DE REPARTOS CERRADOS (*): \n\n");
    }
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
    {
        printf("ABIERTOS ");
    }
    else
    {
        printf("CERRADOS ");
    }
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux=getCabecera(listaAux);
        int diaDeReparto[3];
        calcularDiferenciaFechas(getFechaSalida(repartoAux),fechaSalida,diaDeReparto); /**getDia(getFechaSalida((RepartoPtr)getCabecera(listaAux))*/
        bool condicion=diaDeReparto[0]==0;
        ///CONDICION: "si SOLAMENTE el día JULIANO del reparto (dia, mes y año) coincide con el de la fecha recibida..."
        if(condicion)
        {
            mostrarRepartoSinPaquetes(repartoAux);
        }
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
        {
            mostrarPaquete(paqueteAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    printf("\n");
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE VERIFICACION DE DATOS EN LAS LISTAS///
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
    {
        //esto lo pongo acá para que no pase si no hay un match.
        printf("\n");
    }
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
            //mostramos solo si el cuil y esChofer coinciden
            mostrarPersona(personaAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
    {
        //esto lo pongo acá para que no pase si no hay un match.
        printf("\n");
    }
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
            printf("\n");
            //mostramos si las patentes coinciden, es decir, si strcmp da cero.
            mostrarVehiculo(vehiculoAux);
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
    {
        //esto lo pongo acá para que no pase si no hay un match.
        printf("\n");
    }
    return match;
}

bool buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente)
{
    bool match=false;
    VehiculoPtr vehiculoDevolver;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        vehiculoDevolver=getVehiculo((RepartoPtr)getCabecera(listaAux));
        if(strcmp(getPatente(vehiculoDevolver),patente)==0)
        {
            match=true;
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return match;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DEVOLUCION DE DATOS EN LAS LISTAS///
///-----------------------------------------------------------------------------------------------------------///

RepartoPtr devolverRepartoChofer(CentroLogisticoPtr centroLogistico, char* cuil)
{
    bool match=false;
    RepartoPtr repartoDevolver;
    RepartoPtr repartoAux;
    PersonaPtr personaInvestigar;
    CuilPtr cuilInvestigar;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        repartoAux=(RepartoPtr)getCabecera(listaAux);
        personaInvestigar=getChofer(repartoAux);
        cuilInvestigar=getCuilPersona(personaInvestigar);
        if(strcmp(getCuil(cuilInvestigar),cuil)==0)
        {
            match=true;
            repartoDevolver=repartoAux;
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
    {
        return repartoDevolver;
    }
    else
    {
        return NULL;
    }
}

RepartoPtr devolverRepartoVehiculo(CentroLogisticoPtr centroLogistico, char* patente)
{
    bool match=false;
    VehiculoPtr vehiculoInvestigar;
    RepartoPtr repartoDevolver;
    RepartoPtr repartoActual;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        repartoActual=(RepartoPtr)getCabecera(listaAux);
        vehiculoInvestigar=getVehiculo(repartoActual);
        if(strcmp(getPatente(vehiculoInvestigar),patente)==0)
        {
            match=true;
            repartoDevolver=repartoActual;
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
    {
        return repartoDevolver;
    }
    else
    {
        return NULL;
    }
}

RepartoPtr devolverRepartoFechaSalida(CentroLogisticoPtr centroLogistico, FechaPtr fechaBuscar)
{
    int hora = 0;
    int minutos = 0;
    int cantidadCorrectas = 0;
    int horaBuscar = 0;
    int minutosBuscar = 0;
    ///int posicionEncontrado=0
    bool encontrado=false;
    RepartoPtr repartoDevolver;
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaRepartos = getRepartos(centroLogistico, true);
    agregarLista(ListaAuxiliar, ListaRepartos);
    FechaPtr fechaActual;
    RepartoPtr repartoActual;
    while(!listaVacia(ListaAuxiliar))
    {
        cantidadCorrectas = 0;
        repartoActual = (RepartoPtr)getCabecera(ListaAuxiliar);
        fechaActual = getFechaSalida(repartoActual);
        horaBuscar = getHora(fechaBuscar);
        minutosBuscar = getMinuto(fechaBuscar);
        hora = getHora(fechaActual);
        minutos = getMinuto(fechaActual);
        if(getDia(fechaActual) == getDia(fechaBuscar))
        {
            cantidadCorrectas++;
        }
        if(getMes(fechaActual) == getMes(fechaBuscar))
        {
            cantidadCorrectas++;
        }
        if(getAnio(fechaActual) == getAnio(fechaBuscar))
        {
            cantidadCorrectas++;
        }
        if(hora == horaBuscar)
        {
            cantidadCorrectas++;
        }
        if(minutos == minutosBuscar)
        {
            cantidadCorrectas++;
        }
        if(cantidadCorrectas == 5)
        {
            encontrado = true;
            repartoDevolver=repartoActual;
            ///posicionEncontrado = i;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    if(encontrado)
    {
        return repartoDevolver;
    }
    else
    {
        return NULL;
    }
}

RepartoPtr devolverRepartoFechaRetorno(CentroLogisticoPtr centroLogistico, FechaPtr fechaBuscar)
{
    int diaJuliano = 0;
    int hora = 0;
    int minutos = 0;
    int diaJulianoBuscar=0;
    int i = 0;
    int cantidadCorrectas = 0;
    int horaBuscar = 0;
    int minutosBuscar = 0;
    ///int posicionEncontrado=0
    bool encontrado=false;
    RepartoPtr repartoDevolver;
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaRepartos = getRepartos(centroLogistico, true);
    agregarLista(ListaAuxiliar, ListaRepartos);
    FechaPtr fechaActual;
    RepartoPtr repartoActual;
    while(!listaVacia(ListaAuxiliar))
    {
        cantidadCorrectas = 0;
        repartoActual = (RepartoPtr)getCabecera(ListaAuxiliar);
        fechaActual = getFechaRetorno(repartoActual);
        diaJulianoBuscar = getDiaJuliano(fechaBuscar);
        horaBuscar = getHora(fechaBuscar);
        minutosBuscar = getMinuto(fechaBuscar);
        diaJuliano = getDiaJuliano(fechaActual);
        hora = getHora(fechaActual);
        minutos = getMinuto(fechaActual);
        if(diaJuliano == diaJulianoBuscar)
        {
            cantidadCorrectas++;
        }
        if(hora == horaBuscar)
        {
            cantidadCorrectas++;
        }
        if(minutos == minutosBuscar)
        {
            cantidadCorrectas++;
        }
        if(cantidadCorrectas == 3)
        {
            encontrado = true;
            repartoDevolver=repartoActual;
            ///posicionEncontrado = i;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    if(encontrado)
    {
        return repartoDevolver;
    }
    else
    {
        return NULL;
    }
}

RepartoPtr devolverRepartoPaquete(CentroLogisticoPtr centroLogistico, int ID)
{
    ListaPtr listaAuxiliar2;
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaPaquetes = getRepartos(centroLogistico,true);
    agregarLista(ListaAuxiliar, ListaPaquetes);
    RepartoPtr repartoActual;
    RepartoPtr repartoDevolver;
    PaquetePtr PaqueteActual;
    int ID_paquete = 0;
    bool encontrado = false;
    while(!listaVacia(ListaAuxiliar))
    {
        repartoActual = (RepartoPtr)getCabecera(ListaAuxiliar);
        listaAuxiliar2=crearLista();
        agregarLista(listaAuxiliar2, getPaquetesReparto(repartoActual));
        while(!listaVacia(listaAuxiliar2))
        {
            PaqueteActual = (PaquetePtr)getCabecera(listaAuxiliar2);
            ID_paquete = getID(PaqueteActual);
            if(ID_paquete == ID)
            {
                encontrado = true;
                repartoDevolver = repartoActual;
            }
            ListaPtr ListaDestruir1 = listaAuxiliar2;
            listaAuxiliar2 = getResto(listaAuxiliar2);
            ListaDestruir1 = destruirLista(ListaDestruir1, false);
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        listaAuxiliar2 = destruirLista(listaAuxiliar2, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    if(encontrado)
    {
        return repartoDevolver;
    }
    else
    {
        return NULL;
    }
}

PersonaPtr devolverPersona(CentroLogisticoPtr centroLogistico, char* cuilBuscar)
{
    ListaPtr ListaAux = crearLista();
    agregarLista( ListaAux, getPersonas(centroLogistico) );
    PersonaPtr PersonaActual;
    PersonaPtr PersonaDevolver;
    CuilPtr CuilActual;
    int encontrado = 0;
    bool match = false;
    while(!listaVacia(ListaAux))
    {
        PersonaActual = (PersonaPtr)getCabecera(ListaAux);
        CuilActual = getCuilPersona(PersonaActual);
        encontrado = strcmp( getCuil(CuilActual), cuilBuscar );
        if(encontrado == 0)
        {
            PersonaDevolver = PersonaActual;
            match = true;
        }
        ListaPtr ListaDestruir = ListaAux;
        ListaAux = getResto(ListaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAux = destruirLista(ListaAux, false);
    if(match)
    {
        return PersonaDevolver;
    }
    else
    {
        return NULL;
    }
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE VERIFICACION DE DATOS EN LOS REPARTOS///
///-----------------------------------------------------------------------------------------------------------///

bool buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuilBuscar)
{
    bool match = false;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=getChofer((RepartoPtr)getCabecera(listaAux));
        if(strcmp(getCuil(getCuilPersona(personaAux)),cuilBuscar)==0 && getEsChofer(personaAux)==true)
        {
            match=true;
        }
        ListaPtr ListaDestruir = listaAux;
        listaAux = getResto(listaAux);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    if(match)
    {
        //esto lo pongo acá para que no pase si no hay un match.
        printf("\n");
    }
    return match;
}

bool buscarFechaSalidaRepartos(CentroLogisticoPtr centroLogistico, FechaPtr fechaBuscar)
{
    int diaJuliano = 0;
    int hora = 0;
    int minutos = 0;
    int diaJulianoBuscar=0;
    int cantidadCorrectas = 0;
    int horaBuscar = 0;
    int minutosBuscar = 0;
    ///int posicionEncontrado=0
    bool encontrado=false;
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaRepartos = getRepartos(centroLogistico, true);
    agregarLista(ListaAuxiliar, ListaRepartos);
    FechaPtr fechaActual;
    RepartoPtr repartoActual;
    while(!listaVacia(ListaAuxiliar))
    {
        cantidadCorrectas = 0;
        repartoActual = (RepartoPtr)getCabecera(ListaAuxiliar);
        fechaActual = getFechaSalida(repartoActual);
        diaJulianoBuscar = getDiaJuliano(fechaBuscar);
        horaBuscar = getHora(fechaBuscar);
        minutosBuscar = getMinuto(fechaBuscar);
        diaJuliano = getDiaJuliano(fechaActual);
        hora = getHora(fechaActual);
        minutos = getMinuto(fechaActual);
        if(diaJuliano == diaJulianoBuscar)
        {
            cantidadCorrectas++;
        }
        if(hora == horaBuscar)
        {
            cantidadCorrectas++;
        }
        if(minutos == minutosBuscar)
        {
            cantidadCorrectas++;
        }
        if(cantidadCorrectas == 5)
        {
            encontrado = true;
            ///posicionEncontrado = i;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return encontrado;
}

bool buscarFechaRetornoRepartos(CentroLogisticoPtr centroLogistico, FechaPtr fechaBuscar)
{
    int diaJuliano = 0;
    int hora = 0;
    int minutos = 0;
    int diaJulianoBuscar=0;
    int i = 0;
    int cantidadCorrectas = 0;
    int horaBuscar = 0;
    int minutosBuscar = 0;
    ///int posicionEncontrado=0
    bool encontrado=false;
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaRepartos = getRepartos(centroLogistico, true);
    agregarLista(ListaAuxiliar, ListaRepartos);
    FechaPtr fechaActual;
    RepartoPtr repartoActual;
    while(!listaVacia(ListaAuxiliar))
    {
        cantidadCorrectas = 0;
        repartoActual = (RepartoPtr)getCabecera(ListaAuxiliar);
        fechaActual = getFechaRetorno(repartoActual);
        diaJulianoBuscar = getDiaJuliano(fechaBuscar);
        horaBuscar = getHora(fechaBuscar);
        minutosBuscar = getMinuto(fechaBuscar);
        diaJuliano = getDiaJuliano(fechaActual);
        hora = getHora(fechaActual);
        minutos = getMinuto(fechaActual);
        if(diaJuliano == diaJulianoBuscar)
        {
            cantidadCorrectas++;
        }
        if(hora == horaBuscar)
        {
            cantidadCorrectas++;
        }
        if(minutos == minutosBuscar)
        {
            cantidadCorrectas++;
        }
        if(cantidadCorrectas == 3)
        {
            encontrado = true;
            ///posicionEncontrado = i;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return encontrado;
}

bool buscarPaqueteRepartos(RepartoPtr reparto, int ID)
{
    ListaPtr ListaAuxiliar = crearLista();
    ListaPtr ListaPaquetes = getPaquetesReparto(reparto);
    agregarLista(ListaAuxiliar, ListaPaquetes);
    PaquetePtr PaqueteActual;
    int EstadoPaquete = 0;
    ///int posicionEncontrado = 0;
    int i = 0;
    bool encontrado = false;
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteActual = (PaquetePtr)getCabecera(ListaAuxiliar);
        EstadoPaquete = getEstado(PaqueteActual);
        if(EstadoPaquete == ID)
        {
            ///posicionEncontrado = i;
            encontrado = true;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return encontrado;
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
    {
        agregarDatoLista(getRepartos(centroLogistico,true), reparto);
    }
	else
    {
        agregarDatoLista(getRepartos(centroLogistico,false), reparto);
    }
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
    {
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosAbiertos,posicion);
    }
    else
    {
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosCerrados,posicion);
    }
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
        {
            match=true;
        }
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
        {
            match=true;
        }
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
        {
            match=true;
        }
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
        {
            match=true;
        }
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

///NINGUNA DE LAS OPERACIONES DE ORDENAMIENTO ALTERA EL ESTADO DE CENTRO LOGISTICO
///ORDENA EN UN VECTOR APARTE Y LUEGO LOS MUESTRA, GENERANDOLOS EN MEMORIA LOCAL,
///SIN ALTERAR EL ORDEN ORIGINAL DEL CENTRO LOGISTICO

void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modoOrdenamiento, int modoMostrado)
{
    int TamanioLista = longitudLista(getPersonas(centroLogistico));
    PersonaPtr personaAux;
    bool condicion;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        printf("Lista vacia, no se puede ordenar, intente agregando personas a la lista\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        int Salto = round(TamanioLista / 2);
        bool Cambios = true;
        ///Luego, ordenamos el vector (m. burbuja)
        while( Salto > 0)
        {
            Cambios = false;
            for(int i = 0; i < (TamanioLista - Salto); i++)
            {
                switch(modoOrdenamiento)
                {
                case 1:
                    condicion = strcmp( getNombre( getDatoLista( getPersonas(centroLogistico), i ) ), getNombre( getDatoLista( getPersonas(centroLogistico), i+1 ) ) ) > 0;
                    break;
                    ///condición: "Si el apellido de la persona en j va después del de la persona en j+1..."
                case 2:
                    condicion = strcmp( getApellido( getDatoLista( getPersonas(centroLogistico), i ) ), getApellido( getDatoLista( getPersonas(centroLogistico), i+1 ) ) ) > 0;
                    ///condición: "Si el apellido de la persona en j va después del de la persona en j+1..."
                    break;
                case 3:
                    condicion = strcmp( getCuil( getCuilPersona( getDatoLista( getPersonas(centroLogistico), i ) ) ), getCuil( getCuilPersona( getDatoLista( getPersonas(centroLogistico), i+1 ) ) ) ) > 0;
                    ///condición: "Si el Cuil de la persona en j van después de los de la persona en j+1..."
                    break;
                case 4:
                    break;
                }
                if(condicion)
                {
                    personaAux = removerDeLista( getPersonas(centroLogistico), i );
                    insertarDatoLista( getPersonas(centroLogistico), (PersonaPtr)personaAux, i+1 );
                }
            }
            if( !Cambios)
            {
                Salto = round(Salto / 2);
            }
        }
        mostrarPersonas(centroLogistico, modoMostrado);
        system("pause");
    }
}

void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo)
{
    int TamanioLista = longitudLista( getVehiculos( centroLogistico ) );
    VehiculoPtr vehiculoAux;
    bool condicion = false;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("Lista vacia, intente agregando un vehiculo a la lista\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        int Salto = round(TamanioLista / 2);
        bool Cambios = true;
        while(Salto > 0)
        {
            Cambios = false;
            for(int i=0; i < (TamanioLista - Salto); i++)
            {
                switch(modo)
                {
                case 1:
                    condicion = strcmp( getMarca( getDatoLista( getVehiculos(centroLogistico), i ) ), getMarca( getDatoLista( getVehiculos(centroLogistico), i+1 ) ) ) > 0;
                    ///condición: "Si la marca de vehiculos[j] es posterior a la de vehiculos[j+1]..."
                    break;
                case 2:
                    condicion = condicion && strcmp( getModelo( getDatoLista( getVehiculos(centroLogistico), i ) ), getModelo( getDatoLista( getVehiculos(centroLogistico), i+1 ) ) ) > 0;
                    ///condición: "Si la marca Y modelo de vehiculos[j] son posteriores a los de vehiculos[j+1]..."
                    break;
                case 3:
                    condicion = getTipoVehiculo( getDatoLista( getVehiculos(centroLogistico), i ) ) > getTipoVehiculo( getDatoLista( getVehiculos(centroLogistico), i ) );
                    ///condición: "Si el tipo, la marca Y el modelo de vehiculos[j] son posteriores a los de vehiculos[j+1]..."
                    break;
                case 4:
                    break;
                }
                if(condicion)
                {
                    vehiculoAux = removerDeLista( getVehiculos(centroLogistico), i );
                    insertarDatoLista( getVehiculos(centroLogistico), (VehiculoPtr)vehiculoAux, i+1 );
                }
            }
            if( !Cambios )
            {
                Salto = round(Salto / 2);
            }
        }
        mostrarVehiculos(centroLogistico);
        system("pause");
    }
}

void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo)
{
    int TamanioLista = longitudLista( getPaquetes( centroLogistico ) );
    PaquetePtr paqueteAux;
    bool condicion;
    int diferenciaFechas[3];
    if( listaVacia( getPaquetes(centroLogistico) ) )
    {
        printf("Lista vacia, intente agregando un paquete a la lista\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        int Salto = round(TamanioLista / 2);
        bool Cambios = true;
        while(Salto > 0)
        {
            Cambios = false;
            for(int i = 0 ; i < (TamanioLista - Salto) ; i++)
            {
                switch(modo)
                {
                    case 1:
                        condicion = getID( getDatoLista( getPaquetes(centroLogistico), i ) ) > getID( getDatoLista( getPaquetes(centroLogistico), i+1) );
                        ///condicion de la bandera: "Si el ID de paquetes[j] es mayor al de paquetes[j+1]..."
                        break;
                    case 2:
                        calcularDiferenciaFechas( getFechaEntrega( getDatoLista( getPaquetes(centroLogistico), i) ), getFechaEntrega( getDatoLista( getPaquetes(centroLogistico), i+1) ), diferenciaFechas );
                        condicion = diferenciaFechas[0] >= 0 || diferenciaFechas[1] >= 0 || diferenciaFechas[2] > 0;
                        ///condicion de la bandera: "Si la fecha de entrega de paquetes[j] es mayor a la de paquetes[j+1]..."
                        break;
                    case 3:
                        condicion = getEstado( getDatoLista( getPaquetes(centroLogistico), i) ) > getEstado( getDatoLista( getPaquetes(centroLogistico), i+1) );
                        break;
                    case 4:
                        ///Mostrar sin ordenar
                        break;
                        ///NO REQUIERE CLÁUSULA "DEFAULT"
                }
                if( condicion )
                {
                    paqueteAux = removerDeLista( getPaquetes(centroLogistico), i );
                    insertarDatoLista( getPaquetes(centroLogistico), (PaquetePtr)paqueteAux, i+1 );
                    Cambios = true;
                }
            }
            if( !Cambios )
            {
                Salto = round(Salto / 2);
            }
        }
        mostrarPaquetes(centroLogistico);
        system("pause");
    }
}


void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo)
{
    limpiarBufferTeclado();
    int TamanioLista = longitudLista( getRepartos(centroLogistico, esRepartoAbierto) );
    RepartoPtr repartoAux;
    bool condicion = false;
    int diferenciaFechaSalida[3];
    int diferenciaFechaRetorno[3];
    int diferenciaNombres = 0;
    int diferenciaApellidos = 0;
    if( listaVacia( getRepartos(centroLogistico,esRepartoAbierto) ) )
    {
        printf("Lista de repartos vacia, intente agregando un reparto a la lista\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        int Salto = round(TamanioLista / 2);
        bool Cambios = true;
        while(Salto > 0)
        {
            Cambios = false;
            for(int i = 0 ; i < (TamanioLista - Salto) ; i++)
            {
                switch(modo)
                {
                    case 1:
                        calcularDiferenciaFechas( getFechaSalida( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ), getFechaSalida( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ), diferenciaFechaSalida);
                        condicion = (diferenciaFechaSalida[0] >= 0 && (diferenciaFechaSalida[1] >= 0 || diferenciaFechaSalida[2] > 0));
                        ///condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida de reparto[j] es posterior a la de repartos[j+1]..."
                        break;
                    case 2:
                        calcularDiferenciaFechas( getFechaRetorno( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ), getFechaRetorno( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ), diferenciaFechaRetorno);
                        condicion = diferenciaFechaRetorno[0] >= 0 && (diferenciaFechaRetorno[1] >= 0 || diferenciaFechaRetorno[2] > 0);
                        ///condicion: "Ya sea en dias, horas o minutos, si fechaDeRetorno de reparto[j] es posterior a la de repartos[j+1]..."
                        break;
                    case 3:
                        calcularDiferenciaFechas( getFechaSalida( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ), getFechaSalida( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ), diferenciaFechaSalida);
                        condicion = diferenciaFechaSalida[0]>=0 && (diferenciaFechaSalida[1]>=0 || diferenciaFechaSalida[2]>0); //agrego la condicion de fechaSalida
                        calcularDiferenciaFechas( getFechaRetorno( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ), getFechaRetorno( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ), diferenciaFechaRetorno);
                        condicion = condicion && ( diferenciaFechaRetorno[0] >= 0 && ( diferenciaFechaRetorno[1] >= 0 || diferenciaFechaRetorno[2] > 0 ) ); //sumo la condicion de fechaRetorno
                        ///condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida *Y* fechaDeRetorno de reparto[j] son posteriores a las de repartos[j+1]..."
                        break;
                    case 4:
                        condicion = strcmp( getNombre( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ) ), getNombre( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ) ) ) > 0;
                        ///condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
                        break;
                    case 5:
                        condicion = strcmp( getApellido( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ) ), getApellido( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ) ) ) > 0;
                        ///condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
                        break;
                    case 6:
                        diferenciaApellidos = strcmp( getApellido( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ) ), getApellido( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ) ) );
                        condicion = diferenciaApellidos >= 0;
                        diferenciaNombres = strcmp( getNombre( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i ) ) ), getNombre( getChofer( getDatoLista( getRepartos(centroLogistico, esRepartoAbierto), i+1 ) ) ) );
                        condicion = condicion && diferenciaNombres > 0;
                        ///condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van después de los del chofer del reparto en j+1..."
                        break;
                    case 7:
                        break;
                }
                if( condicion )
                {
                    repartoAux = removerDeLista( getRepartos(centroLogistico, esRepartoAbierto), i );
                    insertarDatoLista( getRepartos(centroLogistico, esRepartoAbierto), (RepartoPtr)repartoAux, i+1 );
                    Cambios = true;
                }
            }
            if( !Cambios )
            {
                Salto = round(Salto / 2);
            }
        }
        mostrarRepartos(centroLogistico, esRepartoAbierto);
        system("pause");
    }
}
