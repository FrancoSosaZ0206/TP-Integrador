#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TDAVehiculo.h"
#include "util.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente)
{
    VehiculoPtr vehiculo=(VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    vehiculo->tipo=tipo;
    vehiculo->marca=crearStringDinamico(marca);
    vehiculo->modelo=crearStringDinamico(modelo);
    vehiculo->patente=crearStringDinamico(patente);
    return vehiculo;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo)
{
    destruirStringDinamico(vehiculo->marca);
    destruirStringDinamico(vehiculo->modelo);
    destruirStringDinamico(vehiculo->patente);
    free(vehiculo);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

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

///-----------------------------------------------------------------------------------------------------------///
                        ///SECCION DE FUNCIONES DE OPERACION CON VEHICULO///
///-----------------------------------------------------------------------------------------------------------///

void mostrarVehiculo(VehiculoPtr vehiculo)
{
    printf("\tTipo: ");
    tipoVehiculo(vehiculo);
    printf("\tMarca: %s\n",getMarca(vehiculo));
    printf("\tModelo: %s\n",getModelo(vehiculo));
    printf("\tPatente: %s\n",getPatente(vehiculo));
}

///muestra al usuario que significa cada numero de tipo de vehiculo.
void helpTipoVehiculo()
{
    //1: Moto, 2: Auto, 3: Camión.
    printf("Tipo 1 = MOTO\n");
    printf("Tipo 2 = AUTO\n");
    printf("Tipo 3 = CAMION\n");
}

void tipoVehiculo(VehiculoPtr vehiculo){
    switch(getTipoVehiculo(vehiculo)){
        case 1:
            printf("AUTO\n");
            break;
        case 2:
            printf("MOTO\n");
            break;
        case 3:
            printf("CAMION\n");
            break;
    }
}


///informa al usuario de que tipo es el vehículo que ingresa.
void mostrarTipoVehiculo(VehiculoPtr vehiculo)
{
    switch(getTipoVehiculo(vehiculo))
    {
    case 1:
        printf("El vehiculo recibido es de tipo MOTO.\n\n");
        break;
    case 2:
        printf("El vehiculo recibido es de tipo AUTO.\n\n");
        break;
    case 3:
        printf("El vehiculo recibido es de tipo CAMION.\n\n");
        break;
    default:
         printf("ERROR: No existe tipo de vehículo para el numero '%d'.\n",getTipoVehiculo(vehiculo));
         printf("Si desconoce los tipos existentes, llame a la funcion 'helpTipoVehiculo()'.\n");
         printf("Ingrese otro invocando a la funcion 'setTipoVehiculo()'.\n");
    }
    printf("\n\n");
}

bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2)
{
    return strcmp(getPatente(vehiculo1),getPatente(vehiculo2)) == 0;
}
