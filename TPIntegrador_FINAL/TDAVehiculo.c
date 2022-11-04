#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TDAVehiculo.h"
#include "util.h"


VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente)
{
    VehiculoPtr vehiculo=(VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));

    vehiculo->tipo=tipo;
    vehiculo->marca=crearStringDinamico(marca);
    vehiculo->modelo=crearStringDinamico(modelo);
    vehiculo->patente=crearStringDinamico(patente);

    return vehiculo;
}
VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo)
{
    vehiculo->marca=destruirStringDinamico(vehiculo->marca);
    vehiculo->modelo=destruirStringDinamico(vehiculo->modelo);
    vehiculo->patente=destruirStringDinamico(vehiculo->patente);
    free(vehiculo);
    return NULL;
}

int getTipoVehiculo(VehiculoPtr vehiculo)
{
    return vehiculo->tipo;
}
char *getMarca(VehiculoPtr vehiculo)
{
    return vehiculo->marca;
}
char *getModelo(VehiculoPtr vehiculo)
{
    return vehiculo->modelo;
}
char *getPatente(VehiculoPtr vehiculo)
{
    return vehiculo->patente;
}

void setTipoVehiculo(VehiculoPtr vehiculo,int tipo)
{
    vehiculo->tipo=tipo;
}
void setMarca(VehiculoPtr vehiculo,char *marca)
{
    strcpy(vehiculo->marca,marca);
}
void setModelo(VehiculoPtr vehiculo,char *modelo)
{
    strcpy(vehiculo->modelo,modelo);
}
void setPatente(VehiculoPtr vehiculo,char *patente)
{
    strcpy(vehiculo->patente,patente);
}

void mostrarVehiculo(VehiculoPtr vehiculo)
{
    if(getTipoVehiculo(vehiculo)==1)
        printf("Vehiculo tipo: MOTO.\n");
    else if(getTipoVehiculo(vehiculo)==2)
        printf("Vehiculo tipo: AUTO.\n");
    else if(getTipoVehiculo(vehiculo)==3)
        printf("Vehiculo tipo: CAMION.\n");
    else
        printf("ERROR, REINGRESE TIPO DE VEHICULO EXISTENTE\n");

    printf("\tMarca: %s\n",getMarca(vehiculo));
    printf("\tModelo: %s\n",getModelo(vehiculo));
    printf("\tPatente: %s\n",getPatente(vehiculo));
}
void helpTipoVehiculo() ///muestra al usuario que significa cada numero de tipo de vehiculo.
{   //1: Moto, 2: Auto, 3: Camión.
    printf("Tipo 1 = MOTO\n");
    printf("Tipo 2 = AUTO\n");
    printf("Tipo 3 = CAMION\n");
}
void mostrarTipoVehiculo(VehiculoPtr vehiculo) ///informa al usuario de que tipo es el vehículo que ingresa.
{
    if(getTipoVehiculo(vehiculo)==1)
        printf("El vehiculo recibido es de tipo MOTO.\n\n");
    else if(getTipoVehiculo(vehiculo)==2)
        printf("El vehiculo recibido es de tipo AUTO.\n\n");
    else if(getTipoVehiculo(vehiculo)==3)
        printf("El vehiculo recibido es de tipo CAMION.\n\n");
    else
    {
        printf("ERROR: No existe tipo de vehículo para el numero '%d'.\n",getTipoVehiculo(vehiculo));
        printf("Si desconoce los tipos existentes, llame a la funcion 'helpTipoVehiculo()'.\n");
        printf("Ingrese otro invocando a la funcion 'setTipoVehiculo()'.\n");
    }
}

bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2)
{
    bool match = match && (getTipoVehiculo(vehiculo1) == getTipoVehiculo(vehiculo2));
    match = match && (strcmp(getMarca(vehiculo1),getMarca(vehiculo2)) == 0);
    match = match && (strcmp(getModelo(vehiculo1),getModelo(vehiculo2)) == 0);
    return match && (strcmp(getPatente(vehiculo1),getPatente(vehiculo2)) == 0);
}

VehiculoPtr copiarVehiculo(VehiculoPtr vehiculoOriginal) ///NUEVA - Orientada para la funcion copiarLista
{
    return crearVehiculo(getTipoVehiculo(vehiculoOriginal),
                         getMarca(vehiculoOriginal),
                         getModelo(vehiculoOriginal),
                         getPatente(vehiculoOriginal));
}
