#ifndef TDAPAQUETES_H_INCLUDED
#define TDAPAQUETES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"
#include "TDAPersona.h"

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
    PersonaPtr cliente;
    int estado; ///0=En dep�sito,1=En curso,2=Retirado,3=Entregado,4=Demorado,5=Suspendido
} Paquete;
typedef Paquete * PaquetePtr;

//Operaci�n: crea un paquete
//Precondici�n: Paquete no debe estar creado.
//Postcondici�n: Un nuevo paquete se creo.
//Par�metros:
// ID: entero que representa el id del paquete.(es unico).
// ancho: entero que represeta el ancho.
// alto: entero que represeta el alto.
// largo: entero que represeta el largo.
// peso: entero que represeta el peso.
// dirRetiro: puntero a la estructura que representa la direccion de retiro.
// dirEntrega: puntero a la estructura que representa la direccion de entrega.
// fechaEntrega: puntero a la estructura que representa la fecha de entrega.
// estado: entero que represeta el estado del paquete.
//Devuelve un puntero a la estructura creada.
PaquetePtr crearPaquete(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,PersonaPtr cliente,int estado);


//Operaci�n: crea un paquete de forma directa, sin recibir estructuras
//Precondici�n: Paquete no debe estar creado.
//Postcondici�n: Un nuevo paquete se creo.
//Par�metros:
// ID: entero que representa el id del paquete.(�nico por paquete / generado al azar en la funcion menuCargaPaquete(), en Menus.c).
// ancho: entero que represeta el ancho.
// alto: entero que represeta el alto.
// largo: entero que represeta el largo.
// peso: entero que represeta el peso.
// calleRetiro: string representando la calle de la direccion de retiro.
// alturaRetiro: entero representando la altura de la calle de la direccion de retiro.
// localidadRetiro: string representando la localidad de la direccion de retiro.
// calleEntrega: string representando la calle de la direccion de entrega.
// alturaEntrega: entero representando la altura de la calle de la direccion de entrega.
// localidadEntrega: string representando la localidad de la direccion de entrega.
// fechaEntrega: 5 enteros representando el dia, mes, a�o, hora y minuto de entrega.
// estado: entero que represeta el estado del paquete.
//Devuelve un puntero a la estructura creada.
PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,char* nombre,char* apellido, char* calleCliente, int alturaCliente,char* localidadCliente, char* strCuil,int estado);

//Operaci�n: Destruye el TDApaquete
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: No va a haber un paquete y la memoria va a ser liberada.
//Par�metros:
// paquete: puntero a la estructura a destruir.
//Devuelve NULL.
PaquetePtr destruirPaquete(PaquetePtr paquete);

//Operaci�n: Obtencion de Id.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el id.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero represntando el id.
int getID(PaquetePtr paquete);
//Operaci�n: Obtencion del ancho.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el ancho.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el ancho.
int getAncho(PaquetePtr paquete);
//Operaci�n: Obtencion de alto.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el alto.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el ancho.
int getAlto(PaquetePtr paquete);
//Operaci�n: Obtencion de largo.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el largo.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el largo.
int getLargo(PaquetePtr paquete);
//Operaci�n: Obtencion de peso.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el peso.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el peso.
int getPeso(PaquetePtr paquete);
//Operaci�n: Obtencion de direcccion de retiro.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene la direccion de retiro.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la direccion de retiro.
DomicilioPtr getDirRetiro(PaquetePtr paquete);
//Operaci�n: Obtencion de direccion de entrega.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene la direccion de entrega.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la direccion de entrega.
DomicilioPtr getDirEntrega(PaquetePtr paquete);
//Operaci�n: Obtencion de fecha de entrega.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene la fecha y horas de la entrega.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la fecha de entrega.
FechaPtr getFechaEntrega(PaquetePtr paquete);

//Operaci�n: Obtencion de cliente.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el cliente destinatario.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero que representa el cliente del paquete en forma de puntero a persona.
PersonaPtr getCliente(PaquetePtr paquete);

//Operaci�n: Obtencion de estado.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Se obtiene el estado.
//Par�metros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero que representa el estado del paquete.
int getEstado(PaquetePtr paquete);

//Operaci�n: Asignar Id.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo id.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// id: entero que representa el nuevo id.
//Devuelve nada
void setID(PaquetePtr paquete,int ID);
//Operaci�n: Asignar ancho.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo ancho.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// ancho: entero que representa el nuevo ancho.
//Devuelve nada
void setAncho(PaquetePtr paquete,int ancho);
//Operaci�n: Asignar alto.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo alto.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// alto: entero que representa el nuevo alto.
//Devuelve nada
void setAlto(PaquetePtr paquete,int alto);
//Operaci�n: Asignar largo.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo largo.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// largo: entero que representa el nuevo largo.
//Devuelve nada
void setLargo(PaquetePtr paquete,int largo);
//Operaci�n: Asignar peso.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo peso.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// peso: entero que representa el nuevo peso.
//Devuelve nada
void setPeso(PaquetePtr paquete,int peso);
//Operaci�n: Asignar la direccion de retiro.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene una nueva direccion de retiro.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// dirRetiro: puntero a la estructura que representa la nueva direccion de retiro.
//Devuelve nada
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro);
//Operaci�n: Asignar la direccion de entrega.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene una nueva direccion de entrega.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// dirEntrega: puntero a la estructura que representa la nueva direccion de entrega.
//Devuelve nada
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega);
//Operaci�n: Asignar la fecha de entrega.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene una nueva fecha de entrega.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// fechaEntrega: puntero a la estructura que representa la nueva fecha de entrega.
//Devuelve nada
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega);

//Operaci�n: Asignar el cliente destinatario.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene una nuevo cliente de entrega.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// fechaEntrega: puntero a la estructura que representa el nueva cliente de entrega.
//Devuelve nada
void setCliente(PaquetePtr paquete, PersonaPtr cliente);

//Operaci�n: Asignar estado.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Paquete tiene un nuevo estado.
//Par�metros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// entero: entero que representa el nuevo estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve nada
void setEstado(PaquetePtr paquete,int estado);

//Operaci�n: Muestra el paquete.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: Imprime lista de paquetes.
//Par�metros:
// paquete: puntero a la estructura a imprimir.
//Devuelve nada
void mostrarPaquete(PaquetePtr paquete);
//Operaci�n: Muestra los estados que puede tener un paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Precondici�n: no tiene.
//Postcondici�n: Se imprimiran los tipos de estados.
//Par�metros: niguno
//Devuelve nada
void helpEstadoPaquete(); //muestra que relacion hay entre cada numero y cada estado posible del paquete.
//Operaci�n: muestra el estado del paquete.
//Precondici�n: Paquete debe estar creado.
//Postcondici�n: imprime el estado
//Par�metros:
// paquete: puntero a la estructura a imprimir.
//Devuelve nada
void mostrarEstadopaquete(PaquetePtr paquete); //muestra solo el estado actual del paquete recibido.

//Operaci�n: verifica si dos paquetes son iguales.
//Precondici�n: Ambos paquetes deben haber sido creados.
//Postcondici�n: chequea si cada campo de las estructuras son id�nticos
//Par�metros:
//  paquete1: puntero a la estructura a verificar.
//  paquete2: puntero a la estructura a verificar.
//Devuelve: true si son id�nticos en ID O en el resto de campos, false de lo contrario.
bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2);

#endif // TDAPAQUETES_H_INCLUDED
