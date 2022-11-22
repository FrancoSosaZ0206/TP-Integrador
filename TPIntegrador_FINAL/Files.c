#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"
#include "Files.h"

#include <sys/stat.h>
#include <dirent.h>

///*************************************************************************************************************

///                  Estructuras Especiales (PRIVADAS, solo usar en las funciones de este archivo)


typedef struct fCuil //a este ya lo definimos como nos dijo el profe. Despues cambio el que utilizamos siempre.
{
    char cuil[15]; //un CUIL con espacios entre cada campo ocuparía 13 espacios, pero le damos un poco de
} fCuil; //espacio extra por las dudas.
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
} fFecha;
typedef fFecha* fFechaPtr;


typedef struct fPersona
{
    char nombre[100];
    char apellido[100];
    fDomicilio domicilio; ///Ojo:
    fCuil cuil; ///las estructuras tampoco pueden ser punteros!!!
    bool esChofer;
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
    int estado; ///0=En depósito,1=En curso,2=Retirado,3=Entregado,4=Demorado,5=Suspendido
} fPaquete;
typedef fPaquete* fPaquetePtr;

typedef struct fVehiculo
{
    int tipo;
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
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr dirRetiro = NULL;
        dirRetiro = fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        DomicilioPtr dirEntrega = NULL;
        dirEntrega = fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        FechaPtr fechaEntrega = NULL;
        fechaEntrega = fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

        paquete = crearPaquete(fgetID(pfpaquete),
                               fgetAncho(pfpaquete),
                               fgetAlto(pfpaquete),
                               fgetLargo(pfpaquete),
                               fgetPeso(pfpaquete),
                               dirRetiro,
                               dirEntrega,
                               fechaEntrega,
                               fgetEstado(pfpaquete));
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
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
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
VehiculoPtr fsetVehiculo(fVehiculoPtr pfvehiculo,VehiculoPtr vehiculo,bool setGuardar) ///AHORA RETORNA PUNTERO A LA ESTRUCTURA SETEADA
{
    if(setGuardar)
    {
        pfvehiculo->tipo=getTipoVehiculo(vehiculo);

        strcpy(pfvehiculo->marca,getMarca(vehiculo));
        strcpy(pfvehiculo->modelo,getModelo(vehiculo));
        strcpy(pfvehiculo->patente,getPatente(vehiculo));
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

        for(int i=n;i>0;i--) ///lo hacemos al revés para mantener el orden original de la pila.
        {
            paqueteAux = fsetPaquete(&pfreparto->paquetes[i],paqueteAux,false);
            apilar(paquetes,(PaquetePtr)paqueteAux);
        }
        reparto = armarReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    }
    return reparto;
}


/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                                 MACROS

const char *DOMICILIOS_OUT = "%s %d, %s\n";
const char *DOMICILIOS_IN = "%[^ ]%*c %d, %[^\n]%*c\n";

const char *FECHAS_OUT = "%s\n";
const char *FECHAS_IN = "%[^\n]%*c\n";
const char *FECHAS_OUT_ALT = "%d/%d/%d, %d:%d\n";
const char *FECHAS_IN_ALT = "%d/%d/%d, %d:%d\n";

const char *FECHAS_STR = "%d/%d/%d, %d:%d";


/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                         FUNICIONES DE CARPETAS

/** OPERACIÓN: crea una carpeta.
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se crea una carpeta de nombre "Archivos" que almacenará los archivos del proyecto.
PARÁMETROS: ninguno
DEVUELVE: true si se pudo crear, false de lo contrario.
*/
bool crearCarpeta()
{
    int resultado = mkdir("Archivos");
    if(resultado == -1)
        return false;
    else
        return true;
}
/** OPERACIÓN: busca y abre una carpeta.
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se busca una carpeta con el nombre "Archivos".
PARÁMETROS: ninguno
DEVUELVE: true si se pudo encontrar y abrir, false de lo contrario.
*/
bool abrirCarpeta()
{
    DIR *carpeta = opendir("Archivos"); ///Chequeamos si existe la carpeta
    if(carpeta==NULL)
        return false;
    else
    {
        closedir(carpeta);
        return true;
    }
}
/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///


///*************************************************************************************************************

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ

/*
bool guardarTodo(CentroLogisticoPtr centroLogistico) //implementacion: llamará a las otras funciones de guardado
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    bool res = guardarNombreCentroLogistico(centroLogistico);
    res = res && guardarPaquetes(centroLogistico);
    res = res && guardarPersonas(centroLogistico);
    res = res && guardarVehiculos(centroLogistico);
    res = res && guardarRepartos(centroLogistico,true);
    res = res && guardarRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}

CentroLogisticoPtr abrirTodo() //implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
{
    if(!abrirCarpeta())
    {
        printf("ERROR: no se pudo abrir la carpeta 'Archivos'.");
        return NULL;
    }

    char *nombreCtroLog = abrirNombreCentroLogistico();
    if(nombreCtroLog==NULL)
    {
        printf("ERROR AL INICIAR SESION,\nNO SE PUDO RECUPERAR EL NOMBRE DEL CENTRO LOGISTICO.\n\n");
        return NULL;
    }
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);
    nombreCtroLog = destruirStringDinamico(nombreCtroLog); //Destruimos el stirng porque fue creado en memoria dinamica.

    bool res = abrirPaquetes(centroLogistico);
    res = res && abrirPersonas(centroLogistico);
    res = res && abrirVehiculos(centroLogistico);
    res = res && abrirRepartos(centroLogistico,true);
    res = res && abrirRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguna funcion falla, la booleana será falso, y nos daremos cuenta.
    if(res)
        return centroLogistico;
    else
        return NULL; //retornamos null si hubo algún error.
} */
///*************************************************************************************************************

///                                     ESPECIALES - AYUDANTES


bool serializarPaquetes(CentroLogisticoPtr c)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE* a = fopen("Archivos/PRUEBAS.txt", "w");
    if(a==NULL)
        return false;

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getPaquetes(c));
    fPaquete fpaq;

    fprintf(a,"LISTA DE PAQUETES (%d)",longitudLista(listaAux));
    for(int i=1;!listaVacia(listaAux);i++)
    {
        PaquetePtr paqueteAux = getCabecera(listaAux);
        fsetPaquete(&fpaq,paqueteAux,true);

        fDomicilioPtr fdirRet = fgetDirRetiro(&fpaq);
        fDomicilioPtr fdirEnt = fgetDirEntrega(&fpaq);

        char fEnt[18];
        traerFechaYHora(getFechaEntrega(paqueteAux),fEnt);

        fprintf(a,"\n\n------------------------------------------\n\n");
        fprintf(a,"Paquete #%d\n\n",fgetID(&fpaq));

        switch(fgetEstado(&fpaq))
        {
        case 0:
            fprintf(a,"Estado: En Deposito\n");
            break;
        case 1:
            fprintf(a,"Estado: En Curso\n");
            break;
        case 2:
            fprintf(a,"Estado: Retirado\n");
            break;
        case 3:
            fprintf(a,"Estado: Entregado\n");
            break;
        case 4:
            fprintf(a,"Estado: Demorado\n");
            break;
        case 5:
            fprintf(a,"Estado: Suspendido\n");
            break;
        case 6:
            fprintf(a,"Estado: Reservado\n");
            break;
        default:
            fprintf(a,"Estado: ERROR\n");
            break;
        }

        fprintf(a,"Ancho, Alto y Largo: %d, %d, %d\n",fgetAncho(&fpaq),
                                                      fgetAlto(&fpaq),
                                                      fgetLargo(&fpaq));
        fprintf(a,"Peso: %d\n",fgetPeso(&fpaq));
        fprintf(a,"Direccion de Retiro: ");
        fprintf(a,DOMICILIOS_OUT,fgetCalle(fdirRet),fgetAltura(fdirRet),fgetLocalidad(fdirRet));
        fprintf(a,"Direccion de Entrega: ");
        fprintf(a,DOMICILIOS_OUT,fgetCalle(fdirEnt),fgetAltura(fdirEnt),fgetLocalidad(fdirEnt));
        fprintf(a,"Fecha de Entrega: ");
        fprintf(a,FECHAS_OUT,fEnt);

        ListaPtr listaDestruir = listaAux;
        listaAux=getResto(listaAux);
        listaDestruir=destruirLista(listaDestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    fclose(a);
    return true;
}
bool deserializarPaquetes(CentroLogisticoPtr c)
{
    if(!abrirCarpeta())
        return false;

    FILE* a = fopen("Archivos/PRUEBAS.txt", "r");
    if(a==NULL)
        return false;

    int n=0;
    fscanf(a,"LISTA DE PERSONAS (%d)",&n);

    for(int i=0;i<n;i++)
    {
        fPaquete fpaq;
        PaquetePtr paqueteAux=NULL;

        fDomicilio fdirRet, fdirEnt;
        fFecha fEnt;

        int ID=0,ancho=0,alto=0,largo=0,peso=0;

        char estadoStr[100];
        int estado=-1;

        char *estados[8];
        estados[0] = "En Deposito";
        estados[1] = "En Curso";
        estados[2] = "Retirado";
        estados[3] = "Entregado";
        estados[4] = "Demorado";
        estados[5] = "Suspendido";
        estados[6] = "Reservado";
        estados[7] = "ERROR";

        char calle[100];
        int altura=0;
        char localidad[100];
        char fechaEntregaStr[18];
        int dia=0,mes=0,anio=0,hora=0,min=0;

        DomicilioPtr dirRetiro = NULL;
        DomicilioPtr dirEntrega = NULL;
        FechaPtr fechaEntrega = NULL;

        fscanf(a,"\n\n------------------------------------------\n\n");
        fscanf(a,"Paquete #%d\n\n",&ID);
        fscanf(a,"Estado: %[^\n]%*c\n",estadoStr);


        for(int j=0;j<8;j++)
        {
            if(strcmp(estadoStr,estados[j]))
            {
                estado=j; //Un estado erroneo se maneja asignando un número que no existe dentro del código de estados establecidos (el 8).
                break;
            }
        }

        fscanf(a,"Ancho, Alto y Largo: %d, %d, %d\n",&ancho,&alto,&largo);
        fscanf(a,"Peso: %d\n",&peso);

        fscanf(a,"Direccion de Retiro: ");
        fscanf(a,DOMICILIOS_IN,calle,&altura,localidad);
        dirRetiro = crearDomicilio(calle,altura,localidad);

        fscanf(a,"Direccion de Entrega: ");
        fscanf(a,DOMICILIOS_IN,calle,&altura,localidad);
        dirEntrega = crearDomicilio(calle,altura,localidad);

        fscanf(a,"Fecha de Entrega: ");
        fscanf(a,FECHAS_IN,fechaEntregaStr);
        sscanf(fechaEntregaStr,FECHAS_STR,&dia,&mes,&anio,&hora,&min);
        fechaEntrega=crearFecha(dia,mes,anio,hora,min);

        paqueteAux = crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,estado);

        agregarPaquete(c,paqueteAux);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
        mostrarPaquete(paqueteAux);
        presionarEnterYLimpiarPantalla();
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }

    fclose(a);
    return true;
}
//bool serializarPaquetes(CentroLogisticoPtr c)
//{
//    if(!abrirCarpeta())
//        if(!crearCarpeta())
//            return false;
//
//    FILE* a = fopen("Archivos/PRUEBAS.txt", "w");
//    if(a==NULL)
//        return false;
//
//    ListaPtr listaAux = crearLista();
//    agregarLista(listaAux,getPaquetes(c));
//
//    fprintf(a,"LISTA DE PAQUETES (%d)",longitudLista(listaAux));
//    for(int i=1;!listaVacia(listaAux);i++)
//    {
//        PaquetePtr paqueteAux = getCabecera(listaAux);
//
//        DomicilioPtr dirRetiro = getDirRetiro(paqueteAux);
//        DomicilioPtr dirEntrega = getDirEntrega(paqueteAux);
//        char fechaEntregaStr[18];
//        traerFechaYHora(getFechaEntrega(paqueteAux),fechaEntregaStr);
//
//        fprintf(a,"\n\n------------------------------------------\n\n");
//        fprintf(a,"Paquete #%d\n\n",getID(paqueteAux));
//
//        switch(getEstado(paqueteAux))
//        {
//        case 0:
//            fprintf(a,"Estado: En Deposito\n");
//            break;
//        case 1:
//            fprintf(a,"Estado: En Curso\n");
//            break;
//        case 2:
//            fprintf(a,"Estado: Retirado\n");
//            break;
//        case 3:
//            fprintf(a,"Estado: Entregado\n");
//            break;
//        case 4:
//            fprintf(a,"Estado: Demorado\n");
//            break;
//        case 5:
//            fprintf(a,"Estado: Suspendido\n");
//            break;
//        case 6:
//            fprintf(a,"Estado: Reservado\n");
//            break;
//        default:
//            fprintf(a,"Estado: ERROR\n");
//            break;
//        }
//
//        fprintf(a,"Ancho, Alto y Largo: %d, %d, %d\n",getAncho(paqueteAux),
//                                                      getAlto(paqueteAux),
//                                                      getLargo(paqueteAux));
//        fprintf(a,"Peso: %d\n",getPeso(paqueteAux));
//        fprintf(a,"Direccion de Retiro: ");
//        fprintf(a,DOMICILIOS_OUT,getCalle(dirRetiro),getAltura(dirRetiro),getLocalidad(dirRetiro));
//        fprintf(a,"Direccion de Entrega: ");
//        fprintf(a,DOMICILIOS_OUT,getCalle(dirEntrega),getAltura(dirEntrega),getLocalidad(dirEntrega));
//        fprintf(a,"Fecha de Entrega: ");
//        fprintf(a,FECHAS_OUT,fechaEntregaStr);
//
//        ListaPtr listaDestruir = listaAux;
//        listaAux=getResto(listaAux);
//        listaDestruir=destruirLista(listaDestruir,false);
//    }
//    listaAux=destruirLista(listaAux,false);
//
//    fclose(a);
//    return true;
//}
//bool deserializarPaquetes(CentroLogisticoPtr c)
//{
//    if(!abrirCarpeta())
//        return false;
//
//    FILE* a = fopen("Archivos/PRUEBAS.txt", "r");
//    if(a==NULL)
//        return false;
//
//    int n=0;
//    fscanf(a,"LISTA DE PERSONAS (%d)",&n);
//
//    for(int i=0;i<n;i++)
//    {
//        PaquetePtr paqueteAux=NULL;
//
//        int ID=0,ancho=0,alto=0,largo=0,peso=0;
//
//        char estadoStr[100];
//        int estado=-1;
//
//        char *estados[8];
//        estados[0] = "En Deposito";
//        estados[1] = "En Curso";
//        estados[2] = "Retirado";
//        estados[3] = "Entregado";
//        estados[4] = "Demorado";
//        estados[5] = "Suspendido";
//        estados[6] = "Reservado";
//        estados[7] = "ERROR";
//
//        char calle[100];
//        int altura=0;
//        char localidad[100];
//        char fechaEntregaStr[18];
//        int dia=0,mes=0,anio=0,hora=0,min=0;
//
//        DomicilioPtr dirRetiro = NULL;
//        DomicilioPtr dirEntrega = NULL;
//        FechaPtr fechaEntrega = NULL;
//
//        fscanf(a,"\n\n------------------------------------------\n\n");
//        fscanf(a,"Paquete #%d\n\n",&ID);
//        fscanf(a,"Estado: %[^\n]%*c\n",estadoStr);
//
//
//        for(int j=0;j<8;j++)
//        {
//            if(strcmp(estadoStr,estados[j]))
//            {
//                estado=j; //Un estado erroneo se maneja asignando un número que no existe dentro del código de estados establecidos (el 8).
//                break;
//            }
//        }
//
//        fscanf(a,"Ancho, Alto y Largo: %d, %d, %d\n",&ancho,&alto,&largo);
//        fscanf(a,"Peso: %d\n",&peso);
//
//        fscanf(a,"Direccion de Retiro: ");
//        fscanf(a,DOMICILIOS_IN,calle,&altura,localidad);
//        dirRetiro = crearDomicilio(calle,altura,localidad);
//
//        fscanf(a,"Direccion de Entrega: ");
//        fscanf(a,DOMICILIOS_IN,calle,&altura,localidad);
//        dirEntrega = crearDomicilio(calle,altura,localidad);
//
//        fscanf(a,"Fecha de Entrega: ");
//        fscanf(a,FECHAS_IN,fechaEntregaStr);
//        sscanf(fechaEntregaStr,FECHAS_STR,&dia,&mes,&anio,&hora,&min);
//        fechaEntrega=crearFecha(dia,mes,anio,hora,min);
//
//        paqueteAux = crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,estado);
//
//        agregarPaquete(c,paqueteAux);
//    }
//
//    fclose(a);
//    return true;
//}


/**
void guardarPersonasPrueba(CentroLogisticoPtr c)
{
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getPersonas(c));

    int n=longitudLista(listaAux);

    FILE* a = fopen("Pruebas.txt", "w");

    fprintf(a,"LISTA DE PERSONAS (%d)",n);
    for(int i=1;!listaVacia(listaAux);i++)
    {
        PersonaPtr personaAux = getCabecera(listaAux);

        fprintf(a,"\n\n------------------------------------------\n\n");
        fprintf(a,"Persona %d\n",i);
        fprintf(a,"Nombre: %s, %s\n",getApellido(personaAux),getNombre(personaAux));
        fprintf(a,"Domicilio: %s %d, %s\n",getCalle(getDomicilio(personaAux)),
                                          getAltura(getDomicilio(personaAux)),
                                          getLocalidad(getDomicilio(personaAux)));
        fprintf(a,"Cuil: %s",getCuil(getCuilPersona(personaAux)));

        ListaPtr listaDestruir = listaAux;
        listaAux=getResto(listaAux);
        listaDestruir=destruirLista(listaDestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    fclose(a);
}

void leerPersonasPrueba()
{
    FILE* a = fopen("Pruebas.txt", "r");

    int n=0;
    fscanf(a,"LISTA DE PERSONAS (%d)",&n);

    ListaPtr listaAux = crearLista();

    for(int i=0;i<n;i++)
    {
        PersonaPtr personaAux=NULL;

        char nombre[100];
        char apellido[100];
        char calle[100];
        int altura=0;
        char localidad[100];
        char cuil[100];
        bool esChofer = false;

        fscanf(a,"\n\n------------------------------------------\n\n");
        fscanf(a,"Persona %d\n",&i);
        fprintf(a,"Nombre: %s, %s\n",apellido,nombre);
        fscanf(a,"Domicilio: %s %d, %s\n",calle,&altura,localidad);
        fscanf(a,"Cuil: %s",cuil);

        personaAux=crearPersonaDirect(nombre,apellido,calle,altura,localidad,cuil,esChofer);
        agregarDatoLista(listaAux,(PersonaPtr)personaAux);
    }
    fclose(a);


    CentroLogisticoPtr c=crearCentroLogisticoRapido("Hola");
    setPersonas(c,listaAux);

    mostrarPersonas(c,3);
    presionarEnterYLimpiarPantalla();
}
*/
