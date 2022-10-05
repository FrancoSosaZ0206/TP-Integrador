#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**************************************************************************************************************************

                                                MENUS - INTERFAZ DE OPERACIONES

***************************************************************************************************************************/


///                             FUNCIONES DE CARGA, VALIDACI�N Y ACTUALIZACI�N DE SUBESTRUCTURAS


//OPERACION: carga de cuil con datos
//PRECONDICI�N: cuil debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos v�lidos
//PAR�METROS:
// puntero a la estructura cuil que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el cuil con su constructora, causar� memory leaks.
void cargarCuil(CuilPtr cuil);
//OPERACION: carga de domicilio con datos
//PRECONDICI�N: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PAR�METROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causar� memory leaks.
void cargarDomicilio(DomicilioPtr domicilio);
//OPERACION: carga de fecha con datos
//PRECONDICI�N: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos v�lidos
//PAR�METROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causar� memory leaks.
void cargarFecha(FechaPtr fecha);

//OPERACION: actualiza los datos de un cuil
//PRECONDICI�N: cuil debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarCuil(CuilPtr cuil);
//OPERACION: actualiza los datos de un domicilio
//PRECONDICI�N: domicilio debe haberse creado
//POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarDomicilio(DomicilioPtr domicilio);
//OPERACION: actualiza los datos de una fecha
//PRECONDICI�N: fecha debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarFecha(FechaPtr fecha);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE CARGA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de carga de paquete
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un paquete y se agrega a la lista de paquetes del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de carga de personas
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea una persona y se agrega a la lista de personas del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de carga de vehiculos
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un vehiculo y se agrega a la lista de vehiculos del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE B�SQUEDA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de busqueda de paquetes
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: se pide un ID, se busca si hay algun paquete que lo tenga.
//              De encontrarse, lo muestra por pantalla, y de lo contrario se informa que no se encontr�.
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada.
void menuBuscarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de busqueda de personas
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: se pide un CUIL, se busca si hay algun persona que lo tenga.
//              De encontrarse, la muestra por pantalla, y de lo contrario se informa que no se encontr�.
//PAR�METROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//DEVUELVE: Nada.
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de busqueda de vehiculos
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: se pide una patente, se busca si hay algun vehiculo que lo tenga.
//              De encontrarse, lo muestra por pantalla, y de lo contrario se informa que no se encontr�.
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada.
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico);

//OPERACION: menu de eliminacion de un paquete de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: Se muestra la lista de paquetes, y el usuario elige el indice del paquete a eliminar.
//               Si el indice es valido, se destruye el paquete, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE ELIMINACI�N DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


void menuEliminarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de eliminacion de un persona de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: Se muestra la lista de personas, y el usuario elige el indice de la persona a eliminar.
//               Si el indice es valido, se destruye la persona, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//DEVUELVE: Nada
void menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de eliminacion de un vehiculo de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: Se muestra la lista de vehiculos, y el usuario elige el indice del vehiculo a eliminar.
//               Si el indice es valido, se destruye el vehiculo, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuEliminarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE MODIFICACI�N DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//FUNCI�N DE MODIFICACI�N DE PAQUETE DE CENTRO LOGISTICO
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaPaquetes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICI�N: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de alg�n campo
//               de alg�n paquete solciitado por el usuario, seleccionando mediante un numero
//               Luego, se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PAR�METROS: CentroLogisticoPtr donde se generara la modificacion del paquete procedente
//DEVUELVE: Nada.
void menuModificarPaquete(CentroLogisticoPtr centroLogistico);
//FUNCI�N DE MODIFICACI�N DE CLIENTE DE CENTRO LOGISTICO
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaClientes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICI�N: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de alg�n campo
//               de alg�n cliente solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PAR�METROS: CentroLogisticoPtr donde se generara la modificacion del cliente o chofer procedente
//DEVUELVE: Nada.
void menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//FUNCI�N DE MODIFICACI�N DE VEHICULO DE CENTRO LOGISTICO
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaVehiculos debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICI�N: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de alg�n campo
//               de alg�n vehiculo solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PAR�METROS: CentroLogisticoPtr donde se generara la modificacion del vehiculo procedente
//DEVUELVE: Nada.
void menuModificarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE ACCI�N DEDICADOS A REPARTOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de armado de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado y llenado con, al menos:
//                  - Un chofer.
//                  - Un vehiculo.
//                  - Un paquete.
//POSTCONDICION: se arma un reparto con fecha de salida y retorno ingresadas por el usuario, y un chofer, vehiculo
//               y pila de paquetes seleccionados de las respectivas listas del centro logistico.
//               Luego, se determina si los datos del reparto no existen en ning�n otro:
//                  1. De ser as�, se agrega a la lista de repartos abiertos del centro log�stico.
//                  2. De lo contrario, se vuelven a elegir estos ultimos datos.
//               El proceso se repite hasta que se cumpla la condicion 1.
//PAR�METROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: nada.
void menuArmarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de busqueda de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se muestra el reparto buscado, o se muestra un mensaje de error de lo contrario.
//PAR�METROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: nada.
void menuBuscarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de eliminacion de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se destruye el reparto seleccionado.
//PAR�METROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: nada.
void menuEliminarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de cerrado de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se mueve el reparto seleccionado a la lista de repartos cerrados.
//PAR�METROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: nada.
void menuCerrarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de actualizacion de datos de un reparto
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se ingresan los nuevos datos del reparto y se aplican los cambios,
///              pasando previamente por el mismo proceso de chequeo que en la funcion menuArmarReparto.
//PAR�METROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: nada.
void menuActualizarReparto(CentroLogisticoPtr centroLogistico);

//OPERACION: men� de muestra de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos y cerrados en las categorias de totales, particular, y filtrados por fecha
//PAR�METROS:
//  centroLogistico: puntero a la estructura centro logistico
//DEVUELVE: nada.
void menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE ACCI�N DEDICADOS A CENTROLOGISTICO

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: men� r�pido de creaci�n de centro logistico
//PRECONDICI�N: el centro logistico debe haber sido DECLARADO previamente y estar vac�o.
//POSTCONDICION: se pide un nombre para el nuevo centro logistico, y se crea de forma r�pida con listas vac�as.
//PAR�METROS:
//  ctroLog: puntero a la estructura centro log�stico que se desea crear
//DEVUELVE: puntero al centro log�stico creado.
CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog);



#endif // MENUS_H_INCLUDED
