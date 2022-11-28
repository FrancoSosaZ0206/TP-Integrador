#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <assert.h> //NUEVA: ayuda con el proceso de testeo.
#include "util.h"
#include "TDAVehiculo.h"
#include "TDACentroLogistico.h"
#include "TDAFechaYHora.h"
#include "FilesV2.h"


/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                                 MACROS

/// *** NOMBRES DE CARPETAS ***
const char *CARPETA = "Archivos";
/// *** NOMBRES DE ARCHIVOS ***
const char *F_PAQUETES = "Paquetes";
const char *F_PERSONAS = "Personas";
const char *F_VEHICULOS = "Vehiculos";
const char *F_REPARTOS_ABIERTOS = "Repartos Abiertos";
const char *F_REPARTOS_CERRADOS = "Repartos Cerrados";
const char *F_CTROLOG = "Nombre del Centro Logistico";
/// *** EXTENSIONES PERMITIDAS ***
const char *F_TEXTO = "txt";
const char *F_BINARIO = "bin";
const char *F_DATOS = "dat";


/*** FORMATOS DE SERIALIZACIÓN      ***
        OUT: para guardar (enviar)
        IN: para abrir (recibir)    ***/

//General
const char *F_TITLE = "LISTA DE %s (%d)\n\n***************************************\n\n\n";
const char *F_BETWEEN =                 "\n---------------------------------------\n\n";
const char *F_END =                     "\n\n***************************************";

//Cuil
const char *CUIL_OUT =      "\tCUIL: %s\n";
const char *CUIL_IN =       "\tCUIL: %[^\n]\n";
//Domicilio
const char *DOMICILIO_OUT = "\t\tCalle: %s\n\t\tAltura: %d\n\t\tLocalidad: %s\n";
const char *DOMICILIO_IN =  "\t\tCalle: %[^\n]%*c\n\t\tAltura: %d\n\t\tLocalidad: %[^\n]%*c\n";
//Fecha
const char *FECHA_OUT =     "%s\n";
const char *FECHA_IN =      "%[^\n]%*c\n";

//Paquetes
const char *PAQUETE_OUT =   "(#%d)\n\n\tEstado: %d. %s\n\tAncho, Alto y Largo: %d, %d, %d\n\tPeso: %d\n";
const char *PAQUETE_IN =    "(#%d)\n\n\tEstado: %d. %[^\n]\n\tAncho, Alto y Largo: %d, %d, %d\n\tPeso: %d\n";
//Personas
const char *PERSONA_OUT =   "\tTipo %s (%s)\n\tApellido y Nombre: %s, %s\n";
const char *PERSONA_IN =    "\tTipo %s (%[^)])\n\tApellido y Nombre: %[^,], %[^\n]\n";
//Vehiculos
const char *VEHICULO_OUT =  "\tTipo %d - %s\n\tMarca: %s\n\tModelo: %s\n\tPatente: %s\n";
const char *VEHICULO_IN =   "\tTipo %d - %[^\n]%*c\n\tMarca: %[^\n]%*c\n\tModelo: %[^\n]%*c\n\tPatente: %[^\n]%*c\n";


/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                  ESTRUCTURAS ESPECIALES (PRIVADAS, SOLO USAR EN LAS FUNCIONES DE ESTE ARCHIVO)


typedef struct fCuil
{
    char cuil[15]; //un CUIL con espacios entre cada campo ocuparía 13 espacios, pero le damos un poco de
} fCuil;           //espacio extra por las dudas.
typedef fCuil* fCuilPtr;

typedef struct fDomicilio
{
    char calle[100];
    int altura;
    char localidad[100];
} fDomicilio;
typedef fDomicilio* fDomicilioPtr;

typedef struct fFecha
{
    int diaJuliano;
    int hora;
    int minuto;
    char fechaStr[18];
} fFecha;
typedef fFecha* fFechaPtr;


typedef struct fPersona
{
    char nombre[100];
    char apellido[100];
    fDomicilio domicilio; ///Ojo:
    fCuil cuil; ///las estructuras tampoco pueden ser punteros!!!
    bool esChofer;
    char esChoferStr[10];
    char valorDeVerdadStr[10]; //Esta variable es solo para serializar "true" o "false" dependiendo del valor de esChofer
} fPersona; //Lo único que pasamos como puntero es la estructura dentro del campo de fwrite o fread
typedef fPersona* fPersonaPtr;

typedef struct fPaquete
{
    int ID;
    int ancho;
    int alto;
    int largo;
    int peso;
    fDomicilio dirRetiro;
    fDomicilio dirEntrega;
    fFecha fechaEntrega;
    int estado; ///0=En depósito,1=En curso,2=Retirado,3=Entregado,4=Demorado,5=Suspendido,6=Reservado
    char estadoStr[20];
} fPaquete;
typedef fPaquete* fPaquetePtr;

typedef struct fVehiculo
{
    int tipo;
    char tipoStr[25];
    char marca[50];
    char modelo[50];
    char patente[15];
} fVehiculo;
typedef fVehiculo* fVehiculoPtr;


typedef struct fReparto
{
    fPersona chofer;
    fVehiculo vehiculo;
    fFecha fechaSalida;
    fFecha fechaRetorno;
    int tamanioPilaPaq; ///la dimension del array...
    fPaquete paquetes[100]; ///depende de la longitud de la pila que me pasan
} fReparto;
typedef fReparto* fRepartoPtr;



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
int fgetDiaJuliano(fFechaPtr pffecha) //no necesitamos pasar los días, meses y anios.
{
    return pffecha->diaJuliano;
}
int fgetHora(fFechaPtr pffecha)
{
    return pffecha->hora;
}
int fgetMinuto(fFechaPtr pffecha)
{
    return pffecha->minuto;
}
char *fgetFechaStr(fFechaPtr pffecha)
{
    return pffecha->fechaStr;
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
char *fgetEsChoferStr(fPersonaPtr pfpersona)
{
    return pfpersona->esChoferStr;
}
char *fgetValorDeVerdadStr(fPersonaPtr pfpersona)
{
    return pfpersona->valorDeVerdadStr;
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
char *fgetEstadoStr(fPaquetePtr pfpaquete)
{
    return pfpaquete->estadoStr;
}

//  Vehiculo
int fgetTipoVehiculo(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->tipo;
}
char *fgetTipoVehiculoStr(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->tipoStr;
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
int fgetTamanioPilaPaq(fRepartoPtr pfreparto)
{
    return pfreparto->tamanioPilaPaq;
}
fPaquetePtr fgetPaquetesReparto(fRepartoPtr pfreparto)
{ ///este si retorna puntero x q almacenamos los paquetes como array.
    return pfreparto->paquetes;
}

//Nuevo "getter" para el array de paquetes estáticos:
//Copia el contenido de cada paquete en un array aparte
void fsetPaquetesReparto2(fRepartoPtr pfreparto,fPaquetePtr pfpaquetes[100],int n)
{
    for(int i=0;i<n;i++)
    {
        pfpaquetes[i]->ID=fgetID(&pfreparto->paquetes[i]);
        pfpaquetes[i]->ancho=fgetAncho(&pfreparto->paquetes[i]);
        pfpaquetes[i]->alto=fgetAlto(&pfreparto->paquetes[i]);
        pfpaquetes[i]->largo=fgetLargo(&pfreparto->paquetes[i]);
        pfpaquetes[i]->peso=fgetPeso(&pfreparto->paquetes[i]);
    //Copiamos la direccion de retiro
        strcpy(pfdomicilio->calle,getCalle(domicilio));
        pfdomicilio->altura=getAltura(domicilio);
        strcpy(pfdomicilio->localidad,getLocalidad(domicilio));
    //Copiamos la direccion de entrega
        strcpy(pfdomicilio->calle,getCalle(domicilio));
        pfdomicilio->altura=getAltura(domicilio);
        strcpy(pfdomicilio->localidad,getLocalidad(domicilio));
    //Copiamos la fecha de entrega
        fsetFecha(fgetFechaEntrega(pfpaquete),getFechaEntrega(paquete),true);

        pfpaquetes[i]->estado=fgetEstado(&pfreparto->paquetes[i]);
        switch(pfpaquetes[i]->estado)
        {
        case 0:
            strcpy(pfpaquetes[i]->estadoStr,"En Deposito");
            break;
        case 1:
            strcpy(pfpaquetes[i]->estadoStr,"En Curso");
            break;
        case 2:
            strcpy(pfpaquetes[i]->estadoStr,"Retirado");
            break;
        case 3:
            strcpy(pfpaquetes[i]->estadoStr,"Entregado");
            break;
        case 4:
            strcpy(pfpaquetes[i]->estadoStr,"Demorado");
            break;
        case 5:
            strcpy(pfpaquetes[i]->estadoStr,"Suspendido");
            break;
        case 6:
            strcpy(pfpaquetes[i]->estadoStr,"Reservado");
            break;
        default:
            strcpy(pfpaquetes[i]->estadoStr,"ERROR");
            break;
        }
    }
}




/** Setters
Se puede setear toda la estructura de una.
Postcondición: si setGuardar == true, setea cuil en fCuil.
               De lo contrario, hace el proceso inverso (ayuda a la hora de abrir un archivo).
*/
CuilPtr fsetCuil(fCuilPtr fcuil,CuilPtr cuil,bool setGuardar)
{
    if(setGuardar)
        strcpy(fcuil->cuil,getCuil(cuil));
    else ///asumimos que la estructura está vacía y la creamos.
        cuil = crearCuil(fgetCuil(fcuil));
    return cuil;
}
DomicilioPtr fsetDomicilio(fDomicilioPtr pfdomicilio,DomicilioPtr domicilio,bool setGuardar)
{
    if(setGuardar)
    {
        strcpy(pfdomicilio->calle,getCalle(domicilio));
        pfdomicilio->altura=getAltura(domicilio);
        strcpy(pfdomicilio->localidad,getLocalidad(domicilio));
    }
    else ///asumimos que la estructura está vacía y la creamos.
        domicilio = crearDomicilio(pfdomicilio->calle,
                                   pfdomicilio->altura,
                                   pfdomicilio->localidad);
    return domicilio;
}
FechaPtr fsetFecha(fFechaPtr pffecha,FechaPtr fecha,bool setGuardar)
{
    if(setGuardar)
    {
        pffecha->diaJuliano=getDiaJuliano(fecha);
        pffecha->hora=getHora(fecha);
        pffecha->minuto=getMinuto(fecha);

        traerFechaYHora(fecha,pffecha->fechaStr);
    }
    else ///asumimos que la estructura está vacía y la creamos.
        fecha = crearFechaDirect(fgetDiaJuliano(pffecha),fgetHora(pffecha),fgetMinuto(pffecha));
    return fecha;
}

PaquetePtr fsetPaquete(fPaquetePtr pfpaquete,PaquetePtr paquete,bool setGuardar)
{
    if(setGuardar)
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
        switch(pfpaquete->estado)
        {
        case 0:
            strcpy(pfpaquete->estadoStr,"En Deposito");
            break;
        case 1:
            strcpy(pfpaquete->estadoStr,"En Curso");
            break;
        case 2:
            strcpy(pfpaquete->estadoStr,"Retirado");
            break;
        case 3:
            strcpy(pfpaquete->estadoStr,"Entregado");
            break;
        case 4:
            strcpy(pfpaquete->estadoStr,"Demorado");
            break;
        case 5:
            strcpy(pfpaquete->estadoStr,"Suspendido");
            break;
        case 6:
            strcpy(pfpaquete->estadoStr,"Reservado");
            break;
        default:
            strcpy(pfpaquete->estadoStr,"ERROR");
            break;
        }
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr dirRetiro = NULL;
        dirRetiro = fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        DomicilioPtr dirEntrega = NULL;
        dirEntrega = fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        FechaPtr fechaEntrega = NULL;
        fechaEntrega = fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

        paquete = crearPaquete(fgetID(pfpaquete),fgetAncho(pfpaquete),
                               fgetAlto(pfpaquete),fgetLargo(pfpaquete),
                               fgetPeso(pfpaquete),dirRetiro,dirEntrega,
                               fechaEntrega,fgetEstado(pfpaquete));
    }
    return paquete;
}
PersonaPtr fsetPersona(fPersonaPtr pfpersona,PersonaPtr persona,bool setGuardar)
{
    if(setGuardar)
    {
        strcpy(pfpersona->nombre,getNombre(persona));
        strcpy(pfpersona->apellido,getApellido(persona));

        fsetDomicilio(fgetDomicilio(pfpersona),getDomicilio(persona),true);
        fsetCuil(fgetCuilPersona(pfpersona),getCuilPersona(persona),true); ///MUCHO OJO: TODAVIA NO SE CAMBIO EL NOMBRE ORIGINAL, SE DEBE HACER ESO PARA QUE FUNCIONE.

        pfpersona->esChofer=getEsChofer(persona);
        if(fgetEsChofer(pfpersona))
        {
            strcpy(pfpersona->esChoferStr,"Chofer");
            strcpy(pfpersona->valorDeVerdadStr,"true");
        }
        else
        {
            strcpy(pfpersona->esChoferStr,"Cliente");
            strcpy(pfpersona->valorDeVerdadStr,"false");
        }
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        if(strcmp(pfpersona->valorDeVerdadStr,"true")==0
           && strcmp(pfpersona->esChoferStr,"Chofer")==0)
            pfpersona->esChofer=true;
        else if(strcmp(pfpersona->valorDeVerdadStr,"false")==0
                && strcmp(pfpersona->esChoferStr,"Cliente")==0)
            pfpersona->esChofer=false;
        else
            exit(5);

        DomicilioPtr domicilio = NULL;
        domicilio = fsetDomicilio(fgetDomicilio(pfpersona),domicilio,false);
        CuilPtr cuil = NULL;
        cuil = fsetCuil(fgetCuilPersona(pfpersona),cuil,false);

        persona = crearPersona(fgetNombre(pfpersona),
                             fgetApellido(pfpersona),
                             domicilio,
                             cuil,
                             fgetEsChofer(pfpersona));
    }
    return persona;
}
VehiculoPtr fsetVehiculo(fVehiculoPtr pfvehiculo,VehiculoPtr vehiculo,bool setGuardar)
{
    if(setGuardar)
    {
        pfvehiculo->tipo=getTipoVehiculo(vehiculo);

        strcpy(pfvehiculo->marca,getMarca(vehiculo));
        strcpy(pfvehiculo->modelo,getModelo(vehiculo));
        strcpy(pfvehiculo->patente,getPatente(vehiculo));

        switch(fgetTipoVehiculo(pfvehiculo))
        {
        case 1:
            strcpy(pfvehiculo->tipoStr,"Moto");
            break;
        case 2:
            strcpy(pfvehiculo->tipoStr,"Auto");
            break;
        case 3:
            strcpy(pfvehiculo->tipoStr,"Camion");
            break;
        default:
            printf("ERROR: tratando de serializar un estado inexistente.\n\n");
            exit(3);
            break;
        }
    }
    else ///asumimos que la estructura está vacía y la creamos.
        vehiculo = crearVehiculo(fgetTipoVehiculo(pfvehiculo),
                             fgetMarca(pfvehiculo),
                             fgetModelo(pfvehiculo),
                             fgetPatente(pfvehiculo));
    return vehiculo;
}

RepartoPtr fsetReparto(fRepartoPtr pfreparto,RepartoPtr reparto,bool setGuardar)
{
    int n=0;
    PaquetePtr paqueteAux;

    if(setGuardar)
    {
        fsetPersona(fgetChofer(pfreparto),getChofer(reparto),true);
        fsetVehiculo(fgetVehiculo(pfreparto),getVehiculo(reparto),true);
        fsetFecha(fgetFechaSalida(pfreparto),getFechaSalida(reparto),true);
        fsetFecha(fgetFechaRetorno(pfreparto),getFechaRetorno(reparto),true);

        n = cantidadPaquetes(reparto);
        pfreparto->tamanioPilaPaq = n;
        for(int i=0;i<n;i++)
        {
            paqueteAux = descargarPaquete(reparto);
            fsetPaquete(&pfreparto->paquetes[i],paqueteAux,true);
        }
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        PersonaPtr chofer = NULL;
        chofer = fsetPersona(fgetChofer(pfreparto),chofer,false);
        VehiculoPtr vehiculo = NULL;
        vehiculo = fsetVehiculo(fgetVehiculo(pfreparto),vehiculo,false);
        FechaPtr fechaSalida = NULL;
        fechaSalida = fsetFecha(fgetFechaSalida(pfreparto),fechaSalida,false);
        FechaPtr fechaRetorno = NULL;
        fechaRetorno = fsetFecha(fgetFechaRetorno(pfreparto),fechaRetorno,false);

        PilaPtr paquetes = crearPila();
        n=pfreparto->tamanioPilaPaq;

        reparto = armarReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
        for(int i=n-1;i>-1;i--) ///lo hacemos al revés para mantener el orden original de la pila.
        {
            paqueteAux = fsetPaquete(&pfreparto->paquetes[i],paqueteAux,false);
            cargarPaquete(reparto,paqueteAux);
        }
    }
    return reparto;
}


/// *** FUNCIONES DE SERIALIZACIÓN (AYUDANTES) ***

void serializarCuil(fCuilPtr pfcuil,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,CUIL_OUT,pfcuil->cuil)!=-1);
}
void serializarDomicilio(fDomicilioPtr pfdom,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,DOMICILIO_OUT,pfdom->calle,pfdom->altura,pfdom->localidad)!=-1);
}
void serializarFecha(fFechaPtr pffecha,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,FECHA_OUT,pffecha->fechaStr)!=-1);
}


void serializarPaquete(fPaquetePtr pfpaquete,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,PAQUETE_OUT,fgetID(pfpaquete),fgetEstado(pfpaquete),fgetEstadoStr(pfpaquete),
            fgetAncho(pfpaquete),fgetAlto(pfpaquete),fgetLargo(pfpaquete),fgetPeso(pfpaquete))!=-1);

    fprintf(f,"\tDireccion de Retiro:\n");
    serializarDomicilio(fgetDirRetiro(pfpaquete),f);
    fprintf(f,"\tDireccion de Entrega:\n");
    serializarDomicilio(fgetDirEntrega(pfpaquete),f);
    fprintf(f,"\tFecha de Entrega: ");
    serializarFecha(fgetFechaEntrega(pfpaquete),f);
}
void serializarPersona(fPersonaPtr pfpersona,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,PERSONA_OUT,fgetEsChoferStr(pfpersona),fgetValorDeVerdadStr(pfpersona),
            fgetApellido(pfpersona),fgetNombre(pfpersona))!=-1);

    fprintf(f,"\tDomicilio:\n");
    serializarDomicilio(fgetDomicilio(pfpersona),f);

    serializarCuil(fgetCuilPersona(pfpersona),f);
}
void serializarVehiculo(fVehiculoPtr pfvehiculo,FILE *f)
{
    assert(f!=NULL);
    assert(fprintf(f,VEHICULO_OUT,fgetTipoVehiculo(pfvehiculo),fgetTipoVehiculoStr(pfvehiculo),
            fgetMarca(pfvehiculo),fgetModelo(pfvehiculo),fgetPatente(pfvehiculo))!=-1);
}
void serializarReparto(fRepartoPtr pfreparto,FILE *f)
{
    assert(f!=NULL);

    fprintf(f,"Chofer:\n");
    serializarPersona(fgetChofer(pfreparto),f);
    fprintf(f,"\nVehiculo:\n");
    serializarVehiculo(fgetVehiculo(pfreparto),f);

    fprintf(f,"\nFecha de Salida: ");
    serializarFecha(fgetFechaSalida(pfreparto),f);

    fprintf(f,"Fecha de Retorno: ");
    serializarFecha(fgetFechaRetorno(pfreparto),f);

/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
    fprintf(f,"\nPaquete %d ",1);

    fPaquetePtr paquetes;
    paquetes = fgetPaquetesReparto(pfreparto);
    serializarPaquete(paquetes[0],f);
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////


//    int n=fgetTamanioPilaPaq(pfreparto);
//    fPaquetePtr fpaquetes = fgetPaquetesReparto(pfreparto);
//
//    assert(fprintf(f,"\nENTREGAS DEL REPARTO (%d):\n",n)!=-1);
//    for(int i=n-1,j=1;i>-1;i--,j++)
//    {
//        fprintf(f,"\nPaquete %d ",j);
//        serializarPaquete(&fpaquetes[i],f);
//        if(i>0)
//            fprintf(f,"\n");
//    }
}

/// *** FUNCIONES DE DESERIALIZACIÓN (AYUDANTES) ***

void deserializarCuil(fCuilPtr pfcuil,FILE *f)
{
    assert(f!=NULL);
    int n=1;
    int res=fscanf(f,CUIL_IN,pfcuil->cuil);

    assert(res==n);
}
void deserializarDomicilio(fDomicilioPtr pfdom,FILE *f)
{
    assert(f!=NULL);
    int n=3;
    int res=fscanf(f,DOMICILIO_IN,pfdom->calle,&pfdom->altura,pfdom->localidad);

    assert(res==n);
}
void deserializarFecha(fFechaPtr pffecha,FILE *f)
{
    assert(f!=NULL);

    int n=1;
    int res=fscanf(f,FECHA_IN,pffecha->fechaStr);
    assert(res==n);

    int dia=0,mes=0,anio=0;
    sscanf(fgetFechaStr(pffecha),"%d/%d/%d, %d:%d",&dia,&mes,&anio,&pffecha->hora,&pffecha->minuto);
    pffecha->diaJuliano = calcularDiaJuliano(dia,mes,anio);
}

void deserializarPaquete(fPaquetePtr pfpaquete,FILE *f)
{
    assert(f!=NULL);

    int n=7;
    int res = fscanf(f,PAQUETE_IN,&pfpaquete->ID,&pfpaquete->estado,pfpaquete->estadoStr,
                        &pfpaquete->ancho,&pfpaquete->alto,&pfpaquete->largo,&pfpaquete->peso);
    assert(res == n);

    fscanf(f,"\tDireccion de Retiro:\n");
    deserializarDomicilio(&pfpaquete->dirRetiro,f);
    fscanf(f,"\tDireccion de Entrega:\n");
    deserializarDomicilio(&pfpaquete->dirEntrega,f);
    fscanf(f,"\tFecha de Entrega: ");
    deserializarFecha(&pfpaquete->fechaEntrega,f);
}
void deserializarPersona(fPersonaPtr pfpersona,FILE *f)
{
    assert(f!=NULL);

    int n=4;
    int res = fscanf(f,PERSONA_IN,pfpersona->esChoferStr,pfpersona->valorDeVerdadStr,
            pfpersona->apellido,pfpersona->nombre);
    assert(res==n);

    fscanf(f,"\tDomicilio:\n");
    deserializarDomicilio(&pfpersona->domicilio,f);
    deserializarCuil(&pfpersona->cuil,f);

    if(strcmp(pfpersona->valorDeVerdadStr,"true")==0)
        pfpersona->esChofer=true;
    else if(strcmp(pfpersona->valorDeVerdadStr,"false")==0)
        pfpersona->esChofer=false;
}
void deserializarVehiculo(fVehiculoPtr pfvehiculo,FILE *f)
{
    assert(f!=NULL);

    int n=5;
    int res = fscanf(f,VEHICULO_IN,&pfvehiculo->tipo,pfvehiculo->tipoStr,
                         pfvehiculo->marca,pfvehiculo->modelo,pfvehiculo->patente);
    assert(res==n);
}
void deserializarReparto(fRepartoPtr pfreparto,FILE *f)
{
    assert(f!=NULL);

    fscanf(f,"Chofer:\n");
    deserializarPersona(fgetChofer(pfreparto),f);
    fscanf(f,"Vehiculo:\n");
    deserializarVehiculo(fgetVehiculo(pfreparto),f);

    fscanf(f,"\nFecha de Salida: ");
    deserializarFecha(fgetFechaSalida(pfreparto),f);
    fscanf(f,"Fecha de Retorno: ");
    deserializarFecha(fgetFechaRetorno(pfreparto),f);


/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
    int indicePaq=0;
    fscanf(f,"\nPaquete %d ",&indicePaq);
    deserializarPaquete(&pfreparto->paquetes[0],f);
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////


//    int n=0;
//    assert(fscanf(f,"\nENTREGAS DEL REPARTO (%d):\n",&n)==1);
//    pfreparto->tamanioPilaPaq=n;
//    for(int i=0,j=0;i<n;i++)
//    {
//        fPaquetePtr fpaquetes = fgetPaquetesReparto(pfreparto);
//        assert(fscanf(f,"\nPaquete %d ",&j)==1);
//        deserializarPaquete(&fpaquetes[i],f);
//        if(i>0)
//            fscanf(f,"\n\n");
//    }
}




/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ


/// *** FUNCIONES DE CARPETAS Y DIRECTORIOS ***

char *getDirectorio(const char *nombreCarpeta, const char *nombreArchivo, const char *tipoArchivo)
{
    char buffer[100];

    strcpy(buffer,nombreCarpeta);
    strcat(buffer,"/");
    strcat(buffer,nombreArchivo);
    strcat(buffer,".");
    strcat(buffer,tipoArchivo);

    return crearStringDinamico(buffer);
}

bool crearCarpeta(const char *nombre)
{
    int resultado = mkdir(nombre);
    if(resultado == -1)
        return false;
    else
        return true;
}

bool abrirCarpeta(const char *nombre)
{
    DIR *carpeta = opendir(nombre); ///Chequeamos si existe la carpeta
    if(carpeta==NULL)
        return false;
    else
    {
        closedir(carpeta);
        return true;
    }
}


/// *** FUNCIONES DE SERIALIZACIÓN ***

bool serializarPaquetes(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        if(!crearCarpeta(CARPETA))
            return false;

    FILE *f;
    int n=longitudLista(getPaquetes(c));
    fPaquete fpaquetes[n];
    PaquetePtr paqueteAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getPaquetes(c));

    char *directorio = getDirectorio(CARPETA,F_PAQUETES,F_TEXTO);

    f = fopen(directorio,"w");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;


    for(int i=0;i<n;i++)
    {
        paqueteAux = getCabecera(listaAux);
        fsetPaquete(&fpaquetes[i],paqueteAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);


    fprintf(f,F_TITLE,"PAQUETES",n);
    for(int i=n-1,j=1;i>-1;i--,j++)
    {
        fprintf(f,"PAQUETE %d ",j);
        serializarPaquete(&fpaquetes[i],f);

        if(i>0)
            fprintf(f,F_BETWEEN);
    }

    fprintf(f,F_END);
    fclose(f);

    return true;
}

bool serializarPersonas(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        if(!crearCarpeta(CARPETA))
            return false;

    FILE *f;
    int n=longitudLista(getPersonas(c));
    fPersona fpersonas[n];
    PersonaPtr personaAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getPersonas(c));

    char *directorio = getDirectorio(CARPETA,F_PERSONAS,F_TEXTO);

    f = fopen(directorio,"w");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;


    for(int i=0;i<n;i++)
    {
        personaAux = getCabecera(listaAux);
        fsetPersona(&fpersonas[i],personaAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);


    fprintf(f,F_TITLE,"PERSONAS",n);
    for(int i=n-1,j=1;i>-1;i--,j++)
    {
        fprintf(f,"PERSONA %d\n\n",j);
        serializarPersona(&fpersonas[i],f);

        if(i>0)
            fprintf(f,F_BETWEEN);
    }

    fprintf(f,F_END);
    fclose(f);

    return true;
}

bool serializarVehiculos(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        if(!crearCarpeta(CARPETA))
            return false;

    FILE *f;
    int n=longitudLista(getVehiculos(c));
    fVehiculo fvehiculos[n];
    VehiculoPtr vehiculoAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getVehiculos(c));

    char *directorio = getDirectorio(CARPETA,F_VEHICULOS,F_TEXTO);

    f = fopen(directorio,"w");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;


    for(int i=0;i<n;i++)
    {
        vehiculoAux = getCabecera(listaAux);
        fsetVehiculo(&fvehiculos[i],vehiculoAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);


    fprintf(f,F_TITLE,"VEHICULOS",n);
    for(int i=n-1,j=1;i>-1;i--,j++)
    {
        fprintf(f,"VEHICULO %d\n\n",j);
        serializarVehiculo(&fvehiculos[i],f);

        if(i>0)
            fprintf(f,F_BETWEEN);
    }

    fprintf(f,F_END);
    fclose(f);

    return true;
}

bool serializarRepartos(CentroLogisticoPtr c,bool esRepartoAbierto)
{
    if(!abrirCarpeta(CARPETA))
        if(!crearCarpeta(CARPETA))
            return false;

    FILE *f;
    int n=longitudLista(getRepartos(c,esRepartoAbierto));
    fReparto frepartos[n];
    RepartoPtr repartoAux;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getRepartos(c,esRepartoAbierto));

    char *directorio;
    if(esRepartoAbierto)
        directorio = getDirectorio(CARPETA,F_REPARTOS_ABIERTOS,F_TEXTO);
    else
        directorio = getDirectorio(CARPETA,F_REPARTOS_CERRADOS,F_TEXTO);

    f = fopen(directorio,"w");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;


    for(int i=0;i<n;i++)
    {
        repartoAux = getCabecera(listaAux);
        fsetReparto(&frepartos[i],repartoAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir,false);
    }
    listaAux = destruirLista(listaAux,false);


    fprintf(f,F_TITLE,"REPARTOS",n);
    for(int i=n-1,j=1;i>-1;i--,j++)
    {
        fprintf(f,"REPARTO %d\n\n",j);
        serializarReparto(&frepartos[i],f);

        if(i>0)
            fprintf(f,F_BETWEEN);
    }

    fprintf(f,F_END);
    fclose(f);

    return true;
}

/// *** FUNCIONES DE DESERIALIZACIÓN ***

bool deserializarPaquetes(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        return false;

    FILE *f;
    int n=0;
    fPaquete fpaquete;
    PaquetePtr paqueteAux;

    char *directorio = getDirectorio(CARPETA,F_PAQUETES,F_TEXTO);
    f = fopen(directorio,"r");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;

    char trash[20];
    fscanf(f,F_TITLE,trash,&n);
    for(int i=0,j=0;i<n;i++)
    {
        fscanf(f,"PAQUETE %d ",&j);
        deserializarPaquete(&fpaquete,f);

        paqueteAux = fsetPaquete(&fpaquete,paqueteAux,false);
        agregarPaquete(c,paqueteAux);

        if(i<n-1)
            fscanf(f,F_BETWEEN);
    }
    fclose(f);

    return true;
}

bool deserializarPersonas(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        return false;

    FILE *f;
    int n=0;
    fPersona fpersona;
    PersonaPtr personaAux;

    char *directorio = getDirectorio(CARPETA,F_PERSONAS,F_TEXTO);
    f = fopen(directorio,"r");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;

    char trash[20];
    fscanf(f,F_TITLE,trash,&n);
    for(int i=0,j=0;i<n;i++)
    {
        fscanf(f,"PERSONA %d\n\n",&j);
        deserializarPersona(&fpersona,f);

        personaAux = fsetPersona(&fpersona,personaAux,false);
        agregarPersona(c,personaAux);

        if(i<n-1)
            fscanf(f,F_BETWEEN);
    }
    fclose(f);

    return true;
}

bool deserializarVehiculos(CentroLogisticoPtr c)
{
    if(!abrirCarpeta(CARPETA))
        return false;

    FILE *f;
    int n=0;
    fVehiculo fvehiculo;
    VehiculoPtr vehiculoAux;

    char *directorio = getDirectorio(CARPETA,F_VEHICULOS,F_TEXTO);
    f = fopen(directorio,"r");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;

    char trash[20];
    fscanf(f,F_TITLE,trash,&n);
    for(int i=0,j=0;i<n;i++)
    {
        fscanf(f,"VEHICULO %d\n\n",&j);
        deserializarVehiculo(&fvehiculo,f);

        vehiculoAux = fsetVehiculo(&fvehiculo,vehiculoAux,false);
        agregarVehiculo(c,vehiculoAux);

        if(i<n-1)
            fscanf(f,F_BETWEEN);
    }
    fclose(f);

    return true;
}

bool deserializarRepartos(CentroLogisticoPtr c,bool esRepartoAbierto)
{
    if(!abrirCarpeta(CARPETA))
        return false;

    FILE *f;
    int n=0;
    fReparto freparto;
    RepartoPtr repartoAux;

    char *directorio;
    if(esRepartoAbierto)
        directorio = getDirectorio(CARPETA,F_REPARTOS_ABIERTOS,F_TEXTO);
    else
        directorio = getDirectorio(CARPETA,F_REPARTOS_CERRADOS,F_TEXTO);

    f = fopen(directorio,"r");
    directorio = destruirStringDinamico(directorio);
    if(f==NULL)
        return false;


    char trash[20];
    fscanf(f,F_TITLE,trash,&n);
    for(int i=0,j=0;i<n;i++)
    {
        fscanf(f,"REPARTO %d\n\n",&j);
        deserializarReparto(&freparto,f);

        repartoAux = fsetReparto(&freparto,repartoAux,false);
        agregarReparto(c,repartoAux,esRepartoAbierto);

        if(i>n-1)
            fscanf(f,F_BETWEEN);
    }
    fclose(f);

    return true;
}
