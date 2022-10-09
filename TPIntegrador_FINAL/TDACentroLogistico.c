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
#include "Menus.h"


CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaClientes,ListaPtr listaChoferes,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados){
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);
    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaClientes=listaClientes;
    centroLogistico->listaChoferes=listaChoferes;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartosAbiertos=listaRepartosAbiertos;
    centroLogistico->listaRepartosCerrados=listaRepartosCerrados;
    return centroLogistico;
}

CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre){
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);
    ListaPtr listaPaquetes=crearLista();
    ListaPtr listaClientes=crearLista();
    ListaPtr listaChoferes=crearLista();
    ListaPtr listaRepartosAbiertos=crearLista();
    ListaPtr listaRepartosCerrados=crearLista();
    ListaPtr listaVehiculos=crearLista();
    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaClientes=listaClientes;
    centroLogistico->listaChoferes=listaChoferes;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartosAbiertos=listaRepartosAbiertos;
    centroLogistico->listaRepartosCerrados=listaRepartosCerrados;
    return centroLogistico;
}


CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico){
    destruirStringDinamico(centroLogistico->nombre);
    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaClientes=destruirLista(centroLogistico->listaClientes,true);
    centroLogistico->listaChoferes=destruirLista(centroLogistico->listaChoferes,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);
    centroLogistico->listaRepartosCerrados=destruirLista(centroLogistico->listaRepartosCerrados,true);
    free(centroLogistico);
    return NULL;
}
char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico){
    return centroLogistico->nombre;
}
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico){
    return centroLogistico->listaPaquetes;
}
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico){
    return centroLogistico->listaPersonas;
}
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico){
    return centroLogistico->listaVehiculos;
}
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
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
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre){
    strcpy(centroLogistico->nombre,nombre);
}
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes){
    centroLogistico->listaPaquetes=listaPaquetes;
}
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas){
    centroLogistico->listaPersonas=listaPersonas;
}
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos){
    centroLogistico->listaVehiculos=listaVehiculos;
}
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto){
	if(esRepartoAbierto)
		centroLogistico->listaRepartosAbiertos = repartos;
	else
		centroLogistico->listaRepartosCerrados = repartos;
}
void setClientes(CentroLogisticoPtr centroLogistico, ListaPtr clientes){
    centroLogistico->listaClientes=clientes;
}
void setChoferes(CentroLogisticoPtr centroLogistico, ListaPtr choferes){
    centroLogistico->listaChoferes=choferes;
}
void mostrarPaquetes(CentroLogisticoPtr centroLogistico){
    printf("\n\n\n /////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n\t\t LISTA DE PAQUETES: \n\n");
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n\n\n");
    int i=0;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getPaquetes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        printf("----------------------------------------------------------------------------\n");
        printf("\t\t PAQUETE NRO %d \n",i++);
        printf(" ----------------------------------------------------------------------------\n\n\n");
        mostrarPaquete(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
        printf("\n\n");
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
}

void mostrarClientes(CentroLogisticoPtr centroLogistico) {
    printf("\n\n\n /////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n\t\t LISTA DE CLIENTES: \n\n");
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n\n\n");
    int i=0;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getClientes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        printf("----------------------------------------------------------------------------\n");
        printf("\t\t CLIENTE NRO %d \n",i++);
        printf(" ----------------------------------------------------------------------------\n\n\n");
        mostrarPersona(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
        printf("\n\n");
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
}

void mostrarChoferes(CentroLogisticoPtr centroLogistico){
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n\t\t LISTA DE CHOFERES: \n\n");
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n\n\n");
    int i=0;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getChoferes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        printf("----------------------------------------------------------------------------\n");
        printf("\t\t CHOFER NRO %d \n",i++);
        printf(" ----------------------------------------------------------------------------\n\n\n");
        mostrarPersona(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
        printf("\n\n");
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
}

void mostrarVehiculos(CentroLogisticoPtr centroLogistico){
    printf("\n\n\n /////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n\t\t LISTA DE VEHICULOS: \n\n");
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n\n\n");
    int i=0;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getVehiculos(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        printf("----------------------------------------------------------------------------\n");
        printf("\t\t VEHICULO NRO %d \n",i++);
        printf(" ----------------------------------------------------------------------------\n\n\n");
        mostrarVehiculo(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
        printf("\n\n");
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
}

void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int i=0;
    printf("\n\n\n /////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n\t\t LISTA DE REPARTOS ");
    if(esRepartoAbierto)
        printf("ABIERTOS \n\n");
    else
        printf("CERRADOS \n\n");
    printf(" /////////////////////////////////////////////////////////////////////////////////// \n\n\n");
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getRepartos(centroLogistico,esRepartoAbierto));
    while(!listaVacia(listaAuxiliar)){
        printf(" ----------------------------------------------------------------------------\n");
        printf("\t\t REPARTO NRO %d \n",i++);
        printf("----------------------------------------------------------------------------\n\n\n");
        mostrarReparto(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
        printf("\n\n");
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
}
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado){
    switch(estado){
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
    for(int i=0;i<longitudLista(getPaquetes(centroLogistico));i++)
        if(getEstado(getDatoLista(getPaquetes(centroLogistico),i))==estado)
            printf("%d.",i),mostrarPaquete(getDatoLista(getPaquetes(centroLogistico),i)),printf("\n\n");
}

int buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuil){
    int i=0,posicionEncontrado=-1;
    PersonaPtr choferAuxiliar;
    char cuilAuxiliar[100];
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAuxiliar)){
        choferAuxiliar=getChofer(getCabecera(listaAuxiliar));
        strcpy(cuilAuxiliar,getCuil(getCuilPersona(choferAuxiliar)));
        if(strcmp(cuil, cuilAuxiliar) == 0)
            posicionEncontrado = i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente){
    int i=0,posicionEncontrado=-1;
    VehiculoPtr vehiculoAuxiliar;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getRepartos(centroLogistico,true));
    while(!listaVacia(listaAuxiliar)){
        vehiculoAuxiliar=getVehiculo(getCabecera(listaAuxiliar));
        if(strcmp(patente, getPatente(vehiculoAuxiliar)) == 0)
            posicionEncontrado=i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarVehiculo(CentroLogisticoPtr centroLogistico, char* patente){
    int i=0,posicionEncontrado=-1;
    VehiculoPtr vehiculoAuxiliar;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getVehiculos(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        vehiculoAuxiliar=getCabecera(listaAuxiliar);
        if(strcmp(patente, getPatente(vehiculoAuxiliar)) == 0)
            posicionEncontrado=i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarCliente(CentroLogisticoPtr centroLogistico, char* cuil){
    int i=0,posicionEncontrado=-1;
    PersonaPtr clienteAuxiliar;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getClientes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        clienteAuxiliar=getCabecera(listaAuxiliar);
        if(strcmp(cuil, getCuil(getCuilPersona(clienteAuxiliar))) == 0)
            posicionEncontrado=i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarChofer(CentroLogisticoPtr centroLogistico, char* cuil){
    int i=0,posicionEncontrado=-1;
    PersonaPtr choferAuxiliar;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getChoferes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        choferAuxiliar=getCabecera(listaAuxiliar);
        if(strcmp(cuil, getCuil(getCuilPersona(choferAuxiliar))) == 0)
            posicionEncontrado=i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarPaquete(CentroLogisticoPtr centroLogistico, int codigo){
    int i=0,posicionEncontrado=-1;
    PaquetePtr paqueteAuxiliar;
    ListaPtr listaAuxiliar=crearLista();
    agregarLista(listaAuxiliar,getPaquetes(centroLogistico));
    while(!listaVacia(listaAuxiliar)){
        paqueteAuxiliar=getCabecera(listaAuxiliar);
        if(codigo==getID(paqueteAuxiliar))
            posicionEncontrado=i;
        listaAuxiliar=getResto(listaAuxiliar);
        i++;
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    printf("\n\n");
    return posicionEncontrado;
}

int buscarReparto(CentroLogisticoPtr centroLogistico, int posicionSolicitada){
    int posicionEncontrado=-1;
        if(posicionSolicitada>=0 && posicionSolicitada<longitudLista(getRepartos(centroLogistico,true)))
            return posicionSolicitada;
    return posicionEncontrado;
}

int menuBusquedaPaqueteReparto(){
    int eleccion=0;
    fflush(stdin);
    printf("Buscar paquete mediante\n");
    printf("1. El indice\n");
    printf("2. El id\n");
    printf("Opcion: ");
    scanf("%d",&eleccion);
    fflush(stdin);
    return eleccion;
}

int menuBuscarPaqueteReparto(CentroLogisticoPtr centroLogistico, RepartoPtr reparto){
    int posicionEncontrado=-1,eleccion=0,ID=0,posicionSolicitada=0;
    eleccion=menuBusquedaPaqueteReparto(reparto);
    printf("Menu de busqueda de paquete\n");
    switch(eleccion){
    case 1:
        printf("Ingrese el indice para buscar: ");
        scanf("%d",&posicionSolicitada);
        if(posicionSolicitada>=0 && posicionSolicitada<longitudLista(getPaquetes(centroLogistico)))
            return posicionSolicitada;
        else
            return -1;
        break;
    case 2:
        printf("Ingrese ID para buscar:");
        scanf("%d",&ID);
        posicionEncontrado=buscarPaquete(centroLogistico,ID);
        return posicionEncontrado;
        break;
    default:
        printf("Seleccione una opcion valida\n");
        return -1;
        break;
    }
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
void agregarCliente(CentroLogisticoPtr centroLogistico,PersonaPtr cliente)
{
    agregarDatoLista(centroLogistico->listaClientes,(PersonaPtr)cliente);
}
void agregarChofer(CentroLogisticoPtr centroLogistico,PersonaPtr chofer)
{
    agregarDatoLista(centroLogistico->listaChoferes,(PersonaPtr)chofer);
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

PersonaPtr removerCliente(CentroLogisticoPtr centroLogistico, int posicion){
    return (PersonaPtr)removerDeLista(getClientes(centroLogistico),posicion);
}

PersonaPtr removerChofer(CentroLogisticoPtr centroLogistico, int posicion){
    return (PersonaPtr)removerDeLista(getChoferes(centroLogistico), posicion);
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
            int diferenciaDia = calcularDiferenciaFechasDias(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            int diferenciaHora = calcularDiferenciaFechasHora(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            int diferenciaMinutos = calcularDiferenciaFechasMinutos(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            bool condicion = diferenciaDia>0 || diferenciaHora>0 || diferenciaMinutos>0;
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
            int diferenciaDia = calcularDiferenciaFechasDias(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            int diferenciaHora = calcularDiferenciaFechasHora(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            int diferenciaMinutos = calcularDiferenciaFechasMinutos(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            bool condicion = diferenciaDia>0 || diferenciaHora>0 || diferenciaMinutos>0;
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
            int diferenciaDiaFS = calcularDiferenciaFechasDias(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            int diferenciaHoraFS = calcularDiferenciaFechasHora(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            int diferenciaMinutosFS = calcularDiferenciaFechasMinutos(getFechaSalida(repartos[j]),getFechaSalida(repartos[j+1]));
            bool condicionFS = diferenciaDiaFS>0 || diferenciaHoraFS>0 || diferenciaMinutosFS>0;

            int diferenciaDiaFR = calcularDiferenciaFechasDias(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            int diferenciaHoraFR = calcularDiferenciaFechasHora(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            int diferenciaMinutosFR = calcularDiferenciaFechasMinutos(getFechaRetorno(repartos[j]),getFechaRetorno(repartos[j+1]));
            bool condicionFR = diferenciaDiaFR>0 || diferenciaHoraFR>0 || diferenciaMinutosFR>0;
            bool condicion = condicionFS && condicionFR; //sumo la condicion de fechaRetorno
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
