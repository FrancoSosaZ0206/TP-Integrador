#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDADomicilio.h"
#include "TDACuil.h"
#include "TDAPersona.h"
#include "util.h"


//Precondición: domicilio y cuil debieron haber sido creados con sus respectivas funciones de creacion.
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer)
{
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));

    persona->nombre=crearStringDinamico(nombre);
    persona->apellido=crearStringDinamico(apellido);
    persona->domicilio=domicilio;
    persona->cuil=cuil;
    persona->esChofer=esChofer; //en VSCode vimos que se puede asignar valores entre variables de tipo bool.
//esChofer valdría NULL por defecto, pero ahora vale o bien true, o bien false.
    return persona;
}

///Creador especial que solo recibe datos primitivos.
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer)
{
    DomicilioPtr domicilio = crearDomicilio(calle,altura,localidad);
    CuilPtr cuil = crearCuil(cuilStr);

    return crearPersona(nombre,apellido,domicilio,cuil,esChofer);
}

PersonaPtr destruirPersona(PersonaPtr persona)
{ //destruimos TODOS los campos, incluyendo los que no reservamos dinámicamente en crearPersona
    persona->nombre=destruirStringDinamico(persona->nombre);
    persona->apellido=destruirStringDinamico(persona->apellido);
    persona->domicilio=destruirDomicilio(persona->domicilio);
    persona->cuil=destruirCuil(persona->cuil);

    free(persona);
    return NULL;
}



void setNombre(PersonaPtr persona,char *nombre)
{
    strcpy(persona->nombre,nombre);
}

void setApellido(PersonaPtr persona,char *apellido)
{
    strcpy(persona->apellido,apellido);
}

void setDomicilio(PersonaPtr persona,DomicilioPtr domicilio)
{
    setCalle(persona->domicilio,domicilio->calle);
    setAltura(persona->domicilio,domicilio->altura);
    setLocalidad(persona->domicilio,domicilio->localidad);
}

void setCuilPersona(PersonaPtr persona,CuilPtr cuil) ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
{
    setCuil(persona->cuil,cuil->cuil);
}

void setEsChofer(PersonaPtr persona,bool esChofer)
{
    persona->esChofer=esChofer; //de nuevo, esto se puede hacer sin drama.
}



char *getNombre(PersonaPtr persona)
{
    return persona->nombre;
}

char *getApellido(PersonaPtr persona)
{
    return persona->apellido;
}

DomicilioPtr getDomicilio(PersonaPtr persona)
{
    return persona->domicilio;
}

CuilPtr getCuilPersona(PersonaPtr persona) ///NUEVO NOMBRE PARA NO CONFUNDIR CON GETCUIL DEL TDA CUIL
{
    return persona->cuil;
}

bool getEsChofer(PersonaPtr persona)
{
    return persona->esChofer;
}



void mostrarPersona(PersonaPtr persona)
{
    printf("\n");
    printf("\tTipo: ");if(getEsChofer(persona)){printf("Chofer\n");}else{printf("Cliente\n");}
    printf("\tNombre y Apellido: %s, %s\n",getNombre(persona),getApellido(persona));
    printf("\tDomicilio: ");mostrarDomicilio(getDomicilio(persona));
    mostrarCuil(getCuilPersona(persona));
    printf("\n");
}



bool personasIguales(PersonaPtr persona1,PersonaPtr persona2)
{
    bool match = strcmp(getNombre(persona1), getNombre(persona2)) == 0;
    match = match && (strcmp(getApellido(persona1), getApellido(persona2)) == 0);
    match = match && domiciliosIguales(getDomicilio(persona1),getDomicilio(persona2));
    return match && cuilsIguales(getCuilPersona(persona1), getCuilPersona(persona2));
}

PersonaPtr copiarPersona(PersonaPtr personaOriginal) ///NUEVA - Orientada para la funcion copiarLista
{
    return crearPersonaDirect(getNombre(personaOriginal),getApellido(personaOriginal),
                                            getCalle(getDomicilio(personaOriginal)),getAltura(getDomicilio(personaOriginal)),getLocalidad(getDomicilio(personaOriginal)),
                                            getCuil(getCuilPersona(personaOriginal)),
                                            getEsChofer(personaOriginal));
}
