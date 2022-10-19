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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

FechaPtr crearFechaDirectNuevo(fFechaPtr FechaEstatico)
{
    FechaPtr fecha = (FechaPtr)obtenerMemoria(sizeof(Fecha));
    fecha->diaJuliano=FechaEstatico->diaJuliano;
    fecha->hora=FechaEstatico->hora;
    fecha->minuto=FechaEstatico->minuto;
    return fecha;
}

DomicilioPtr crearDomicilioNuevo(fDomicilioPtr DomicilioEstatico)
{
    DomicilioPtr domicilio = (DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    domicilio->calle=crearStringDinamico(DomicilioEstatico->calle);
    domicilio->altura=DomicilioEstatico->altura;
    domicilio->localidad=crearStringDinamico(DomicilioEstatico->localidad);
    return domicilio;
}

PaquetePtr crearPaqueteDirectNuevo(fPaquetePtr PaqueteEstatico)
{
    PaquetePtr paquete=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    paquete->ID=PaqueteEstatico->ID;
    paquete->ancho=PaqueteEstatico->ancho;
    paquete->alto=PaqueteEstatico->alto;
    paquete->largo=PaqueteEstatico->largo;
    paquete->peso=PaqueteEstatico->peso;
    paquete->estado=PaqueteEstatico->estado;
    paquete->dirRetiro=crearDomicilioNuevo(&PaqueteEstatico->dirRetiro);
    paquete->dirEntrega=crearDomicilioNuevo(&PaqueteEstatico->dirEntrega);
    paquete->fechaEntrega=crearFechaDirectNuevo(&PaqueteEstatico->fechaEntrega);
    paquete->cliente=crearPersonaDirectNuevo(&PaqueteEstatico->cliente);
    return paquete;
}

PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PersonaEstatico)
{
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(PersonaEstatico->nombre);
    persona->apellido=crearStringDinamico(PersonaEstatico->apellido);
    persona->domicilio=crearDomicilio(PersonaEstatico->domicilio.calle,PersonaEstatico->domicilio.altura,PersonaEstatico->domicilio.localidad);
    persona->cuil=crearCuil(PersonaEstatico->cuil.cuil);
    persona->esChofer=PersonaEstatico->esChofer;
    return persona;
}

VehiculoPtr crearVehiculoDirectNuevo(fVehiculoPtr VehiculoEstatico)
{
    VehiculoPtr vehiculo = (VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    vehiculo->tipo=VehiculoEstatico->tipo;
    vehiculo->marca=crearStringDinamico(VehiculoEstatico->marca);
    vehiculo->modelo=crearStringDinamico(VehiculoEstatico->modelo);
    vehiculo->patente=crearStringDinamico(VehiculoEstatico->patente);
    return vehiculo;
}

RepartoPtr crearRepartoDirectoNuevo(fRepartoPtr RepartoEstatico)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));
    reparto->chofer=crearPersonaDirectNuevo(&RepartoEstatico->chofer);
    reparto->vehiculo=crearVehiculoDirectNuevo(&RepartoEstatico->vehiculo);
    reparto->fechaSalida=crearFechaDirectNuevo(&RepartoEstatico->fechaSalida);
    reparto->fechaRetorno=crearFechaDirectNuevo(&RepartoEstatico->fechaRetorno);
    ListaPtr paquetes=crearLista();
    PaquetePtr PaqueteDinamico;
    for(int i=0;i<RepartoEstatico->tamanioPilaPaq;i++){
        PaqueteDinamico=PasajePaqueteDinamico(&RepartoEstatico->paquetes[i],PaqueteDinamico,true);
        agregarDatoLista(paquetes,(PaquetePtr)PaqueteDinamico);
    }
    reparto->paquetes=paquetes;
    return reparto;
}

///-----------------------------------------------------------------------------------------------------------///
            ///SECCION DE FUNCIONES DE CONVERSION [ ESTATICA - DINAMICA ] [ DINAMICA - ESTATICA ]///
///-----------------------------------------------------------------------------------------------------------///

FechaPtr PasajeFechaDinamico(fFechaPtr FechaEstatica, FechaPtr FechaDinamica, bool ADinamico)
{
    if(ADinamico){
        FechaDinamica=crearFechaDirectNuevo(FechaEstatica);
    }else{
        FechaEstatica->diaJuliano=getDiaJuliano(FechaDinamica);
        FechaEstatica->hora=getHora(FechaDinamica);
        FechaEstatica->minuto=getMinuto(FechaDinamica);
    }
    return FechaDinamica;
}

DomicilioPtr PasajeDomicilioDinamico(fDomicilioPtr DomicilioEstatico, DomicilioPtr DomicilioDinamico, bool ADinamico)
{
    if(ADinamico){
        DomicilioDinamico=crearDomicilio(DomicilioEstatico->calle,DomicilioEstatico->altura,DomicilioEstatico->localidad);
    }else{
        strcpy(DomicilioEstatico->calle,DomicilioDinamico->calle);
        DomicilioEstatico->altura=DomicilioDinamico->altura;
        strcpy(DomicilioEstatico->localidad,DomicilioDinamico->localidad);
    }
    return DomicilioDinamico;
}

CuilPtr PasajeCuilDinamico(fCuilPtr CuilEstatico, CuilPtr CuilDinamico, bool ADinamico)
{
    if(ADinamico){
        CuilDinamico=crearCuil(CuilEstatico->cuil);
    }else{
        strcpy(CuilEstatico->cuil,CuilDinamico->cuil);
    }
    return CuilDinamico;
}

VehiculoPtr PasajeVehiculoDinamico(fVehiculoPtr VehiculoEstatico, VehiculoPtr VehiculoDinamico, bool ADinamico)
{
    if(ADinamico){
        VehiculoDinamico=crearVehiculoDirectNuevo(VehiculoEstatico);
    }else{
        VehiculoEstatico->tipo=VehiculoDinamico->tipo;
        strcpy(VehiculoEstatico->marca,VehiculoDinamico->marca);
        strcpy(VehiculoEstatico->modelo,VehiculoDinamico->modelo);
        strcpy(VehiculoEstatico->patente,VehiculoDinamico->patente);
    }
    return VehiculoDinamico;
}

PersonaPtr PasajePersonaDinamico(fPersonaPtr PersonaEstatico, PersonaPtr PersonaDinamica, bool ADinamico)
{
    if(ADinamico){
        PersonaDinamica=crearPersonaDirectNuevo(PersonaEstatico);
    }else{
        strcpy(PersonaEstatico->nombre ,PersonaDinamica->nombre);
        strcpy(PersonaEstatico->apellido,PersonaDinamica->apellido);
        PasajeDomicilioDinamico(&PersonaEstatico->domicilio,PersonaDinamica->domicilio,false);
        strcpy(PersonaEstatico->cuil.cuil,PersonaDinamica->cuil->cuil);
    }
    return PersonaDinamica;
}

PaquetePtr PasajePaqueteDinamico(fPaquetePtr PaqueteEstatico, PaquetePtr PaqueteDinamico, bool ADinamico)
{
    if(ADinamico){
        PaqueteDinamico=crearPaqueteDirectNuevo(PaqueteEstatico);
    }else{
        PaqueteEstatico->ID=PaqueteDinamico->ID;
        PaqueteEstatico->alto=PaqueteDinamico->alto;
        PaqueteEstatico->ancho=PaqueteDinamico->ancho;
        PaqueteEstatico->largo=PaqueteDinamico->largo;
        PaqueteEstatico->peso=PaqueteDinamico->peso;
        PaqueteEstatico->estado=PaqueteDinamico->estado;
        PasajeDomicilioDinamico(&PaqueteEstatico->dirRetiro,PaqueteDinamico->dirRetiro,false);
        PasajeDomicilioDinamico(&PaqueteEstatico->dirEntrega,PaqueteDinamico->dirEntrega,false);
        PasajeFechaDinamico(&PaqueteEstatico->fechaEntrega,PaqueteDinamico->fechaEntrega,false);
        PasajePersonaDinamico(&PaqueteEstatico->cliente,PaqueteDinamico->cliente,false);
    }
    return PaqueteDinamico;
}

RepartoPtr PasajeRepartoDinamico(fRepartoPtr RepartoEstatico, RepartoPtr RepartoDinamico, bool ADinamico)
{
    if(ADinamico){
        RepartoDinamico=crearRepartoDirectoNuevo(RepartoEstatico);
    }else{
        PasajePersonaDinamico(&RepartoEstatico->chofer,RepartoDinamico->chofer,false);
        PasajeVehiculoDinamico(&RepartoEstatico->vehiculo,RepartoDinamico->vehiculo,false);
        PasajeFechaDinamico(&RepartoEstatico->fechaSalida,RepartoDinamico->fechaSalida,false);
        PasajeFechaDinamico(&RepartoEstatico->fechaRetorno,RepartoDinamico->fechaRetorno,false);
        int total=(int)longitudLista(getPaquetesReparto(RepartoDinamico));
        RepartoEstatico->tamanioPilaPaq=total;
        ListaPtr ListaAuxiliar=(ListaPtr)getPaquetesReparto(RepartoDinamico);
        PaquetePtr PD;
        int i=0;
        while(!listaVacia(ListaAuxiliar))
        {
            PD=getCabecera(ListaAuxiliar);
            PasajePaqueteDinamico(&RepartoEstatico->paquetes[i],PD,false);
            ListaAuxiliar=getResto(ListaAuxiliar);
            i++;
        }
    }
    return RepartoDinamico;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE ESCRITURA///
///-----------------------------------------------------------------------------------------------------------///

bool guardarVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    arch=fopen("VehiculosPrueba.bin","wb");
    fclose(arch);
    arch=fopen("VehiculosPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fVehiculo VehiculoEstatico;
    VehiculoPtr VehiculoDinamico;
    ListaPtr ListaAuxiliar=getVehiculos(centroLogistico);
    while(!listaVacia(ListaAuxiliar)){
        VehiculoDinamico=getCabecera(ListaAuxiliar);
        PasajeVehiculoDinamico(&VehiculoEstatico,VehiculoDinamico,false);
        fwrite(&VehiculoEstatico,sizeof(fVehiculo),1,arch);
        ListaAuxiliar=getResto(ListaAuxiliar);
    }
    fclose(arch);
    return guardado;
}

bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE* arch;
    bool guardado=false;
    fReparto RepartoEstatico;
    RepartoPtr RepartoDinamico;
    ListaPtr ListaAuxiliar=crearLista();
    agregarLista(ListaAuxiliar,getRepartos(centroLogistico,esRepartoAbierto));
    if(esRepartoAbierto)
    {
        arch=fopen("RepartosAbiertosPrueba.bin","wb");
        fclose(arch);
        arch=fopen("RepartosAbiertosPrueba.bin","ab");
    }
    else
    {
        arch=fopen("RepartosCerradosPrueba.bin","wb");
        fclose(arch);
        arch=fopen("RepartosCerradosPrueba.bin","ab");
    }
    if(arch!=NULL)
    {
        guardado=true;
    }
    while(!listaVacia(ListaAuxiliar))
    {
        RepartoDinamico=(RepartoPtr)getCabecera(ListaAuxiliar);
        PasajeRepartoDinamico(&RepartoEstatico,RepartoDinamico,false);
        fwrite(&RepartoEstatico,sizeof(fReparto),1,arch);
        ListaAuxiliar=getResto(ListaAuxiliar);
    }
    ListaAuxiliar=destruirLista(ListaAuxiliar,false);
    fclose(arch);
    return guardado;
}

bool guardarPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    fPersona PersonaEstatico;
    PersonaPtr PersonaDinamica;
    ListaPtr ListaAuxiliar=getPersonas(centroLogistico);
    arch=fopen("PersonasPrueba.bin","wb");
    fclose(arch);
    arch=fopen("PersonasPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    while(!listaVacia(ListaAuxiliar)){
        PersonaDinamica=getCabecera(ListaAuxiliar);
        PasajePersonaDinamico(&PersonaEstatico,PersonaDinamica,false);
        fwrite(&PersonaEstatico,sizeof(fPersona),1,arch);
        ListaAuxiliar=getResto(ListaAuxiliar);
    }
    fclose(arch);
    return guardado;
}

bool guardarPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    fPaquete PaqueteEstatico;
    PaquetePtr PaqueteDinamico;
    ListaPtr ListaAuxiliar=getPaquetes(centroLogistico);
    arch=fopen("PaquetesPrueba.bin","wb");
    fclose(arch);
    arch=fopen("PaquetesPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    while(!listaVacia(ListaAuxiliar)){
        PaqueteDinamico=getCabecera(ListaAuxiliar);
        PasajePaqueteDinamico(&PaqueteEstatico,PaqueteDinamico,false);
        fwrite(&PaqueteEstatico,sizeof(fPaquete),1,arch);
        ListaAuxiliar=getResto(ListaAuxiliar);
    }
    fclose(arch);
    return guardado;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE LECTURA///
///-----------------------------------------------------------------------------------------------------------///

bool abrirVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    fVehiculo VehiculoEstatico;
    VehiculoPtr VehiculoDinamico;
    arch=fopen("VehiculosPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&VehiculoEstatico,sizeof(fVehiculo),1,arch);
    while(!feof(arch)){
        VehiculoDinamico=PasajeVehiculoDinamico(&VehiculoEstatico,VehiculoDinamico,true);
        agregarVehiculo(centroLogistico,VehiculoDinamico);
        fread(&VehiculoEstatico,sizeof(fVehiculo),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    fPersona PersonaEstatico;
    PersonaPtr PersonaDinamico;
    arch=fopen("PersonasPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&PersonaEstatico,sizeof(fPersona),1,arch);
    while(!feof(arch)){
        PersonaDinamico=PasajePersonaDinamico(&PersonaEstatico,PersonaDinamico,true);
        agregarPersona(centroLogistico,PersonaDinamico);
        fread(&PersonaEstatico,sizeof(fPersona),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    fPaquete PaqueteEstatico;
    PaquetePtr PaqueteDinamico;
    arch=fopen("PaquetesPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&PaqueteEstatico,sizeof(fPaquete),1,arch);
    while(!feof(arch)){
        PaqueteDinamico=PasajePaqueteDinamico(&PaqueteEstatico,PaqueteDinamico,true);
        agregarPaquete(centroLogistico,PaqueteDinamico);
        fread(&PaqueteEstatico,sizeof(fPaquete),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    FILE* arch;
    fReparto RepartoEstatico;
    RepartoPtr RepartoDinamico;
    bool guardado=false;
    if(esRepartoAbierto)
    {
        arch=fopen("RepartosAbiertosPrueba.bin","rb");
    }
    else
    {
        arch=fopen("RepartosCerradosPrueba.bin","rb");
    }
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&RepartoEstatico,sizeof(fReparto),1,arch);
    while(!feof(arch))
    {
        RepartoDinamico=PasajeRepartoDinamico(&RepartoEstatico,RepartoDinamico,true);
        agregarReparto(centroLogistico,RepartoDinamico,esRepartoAbierto);
        fread(&RepartoEstatico,sizeof(fReparto),1,arch);
    }
    fclose(arch);
    return guardado;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GENERALES///
///-----------------------------------------------------------------------------------------------------------///

bool guardarTodo(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    bool guardado=false;
    char nombreCentroLog[100];
    strcpy(nombreCentroLog,getNombreCentroLogistico(centroLogistico));
    arch=fopen("NombreCentroLogistico.bin","wb");
    fwrite(&nombreCentroLog,sizeof(char),100,arch);
    fclose(arch);
    guardado=guardarPaquetes(centroLogistico);
    guardado=guardado && guardarVehiculos(centroLogistico);
    guardado=guardado && guardarRepartos(centroLogistico,true);
    guardado=guardado && guardarRepartos(centroLogistico,false);
    guardado=guardado && guardarPersonas(centroLogistico);
    return guardado;
}

CentroLogisticoPtr abrirTodo()
{
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido("");
    FILE* arch;
    bool guardado=false;
    char nombreCentroLog[100];
    arch=fopen("NombreCentroLogistico.bin","rb");
    fread(&nombreCentroLog,sizeof(char),100,arch);
    fclose(arch);
    guardado=abrirPaquetes(centroLogistico);
    guardado=guardado && abrirPersonas(centroLogistico);
    guardado=guardado && abrirRepartos(centroLogistico,true);
    guardado=guardado && abrirRepartos(centroLogistico,false);
    guardado=guardado && abrirVehiculos(centroLogistico);
    if(!guardado)
    {
        printf("ERROR AL ABRIR TODO!!!\n");
        exit(1);
    }
    return centroLogistico;
}
