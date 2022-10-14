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

const bool mostradoActivado=false;

///*************************************************************************************************************

///                  Estructuras Especiales (PRIVADAS, solo usar en las funciones de este archivo)


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
    PaquetePtr paqueteAux=0;

    if(setParaGuardar)
    {
        fsetPersona(fgetChofer(pfreparto),getChofer(reparto),true);
        fsetVehiculo(fgetVehiculo(pfreparto),getVehiculo(reparto),true);
        fsetFecha(fgetFechaSalida(pfreparto),getFechaSalida(reparto),true);
        fsetFecha(fgetFechaRetorno(pfreparto),getFechaRetorno(reparto),true);

        while(!pilaVacia(getPaquetesReparto(reparto)))
        {
            paqueteAux = descargarPaquete(reparto);
            fsetPaquete(&pfreparto->paquetes[n],paqueteAux,true);
            n++;
        }
        pfreparto->tamanioPilaPaq = n;
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        PersonaPtr chofer=0;
        VehiculoPtr vehiculo=0;
        FechaPtr fechaSalida=0;
        FechaPtr fechaRetorno=0;

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
        reparto = crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    }
    paqueteAux = NULL;
}


///*************************************************************************************************************

///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ

//  listas de datos / estructuras
bool guardarPersonas(CentroLogisticoPtr centroLogistico)
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
bool guardarPaquetes(CentroLogisticoPtr centroLogistico)
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
bool guardarVehiculos(CentroLogisticoPtr centroLogistico)
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
bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
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
    bool res = true; //a diferencia de las funciones anteriores, usamos una bandera para juntar al conjugado.
    if(archivo==NULL)
        res=false;
    else
    {
        char temp[100];
        strcpy(temp,getNombreCentroLogistico(centroLogistico));
        fwrite(temp,sizeof(char),100,archivo);
        fclose(archivo);
    }
    res = res && guardarPaquetes(centroLogistico);
    res = res && guardarPersonas(centroLogistico);
    res = res && guardarVehiculos(centroLogistico);
    res = res && GuardarRepartosNuevo(centroLogistico,true);
    res = res && GuardarRepartosNuevo(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}


//  listas de datos (CentroLogistico)
bool abrirPersonas(CentroLogisticoPtr centroLogistico)
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
        PersonaPtr personaAux=0;

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
bool abrirPaquetes(CentroLogisticoPtr centroLogistico)
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
bool abrirVehiculos(CentroLogisticoPtr centroLogistico)
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
bool abrirRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
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
//  general

CentroLogisticoPtr abrirTodo() //implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
{
    //Primero, recuperamos el nombre del centro logistico.
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","r");
    bool res=true;

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



///-----------------------------------------------------------------------------------///

void mostrarRepartoEstatico(fReparto RE)
{
    printf("NOMBRE: %s\n", RE.chofer.nombre);
    printf("TIPO: %d\n", RE.vehiculo.tipo);
    printf("DIA1: %d\n", RE.fechaSalida.hora);
    printf("DIA2: %d\n", RE.fechaRetorno.hora);
    printf("ALTO: %d\n", RE.paquetes[0].alto);
}

void funcionDinamicoEstaticoReparto()
{
    fReparto repartoEstatico;
    RepartoPtr repartoDinamico;
    DomicilioPtr domicilioChofer1=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro1=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega1=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
    FechaPtr fechaSalida1=crearFechaDirect(2500000,16,45); //Para el reparto
    FechaPtr fechaRetorno1=crearFechaDirect(2500000,17,45); //Para el reparto
    FechaPtr fechaEntrega1=crearFechaDirect(2500000,18,45);
    CuilPtr cuil1=crearCuil("20346547546");
    PersonaPtr chofer1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,true);
    PaquetePtr paquete1=crearPaquete(1,4,5,2,65,dirRetiro1,dirEntrega1,fechaEntrega1,0);
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    PilaPtr pilaPaquetes = crearPila();
    apilar(pilaPaquetes,(PaquetePtr)paquete1);
    repartoDinamico=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,pilaPaquetes);
    fsetReparto(&repartoEstatico,repartoDinamico,true);
    mostrarRepartoEstatico(repartoEstatico);
    FILE* a;
    a=fopen("PROBANDO.bin","wb");
    fwrite(&repartoEstatico,sizeof(fReparto),1,a);
    fclose(a);
    fReparto repartoEstaticoRespaldo;
    a=fopen("PROBANDO.bin","rb");
    fread(&repartoEstaticoRespaldo,sizeof(fReparto),1,a);
    fclose(a);
    mostrarRepartoEstatico(repartoEstaticoRespaldo);
    system("pause");
}

///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

            ///SECCION DE UTILIZACION DE ARCHIVOS///
        ///TODAS LAS FUNCIONES EN ADELANTE FUNCIONAN///

///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///
///---------------------------------------------------------------------------///

FechaPtr crearFechaDirectNuevo(fFechaPtr FE)
{
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

PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PE)
{
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
    reparto->listaPaquetes=paquetes;
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

///---------------------------------------------------------------------------///


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
    if(mostradoActivado){
        ListaPtr LA=LV;
        while(!listaVacia(LA)){
            VD=getCabecera(LA);
            mostrarVehiculo(VD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LV;
}

///-----------------------------------------------------------------------///


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

void GuardarListaClientesNuevo(ListaPtr listaClientes)
{
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

ListaPtr LeerListaClientesNuevo()
{
    FILE* arch;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LC=crearLista();
    arch=fopen("ClientesPrueba.bin","rb");
    arch=fopen("ClientesPrueba.bin","rb");
    fread(&PE,sizeof(fPersona),1,arch);
    while(!feof(arch)){
        PD=PasajePersonaDinamico(&PE,PD,true);
        agregarDatoLista(LC,(PersonaPtr)PD);
        fread(&PE,sizeof(fPersona),1,arch);
    }
    fclose(arch);
    if(mostradoActivado){
        ListaPtr LA=LC;
        while(!listaVacia(LA)){
            PD=getCabecera(LA);
            mostrarPersona(PD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LC;
}

void GuardarListaChoferesNuevo(ListaPtr listaClientes)
{
    FILE* arch;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LA=listaClientes;
    arch=fopen("ChoferesPrueba.bin","wb");
    fclose(arch);
    arch=fopen("ChoferesPrueba.bin","ab");
    while(!listaVacia(LA)){
        PD=getCabecera(LA);
        PasajePersonaDinamico(&PE,PD,false);
        fwrite(&PE,sizeof(fPersona),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}

ListaPtr LeerListaChoferesNuevo()
{
    FILE* arch;
    fPersona PE;
    PersonaPtr PD;
    ListaPtr LC=crearLista();
    arch=fopen("ChoferesPrueba.bin","rb");
    fread(&PE,sizeof(fPersona),1,arch);
    while(!feof(arch)){
        PD=PasajePersonaDinamico(&PE,PD,true);
        agregarDatoLista(LC,(PersonaPtr)PD);
        fread(&PE,sizeof(fPersona),1,arch);
    }
    fclose(arch);
    if(mostradoActivado){
        ListaPtr LA=LC;
        while(!listaVacia(LA)){
            PD=getCabecera(LA);
            mostrarPersona(PD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LC;
}

///-----------------------------------------------------------------------///

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
    if(mostradoActivado){
        ListaPtr LA=LP;
        while(!listaVacia(LA)){
            PD=getCabecera(LA);
            mostrarPaquete(PD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LP;
}

///-----------------------------------------------------------------------///


RepartoPtr PasajeRepartoDinamico(fRepartoPtr RE, RepartoPtr RD, bool ADinamico){
    if(ADinamico){
        RD=crearRepartoDirectoNuevo(RE);
    }else{
        PasajePersonaDinamico(&RE->chofer,RD->chofer,false);
        PasajeVehiculoDinamico(&RE->vehiculo,RD->vehiculo,false);
        PasajeFechaDinamico(&RE->fechaSalida,RD->fechaSalida,false);
        PasajeFechaDinamico(&RE->fechaRetorno,RD->fechaRetorno,false);
        int total=(int)longitudLista(getListaPaquetesReparto(RD));
        RE->tamanioPilaPaq=total;
        ListaPtr LA=(ListaPtr)getListaPaquetesReparto(RD);
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

void GuardarListaRepartosAbiertosNuevo(ListaPtr listaRepartos){
    FILE* arch;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr LA=listaRepartos;
    arch=fopen("RepartosAbiertosPrueba.bin","wb");
    fclose(arch);
    arch=fopen("RepartosAbiertosPrueba.bin","ab");
    while(!listaVacia(LA)){
        RD=(RepartoPtr)getCabecera(LA);
        PasajeRepartoDinamico(&RE,RD,false);
        fwrite(&RE,sizeof(fReparto),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}

ListaPtr LeerListaRepartosAbiertosNuevo(){
    FILE* arch;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr LR=crearLista();
    arch=fopen("RepartosAbiertosPrueba.bin","rb");
    fread(&RE,sizeof(fReparto),1,arch);
    while(!feof(arch)){
        RD=PasajeRepartoDinamico(&RE,RD,true);
        agregarDatoLista(LR,(RepartoPtr)RD);
        fread(&RE,sizeof(fReparto),1,arch);
    }
    fclose(arch);
    ListaPtr LA=LR;
    if(mostradoActivado){
        while(!listaVacia(LA)){
            RD=getCabecera(LA);
            mostrarReparto(RD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LR;
}

void GuardarListaRepartosCerradosNuevo(ListaPtr listaRepartos){
    FILE* arch;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr LA=listaRepartos;
    arch=fopen("RepartosCerradosPrueba.bin","wb");
    fclose(arch);
    arch=fopen("RepartosCerradosPrueba.bin","ab");
    while(!listaVacia(LA)){
        RD=(RepartoPtr)getCabecera(LA);
        PasajeRepartoDinamico(&RE,RD,false);
        fwrite(&RE,sizeof(fReparto),1,arch);
        LA=getResto(LA);
    }
    fclose(arch);
}

ListaPtr LeerListaRepartosCerradosNuevo(){
    FILE* arch;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr LR=crearLista();
    arch=fopen("RepartosCerradosPrueba.bin","rb");
    fread(&RE,sizeof(fReparto),1,arch);
    while(!feof(arch)){
        RD=PasajeRepartoDinamico(&RE,RD,true);
        agregarDatoLista(LR,(RepartoPtr)RD);
        fread(&RE,sizeof(fReparto),1,arch);
    }
    fclose(arch);
    ListaPtr LA=LR;
    if(mostradoActivado){
        while(!listaVacia(LA)){
            RD=getCabecera(LA);
            mostrarReparto(RD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return LR;
}

bool GuardarRepartosNuevo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE* arch;
    bool guardado1=false;
    bool guardado2=false;
    fReparto RE;
    RepartoPtr RD;
    ListaPtr listaRepartos=getRepartos(centroLogistico,esRepartoAbierto);
    ListaPtr LA=crearLista();
    agregarLista(LA,listaRepartos);
    if(esRepartoAbierto)
    {
        arch=fopen("RepartosAbiertosPrueba.bin","wb");
        if(arch!=NULL)
        {
            guardado1=true;
        }
        fclose(arch);
        arch=fopen("RepartosAbiertosPrueba.bin","ab");
        if(arch!=NULL)
        {
            guardado2=true;
        }
    }
    else
    {
        arch=fopen("RepartosCerradosPrueba.bin","wb");
        if(arch!=NULL)
        {
            guardado1=true;
        }
        fclose(arch);
        arch=fopen("RepartosCerradosPrueba.bin","ab");
        if(arch!=NULL)
        {
            guardado2=true;
        }
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
    return guardado1 && guardado2;
}

bool LeerRepartosNuevo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE* arch;
    bool guardado=false;
    fReparto RE;
    RepartoPtr RD;
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
    ListaPtr LA=getRepartos(centroLogistico,esRepartoAbierto);
    if(mostradoActivado)
    {
        while(!listaVacia(LA))
        {
            RD=getCabecera(LA);
            mostrarReparto(RD);
            LA=getResto(LA);
        }
        system("pause");
    }
    return guardado;
}

///------------------------------------------------------------///

void GuardarTodoNuevo(CentroLogisticoPtr centroLogistico)
{
    FILE* arch;
    char nombreCentroLog[100];
    strcpy(nombreCentroLog,getNombreCentroLogistico(centroLogistico));
    arch=fopen("NombreCentroLogistico.bin","wb");
    fwrite(&nombreCentroLog,sizeof(100),1,arch);
    fclose(arch);
    GuardarListaClientesNuevo(getClientes(centroLogistico));
    GuardarListaChoferesNuevo(getChoferes(centroLogistico));
    GuardarListaPaquetesNuevo(getPaquetes(centroLogistico));
    GuardarListaVehiculosNuevo(getVehiculos(centroLogistico));
    GuardarListaRepartosAbiertosNuevo(getRepartos(centroLogistico,true));
    GuardarListaRepartosCerradosNuevo(getRepartos(centroLogistico,false));
}

CentroLogisticoPtr AbrirTodoNuevo()
{
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido("");
    FILE* arch;
    char nombreCentroLog[100];
    arch=fopen("NombreCentroLogistico.bin","rb");
    fread(&nombreCentroLog,sizeof(100),1,arch);
    fclose(arch);
    setRepartos(centroLogistico,LeerListaRepartosAbiertosNuevo(),true);
    setRepartos(centroLogistico,LeerListaRepartosCerradosNuevo(),false);
    setVehiculos(centroLogistico,LeerListaVehiculosNuevo());
    setPaquetes(centroLogistico,LeerListaPaquetesNuevo());
    setClientes(centroLogistico,LeerListaClientesNuevo());
    setChoferes(centroLogistico,LeerListaChoferesNuevo());
    return centroLogistico;
}
