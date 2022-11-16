#ifndef TDAPAQUETES_H_INCLUDED
#define TDAPAQUETES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                            INTERFAZ DEL TDA PAQUETES

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Paquete
{
    int ID;
    int ancho;
    int alto;
    int largo;
    int peso;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    FechaPtr fechaEntrega;
    int estado;
} Paquete;
typedef Paquete * PaquetePtr;

/** ESTADOS DEL PAQUETE:
        0 = En depósito
        1 = En curso
        2 = Retirado
        3 = Entregado
        4 = Demorado
        5 = Suspendido
        6 = Reservado
*/


///CREACION Y DESTRUCCION

/** OPERACIÓN: crea un paquete
PRECONDICIÓN: Paquete no debe estar creado.
POSTCONDICIÓN: se crea un nuevo paquete con los parámetros recibidos
PARÁMETROS:
    - ID: entero que representa el id del paquete.(es unico).
    - ancho: entero que represeta el ancho.
    - alto: entero que represeta el alto.
    - largo: entero que represeta el largo.
    - peso: entero que represeta el peso.
    - dirRetiro: puntero a la estructura que representa la direccion de retiro.
    - dirEntrega: puntero a la estructura que representa la direccion de entrega.
    - fechaEntrega: puntero a la estructura que representa la fecha de entrega.
    - estado: entero que represeta el estado del paquete.
DEVUELVE: un puntero al paquete creado. */
PaquetePtr crearPaquete(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,int estado);

/** OPERACIÓN: crea un paquete de forma directa, sin recibir estructuras
PRECONDICIÓN: ninguna
POSTCONDICIÓN: se crea un nuevo paquete con los parámetros recibidos.
               Para los domicilios y fecha de entrega, llama a sus respectivas constructoras
PARÁMETROS:
    - ID: entero que representa el id del paquete.(único por paquete / generado al azar en la funcion menuCargaPaquete(), en Menus.c).
    - ancho: entero que represeta el ancho.
    - alto: entero que represeta el alto.
    - largo: entero que represeta el largo.
    - peso: entero que represeta el peso.
    - calleRetiro: string representando la calle de la direccion de retiro.
    - alturaRetiro: entero representando la altura de la calle de la direccion de retiro.
    - localidadRetiro: string representando la localidad de la direccion de retiro.
    - calleEntrega: string representando la calle de la direccion de entrega.
    - alturaEntrega: entero representando la altura de la calle de la direccion de entrega.
    - localidadEntrega: string representando la localidad de la direccion de entrega.
    - fechaEntrega: 5 enteros representando el dia, mes, año, hora y minuto de entrega.
    - estado: entero que represeta el estado del paquete.
DEVUELVE: un puntero al paquete creado. */
PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,int estado);

/** OPERACIÓN: destrucción (destructora)
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: se libera la memoria reservada para el paquete
PARÁMETROS:
    - paquete: puntero al paquete a destruir.
DEVUELVE: NULL. */
PaquetePtr destruirPaquete(PaquetePtr paquete);


///GETTERS

/** OPERACIÓN: Obtencion de ID.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el ID.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero represntando el ID. */
int getID(PaquetePtr paquete);

/** OPERACIÓN: Obtencion del ancho.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el ancho.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el ancho. */
int getAncho(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de alto.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el alto.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el ancho. */
int getAlto(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de largo.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el largo.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el largo. */
int getLargo(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de peso.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el peso.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero representando el peso. */
int getPeso(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de direcccion de retiro.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene la direccion de retiro.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un puntero a la direccion de retiro. */
DomicilioPtr getDirRetiro(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de direccion de entrega.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene la direccion de entrega.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un puntero a la direccion de entrega. */
DomicilioPtr getDirEntrega(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de fecha de entrega.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene la fecha y horas de la entrega.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un puntero a la fecha de entrega. */
FechaPtr getFechaEntrega(PaquetePtr paquete);

/** OPERACIÓN: Obtencion de estado.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Se obtiene el estado.
PARÁMETROS:
    - paquete: puntero a la estructura a sacar el dato.
DEVUELVE: un entero que representa el estado del paquete. */
int getEstado(PaquetePtr paquete);


///SETTERS

/** OPERACIÓN: Asignar Id.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo id.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - id: entero que representa el nuevo id.
DEVUELVE: nada. */
void setID(PaquetePtr paquete,int ID);

/** OPERACIÓN: Asignar ancho.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo ancho.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - ancho: entero que representa el nuevo ancho.
DEVUELVE: nada. */
void setAncho(PaquetePtr paquete,int ancho);

/** OPERACIÓN: Asignar alto.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo alto.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - alto: entero que representa el nuevo alto.
DEVUELVE: nada. */
void setAlto(PaquetePtr paquete,int alto);

/** OPERACIÓN: Asignar largo.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo largo.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - largo: entero que representa el nuevo largo.
DEVUELVE: nada. */
void setLargo(PaquetePtr paquete,int largo);

/** OPERACIÓN: Asignar peso.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo peso.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el nuevo dato.
    - peso: entero que representa el nuevo peso.
DEVUELVE: nada. */
void setPeso(PaquetePtr paquete,int peso);

/** OPERACIÓN: Asignar la direccion de retiro.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene una nueva direccion de retiro.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - dirRetiro: puntero a la estructura que representa la nueva direccion de retiro.
DEVUELVE: nada. */
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro);

/** OPERACIÓN: Asignar la direccion de entrega.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene una nueva direccion de entrega.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - dirEntrega: puntero a la estructura que representa la nueva direccion de entrega.
DEVUELVE: nada. */
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega);

/** OPERACIÓN: Asignar la fecha de entrega.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene una nueva fecha de entrega.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - fechaEntrega: puntero a la estructura que representa la nueva fecha de entrega.
DEVUELVE: nada. */
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega);

/** OPERACIÓN: Asignar estado.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Paquete tiene un nuevo estado.
PARÁMETROS:
    - paquete: puntero a la estructura a asignar el  nuevo dato.
    - entero: entero que representa el nuevo estado del paquete.
DEVUELVE: nada. */
void setEstado(PaquetePtr paquete,int estado);


///OPERACIONES ESPECIALES

/** OPERACIÓN: Muestra el paquete.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: Imprime un paquete por pantalla.
PARÁMETROS:
    - paquete: puntero a la estructura a mostrar.
DEVUELVE: nada. */
void mostrarPaquete(PaquetePtr paquete);

/** OPERACIÓN: Muestra los estados que puede tener un paquete y los números relacionados con cada uno.
    0 = En depósito
    1 = En curso
    2 = Retirado
    3 = Entregado
    4 = Demorado
    5 = Suspendido
PRECONDICIÓN: no tiene.
POSTCONDICIÓN: Se imprimirán los tipos de estados.
PARÁMETROS: niguno
DEVUELVE: nada. */
void helpEstadoPaquete();

/** OPERACIÓN: muestra el estado del paquete.
PRECONDICIÓN: Paquete debe estar creado.
POSTCONDICIÓN: imprime el estado
PARÁMETROS:
    - paquete: puntero a la estructura a imprimir.
DEVUELVE: nada. */
void mostrarEstadopaquete(PaquetePtr paquete);

/** OPERACIÓN: verifica si dos paquetes son iguales.
PRECONDICIÓN: Ambos paquetes deben haber sido creados.
POSTCONDICIÓN: chequea la equidad de cada campo de la estructura.
PARÁMETROS:
    - paquete1: puntero a la estructura a verificar.
    - paquete2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos en ID O en el resto de campos, false de lo contrario. */
bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2);

/** OPERACIÓN: crea una copia de un paquete (Orientada para la funcion copiarLista)
PRECONDICIÓN: paqueteOriginal debe haber sido creado previamente
POSTCONDICIÓN: duplica los contenidos del paquete en uno nuevo
PARÁMETROS:
    - paqueteOriginal: puntero al paquete del que se quiere hacer una copia
DEVUELVE: puntero a la copia del paquete creada. */
PaquetePtr copiarPaquete(PaquetePtr paqueteOriginal);


#endif // TDAPAQUETES_H_INCLUDED
