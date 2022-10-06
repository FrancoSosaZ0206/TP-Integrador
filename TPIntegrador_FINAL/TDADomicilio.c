#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDADomicilio.h"
#include "util.h"

DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad)
{
    DomicilioPtr domicilio=(DomicilioPtr)obtenerMemoria(sizeof(Domicilio));

    domicilio->calle=crearStringDinamico(calle);

    domicilio->altura=altura;

    domicilio->localidad=crearStringDinamico(localidad);

    return domicilio;
}

DomicilioPtr destruirDomicilio(DomicilioPtr domicilio)
{
    destruirStringDinamico(getCalle(domicilio)); //no probé esta funcion con estructuras, así que si sale mal,
    destruirStringDinamico(getLocalidad(domicilio)); //cambiamos esto por el clásico free(domicilio->...)
    free(domicilio);
    return NULL;
}



void setCalle(DomicilioPtr domicilio,char *calle)
{
    strcpy(domicilio->calle,calle);
}

void setAltura(DomicilioPtr domicilio,int altura)
{
    domicilio->altura=altura;
}

void setLocalidad(DomicilioPtr domicilio,char *localidad)
{
    strcpy(domicilio->localidad,localidad);
}



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

void mostrarDomicilio(DomicilioPtr domicilio)
{
    printf("%s %d, %s\n",getCalle(domicilio),getAltura(domicilio),getLocalidad(domicilio));
}

bool domiciliosIguales(DomicilioPtr domicilio1,DomicilioPtr domicilio2)
{
    bool condicion = strcmp(getCalle(domicilio1),getCalle(domicilio2)) == 0;
    condicion = condicion && getAltura(domicilio1) == getAltura(domicilio2);
    return condicion && strcmp(getLocalidad(domicilio1),getLocalidad(domicilio2)) == 0;
}
