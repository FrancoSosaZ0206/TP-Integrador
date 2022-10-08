#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "Pila.h"
#include "TDACentroLogistico.h"
#include "TDACuil.h"
#include "TDADomicilio.h"
#include "TDAFechaYHora.h"
#include "TDANodo.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDARepartos.h"
#include "TDAVehiculo.h"
#include "Files.h"

///*************************************************************************************************************

///                  Estructuras Especiales (PRIVADAS, solo usar en las funciones de este archivo)

//Ayudín - ¿Cuánto espacio ocupan 50 caracteres?

//  1234567891234567892234567893234567894234567895

/*
typedef struct f
{
    ;
} f;
typedef f* fPtr; <<<ESTO NO HAY QUE USARLO, DIRECTAMENTE PASAMOS EL ADDRESS DE LA STRUCT CON &
*/

///*************************************************************************************************************

///                                             FUNCIONES PRIVADAS/INTERNAS

///Getters
//  Cuil
char *fgetCuil(fCuilPtr pfcuil)
{
    return pfcuil->cuil;
}
//  Domicilio
char *fgetCalle(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->calle;
}
int fgetAltura(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->altura;
}
char *fgetLocalidad(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->localidad;
}
//  Fecha
int fgetHora(fFechaPtr pffecha)
{
    return pffecha->hora;
}
int fgetMinuto(fFechaPtr pffecha)
{
    return pffecha->minuto;
}
//  Persona
char *fgetNombre(fPersonaPtr pfpersona)
{
    return pfpersona->nombre;
}
char *fgetApellido(fPersonaPtr pfpersona)
{
    return pfpersona->apellido;
}
fDomicilioPtr fgetDomicilio(fPersonaPtr pfpersona)
{
    return &pfpersona->domicilio;
}
fCuilPtr fgetCuilPersona(fPersonaPtr pfpersona)
{
    fCuilPtr pfcuil = &pfpersona->cuil;
    return pfcuil;
}
bool fgetEsChofer(fPersonaPtr pfpersona)
{
    return pfpersona->esChofer;
}
//  Paquete
int fgetID(fPaquetePtr pfpaquete)
{
    return pfpaquete->ID;
}
int fgetAncho(fPaquetePtr pfpaquete)
{
    return pfpaquete->ancho;
}
int fgetAlto(fPaquetePtr pfpaquete)
{
    return pfpaquete->alto;
}
int fgetLargo(fPaquetePtr pfpaquete)
{
    return pfpaquete->largo;
}
int fgetPeso(fPaquetePtr pfpaquete)
{
    return pfpaquete->peso;
}
fDomicilioPtr fgetDirRetiro(fPaquetePtr pfpaquete)
{
    return &pfpaquete->dirRetiro;
}
fDomicilioPtr fgetDirEntrega(fPaquetePtr pfpaquete)
{
    return &pfpaquete->dirEntrega;
}
fFechaPtr fgetFechaEntrega(fPaquetePtr pfpaquete)
{
    return &pfpaquete->fechaEntrega;
}
int fgetEstado(fPaquetePtr pfpaquete)
{
    return pfpaquete->estado;
}
//  Vehiculo
int fgetTipoVehiculo(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->tipo;
}
char *fgetMarca(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->marca;
}
char *fgetModelo(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->modelo;
}
char *fgetPatente(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->patente;
}
//  Reparto
fPersonaPtr fgetChofer(fRepartoPtr pfreparto)
{
    return &pfreparto->chofer;
}
fVehiculoPtr fgetVehiculo(fRepartoPtr pfreparto)
{
    return &pfreparto->vehiculo;
}
fFechaPtr fgetFechaSalida(fRepartoPtr pfreparto)
{
    return &pfreparto->fechaSalida;
}
fFechaPtr fgetFechaRetorno(fRepartoPtr pfreparto)
{
    return &pfreparto->fechaRetorno;
}

///este si retorna puntero x q almacenamos los paquetes como array.
fPaquete *fgetPaquetesReparto(fRepartoPtr pfreparto)
{
    return pfreparto->paquetes;
}

///Setters
/**
Se puede setear toda la estructura de una.
Postcondición: si setParaGuardar == true, setea cuil en fCuil.
               De lo contrario, hace el proceso inverso (ayuda a la hora de abrir un archivo).
*/
void fsetCuil(fCuilPtr fcuil,CuilPtr cuil,bool setParaGuardar)
{
    if(setParaGuardar)
        strcpy(fcuil->cuil,getCuil(cuil));
    else ///asumimos que la estructura está vacía y la creamos.
        cuil=crearCuil(fgetCuil(fcuil));
}
void fsetDomicilio(fDomicilioPtr pfdomicilio,DomicilioPtr domicilio,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        strcpy(pfdomicilio->calle,getCalle(domicilio));
        pfdomicilio->altura=getAltura(domicilio);
        strcpy(pfdomicilio->localidad,getLocalidad(domicilio));
    }
    else ///asumimos que la estructura está vacía y la creamos.
        domicilio=crearDomicilio(fgetCalle(pfdomicilio),fgetAltura(pfdomicilio),fgetLocalidad(pfdomicilio));
}
void fsetFecha(fFechaPtr pffecha,FechaPtr fecha,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pffecha->hora=getHora(fecha);
        pffecha->minuto=getMinuto(fecha);
    }
     ///asumimos que la estructura está vacía y la creamos.
}
void fsetPersona(fPersonaPtr pfpersona,PersonaPtr persona,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        strcpy(pfpersona->nombre,getNombre(persona));
        strcpy(pfpersona->apellido,getApellido(persona));

        fsetDomicilio(fgetDomicilio(pfpersona),getDomicilio(persona),true);
        fsetCuil(fgetCuilPersona(pfpersona),getCuilPersona(persona),true); ///MUCHO OJO: TODAVIA NO SE CAMBIO EL NOMBRE ORIGINAL, SE DEBE HACER ESO PARA QUE FUNCIONE.

        pfpersona->esChofer=getEsChofer(persona);
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr domicilio=0;
        CuilPtr cuil=0;
        fsetDomicilio(fgetDomicilio(pfpersona),domicilio,false);
        fsetCuil(fgetCuilPersona(pfpersona),cuil,false);
        persona=crearPersona(fgetNombre(pfpersona),fgetApellido(pfpersona),domicilio,cuil,fgetEsChofer(pfpersona));
    }
}
void fsetPaquete(fPaquetePtr pfpaquete,PaquetePtr paquete,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pfpaquete->ID=getID(paquete);
        pfpaquete->ancho=getAncho(paquete);
        pfpaquete->alto=getAlto(paquete);
        pfpaquete->largo=getLargo(paquete);
        pfpaquete->peso=getPeso(paquete);

        fsetDomicilio(fgetDirRetiro(pfpaquete),getDirRetiro(paquete),true);
        fsetDomicilio(fgetDirEntrega(pfpaquete),getDirEntrega(paquete),true);
        fsetFecha(fgetFechaEntrega(pfpaquete),getFechaEntrega(paquete),true);

        pfpaquete->estado=getEstado(paquete);
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr dirRetiro=0;
        DomicilioPtr dirEntrega=0;
        FechaPtr fechaEntrega=0;

        fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

        //paquete=crearPaquete(fgetID(pfpaquete),fgetAncho(pfpaquete),fgetAlto(pfpaquete),fgetLargo(pfpaquete),fgetPeso(pfpaquete),dirRetiro,dirEntrega,fechaEntrega,fgetEstado(pfpaquete));
    }
}
void fsetVehiculo(fVehiculoPtr pfvehiculo,VehiculoPtr vehiculo,bool setParaGuardar){
    if(setParaGuardar){
        pfvehiculo->tipo=getTipoVehiculo(vehiculo);
        strcpy(pfvehiculo->marca,getMarca(vehiculo));
        strcpy(pfvehiculo->modelo,getModelo(vehiculo));
        strcpy(pfvehiculo->patente,getPatente(vehiculo));
    }else ///asumimos que la estructura está vacía y la creamos.
        vehiculo=crearVehiculo(fgetTipoVehiculo(pfvehiculo),fgetMarca(pfvehiculo),fgetModelo(pfvehiculo),fgetPatente(pfvehiculo));
}
RepartoPtr fsetReparto(fRepartoPtr pfreparto,RepartoPtr reparto,bool setParaGuardar){
    int n=0;
    PaquetePtr paqueteAux=0;
    if(setParaGuardar){
        fsetPersona(fgetChofer(pfreparto),getChofer(reparto),true);
        fsetVehiculo(fgetVehiculo(pfreparto),getVehiculo(reparto),true);
        fsetFecha(fgetFechaSalida(pfreparto),getFechaSalida(reparto),true);
        fsetFecha(fgetFechaRetorno(pfreparto),getFechaRetorno(reparto),true);
        n=CantidadEntregas(reparto);
        pfreparto->tamanioPilaPaq = n;
        for(int i=0;i<n;i++){
            paqueteAux = getDatoLista(getListaPaquetesReparto(reparto),i);
            fsetPaquete(&pfreparto->paquetes[i],paqueteAux,true);
        }
        return 0;
    }else{ ///asumimos que la estructura está vacía y la creamos.
        PersonaPtr chofer=0;
        VehiculoPtr vehiculo=0;
        FechaPtr fechaSalida=0;
        FechaPtr fechaRetorno=0;
        fsetPersona(fgetChofer(pfreparto),chofer,false);
        fsetVehiculo(fgetVehiculo(pfreparto),vehiculo,false);
        fsetFecha(fgetFechaSalida(pfreparto),fechaSalida,false);
        fsetFecha(fgetFechaRetorno(pfreparto),fechaRetorno,false);
        ListaPtr paquetes = crearLista();
        n=pfreparto->tamanioPilaPaq;
        ///lo hacemos al revés para mantener el orden original de la pila.
        for(int i=0;i<n;i++){
            fsetPaquete(&pfreparto->paquetes[i],paqueteAux,false);
            agregarDatoLista(paquetes,(PaquetePtr)paqueteAux);
        }
        RepartoPtr reparto = crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
        return reparto;
    }
    paqueteAux = 0;
}

/*
VehiculoPtr pruebaDePasaje(){
    fVehiculo vehiculoEstatico;
    vehiculoEstatico.tipo=3;
    strcpy(vehiculoEstatico.marca,"Mercedes");
    strcpy(vehiculoEstatico.modelo,"Actros");
    strcpy(vehiculoEstatico.patente,"12JKU89");
    VehiculoPtr vehiculoDinamico;
    vehiculoDinamico=crearVehiculo(vehiculoEstatico.tipo,vehiculoEstatico.marca,vehiculoEstatico.modelo,vehiculoEstatico.patente);

    fVehiculoPtr vehiculoEstatico=(fVehiculoPtr)obtenerMemoria(sizeof(fVehiculo));
    vehiculoEstatico=crearVehiculo(3,"Mercedes","Actros","19JKU89");
    VehiculoPtr vehiculoDinamico=crearVehiculo(getTipoVehiculo(vehiculoEstatico),getMarca(vehiculoEstatico),getModelo(vehiculoEstatico),getPatente(vehiculoEstatico));
    FILE* a;
    a=fopen("Pruebas.bin","wb");
    fwrite(&vehiculoEstatico,sizeof(fVehiculo),1,a);
    fclose(a);
    free(vehiculoEstatico);

    fVehiculo vehiculoEstatico;
    setTipoVehiculo(&vehiculoEstatico,3);
    setMarca(&vehiculoEstatico,"Mercedes");
    setModelo(&vehiculoEstatico,"Actros");
    setPatente(&vehiculoEstatico,"10JKU89");
    VehiculoPtr vehiculoDinamico = crearVehiculo(getTipoVehiculo(&vehiculoEstatico),getMarca(&vehiculoEstatico),getModelo(&vehiculoEstatico),getPatente(&vehiculoEstatico));
    FILE* a;
    a=fopen("Pruebas.bin","wb");
    fwrite(&vehiculoEstatico,sizeof(fVehiculo),1,a);
    fclose(a);
    return vehiculoDinamico;
}

VehiculoPtr pruebaDeLectura(){
    fVehiculo vehiculoEstatico;
    FILE* a;
    a=fopen("Pruebas.bin","rb");
    fread(&vehiculoEstatico,sizeof(fVehiculo),1,a);
    fclose(a);
    mostrarVehiculo(&vehiculoEstatico);
}
*/

///*************************************************************************************************************

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ


//Escritura
//Precondición: La variable estructura / lista que se pase deberá haber sido creada previamente.
//Postcondición: se guarda los contenidos de la estructura / lista en un archivo dedicado al tipo de estructura / lista.
//Devuelve true si se pudo guardar, false de lo contrario (if archivo != 0)
//  datos / estructuras individuales
bool guardarCuil(CuilPtr cuil)
{
    FILE *archivo = fopen("Cuil.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fCuil fcuil;
        fsetCuil(&fcuil,cuil,true);

        fwrite(&fcuil,sizeof(fCuil),1,archivo);
        fclose(archivo);
        return true;
    }
}
bool guardarDomicilio(DomicilioPtr domicilio)
{
    FILE *archivo = fopen("Domicilio.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fDomicilio fdomicilio;
        fsetDomicilio(&fdomicilio,domicilio,true);

        fwrite(&fdomicilio,sizeof(fDomicilio),1,archivo);
        fclose(archivo);
        return true;
    }
}
bool guardarFecha(FechaPtr fecha)
{
    FILE *archivo = fopen("Fecha.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fFecha ffecha;
        fsetFecha(&ffecha,fecha,true);

        fwrite(&ffecha,sizeof(fFecha),1,archivo);
        fclose(archivo);
        return true;
    }
}
bool guardarPersona(PersonaPtr persona)
{
    FILE *archivo = fopen("Persona.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fPersona fpersona;
        fsetPersona(&fpersona,persona,true);

        fwrite(&fpersona,sizeof(fPersona),1,archivo);
        fclose(archivo);
        return true;
    }
}


bool guardarPaquete(PaquetePtr paquete)
{
    FILE *archivo = fopen("Paquete.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fPaquete fpaquete;
        fsetPaquete(&fpaquete,paquete,true);

        fwrite(&fpaquete,sizeof(fPaquete),1,archivo);
        fclose(archivo);
        return true;
    }
}
bool guardarVehiculo(VehiculoPtr vehiculo)
{
    FILE *archivo = fopen("Vehiculo.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fVehiculo fvehiculo;
        fsetVehiculo(&fvehiculo,vehiculo,true);

        fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);
        fclose(archivo);
        return true;
    }
}
bool guardarReparto(RepartoPtr reparto)
{
    FILE *archivo = fopen("Reparto.txt","w");
    if(archivo==0)
        return false;
    else
    {
        fReparto freparto;
        fsetReparto(&freparto,reparto,true);

        fwrite(&freparto,sizeof(fReparto),1,archivo);
        fclose(archivo);
        return true;
    }
}
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
///Postcondición: LA CANTIDAD QUE ELEMENTOS QUE SE PASAN DEBEN TENERSE EN CUENTA AL USAR LAS CONTRAPARTES DE APERTURA
bool guardarCuils(CuilPtr *cuils,int cantidad)
{
    FILE *archivo = fopen("Cuils por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fCuil fcuil;

        for(int i=0;i<cantidad;i++)
        {
            fsetCuil(&fcuil,*(cuils+i),true);
            fwrite(&fcuil,sizeof(fCuil),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarDomicilios(DomicilioPtr *domicilios,int cantidad)
{
    FILE *archivo = fopen("Domicilios por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fDomicilio fdomicilio;

        for(int i=0;i<cantidad;i++)
        {
            fsetDomicilio(&fdomicilio,*(domicilios+i),true);
            fwrite(&fdomicilio,sizeof(fDomicilio),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarFechas(FechaPtr *fechas,int cantidad)
{
    FILE *archivo = fopen("Fechas por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fFecha ffecha;

        for(int i=0;i<cantidad;i++)
        {
            fsetFecha(&ffecha,*(fechas+i),true);
            fwrite(&ffecha,sizeof(fFecha),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarPersonas(PersonaPtr *personas,int cantidad)
{
    FILE *archivo = fopen("Personas por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fPersona fpersona;

        for(int i=0;i<cantidad;i++)
        {
            fsetPersona(&fpersona,*(personas+i),true);
            fwrite(&fpersona,sizeof(fPersona),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarPaquetes(PaquetePtr *paquetes,int cantidad)
{
    FILE *archivo = fopen("Paquetes por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fPaquete fpaquete;

        for(int i=0;i<cantidad;i++)
        {
            fsetPaquete(&fpaquete,*(paquetes+i),true);
            fwrite(&fpaquete,sizeof(fPaquete),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarVehiculos(VehiculoPtr *vehiculos,int cantidad)
{
    FILE *archivo = fopen("Vehiculos por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fVehiculo fvehiculo;

        for(int i=0;i<cantidad;i++)
        {
            fsetVehiculo(&fvehiculo,*(vehiculos+i),true);
            fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarRepartos(RepartoPtr *repartos,int cantidad)
{
    FILE *archivo = fopen("Repartos por Defecto.txt","w");


    if(archivo==0)
        return false;
    else
    {
    ///guardamos la cantidad que son, para que al abrir sepa donde parar de buscar
        fwrite(&cantidad,sizeof(int),1,archivo);

        fReparto freparto;

        for(int i=0;i<cantidad;i++)
        {
            fsetReparto(&freparto,*(repartos+i),true);
            fwrite(&freparto,sizeof(fReparto),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
//  listas de datos / estructuras
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Personas.txt","w");

    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getPersonas(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fPersona fpersona;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getPersonas(centroLogistico));

        while(!listaVacia(listaAux))
        {
            PersonaPtr personaAux = (PersonaPtr)getCabecera(listaAux);
            fsetPersona(&fpersona,personaAux,true);

            fwrite(&fpersona,sizeof(fPersona),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}

bool guardarListaClientes(CentroLogisticoPtr centroLogistico){
    FILE *archivo = fopen("Lista de Clientes.txt","w");
    if(archivo==0)
        return false;
    else{
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n;
        n=longitudLista(getClientes(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);
        fPersona fpersona;
        for(int i=0;i<longitudLista(getClientes(centroLogistico));i++){
            PersonaPtr personaAux=getDatoLista(getClientes(centroLogistico),i);
            fsetPersona(&fpersona,personaAux,true);
            fwrite(&fpersona,sizeof(fPersona),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}

bool guardarListaChoferes(CentroLogisticoPtr centroLogistico){
    FILE *archivo = fopen("Lista de Choferes.txt","w");
    if(archivo==0)
        return false;
    else{
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n=longitudLista(getChoferes(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);
        fPersona fpersona;
        for(int i=0;i<longitudLista(getChoferes(centroLogistico));i++){
            PersonaPtr personaAux=getDatoLista(getChoferes(centroLogistico),i);
            fsetPersona(&fpersona,personaAux,true);
            fwrite(&fpersona,sizeof(fPersona),1,archivo);
        }
        fclose(archivo);
        return true;
    }
}
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","w");

    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getPaquetes(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getPaquetes(centroLogistico));

        while(!listaVacia(listaAux)){
            PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
            fsetPaquete(&fpaquete,paqueteAux,true);

            fwrite(&fpaquete,sizeof(fPaquete),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Vehiculos.txt","w");

    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getVehiculos(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getVehiculos(centroLogistico));

        while(!listaVacia(listaAux))
        {
            VehiculoPtr vehiculoAux = (VehiculoPtr)getCabecera(listaAux);
            fsetVehiculo(&fvehiculo,vehiculoAux,true);

            fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Lista de Repartos Abiertos.txt","w");
	else
		archivo = fopen("Lista de Repartos Cerrados.txt","w");

    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n; ///guardamos primero la cantidad de elementos de la lista
		if(esRepartoAbierto)
			n = longitudLista(getRepartos(centroLogistico,true));
		else
			n = longitudLista(getRepartos(centroLogistico,false));

        fwrite(&n,sizeof(int),1,archivo);

        fReparto freparto;
        ListaPtr listaAux = crearLista();
        if(esRepartoAbierto)
			agregarLista(listaAux,getRepartos(centroLogistico,true));
		else
			agregarLista(listaAux,getRepartos(centroLogistico,false));

        while(!listaVacia(listaAux))
        {
            RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
            fsetReparto(&freparto,repartoAux,true);

            fwrite(&freparto,sizeof(fReparto),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
//  general
bool guardarTodo(CentroLogisticoPtr centroLogistico) //implementacion: llamará a las otras funciones de guardado
{
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","w");
    //a diferencia de las funciones anteriores, usamos una bandera para juntar al conjugado
    bool res = true;
    if(archivo==0)
        res=false;
    else{
        char temp[100];
        strcpy(temp,getNombreCentroLogistico(centroLogistico));
        //2 más que el original: 1 x el '\0', y 2 x el caracter que le agregaremos.
        int longStr=strlen(temp) + 2;
        char nombreCtroLog[longStr];
        strcpy(nombreCtroLog,temp);
        nombreCtroLog[longStr-1]='\n'; ///le agregamos el caracter especial para la apertura.
    ///Guardamos el nombre del centro logistico en un archivo aparte
        fwrite(nombreCtroLog,sizeof(char),longStr,archivo);
        fclose(archivo);
    }
    /*res = res && guardarListaPaquetes(centroLogistico);
    //res = res && guardarListaPersonas(centroLogistico);
    res = res && guardarListaChoferes(centroLogistico);
    res = res && guardarListaClientes(centroLogistico);
    res = res && guardarListaVehiculos(centroLogistico);
    res = res && guardarListaRepartos(centroLogistico,true);
    res = res && guardarListaRepartos(centroLogistico,false);*/
    guardarListaPaquetes(centroLogistico);
    //res = res && guardarListaPersonas(centroLogistico);
    guardarListaChoferes(centroLogistico);
    guardarListaClientes(centroLogistico);
    guardarListaVehiculos(centroLogistico);
    guardarListaRepartos(centroLogistico,true);
    guardarListaRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}

//  datos / estructuras individuales
bool abrirCuil(CuilPtr cuil)
{
    FILE *archivo = fopen("Cuil.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fCuil fcuil;

        fread(&fcuil,sizeof(fCuil),1,archivo);

        fsetCuil(&fcuil,cuil,false);

        fclose(archivo);
        return true;
    }
}
bool abrirDomicilio(DomicilioPtr domicilio)
{
    FILE *archivo = fopen("Domicilio.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fDomicilio fdomicilio;

        fwrite(&fdomicilio,sizeof(fDomicilio),1,archivo);

        fsetDomicilio(&fdomicilio,domicilio,false);

        fclose(archivo);
        return true;
    }
}
bool abrirFecha(FechaPtr fecha)
{
    FILE *archivo = fopen("Fecha.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fFecha ffecha;

        fwrite(&ffecha,sizeof(fFecha),1,archivo);
        fsetFecha(&ffecha,fecha,false);
        fclose(archivo);
        return true;
    }
}
bool abrirPersona(PersonaPtr persona)
{
    FILE *archivo = fopen("Persona.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fPersona fpersona;

        fwrite(&fpersona,sizeof(fPersona),1,archivo);
        fsetPersona(&fpersona,persona,false);
        fclose(archivo);
        return true;
    }
}
bool abrirPaquete(PaquetePtr paquete)
{
    FILE *archivo = fopen("Paquete.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fPaquete fpaquete;

        fwrite(&fpaquete,sizeof(fPaquete),1,archivo);
        fsetPaquete(&fpaquete,paquete,false);
        fclose(archivo);
        return true;
    }
}
bool abrirVehiculo(VehiculoPtr vehiculo)
{
    FILE *archivo = fopen("Vehiculo.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fVehiculo fvehiculo;

        fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);
        fsetVehiculo(&fvehiculo,vehiculo,false);
        fclose(archivo);
        return true;
    }
}
bool abrirReparto(RepartoPtr reparto)
{
    FILE *archivo = fopen("Reparto.txt","r");
    if(archivo==0)
        return false;
    else
    {
        fReparto freparto;

        fwrite(&freparto,sizeof(fReparto),1,archivo);
        fsetReparto(&freparto,reparto,false);
        fclose(archivo);
        return true;
    }
}
//  conjuntos de datos / estructuras    -   Para abrir bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
///Parámetros
///     cantidad: numero de elementos guardados previamente con la contraparte de guardado.
bool abrirCuils(CuilPtr *cuils)
{
    FILE *archivo = fopen("Cuils por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);

        fCuil fcuil;

        for(int i=0;i<n;i++)
        {
            fwrite(&fcuil,sizeof(fCuil),1,archivo);
            fsetCuil(&fcuil,*(cuils+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirDomicilios(DomicilioPtr *domicilios)
{
    FILE *archivo = fopen("Domicilios por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fDomicilio fdomicilio;

        for(int i=0;i<n;i++)
        {
            fwrite(&fdomicilio,sizeof(fDomicilio),1,archivo);
            fsetDomicilio(&fdomicilio,*(domicilios+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirFechas(FechaPtr *fechas)
{
    FILE *archivo = fopen("Fechas por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fFecha ffecha;

        for(int i=0;i<n;i++)
        {
            fwrite(&ffecha,sizeof(fFecha),1,archivo);
            fsetFecha(&ffecha,*(fechas+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirPersonas(PersonaPtr *personas)
{
    FILE *archivo = fopen("Personas por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fPersona fpersona;

        for(int i=0;i<n;i++)
        {
            fwrite(&fpersona,sizeof(fPersona),1,archivo);
            fsetPersona(&fpersona,*(personas+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirPaquetes(PaquetePtr *paquetes)
{
    FILE *archivo = fopen("Paquetes por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fPaquete fpaquete;

        for(int i=0;i<n;i++)
        {
            fwrite(&fpaquete,sizeof(fPaquete),1,archivo);
            fsetPaquete(&fpaquete,*(paquetes+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirVehiculos(VehiculoPtr *vehiculos)
{
    FILE *archivo = fopen("Vehiculos por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fVehiculo fvehiculo;

        for(int i=0;i<n;i++)
        {
            fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);
            fsetVehiculo(&fvehiculo,*(vehiculos+i),false);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirRepartos(RepartoPtr *repartos)
{
    FILE *archivo = fopen("Repartos por Defecto.txt","r");

    if(archivo==0)
        return false;
    else
    {
    //leemos la cantidad que son y la almacenamos en un entero que delimita el for
        int n;
        fread(&n,sizeof(int),1,archivo);
        fReparto freparto;

        for(int i=0;i<n;i++)
        {
            fwrite(&freparto,sizeof(fReparto),1,archivo);
            fsetReparto(&freparto,*(repartos+i),false);
        }
        fclose(archivo);
        return true;
    }
}
//  conjuntos de datos / estructuras
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico){
    FILE *archivo = fopen("Lista de Personas.txt","r");
    if(archivo==0)
        return false;
    else{
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);
        fPersona fpersona;
        PersonaPtr personaAux=0;
        for(int i=0;i<n;i++){
            fread(&fpersona,sizeof(fPersona),1,archivo);
            fsetPersona(&fpersona,personaAux,false);
            agregarPersona(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}

bool abrirListaChoferes(CentroLogisticoPtr centroLogistico){
    FILE *archivo = fopen("Lista de Choferes.txt","r");
    if(archivo==0)
        return false;
    else{
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n=0;
        fread(&n,sizeof(int),1,archivo);
        fPersona fpersona;
        PersonaPtr personaAux=0;
        for(int i=0;i<n;i++){
            fread(&fpersona,sizeof(fPersona),1,archivo);
            fsetPersona(&fpersona,personaAux,false);
            agregarChofer(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}

bool abrirListaClientes(CentroLogisticoPtr centroLogistico){
    FILE *archivo = fopen("Lista de Clientes.txt","r");
    if(archivo==0)
        return false;
    else{
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n=0;
        fread(&n,sizeof(int),1,archivo);
        fPersona fpersona;
        PersonaPtr personaAux=0;
        for(int i=0;i<n;i++){
            fread(&fpersona,sizeof(fPersona),1,archivo);
            fsetPersona(&fpersona,personaAux,false);
            agregarCliente(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}

bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","r");

    if(archivo==0)
    {
        printf("\n\nARCHIVO = 0");
        return false;
    }
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;
        PaquetePtr paqueteAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&fpaquete,sizeof(fPaquete),1,archivo);

            fsetPaquete(&fpaquete,paqueteAux,false);
            agregarPaquete(centroLogistico,paqueteAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Vehiculos.txt","r");

    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;
        VehiculoPtr vehiculoAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&fvehiculo,sizeof(fVehiculo),1,archivo);

            fsetVehiculo(&fvehiculo,vehiculoAux,false);
            agregarVehiculo(centroLogistico,vehiculoAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Lista de Repartos Abiertos.txt","r");
	else
		archivo = fopen("Lista de Repartos Cerrados.txt","r");


    if(archivo==0)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fReparto freparto;
        RepartoPtr repartoAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&freparto,sizeof(fReparto),1,archivo);

            fsetReparto(&freparto,repartoAux,false);
            if(esRepartoAbierto)
                agregarReparto(centroLogistico,repartoAux,true);
            else
                agregarReparto(centroLogistico,repartoAux,false);
        }
        fclose(archivo);
        return true;
    }
}
//implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
CentroLogisticoPtr abrirTodo(){
    //Primero, recuperamos el nombre del centro logistico.
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","r");
    bool res=true;
    char nombreCtroLog[100];
    if(archivo==0)
        res=false;
    else{
        if(LeerString(archivo,nombreCtroLog,100,'\n')==EOF)
            res=false; ///volvemos a poner false si el archivo abre, pero está vacío por alguna razón.
    }
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);
    res = res && abrirListaPaquetes(centroLogistico);
    //res = res && guardarListaPersonas(centroLogistico);
    res = res && guardarListaClientes(centroLogistico);
    res = res && guardarListaChoferes(centroLogistico);
    res = res && abrirListaVehiculos(centroLogistico);
    res = res && abrirListaRepartos(centroLogistico,true);
    res = res && abrirListaRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguna funcion falla, la booleana será falso, y nos daremos cuenta.
    if(res)
        return centroLogistico;
    else
        return 0; //retornamos null si hubo algún error.
}
///*************************************************************************************************************

///                                     ESPECIALES - AYUDANTES


// Función para leer líneas de texto terminadas con un
// caracter determinado
int LeerString(FILE *archivo,char buffer[], int longitudMax,char terminador){
    // leemos caracter a caracter hasta encontrar terminador o EOF
    char caracter;
    int k=0;
    do{
        caracter=fgetc(archivo);
        if(k<longitudMax)
            buffer[k]=caracter;
        k++;
    } while(caracter!=EOF && caracter!=terminador);
    buffer[k]=0; // agregamos el terminador
    if(caracter==EOF)
        return EOF;
    else
        return k;
}


///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

FechaPtr PasajeFechaDinamico(fFechaPtr FE, FechaPtr FD, bool ADinamico){
    if(ADinamico){
        FD=crearFecha(FE->dia,FE->mes,FE->anio,FE->hora,FE->minuto);
    }else{
        FE->dia=getDiaNatural(FD);
        FE->mes=getMesNatural(FD);
        FE->anio=getAnioNatural(FD);
        FE->hora=getHoraNatural(FD);
        FE->minuto=getMinutoNatural(FD);
    }
    return FD;
}

DomicilioPtr PasajeDomicilioDinamico(fDomicilioPtr DE, DomicilioPtr DD, bool ADinamico){
    if(ADinamico){
        DD=crearDomicilio(DE->calle,DE->altura,DE->localidad);
    }else{
        strcpy(DE->calle,DD->calle);
        DE->altura=DD->altura;
        strcpy(DE->localidad,DD->localidad);
    }
    return DD;
}

CuilPtr PasajeCuilDinamico(fCuilPtr CE, CuilPtr CD, bool ADinamico){
    if(ADinamico){
        CD=crearCuil(CE->cuil);
    }else{
        strcpy(CE->cuil,CD->cuil);
    }
    return CD;
}
///---------------------------------------------------------------------------///
VehiculoPtr PasajeVehiculoDinamico(fVehiculoPtr VE, VehiculoPtr VD, bool ADinamico){
    if(ADinamico){
        VD=crearVehiculo(VE->tipo,VE->marca,VE->modelo,VE->patente);
    }else{
        VE->tipo=VD->tipo;
        strcpy(VE->marca,VD->marca);
        strcpy(VE->modelo,VD->modelo);
        strcpy(VE->patente,VD->patente);
    }
    return VD;
}
void GuardarListaVehiculosNuevo(ListaPtr listaVehiculos){
    FILE* arch;
    arch=fopen("VehiculosPrueba.bin","wb");
    fclose(arch);
    arch=fopen("VehiculosPrueba.bin","ab");
    fVehiculo VE;
    VehiculoPtr VD;
    ListaPtr LA=listaVehiculos;
    while(!listaVacia(LA)){
        VD=getCabecera(LA);
        PasajeVehiculoDinamico(&VE,VD,false);
        fwrite(&VE,sizeof(fVehiculo),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}
ListaPtr LeerListaVehiculosNuevo(){
    FILE* arch;
    fVehiculo VE;
    VehiculoPtr VD;
    ListaPtr LV=crearLista();
    arch=fopen("VehiculosPrueba.bin","rb");
    fread(&VE,sizeof(fVehiculo),1,arch);
    while(!feof(arch)){
        VD=PasajeVehiculoDinamico(&VE,VD,true);
        agregarDatoLista(LV,(VehiculoPtr)VD);
        fread(&VE,sizeof(fVehiculo),1,arch);
    }
    fclose(arch);
    /*ListaPtr LA=LV;
    while(!listaVacia(LA)){
        VD=getCabecera(LA);
        mostrarVehiculo(VD);
        LA=getResto(LA);
    }
    system("pause");*/
    return LV;
}

///-----------------------------------------------------------------------///

PersonaPtr PasajePersonaDinamico(fPersonaPtr PE, PersonaPtr PD, bool ADinamico){
    if(ADinamico){
        /*PD=crearPersonaDirect(PE->nombre,PE->apellido,
                              PE->domicilio.calle,
                              PE->domicilio.altura,
                              PE->domicilio.localidad,
                              PE->cuil,PE->esChofer);*/
        PD=crearPersonaDirectNuevo(PE);
    }else{
        strcpy(PE->nombre ,PD->nombre);
        strcpy(PE->apellido,PD->apellido);
        strcpy(PE->domicilio.calle,PD->domicilio->calle);
        PE->domicilio.altura=PD->domicilio->altura;
        strcpy(PE->domicilio.localidad,PD->domicilio->localidad);
        strcpy(PE->cuil,PD->cuil->cuil);
    }
    return PD;
}

void GuardarListaClientesNuevo(ListaPtr listaClientes){
    FILE* arch;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LA=listaClientes;
    arch=fopen("ClientesPrueba.bin","wb");
    fclose(arch);
    arch=fopen("ClientesPrueba.bin","ab");
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        PasajePersonaDinamico(&PE,PD,false);
        fwrite(&PE,sizeof(fPersona),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}

ListaPtr LeerListaClientesNuevo(){
    FILE* arch;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LC=crearLista();
    arch=fopen("ClientesPrueba.bin","rb");
    fread(&PE,sizeof(fPersona),1,arch);
    while(!feof(arch)){
        PD=PasajePersonaDinamico(&PE,PD,true);
        agregarDatoLista(LC,(PersonaPtr)PD);
        fread(&PE,sizeof(fPersona),1,arch);
    }
    fclose(arch);
    /*ListaPtr LA=LC;
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        mostrarPersona(PD);
        LA=getResto(LA);
    }
    system("pause");*/
    return LC;
}

///-----------------------------------------------------------------------///


PaquetePtr PasajePaqueteDinamico(fPaquetePtr PE, PaquetePtr PD, bool ADinamico){
    if(ADinamico){
        /*PD=crearPaqueteDirect(PE->ID,PE->ancho,PE->alto,Pe->largo,PE->peso,
                              PE->dirRetiro->calle,PE->dirRetiro->altura,PE->dirRetiro->localidad,
                              PE->dirEntrega->calle,PE->dirEntrega->altura,PE->dirEntrega->localidad,
                              PE->fechaEntrega->dia,PE->fechaEntrega->mes,PE->fechaEntrega->anio,
                              PE->fechaEntrega->hora,PE->fechaEntrega->minuto,PE->estado,
                              PE->cliente->nombre,PE->cliente->apellido,PE->cliente->domicilio->calle,
                              PE->cliente->domicilio->altura,PE->cliente->domicilio->localidad,
                              PE->cliente->cuil,PE->cliente->esChofer);*/
        PD=crearPaqueteDirectNuevo(PE);
    }else{
        PE->ID=PD->ID;
        PE->alto=PD->alto;
        PE->ancho=PD->ancho;
        PE->largo=PD->largo;
        PE->peso=PD->peso;
        PE->estado=PD->estado;
        PasajeDomicilioDinamico(&PE->dirRetiro,PD->dirRetiro,false);
        PasajeDomicilioDinamico(&PE->dirEntrega,PD->dirEntrega,false);
        PasajeFechaDinamico(&PE->fechaEntrega,PD->fechaEntrega,false);
        PasajePersonaDinamico(&PE->cliente,PD->cliente,false);
    }
    return PD;
}


void GuardarListaPaquetesNuevo(ListaPtr listaPaquetes){
    FILE* arch;
    fPaquete PE;
    PaquetePtr PD;
    ListaPtr LA=listaPaquetes;
    arch=fopen("PaquetesPrueba.bin","wb");
    fclose(arch);
    arch=fopen("PaquetesPrueba.bin","ab");
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        PasajePaqueteDinamico(&PE,PD,false);
        fwrite(&PE,sizeof(fPaquete),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}

ListaPtr LeerListaPaquetesNuevo(){
    FILE* arch;
    fPaquete PE;
    PaquetePtr PD;
    ListaPtr LP=crearLista();
    arch=fopen("PaquetesPrueba.bin","rb");
    fread(&PE,sizeof(fPaquete),1,arch);
    while(!feof(arch)){
        PD=PasajePaqueteDinamico(&PE,PD,true);
        agregarDatoLista(LP,(PaquetePtr)PD);
        fread(&PE,sizeof(fPaquete),1,arch);
    }
    fclose(arch);
    ListaPtr LA=LP;
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        mostrarPaquete(PD);
        LA=getResto(LA);
    }
    return LP;
}


///-----------------------------------------------------------------------///

/*
void pruebaPasajePaquete(){
    fPaquete PE;
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);
    PaquetePtr PD=crearPaqueteDirect1(1,1,1,1,1,"1",1,"1","1",1,"1",1,1,2022,1,1,1,"1","1","1",1,"1","1","1","1","1",1,"1","1",false);
    ///mostrarPaquete(PD);
    PasajePaqueteDinamico(&PE,PD,false);
    PaquetePtr PDP=PasajePaqueteDinamico(&PE,PDP,true);
    system("cls");
    mostrarPaquete(PDP);
    printf("%d\n", PE.alto);
    printf("%d\n", PE.fechaEntrega.dia);
    printf("%d\n", PE.dirEntrega.altura);
    printf("%d\n", PE.dirRetiro.altura);
    printf("%s\n", PE.cliente.nombre);
}*/


/*

void pruebaPasaje(ListaPtr listaVehiculos){
    fVehiculo VE;///Vehiculo en memoria estatica
    fVehiculo VEP;///Vehiculo en memoria estatica de prueba
    VehiculoPtr VD;///Vehiculo en memoria dinamica
    VehiculoPtr VDP;///Vehiculo en memoria dinamica de prueba
    VehiculoPtr VDPV2;///Vehiculo en memoria dinamica de prueba version 2

    printf("Nueva prueba: \n\n");
    ///printf("%s\n", getMarca(&VE));///BROKEN
    ///mostrarVehiculo(&VE);
    VD=crearVehiculo(3,"Mercedes Benz","Actros","19JKU89");
    PasajeVehiculoDinamico(&VE,VD,false);
    VD=destruirVehiculo(VD);
    VDP=PasajeVehiculoDinamico(&VE,VDP,true);
    ///mostrarVehiculo(VDP);

    FILE* a;
    a=fopen("PROBANDO.bin","wb");
    fwrite(&VE,sizeof(fVehiculo),1,a);
    fclose(a);
    a=fopen("PROBANDO.bin","rb");
    fread(&VEP,sizeof(fVehiculo),1,a);
    fclose(a);
    VDPV2=PasajeVehiculoDinamico(&VEP,VDPV2,true);
    mostrarVehiculo(VDPV2);
    system("pause");
}
*/

    /*VD=crearVehiculo(3,"Mercedes Benz","Actros","19JKU89");
    DinamicoEstatico(VD,&VE);
    printf("Prueba inicial de pasaje dinamico-estatico\n");
    printf("%d\n", VE.tipo);
    printf("%s\n", VE.marca);
    printf("%s\n", VE.modelo);
    printf("%s\n", VE.patente);
    fVehiculoPtr VED;///Vehiculo en memoria dinamico con tamanio campos en memoria estatica
    FILE *a;
    a=fopen("probando.bin","wb");
    fwrite(&VE,sizeof(fVehiculo),1,a);
    fclose(a);
    a=fopen("probando.bin","rb");
    fread(&VEP,sizeof(fVehiculo),1,a);
    fclose(a);
    printf("Prueba inicial de lectura\n");
    printf("%d\n", VEP.tipo);
    printf("%s\n", VEP.marca);
    printf("%s\n", VEP.modelo);
    printf("%s\n", VEP.patente);*/

    /*
void pruebaDePasajes(){
    fCuil CE;
    CuilPtr CD=crearCuil("20458730955");
    fDomicilio DE;
    DomicilioPtr DD=crearDomicilio("Sixto",1200,"Lomas");
    fFecha FE;
    FechaPtr FD=crearFecha(10,12,2022,16,45);
    PasajeCuilDinamico(&CE,CD,false);
    PasajeDomicilioDinamico(&DE,DD,false);
    PasajeFechaDinamico(&FE,FD,false);
    printf("Evaluacion de las pruebas: \n\n");
    printf("Cuil: %s\n", CE.cuil);
    printf("Domicilio: %s - %d - %s \n", DE.calle,DE.altura,DE.localidad);
    printf("Fecha: %d / %d / %d -- %d : %d \n", FE.dia,FE.mes,FE.anio,FE.hora,FE.minuto);
    system("pause");
}*/

/*
void pruebaPasajePersona(){
    fPersona PE;
    PersonaPtr PD=crearPersonaDirect("GASTON","ROMERO","SIXTO",1200,"LOMAS","20458730955",false);
    mostrarPersona(PD);
    PasajePersonaDinamico(&PE,PD,false);
    printf("Probando Resultados:\n\n");
    printf("%s - %s - %s - %d - %s - %s \n", PE.nombre,PE.apellido,PE.domicilio.calle,PE.domicilio.altura,PE.domicilio.localidad,PE.cuil);
    system("pause");
}
*/
