#ifndef TDAVEHICULO_H_INCLUDED
#define TDAVEHICULO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vehiculo
{
    int tipo; ///1: Moto, 2: Auto, 3: Camión.
    char *marca;
    char *modelo;
    char *patente; //Consejo del profe: preferible definirlo como un char y listo, no tener que hacer todo el TDA y sus funciones.
} Vehiculo;
typedef Vehiculo * VehiculoPtr;

VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente);
/** OPERACIÓN de construccion (constructor)
PRECONDICIÓN: Vehiculo no debe haberse creado
POSTCONDICIÓN: Se crea Vehiculo con null en VehiculoPtr
PARÁMETROS:
Ninguno
DEVUELVE:  puntero al nodo creado

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo);
/** OPERACIÓN de destruccion (destructor)
PRECONDICIÓN: El nodo vehiculo debe haberse creado
POSTCONDICIÓN: Se Libera la memoria de Vehiculo eliminado
PARÁMETROS:
    - puntero a Vehiculoa eliminar
DEVUELVE:  NULL. */

int getTipoVehiculo(VehiculoPtr vehiculo);
/** OPERACIÓN: obtiene el tipo de vehiculo asignado del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe tener un tipo de vehiculo asignado
POSTCONDICIÓN: muestra el tipo de vehiculo obtenido
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getMarca(VehiculoPtr vehiculo);
/** OPERACIÓN: obtiene la marca asignado del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe tener una marca asignado
POSTCONDICIÓN: muestra la marca obtenido
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getModelo(VehiculoPtr vehiculo);
/** OPERACIÓN: obtiene el modelo asignado del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe tener el modelo asignado
POSTCONDICIÓN: muestra el modelo obtenido
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char

char *getPatente(VehiculoPtr vehiculo);
/** OPERACIÓN: obtiene la patente asignado del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe tener un patente asignado
POSTCONDICIÓN: muestra la patente obtenido
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  char


void setTipoVehiculo(VehiculoPtr vehiculo, int tipo);
/** OPERACIÓN: asigna el tipo de vehiculo ///1: Moto, 2: Auto, 3: Camión.
PRECONDICIÓN: la estructura Vehiculo debe estar creada
POSTCONDICIÓN: agrega el valor de tipo de vehiculo a la estructura Vehiculo
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  int

void setMarca(VehiculoPtr vehiculo, char *marca);
/** OPERACIÓN: asigna la marca del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe estar creada
POSTCONDICIÓN: agrega el valor de marca a la estructura Vehiculo
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void setModelo(VehiculoPtr vehiculo, char *modelo);
/** OPERACIÓN: asigna el modelo del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe estar creada
POSTCONDICIÓN: agrega el modelo a la estructura Vehiculo
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void setPatente(VehiculoPtr vehiculo, char *patente);
/** OPERACIÓN: asigna la patente del vehiculo
PRECONDICIÓN: la estructura Vehiculo debe estar creada
POSTCONDICIÓN: agrega la patente a la estructura Vehiculo
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada

void mostrarVehiculo(VehiculoPtr vehiculo);
/** OPERACIÓN: muestra el vehiculo
PRECONDICIÓN: todos los valores de la estructura Vehiculo deben tener un valor
POSTCONDICIÓN: mostrar el vehiculo
PARÁMETROS: vehiculo(puntero a la estructura vehiculo)

DEVUELVE:  nada


/** OPERACIÓN: ventana de ayuda de tipo de vehiculo
PRECONDICIÓN: nunguna
POSTCONDICIÓN: muestra en pantalla la relacion entre los numeros y los tipos de vehiculo
PARÁMETROS: ninuno
DEVUELVE:  Nada
void helpTipoVehiculo(); ///muestra al usuario que significa cada numero de tipo de vehiculo.
/** OPERACIÓN: muestra el tipo de vehiculo
PRECONDICIÓN: vehiculo debe haber sido creado
POSTCONDICIÓN: muestra el tipo del vehiculo recibido por pantalla (si no existe, informará con mensaje de error)
PARÁMETROS: puntero al vehiculo del que se quiere saber su tipo
DEVUELVE:  nada. */
void mostrarTipoVehiculo(VehiculoPtr vehiculo); ///informa al usuario de que tipo es el vehículo que ingresa.

/** OPERACIÓN: verifica si dos vehiculos son iguales.
PRECONDICIÓN: Ambos vehiculos deben haber sido creados.
POSTCONDICIÓN: chequea si las estructuras son idénticas en patente
PARÁMETROS:
    - vehiculo1: puntero a la estructura a verificar.
    - vehiculo2: puntero a la estructura a verificar.
DEVUELVE:  true si son idénticos en patente, false de lo contrario. */
bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2);

/*  OPERACIÓN: crea una copia de un vehiculo
PRECONDICIÓN: vehiculoOriginal debe haber sido creado previamente
POSTCONDICIÓN: duplica los contenidos del vehiculo en uno nuevo
PARÁMETROS:
    - vehiculoOriginal: puntero al vehiculo del que se quiere hacer una copia
DEVUELVE:  puntero a la copia del vehiculo creada. */
VehiculoPtr copiarVehiculo(VehiculoPtr vehiculoOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif // TDAVEHICULO_H_INCLUDED
