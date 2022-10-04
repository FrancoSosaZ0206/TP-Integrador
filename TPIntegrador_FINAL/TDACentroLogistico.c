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


CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartos)
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);

    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaPersonas=listaPersonas;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartos=listaRepartos;

    return centroLogistico;
}
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro logístico con un nombre y listas vacías.
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));

    centroLogistico->nombre=crearStringDinamico(nombre);
///nota: destruir el string original luego de hacer esto y ver si funca
///Si eso funca, agergar un parámetro bool más que indique si el string recibido es dinamico o estático, así no destruimos el string aunque sea estatico.

    centroLogistico->listaPaquetes=crearLista();
    centroLogistico->listaPersonas=crearLista();
    centroLogistico->listaVehiculos=crearLista();
    centroLogistico->listaRepartos=crearLista();

    return centroLogistico;
}
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    destruirStringDinamico(centroLogistico->nombre);

    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartos=destruirLista(centroLogistico->listaRepartos,true);

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
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaRepartos;
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
void setRepartos(CentroLogisticoPtr centroLogistico,ListaPtr listaRepartos)
{
    centroLogistico->listaRepartos=listaRepartos;
}

void mostrarPaquetes(CentroLogisticoPtr centroLogistico)
{
    /*
    ¿CUÁL ERA EL PROBLEMA?

    yo tenía esto:
    while(!listaVacia(getPaquetes(centroLogistico)))

    al usar eso, el while chequeaba constantemente si la lista estaba
    vacía o no, pero NUNCA IBA A ESTAR VACÍA PORQUE ESTABA CHEQUEANDO
    LA LISTA ORIGINAL, NO LA AUXILIAR.
    */

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));

    int i=0;

    printf("\nLISTA DE PAQUETES: \n\n");
    while(!listaVacia(listaAux)) //getPaquetes(centroLogistico)
    {
        printf("%d. ",i+1);
        mostrarPaquete((PaquetePtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarPersonas(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE PERSONAS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);
        mostrarPersona((PersonaPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarClientes(CentroLogisticoPtr centroLogistico) //busca y muestra solo las personas cuyo esChofer==false.
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE CLIENTES: \n\n");
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux)==false)
        {
            printf("%d. ",i+1);

            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarChoferes(CentroLogisticoPtr centroLogistico) //busca y muestra solo las personas cuyo esChofer==true.
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE CHOFERES: \n\n");
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux))
        {
            printf("%d. ",i+1);

            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

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
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarRepartos(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));

    int i=0;

    printf("\nLISTA DE REPARTOS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);

        mostrarReparto((RepartoPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarRepartosPorFechaDeSalida(CentroLogisticoPtr centroLogistico)
{
    ordenarPorFechaDeSalidaRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));

    int i=0;

    printf("\n LISTA DE REPARTOS POR FECHA DE SALIDA: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);

        mostrarRepartoSinPaquetes((RepartoPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

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
///NUEVO: Funciones de búsqueda de datos en la lista
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
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

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
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
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
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}
///////////////////////////////////////////////////FUNCIONES DE VALIDACION//////////////////////////////////////////////////////////////////////////

bool cuilExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona) // devuelve true si la persona que le ingresamos tiene el mismo cuil que una de las personas, false si no
{

    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {

        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(strcmp(getCuil(getCuilPersona(personaAux)),getCuil(persona))==0)
        {
            match=true;
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}
bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto)
{
    bool match=false;
    RepartoPtr repartoAux;

    bool condicion;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico));
    while(!listaVacia(listaAux))
    {
        repartoAux=(RepartoPtr)getCabecera(listaAux);

        condicion=calcularDiferenciaFechas(getFechaSalida(repartoAux),getFechaSalida(reparto))==0;
        condicion = condicion && strcmp(getCuil(getCuilPersona(repartoAux)),getCuil(getCuilPersona(reparto)))==0;

        if(condicion)
            match=true;

        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

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
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto)
{
    agregarDatoLista(centroLogistico->listaRepartos,(RepartoPtr)reparto);
}
//Funciones de inserción a la lista
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
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion)
{
    return insertarDatoLista(centroLogistico->listaRepartos,(RepartoPtr)reparto,posicion);
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
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (RepartoPtr)removerDeLista(centroLogistico->listaRepartos,posicion);
}
//Funciones para resetear listas
///Precondición: debe existir una funcion de destruccion para cada tipo de dato.
void resetearPaquetes(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaPaquetes))
    {
        PaquetePtr paqueteEliminar=(PaquetePtr)removerDeLista(centroLogistico->listaPaquetes,0);
        paqueteEliminar=destruirPaquete(paqueteEliminar);
    }
}
void resetearPersonas(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaPersonas))
    {
        PersonaPtr personaEliminar=(PersonaPtr)removerDeLista(centroLogistico->listaPersonas,0);
        personaEliminar=destruirPersona(personaEliminar);
    }
}
void resetearVehiculos(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaVehiculos))
    {
        VehiculoPtr vehiculoEliminar=(VehiculoPtr)removerDeLista(centroLogistico->listaVehiculos,0);
        vehiculoEliminar=destruirVehiculo(vehiculoEliminar);
    }
}
void resetearRepartos(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaRepartos))
    {
        RepartoPtr repartoEliminar=(RepartoPtr)removerDeLista(centroLogistico->listaRepartos,0);
        repartoEliminar=cerrarReparto(repartoEliminar); //usamos cerrar reparto porque la destructora es una funcion privada.
    }
}

///FUNCIONES DE ORDENAMIENTO
void ordenarPorFechaDeSalidaRepartos(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int longitudListaRepartos=longitudLista(listaRepartos);
    RepartoPtr repartos[longitudLista(listaRepartos)];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<longitudListaRepartos-1 ; i++){
        for(int j=i; j<longitudListaRepartos-1; j++){
            if(repartos[j]->fechaSalida > repartos[j+1]->fechaSalida){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<longitudListaRepartos; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorFechaDeRetornoRepartos(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int longitudListaRepartos=longitudLista(listaRepartos);
    RepartoPtr repartos[longitudLista(listaRepartos)];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<longitudListaRepartos-1 ; i++){
        for(int j=i; j<longitudListaRepartos-1; j++){
            if(repartos[j]->fechaRetorno > repartos[j+1]->fechaRetorno){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<longitudListaRepartos; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorFechaDeSalidaRetornoRepartos(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int longitudListaRepartos=longitudLista(listaRepartos);
    RepartoPtr repartos[longitudLista(listaRepartos)];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<longitudListaRepartos-1 ; i++){
        for(int j=i; j<longitudListaRepartos-1; j++){
            if(repartos[j]->fechaSalida > repartos[j+1]->fechaSalida && repartos[j]->fechaRetorno > repartos[j+1]->fechaRetorno){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<longitudListaRepartos; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorNombreRepartosChoferes(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
            if(strcmp(getNombre(personas[j]), getNombre(personas[j+1]))==0){
                personaAux=personas[j];
                personas[j]=personas[j+1];
                personas[j+1]=personaAux;
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
void ordenarPorApellidoRepartosChoferes(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
            if(strcmp(getApellido(personas[j]), getApellido(personas[j+1]))==0){
                personaAux=personas[j];
                personas[j]=personas[j+1];
                personas[j+1]=personaAux;
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
void ordenarPorNombreApellidoRepartosChoferes(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
           if(strcmp(getNombre(personas[j]), getNombre(personas[j+1]))==0){
               if(strcmp(getApellido(personas[j]), getApellido(personas[j+1]))==0){
                    personaAux=personas[j];
                    personas[j]=personas[j+1];
                    personas[j+1]=personaAux;
                }
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
