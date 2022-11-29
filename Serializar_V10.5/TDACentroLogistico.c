#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Lista.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDARepartos.h"
#include "TDACentroLogistico.h"
#include "Menus.h"
#include "util.h"



/// /////////////////////////////////FUNCIONES CONSTRUCTORAS Y DESTRUCTORAS/////////////////////////////////////////////////////////////////////// ///

CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados)
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);

    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaPersonas=listaPersonas;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartosAbiertos=listaRepartosAbiertos;

    return centroLogistico;
}

CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro log�stico con un nombre y listas vac�as.
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));

    centroLogistico->nombre=crearStringDinamico(nombre);

    centroLogistico->listaPaquetes=crearLista();
    centroLogistico->listaPersonas=crearLista();
    centroLogistico->listaVehiculos=crearLista();
    centroLogistico->listaRepartosAbiertos=crearLista();

    return centroLogistico;
}

CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    centroLogistico->nombre=destruirStringDinamico(centroLogistico->nombre);

    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);

    free(centroLogistico);

    return NULL;
}

/// ///////////////////////////////////////////////GETTERS/////////////////////////////////////////////////////////////////////// ///

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

ListaPtr getRepartos(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaRepartosAbiertos;
}

/// ///////////////////////////////////////////////SETTERS/////////////////////////////////////////////////////////////////////// ///

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

void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos)
{
    centroLogistico->listaRepartosAbiertos = repartos;
}

/// ///////////////////////////////////////////////FUNCIONES DE MUESTRA Y FILTRADO/////////////////////////////////////////////////////////////////////// ///

void mostrarPaquetes(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));

    printf("\nLISTA DE PAQUETES: \n\n");
    for(int i=1;!listaVacia(listaAux);i++)
    {
        printf("%d. ",i);
        mostrarPaquete((PaquetePtr)getCabecera(listaAux));

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);

        if(!listaVacia(listaAux))
            printf("\n");
    }
    printf("\n-----------------------------------------------------\n\n");
    listaAux=destruirLista(listaAux,false);
}

void mostrarPersonas(CentroLogisticoPtr centroLogistico,int modo)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

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
    for(int i=1;!listaVacia(listaAux);i++)
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

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);

        if(!listaVacia(listaAux))
            printf("\n");
    }
    printf("\n-----------------------------------------------------\n\n");
    listaAux=destruirLista(listaAux,false);
}

void mostrarVehiculos(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));

    printf("\nLISTA DE VEHICULOS: \n\n");
    for(int i=1;!listaVacia(listaAux);i++)
    {
        printf("%d. ",i);
        mostrarVehiculo((VehiculoPtr)getCabecera(listaAux));

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);

        if(!listaVacia(listaAux))
            printf("\n");
    }
    printf("\n-----------------------------------------------------\n\n");
    listaAux=destruirLista(listaAux,false);
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico)
{
	printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));
    for(int i=1;!listaVacia(listaAux);i++)
    {
        RepartoPtr repartoAux = (RepartoPtr) getCabecera(listaAux);
        printf("%d. ", i);
        mostrarRepartoSinPaquetes(repartoAux);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);

        if(!listaVacia(listaAux))
            printf("\n\n\n");
    }
    printf("\n-----------------------------------------------------\n\n");
    listaAux=destruirLista(listaAux,false);
}

void filtrarRepartosPorFecha(CentroLogisticoPtr centroLogistico,FechaPtr fecha)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));

    printf("\nLISTA DE REPARTOS ");
    printf("ABIERTOS ");
    char buffer[11];
    traerFechaCorta(fecha,buffer);
    printf("FILTRADOS POR DIA DE SALIDA - %s \n\n\n\n",buffer);
    for(int i=1;!listaVacia(listaAux);i++)
    {
        RepartoPtr repartoAux=getCabecera(listaAux);
        int *diaJulianoDeReparto = calcularDiferenciaFechas(getFechaSalida(repartoAux),fecha);
        bool condicion = diaJulianoDeReparto[0]==0;
    ///CONDICION: "si SOLAMENTE el d�a JULIANO del reparto (dia, mes y a�o) coincide con el de la fecha recibida..."
        if(condicion)
        {
            printf("\n\n%d. ", i);
            mostrarRepartoSinPaquetes(repartoAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void filtrarPaquetesPorEstado(CentroLogisticoPtr centroLogistico,int estado) //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().
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
    case 6:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'RESERVADO': \n\n");
        break;
    default:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'ERROR': \n\n");
        break;
    }

    for(int i=1;!listaVacia(listaAux);i++)
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);
        if(getEstado(paqueteAux)==estado)
        {
            printf("\n\n%d. ", i);
            mostrarPaquete(paqueteAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux,false);
    printf("\n");
}

void filtrarPaquetesEnCurso(CentroLogisticoPtr centroLogistico, bool enCurso)
{
    bool condicion;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    if(enCurso) { printf("\n\nLISTA DE PAQUETES EN CURSO\n\n"); }
    else { printf("\n\nLISTA DE PAQUETES EN DEPOSITO\n\n"); }

    for(int i=1;!listaVacia(listaAux);i++)
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);
        int estado = getEstado(paqueteAux);

        if(enCurso) { condicion = estado == 1 || estado == 2 || estado == 4; }
        else { condicion = estado == 0 || estado == 5; }

        if(condicion)
        {
            printf("\n\n%d. ", i);
            mostrarPaquete(paqueteAux);
        }

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux,false);
}

void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    PaquetePtr paqueteAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    for(int i=1;!listaVacia(listaAux);i++)
    {
        paqueteAux = (PaquetePtr)getCabecera(listaAux);

        int estado = getEstado(paqueteAux);
        bool paqueteDisponible = estado == 0 || estado == 5;
        if(paqueteDisponible)
        {
            printf("\n\n%d. ", i);
            mostrarPaquete(paqueteAux);
        }

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
}

bool choferEnReparto(CentroLogisticoPtr centroLogistico, PersonaPtr chofer, FechaPtr fechaSalida)
{
    if(!getEsChofer(chofer))
        return false;
    else
    {
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux, getRepartos(centroLogistico));

        ListaPtr listaAux2 = crearLista();
        agregarLista(listaAux2, getRepartos(centroLogistico));

        int *difFechas = NULL;
        int *difFechas2 = NULL;

        while(!listaVacia(listaAux))
        {
            RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);

            difFechas = calcularDiferenciaFechas(fechaSalida,getFechaSalida(repartoAux));
            bool condicion = difFechas[0]==0 && personasIguales(chofer,getChofer(repartoAux));

        ///Un chofer puede tener varios repartos asignados, pero no en el mismo d�a. Por eso,
        ///Condici�n: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
            if(condicion)
            {
                listaAux = destruirLista(listaAux, false);

                free(difFechas);
                difFechas = NULL;
                return true;
            }

            ListaPtr listaDestruir = listaAux;
            listaAux = getResto(listaAux);
            listaDestruir = destruirLista(listaDestruir, false);
        }
        free(difFechas);
        difFechas = NULL;
        listaAux = destruirLista(listaAux, false);

        while(!listaVacia(listaAux2))
        {
            RepartoPtr repartoAux2 = (RepartoPtr)getCabecera(listaAux2);

            difFechas2 = calcularDiferenciaFechas(fechaSalida,getFechaSalida(repartoAux2));
            bool condicion2 = difFechas2[0]==0 && personasIguales(chofer,getChofer(repartoAux2));
        ///Un chofer puede tener varios repartos asignados, pero no en el mismo d�a. Por eso,
        ///Condici�n: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
            if(condicion2)
            {
                listaAux2 = destruirLista(listaAux2, false);

                free(difFechas2);
                difFechas2 = NULL;
                return true;
            }

            ListaPtr listaDestruir2 = listaAux2;
            listaAux2 = getResto(listaAux2);
            listaDestruir2 = destruirLista(listaDestruir2, false);
        }

        free(difFechas2);
        difFechas2 = NULL;

        listaAux2 = destruirLista(listaAux2, false);
        return false;
    }
}

void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fechaSalida)
{
    PersonaPtr personaAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));

    for(int i=1;!listaVacia(listaAux);i++)
    {
        personaAux = (PersonaPtr)getCabecera(listaAux);

    //Condicion: tiene que ser un chofer, y no figurar en la lista de repartos abiertos
        if(!choferEnReparto(centroLogistico, personaAux, fechaSalida) && getEsChofer(personaAux))
        { ///De esta manera, no se vuelve necesario encadenar tantos ifs.
            printf("\n\n%d. ",i);
            mostrarPersona(personaAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
}

/// ///////////////////////////////////////////////FUNCIONES DE B�SQUEDA/////////////////////////////////////////////////////////////////////// ///

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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo ac� para que no pase si no hay un match.

    return match;
}
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(strcmp(getCuil(getCuilPersona(personaAux)),getCuil(cuil))==0 && getEsChofer(personaAux)==esChofer)
        {
            match=true;
            mostrarPersona(personaAux); //mostramos solo si el cuil y esChofer coinciden
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo ac� para que no pase si no hay un match.

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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo ac� para que no pase si no hay un match.

    return match;
}

bool buscarReparto(CentroLogisticoPtr centroLogistico,int modo)
{
    bool condicion=false;
    bool match=false;

    int n=0;

    int i=0;
    CuilPtr cuilBuscar;
    char patenteBuscar[100];
    int IDBuscar;
    FechaPtr fechaBuscar;

    if(modo==1)
    {
        n=longitudLista(getRepartos(centroLogistico));
        do
        {
            printf("BUSCAR POR INDICE: \n");

            printf("Seleccione un indice: ");
            scanf("%d",&i);
            limpiarBufferTeclado();

            if(i<=0 || i>n)
                printf("ERROR: Indice inexistente.\n\n");
        } while(i<=0 || i>n);
    }
    else if(modo == 2)
    {
        printf("BUSCAR POR CUIL: \n");
        cuilBuscar=cargarCuil(centroLogistico);
        if(cuilBuscar==NULL)
        {
            printf("No se pudo buscar por CUIL.");
            presionarEnterYLimpiarPantalla();
            return match;
        }
    }
    else if(modo == 3)
    {
        printf("BUSCAR POR PATENTE: \n");
        do
        {
            printf("\n\n\tFormato: [AA 111 AA]");
            printf("\n\n\tPatente: ");
            scanf("%[^\n]%*c", patenteBuscar);
            limpiarBufferTeclado();

            if(!esPatenteValida(patenteBuscar))
            {
                printf("\n\n\t [Patente invalida...]\n");
                presionarEnterYLimpiarPantalla();
            }
        } while(!esPatenteValida(patenteBuscar));
    }
    else if(modo == 4)
    {
        printf("BUSCAR POR FECHA DE SALIDA: \n");
        fechaBuscar = cargarFecha();
    }
    else if(modo == 5)
    {
        printf("BUSCAR POR FECHA DE RETORNO: \n");
        fechaBuscar = cargarFecha();
    }
    else if(modo == 6)
    {
        n=longitudLista(getPaquetes(centroLogistico));

        do
        {
            printf("BUSCAR POR ID DEL PAQUETE: \n");
            printf("Ingrese el ID del paquete: ");
            scanf("%d",&IDBuscar);
            limpiarBufferTeclado();

            if(IDBuscar<0 || IDBuscar>n)
                printf("ERROR: ID inexistente.");
        } while(IDBuscar<0 || IDBuscar>n);
    }

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));

    for(int j=0;!listaVacia(listaAux);j++)
    {
        RepartoPtr repartoAux=(RepartoPtr)getCabecera(listaAux);

        switch(modo)
        {
        case 1:
            condicion = i==j;
            break;
        case 2:
            condicion = cuilsIguales(cuilBuscar,getCuilPersona(getChofer(repartoAux)));
            break;
        case 3:
            condicion = strcmp(patenteBuscar,(getPatente(getVehiculo(repartoAux))));
            break;
        case 4:
            condicion = fechasIguales(fechaBuscar,getFechaSalida(repartoAux));
            break;
        case 5:
            condicion = fechasIguales(fechaBuscar,getFechaRetorno(repartoAux));
            break;
        }
        if(modo==6)
        {
            n=cantidadPaquetes(repartoAux);
            PaquetePtr paquetesAux[n];
            int ultimaPos=0;
            for(int i=0;!pilaVacia(getPaquetesReparto(repartoAux));i++)
            {
                paquetesAux[i] = descargarPaquete(repartoAux);

                if(IDBuscar==getID(paquetesAux[i]))
                {
                    condicion=true;
                    ultimaPos=n-i;
                    break;
                }
                if(condicion)
                {
                    printf("FUNCION BUSCAR REPARTO, CLAUSULA 6: no se siguio el break en el 1er for.\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }
            for(int i=n-1;i>ultimaPos-1;i--)
                cargarPaquete(repartoAux,paquetesAux[i]);
        }

        if(condicion)
        {
            match=true;
            mostrarReparto(repartoAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo ac� para que no pase si no hay un match.

    return match;
}

/// /////////////////////////////////////////FUNCIONES DE AGREGADO A LA LISTA/////////////////////////////////////////////////////////////////////// ///

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
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto)
{
    agregarDatoLista(getRepartos(centroLogistico), reparto);
}

/// ////////////////////////////////////////FUNCIONES DE INSERCI�N A LA LISTA/////////////////////////////////////////////////////////////////////// ///

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

bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion) ///SOLO PARA REPARTOS ABIERTOS
{
    return insertarDatoLista(centroLogistico->listaRepartosAbiertos,(RepartoPtr)reparto,posicion);
}

/// //////////////////////////////////////FUNCIONES DE ELIMINACI�N DE LA LISTA/////////////////////////////////////////////////////////////////////// ///

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
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion)
{
    RepartoPtr repartoRemover = (RepartoPtr)removerDeLista(getRepartos(centroLogistico),posicion);

    int n = cantidadPaquetes(repartoRemover);
    PaquetePtr paquetes[n];
    for(int i=0;i<n;i++)
    {
        paquetes[i] = descargarPaquete(repartoRemover);

        int estado = getEstado(paquetes[i]);
        if(estado!=3 && estado!=5)
            setEstado(paquetes[i],0);
    }
    for(int i=n-1;i>-1;i--)
        cargarPaquete(repartoRemover,paquetes[i]);

    return repartoRemover;
}

void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion) ///Ahora es autom�tico
{
    ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion);

    ///Copiamos el contenido del reparto en uno nuevo.
    RepartoPtr copiaReparto = copiarReparto(repartoACerrar);

    ///Obtenemos cada paquete de la pila y marcamos como suspendido los que no se entregaron
    int n=cantidadPaquetes(repartoACerrar);
    PaquetePtr paquetesAux[n];

    int nPaqSuspendidos=0;

    for(int i=0;i<n;i++)
    {
        paquetesAux[i] = descargarPaquete(repartoACerrar);

        if(!quedaTiempo(getFechaRetorno(repartoACerrar)) && getEstado(paquetesAux[i])!=3)
        {
            setEstado(paquetesAux[i],5);
            nPaqSuspendidos++;
        }
    }

    int paqSuspendidos[nPaqSuspendidos];

    for(int i=n-1,j=0;i>-1 && j<nPaqSuspendidos;i--)
    {
        if(getEstado(paquetesAux[i])==5)
        {
            paqSuspendidos[j] = getID(paquetesAux[i]);
            j++;
        }
        cargarPaquete(repartoACerrar,paquetesAux[i]);
    }

///Agregamos la copia del reparto cerrado a la lista de cerrados
    agregarReparto(centroLogistico,copiaReparto);

///Destruimos el reparto original e informamos
    repartoACerrar=destruirReparto(repartoACerrar);
    printf("Cerrado reparto %d...\n",posicion+1);

    printf("Se suspendieron los paquetes:\n");
    for(int i=0;i<nPaqSuspendidos;i++)
        printf("\t #%d \n",paqSuspendidos[i]);
    printf("\n");
}

/// ///////////////////////////////////////////////FUNCIONES DE VALIDACI�N/////////////////////////////////////////////////////////////////////// ///

bool hayPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    PaquetePtr paqueteAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        paqueteAux = (PaquetePtr)getCabecera(listaAux);

        int estado = getEstado(paqueteAux);
        bool paqueteDisponible = estado == 0 || estado == 5;
        if(paqueteDisponible)
        {
            listaAux = destruirLista(listaAux, false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    return false;
}

bool hayPersonas(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    PersonaPtr personaAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        personaAux = (PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux) == esChofer)
        {
            listaAux = destruirLista(listaAux, false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    return false;
}

bool esIDExistente(CentroLogisticoPtr centroLogistico, int ID)
{
    PaquetePtr paqueteAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        paqueteAux = (PaquetePtr)getCabecera(listaAux);
        if(ID == getID(paqueteAux))
        {
            listaAux = destruirLista(listaAux, false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    return false;
}

bool esCuilExistente(CentroLogisticoPtr centroLogistico, CuilPtr cuil)
{
    CuilPtr cuilAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico) );

    while(!listaVacia(listaAux))
    {
        cuilAux = getCuilPersona( (PersonaPtr)getCabecera(listaAux) );

        if( cuilsIguales( cuilAux , cuil ) )
        {
            listaAux = destruirLista(listaAux, false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    return false;
}

bool esPatenteValida(char* patente)
{
    int pass = 0;
///Se eval�a si tiene 4 letras y 3 numeros

    if( isalpha(patente[0]) ) { pass++; }
    if( isalpha(patente[1]) ) { pass++; }

    if( isdigit(patente[3]) ) { pass++; }
    if( isdigit(patente[4]) ) { pass++; }
    if( isdigit(patente[5]) ) { pass++; }

    if( isalpha(patente[7]) ) { pass++; }
    if( isalpha(patente[8]) ) { pass++; }

    if( pass == 7 )
        return true;
    else
        return false;
}

void mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fecha)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    for(int i=1;!listaVacia(listaAux);i++)
    {
        if(esVehiculoDisponible(centroLogistico,getPatente(getCabecera(listaAux)),fecha))
        {
            printf("\n\nPosicion %d.",i);
            mostrarVehiculo(getCabecera(listaAux));
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
}

bool esVehiculoDisponible(CentroLogisticoPtr centroLogistico, char* patente,FechaPtr fecha)
{
    VehiculoPtr vehiculoDevolver;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
        vehiculoDevolver=getVehiculo(repartoAux);
        if(strcmp(getPatente(vehiculoDevolver),patente)==0 && getDiaJuliano(fecha)==getDiaJuliano(getFechaSalida(repartoAux)))
        {
            listaAux=destruirLista(listaAux,false);
            return false;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return true;
}

bool esPatenteExistente(CentroLogisticoPtr centroLogistico, char* patente)
{
    VehiculoPtr vehiculoAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getVehiculos(centroLogistico) );

    while(!listaVacia(listaAux))
    {
        vehiculoAux = (VehiculoPtr)getCabecera(listaAux);
        if( strcmp( patente, getPatente(vehiculoAux) ) == 0 )
        {
            listaAux = destruirLista(listaAux, false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    return false;
}

bool esPaqueteExistente(CentroLogisticoPtr centroLogistico, PaquetePtr paquete)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
        if(paquetesIguales(paqueteAux,paquete))
        {
            listaAux=destruirLista(listaAux,false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return false;
}

bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona) // devuelve true si la persona que le ingresamos tiene el mismo cuil que una de las personas, false si no
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(personasIguales(personaAux,persona))
        {
            listaAux=destruirLista(listaAux,false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return false;
}

bool esVehiculoExistente(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculo)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    while(!listaVacia(listaAux))
    {
        VehiculoPtr vehculoAux = (VehiculoPtr)getCabecera(listaAux);
        if(vehiculosIguales(vehculoAux,vehiculo))
        {
            listaAux=destruirLista(listaAux,false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return false;
}

bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto)
{ ///NUEVO: ahora recorre la lista de repartos abiertos y cerrados a la vez.
    ListaPtr listaAux=crearLista();
    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));
    agregarLista(listaAux2,getRepartos(centroLogistico));
    while(!listaVacia(listaAux) && !listaVacia(listaAux2))
    {
        RepartoPtr repartoAux=(RepartoPtr)getCabecera(listaAux);
        RepartoPtr repartoAux2=(RepartoPtr)getCabecera(listaAux2);

        int *difFechas = calcularDiferenciaFechas(getFechaSalida(reparto),getFechaSalida(repartoAux));
        bool condicion = difFechas[0]==0 && personasIguales(getChofer(repartoAux),getChofer(reparto));

        int *difFechas2 = calcularDiferenciaFechas(getFechaSalida(reparto),getFechaSalida(repartoAux2));
        bool condicion2 = difFechas2[0]==0 && personasIguales(getChofer(repartoAux2),getChofer(reparto));
    ///Un chofer puede tener varios repartos asignados, pero no en el mismo d�a. Por eso,
    ///Condici�n: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
        if(condicion || condicion2)
        {
            listaAux=destruirLista(listaAux,false);
            listaAux2=destruirLista(listaAux2,false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);

        listaDestruir = listaAux2;
        listaAux2 = getResto(listaAux2);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    listaAux2=destruirLista(listaAux2,false);
    return false;
}

/// ///////////////////////////////////////////////FUNCIONES DE ORDENAMIENTO/////////////////////////////////////////////////////////////////////// ///

void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getPaquetes(centroLogistico));

    PaquetePtr paquetes[n];
    PaquetePtr paqueteAux;

    int *diferenciaFechas;
    bool condicion;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        paquetes[i]=removerPaquete(centroLogistico,0);

    ///Luego, ordenamos el vector (m. shell)
    int salto=n/2;
    while(salto>0)
    {
        bool cambios = false;
        for(int i=0;i<(n-salto);i++)
        {
            switch(modo)
            {
            case 1:
                condicion = getID(paquetes[i]) > getID(paquetes[i+salto]);
            //condicion de la bandera: "Si el ID de paquetes[i] es mayor al de paquetes[i+salto]..."
                break;
            case 2:
                diferenciaFechas=calcularDiferenciaFechas(getFechaEntrega(paquetes[i]),getFechaEntrega(paquetes[i+salto]));
                condicion = diferenciaFechas[0]>0 || diferenciaFechas[1]>0 || diferenciaFechas[2]>0;
            //condicion de la bandera: "Si la fecha de entrega de paquetes[i] es mayor a la de paquetes[i+salto]..."
                break;
            case 3:
                condicion = getEstado(paquetes[i]) > getEstado(paquetes[i+salto]);
                break;
            ///NO REQUIERE CL�USULA "DEFAULT"
            }
            if(condicion)
            { //Hago un swap
                cambios=true;
                paqueteAux=paquetes[i];
                paquetes[i]=paquetes[i+salto];
                paquetes[i+salto]=paqueteAux;
            }
        }
        if(!cambios)
            salto/=2;
    }
    ///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=n-1; i>-1; i--)
        agregarPaquete(centroLogistico,paquetes[i]);
}
void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getPersonas(centroLogistico));

    PersonaPtr personas[n];
    PersonaPtr personaAux;

    bool condicion;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        personas[i]=removerPersona(centroLogistico,0);

    int salto=n/2;
    ///Luego, ordenamos el vector (m. shell)
    while(salto>0)
    {
        bool cambios = false;
        for(int i=0;i<(n-salto);i++)
        {
            switch(modo)
            {
            case 1:
                condicion = strcmp(getNombre(personas[i]),getNombre(personas[i+salto])) > 0;
                break;
                //condici�n: "Si el apellido de la persona en j va despu�s del de la persona en [i+salto]..."
            case 2:
                condicion = strcmp(getApellido(personas[i]),getApellido(personas[i+salto])) > 0;
            //condici�n: "Si el apellido de la persona en j va despu�s del de la persona en [i+salto]..."
                break;
            case 3:
                condicion = strcmp(getApellido(personas[i]),getApellido(personas[i+salto])) >= 0;
                condicion = condicion && strcmp(getNombre(personas[i]),getNombre(personas[i+salto])) > 0;
            //condici�n: "Si el APELLIDO Y EL NOMBRE de la persona en j van despu�s de los de la persona en [i+salto]..."
                break;
            }
            if(condicion)
            { //Hago un swap
                cambios=true;
                personaAux=personas[i];
                personas[i]=personas[i+salto];
                personas[i+salto]=personaAux;
            }
        }
        if(!cambios)
            salto/=2;
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=n-1; i>-1; i--)
        agregarPersona(centroLogistico,personas[i]);
}
void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getVehiculos(centroLogistico));

    VehiculoPtr vehiculos[n];
    VehiculoPtr vehiculoAux;

    bool condicion;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        vehiculos[i]=removerVehiculo(centroLogistico,0);

    ///Luego, ordenamos el vector (m. shell)
    int salto=n/2;
    while(salto>0)
    {
        bool cambios = false;
        for(int i=0;i<(n-salto);i++)
        {
            switch(modo)
            {
            case 1:
                condicion = strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[i+salto])) > 0;
            //condici�n: "Si la marca de vehiculos[i] es posterior a la de vehiculos[i+salto]..."
                break;
            case 2:
                condicion = strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[i+salto])) >= 0;
                condicion = condicion && strcmp(getModelo(vehiculos[i]),getModelo(vehiculos[i+salto])) > 0;
            //condici�n: "Si la marca Y modelo de vehiculos[i] son posteriores a los de vehiculos[i+salto]..."
                break;
            case 3:
                condicion = getTipoVehiculo(vehiculos[i]) >= getTipoVehiculo(vehiculos[i+salto]);
                condicion = condicion && strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[i+salto])) >= 0;
                condicion = condicion && strcmp(getModelo(vehiculos[i]),getModelo(vehiculos[i+salto])) > 0;
            //condici�n: "Si el tipo, la marca Y el modelo de vehiculos[i] son posteriores a los de vehiculos[i+salto]..."
                break;
            }
            if(condicion)
            { //Hago un swap
                cambios=true;
                vehiculoAux=vehiculos[i];
                vehiculos[i]=vehiculos[i+salto];
                vehiculos[i+salto]=vehiculoAux;
            }
        }
        if(!cambios)
            salto/=2;
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=n-1; i>-1; i--)
        agregarVehiculo(centroLogistico,vehiculos[i]);
}

void ordenarRepartos(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getRepartos(centroLogistico));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    bool condicion;
    int *diferenciaFechaSalida;
    int *diferenciaFechaRetorno;
    int diferenciaNombres=0;
    int diferenciaApellidos=0;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0);

    ///Luego, ordenamos el vector (m. shell)
    int salto=n/2;
    while(salto>0)
    {
        bool cambios = false;
        for(int i=0;i<(n-salto);i++)
        {
            switch(modo)
            {
            case 1:
                diferenciaFechaSalida = calcularDiferenciaFechas(getFechaSalida(repartos[i]),getFechaSalida(repartos[i+salto]));
                condicion = diferenciaFechaSalida[0]>0 || diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0;
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida de reparto[i] es posterior a la de repartos[i+salto]..."
                break;
            case 2:
                diferenciaFechaRetorno = calcularDiferenciaFechas(getFechaRetorno(repartos[i]),getFechaRetorno(repartos[i+salto]));
                condicion = diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0;
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeRetorno de reparto[i] es posterior a la de repartos[i+salto]..."
                break;
            case 3:
                diferenciaFechaSalida = calcularDiferenciaFechas(getFechaSalida(repartos[i]),getFechaSalida(repartos[i+salto]));
                condicion = diferenciaFechaSalida[0]>0 || diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0; //agrego la condicion de fechaSalida
                diferenciaFechaRetorno = calcularDiferenciaFechas(getFechaRetorno(repartos[i]),getFechaRetorno(repartos[i+salto]));
                condicion = condicion && (diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0); //sumo la condicion de fechaRetorno
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida *Y* fechaDeRetorno de reparto[i] son posteriores a las de repartos[i+salto]..."
                break;
            case 4:
                condicion = strcmp(getNombre(getChofer(repartos[i])),getNombre(getChofer(repartos[i+salto]))) > 0;
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va despu�s del del reparto en i+salto..."
                break;
            case 5:
                condicion = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[i+salto]))) > 0;
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va despu�s del del reparto en [i+salto]..."
                break;
            case 6:
                diferenciaApellidos = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[i+salto])));
                condicion = diferenciaApellidos >= 0;
                diferenciaNombres = strcmp(getNombre(getChofer(repartos[i])),getNombre(getChofer(repartos[i+salto])));
                condicion = condicion && diferenciaNombres > 0;
            //condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van despu�s de los del chofer del reparto en [i+salto]..."
                break;
            }
            if(condicion)
            { //Hago un swap
                cambios=true;
                repartoAux=repartos[i];
                repartos[i]=repartos[i+salto];
                repartos[i+salto]=repartoAux;
            }
        }
        if(!cambios)
            salto/=2;
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=n-1; i>-1; i--)
        agregarReparto(centroLogistico,repartos[i]);
}


/// ///////////////////////////////////////////////SISTEMA DE ACTUALIZACI�N AUTOM�TICA DE REPARTOS////////////////////////////////////////////////////////// ///

void actualizarRepartos(CentroLogisticoPtr ctroLog) ///NUEVA
{
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getRepartos(ctroLog));

    bool hayCambios=false;

    for(int i=0;!listaVacia(listaAux);i++)
    {
        RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);

        if(!quedaTiempo(getFechaRetorno(repartoAux)))
        {
            hayCambios=true;
            cerrarReparto(ctroLog,i);
        }
        else
            hayCambios = actualizarReparto(repartoAux,i+1);

        if(hayCambios)
            printf("\n\n");

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);

    if(hayCambios)
        presionarEnterYLimpiarPantalla();
}
