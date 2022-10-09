#ifndef TDAVEHICULO_H_INCLUDED
#define TDAVEHICULO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct Vehiculo
{
    int tipo; ///1: Moto, 2: Auto, 3: Camión.
    char *marca;
    char *modelo;
    char *patente; //Consejo del profe: preferible definirlo como un char y listo, no tener que hacer todo el TDA y sus funciones.
} Vehiculo;
typedef Vehiculo * VehiculoPtr;

VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente);
// Operación de construccion (constructor)
// Precondición: Vehiculo no debe haberse creado
// Postcondición: Se crea Vehiculo con null en VehiculoPtr
// Parámetros:
// Ninguno
// Devuelve puntero al nodo creado

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo);
// Operación de destruccion (destructor)
// Precondición: El nodo vehiculo debe haberse creado
// Postcondición: Se Libera la memoria de Vehiculo eliminado
// Parámetros:
//  puntero a Vehiculoa eliminar
// Devuelve NULL

int getTipoVehiculo(VehiculoPtr vehiculo);
//Operación: obtiene el tipo de vehiculo asignado del vehiculo
//Precondición: la estructura Vehiculo debe tener un tipo de vehiculo asignado
//Postcondición: muestra el tipo de vehiculo obtenido
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getMarca(VehiculoPtr vehiculo);
//Operación: obtiene la marca asignado del vehiculo
//Precondición: la estructura Vehiculo debe tener una marca asignado
//Postcondición: muestra la marca obtenido
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getModelo(VehiculoPtr vehiculo);
//Operación: obtiene el modelo asignado del vehiculo
//Precondición: la estructura Vehiculo debe tener el modelo asignado
//Postcondición: muestra el modelo obtenido
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char

char *getPatente(VehiculoPtr vehiculo);
//Operación: obtiene la patente asignado del vehiculo
//Precondición: la estructura Vehiculo debe tener un patente asignado
//Postcondición: muestra la patente obtenido
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: char


void setTipoVehiculo(VehiculoPtr vehiculo, int tipo);
//Operación: asigna el tipo de vehiculo ///1: Moto, 2: Auto, 3: Camión.
//Precondición: la estructura Vehiculo debe estar creada
//Postcondición: agrega el valor de tipo de vehiculo a la estructura Vehiculo
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: int

void setMarca(VehiculoPtr vehiculo, char *marca);
//Operación: asigna la marca del vehiculo
//Precondición: la estructura Vehiculo debe estar creada
//Postcondición: agrega el valor de marca a la estructura Vehiculo
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void setModelo(VehiculoPtr vehiculo, char *modelo);
//Operación: asigna el modelo del vehiculo
//Precondición: la estructura Vehiculo debe estar creada
//Postcondición: agrega el modelo a la estructura Vehiculo
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void setPatente(VehiculoPtr vehiculo, char *patente);
//Operación: asigna la patente del vehiculo
//Precondición: la estructura Vehiculo debe estar creada
//Postcondición: agrega la patente a la estructura Vehiculo
//Parámetros: vehiculo(puntero a la estructura vehiculo)
//
//Devuelve: nada

void mostrarVehiculo(VehiculoPtr vehiculo);
//Operación: muestra el vehiculo
//Precondición: todos los valores de la estructura Vehiculo deben tener un valor
//Postcondición: mostrar el vehiculo
//Parámetros: vehiculo(puntero a la estructura vehiculo)
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
//POSTCONDICION: muestra el tipo del vehiculo recibido por pantalla (si no existe, informará con mensaje de error)
//PARAMETROS: puntero al vehiculo del que se quiere saber su tipo
//DEVUELVE: nada.
void mostrarTipoVehiculo(VehiculoPtr vehiculo); ///informa al usuario de que tipo es el vehículo que ingresa.



#endif // TDAVEHICULO_H_INCLUDED
