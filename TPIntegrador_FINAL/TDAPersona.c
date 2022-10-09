#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDADomicilio.h"
#include "TDACuil.h"
#include "TDAPersona.h"
#include "util.h"
#include "Files.h"


//Precondici�n: domicilio y cuil debieron haber sido creados con sus respectivas funciones de creacion.
PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer)
{
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(nombre);
    persona->apellido=crearStringDinamico(apellido);
    persona->domicilio=domicilio;
    persona->cuil=cuil;
    persona->esChofer=esChofer; //en VSCode vimos que se puede asignar valores entre variables de tipo bool.
//esChofer valdr�a NULL por defecto, pero ahora vale o bien true, o bien false.
    return persona;
}

///Creador especial que solo recibe datos primitivos.
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer)
{
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(nombre);
    persona->apellido=crearStringDinamico(apellido);
    persona->domicilio=crearDomicilio(calle,altura,localidad);
    persona->cuil=crearCuil(cuilStr);
    persona->esChofer=esChofer;
    return persona;
}

PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PE)
{
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(PE->nombre);
    persona->apellido=crearStringDinamico(PE->apellido);
    persona->domicilio=crearDomicilio(PE->domicilio.calle,PE->domicilio.altura,PE->domicilio.localidad);
    persona->cuil=crearCuil(PE->cuil);
    persona->esChofer=PE->esChofer;
    return persona;
}

PersonaPtr destruirPersona(PersonaPtr persona)
{ //destruimos TODOS los campos, incluyendo los que no reservamos din�micamente en crearPersona
    destruirStringDinamico(persona->nombre);
    destruirStringDinamico(persona->apellido);
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
    persona->domicilio=domicilio;
}

void setCuilPersona(PersonaPtr persona, CuilPtr cuil) ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
{
    persona->cuil=cuil;
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

void mostrarPersona(PersonaPtr persona){
    printf("Tipo: ");
    if(getEsChofer(persona))
        printf("Chofer\n");
    else
        printf("Cliente\n");
    printf("\tApellido: %s\n",getApellido(persona));
    printf("\tNombre: %s\n", getNombre(persona));
    printf("\tDomicilio: ");
    mostrarDomicilio(getDomicilio(persona));
    mostrarCuil(getCuilPersona(persona));
}
