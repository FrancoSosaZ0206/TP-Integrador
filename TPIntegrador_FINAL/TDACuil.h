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
//Precondición: Cuil no debe estar creado.
//Postcondición: Crea un nuevo cuil.
//Parámetros:
// tipo: entero que representa el genero
// dni: entero que representa el documenteo dni.
// nVerificador: entero que representa el numero verificador.
//Devuelve un puntero a la estructura creada.
CuilPtr crearCuil(char *cuilStr);

//Para no reemplazar la funcion con la vieja implementacion que teníamos con la nueva, hice esta
//En realidad, está bien tener esta funcion, pero hay que cambiar la que está en los menues
CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador);

//Operación: Destruccion del TDACuil.
//Precondición: Cuil debe estar creado.
//Postcondición: Se elimina de la memoria el cuil y se libera.
//Parámetros:
// cuil: puntero a la estructura a destruir.
//Devuelve NULL.
CuilPtr destruirCuil(CuilPtr cuil);

///*****************************************************************************************************
///                                            SETTERS

void setCuil(CuilPtr cuil,char *cuilStr); ///NUEVA
//Operación: Asignacion de tipo de genero.
//Precondición: Cuil debe estar creado.
//Postcondición: Cuil va a tener un nuevo tipo de valor.
//Parámetros:
// cuil: puntero a la estructura a asignar el nuevo dato.
// tipo: entero que representa el nuevo dato.
//Devuelve nada
void setTipo(CuilPtr cuil,int tipo);
//Operación: Asignacion de dni.
//Precondición: Cuil debe estar creado.
//Postcondición: Cuil va a tener un nuevo tipo de valor.
//Parámetros:
// cuil: puntero a la estructura a asignar el nuevo dato.
// dni: entero que representa el nuevo dato.
//Devuelve nada
void setDni(CuilPtr cuil,int dni);
//Operación: Asignacion de tipo de genero.
//Precondición: Cuil debe estar creado.
//Postcondición: Cuil va a tener un nuevo tipo de valor.
//Parámetros:
// cuil: puntero a la estructura a asignar el nuevo dato.
// nVerificador: entero que representa el nuevo dato.
//Devuelve nada
void setNVerificador(CuilPtr cuil,int nVerificador);

///*****************************************************************************************************
///                                            GETTERS

char *getCuil(CuilPtr cuil); ///NUEVA

//Operación: Obtencion del tipo.
//Precondición: Cuil debe estar creado.
//Postcondición: Se obtiene el tipo de cuil.
//Parámetros:
// cuil: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el tipo de cuil.
int getTipo(CuilPtr cuil);
//Operación: Obtencion del tipo.
//Precondición: Cuil debe estar creado.
//Postcondición: Se obtiene el dni de cuil.
//Parámetros:
// cuil: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el dni de cuil.
int getDni(CuilPtr cuil);
//Operación: Obtencion del tipo.
//Precondición: Cuil debe estar creado.
//Postcondición: Se obtiene el numero verificador de cuil.
//Parámetros:
// cuil: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el nuemero verificador de cuil.
int getNVerificador(CuilPtr cuil);

///*****************************************************************************************************
///                                       ESPECIALES

//Operación: determina si el cuil recibido es valido
//Precondición: cuil debe haber sido creado con crearCuil()
//Postcondición: ninguna
//Parámetros: puntero a estructura cuil a validar
//Devuelve true si es valido, false de lo contrario
bool esCuilValido(CuilPtr cuil); ///NUEVA - NO APTA PARA TIPO EMPRESA

//Operación: sugiere un cuil valido a partir del que se recibe
//Precondición: cuil debe haber sido creado con crearCuil()
//Postcondición: imprime una sugerencia de cuil valido por pantalla
//Parámetros: puntero a estructura cuil de la cual se quiere mostrar sugerencia
//No devuelve nada.
void sugerirCuilValido(CuilPtr cuil);

//Operación: convierte el cuil recibido a un cuil valido (si era invalido)
//Precondición: cuil debe haber sido creado con crearCuil()
//Postcondición: cuil cambia a un nuevo valor válido
//Parámetros: puntero a estructura cuil que se quiere convertir
//No devuelve nada.
///ADVERTENCIA: Cambia el cuil original aunque la conversion falle.
void convertirACuilValido(CuilPtr cuil);

///*****************************************************************************************************

//Operación: menú de ayuda de CUIL
//Precondición: ninguna
//Postcondición: ninguna
//Parámetros: despliega un menú de ayuda para que el usuario sepa como es un cuil
//No devuelve nada.
void helpCuil();

//Operación: muestra el CUIL recibido
//Precondición: cuil debe haber sido creado con crearCuil()
//Postcondición: imprime el CUIL recibido por pantalla
//Parámetros: puntero a estructura cuil que se quiere mostrar
//No devuelve nada.
void mostrarCuil(CuilPtr cuil);

#endif // TDACUIL_H_INCLUDED
