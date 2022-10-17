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
    int estado; ///0=En depósito,1=En curso,2=Retirado,3=Entregado,4=Demorado,5=Suspendido
} Paquete;
typedef Paquete * PaquetePtr;

//Operación: crea un paquete
//Precondición: Paquete no debe estar creado.
//Postcondición: Un nuevo paquete se creo.
//Parámetros:
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


//Operación: crea un paquete de forma directa, sin recibir estructuras
//Precondición: Paquete no debe estar creado.
//Postcondición: Un nuevo paquete se creo.
//Parámetros:
// ID: entero que representa el id del paquete.(único por paquete / generado al azar en la funcion menuCargaPaquete(), en Menus.c).
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
// fechaEntrega: 5 enteros representando el dia, mes, año, hora y minuto de entrega.
// estado: entero que represeta el estado del paquete.
//Devuelve un puntero a la estructura creada.
PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,char* nombre,char* apellido, char* calleCliente, int alturaCliente,char* localidadCliente, char* strCuil,int estado);

//Operación: Destruye el TDApaquete
//Precondición: Paquete debe estar creado.
//Postcondición: No va a haber un paquete y la memoria va a ser liberada.
//Parámetros:
// paquete: puntero a la estructura a destruir.
//Devuelve NULL.
PaquetePtr destruirPaquete(PaquetePtr paquete);

//Operación: Obtencion de Id.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el id.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero represntando el id.
int getID(PaquetePtr paquete);
//Operación: Obtencion del ancho.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el ancho.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el ancho.
int getAncho(PaquetePtr paquete);
//Operación: Obtencion de alto.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el alto.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el ancho.
int getAlto(PaquetePtr paquete);
//Operación: Obtencion de largo.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el largo.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el largo.
int getLargo(PaquetePtr paquete);
//Operación: Obtencion de peso.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el peso.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero representando el peso.
int getPeso(PaquetePtr paquete);
//Operación: Obtencion de direcccion de retiro.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene la direccion de retiro.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la direccion de retiro.
DomicilioPtr getDirRetiro(PaquetePtr paquete);
//Operación: Obtencion de direccion de entrega.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene la direccion de entrega.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la direccion de entrega.
DomicilioPtr getDirEntrega(PaquetePtr paquete);
//Operación: Obtencion de fecha de entrega.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene la fecha y horas de la entrega.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un puntero a la estructura que es la fecha de entrega.
FechaPtr getFechaEntrega(PaquetePtr paquete);

//Operación: Obtencion de cliente.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el cliente destinatario.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero que representa el cliente del paquete en forma de puntero a persona.
PersonaPtr getCliente(PaquetePtr paquete);

//Operación: Obtencion de estado.
//Precondición: Paquete debe estar creado.
//Postcondición: Se obtiene el estado.
//Parámetros:
// paquete: puntero a la estructura a sacar el dato.
//Devuelve un entero que representa el estado del paquete.
int getEstado(PaquetePtr paquete);

//Operación: Asignar Id.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo id.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// id: entero que representa el nuevo id.
//Devuelve nada
void setID(PaquetePtr paquete,int ID);
//Operación: Asignar ancho.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo ancho.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// ancho: entero que representa el nuevo ancho.
//Devuelve nada
void setAncho(PaquetePtr paquete,int ancho);
//Operación: Asignar alto.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo alto.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// alto: entero que representa el nuevo alto.
//Devuelve nada
void setAlto(PaquetePtr paquete,int alto);
//Operación: Asignar largo.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo largo.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// largo: entero que representa el nuevo largo.
//Devuelve nada
void setLargo(PaquetePtr paquete,int largo);
//Operación: Asignar peso.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo peso.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// peso: entero que representa el nuevo peso.
//Devuelve nada
void setPeso(PaquetePtr paquete,int peso);
//Operación: Asignar la direccion de retiro.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene una nueva direccion de retiro.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// dirRetiro: puntero a la estructura que representa la nueva direccion de retiro.
//Devuelve nada
void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro);
//Operación: Asignar la direccion de entrega.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene una nueva direccion de entrega.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// dirEntrega: puntero a la estructura que representa la nueva direccion de entrega.
//Devuelve nada
void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega);
//Operación: Asignar la fecha de entrega.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene una nueva fecha de entrega.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// fechaEntrega: puntero a la estructura que representa la nueva fecha de entrega.
//Devuelve nada
void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega);

//Operación: Asignar el cliente destinatario.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene una nuevo cliente de entrega.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// fechaEntrega: puntero a la estructura que representa el nueva cliente de entrega.
//Devuelve nada
void setCliente(PaquetePtr paquete, PersonaPtr cliente);

//Operación: Asignar estado.
//Precondición: Paquete debe estar creado.
//Postcondición: Paquete tiene un nuevo estado.
//Parámetros:
// paquete: puntero a la estructura a asignar el  nuevo dato.
// entero: entero que representa el nuevo estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve nada
void setEstado(PaquetePtr paquete,int estado);

//Operación: Muestra el paquete.
//Precondición: Paquete debe estar creado.
//Postcondición: Imprime lista de paquetes.
//Parámetros:
// paquete: puntero a la estructura a imprimir.
//Devuelve nada
void mostrarPaquete(PaquetePtr paquete);
//Operación: Muestra los estados que puede tener un paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Precondición: no tiene.
//Postcondición: Se imprimiran los tipos de estados.
//Parámetros: niguno
//Devuelve nada
void helpEstadoPaquete(); //muestra que relacion hay entre cada numero y cada estado posible del paquete.
//Operación: muestra el estado del paquete.
//Precondición: Paquete debe estar creado.
//Postcondición: imprime el estado
//Parámetros:
// paquete: puntero a la estructura a imprimir.
//Devuelve nada
void mostrarEstadopaquete(PaquetePtr paquete); //muestra solo el estado actual del paquete recibido.

//Operación: verifica si dos paquetes son iguales.
//Precondición: Ambos paquetes deben haber sido creados.
//Postcondición: chequea si cada campo de las estructuras son idénticos
//Parámetros:
//  paquete1: puntero a la estructura a verificar.
//  paquete2: puntero a la estructura a verificar.
//Devuelve: true si son idénticos en ID O en el resto de campos, false de lo contrario.
bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2);

#endif // TDAPAQUETES_H_INCLUDED
