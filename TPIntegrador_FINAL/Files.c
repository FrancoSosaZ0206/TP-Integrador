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

///PRINCIPALMENTE
///PASAJES DE MEMORIA ESTATICA A MEMORIA DINAMICA
///PASAJES DE MEMORIA DINAMICA A MEMORIA ESTATICA
FechaPtr crearFechaDirectNuevo(fFechaPtr FE);
DomicilioPtr crearDomicilioNuevo(fDomicilioPtr DE);
PaquetePtr crearPaqueteDirectNuevo(fPaquetePtr PE);
PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PE);
VehiculoPtr crearVehiculoDirectNuevo(fVehiculoPtr VE);
RepartoPtr crearRepartoDirectoNuevo(fRepartoPtr RE);
FechaPtr PasajeFechaDinamico(fFechaPtr FE, FechaPtr FD, bool ADinamico);
DomicilioPtr PasajeDomicilioDinamico(fDomicilioPtr DE, DomicilioPtr DD, bool ADinamico);
CuilPtr PasajeCuilDinamico(fCuilPtr CE, CuilPtr CD, bool ADinamico);
VehiculoPtr PasajeVehiculoDinamico(fVehiculoPtr VE, VehiculoPtr VD, bool ADinamico);
PersonaPtr PasajePersonaDinamico(fPersonaPtr PE, PersonaPtr PD, bool ADinamico);
PaquetePtr PasajePaqueteDinamico(fPaquetePtr PE, PaquetePtr PD, bool ADinamico);
RepartoPtr PasajeRepartoDinamico(fRepartoPtr RE, RepartoPtr RD, bool ADinamico);

///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

            ///SECCION DE UTILIZACION DE ARCHIVOS///

///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

FechaPtr crearFechaDirectNuevo(fFechaPtr FE){
    FechaPtr f = (FechaPtr)obtenerMemoria(sizeof(Fecha));
    f->diaJuliano=FE->diaJuliano;
    f->hora=FE->hora;
    f->minuto=FE->minuto;
    return f;
}

DomicilioPtr crearDomicilioNuevo(fDomicilioPtr DE){
    DomicilioPtr domicilio = (DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    domicilio->calle=crearStringDinamico(DE->calle);
    domicilio->altura=DE->altura;
    domicilio->localidad=crearStringDinamico(DE->localidad);
    return domicilio;
}

PaquetePtr crearPaqueteDirectNuevo(fPaquetePtr PE){
    PaquetePtr paquete=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    paquete->ID=PE->ID;
    paquete->ancho=PE->ancho;
    paquete->alto=PE->alto;
    paquete->largo=PE->largo;
    paquete->peso=PE->peso;
    paquete->estado=PE->estado;
    paquete->dirRetiro=crearDomicilioNuevo(&PE->dirRetiro);
    paquete->dirEntrega=crearDomicilioNuevo(&PE->dirEntrega);
    paquete->fechaEntrega=crearFechaDirectNuevo(&PE->fechaEntrega);
    ///paquete->cliente=crearPersonaDirectNuevo(&PE->cliente);
    return paquete;
}

PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PE){
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(PE->nombre);
    persona->apellido=crearStringDinamico(PE->apellido);
    persona->domicilio=crearDomicilio(PE->domicilio.calle,PE->domicilio.altura,PE->domicilio.localidad);
    persona->cuil=crearCuil(PE->cuil.cuil);
    persona->esChofer=PE->esChofer;
    return persona;
}

VehiculoPtr crearVehiculoDirectNuevo(fVehiculoPtr VE){
    VehiculoPtr vehiculo = (VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    vehiculo->tipo=VE->tipo;
    vehiculo->marca=crearStringDinamico(VE->marca);
    vehiculo->modelo=crearStringDinamico(VE->modelo);
    vehiculo->patente=crearStringDinamico(VE->patente);
    return vehiculo;
}

RepartoPtr crearRepartoDirectoNuevo(fRepartoPtr RE){
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));
    reparto->chofer=crearPersonaDirectNuevo(&RE->chofer);
    reparto->vehiculo=crearVehiculoDirectNuevo(&RE->vehiculo);
    reparto->fechaSalida=crearFechaDirectNuevo(&RE->fechaSalida);
    reparto->fechaRetorno=crearFechaDirectNuevo(&RE->fechaRetorno);
    ListaPtr paquetes=crearLista();
    PaquetePtr PD;
    for(int i=0;i<RE->tamanioPilaPaq;i++){
        PD=PasajePaqueteDinamico(&RE->paquetes[i],PD,true);
        agregarDatoLista(paquetes,(PaquetePtr)PD);
    }
    reparto->paquetes=paquetes;
    return reparto;
}

///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

FechaPtr PasajeFechaDinamico(fFechaPtr FE, FechaPtr FD, bool ADinamico){
    if(ADinamico){
        FD=crearFechaDirectNuevo(FE);
    }else{
        FE->diaJuliano=getDiaJuliano(FD);
        FE->hora=getHora(FD);
        FE->minuto=getMinuto(FD);
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

VehiculoPtr PasajeVehiculoDinamico(fVehiculoPtr VE, VehiculoPtr VD, bool ADinamico){
    if(ADinamico){
        VD=crearVehiculoDirectNuevo(VE);
    }else{
        VE->tipo=VD->tipo;
        strcpy(VE->marca,VD->marca);
        strcpy(VE->modelo,VD->modelo);
        strcpy(VE->patente,VD->patente);
    }
    return VD;
}

PersonaPtr PasajePersonaDinamico(fPersonaPtr PE, PersonaPtr PD, bool ADinamico){
    if(ADinamico){
        PD=crearPersonaDirectNuevo(PE);
    }else{
        strcpy(PE->nombre ,PD->nombre);
        strcpy(PE->apellido,PD->apellido);
        PasajeDomicilioDinamico(&PE->domicilio,PD->domicilio,false);
        strcpy(PE->cuil.cuil,PD->cuil->cuil);
    }
    return PD;
}

PaquetePtr PasajePaqueteDinamico(fPaquetePtr PE, PaquetePtr PD, bool ADinamico){
    if(ADinamico){
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
        ///PasajePersonaDinamico(&PE->cliente,PD->cliente,false);
    }
    return PD;
}

RepartoPtr PasajeRepartoDinamico(fRepartoPtr RE, RepartoPtr RD, bool ADinamico){
    if(ADinamico){
        RD=crearRepartoDirectoNuevo(RE);
    }else{
        PasajePersonaDinamico(&RE->chofer,RD->chofer,false);
        PasajeVehiculoDinamico(&RE->vehiculo,RD->vehiculo,false);
        PasajeFechaDinamico(&RE->fechaSalida,RD->fechaSalida,false);
        PasajeFechaDinamico(&RE->fechaRetorno,RD->fechaRetorno,false);
        int total=(int)longitudLista(getPaquetesReparto(RD));
        RE->tamanioPilaPaq=total;
        ListaPtr LA=(ListaPtr)getPaquetesReparto(RD);
        PaquetePtr PD;
        int i=0;
        while(!listaVacia(LA))
        {
            PD=getCabecera(LA);
            PasajePaqueteDinamico(&RE->paquetes[i],PD,false);
            LA=getResto(LA);
            i++;
        }
    }
    return RD;
}


///---------------------------------------------------------------------------///

bool guardarVehiculos(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    arch=fopen("VehiculosPrueba.bin","wb");
    fclose(arch);
    arch=fopen("VehiculosPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fVehiculo VE;
    VehiculoPtr VD;
    ListaPtr LA=getVehiculos(centroLogistico);
    while(!listaVacia(LA)){
        VD=getCabecera(LA);
        PasajeVehiculoDinamico(&VE,VD,false);
        fwrite(&VE,sizeof(fVehiculo),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
    return guardado;
}

bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    FILE* arch;
    bool guardado=false;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr LA=crearLista();
    agregarLista(LA,getRepartos(centroLogistico,esRepartoAbierto));
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
    while(!listaVacia(LA))
    {
        RD=(RepartoPtr)getCabecera(LA);
        PasajeRepartoDinamico(&RE,RD,false);
        fwrite(&RE,sizeof(fReparto),1,arch);
        LA=getResto(LA);
    }
    LA=destruirLista(LA,false);
    fclose(arch);
    return guardado;
}

bool guardarPersonas(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LA=getPersonas(centroLogistico);
    arch=fopen("PersonasPrueba.bin","wb");
    fclose(arch);
    arch=fopen("PersonasPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        PasajePersonaDinamico(&PE,PD,false);
        fwrite(&PE,sizeof(fPersona),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
    return guardado;
}

bool guardarPaquetes(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    fPaquete PE;
    PaquetePtr PD;
    ListaPtr LA=getPaquetes(centroLogistico);
    arch=fopen("PaquetesPrueba.bin","wb");
    fclose(arch);
    arch=fopen("PaquetesPrueba.bin","ab");
    if(arch!=NULL)
    {
        guardado=true;
    }
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        PasajePaqueteDinamico(&PE,PD,false);
        fwrite(&PE,sizeof(fPaquete),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
    return guardado;
}

///-----------------------------------------------------------------------///

bool abrirVehiculos(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    fVehiculo VE;
    VehiculoPtr VD;
    arch=fopen("VehiculosPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&VE,sizeof(fVehiculo),1,arch);
    while(!feof(arch)){
        VD=PasajeVehiculoDinamico(&VE,VD,true);
        agregarVehiculo(centroLogistico,VD);
        fread(&VE,sizeof(fVehiculo),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirPersonas(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    fPersona PE;
    PersonaPtr PD;
    arch=fopen("PersonasPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&PE,sizeof(fPersona),1,arch);
    while(!feof(arch)){
        PD=PasajePersonaDinamico(&PE,PD,true);
        agregarPersona(centroLogistico,PD);
        fread(&PE,sizeof(fPersona),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirPaquetes(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    fPaquete PE;
    PaquetePtr PD;
    arch=fopen("PaquetesPrueba.bin","rb");
    if(arch!=NULL)
    {
        guardado=true;
    }
    fread(&PE,sizeof(fPaquete),1,arch);
    while(!feof(arch)){
        PD=PasajePaqueteDinamico(&PE,PD,true);
        agregarPaquete(centroLogistico,PD);
        fread(&PE,sizeof(fPaquete),1,arch);
    }
    fclose(arch);
    return guardado;
}

bool abrirRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto){
    FILE* arch;
    fReparto RE;
    RepartoPtr RD;
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
    fread(&RE,sizeof(fReparto),1,arch);
    while(!feof(arch))
    {
        RD=PasajeRepartoDinamico(&RE,RD,true);
        agregarReparto(centroLogistico,RD,esRepartoAbierto);
        fread(&RE,sizeof(fReparto),1,arch);
    }
    fclose(arch);
    return guardado;
}

///------------------------------------------------------------///

bool guardarTodo(CentroLogisticoPtr centroLogistico){
    FILE* arch;
    bool guardado=false;
    char nombreCentroLog[100];
    strcpy(nombreCentroLog,getNombreCentroLogistico(centroLogistico));
    arch=fopen("NombreCentroLogistico.bin","wb");
    fwrite(&nombreCentroLog,sizeof(100),1,arch);
    fclose(arch);
    guardado=guardarPaquetes(centroLogistico);
    guardado=guardado && guardarVehiculos(centroLogistico);
    guardado=guardado && guardarRepartos(centroLogistico,true);
    guardado=guardado && guardarRepartos(centroLogistico,false);
    guardado=guardado && guardarPersonas(centroLogistico);
    return guardado;
}

CentroLogisticoPtr abrirTodo(){
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido("");
    FILE* arch;
    bool guardado=false;
    char nombreCentroLog[100];
    arch=fopen("NombreCentroLogistico.bin","rb");
    fread(&nombreCentroLog,sizeof(100),1,arch);
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
