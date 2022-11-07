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



/// /////////////////////////////////FUNCIONES CONSTRUCTORAS Y DESTRUCTORAS//////////////////////////////////////////////////////////////////////////

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
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    centroLogistico->nombre=destruirStringDinamico(centroLogistico->nombre);

    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);
    centroLogistico->listaRepartosCerrados=destruirLista(centroLogistico->listaRepartosCerrados,true);

    free(centroLogistico);

    return NULL;
}

/// ///////////////////////////////////////////////GETTERS//////////////////////////////////////////////////////////////////////////

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

/// ///////////////////////////////////////////////SETTERS//////////////////////////////////////////////////////////////////////////

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

/// ///////////////////////////////////////////////FUNCIONES DE MUESTRA Y FILTRADO//////////////////////////////////////////////////////////////////////////

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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
        if(!listaVacia(listaAux))
            printf("\n");

        i++;
    }
    printf("\n-----------------------------------------------------");
    listaAux=destruirLista(listaAux,false);
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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
        if(!listaVacia(listaAux))
            printf("\n");

        i++;
    }
    printf("\n-----------------------------------------------------");
    listaAux=destruirLista(listaAux,false);
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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
        if(!listaVacia(listaAux))
            printf("\n");

        i++;
    }
    printf("\n-----------------------------------------------------");
    listaAux=destruirLista(listaAux,false);
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
    {
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
    }
	else
    {
        printf("\nLISTA DE REPARTOS CERRADOS (*): \n\n");
    }
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));
    int i = 1;
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux = (RepartoPtr) getCabecera(listaAux);
        printf("\n\n Posicion %d. \n\n", i);
        mostrarRepartoSinPaquetes(repartoAux);
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
        i++;
    }
    printf("\n-----------------------------------------------------");
    listaAux=destruirLista(listaAux,false);
}

void filtrarRepartosPorFecha(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,FechaPtr fecha)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

    printf("\nLISTA DE REPARTOS ");
    if(esRepartoAbierto)
        printf("ABIERTOS ");
    else
        printf("CERRADOS ");
    char buffer[11];
    traerFechaCorta(fecha,buffer);
    printf("FILTRADOS POR DIA DE SALIDA - %s \n\n\n\n",buffer);
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux=getCabecera(listaAux);
        int *diaJulianoDeReparto = calcularDiferenciaFechas(getFechaSalida(repartoAux),fecha);
        bool condicion = diaJulianoDeReparto[0]==0;
    ///CONDICION: "si SOLAMENTE el día JULIANO del reparto (dia, mes y año) coincide con el de la fecha recibida..."
        if(condicion)
        {
            mostrarRepartoSinPaquetes(repartoAux);
            printf("\n\n\n");
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
    int i = 1;
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
            printf("\n\n Posicion %d. \n\n", i++);
            mostrarPaquete(paqueteAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux,false);
    printf("\n");
}

void filtrarPaquetesEnCurso(CentroLogisticoPtr centroLogistico, bool enCurso) ///NUEVA
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
            printf("\n\n Posicion %d. \n\n", i);
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
            printf("\n\n Posicion %d. \n\n", i);
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
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getRepartos(centroLogistico, true));
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
        bool condicion = personasIguales(getChofer(repartoAux),chofer);
        if(condicion)
        {
            listaAux = destruirLista(listaAux,false);
            return true;
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);

    listaAux = crearLista();
    agregarLista(listaAux, getRepartos(centroLogistico, false));
    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
        bool condicion = (getDia(fechaSalida)==getDia(getFechaSalida(repartoAux))) && personasIguales(getChofer(repartoAux),chofer);
        if(condicion)
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

void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fechaSalida)
{
    PersonaPtr personaAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));
    for(int i=1;!listaVacia(listaAux);i++)
    {
        personaAux = (PersonaPtr)getCabecera(listaAux);
        ///De esta manera, no se vuelve necesario encadenar tantos ifs.
        //Condicion: tiene que ser un chofer, y no figurar en la lista de repartos abiertos
        if(!choferEnReparto(centroLogistico, personaAux, fechaSalida) && getEsChofer(personaAux))
        {
            printf("\n\nPosicion %d.\n\n", i);
            mostrarPersona(personaAux);
        }
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
}

bool mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico)
{
    VehiculoPtr vehiculoDevolver;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        vehiculoDevolver=getVehiculo((RepartoPtr)getCabecera(listaAux));
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    return false;
}

/// ///////////////////////////////////////////////FUNCIONES DE BÚSQUEDA//////////////////////////////////////////////////////////////////////////

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
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

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
        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}

bool buscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo)
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
        n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
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
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

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
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}

/// /////////////////////////////////////////FUNCIONES DE AGREGADO A LA LISTA//////////////////////////////////////////////////////////////////////////

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

/// ////////////////////////////////////////FUNCIONES DE INSERCIÓN A LA LISTA//////////////////////////////////////////////////////////////////////////

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

/// //////////////////////////////////////FUNCIONES DE ELIMINACIÓN DE LA LISTA//////////////////////////////////////////////////////////////////////////

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
///NUEVA IMPLEMENTACIÓN
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion)
{ ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion,true);
///Copiamos el contenido del reparto en uno nuevo.
///NUEVO: aprovechamos las nuevas funciones "copiarX" para agilizar y simplificar el proceso.
    RepartoPtr copiaReparto = copiarReparto(repartoACerrar);

///Obtenemos cada paquete de la pila y registramos sus estados
    int n=cantidadPaquetes(repartoACerrar);
    PaquetePtr paquetesAux[n];

    int estadoPaquetes[6];
    for(int i=0;i<n;i++)
    {
        paquetesAux[i] = descargarPaquete(repartoACerrar);
    ///Salvamos el conjunto de estados de los paquetes de la pila como valores de verdad en un vector de enteros
        switch(getEstado(paquetesAux[i]))
        {
        case 0:
            estadoPaquetes[0]=1;
            break;
        case 1:
            estadoPaquetes[1]=1;
            break;
        case 2:
            estadoPaquetes[2]=1;
            break;
        case 3:
            estadoPaquetes[3]=1;
            break;
        case 4:
            estadoPaquetes[4]=1;
            break;
        case 5:
            estadoPaquetes[5]=1;
            break;
        }
    }
    for(int i=n-1;i>-1;i--)
        cargarPaquete(repartoACerrar,paquetesAux[i]);

///Agregamos la copia del reparto cerrado a la lista de cerrados
    agregarReparto(centroLogistico,copiaReparto,false);
///Destruimos el reparto original
    repartoACerrar=destruirReparto(repartoACerrar);

    printf("\n\nCerrando reparto...\n\n");
    bool condicion = estadoPaquetes[0]==0;
    condicion = condicion && estadoPaquetes[1]==0;
    condicion = condicion && estadoPaquetes[2]==0;
    condicion = condicion && estadoPaquetes[3]==1;
    condicion = condicion && estadoPaquetes[4]==0;
    condicion = condicion && estadoPaquetes[5]==0;
///Imprimimos un mensaje informativo acerca del estado de los paquetes
    if(condicion)
        printf("Todos los paquetes fueron entregados con exito.\n\n");
    else if(estadoPaquetes[0]==1)
        printf("ADVERTENCIA: Quedaron paquetes marcados como 'EN DEPOSITO'.\n\n");
    else if(estadoPaquetes[1]==1 || estadoPaquetes[2]==1)
        printf("Quedaron paquetes sin entregar. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
    else if(estadoPaquetes[4]==1)
        printf("Algunos paquetes estan demorados. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
    else if(estadoPaquetes[5]==1)
        printf("Se suspendieron algunos paquetes. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
}

/// ///////////////////////////////////////////////FUNCIONES DE VALIDACIÓN//////////////////////////////////////////////////////////////////////////

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
///Se evalua si tiene 4 letras y 3 numeros

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


bool buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente)
{
    VehiculoPtr vehiculoDevolver;
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAux))
    {
        vehiculoDevolver=getVehiculo((RepartoPtr)getCabecera(listaAux));
        if(strcmp(getPatente(vehiculoDevolver),patente)==0)
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
    agregarLista(listaAux,getRepartos(centroLogistico,true));
    agregarLista(listaAux2,getRepartos(centroLogistico,false));
    while(!listaVacia(listaAux) && !listaVacia(listaAux2))
    {
        RepartoPtr repartoAux=(RepartoPtr)getCabecera(listaAux);
        RepartoPtr repartoAux2=(RepartoPtr)getCabecera(listaAux2);

        int *difFechas = calcularDiferenciaFechas(getFechaSalida(reparto),getFechaSalida(repartoAux));
        bool condicion = difFechas[0]==0 && personasIguales(getChofer(repartoAux),getChofer(reparto));

        int *difFechas2 = calcularDiferenciaFechas(getFechaSalida(reparto),getFechaSalida(repartoAux2));
        bool condicion2 = difFechas2[0]==0 && personasIguales(getChofer(repartoAux2),getChofer(reparto));
    ///Un chofer puede tener varios repartos asignados, pero no en el mismo día. Por eso,
    ///Condición: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
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

/// ///////////////////////////////////////////////FUNCIONES DE ORDENAMIENTO//////////////////////////////////////////////////////////////////////////

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
            ///NO REQUIERE CLÁUSULA "DEFAULT"
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
                //condición: "Si el apellido de la persona en j va después del de la persona en [i+salto]..."
            case 2:
                condicion = strcmp(getApellido(personas[i]),getApellido(personas[i+salto])) > 0;
            //condición: "Si el apellido de la persona en j va después del de la persona en [i+salto]..."
                break;
            case 3:
                condicion = strcmp(getApellido(personas[i]),getApellido(personas[i+salto])) >= 0;
                condicion = condicion && strcmp(getNombre(personas[i]),getNombre(personas[i+salto])) > 0;
            //condición: "Si el APELLIDO Y EL NOMBRE de la persona en j van después de los de la persona en [i+salto]..."
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
            //condición: "Si la marca de vehiculos[i] es posterior a la de vehiculos[i+salto]..."
                break;
            case 2:
                condicion = strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[i+salto])) >= 0;
                condicion = condicion && strcmp(getModelo(vehiculos[i]),getModelo(vehiculos[i+salto])) > 0;
            //condición: "Si la marca Y modelo de vehiculos[i] son posteriores a los de vehiculos[i+salto]..."
                break;
            case 3:
                condicion = getTipoVehiculo(vehiculos[i]) >= getTipoVehiculo(vehiculos[i+salto]);
                condicion = condicion && strcmp(getMarca(vehiculos[i]),getMarca(vehiculos[i+salto])) >= 0;
                condicion = condicion && strcmp(getModelo(vehiculos[i]),getModelo(vehiculos[i+salto])) > 0;
            //condición: "Si el tipo, la marca Y el modelo de vehiculos[i] son posteriores a los de vehiculos[i+salto]..."
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

void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    bool condicion;
    int *diferenciaFechaSalida;
    int *diferenciaFechaRetorno;
    int diferenciaNombres=0;
    int diferenciaApellidos=0;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

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
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en i+salto..."
                break;
            case 5:
                condicion = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[i+salto]))) > 0;
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en [i+salto]..."
                break;
            case 6:
                diferenciaApellidos = strcmp(getApellido(getChofer(repartos[i])),getApellido(getChofer(repartos[i+salto])));
                condicion = diferenciaApellidos >= 0;
                diferenciaNombres = strcmp(getNombre(getChofer(repartos[i])),getNombre(getChofer(repartos[i+salto])));
                condicion = condicion && diferenciaNombres > 0;
            //condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van después de los del chofer del reparto en [i+salto]..."
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
        agregarReparto(centroLogistico,repartos[i],esRepartoAbierto);
}
