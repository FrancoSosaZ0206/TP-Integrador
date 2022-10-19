#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//FUNCIÓN DE OBTENCIÓN DE MEMORIA
//PRECONDICIÓN: Debe haber espacio en memoria disponible
//POSTCONDICIÓN: Devuelve un puntero a memoria dinamica
//PARÁMETROS: tamanio en bytes de la memoria a reservar
//DEVUELVE: puntero a void, casteable a cualquier tipo de dato.
void *obtenerMemoria(size_t tamanio);
//FUNCIÓN DE CREACIÓN DE STRING DINAMICO
//PRECONDICIÓN: debe haber memoria suficiente disponible
//POSTCONDICIÓN: Devuelve un puntero a char con la posicion del string reservado en memoria dinamica
//PARÁMETROS: una cadena de caracteres representada por medio de un puntero a char
//DEVUELVE: un puntero a char a la primera posicion de la memoria reservada
char *crearStringDinamico(char* literal);
//FUNCIÓN DE DESTRUCCIÓN DE STRING DINAMICO
//PRECONDICIÓN: debe haber sido creado en memoria dinamica para ser destruido con crearStringDinamico
//POSTCONDICIÓN: libera la memoria que anteriormente ocupaba esa cadena de caracteres reservada en memoria dinamica
//PARÁMETROS: cadena de caracteres representada por medio de un puntero a char
//devuelve NULL
void destruirStringDinamico(char *buffer);

//FUNCIÓN DE LIMPIEZA DE BUFFER DE TECLADO (UTILIZA FFLUSH(STDIN))
//PRECONDICIÓN: Ninguna
//POSTCONDICIÓN: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
//PARÁMETROS: Ninguno
//DEVUELVE: Nada.
void limpiarBufferTeclado();
//FUNCIÓN DE LIMPIEZA DE BUFFER DE TECLADO (UTILIZA GETCHAR())
//PRECONDICIÓN: Ninguna
//POSTCONDICIÓN: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
//PARÁMETROS: Ninguno
//DEVUELVE: Nada.
void limpiarBufferTecladoPresionandoEnter();

//FUNCIÓN DE LIMPIEZA Y PAUSA
//PRECONDICIÓN: Ninguna
//POSTCONDICIÓN: Limpia la pantalla con system("cls") y genera una pausa con getChar
//PARÁMETROS: Ninguno
//DEVUELVE: Nada.
void presionarEnterYLimpiarPantalla();

/* OPERACIÓN: Extrae todos los números de un string y los separa en dígitos individuales
PRECONDICIÓN: el string recibido debe contener uno o más números
              el vector de enteros recibido debe haber sido declarado
POSTCONDICIÓN: Copia todos los números del string en un vector de enteros
PARÁMETROS:
    - source: string del que se extraerán los números
    - buffer: vector de enteros que contendrá cada dígito de los números.
DEVUELVE: cantidad de dígitos extraídos. */
int extraerDigitosString(char *source,int buffer[]);

#endif // UTIL_H_INCLUDED
