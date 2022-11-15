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
    0 = En dep�sito
    1 = En curso
    2 = Retirado
    3 = Entregado
    4 = Demorado
    5 = Suspendido
*/

//Operaci�n: crea un paquete
//PRECONDICI�N: Paquete no debe estar creado.
//POSTCONDICI�N: Un nuevo paquete se creo.
//PAR�METROS:
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


//Operaci�n: crea un paquete de forma directa, sin recibir estructuras
//PRECONDICI�N: Paquete no debe estar creado.
//POSTCONDICI�N: Un nuevo paquete se creo.
//PAR�METROS:
ID: entero que representa el id del paquete.(�nico por paquete / generado al azar en la funcion menuCargaPaquete(), en Menus.c).
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
fechaEntrega: 5 enteros representando el dia, mes, a�o, hora y minuto de entrega.
estado: entero que represeta el estado del paquete.
//DEVUELVE: un puntero a la estructura creada.
PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,int estado);

//Operaci�n: Destruye el TDApaquete
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: No va a haber un paquete y la memoria va a ser liberada.
//PAR�METROS:
paquete: puntero a la estructura a destruir.
//DEVUELVE: NULL.
PaquetePtr destruirPaquete(PaquetePtr paquete);

//Operaci�n: Obtencion de Id.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el id.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero represntando el id.
int getID(PaquetePtr paquete);
//Operaci�n: Obtencion del ancho.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el ancho.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el ancho.
int getAncho(PaquetePtr paquete);
//Operaci�n: Obtencion de alto.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el alto.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el ancho.
int getAlto(PaquetePtr paquete);
//Operaci�n: Obtencion de largo.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el largo.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el largo.
int getLargo(PaquetePtr paquete);
//Operaci�n: Obtencion de peso.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el peso.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero representando el peso.
int getPeso(PaquetePtr paquete);
//Operaci�n: Obtencion de direcccion de retiro.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene la direccion de retiro.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la direccion de retiro.
DomicilioPtr getDirRetiro(PaquetePtr paquete);
//Operaci�n: Obtencion de direccion de entrega.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene la direccion de entrega.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la direccion de entrega.
DomicilioPtr getDirEntrega(PaquetePtr paquete);
//Operaci�n: Obtencion de fecha de entrega.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene la fecha y horas de la entrega.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un puntero a la estructura que es la fecha de entrega.
FechaPtr getFechaEntrega(PaquetePtr paquete);
//Operaci�n: Obtencion de estado.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Se obtiene el estado.
//PAR�METROS:
paquete: puntero a la estructura a sacar el dato.
//DEVUELVE: un entero que representa el estado del paquete.
int getEstado(PaquetePtr paquete);

//Operaci�n: Asignar Id.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo id.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
id: entero que representa el nuevo id.
//DEVUELVE: nada
void setID(PaquetePtr paquete,int ID);
//Operaci�n: Asignar ancho.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo ancho.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
ancho: entero que representa el nuevo ancho.
//DEVUELVE: nada
void setAncho(PaquetePtr paquete,int ancho);
//Operaci�n: Asignar alto.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo alto.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
alto: entero que representa el nuevo alto.
//DEVUELVE: nada
void setAlto(PaquetePtr paquete,int alto);
//Operaci�n: Asignar largo.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo largo.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
largo: entero que representa el nuevo largo.
//DEVUELVE: nada
void setLargo(PaquetePtr paquete,int largo);
//Operaci�n: Asignar peso.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo peso.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
peso: entero que representa el nuevo peso.
//DEVUELVE: nada
void setPeso(PaquetePtr paquete,int peso);
//Operaci�n: Asignar la direccion de retiro.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene una nueva direccion de retiro.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
dirRetiro: puntero a la estructura que representa la nueva direccion de retiro.
//DEVUELVE: nada
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro);
//Operaci�n: Asignar la direccion de entrega.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene una nueva direccion de entrega.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
dirEntrega: puntero a la estructura que representa la nueva direccion de entrega.
//DEVUELVE: nada
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega);
//Operaci�n: Asignar la fecha de entrega.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene una nueva fecha de entrega.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
fechaEntrega: puntero a la estructura que representa la nueva fecha de entrega.
//DEVUELVE: nada
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega);
//Operaci�n: Asignar estado.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Paquete tiene un nuevo estado.
//PAR�METROS:
paquete: puntero a la estructura a asignar el  nuevo dato.
entero: entero que representa el nuevo estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//DEVUELVE: nada
void setEstado(PaquetePtr paquete,int estado);

//Operaci�n: Muestra el paquete.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: Imprime lista de paquetes.
//PAR�METROS:
paquete: puntero a la estructura a imprimir.
//DEVUELVE: nada
void mostrarPaquete(PaquetePtr paquete);
//Operaci�n: Muestra los estados que puede tener un paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//PRECONDICI�N: no tiene.
//POSTCONDICI�N: Se imprimiran los tipos de estados.
//PAR�METROS: niguno
//DEVUELVE: nada
void helpEstadoPaquete(); //muestra que relacion hay entre cada numero y cada estado posible del paquete.
//Operaci�n: muestra el estado del paquete.
//PRECONDICI�N: Paquete debe estar creado.
//POSTCONDICI�N: imprime el estado
//PAR�METROS:
paquete: puntero a la estructura a imprimir.
//DEVUELVE: nada
void mostrarEstadopaquete(PaquetePtr paquete); //muestra solo el estado actual del paquete recibido.

//Operaci�n: verifica si dos paquetes son iguales.
//PRECONDICI�N: Ambos paquetes deben haber sido creados.
//POSTCONDICI�N: chequea la equidad de cada campo de la estructura.
//PAR�METROS:
 paquete1: puntero a la estructura a verificar.
 paquete2: puntero a la estructura a verificar.
//DEVUELVE:  true si son id�nticos en ID O en el resto de campos, false de lo contrario.
bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2);

/*  Operaci�n: crea una copia de un paquete
PRECONDICI�N: paqueteOriginal debe haber sido creado previamente
POSTCONDICI�N: duplica los contenidos del paquete en uno nuevo
PAR�METROS:
    - paqueteOriginal: puntero al paquete del que se quiere hacer una copia
DEVUELVE:  puntero a la copia del paquete creada. */
PaquetePtr copiarPaquete(PaquetePtr paqueteOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif // TDAPAQUETES_H_INCLUDED
