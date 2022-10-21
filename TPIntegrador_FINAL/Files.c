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
    char calle[50];
    int altura;
    char localidad[50];
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
    char nombre[50];
    char apellido[50];
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
    fPaquete paquetes[]; ///depende de la longitud de la pila que me pasan
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
        domicilio = crearDomicilio(fgetCalle(pfdomicilio),fgetAltura(pfdomicilio),fgetLocalidad(pfdomicilio));
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

        printf("ID=%d\nancho=%d\nalto=%d\nlargo=%d\npeso=%d\n\n",pfpaquete->ID,
                                                                 pfpaquete->ancho,
                                                                 pfpaquete->alto,
                                                                 pfpaquete->largo,
                                                                 pfpaquete->peso);
        presionarEnterYLimpiarPantalla();

        fsetDomicilio(fgetDirRetiro(pfpaquete),getDirRetiro(paquete),true);
        fsetDomicilio(fgetDirEntrega(pfpaquete),getDirEntrega(paquete),true);
        fsetFecha(fgetFechaEntrega(pfpaquete),getFechaEntrega(paquete),true);

        pfpaquete->estado=getEstado(paquete);
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr dirRetiro = fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        DomicilioPtr dirEntrega = fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        FechaPtr fechaEntrega = fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

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
        DomicilioPtr domicilio = fsetDomicilio(fgetDomicilio(pfpersona),domicilio,false);
        CuilPtr cuil = fsetCuil(fgetCuilPersona(pfpersona),cuil,false);

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
        PersonaPtr chofer = fsetPersona(fgetChofer(pfreparto),chofer,false);
        VehiculoPtr vehiculo = fsetVehiculo(fgetVehiculo(pfreparto),vehiculo,false);
        FechaPtr fechaSalida = fsetFecha(fgetFechaSalida(pfreparto),fechaSalida,false);
        FechaPtr fechaRetorno = fsetFecha(fgetFechaRetorno(pfreparto),fechaRetorno,false);

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
PARÁMETROS: puntero a la variable DIR (directorio) a usar
DEVUELVE: true si se pudo encontrar y abrir, false de lo contrario.
*/
bool abrirCarpeta(DIR *carpeta)
{
    carpeta = opendir("Archivos"); ///Chequeamos si existe la carpeta
    if(carpeta==NULL)
        return false;
    else
        return true;
}
/** OPERACIÓN: cierra una carpeta.
PRECONDICIÓN: debe haber una carpeta "Archivos" creada y abierta en el proyecto
POSTCONDICIÓN: se terminan de utilizar los recursos para mantener abierta la carpeta
PARÁMETROS: puntero a la variable DIR (directorio) a usar
DEVUELVE: true si se pudo cerrar, false de lo contrario.
*/
bool cerrarCarpeta(DIR *carpeta)
{
    int resultado = closedir(carpeta);
    if(-1==resultado)
        return false;
    else
        return true;
}
/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///


///*************************************************************************************************************

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ

//  listas de datos / estructuras
bool guardarPaquetes(CentroLogisticoPtr centroLogistico)
{
    DIR *carpeta;
    if(!abrirCarpeta(carpeta))
        crearCarpeta();

    FILE *archivo = fopen("Archivos/Lista de Paquetes.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getPaquetes(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getPaquetes(centroLogistico));

        while(!listaVacia(listaAux))
        {
            PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
            fsetPaquete(&fpaquete,paqueteAux,true);

            fwrite(&fpaquete,sizeof(fPaquete),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        cerrarCarpeta(carpeta);
        return true;
    }
}
bool guardarPersonas(CentroLogisticoPtr centroLogistico)
{
    DIR *carpeta;
    if(!abrirCarpeta(carpeta))
        crearCarpeta();

    FILE *archivo = fopen("Archivos/Lista de Personas.txt","w");

    if(archivo==NULL)
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
        cerrarCarpeta(carpeta);
        return true;
    }
}
bool guardarVehiculos(CentroLogisticoPtr centroLogistico)
{
    DIR *carpeta;
    if(!abrirCarpeta(carpeta))
        crearCarpeta();

    FILE *archivo = fopen("Archivos/Lista de Vehiculos.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getVehiculos(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        //fVehiculo fvehiculo;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getVehiculos(centroLogistico));

        while(!listaVacia(listaAux))
        {
            VehiculoPtr vehiculoAux = (VehiculoPtr)getCabecera(listaAux);

            fVehiculo fvehiculo;

            fsetVehiculo(&fvehiculo,vehiculoAux,true); ///NUEVO MÉTODO

            fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        cerrarCarpeta(carpeta);
        return true;
    }
}
bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    DIR *carpeta;
    if(!abrirCarpeta(carpeta))
        crearCarpeta();

    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Archivos/Lista de Repartos Abiertos.txt","w");
	else
		archivo = fopen("Archivos/Lista de Repartos Cerrados.txt","w");

    if(archivo==NULL)
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
        cerrarCarpeta(carpeta);
        return true;
    }
}
//  general
bool guardarTodo(CentroLogisticoPtr centroLogistico) //implementacion: llamará a las otras funciones de guardado
{
    DIR *carpeta;
    if(!abrirCarpeta(carpeta))
        crearCarpeta();

    FILE *archivo = fopen("Archivos/Nombre del Centro Logistico.txt","w");
    bool res = true; //a diferencia de las funciones anteriores, usamos una bandera para juntar al conjugado.
    if(archivo==NULL)
        res=false;
    else
    {
        char *temp = getNombreCentroLogistico(centroLogistico);
        int longStr = strlen(temp) + 2; //2 más que el original: 1 x el '\0', y 2 x el caracter que le agregaremos.

        char nombreCtroLog[longStr];
        strcpy(nombreCtroLog,temp);
        nombreCtroLog[longStr-1]='\n'; ///le agregamos el caracter especial para la apertura.
    ///Guardamos el nombre del centro logistico en un archivo aparte
        fwrite(nombreCtroLog,sizeof(char),longStr,archivo);
        fclose(archivo);
        cerrarCarpeta(carpeta);
    }
    res = res && guardarPaquetes(centroLogistico);
    res = res && guardarPersonas(centroLogistico);
    res = res && guardarVehiculos(centroLogistico);
    res = res && guardarRepartos(centroLogistico,true);
    res = res && guardarRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}


//  listas de datos (CentroLogistico)
bool abrirPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Paquetes.txt","r");

    if(archivo==NULL)
    {
        printf("\n\nARCHIVO = NULL");
        return false;
    }
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;

        for(int i=0;i<n;i++)
        {
            fread(&fpaquete,sizeof(fPaquete),1,archivo);

            PaquetePtr paqueteAux = fsetPaquete(&fpaquete,paqueteAux,false);
            agregarPaquete(centroLogistico,paqueteAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Personas.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);
        fPersona fpersona;

        for(int i=0;i<n;i++)
        {
            fread(&fpersona,sizeof(fPersona),1,archivo);

            PersonaPtr personaAux = fsetPersona(&fpersona,personaAux,false);
            agregarPersona(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Archivos/Lista de Vehiculos.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;

        for(int i=0;i<n;i++)
        {
            fread(&fvehiculo,sizeof(fVehiculo),1,archivo);

            VehiculoPtr vehiculoAux = fsetVehiculo(&fvehiculo,vehiculoAux,false);
            agregarVehiculo(centroLogistico,vehiculoAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
    if(esRepartoAbierto)
        archivo = fopen("Archivos/Lista de Repartos Abiertos.txt","r");
    else
        archivo = fopen("Archivos/Lista de Repartos Cerrados.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fReparto freparto;

        for(int i=0;i<n;i++)
        {
            fread(&freparto,sizeof(fReparto),1,archivo);

            RepartoPtr repartoAux = fsetReparto(&freparto,repartoAux,false);
            if(esRepartoAbierto)
                agregarReparto(centroLogistico,repartoAux,true);
            else
                agregarReparto(centroLogistico,repartoAux,false);
        }
        fclose(archivo);
        return true;
    }
}
//  general

CentroLogisticoPtr abrirTodo() //implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
{
    DIR *carpeta;
    bool res = abrirCarpeta(carpeta); //Primero, chequeamos que la carpeta exista.
    if(res) //Si existe, hacemos lo demás
    {
    //Luego, recuperamos el nombre del centro logistico.
        FILE *archivo = fopen("Archivos/Nombre del Centro Logistico.txt","r");

        char nombreCtroLog[100];

        if(archivo==NULL)
            res=false;
        else
        {
            if(LeerString(archivo,nombreCtroLog,100,'\n')==EOF)
                res=false; ///volvemos a poner false si el archivo abre, pero está vacío por alguna razón.
        }

        CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);

        res = res && abrirPaquetes(centroLogistico);
        res = res && abrirPersonas(centroLogistico);
        res = res && abrirVehiculos(centroLogistico);
        res = res && abrirRepartos(centroLogistico,true);
        res = res && abrirRepartos(centroLogistico,false);
    ///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
    ///De esta manera, si alguna funcion falla, la booleana será falso, y nos daremos cuenta.
        cerrarCarpeta(carpeta);
        if(res)
            return centroLogistico;
        else
            return NULL;
    }
    else
        return NULL; //retornamos null si hubo algún error.
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
