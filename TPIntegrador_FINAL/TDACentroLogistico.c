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
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro log�stico con un nombre y listas vac�as.
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
    destruirStringDinamico(centroLogistico->nombre);

    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);
    centroLogistico->listaRepartosCerrados=destruirLista(centroLogistico->listaRepartosCerrados,true);

    free(centroLogistico);

    return NULL;
}

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
        listaAux=getResto(listaAux);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
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
        listaAux=getResto(listaAux);

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
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    ListaPtr listaAux=crearLista();
	if(esRepartoAbierto)
    {
		listaAux = getRepartos(centroLogistico,true);
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
    }
	else
    {
		listaAux = getRepartos(centroLogistico,false);
        printf("\nLISTA DE REPARTOS CERRADOS: \n\n");
    }

    mostrarRepartosPorFechaDeSalida(centroLogistico,esRepartoAbierto);
}
void mostrarRepartosPorFechaDeSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto) ///Solo funciona con repartos abiertos
{
    ordenarRepartos(centroLogistico,esRepartoAbierto,1);
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

    int i=0;

    printf("\nLISTA DE REPARTOS ORDENADOS POR FECHA DE SALIDA: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);

        mostrarRepartoSinPaquetes((RepartoPtr)getCabecera(listaAux));
        listaAux=getResto(listaAux);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}


void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado) //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().
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
        if(paqueteAux->estado==estado)
            mostrarPaquete(paqueteAux);
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
///NUEVO: Funciones de b�squeda de datos en la lista
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
        listaAux=getResto(listaAux);
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
        listaAux=getResto(listaAux);
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
        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo ac� para que no pase si no hay un match.

    return match;
}
//Funciones de agregado a la lista
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
//Funciones de inserci�n a la lista
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
//Funciones para eliminar de la lista
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
///NUEVA
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion)
{ ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion,true);
///Obtenemos cada paquete de la pila y le cambiamos el estado a 3: "entregado"
    PaquetePtr *paquetesAux;
    int n=cantidadPaquetes(repartoACerrar);
    for(int i=0;i<n;i++)
    {
        paquetesAux[i] = descargarPaquete(repartoACerrar);
        setEstado(paquetesAux[i],3);
    }
    for(int i=n;i>0;i--)
        cargarPaquete(repartoACerrar,paquetesAux[i]);
///Agregamos el reparto a la lista de cerrados
    agregarReparto(centroLogistico,repartoACerrar,false);
}

///////////////////////////////////////////////////FUNCIONES DE VALIDACION//////////////////////////////////////////////////////////////////////////

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
        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);

    return match;
}
bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona) // devuelve true si la persona que le ingresamos tiene el mismo cuil que una de las personas, false si no
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(personasIguales(personaAux,persona))
            match=true;
        listaAux=getResto(listaAux);
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
        listaAux=getResto(listaAux);
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
///Un chofer puede tener varios repartos asignados, pero no en el mismo d�a. Por eso,
///Condici�n: "si la fecha de salida **Y** el cuil del chofer del reparto recibido, ya existen en otro reparto..."
        if(condicion)
            match=true;
        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);

    return match;
}

///FUNCIONES DE ORDENAMIENTO
void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modo)
{
    int n=longitudLista(getPersonas(centroLogistico));

    PersonaPtr personas[n];
    PersonaPtr personaAux;

    bool condicion;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        personas[i]=removerPersona(centroLogistico,0);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            switch(modo)
            {
            case 1:
                condicion = strcmp(getNombre(personas[j]),getNombre(personas[j+1])) > 0;
                break;
                //condici�n: "Si el apellido de la persona en j va despu�s del de la persona en j+1..."
            case 2:
                condicion = strcmp(getApellido(personas[j]),getApellido(personas[j+1])) > 0;
            //condici�n: "Si el apellido de la persona en j va despu�s del de la persona en j+1..."
                break;
            case 3:
                condicion = strcmp(getApellido(personas[j]),getApellido(personas[j+1])) >= 0;
                condicion = condicion && strcmp(getNombre(personas[j]),getNombre(personas[j+1])) > 0;
            //condici�n: "Si el APELLIDO Y EL NOMBRE de la persona en j van despu�s de los de la persona en j+1..."
                break;
            }
            if(condicion)
            { //Hago un swap
                personaAux=personas[j];
                personas[j]=personas[j+1];
                personas[j+1]=personaAux;
            }
        }
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
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

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            switch(modo)
            {
            case 1:
                condicion = strcmp(getMarca(vehiculos[j]),getMarca(vehiculos[j+1])) > 0;
            //condici�n: "Si la marca de vehiculos[j] es posterior a la de vehiculos[j+1]..."
                break;
            case 2:
                condicion = strcmp(getMarca(vehiculos[j]),getMarca(vehiculos[j+1])) >= 0;
                condicion = condicion && strcmp(getModelo(vehiculos[j]),getModelo(vehiculos[j+1])) > 0;
            //condici�n: "Si la marca Y modelo de vehiculos[j] son posteriores a los de vehiculos[j+1]..."
                break;
            }
            if(condicion)
            { //Hago un swap
                vehiculoAux=vehiculos[j];
                vehiculos[j]=vehiculos[j+1];
                vehiculos[j+1]=vehiculoAux;
            }
        }
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
        agregarVehiculo(centroLogistico,vehiculos[i]);
}
void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modoOrden)
{
    int n=longitudLista(getPaquetes(centroLogistico));

    PaquetePtr paquetes[n];
    PaquetePtr paqueteAux;

    bool condicion;
    int *diferenciaFechas;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        paquetes[i]=removerPaquete(centroLogistico,0);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            switch(modoOrden)
            {
            case 1:
                condicion = getID(paquetes[j]) > getID(paquetes[j+1]);
            //condicion de la bandera: "Si el ID de paquetes[j] es mayor al de paquetes[j+1]..."
                break;
            case 2:
                diferenciaFechas=calcularDiferenciaFechas(getFechaEntrega(paquetes[j]),getFechaEntrega(paquetes[j+1]));
                condicion = diferenciaFechas[0]>0 || diferenciaFechas[1]>0 || diferenciaFechas[2]>0;
            //condicion de la bandera: "Si la fecha de entrega de paquetes[j] es mayor a la de paquetes[j+1]..."
                break;
            case 3:
                condicion = getEstado(paquetes[j]) > getEstado(paquetes[j+1]);
                break;
        ///NO REQUIERE CL�USULA "DEFAULT"
            }
            if(condicion)
            { //Hago un swap
                paqueteAux=paquetes[j];
                paquetes[j]=paquetes[j+1];
                paquetes[j+1]=paqueteAux;
            }
        }
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
        agregarPaquete(centroLogistico,paquetes[i]);
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

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            switch(modo)
            {
            case 1:
                diferenciaFechaSalida = calcularDiferenciaFechas(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
                condicion = diferenciaFechaSalida[0]>0 || diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0;
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida de reparto[j] es posterior a la de repartos[j+1]..."
                break;
            case 2:
                diferenciaFechaRetorno = calcularDiferenciaFechas(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
                condicion = diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0;
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeRetorno de reparto[j] es posterior a la de repartos[j+1]..."
                break;
            case 3:
                diferenciaFechaSalida = calcularDiferenciaFechas(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
                condicion = diferenciaFechaSalida[0]>0 || diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0; //agrego la condicion de fechaSalida
                diferenciaFechaRetorno = calcularDiferenciaFechas(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
                condicion = condicion && (diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0); //sumo la condicion de fechaRetorno
            //condicion: "Ya sea en dias, horas o minutos, si fechaDeSalida *Y* fechaDeRetorno de reparto[j] son posteriores a las de repartos[j+1]..."
                break;
            case 4:
                condicion = strcmp(getNombre(getChofer(repartos[j])),getNombre(getChofer(repartos[j+1]))) > 0;
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va despu�s del del reparto en j+1..."
                break;
            case 5:
                condicion = strcmp(getApellido(getChofer(repartos[j])),getApellido(getChofer(repartos[j+1]))) > 0;
            //condicion de la bandera: "Si el nombre del chofer del reparto en j va despu�s del del reparto en j+1..."
                break;
            case 6:
                diferenciaApellidos = strcmp(getApellido(getChofer(repartos[j])),getApellido(getChofer(repartos[j+1])));
                condicion = diferenciaApellidos >= 0;
                diferenciaNombres = strcmp(getNombre(getChofer(repartos[j])),getNombre(getChofer(repartos[j+1])));
                condicion = condicion && diferenciaNombres > 0;
            //condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van despu�s de los del chofer del reparto en j+1..."
                break;
            }
            if(condicion)
            { //Hago un swap
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
///Finalmente, agregamos nuevamente los elementos ordenados a la lista
    for(int i=0; i<n; i++)
        agregarReparto(centroLogistico,repartos[i],esRepartoAbierto);
}
