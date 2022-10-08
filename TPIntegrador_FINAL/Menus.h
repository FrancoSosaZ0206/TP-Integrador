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
CuilPtr cargarCuil(CuilPtr cuil);
//OPERACION: carga de domicilio con datos
//PRECONDICIÓN: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PARÁMETROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causará memory leaks.
DomicilioPtr cargarDomicilio(DomicilioPtr domicilio);
//OPERACION: carga de fecha con datos
//PRECONDICIÓN: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos válidos
//PARÁMETROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causará memory leaks.
FechaPtr cargarFecha(FechaPtr fecha);

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

PersonaPtr menuCargarCliente(CentroLogisticoPtr centroLogistico);

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


//OPERACION: Crear un reparto en la lista
//PRECONDICIÓN: centroLogistico debe haber sido creado previamente con crearCentroLogistico
//POSTCONDICION: crea una unidade de repartoPtr en la cual se seleccionaran los elementos
//acumulados de los archivos de choferes, paquetes, y vehiculos para poner en marcha
//el reparto, todos los elementos seran seleccionados por el usuario
//PARÁMETROS:
//          puntero a la estructura centro logistico
//DEVUELVE: vacio
void menuArmarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: Busqueda de un reparto en la lista
//PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//POSTCONDICION: buscara dentro de los repartos abiertos o cerrados un reparto en particular
//este sera solicitado de manera numerica por el usuario, buscando dentro de la lista de repartos
//abiertos de centro logistico
//PARÁMETROS: puntero a centro logistico
//variable logica que determina a que lista de repartos se iniciara la busqueda
//DEVUELVE: vacio
void menuBuscarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);
//OPERACION: eliminacion de reparto
//PRECONDICIÓN: centroLogistico debe haber sido creado previamente con crearCentroLogistico
//POSTCONDICION: eliminara un reparto seleccionado mediante el indice por el usuario,
//mostrandolos por pantalla, el cual removera el reparto en esa posicion de los existentes
//PARÁMETROS: puntero a centro logistico
//variable logica que determina a que lista de repartos se iniciara la busqueda
//DEVUELVE: vacio
void menuEliminarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);
//OPERACION: cerrar reparto
//PRECONDICIÓN: centroLogistico debe haber sido creado previamente con crearCentroLogistico
//POSTCONDICION: se solicitara por pantalla la seleccion de un reparto por parte del usuario
//para remover de los repartos abiertos a los cerrados, devolviendo aquellos que no han sido entregados
//PARÁMETROS: puntero a centro logistico
//variable logica que determina a que lista de repartos se iniciara la busqueda
//DEVUELVE: vacio
void menuCerrarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: actualizar reparto
//PRECONDICIÓN: centroLogistico debe haber sido creado previamente con crearCentroLogistico
//POSTCONDICION: se le solicitara al usuario un reparto para modificar su estado
//posteriormente se le solicitara un indice para seleccionar un paquete y
//actualizarle el estado mediante una representacion numerica ingresada por consola
//PARÁMETROS: puntero a centro logistico
//variable logica que determina a que lista de repartos se iniciara la busqueda
//DEVUELVE: vacio
void menuActualizarReparto(CentroLogisticoPtr centroLogistico);

//OPERACION: menú de muestra de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos y cerrados en las categorias de totales, particular, y filtrados por fecha
//PARÁMETROS:
//  centroLogistico: puntero a la estructura centro logistico
//DEVUELVE: nada.
void menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


//OPERACION: menú de muestra de entregas de un solo reparto
//PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos unicamente, se le solicitara al usuario que seleccione un
//               reparto para mostrar sus entregas, y asi poder seleccionar una entrega modificando
//               su valor de estado, 0 deposito, 1 en curso, 2 cancelado, 3 entregado
//PARÁMETROS:
//  centroLogistico: puntero a la estructura centro logistico
// variable logica para saber si son abiertos o cerrados los repartos
//DEVUELVE: nada.
void menuMostrarEntregasReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);



///--------------------------------------------------------------------------------------------------------------------------

///                                             MENÚS DE ACCIÓN DEDICADOS A CENTROLOGISTICO

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menú rápido de creación de centro logistico
//PRECONDICIÓN: el centro logistico debe haber sido DECLARADO previamente y estar vacío.
//POSTCONDICION: se pide un nombre para el nuevo centro logistico, y se crea de forma rápida con listas vacías.
//PARÁMETROS:
//  ctroLog: puntero a la estructura centro logístico que se desea crear
//DEVUELVE: puntero al centro logístico creado.
CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog);



#endif // MENUS_H_INCLUDED
