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
//Operaci�n: Creacion del TDACuil
//PRECONDICI�N: Cuil no debe estar creado.
//POSTCONDICI�N: Crea un nuevo cuil.
//PAR�METROS:
tipo: entero que representa el genero
dni: entero que representa el documenteo dni.
nVerificador: entero que representa el numero verificador.
//DEVUELVE: un puntero a la estructura creada.
CuilPtr crearCuil(char *cuilStr);

//Para no reemplazar la funcion con la vieja implementacion que ten�amos con la nueva, hice esta
//En realidad, est� bien tener esta funcion, pero hay que cambiar la que est� en los menues
CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador);

//Operaci�n: Destruccion del TDACuil.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Se elimina de la memoria el cuil y se libera.
//PAR�METROS:
cuil: puntero a la estructura a destruir.
//DEVUELVE: NULL.
CuilPtr destruirCuil(CuilPtr cuil);

///*****************************************************************************************************
///                                            SETTERS

void setCuil(CuilPtr cuil,char *cuilStr); ///NUEVA
//Operaci�n: Asignacion de tipo de genero.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Cuil va a tener un nuevo tipo de valor.
//PAR�METROS:
cuil: puntero a la estructura a asignar el nuevo dato.
tipo: entero que representa el nuevo dato.
//DEVUELVE: nada
void setTipo(CuilPtr cuil,int tipo);
//Operaci�n: Asignacion de dni.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Cuil va a tener un nuevo tipo de valor.
//PAR�METROS:
cuil: puntero a la estructura a asignar el nuevo dato.
dni: entero que representa el nuevo dato.
//DEVUELVE: nada
void setDni(CuilPtr cuil,int dni);
//Operaci�n: Asignacion de tipo de genero.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Cuil va a tener un nuevo tipo de valor.
//PAR�METROS:
cuil: puntero a la estructura a asignar el nuevo dato.
nVerificador: entero que representa el nuevo dato.
//DEVUELVE: nada
void setNVerificador(CuilPtr cuil,int nVerificador);

///*****************************************************************************************************
///                                            GETTERS

char *getCuil(CuilPtr cuil); ///NUEVA

//Operaci�n: Obtencion del tipo.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Se obtiene el tipo de cuil.
//PAR�METROS:
// cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el tipo de cuil.
int getTipo(CuilPtr cuil);
//Operaci�n: Obtencion del tipo.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Se obtiene el dni de cuil.
//PAR�METROS:
cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el dni de cuil.
int getDni(CuilPtr cuil);
//Operaci�n: Obtencion del tipo.
//PRECONDICI�N: Cuil debe estar creado.
//POSTCONDICI�N: Se obtiene el numero verificador de cuil.
//PAR�METROS:
cuil: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el nuemero verificador de cuil.
int getNVerificador(CuilPtr cuil);

///*****************************************************************************************************
///                                       ESPECIALES

//Operaci�n: determina si el cuil recibido es valido
//PRECONDICI�N: cuil debe haber sido creado con crearCuil()
//POSTCONDICI�N: ninguna
//PAR�METROS: puntero a estructura cuil a validar
//DEVUELVE: true si es valido, false de lo contrario. */
bool esCuilValido(CuilPtr cuil); ///NUEVA - NO APTA PARA TIPO EMPRESA

///*****************************************************************************************************

//Operaci�n: men� de ayuda de CUIL
//PRECONDICI�N: ninguna
//POSTCONDICI�N: ninguna
//PAR�METROS: despliega un men� de ayuda para que el usuario sepa como es un cuil
//No DEVUELVE: nada.
void helpCuil();

//Operaci�n: muestra el CUIL recibido
//PRECONDICI�N: cuil debe haber sido creado con crearCuil()
//POSTCONDICI�N: imprime el CUIL recibido por pantalla
//PAR�METROS: puntero a estructura cuil que se quiere mostrar
//No DEVUELVE: nada.
void mostrarCuil(CuilPtr cuil);

//Operaci�n: verifica si dos CUIL son iguales.
//PRECONDICI�N: Ambos cuil deben haber sido creados.
//POSTCONDICI�N: chequea si las estructuras son id�nticas en cuil
//PAR�METROS:
 cuil1: puntero a la estructura a verificar.
 cuil2: puntero a la estructura a verificar.
//DEVUELVE:  true si son id�nticos, false de lo contrario. */.
bool cuilsIguales(CuilPtr cuil1,CuilPtr cuil2);


#endif // TDACUIL_H_INCLUDED
