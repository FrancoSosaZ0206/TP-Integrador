#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"
#include "Files.h"

#include <sys/stat.h>
#include <dirent.h> ///NUEVOS: para crear carpetas

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

///  listas de datos / estructuras
bool guardarPaquetes(CentroLogisticoPtr centroLogistico)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE *archivo = fopen("Archivos/Lista de Paquetes.bin","wb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
    int n = longitudLista(getPaquetes(centroLogistico));
    fwrite(&n,sizeof(int),1,archivo);

    fPaquete fpaquetes[n];
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux , getPaquetes(centroLogistico));

    for(int i=0;!listaVacia(listaAux);i++)
    {
        PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
        fsetPaquete(&fpaquetes[i],paqueteAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    fwrite(&fpaquetes,sizeof(fPaquete),n,archivo);

    fclose(archivo);
    return true;
}
bool guardarPersonas(CentroLogisticoPtr centroLogistico)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE *archivo = fopen("Archivos/Lista de Personas.bin","wb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
    int n = longitudLista(getPersonas(centroLogistico));
    fwrite(&n,sizeof(int),1,archivo);

    fPersona fpersonas[n];
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux , getPersonas(centroLogistico));

    for(int i=0;!listaVacia(listaAux);i++)
    {
        PersonaPtr personaAux = (PersonaPtr)getCabecera(listaAux);
        fsetPersona(&fpersonas[i],personaAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    fwrite(&fpersonas,sizeof(fPersona),n,archivo);

    fclose(archivo);
    return true;
}
bool guardarVehiculos(CentroLogisticoPtr centroLogistico)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE *archivo = fopen("Archivos/Lista de Vehiculos.bin","wb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
    int n = longitudLista(getVehiculos(centroLogistico));
    fwrite(&n,sizeof(int),1,archivo);

    fVehiculo fvehiculos[n];
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux , getVehiculos(centroLogistico));

    for(int i=0;!listaVacia(listaAux);i++)
    {
        VehiculoPtr vehiculoAux = (VehiculoPtr)getCabecera(listaAux);
        fsetVehiculo(&fvehiculos[i],vehiculoAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    fwrite(&fvehiculos,sizeof(fVehiculo),n,archivo);

    fclose(archivo);
    return true;
}
bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Archivos/Lista de Repartos Abiertos.bin","wb");
	else
		archivo = fopen("Archivos/Lista de Repartos Cerrados.bin","wb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
    int n; ///guardamos primero la cantidad de elementos de la lista
    if(esRepartoAbierto)
        n = longitudLista(getRepartos(centroLogistico,true));
    else
        n = longitudLista(getRepartos(centroLogistico,false));

    fwrite(&n,sizeof(int),1,archivo);

    fReparto frepartos[n];
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,getRepartos(centroLogistico,esRepartoAbierto));

    for(int i=0;!listaVacia(listaAux);i++)
    {
        RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
        fsetReparto(&frepartos[i],repartoAux,true);

        ListaPtr listaDestruir = listaAux;
        listaAux = getResto(listaAux);
        listaDestruir = destruirLista(listaDestruir, false);
    }
    listaAux=destruirLista(listaAux,false);
    fwrite(&frepartos,sizeof(fReparto),n,archivo);

    fclose(archivo);
    return true;
}
///  General
bool guardarNombreCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    if(!abrirCarpeta())
        if(!crearCarpeta())
            return false;

    FILE *archivo = fopen("Archivos/Nombre del Centro Logistico.txt","w");
    if(archivo==NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO 'Nombre del Centro Logistico.txt'.\n\n");
        return false;
    }

    char *temp = getNombreCentroLogistico(centroLogistico);
    int longStr = strlen(temp) + 2; //2 más que el original: 1 x el '\0', y 2 x el caracter que le agregaremos.

    char nombreCtroLog[longStr];
    strcpy(nombreCtroLog,temp);
    nombreCtroLog[longStr-1]='\n'; ///le agregamos el caracter especial para la apertura.
///Guardamos el nombre del centro logistico en un archivo aparte
    fwrite(nombreCtroLog,sizeof(char),longStr,archivo);
    fclose(archivo);

    return true;
}

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


///  Listas de datos (CentroLogistico)
bool abrirPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Paquetes.bin","rb");

    if(archivo==NULL)
    {
        printf("\n\nARCHIVO = NULL");
        return false;
    }
///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
    int n = 0;
    fread(&n,sizeof(int),1,archivo);
    fPaquete fpaquetes[n];
    fread(&fpaquetes,sizeof(fPaquete),n,archivo);

    for(int i=n-1;i>-1;i--)
    {
        PaquetePtr paqueteAux = fsetPaquete(&fpaquetes[i],paqueteAux,false);
        agregarPaquete(centroLogistico,paqueteAux);
    }
    fclose(archivo);
    return true;
}
bool abrirPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Personas.bin","rb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
    int n = 0;
    fread(&n,sizeof(int),1,archivo);
    fPersona fpersonas[n];
    fread(&fpersonas,sizeof(fPersona),n,archivo);

    for(int i=n-1;i>-1;i--)
    {
        PersonaPtr personaAux = fsetPersona(&fpersonas[i],personaAux,false);
        agregarPersona(centroLogistico,personaAux);
    }
    fclose(archivo);
    return true;
}
bool abrirVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Vehiculos.bin","rb");

    if(archivo==NULL)
        return false;
///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
    int n = 0;
    fread(&n,sizeof(int),1,archivo);
    fVehiculo fvehiculos[n];
    fread(&fvehiculos,sizeof(fVehiculo),n,archivo);

    for(int i=n-1;i>-1;i--)
    {
        VehiculoPtr vehiculoAux = fsetVehiculo(&fvehiculos[i],vehiculoAux,false);
        agregarVehiculo(centroLogistico,vehiculoAux);
    }
    fclose(archivo);
    return true;
}
bool abrirRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
    if(esRepartoAbierto)
        archivo = fopen("Archivos/Lista de Repartos Abiertos.bin","rb");
    else
        archivo = fopen("Archivos/Lista de Repartos Cerrados.bin","rb");

    if(archivo==NULL)
        return false;
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
    int n = 0;
    fread(&n,sizeof(int),1,archivo);

    fReparto frepartos[n];
    fread(&frepartos,sizeof(fReparto),n,archivo);

    for(int i=n-1;i>-1;i--)
    {
        RepartoPtr repartoAux = fsetReparto(&frepartos[i],repartoAux,false);
        agregarReparto(centroLogistico,repartoAux,esRepartoAbierto);
    }
    fclose(archivo);
    return true;
}
///  General
char *abrirNombreCentroLogistico()
{
    if(!abrirCarpeta())
    {
        printf("ERROR: no se pudo abrir la carpeta 'Archivos'.");
        return NULL;
    }
//Si se pudo abrir la carpeta, recuperamos el nombre del centro logistico.
    FILE *archivo = fopen("Archivos/Nombre del Centro Logistico.txt","r");
    char temp[100];
    if(archivo==NULL || LeerString(archivo,temp,100,'\n')==EOF) ///si el archivo no abre o está vacío por alguna razón,
    {
        printf("ERROR: archivo inexistente o vacio."); ///mostramos un mensaje de error, y
        return NULL; ///retornamos NULL
    }
    char *nombreCtroLog = crearStringDinamico(temp);
    return nombreCtroLog;
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
}
///*************************************************************************************************************

///                                     ESPECIALES - AYUDANTES


/* Función para leer líneas de texto terminadas con un
caracter determinado */
int LeerString(FILE *archivo, char buffer[], int longitudMax, char terminador){
    char caracter;
    int k = 0;
    do{
        caracter = fgetc(archivo);
        if(k < longitudMax) { buffer[k] = caracter; }
        k++;
    } while(caracter != EOF && caracter != terminador);
    buffer[k] = 0;
    if(caracter == EOF) { return EOF; }
    else { return k; }
}

void guardarPersonaPrueba(PersonaPtr p1, int posicion) {
    fPersona p2;
    fsetPersona(&p2,p1,true);
    strcat(p2.nombre, "\n");
    strcat(p2.apellido, "\n");
    strcat(p2.domicilio.calle, "\n");
    strcat(p2.domicilio.localidad, "\n");
    strcat(p2.cuil.cuil, "\n");
    FILE* a = fopen("Pruebas.txt", "wb");
    fprintf(a, "%s %d %s", "Persona ", posicion, "\n");
    fprintf(a, "%s", "Nombre: ");
    fprintf(a, "%s", p2.nombre);
    fprintf(a, "%s", "Apellido: ");
    fprintf(a, "%s", p2.apellido);
    fprintf(a, "%s", "Domicilio: \n");
    fprintf(a, "%s", "Calle: ");
    fprintf(a, "%s", p2.domicilio.calle);
    fprintf(a, "%s", "Altura: ");
    fprintf(a, "%d", p2.domicilio.altura);
    fprintf(a, "%s", "\n");
    fprintf(a, "%s", "Localidad: ");
    fprintf(a, "%s", p2.domicilio.localidad);
    fprintf(a, "%s", "Cuil: ");
    fprintf(a, "%s", p2.cuil.cuil);
    fclose(a);
}

void leerPersonaPrueba(PersonaPtr p1, int posicion) {

}
