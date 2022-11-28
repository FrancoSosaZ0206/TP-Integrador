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

/// Nueva implementación
/** OPERACIÓN: creación (constructora)
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se crea un cuil en memoria dinámica con el parámetro recibido
PARÁMETROS:
    - cuilStr: string representando el cuil a crear
DEVUELVE: un puntero al TDA cuil creado. */
CuilPtr crearCuil(char *cuilStr);

/// Vieja implementación
/** OPERACIÓN: creación (constructora)
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se crea un cuil en memoria dinámica con los parámetros recibidos
PARÁMETROS:
    - tipo: entero que representa el tipo de persona
    - dni: entero que representa el documento dni.
    - nVerificador: entero que representa el numero verificador.
DEVUELVE: un puntero al cuil creado. */
CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador);

/** OPERACIÓN: destrucción (destructora)
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: se libera la memoria reservada para el cuil
PARÁMETROS:
    - cuil: puntero al cuil a destruir.
DEVUELVE: NULL. */
CuilPtr destruirCuil(CuilPtr cuil);


///*****************************************************************************************************
///                                            SETTERS

/** OPERACIÓN: Asignacion de cuil completo.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: la estructura cuil cambia con el valor del nuevo cuil string.
PARÁMETROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - cuilStr: string representando el nuevo cuil.
DEVUELVE: nada. */
void setCuil(CuilPtr cuil,char *cuilStr);

/** OPERACIÓN: Asignacion de tipo de genero.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: cuil cambia con el nuevo tipo.
PARÁMETROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - tipo: entero que representa el nuevo tipo de persona.
DEVUELVE: nada. */
void setTipo(CuilPtr cuil,int tipo);

/** OPERACIÓN: Asignacion de dni.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: cuil cambia con el nuevo dni.
PARÁMETROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - dni: entero que representa el nuevo dni.
DEVUELVE: nada. */
void setDni(CuilPtr cuil,int dni);

/** OPERACIÓN: Asignacion de tipo de genero.
PRECONDICIÓN: cuil debe estar creado.
POSTCONDICIÓN: cuil cambia con el nuevo numero verificador.
PARÁMETROS:
    - cuil: puntero a la estructura a asignar el nuevo dato.
    - nVerificador: entero que representa el nuevo numero verificador.
DEVUELVE: nada. */
void setNVerificador(CuilPtr cuil,int nVerificador);


///*****************************************************************************************************
///                                            GETTERS

/** OPERACIÓN: obtencion del cuil.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: se obtiene el cuil completo en forma de string.
PARÁMETROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un puntero a char representando el cuil. */
char *getCuil(CuilPtr cuil);

/** OPERACIÓN: Obtencion del tipo.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: Se obtiene el tipo de cuil.
PARÁMETROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el tipo de cuil. */
int getTipo(CuilPtr cuil);

/** OPERACIÓN: Obtencion del tipo.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: Se obtiene el dni de cuil.
PARÁMETROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el dni de cuil. */
int getDni(CuilPtr cuil);

/** OPERACIÓN: Obtencion del tipo.
PRECONDICIÓN: cuil debe haberse creado con crearCuil
POSTCONDICIÓN: Se obtiene el numero verificador de cuil.
PARÁMETROS:
    - cuil: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el numero verificador de cuil. */
int getNVerificador(CuilPtr cuil);


///*****************************************************************************************************
///                                       ESPECIALES

/** OPERACIÓN: determina si un cuil es valido
PRECONDICIÓN: cuil debe haber sido creado con crearCuil
POSTCONDICIÓN: ninguna
PARÁMETROS:
    - puntero al cuil a validar
DEVUELVE: true si es valido, false de lo contrario. */
bool esCuilValido(CuilPtr cuil); ///NO APTA PARA TIPO EMPRESA

///*****************************************************************************************************

/** OPERACIÓN: menú de ayuda de CUIL
PRECONDICIÓN: ninguna
POSTCONDICIÓN: despliega un menú de ayuda para que el usuario sepa como es un cuil
PARÁMETROS: ninguno
DEVUELVE: nada. */
void helpCuil();

/** OPERACIÓN: muestra el CUIL recibido
PRECONDICIÓN: cuil debe haber sido creado con crearCuil
POSTCONDICIÓN: imprime el CUIL recibido por pantalla
PARÁMETROS:
    - puntero al cuil a mostrar
DEVUELVE: nada. */
void mostrarCuil(CuilPtr cuil);

/** OPERACIÓN: verifica si dos CUIL son iguales.
PRECONDICIÓN: Ambos cuil deben haber sido creados.
POSTCONDICIÓN: chequea si las estructuras son idénticas en cuil
PARÁMETROS:
    - cuil1: puntero a la estructura a verificar.
    - cuil2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos, false de lo contrario. */
bool cuilsIguales(CuilPtr cuil1,CuilPtr cuil2);


#endif // TDACUIL_H_INCLUDED
