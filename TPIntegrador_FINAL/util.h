#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/** OPERACI�N: obtenci�n de memoria
PRECONDICI�N: Debe haber espacio en memoria disponible
POSTCONDICI�N: crea un puntero a un dato general en memoria dinamica
PAR�METROS:
    - tamanio: tama�o en bytes de la memoria a reservar
DEVUELVE: puntero a void casteable a cualquier tipo de dato. */
void *obtenerMemoria(size_t tamanio);

/** OPERACI�N: creaci�n de string din�mico
PRECONDICI�N: debe haber memoria suficiente disponible
POSTCONDICI�N: crea un puntero a char en memoria din�mica con el contenido del string recibido
PAR�METROS:
    - literal: puntero a char representando una cadena de caracteres
DEVUELVE: puntero a char a la primera posicion de la memoria reservada. */
char *crearStringDinamico(char* literal);

/** OPERACI�N: destrucci�n de string din�mico
PRECONDICI�N: buffer debe haberse creado con crearStringDin�mico
POSTCONDICI�N: libera la memoria previamente reservada para el string din�mico
PAR�METROS:
    - buffer: puntero a char representando una cadena de caracteres
DEVUELVE: NULL. */
char *destruirStringDinamico(char *buffer);

/** OPERACI�N: limpieza de buffer de teclado (utiliza fflush(STDIN))
PRECONDICI�N: Ninguna
POSTCONDICI�N: Libera la acumulacion del buffer del teclado,
               permitiendo ingresar m�s datos por teclado correctamente sin errores
PAR�METROS: Ninguno
DEVUELVE:  Nada. */
void limpiarBufferTeclado();
/** OPERACI�N: LIMPIEZA DE BUFFER DE TECLADO (UTILIZA GETCHAR())
PRECONDICI�N: Ninguna
POSTCONDICI�N: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
PAR�METROS: Ninguno
DEVUELVE:  Nada. */
void limpiarBufferTecladoPresionandoEnter();

/** OPERACI�N: LIMPIEZA Y PAUSA
PRECONDICI�N: Ninguna
POSTCONDICI�N: Limpia la pantalla con system("cls") y genera una pausa con getChar
PAR�METROS: Ninguno
DEVUELVE:  Nada. */
void presionarEnterYLimpiarPantalla();

/** OPERACI�N: Extrae todos los n�meros de un string y los separa en d�gitos individuales
PRECONDICI�N: el string recibido debe contener uno o m�s n�meros
              el vector de enteros recibido debe haber sido declarado
POSTCONDICI�N: Copia todos los n�meros del string en un vector de enteros
PAR�METROS:
    - source: string del que se extraer�n los n�meros
    - buffer: vector de enteros que contendr� cada d�gito de los n�meros.
DEVUELVE:  cantidad de d�gitos extra�dos. */
int extraerDigitosString(char *source,int buffer[]);


#endif // UTIL_H_INCLUDED
