#ifndef TDAVEHICULO_H_INCLUDED
#define TDAVEHICULO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vehiculo
{
    int tipo; ///1: Moto, 2: Auto, 3: Cami�n.
    char *marca;
    char *modelo;
    char *patente; //Consejo del profe: preferible definirlo como un char y listo, no tener que hacer todo el TDA y sus funciones.
} Vehiculo;
typedef Vehiculo * VehiculoPtr;

VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente);
/** OPERACI�N de construccion (constructor)
PRECONDICI�N: Vehiculo no debe haberse creado
POSTCONDICI�N: Se crea Vehiculo con null en VehiculoPtr
PAR�METROS:
Ninguno
DEVUELVE:  puntero al nodo creado

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo);
/** OPERACI�N de destruccion (destructor)
PRECONDICI�N: El nodo vehiculo debe haberse creado
POSTCONDICI�N: Se Libera la memoria de Vehiculo eliminado
PAR�METROS:
    - puntero a Vehiculoa eliminar
DEVUELVE:  NULL. */

int getTipoVehiculo(VehiculoPtr vehiculo);
/** OPERACI�N: obtiene el tipo de vehiculo asignado del vehiculo
PRECONDICI�N: la estructura Vehiculo debe tener un tipo de vehiculo asignado
POSTCONDICI�N: muestra el tipo de vehiculo obtenido
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getMarca(VehiculoPtr vehiculo);
/** OPERACI�N: obtiene la marca asignado del vehiculo
PRECONDICI�N: la estructura Vehiculo debe tener una marca asignado
POSTCONDICI�N: muestra la marca obtenido
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getModelo(VehiculoPtr vehiculo);
/** OPERACI�N: obtiene el modelo asignado del vehiculo
PRECONDICI�N: la estructura Vehiculo debe tener el modelo asignado
POSTCONDICI�N: muestra el modelo obtenido
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getPatente(VehiculoPtr vehiculo);
/** OPERACI�N: obtiene la patente asignado del vehiculo
PRECONDICI�N: la estructura Vehiculo debe tener un patente asignado
POSTCONDICI�N: muestra la patente obtenido
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char


void setTipoVehiculo(VehiculoPtr vehiculo, int tipo);
/** OPERACI�N: asigna el tipo de vehiculo ///1: Moto, 2: Auto, 3: Cami�n.
PRECONDICI�N: la estructura Vehiculo debe estar creada
POSTCONDICI�N: agrega el valor de tipo de vehiculo a la estructura Vehiculo
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  int

void setMarca(VehiculoPtr vehiculo, char *marca);
/** OPERACI�N: asigna la marca del vehiculo
PRECONDICI�N: la estructura Vehiculo debe estar creada
POSTCONDICI�N: agrega el valor de marca a la estructura Vehiculo
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void setModelo(VehiculoPtr vehiculo, char *modelo);
/** OPERACI�N: asigna el modelo del vehiculo
PRECONDICI�N: la estructura Vehiculo debe estar creada
POSTCONDICI�N: agrega el modelo a la estructura Vehiculo
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void setPatente(VehiculoPtr vehiculo, char *patente);
/** OPERACI�N: asigna la patente del vehiculo
PRECONDICI�N: la estructura Vehiculo debe estar creada
POSTCONDICI�N: agrega la patente a la estructura Vehiculo
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void mostrarVehiculo(VehiculoPtr vehiculo);
/** OPERACI�N: muestra el vehiculo
PRECONDICI�N: todos los valores de la estructura Vehiculo deben tener un valor
POSTCONDICI�N: mostrar el vehiculo
PAR�METROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada


/** OPERACI�N: ventana de ayuda de tipo de vehiculo
PRECONDICI�N: nunguna
POSTCONDICI�N: muestra en pantalla la relacion entre los numeros y los tipos de vehiculo
PAR�METROS: ninuno
DEVUELVE:  Nada
void helpTipoVehiculo(); ///muestra al usuario que significa cada numero de tipo de vehiculo.
/** OPERACI�N: muestra el tipo de vehiculo
PRECONDICI�N: vehiculo debe haber sido creado
POSTCONDICI�N: muestra el tipo del vehiculo recibido por pantalla (si no existe, informar� con mensaje de error)
PAR�METROS: puntero al vehiculo del que se quiere saber su tipo
DEVUELVE:  nada. */
void mostrarTipoVehiculo(VehiculoPtr vehiculo); ///informa al usuario de que tipo es el veh�culo que ingresa.

/** OPERACI�N: verifica si dos vehiculos son iguales.
PRECONDICI�N: Ambos vehiculos deben haber sido creados.
POSTCONDICI�N: chequea si las estructuras son id�nticas en patente
PAR�METROS:
    - vehiculo1: puntero a la estructura a verificar.
    - vehiculo2: puntero a la estructura a verificar.
DEVUELVE:  true si son id�nticos en patente, false de lo contrario. */
bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2);

/*  OPERACI�N: crea una copia de un vehiculo
PRECONDICI�N: vehiculoOriginal debe haber sido creado previamente
POSTCONDICI�N: duplica los contenidos del vehiculo en uno nuevo
PAR�METROS:
    - vehiculoOriginal: puntero al vehiculo del que se quiere hacer una copia
DEVUELVE:  puntero a la copia del vehiculo creada. */
VehiculoPtr copiarVehiculo(VehiculoPtr vehiculoOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif // TDAVEHICULO_H_INCLUDED
