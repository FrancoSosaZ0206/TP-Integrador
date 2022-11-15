#ifndef TDAPAQUETES_H_INCLUDED
#define TDAPAQUETES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"

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
*/

//Operación: crea un paquete
//PRECONDICIÓN: Paquete no debe estar creado.
//POSTCONDICIÓN: Un nuevo paquete se creo.
//PARÁMETROS:
ID: entero que representa el id del paquete.(es unico).
ancho: entero que represeta el ancho.
alto: entero que represeta el alto.
largo: entero que represeta el largo.
peso: entero que represeta el peso.
dirRetiro: puntero a la estructura que representa la direccion de retiro.
dirEntrega: puntero a la estructura que representa la direccion de entrega.
fechaEntrega: puntero a la estructura que representa la fecha de entrega.
estado: entero que represeta el estado del paquete.
//DEVUELVE: un puntero a la estructura creada.
PaquetePtr crearPaquete(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,int estado);


//Operación: crea un paquete de forma directa, sin recibir estructuras
//PRECONDICIÓN: Paquete no debe estar creado.
//POSTCONDICIÓN: Un nuevo paquete se creo.
//PARÁMETROS:
ID: entero que representa el id del paquete.(único por paquete / generado al azar en la funcion menuCargaPaquete(), en Menus.c).
ancho: entero que represeta el ancho.
alto: entero que represeta el alto.
largo: entero que represeta el largo.
peso: entero que represeta el peso.
calleRetiro: string representando la calle de la direccion de retiro.
alturaRetiro: entero representando la altura de la calle de la direccion de retiro.
localidadRetiro: string representando la localidad de la direccion de retiro.
calleEntrega: string representando la calle de la direccion de entrega.
alturaEntrega: entero representando la altura de la calle de la direccion de entrega.
localidadEntrega: string representando la localidad de la direccion de entrega.
fechaEntrega: 5 enteros representando el dia, mes, año, hora y minuto de entrega.
estado: entero que represeta el estado del paquete.
//DEVUELVE: un puntero a la estructura creada.
PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,int estado);

//Operación: Destruye el TDApaquete
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: No va a haber un paquete y la memoria va a ser liberada.
//PARÁMETROS:
paquete: puntero a la estructura a destruir.
//DEVUELVE: NULL.
PaquetePtr destruirPaquete(PaquetePtr paquete);

//Operación: Obtencion de Id.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el id.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero represntando el id.
int getID(PaquetePtr paquete);
//Operación: Obtencion del ancho.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el ancho.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el ancho.
int getAncho(PaquetePtr paquete);
//Operación: Obtencion de alto.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el alto.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el ancho.
int getAlto(PaquetePtr paquete);
//Operación: Obtencion de largo.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el largo.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el largo.
int getLargo(PaquetePtr paquete);
//Operación: Obtencion de peso.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el peso.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el peso.
int getPeso(PaquetePtr paquete);
//Operación: Obtencion de direcccion de retiro.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene la direccion de retiro.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la direccion de retiro.
DomicilioPtr getDirRetiro(PaquetePtr paquete);
//Operación: Obtencion de direccion de entrega.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene la direccion de entrega.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la direccion de entrega.
DomicilioPtr getDirEntrega(PaquetePtr paquete);
//Operación: Obtencion de fecha de entrega.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene la fecha y horas de la entrega.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la fecha de entrega.
FechaPtr getFechaEntrega(PaquetePtr paquete);
//Operación: Obtencion de estado.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Se obtiene el estado.
//PARÁMETROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero que representa el estado del paquete.
int getEstado(PaquetePtr paquete);

//Operación: Asignar Id.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo id.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
id: entero que representa el nuevo id.
//DEVUELVE: nada
void setID(PaquetePtr paquete,int ID);
//Operación: Asignar ancho.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo ancho.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
ancho: entero que representa el nuevo ancho.
//DEVUELVE: nada
void setAncho(PaquetePtr paquete,int ancho);
//Operación: Asignar alto.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo alto.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
alto: entero que representa el nuevo alto.
//DEVUELVE: nada
void setAlto(PaquetePtr paquete,int alto);
//Operación: Asignar largo.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo largo.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
largo: entero que representa el nuevo largo.
//DEVUELVE: nada
void setLargo(PaquetePtr paquete,int largo);
//Operación: Asignar peso.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo peso.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
peso: entero que representa el nuevo peso.
//DEVUELVE: nada
void setPeso(PaquetePtr paquete,int peso);
//Operación: Asignar la direccion de retiro.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene una nueva direccion de retiro.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
dirRetiro: puntero a la estructura que representa la nueva direccion de retiro.
//DEVUELVE: nada
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro);
//Operación: Asignar la direccion de entrega.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene una nueva direccion de entrega.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
dirEntrega: puntero a la estructura que representa la nueva direccion de entrega.
//DEVUELVE: nada
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega);
//Operación: Asignar la fecha de entrega.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene una nueva fecha de entrega.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
fechaEntrega: puntero a la estructura que representa la nueva fecha de entrega.
//DEVUELVE: nada
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega);
//Operación: Asignar estado.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Paquete tiene un nuevo estado.
//PARÁMETROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
entero: entero que representa el nuevo estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//DEVUELVE: nada
void setEstado(PaquetePtr paquete,int estado);

//Operación: Muestra el paquete.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: Imprime lista de paquetes.
//PARÁMETROS:
paquete: puntero a la estructura a imprimir.
//DEVUELVE: nada
void mostrarPaquete(PaquetePtr paquete);
//Operación: Muestra los estados que puede tener un paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//PRECONDICIÓN: no tiene.
//POSTCONDICIÓN: Se imprimiran los tipos de estados.
//PARÁMETROS: niguno
//DEVUELVE: nada
void helpEstadoPaquete(); //muestra que relacion hay entre cada numero y cada estado posible del paquete.
//Operación: muestra el estado del paquete.
//PRECONDICIÓN: Paquete debe estar creado.
//POSTCONDICIÓN: imprime el estado
//PARÁMETROS:
paquete: puntero a la estructura a imprimir.
//DEVUELVE: nada
void mostrarEstadopaquete(PaquetePtr paquete); //muestra solo el estado actual del paquete recibido.

//Operación: verifica si dos paquetes son iguales.
//PRECONDICIÓN: Ambos paquetes deben haber sido creados.
//POSTCONDICIÓN: chequea la equidad de cada campo de la estructura.
//PARÁMETROS:
 paquete1: puntero a la estructura a verificar.
 paquete2: puntero a la estructura a verificar.
//DEVUELVE:  true si son idénticos en ID O en el resto de campos, false de lo contrario.
bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2);

/*  Operación: crea una copia de un paquete
PRECONDICIÓN: paqueteOriginal debe haber sido creado previamente
POSTCONDICIÓN: duplica los contenidos del paquete en uno nuevo
PARÁMETROS:
    - paqueteOriginal: puntero al paquete del que se quiere hacer una copia
DEVUELVE:  puntero a la copia del paquete creada. */
PaquetePtr copiarPaquete(PaquetePtr paqueteOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif // TDAPAQUETES_H_INCLUDED
