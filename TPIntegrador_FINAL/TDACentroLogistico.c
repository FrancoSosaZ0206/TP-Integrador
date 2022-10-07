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
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro logístico con un nombre y listas vacías.
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    ListaPtr listaPaquetesAux = crearLista();
    ListaPtr listaPersonasAux = crearLista();
    ListaPtr listaVehiculosAux = crearLista();
    ListaPtr listaRepartosAbiertosAux = crearLista();
    ListaPtr listaRepartosCerradosAux = crearLista();
    centroLogistico->nombre=crearStringDinamico(nombre);
    centroLogistico->listaPaquetes = listaPaquetesAux;
    centroLogistico->listaPersonas = listaPersonasAux;
    centroLogistico->listaVehiculos = listaVehiculosAux;
    centroLogistico->listaRepartosAbiertos = listaRepartosAbiertosAux;
    centroLogistico->listaRepartosCerrados = listaRepartosCerradosAux;
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

ListaPtr getClientes(CentroLogisticoPtr centroLogistico){
    return centroLogistico->listaClientes;
}
ListaPtr getChoferes(CentroLogisticoPtr centroLogistico){
    return centroLogistico->listaChoferes;
}


void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre)
{
    strcpy(centroLogistico->nombre,nombre);
}
CentroLogisticoPtr setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes)
{
    centroLogistico->listaPaquetes=listaPaquetes;
}
CentroLogisticoPtr setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas)
{
    centroLogistico->listaPersonas=listaPersonas;
}
CentroLogisticoPtr setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos)
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

CentroLogisticoPtr setClientes(CentroLogisticoPtr centroLogistico, ListaPtr clientes){
    centroLogistico->listaClientes=clientes;
}
CentroLogisticoPtr setChoferes(CentroLogisticoPtr centroLogistico, ListaPtr choferes){
    centroLogistico->listaChoferes=choferes;
}

void mostrarPaquetes(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    printf("\nLISTA DE PAQUETES: \n\n");
    while(i!=longitudLista(getPaquetes(centroLogistico))){
        printf("%d. ",i+1);
        mostrarPaquete((PaquetePtr)getDatoLista(getPaquetes(centroLogistico),i++));
    }
}

void mostrarPersonas(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    int i=0;
    printf("\nLISTA DE PERSONAS: \n\n");
    while(!listaVacia(listaAux)){
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
    /*ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    int i=0;
    printf("\nLISTA DE CLIENTES: \n\n");
    while(!listaVacia(listaAux)){
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux)==false){
            printf("%d. ",i+1);
            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");*/
    for(int i=0;i<longitudLista(getClientes(centroLogistico));i++){
        printf("%d.",i);
        mostrarPersona((PersonaPtr)getDatoLista(getClientes(centroLogistico),i++));
    }
}
void mostrarChoferes(CentroLogisticoPtr centroLogistico) //busca y muestra solo las personas cuyo esChofer==true.
{
    /*ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    int i=0;
    printf("\nLISTA DE CHOFERES: \n\n");
    while(!listaVacia(listaAux)){
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux)){
            printf("%d. ",i+1);
            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");*/
    for(int i=0;i<longitudLista(getChoferes(centroLogistico));i++){
        printf("%d.",i);
        mostrarPersona((PersonaPtr)getDatoLista(getChoferes(centroLogistico),i++));
    }
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
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    ListaPtr listaAux=crearLista();
	if(esRepartoAbierto){
		listaAux = getRepartos(centroLogistico,true);
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
    }else{
		listaAux = getRepartos(centroLogistico,false);
        printf("\nLISTA DE REPARTOS CERRADOS: \n\n");
    }
    int i=0;
    while(i<longitudLista(listaAux)){
        printf("\t\tReparto Nro: %d\n\n",i);
        mostrarReparto(getDatoLista(listaAux,i++));
    }
    /*while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);
        mostrarReparto((RepartoPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
        i++;
    }
    listaAux=destruirLista(listaAux,false);*/
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
void cerrarRepartoCtroLogistico(CentroLogisticoPtr centroLogistico, int posicion)
{ ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion,true);
///Obtenemos cada paquete de la pila y le cambiamos el estado a 3: "entregado"
    PaquetePtr paqueteAux;
    int n=cantidadPaquetes(repartoACerrar);
    for(int i=0;i<n;i++)
    {
        paqueteAux = descargarPaquete(repartoACerrar);
        setEstado(paqueteAux,3);
    }
    for(int i=0;i<n;i++)
        cargarPaquete(repartoACerrar,paqueteAux);
///Agregamos el reparto a la lista de cerrados
    agregarReparto(centroLogistico,repartoACerrar,false);
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
void resetearRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    ListaPtr listaAux=getRepartos(centroLogistico,esRepartoAbierto);

    while(!listaVacia(listaAux))
    {
        RepartoPtr repartoEliminar=(RepartoPtr)removerDeLista(listaAux,0);
        repartoEliminar=cerrarReparto(repartoEliminar); //usamos cerrar reparto porque la destructora es una funcion privada.
    }
}

///FUNCIONES DE ORDENAMIENTO
void ordenarPorMarca(CentroLogisticoPtr centroLogistico)
{
    int n=longitudLista(getVehiculos(centroLogistico));

    VehiculoPtr vehiculos[n];
    VehiculoPtr vehiculoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        vehiculos[i]=removerVehiculo(centroLogistico,0);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            int diferenciaMarcas = strcmp(getMarca(vehiculos[j]),getMarca(vehiculos[j+1]));
            bool condicion = diferenciaMarcas > 0;
        //condicion de la bandera: "Si la marca de vehiculos[j] es posterior a la de vehiculos[j+1]..."
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
void ordenarPorID(CentroLogisticoPtr centroLogistico)
{
    int n=longitudLista(getPaquetes(centroLogistico));

    PaquetePtr paquetes[n];
    PaquetePtr paqueteAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        paquetes[i]=removerPaquete(centroLogistico,0);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            bool condicion = getID(paquetes[j]) > getID(paquetes[j+1]);
        //condicion de la bandera: "Si el ID de paquetes[j] es mayor al de paquetes[j+1]..."
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

void ordenarPorFechaSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            int *diferenciaFechas = calcularDiferenciaFechas(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            bool condicion = diferenciaFechas[0]>0 || diferenciaFechas[1]>0 || diferenciaFechas[2]>0;
        //condicion de la bandera: "Ya sea en dias, horas o minutos, si fechaDeSalida de reparto[j] es posterior a la de repartos[j+1]..."
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
void ordenarPorFechaRetorno(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            int *diferenciaFechas = calcularDiferenciaFechas(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            bool condicion = diferenciaFechas[0]>0 || diferenciaFechas[1]>0 || diferenciaFechas[2]>0;
        //condicion de la bandera: "Ya sea en dias, horas o minutos, si fechaDeRetorno de reparto[j] es posterior a la de repartos[j+1]..."
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
void ordenarPorFechaRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            int *diferenciaFechaSalida = calcularDiferenciaFechas(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            bool condicion = diferenciaFechaSalida[0]>0 || diferenciaFechaSalida[1]>0 || diferenciaFechaSalida[2]>0; //agrego la condicion de fechaSalida
            int *diferenciaFechaRetorno = calcularDiferenciaFechas(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            condicion = condicion && (diferenciaFechaRetorno[0]>0 || diferenciaFechaRetorno[1]>0 || diferenciaFechaRetorno[2]>0); //sumo la condicion de fechaRetorno
///condicion de la bandera: "Ya sea en dias, horas o minutos, si fechaDeSalida *Y* fechaDeRetorno de reparto[j] son posteriores a las de repartos[j+1]..."
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
void ordenarPorNombreChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            bool condicion = strcmp(getNombre(getChofer(repartos[j])),getNombre(getChofer(repartos[j+1]))) > 0;
        //condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
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
void ordenarPorApellidoChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            bool condicion = strcmp(getApellido(getChofer(repartos[j])),getApellido(getChofer(repartos[j+1]))) > 0;
        //condicion de la bandera: "Si el nombre del chofer del reparto en j va después del del reparto en j+1..."
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
void ordenarPorChoferRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    RepartoPtr repartos[n];
    RepartoPtr repartoAux;

    for(int i=0;i<n;i++) ///Primero, vaciamos la lista en el vector
        repartos[i]=removerReparto(centroLogistico,0,esRepartoAbierto);

///Luego, ordenamos el vector (m. burbuja)
    for(int i=0; i<n-1 ; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            int diferenciaApellidos = strcmp(getApellido(getChofer(repartos[j])),getApellido(getChofer(repartos[j+1])));
            bool condicion = diferenciaApellidos > 0;
            int diferenciaNombres = strcmp(getNombre(getChofer(repartos[j])),getNombre(getChofer(repartos[j+1])));
            condicion = condicion && diferenciaNombres > 0;
        //condicion de la bandera: "Si el APELLIDO Y NOMBRE del chofer del reparto en j van después de los del chofer del reparto en j+1..."
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
