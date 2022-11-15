#ifndef TDACUIL_H_INCLUDED
#define TDACUIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                INTERFAZ DEL TDA CUIL

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Cuil
{ //hombre=20,mujer=27,empresa=30
    char *cuil;
} Cuil;
typedef Cuil* CuilPtr;

///*****************************************************************************************************
///                                 FUNCIONES: CREACION Y DESTRUCCION

/// Nueva implementaci�n
/** OPERACI�N: creaci�n (constructora)
PRECONDICI�N: ninguna
POSTCONDICI�N: se crea un cuil en memoria din�mica con el par�metro recibido
PAR�METROS:
    - cuilStr: string representando el cuil a crear
DEVUELVE: un puntero al TDA cuil creado. */
CuilPtr crearCuil(char *cuilStr);

/// Vieja implementaci�n
/** OPERACI�N: creaci�n (constructora)
PRECONDICI�N: ninguna
POSTCONDICI�N: se crea un cuil en memoria din�mica con los par�metros recibidos
PAR�METROS:
    - tipo: entero que representa el tipo de persona
    - dni: entero que representa el documento dni.
    - nVerificador: entero que representa el numero verificador.
DEVUELVE: un puntero al cuil creado. */
CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador);

/** OPERACI�N: destrucci�n (destructora)
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: se libera la memoria reservada para el cuil
PAR�METROS:
    - cuil: puntero al cuil a destruir.
DEVUELVE: NULL. */
CuilPtr destruirCuil(CuilPtr cuil);


///*****************************************************************************************************
///                                            SETTERS

/** OPERACI�N: Asignacion de cuil completo.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: la estructura cuil cambia con el valor del nuevo cuil string.
PAR�METROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - cuilStr: string representando el nuevo cuil.
DEVUELVE: nada. */
void setCuil(CuilPtr cuil,char *cuilStr);

/** OPERACI�N: Asignacion de tipo de genero.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: cuil cambia con el nuevo tipo.
PAR�METROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - tipo: entero que representa el nuevo tipo de persona.
DEVUELVE: nada. */
void setTipo(CuilPtr cuil,int tipo);

/** OPERACI�N: Asignacion de dni.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: cuil cambia con el nuevo dni.
PAR�METROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - dni: entero que representa el nuevo dni.
DEVUELVE: nada. */
void setDni(CuilPtr cuil,int dni);

/** OPERACI�N: Asignacion de tipo de genero.
PRECONDICI�N: cuil debe estar creado.
POSTCONDICI�N: cuil cambia con el nuevo numero verificador.
PAR�METROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - nVerificador: entero que representa el nuevo numero verificador.
DEVUELVE: nada. */
void setNVerificador(CuilPtr cuil,int nVerificador);


///*****************************************************************************************************
///                                            GETTERS

/** OPERACI�N: obtencion del cuil.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: se obtiene el cuil completo en forma de string.
PAR�METROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un puntero a char representando el cuil. */
char *getCuil(CuilPtr cuil);

/** OPERACI�N: Obtencion del tipo.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: Se obtiene el tipo de cuil.
PAR�METROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el tipo de cuil. */
int getTipo(CuilPtr cuil);

/** OPERACI�N: Obtencion del tipo.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: Se obtiene el dni de cuil.
PAR�METROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el dni de cuil. */
int getDni(CuilPtr cuil);

/** OPERACI�N: Obtencion del tipo.
PRECONDICI�N: cuil debe haberse creado con crearCuil
POSTCONDICI�N: Se obtiene el numero verificador de cuil.
PAR�METROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el numero verificador de cuil. */
int getNVerificador(CuilPtr cuil);


///*****************************************************************************************************
///                                       ESPECIALES

/** OPERACI�N: determina si un cuil es valido
PRECONDICI�N: cuil debe haber sido creado con crearCuil
POSTCONDICI�N: ninguna
PAR�METROS:
    - puntero al cuil a validar
DEVUELVE: true si es valido, false de lo contrario. */
bool esCuilValido(CuilPtr cuil); ///NO APTA PARA TIPO EMPRESA

///*****************************************************************************************************

/** OPERACI�N: men� de ayuda de CUIL
PRECONDICI�N: ninguna
POSTCONDICI�N: despliega un men� de ayuda para que el usuario sepa como es un cuil
PAR�METROS: ninguno
DEVUELVE: nada. */
void helpCuil();

/** OPERACI�N: muestra el CUIL recibido
PRECONDICI�N: cuil debe haber sido creado con crearCuil
POSTCONDICI�N: imprime el CUIL recibido por pantalla
PAR�METROS:
    - puntero al cuil a mostrar
DEVUELVE: nada. */
void mostrarCuil(CuilPtr cuil);

/** OPERACI�N: verifica si dos CUIL son iguales.
PRECONDICI�N: Ambos cuil deben haber sido creados.
POSTCONDICI�N: chequea si las estructuras son id�nticas en cuil
PAR�METROS:
    - cuil1: puntero a la estructura a verificar.
    - cuil2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos, false de lo contrario. */
bool cuilsIguales(CuilPtr cuil1,CuilPtr cuil2);


#endif // TDACUIL_H_INCLUDED
