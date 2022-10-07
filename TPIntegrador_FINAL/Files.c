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
        pffecha->diaJuliano=getDiaJuliano(fecha);
        pffecha->hora=getHora(fecha);
        pffecha->minuto=getMinuto(fecha);
    }
    else ///asumimos que la estructura está vacía y la creamos.
        fecha = crearFechaDirect(fgetDiaJuliano(pffecha),fgetHora(pffecha),fgetMinuto(pffecha));
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
        DomicilioPtr domicilio;
        CuilPtr cuil;
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
        DomicilioPtr dirRetiro;
        DomicilioPtr dirEntrega;
        FechaPtr fechaEntrega;

        fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

        paquete=crearPaquete(fgetID(pfpaquete),fgetAncho(pfpaquete),fgetAlto(pfpaquete),fgetLargo(pfpaquete),fgetPeso(pfpaquete),dirRetiro,dirEntrega,fechaEntrega,fgetEstado(pfpaquete));
    }
}
void fsetVehiculo(fVehiculoPtr pfvehiculo,VehiculoPtr vehiculo,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pfvehiculo->tipo=getTipoVehiculo(vehiculo);

        strcpy(pfvehiculo->marca,getMarca(vehiculo));
        strcpy(pfvehiculo->modelo,getModelo(vehiculo));
        strcpy(pfvehiculo->patente,getPatente(vehiculo));
    }
    else ///asumimos que la estructura está vacía y la creamos.
        vehiculo=crearVehiculo(fgetTipoVehiculo(pfvehiculo),fgetMarca(pfvehiculo),fgetModelo(pfvehiculo),fgetPatente(pfvehiculo));
}
void fsetReparto(fRepartoPtr pfreparto,RepartoPtr reparto,bool setParaGuardar)
{
    int n=0;
    PaquetePtr paqueteAux;

    if(setParaGuardar)
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
        PersonaPtr chofer;
        VehiculoPtr vehiculo;
        FechaPtr fechaSalida;
        FechaPtr fechaRetorno;

        fsetPersona(fgetChofer(pfreparto),chofer,false);
        fsetVehiculo(fgetVehiculo(pfreparto),vehiculo,false);
        fsetFecha(fgetFechaSalida(pfreparto),fechaSalida,false);
        fsetFecha(fgetFechaRetorno(pfreparto),fechaRetorno,false);

        PilaPtr paquetes = crearPila();
        n=pfreparto->tamanioPilaPaq;

        for(int i=n;i>0;i--) ///lo hacemos al revés para mantener el orden original de la pila.
        {
            fsetPaquete(&pfreparto->paquetes[i],paqueteAux,false);
            apilar(paquetes,(PaquetePtr)paqueteAux);
        }
        reparto = armarReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    }

    paqueteAux = NULL;
}


///*************************************************************************************************************

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ


//Escritura
//Precondición: La variable estructura / lista que se pase deberá haber sido creada previamente.
//Postcondición: se guarda los contenidos de la estructura / lista en un archivo dedicado al tipo de estructura / lista.
//Devuelve true si se pudo guardar, false de lo contrario (if archivo != NULL)
//  datos / estructuras individuales
bool guardarCuil(CuilPtr cuil)
{
    FILE *archivo = fopen("Cuil.txt","w");
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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


    if(archivo==NULL)
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
        return true;
    }
}
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","w");

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
        return true;
    }
}
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Vehiculos.txt","w");

    if(archivo==NULL)
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
        return true;
    }
}
//  general
bool guardarTodo(CentroLogisticoPtr centroLogistico) //implementacion: llamará a las otras funciones de guardado
{
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","w");
    //a diferencia de las funciones anteriores, usamos una bandera para juntar al conjugado
    bool res = true;
    if(archivo==NULL)
        res=false;
    else{
        char *temp = getNombreCentroLogistico(centroLogistico);
        //2 más que el original: 1 x el '\0', y 2 x el caracter que le agregaremos.
        int longStr = strlen(temp) + 2;
        char nombreCtroLog[longStr];
        strcpy(nombreCtroLog,temp);
        nombreCtroLog[longStr-1]='\n'; ///le agregamos el caracter especial para la apertura.
    ///Guardamos el nombre del centro logistico en un archivo aparte
        fwrite(nombreCtroLog,sizeof(char),longStr,archivo);
        fclose(archivo);
    }
    res = res && guardarListaPaquetes(centroLogistico);
    res = res && guardarListaPersonas(centroLogistico);
    res = res && guardarListaVehiculos(centroLogistico);
    res = res && guardarListaRepartos(centroLogistico,true);
    res = res && guardarListaRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}

//  datos / estructuras individuales
bool abrirCuil(CuilPtr cuil)
{
    FILE *archivo = fopen("Cuil.txt","r");
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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
    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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

    if(archivo==NULL)
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
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Personas.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fPersona fpersona;
        PersonaPtr personaAux;

        for(int i=0;i<n;i++)
        {
            fread(&fpersona,sizeof(fPersona),1,archivo);

            fsetPersona(&fpersona,personaAux,false);
            agregarPersona(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","r");

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
        PaquetePtr paqueteAux;

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

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;
        VehiculoPtr vehiculoAux;

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


    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fReparto freparto;
        RepartoPtr repartoAux;

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
//  general
CentroLogisticoPtr abrirTodo() //implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
{
    //Primero, recuperamos el nombre del centro logistico.
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","r");
    bool res=true;

    char *nombreCtroLog;

    if(archivo==NULL)
        res=false;
    else
    {
        if(LeerString(archivo,nombreCtroLog,100,'\n')==EOF)
            res=false; ///volvemos a poner false si el archivo abre, pero está vacío por alguna razón.
    }

    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);

    res = res && abrirListaPaquetes(centroLogistico);
    res = res && abrirListaPersonas(centroLogistico);
    res = res && abrirListaVehiculos(centroLogistico);
    res = res && abrirListaRepartos(centroLogistico,true);
    res = res && abrirListaRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguna funcion falla, la booleana será falso, y nos daremos cuenta.
    if(res)
        return centroLogistico;
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
