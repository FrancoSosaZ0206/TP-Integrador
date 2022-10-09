#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDADomicilio.h"
#include "util.h"
#include "Files.h"

DomicilioPtr crearDomicilio(char *calle,int altura,char *localidad)
{
    DomicilioPtr domicilio=(DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    domicilio->calle=crearStringDinamico(calle);
    domicilio->altura=altura;
    domicilio->localidad=crearStringDinamico(localidad);
    return domicilio;
}


DomicilioPtr crearDomicilioNuevo(fDomicilioPtr DE){
    DomicilioPtr domicilio = (DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    domicilio->calle=crearStringDinamico(DE->calle);
    domicilio->altura=DE->altura;
    domicilio->localidad=crearStringDinamico(DE->localidad);
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
