#ifndef FILESV2_H_INCLUDED
#define FILESV2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDAVehiculo.h"
#include "TDACentroLogistico.h"


/** OPERACI�N: crea un directorio en formato string en base al nombre de una carpeta, el nombre y el tipo de un archivo.
PRECONDICI�N:
    - los par�metros recibidos deben ser las macros definidas al principio del programa.
    - el tipo de archivo debe ser:
        txt,
        bin, o
        dat.
POSTCONDICI�N: se crea un string conteniendo un directorio basado en los par�metros recibidos.
PAR�METROS:
    - nombreCarpeta: string representando el nombre de la carpeta donde se encuentra el archivo
    - nombreArchivo: string representando el nombre del archivo contenido en la carpeta
    - tipoArchivo: string representando la extensi�n del archivo correspondiente.
                    puede ser txt, bin o dat (EL PUNTO SE PONE EN LA FUNCION, NO PONER AC�)
DEVUELVE: string representando el directorio creado. */
char *getDirectorio(const char *nombreCarpeta, const char *nombreArchivo, const char *tipoArchivo);

/** OPERACI�N: crea una carpeta.
PRECONDICI�N: nombre debe tener contenido
POSTCONDICI�N: se crea una carpeta con el nombre indicado que almacenar� los archivos del proyecto.
PAR�METROS:
    - nombre: string representando el nombre de la carpeta a crear
DEVUELVE: true si la carpeta si se pudo crear, false de lo contrario. */
bool crearCarpeta(const char *nombre);

/** OPERACI�N: busca y abre una carpeta.
PRECONDICI�N: ninguna
POSTCONDICI�N: se busca una carpeta con el nombre especificado.
PAR�METROS:
    - nombre: string representando el nombre de la carpeta a abrir
DEVUELVE: true si se pudo encontrar y abrir, false de lo contrario. */
bool abrirCarpeta(const char *nombre);





/** OPERACI�N: serializaci�n de paquetes (guardado)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se serializan los datos de la lista en un archivo de texto con un formato f�cil de leer
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarPaquetes(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: serializaci�n de personas (guardado)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se serializan los datos de la lista en un archivo de texto con un formato f�cil de leer
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarPersonas(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: serializaci�n de veh�culos (guardado)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se serializan los datos de la lista en un archivo de texto con un formato f�cil de leer
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarVehiculos(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: serializaci�n de repartos (guardado)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se serializan los datos de la lista en un archivo de texto con un formato f�cil de leer
PAR�METROS:
    - c: puntero al centro logistico
    - esRepartoAbierto: booleano indicando si es lista de repartos abiertos (true) o cerrados (false)
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarRepartos(CentroLogisticoPtr c, char* nombreCarpeta);



/** OPERACI�N: deserializaci�n de paquetes (apertura)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarPaquetes(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: deserializaci�n de personas (apertura)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarPersonas(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: deserializaci�n de veh�culos (apertura)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PAR�METROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarVehiculos(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACI�N: deserializaci�n de repartos (apertura)
PRECONDICI�N: c debe haberse creado
POSTCONDICI�N: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PAR�METROS:
    - c: puntero al centro logistico
    - esRepartoAbierto: booleano indicando si es lista de repartos abiertos (true) o cerrados (false)
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarRepartos(CentroLogisticoPtr c, char* nombreCarpeta);

bool abrirTodo(CentroLogisticoPtr c, char* directorio);
bool guardarTodo(CentroLogisticoPtr c, char* nombreCarpeta);

#endif // FILESV2_H_INCLUDED
