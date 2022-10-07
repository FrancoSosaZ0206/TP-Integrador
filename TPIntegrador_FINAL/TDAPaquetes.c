#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"
#include "TDAPaquetes.h"
#include "util.h"

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

PaquetePtr crearPaqueteNuevo(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,PersonaPtr cliente,int estado){
    PaquetePtr paquete=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    paquete->ID=ID;
    paquete->ancho=ancho;
    paquete->alto=alto;
    paquete->largo=largo;
    paquete->peso=peso;
    paquete->dirRetiro=dirRetiro;
    paquete->dirEntrega=dirEntrega;
    paquete->fechaEntrega=fechaEntrega;
    paquete->cliente=cliente;
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

PersonaPtr getClientePaquete(PaquetePtr paquete){
    return paquete->cliente;
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

void setClientePaquete(PaquetePtr paquete, PersonaPtr cliente){
    paquete->cliente = cliente;
}

void mostrarPaquete(PaquetePtr paquete)
{
    printf("Paquete #%d\n",getID(paquete));
    switch(getEstado(paquete)){
    case 0:
        printf("\tEstado: En Deposito\n");
        break;
    case 1:
        printf("\tEstado: En Curso\n");
        break;
    case 2:
        printf("\tEstado: Retirado\n");
        break;
    case 3:
        printf("\tEstado: Entregado\n");
        break;
    case 4:
        printf("\tEstado: Demorado\n");
        break;
    case 5:
        printf("\tEstado: Suspendido\n");
        break;
    default:
        printf("\tEstado: ERROR\n");
        break;
    }
    printf("\tAncho: %d\n",getAncho(paquete));
    printf("\tAlto: %d\n",getAlto(paquete));
    printf("\tLargo: %d\n",getLargo(paquete));
    printf("\tPeso: %d\n",getPeso(paquete));
    printf("\tDireccion de Retiro: ");
    mostrarDomicilio(getDirRetiro(paquete));
    printf("\tDireccion de Entrega: ");
    mostrarDomicilio(getDirEntrega(paquete));
    char *bufferFecha;
    traerFechaYHora(getFechaEntrega(paquete),bufferFecha);
    printf("\tFecha y Hora de Entrega: %s\n",bufferFecha);
}

void mostrarPaqueteNuevo(PaquetePtr paquete)
{
    printf("Paquete #%d\n",getID(paquete));
    switch(getEstado(paquete)){
    case 0:
        printf("\tEstado: En Deposito\n");
        break;
    case 1:
        printf("\tEstado: En Curso\n");
        break;
    case 2:
        printf("\tEstado: Retirado\n");
        break;
    case 3:
        printf("\tEstado: Entregado\n");
        break;
    case 4:
        printf("\tEstado: Demorado\n");
        break;
    case 5:
        printf("\tEstado: Suspendido\n");
        break;
    default:
        printf("\tEstado: ERROR\n");
        break;
    }
    printf("\tAncho: %d\n",getAncho(paquete));
    printf("\tAlto: %d\n",getAlto(paquete));
    printf("\tLargo: %d\n",getLargo(paquete));
    printf("\tPeso: %d\n",getPeso(paquete));
    printf("\tDireccion de Retiro: ");
    mostrarDomicilio(getDirRetiro(paquete));
    printf("\tDireccion de Entrega: ");
    mostrarDomicilio(getDirEntrega(paquete));
    /*char *bufferFecha;
    traerFechaYHora(getFechaEntrega(paquete),bufferFecha);
    printf("\tFecha y Hora de Entrega: %s\n",bufferFecha);*/
    mostrarFecha(getFechaEntrega(paquete));
    mostrarPersona(getClientePaquete(paquete));
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
