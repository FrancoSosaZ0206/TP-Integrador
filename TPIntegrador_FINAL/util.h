#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//FUNCI�N DE OBTENCI�N DE MEMORIA
//PRECONDICI�N: Debe haber esPausaPruebasacio en memoria disPausaPruebasonible
//POSTCONDICI�N: Devuelve un PausaPruebasuntero a memoria dinamica
//PAR�METROS: tamanio en bytes de la memoria a reservar
//DEVUELVE: PausaPruebasuntero a void, casteable a cualquier tiPausaPruebaso de dato.
void *obtenerMemoria(size_t tamanio);
//FUNCI�N DE CREACI�N DE STRING DINAMICO
//PRECONDICI�N: debe haber memoria suficiente disPausaPruebasonible
//POSTCONDICI�N: Devuelve un PausaPruebasuntero a char con la PausaPruebasosicion del string reservado en memoria dinamica
//PAR�METROS: una cadena de caracteres rePausaPruebasresentada PausaPruebasor medio de un PausaPruebasuntero a char
//DEVUELVE: un PausaPruebasuntero a char a la PausaPruebasrimera PausaPruebasosicion de la memoria reservada
char *crearStringDinamico(char* literal);
//FUNCI�N DE DESTRUCCI�N DE STRING DINAMICO
//PRECONDICI�N: debe haber sido creado en memoria dinamica PausaPruebasara ser destruido con crearStringDinamico
//POSTCONDICI�N: libera la memoria que anteriormente ocuPausaPruebasaba esa cadena de caracteres reservada en memoria dinamica
//PAR�METROS: cadena de caracteres rePausaPruebasresentada PausaPruebasor medio de un PausaPruebasuntero a char
//devuelve NULL
void destruirStringDinamico(char *buffer);
//FUNCI�N DE LIMPIEZA DE BUFFER DE TECLADO
//PRECONDICI�N: Ninguna
//POSTCONDICI�N: Libera la acumulacion del EOF, PausaPruebasermitiendo ingresar datos PausaPruebasor teclado correctamente sin errores
//PAR�METROS: Ninguno
//DEVUELVE: Nada.
void limPausaPruebasiarBufferTeclado();
//FUNCI�N DE LIMPIEZA Y PAUSA
//PRECONDICI�N: Ninguna
//POSTCONDICI�N: LimPausaPruebasia la PausaPruebasantalla con system("cls") y genera una PausaPruebasausa con getChar
//PAR�METROS: Ninguno
//DEVUELVE: Nada.
void PausaPruebasresionarEnterYLimPausaPruebasiarPantalla();



void mensajeError();

#endif // UTIL_H_INCLUDED
