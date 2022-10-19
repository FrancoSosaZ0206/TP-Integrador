#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//FUNCI�N DE OBTENCI�N DE MEMORIA
//PRECONDICI�N: Debe haber espacio en memoria disponible
//POSTCONDICI�N: Devuelve un puntero a memoria dinamica
//PAR�METROS: tamanio en bytes de la memoria a reservar
//DEVUELVE: puntero a void, casteable a cualquier tipo de dato.
void *obtenerMemoria(size_t tamanio);
//FUNCI�N DE CREACI�N DE STRING DINAMICO
//PRECONDICI�N: debe haber memoria suficiente disponible
//POSTCONDICI�N: Devuelve un puntero a char con la posicion del string reservado en memoria dinamica
//PAR�METROS: una cadena de caracteres representada por medio de un puntero a char
//DEVUELVE: un puntero a char a la primera posicion de la memoria reservada
char *crearStringDinamico(char* literal);
//FUNCI�N DE DESTRUCCI�N DE STRING DINAMICO
//PRECONDICI�N: debe haber sido creado en memoria dinamica para ser destruido con crearStringDinamico
//POSTCONDICI�N: libera la memoria que anteriormente ocupaba esa cadena de caracteres reservada en memoria dinamica
//PAR�METROS: cadena de caracteres representada por medio de un puntero a char
//devuelve NULL
void destruirStringDinamico(char *buffer);

//FUNCI�N DE LIMPIEZA DE BUFFER DE TECLADO (UTILIZA FFLUSH(STDIN))
//PRECONDICI�N: Ninguna
//POSTCONDICI�N: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
//PAR�METROS: Ninguno
//DEVUELVE: Nada.
void limpiarBufferTeclado();
//FUNCI�N DE LIMPIEZA DE BUFFER DE TECLADO (UTILIZA GETCHAR())
//PRECONDICI�N: Ninguna
//POSTCONDICI�N: Libera la acumulacion del EOF, permitiendo ingresar datos por teclado correctamente sin errores
//PAR�METROS: Ninguno
//DEVUELVE: Nada.
void limpiarBufferTecladoPresionandoEnter();

//FUNCI�N DE LIMPIEZA Y PAUSA
//PRECONDICI�N: Ninguna
//POSTCONDICI�N: Limpia la pantalla con system("cls") y genera una pausa con getChar
//PAR�METROS: Ninguno
//DEVUELVE: Nada.
void presionarEnterYLimpiarPantalla();

/* OPERACI�N: Extrae todos los n�meros de un string y los separa en d�gitos individuales
PRECONDICI�N: el string recibido debe contener uno o m�s n�meros
              el vector de enteros recibido debe haber sido declarado
POSTCONDICI�N: Copia todos los n�meros del string en un vector de enteros
PAR�METROS:
    - source: string del que se extraer�n los n�meros
    - buffer: vector de enteros que contendr� cada d�gito de los n�meros.
DEVUELVE: cantidad de d�gitos extra�dos. */
int extraerDigitosString(char *source,int buffer[]);

#endif // UTIL_H_INCLUDED
