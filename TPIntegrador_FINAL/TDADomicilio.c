#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDADomicilio.h"
#include "util.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad)
{
    DomicilioPtr domicilio=(DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    domicilio->calle=crearStringDinamico(calle);
    domicilio->altura=altura;
    domicilio->localidad=crearStringDinamico(localidad);
    return domicilio;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

DomicilioPtr destruirDomicilio(DomicilioPtr domicilio)
{
    destruirStringDinamico(getCalle(domicilio)); //no probé esta funcion con estructuras, así que si sale mal,
    destruirStringDinamico(getLocalidad(domicilio)); //cambiamos esto por el clásico free(domicilio->...)
    free(domicilio);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setCalle(DomicilioPtr domicilio,char *calle)
{
    destruirStringDinamico(domicilio->calle);
    char* NuevaCalle = crearStringDinamico(calle);
    domicilio->calle = NuevaCalle;
}

void setAltura(DomicilioPtr domicilio,int altura)
{
    domicilio->altura=altura;
}

void setLocalidad(DomicilioPtr domicilio,char *localidad)
{
    destruirStringDinamico(domicilio->localidad);
    char* NuevaLocalidad = crearStringDinamico(localidad);
    domicilio->localidad = NuevaLocalidad;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

char *getCalle(DomicilioPtr domicilio)
{
    return domicilio->calle;
}

int getAltura(DomicilioPtr domicilio)
{
    return domicilio->altura;
}

char *getLocalidad(DomicilioPtr domicilio)
{
    return domicilio->localidad;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE OPERACIONES CON DOMICILIO///
///-----------------------------------------------------------------------------------------------------------///

void mostrarDomicilio(DomicilioPtr domicilio)
{
    printf(" %s %d, %s\n",getCalle(domicilio),getAltura(domicilio),getLocalidad(domicilio));
}

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2)
{
    bool condicion = strcmp(getCalle(domicilio1),getCalle(domicilio2)) == 0;
    condicion = condicion && getAltura(domicilio1) == getAltura(domicilio2);
    return condicion && strcmp(getLocalidad(domicilio1),getLocalidad(domicilio2)) == 0;
}

///-----------------------------------------------------------------------------------------------------------///
                        ///SECCION DE MENUES DE OPERACIONES CON EL DOMICILIO///
///-----------------------------------------------------------------------------------------------------------///

DomicilioPtr cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura = 0;
    char localidad[100];

    printf("\n\n\t\t Calle: ");
    seleccionarString(calle);

    printf("\n\t\t Altura: ");
    altura = seleccionarNumero();

    printf("\n\t\t Localidad: ");
    seleccionarString(localidad);

    domicilio = crearDomicilio(calle,altura,localidad);

    return domicilio;
}

void actualizarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura = 0;
    char localidad[100];

    printf("\n\n\t\t Calle: ");
    seleccionarString(calle);

    printf("\n\t\t Altura: ");
    altura = seleccionarNumero();

    printf("\n\t\t Localidad: ");
    seleccionarString(localidad);

    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}
