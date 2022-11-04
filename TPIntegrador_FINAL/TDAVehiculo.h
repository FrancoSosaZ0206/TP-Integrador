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
// Operaci�n de construccion (constructor)
// Precondici�n: Vehiculo no debe haberse creado
// Postcondici�n: Se crea Vehiculo con null en VehiculoPtr
// Par�metros:
// Ninguno
// Devuelve puntero al nodo creado

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo);
// Operaci�n de destruccion (destructor)
// Precondici�n: El nodo vehiculo debe haberse creado
// Postcondici�n: Se Libera la memoria de Vehiculo eliminado
// Par�metros:
//  puntero a Vehiculoa eliminar
// Devuelve NULL

int getTipoVehiculo(VehiculoPtr vehiculo);
//Operaci�n: obtiene el tipo de vehiculo asignado del vehiculo
//Precondici�n: la estructura Vehiculo debe tener un tipo de vehiculo asignado
//Postcondici�n: muestra el tipo de vehiculo obtenido
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getMarca(VehiculoPtr vehiculo);
//Operaci�n: obtiene la marca asignado del vehiculo
//Precondici�n: la estructura Vehiculo debe tener una marca asignado
//Postcondici�n: muestra la marca obtenido
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getModelo(VehiculoPtr vehiculo);
//Operaci�n: obtiene el modelo asignado del vehiculo
//Precondici�n: la estructura Vehiculo debe tener el modelo asignado
//Postcondici�n: muestra el modelo obtenido
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getPatente(VehiculoPtr vehiculo);
//Operaci�n: obtiene la patente asignado del vehiculo
//Precondici�n: la estructura Vehiculo debe tener un patente asignado
//Postcondici�n: muestra la patente obtenido
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char


void setTipoVehiculo(VehiculoPtr vehiculo, int tipo);
//Operaci�n: asigna el tipo de vehiculo ///1: Moto, 2: Auto, 3: Cami�n.
//Precondici�n: la estructura Vehiculo debe estar creada
//Postcondici�n: agrega el valor de tipo de vehiculo a la estructura Vehiculo
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: int

void setMarca(VehiculoPtr vehiculo, char *marca);
//Operaci�n: asigna la marca del vehiculo
//Precondici�n: la estructura Vehiculo debe estar creada
//Postcondici�n: agrega el valor de marca a la estructura Vehiculo
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void setModelo(VehiculoPtr vehiculo, char *modelo);
//Operaci�n: asigna el modelo del vehiculo
//Precondici�n: la estructura Vehiculo debe estar creada
//Postcondici�n: agrega el modelo a la estructura Vehiculo
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void setPatente(VehiculoPtr vehiculo, char *patente);
//Operaci�n: asigna la patente del vehiculo
//Precondici�n: la estructura Vehiculo debe estar creada
//Postcondici�n: agrega la patente a la estructura Vehiculo
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void mostrarVehiculo(VehiculoPtr vehiculo);
//Operaci�n: muestra el vehiculo
//Precondici�n: todos los valores de la estructura Vehiculo deben tener un valor
//Postcondici�n: mostrar el vehiculo
//Par�metros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada


//Operacion: ventana de ayuda de tipo de vehiculo
//PRECONDICION: nunguna
//POSTCONDICION: muestra en pantalla la relacion entre los numeros y los tipos de vehiculo
//PARAMETROS: ninuno
//DEVUELVE: Nada
void helpTipoVehiculo(); ///muestra al usuario que significa cada numero de tipo de vehiculo.
//Operacion: muestra el tipo de vehiculo
//PRECONDICION: vehiculo debe haber sido creado
//POSTCONDICION: muestra el tipo del vehiculo recibido por pantalla (si no existe, informar� con mensaje de error)
//PARAMETROS: puntero al vehiculo del que se quiere saber su tipo
//DEVUELVE: nada.
void mostrarTipoVehiculo(VehiculoPtr vehiculo); ///informa al usuario de que tipo es el veh�culo que ingresa.

//Operaci�n: verifica si dos vehiculos son iguales.
//Precondici�n: Ambos vehiculos deben haber sido creados.
//Postcondici�n: chequea si las estructuras son id�nticas en patente
//Par�metros:
//  vehiculo1: puntero a la estructura a verificar.
//  vehiculo2: puntero a la estructura a verificar.
//Devuelve: true si son id�nticos en patente, false de lo contrario.
bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2);

/*  Operaci�n: crea una copia de un vehiculo
Precondici�n: vehiculoOriginal debe haber sido creado previamente
Postcondici�n: duplica los contenidos del vehiculo en uno nuevo
Par�metros:
    - vehiculoOriginal: puntero al vehiculo del que se quiere hacer una copia
Devuelve: puntero a la copia del vehiculo creada. */
VehiculoPtr copiarVehiculo(VehiculoPtr vehiculoOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif // TDAVEHICULO_H_INCLUDED
