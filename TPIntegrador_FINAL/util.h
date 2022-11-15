#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/** OPERACIÓN: obtención de memoria
PRECONDICIÓN: Debe haber espacio en memoria disponible
POSTCONDICIÓN: crea un puntero a un dato general en memoria dinamica
PARÁMETROS:
    - tamanio: tamaño en bytes de la memoria a reservar
DEVUELVE: puntero a void casteable a cualquier tipo de dato. */
void *obtenerMemoria(size_t tamanio);

/** OPERACIÓN: creación de string dinámico
PRECONDICIÓN: debe haber memoria suficiente disponible
POSTCONDICIÓN: crea un puntero a char en memoria dinámica con el contenido del string recibido
PARÁMETROS:
    - literal: puntero a char representando una cadena de caracteres
DEVUELVE: puntero a char a la primera posicion de la memoria reservada. */
char *crearStringDinamico(char* literal);

/** OPERACIÓN: destrucción de string dinámico
PRECONDICIÓN: buffer debe haberse creado con crearStringDinámico
POSTCONDICIÓN: libera la memoria previamente reservada para el string dinámico
PARÁMETROS:
    - buffer: puntero a char representando una cadena de caracteres
DEVUELVE: NULL. */
char *destruirStringDinamico(char *buffer);

/** OPERACIÓN: limpieza de buffer de teclado (utiliza fflush(STDIN))
PRECONDICIÓN: Ninguna
POSTCONDICIÓN: Libera la acumulacion del buffer del teclado,
               permitiendo ingresar más datos por teclado correctamente sin errores
PARÁMETROS: Ninguno
DEVUELVE:  Nada. */
void limpiarBufferTeclado();
/** OPERACIÓN: LIMPIEZA DE BUFFER DE TECLADO (UTILIZA GETCHAR())
PRECONDICIÓN: Ninguna
POSTCONDICIÓN: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
PARÁMETROS: Ninguno
DEVUELVE:  Nada. */
void limpiarBufferTecladoPresionandoEnter();

/** OPERACIÓN: LIMPIEZA Y PAUSA
PRECONDICIÓN: Ninguna
POSTCONDICIÓN: Limpia la pantalla con system("cls") y genera una pausa con getChar
PARÁMETROS: Ninguno
DEVUELVE:  Nada. */
void presionarEnterYLimpiarPantalla();

/** OPERACIÓN: Extrae todos los números de un string y los separa en dígitos individuales
PRECONDICIÓN: el string recibido debe contener uno o más números
              el vector de enteros recibido debe haber sido declarado
POSTCONDICIÓN: Copia todos los números del string en un vector de enteros
PARÁMETROS:
    - source: string del que se extraerán los números
    - buffer: vector de enteros que contendrá cada dígito de los números.
DEVUELVE:  cantidad de dígitos extraídos. */
int extraerDigitosString(char *source,int buffer[]);


#endif // UTIL_H_INCLUDED
