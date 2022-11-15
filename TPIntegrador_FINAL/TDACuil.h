#ifndef TDACUIL_H_INCLUDED
#define TDACUIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*******************************************************************************************************

                                        TDA CUIL - INTERFAZ

*******************************************************************************************************/

typedef struct Cuil
{ //hombre=20,mujer=27,empresa=30
    char *cuil; ///NUEVA IMPLEMENTACION: Ahora es un solo string.
} Cuil;

///NOTAS: SE AGREGARON ALGUNAS FUNCIONES, Y OTRAS SE CONSERVARON (ej.: setters y getters)

typedef Cuil* CuilPtr;

///*****************************************************************************************************
///                                 FUNCIONES: CREACION Y DESTRUCCION
//Operación: Creacion del TDACuil
//PRECONDICIÓN: Cuil no debe estar creado.
//POSTCONDICIÓN: Crea un nuevo cuil.
//PARÁMETROS:
tipo: entero que representa el genero
dni: entero que representa el documenteo dni.
nVerificador: entero que representa el numero verificador.
//DEVUELVE: un puntero a la estructura creada.
CuilPtr crearCuil(char *cuilStr);

//Para no reemplazar la funcion con la vieja implementacion que teníamos con la nueva, hice esta
//En realidad, está bien tener esta funcion, pero hay que cambiar la que está en los menues
CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador);

//Operación: Destruccion del TDACuil.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Se elimina de la memoria el cuil y se libera.
//PARÁMETROS:
cuil: puntero a la estructura a destruir.
//DEVUELVE: NULL.
CuilPtr destruirCuil(CuilPtr cuil);

///*****************************************************************************************************
///                                            SETTERS

void setCuil(CuilPtr cuil,char *cuilStr); ///NUEVA
//Operación: Asignacion de tipo de genero.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Cuil va a tener un nuevo tipo de valor.
//PARÁMETROS:
cuil: puntero a la estructura a asignar el nuevo dato.
tipo: entero que representa el nuevo dato.
//DEVUELVE: nada
void setTipo(CuilPtr cuil,int tipo);
//Operación: Asignacion de dni.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Cuil va a tener un nuevo tipo de valor.
//PARÁMETROS:
cuil: puntero a la estructura a asignar el nuevo dato.
dni: entero que representa el nuevo dato.
//DEVUELVE: nada
void setDni(CuilPtr cuil,int dni);
//Operación: Asignacion de tipo de genero.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Cuil va a tener un nuevo tipo de valor.
//PARÁMETROS:
cuil: puntero a la estructura a asignar el nuevo dato.
nVerificador: entero que representa el nuevo dato.
//DEVUELVE: nada
void setNVerificador(CuilPtr cuil,int nVerificador);

///*****************************************************************************************************
///                                            GETTERS

char *getCuil(CuilPtr cuil); ///NUEVA

//Operación: Obtencion del tipo.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Se obtiene el tipo de cuil.
//PARÁMETROS:
// cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el tipo de cuil.
int getTipo(CuilPtr cuil);
//Operación: Obtencion del tipo.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Se obtiene el dni de cuil.
//PARÁMETROS:
cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el dni de cuil.
int getDni(CuilPtr cuil);
//Operación: Obtencion del tipo.
//PRECONDICIÓN: Cuil debe estar creado.
//POSTCONDICIÓN: Se obtiene el numero verificador de cuil.
//PARÁMETROS:
cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el nuemero verificador de cuil.
int getNVerificador(CuilPtr cuil);

///*****************************************************************************************************
///                                       ESPECIALES

//Operación: determina si el cuil recibido es valido
//PRECONDICIÓN: cuil debe haber sido creado con crearCuil()
//POSTCONDICIÓN: ninguna
//PARÁMETROS: puntero a estructura cuil a validar
//DEVUELVE: true si es valido, false de lo contrario. */
bool esCuilValido(CuilPtr cuil); ///NUEVA - NO APTA PARA TIPO EMPRESA

///*****************************************************************************************************

//Operación: menú de ayuda de CUIL
//PRECONDICIÓN: ninguna
//POSTCONDICIÓN: ninguna
//PARÁMETROS: despliega un menú de ayuda para que el usuario sepa como es un cuil
//No DEVUELVE: nada.
void helpCuil();

//Operación: muestra el CUIL recibido
//PRECONDICIÓN: cuil debe haber sido creado con crearCuil()
//POSTCONDICIÓN: imprime el CUIL recibido por pantalla
//PARÁMETROS: puntero a estructura cuil que se quiere mostrar
//No DEVUELVE: nada.
void mostrarCuil(CuilPtr cuil);

//Operación: verifica si dos CUIL son iguales.
//PRECONDICIÓN: Ambos cuil deben haber sido creados.
//POSTCONDICIÓN: chequea si las estructuras son idénticas en cuil
//PARÁMETROS:
 cuil1: puntero a la estructura a verificar.
 cuil2: puntero a la estructura a verificar.
//DEVUELVE:  true si son idénticos, false de lo contrario. */.
bool cuilsIguales(CuilPtr cuil1,CuilPtr cuil2);


#endif // TDACUIL_H_INCLUDED
