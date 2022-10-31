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
    domicilio->calle=destruirStringDinamico(domicilio->calle);
    domicilio->localidad=destruirStringDinamico(domicilio->localidad);
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
    bool SonDomiciliosIguales = true;
    SonDomiciliosIguales = SonDomiciliosIguales && (strcmp(getCalle(domicilio1),getCalle(domicilio2)) == 0);
    SonDomiciliosIguales = SonDomiciliosIguales && (getAltura(domicilio1) == getAltura(domicilio2));
    SonDomiciliosIguales = SonDomiciliosIguales && (strcmp(getLocalidad(domicilio1),getLocalidad(domicilio2)) == 0);
    return SonDomiciliosIguales;
}



