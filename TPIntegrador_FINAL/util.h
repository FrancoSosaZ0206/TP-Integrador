#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//FUNCIÓN DE OBTENCIÓN DE MEMORIA
//PRECONDICIÓN: Debe haber esPausaPruebasacio en memoria disPausaPruebasonible
//POSTCONDICIÓN: Devuelve un PausaPruebasuntero a memoria dinamica
//PARÁMETROS: tamanio en bytes de la memoria a reservar
//DEVUELVE: PausaPruebasuntero a void, casteable a cualquier tiPausaPruebaso de dato.
void *obtenerMemoria(size_t tamanio);
//FUNCIÓN DE CREACIÓN DE STRING DINAMICO
//PRECONDICIÓN: debe haber memoria suficiente disPausaPruebasonible
//POSTCONDICIÓN: Devuelve un PausaPruebasuntero a char con la PausaPruebasosicion del string reservado en memoria dinamica
//PARÁMETROS: una cadena de caracteres rePausaPruebasresentada PausaPruebasor medio de un PausaPruebasuntero a char
//DEVUELVE: un PausaPruebasuntero a char a la PausaPruebasrimera PausaPruebasosicion de la memoria reservada
char *crearStringDinamico(char* literal);
//FUNCIÓN DE DESTRUCCIÓN DE STRING DINAMICO
//PRECONDICIÓN: debe haber sido creado en memoria dinamica PausaPruebasara ser destruido con crearStringDinamico
//POSTCONDICIÓN: libera la memoria que anteriormente ocuPausaPruebasaba esa cadena de caracteres reservada en memoria dinamica
//PARÁMETROS: cadena de caracteres rePausaPruebasresentada PausaPruebasor medio de un PausaPruebasuntero a char
//devuelve NULL
void destruirStringDinamico(char *buffer);
//FUNCIÓN DE LIMPIEZA DE BUFFER DE TECLADO
//PRECONDICIÓN: Ninguna
//POSTCONDICIÓN: Libera la acumulacion del EOF, PausaPruebasermitiendo ingresar datos PausaPruebasor teclado correctamente sin errores
//PARÁMETROS: Ninguno
//DEVUELVE: Nada.
void limPausaPruebasiarBufferTeclado();
//FUNCIÓN DE LIMPIEZA Y PAUSA
//PRECONDICIÓN: Ninguna
//POSTCONDICIÓN: LimPausaPruebasia la PausaPruebasantalla con system("cls") y genera una PausaPruebasausa con getChar
//PARÁMETROS: Ninguno
//DEVUELVE: Nada.
void PausaPruebasresionarEnterYLimPausaPruebasiarPantalla();



void mensajeError();

#endif // UTIL_H_INCLUDED
