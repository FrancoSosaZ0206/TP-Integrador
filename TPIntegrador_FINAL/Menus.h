#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**************************************************************************************************************************

                                                MENUS - INTERFAZ DE OPERACIONES

***************************************************************************************************************************/


///                             FUNCIONES DE CARGA, VALIDACIÓN Y ACTUALIZACIÓN DE SUBESTRUCTURAS


//OPERACION: carga de cuil con datos
//PRECONDICIÓN: cuil debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos válidos
//PARÁMETROS:
// puntero a la estructura cuil que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el cuil con su constructora, causará memory leaks.
void cargarCuil(CuilPtr cuil);
//OPERACION: carga de domicilio con datos
//PRECONDICIÓN: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PARÁMETROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causará memory leaks.
void cargarDomicilio(DomicilioPtr domicilio);
//OPERACION: carga de fecha con datos
//PRECONDICIÓN: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos válidos
//PARÁMETROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causará memory leaks.
void cargarFecha(FechaPtr fecha);

//OPERACION: actualiza los datos de un cuil
//PRECONDICIÓN: cuil debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarCuil(CuilPtr cuil);
//OPERACION: actualiza los datos de un domicilio
//PRECONDICIÓN: domicilio debe haberse creado
//POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarDomicilio(DomicilioPtr domicilio);
//OPERACION: actualiza los datos de una fecha
//PRECONDICIÓN: fecha debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarFecha(FechaPtr fecha);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE CARGA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de carga de paquete
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un paquete y se agrega a la lista de paquetes del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de carga de personas
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea una persona y se agrega a la lista de personas del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de carga de vehiculos
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un vehiculo y se agrega a la lista de vehiculos del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuCargarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE BÚSQUEDA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de busqueda de paquetes
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: se pide un ID, se busca si hay algun paquete que lo tenga.
//              De encontrarse, lo muestra por pantalla, y de lo contrario se informa que no se encontró.
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada.
void menuBuscarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de busqueda de personas
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: se pide un CUIL, se busca si hay algun persona que lo tenga.
//              De encontrarse, la muestra por pantalla, y de lo contrario se informa que no se encontró.
//PARÁMETROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//DEVUELVE: Nada.
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de busqueda de vehiculos
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: se pide una patente, se busca si hay algun vehiculo que lo tenga.
//              De encontrarse, lo muestra por pantalla, y de lo contrario se informa que no se encontró.
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada.
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico);

//OPERACION: menu de eliminacion de un paquete de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: Se muestra la lista de paquetes, y el usuario elige el indice del paquete a eliminar.
//               Si el indice es valido, se destruye el paquete, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada

///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE ELIMINACIÓN DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


void menuEliminarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de eliminacion de un persona de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: Se muestra la lista de personas, y el usuario elige el indice de la persona a eliminar.
//               Si el indice es valido, se destruye la persona, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//DEVUELVE: Nada
void menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de eliminacion de un vehiculo de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: Se muestra la lista de vehiculos, y el usuario elige el indice del vehiculo a eliminar.
//               Si el indice es valido, se destruye el vehiculo, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
void menuEliminarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE MODIFICACIÓN DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//FUNCIÓN DE MODIFICACIÓN DE PAQUETE DE CENTRO LOGISTICO
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaPaquetes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICIÓN: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de algún campo
//               de algún paquete solciitado por el usuario, seleccionando mediante un numero
//               Luego, se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PARÁMETROS: CentroLogisticoPtr donde se generara la modificacion del paquete procedente
//DEVUELVE: Nada.
void menuModificarPaquete(CentroLogisticoPtr centroLogistico);
//FUNCIÓN DE MODIFICACIÓN DE CLIENTE DE CENTRO LOGISTICO
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaClientes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICIÓN: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de algún campo
//               de algún cliente solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PARÁMETROS: CentroLogisticoPtr donde se generara la modificacion del cliente o chofer procedente
//DEVUELVE: Nada.
void menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//FUNCIÓN DE MODIFICACIÓN DE VEHICULO DE CENTRO LOGISTICO
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaVehiculos debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICIÓN: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de algún campo
//               de algún vehiculo solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PARÁMETROS: CentroLogisticoPtr donde se generara la modificacion del vehiculo procedente
//DEVUELVE: Nada.
void menuModificarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE ACCIÓN DEDICADOS A REPARTOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION:
//PRECONDICIÓN:
//POSTCONDICION:
//PARÁMETROS:
//
//DEVUELVE:
void menuArmarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION:
//PRECONDICIÓN:
//POSTCONDICION:
//PARÁMETROS:
//
//DEVUELVE:
void menuBuscarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION:
//PRECONDICIÓN:
//POSTCONDICION:
//PARÁMETROS:
//
//DEVUELVE:
void menuCerrarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION:
//PRECONDICIÓN:
//POSTCONDICION:
//PARÁMETROS:
//
//DEVUELVE:
void menuActualizarReparto(CentroLogisticoPtr centroLogistico);


#endif // MENUS_H_INCLUDED
