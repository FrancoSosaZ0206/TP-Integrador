#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"
#include "Files.h"

#include <sys/stat.h>
#include <dirent.h>

/// ///////////////////////////////////////////////////////////////////////////////////////////////// ///

///                                                 MACROS

const char *DOMICILIOS_OUT = "%s %d, %s\n";
const char *DOMICILIOS_IN = "%[^ ]%*c %d, %[^\n]%*c\n";
const char *FECHAS_OUT = "%s\n";
const char *FECHAS_IN = "%[^\n]%*c\n";
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

    fprintf(a,"LISTA DE PAQUETES (%d)",longitudLista(listaAux));
    for(int i=1;!listaVacia(listaAux);i++)
    {
        PaquetePtr paqueteAux = getCabecera(listaAux);

        DomicilioPtr dirRetiro = getDirRetiro(paqueteAux);
        DomicilioPtr dirEntrega = getDirEntrega(paqueteAux);
        char fechaEntregaStr[18];
        traerFechaYHora(getFechaEntrega(paqueteAux),fechaEntregaStr);

        fprintf(a,"\n\n------------------------------------------\n\n");
        fprintf(a,"Paquete #%d\n\n",getID(paqueteAux));

        switch(getEstado(paqueteAux))
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

        fprintf(a,"Ancho, Alto y Largo: %d, %d, %d\n",getAncho(paqueteAux),
                                                      getAlto(paqueteAux),
                                                      getLargo(paqueteAux));
        fprintf(a,"Peso: %d\n",getPeso(paqueteAux));
        fprintf(a,"Direccion de Retiro: ");
        fprintf(a,DOMICILIOS_OUT,getCalle(dirRetiro),getAltura(dirRetiro),getLocalidad(dirRetiro));
        fprintf(a,"Direccion de Entrega: ");
        fprintf(a,DOMICILIOS_OUT,getCalle(dirEntrega),getAltura(dirEntrega),getLocalidad(dirEntrega));
        fprintf(a,"Fecha de Entrega: ");
        fprintf(a,FECHAS_OUT,fechaEntregaStr);

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
        PaquetePtr paqueteAux=NULL;

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
    }

    fclose(a);
    return true;
}


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
