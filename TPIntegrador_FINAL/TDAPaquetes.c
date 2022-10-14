#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"
#include "TDAPaquetes.h"
#include "util.h"
#include "Pila.h"

PaquetePtr crearPaquete(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,int estado){
    PaquetePtr paquete=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    paquete->ID=ID;
    paquete->ancho=ancho;
    paquete->alto=alto;
    paquete->largo=largo;
    paquete->peso=peso;
    paquete->dirRetiro=dirRetiro;
    paquete->dirEntrega=dirEntrega;
    paquete->fechaEntrega=fechaEntrega;
    paquete->estado=estado;
    return paquete;
}


PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,int estado)
{
    PaquetePtr paquete = (PaquetePtr) obtenerMemoria(sizeof(Paquete));

    paquete->ID=ID;
    paquete->ancho=ancho;
    paquete->alto=alto;
    paquete->largo=largo;
    paquete->peso=peso;

    paquete->dirRetiro=crearDomicilio(calleRetiro,alturaRetiro,localidadRetiro);
    paquete->dirEntrega=crearDomicilio(calleEntrega,alturaEntrega,localidadEntrega);
    paquete->fechaEntrega=crearFecha(dia,mes,anio,hora,minuto);

    paquete->estado=estado;

    return paquete;
}

PaquetePtr destruirPaquete(PaquetePtr paquete)
{
    paquete->dirRetiro=destruirDomicilio(paquete->dirRetiro);
    paquete->dirEntrega=destruirDomicilio(paquete->dirEntrega);
    paquete->fechaEntrega=destruirFecha(paquete->fechaEntrega);
    free(paquete);
    return NULL;
}

int getID(PaquetePtr paquete)
{
    return paquete->ID;
}
int getAncho(PaquetePtr paquete)
{
    return paquete->ancho;
}
int getAlto(PaquetePtr paquete)
{
    return paquete->alto;
}
int getLargo(PaquetePtr paquete)
{
    return paquete->largo;
}
int getPeso(PaquetePtr paquete)
{
    return paquete->peso;
}
DomicilioPtr getDirRetiro(PaquetePtr paquete)
{
    return paquete->dirRetiro;
}
DomicilioPtr getDirEntrega(PaquetePtr paquete)
{
    return paquete->dirEntrega;
}
FechaPtr getFechaEntrega(PaquetePtr paquete)
{
    return paquete->fechaEntrega;
}
int getEstado(PaquetePtr paquete)
{
    return paquete->estado;
}


void setID(PaquetePtr paquete,int ID)
{
    paquete->ID=ID;
}
void setAncho(PaquetePtr paquete,int ancho)
{
    paquete->ancho=ancho;
}
void setAlto(PaquetePtr paquete,int alto)
{
    paquete->alto=alto;
}
void setLargo(PaquetePtr paquete,int largo)
{
    paquete->largo=largo;
}
void setPeso(PaquetePtr paquete,int peso)
{
    paquete->peso=peso;
}
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro)
{
    paquete->dirRetiro=dirRetiro;
}
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega)
{
    paquete->dirEntrega=dirEntrega;
}
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega)
{
    paquete->fechaEntrega=fechaEntrega;
}
void setEstado(PaquetePtr paquete,int estado)
{
    paquete->estado=estado;
}

void mostrarPaquete(PaquetePtr paquete)
{
    mostrarEstadopaquete(paquete);
    printf("\tAncho: %d\n",getAncho(paquete));
    printf("\tAlto: %d\n",getAlto(paquete));
    printf("\tLargo: %d\n",getLargo(paquete));
    printf("\tPeso: %d\n",getPeso(paquete));
    printf("\tDireccion de Retiro: ");
    mostrarDomicilio(getDirRetiro(paquete));
    printf("\tDireccion de Entrega: ");
    mostrarDomicilio(getDirEntrega(paquete));
    printf("FECHA DE ENTREGA: \n");
    mostrarFecha(getFechaEntrega(paquete));
}


void helpEstadoPaquete() //muestra que relacion hay entre cada numero y cada estado posible del paquete.
{
    printf("Codigo de estados: \n");
    printf("\t0 = En Deposito\n");
    printf("\t1 = En Curso\n");
    printf("\t2 = Retirado\n");
    printf("\t3 = Entregado\n");
    printf("\t4 = Demorado\n");
    printf("\t5 = Suspendido\n\n");
}
void mostrarEstadopaquete(PaquetePtr paquete) //muestra solo el estado actual del paquete recibido.
{
    switch(getEstado(paquete))
    {
    case 0:
        printf("Estado del Paquete #%d = En Deposito.\n\n",getID(paquete));
        break;
    case 1:
        printf("Estado del Paquete #%d = En Curso.\n\n",getID(paquete));
        break;
    case 2:
        printf("Estado del Paquete #%d = Retirado.\n\n",getID(paquete));
        break;
    case 3:
        printf("Estado del Paquete #%d = Entregado.\n\n",getID(paquete));
        break;
    case 4:
        printf("Estado del Paquete #%d = Demorado.\n\n",getID(paquete));
        break;
    case 5:
        printf("Estado del Paquete #%d = Suspendido.\n\n",getID(paquete));
        break;
    default:
        printf("Estado del Paquete #%d = ERROR.\n",getID(paquete));
        break;
    }
}


bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2)
{
    bool matchID,matchResto;

    DomicilioPtr dirRetiro1 = getDirRetiro(paquete1);
    DomicilioPtr dirRetiro2 = getDirRetiro(paquete2);
    DomicilioPtr dirEntrega1 = getDirEntrega(paquete1);
    DomicilioPtr dirEntrega2 = getDirEntrega(paquete2);

    FechaPtr fechaEntrega1 = getFechaEntrega(paquete1);
    FechaPtr fechaEntrega2 = getFechaEntrega(paquete2);
    int difFechas[3];
    calcularDiferenciaFechas(fechaEntrega1,fechaEntrega2,difFechas);

//primero, se verifica si el ID de paquete1 es igual al del paquete2
    matchID = getID(paquete1) == getID(paquete2);
//luego, se verifica si las dimensiones de paquete1 son iguales
    matchResto = getAncho(paquete1) == getAncho(paquete2);
    matchResto = matchResto && getAlto(paquete1) == getAlto(paquete2);
    matchResto = matchResto && getLargo(paquete1) == getLargo(paquete2);
    matchResto = matchResto && getPeso(paquete1) == getPeso(paquete2);
//después, se verifica si las direcciones de retiro de paquete1 coinciden con las del paquete2
    matchResto = matchResto && strcmp(getCalle(dirRetiro1),getCalle(dirRetiro2))==0;
    matchResto = matchResto && getAltura(dirRetiro1) == getAltura(dirRetiro2);
    matchResto = matchResto && strcmp(getLocalidad(dirRetiro1),getLocalidad(dirRetiro2))==0;
//posteriormente, se verifica si las direcciones de entrega de paquete1 coinciden con las del paquete2
    matchResto = matchResto && strcmp(getCalle(dirEntrega1),getCalle(dirEntrega2))==0;
    matchResto = matchResto && getAltura(dirEntrega1) == getAltura(dirEntrega2);
    matchResto = matchResto && strcmp(getLocalidad(dirEntrega1),getLocalidad(dirEntrega2))==0;
//finalmente, se chequea la fecha de entrega
    matchResto = matchResto && difFechas[0]==0 && difFechas[1]==0 && difFechas[2]==0;

    //la condicion final será: "si coinciden los ID, o bien el resto de parámetros, o bien todo..."
    return matchID || matchResto;
}
