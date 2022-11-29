#ifndef FILESV2_H_INCLUDED
#define FILESV2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDAVehiculo.h"
#include "TDACentroLogistico.h"


/** OPERACIÓN: crea un directorio en formato string en base al nombre de una carpeta, el nombre y el tipo de un archivo.
PRECONDICIÓN:
    - los parámetros recibidos deben ser las macros definidas al principio del programa.
    - el tipo de archivo debe ser:
        txt,
        bin, o
        dat.
POSTCONDICIÓN: se crea un string conteniendo un directorio basado en los parámetros recibidos.
PARÁMETROS:
    - nombreCarpeta: string representando el nombre de la carpeta donde se encuentra el archivo
    - nombreArchivo: string representando el nombre del archivo contenido en la carpeta
    - tipoArchivo: string representando la extensión del archivo correspondiente.
                    puede ser txt, bin o dat (EL PUNTO SE PONE EN LA FUNCION, NO PONER ACÁ)
DEVUELVE: string representando el directorio creado. */
char *getDirectorio(const char *nombreCarpeta, const char *nombreArchivo, const char *tipoArchivo);

/** OPERACIÓN: crea una carpeta.
PRECONDICIÓN: nombre debe tener contenido
POSTCONDICIÓN: se crea una carpeta con el nombre indicado que almacenará los archivos del proyecto.
PARÁMETROS:
    - nombre: string representando el nombre de la carpeta a crear
DEVUELVE: true si la carpeta si se pudo crear, false de lo contrario. */
bool crearCarpeta(const char *nombre);

/** OPERACIÓN: busca y abre una carpeta.
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se busca una carpeta con el nombre especificado.
PARÁMETROS:
    - nombre: string representando el nombre de la carpeta a abrir
DEVUELVE: true si se pudo encontrar y abrir, false de lo contrario. */
bool abrirCarpeta(const char *nombre);





/** OPERACIÓN: serialización de paquetes (guardado)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se serializan los datos de la lista en un archivo de texto con un formato fácil de leer
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarPaquetes(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: serialización de personas (guardado)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se serializan los datos de la lista en un archivo de texto con un formato fácil de leer
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarPersonas(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: serialización de vehículos (guardado)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se serializan los datos de la lista en un archivo de texto con un formato fácil de leer
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarVehiculos(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: serialización de repartos (guardado)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se serializan los datos de la lista en un archivo de texto con un formato fácil de leer
PARÁMETROS:
    - c: puntero al centro logistico
    - esRepartoAbierto: booleano indicando si es lista de repartos abiertos (true) o cerrados (false)
DEVUELVE: true si se pudo guardar, false de lo contrario. */
bool serializarRepartos(CentroLogisticoPtr c, char* nombreCarpeta);



/** OPERACIÓN: deserialización de paquetes (apertura)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarPaquetes(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: deserialización de personas (apertura)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarPersonas(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: deserialización de vehículos (apertura)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PARÁMETROS:
    - c: puntero al centro logistico
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarVehiculos(CentroLogisticoPtr c, char* nombreCarpeta);

/** OPERACIÓN: deserialización de repartos (apertura)
PRECONDICIÓN: c debe haberse creado
POSTCONDICIÓN: se deserializan los datos de la lista desde un archivo de texto al centro logistico
PARÁMETROS:
    - c: puntero al centro logistico
    - esRepartoAbierto: booleano indicando si es lista de repartos abiertos (true) o cerrados (false)
DEVUELVE: true si se pudo abrir, false de lo contrario. */
bool deserializarRepartos(CentroLogisticoPtr c, char* nombreCarpeta);

bool abrirTodo(CentroLogisticoPtr c, char* directorio);
bool guardarTodo(CentroLogisticoPtr c, char* nombreCarpeta);

#endif // FILESV2_H_INCLUDED
