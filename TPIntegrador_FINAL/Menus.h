#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**************************************************************************************************************************

                                                MENUS - INTERFAZ DE OPERACIONES

***************************************************************************************************************************/


///--------------------------------------------------------------------------------------------------------------------------

///                                                 MEN�S DE CARGA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de carga de paquete
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un paquete y se agrega a la lista de paquetes del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de carga de personas
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea una persona y se agrega a la lista de personas del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de carga de vehiculos
//PRECONDICI�N: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un vehiculo y se agrega a la lista de vehiculos del centro logistico
//PAR�METROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico);

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


///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE ELIMINACI�N DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de eliminacion de un paquete de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: Se muestra la lista de paquetes, y el usuario elige el indice del paquete a eliminar.
//               Si el indice es valido, se destruye el paquete, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico,int opMenuAnterior);
//OPERACION: menu de eliminacion de un persona de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: Se muestra la lista de personas, y el usuario elige el indice de la persona a eliminar.
//               Si el indice es valido, se destruye la persona, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior);
//OPERACION: menu de eliminacion de un vehiculo de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: Se muestra la lista de vehiculos, y el usuario elige el indice del vehiculo a eliminar.
//               Si el indice es valido, se destruye el vehiculo, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior);

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
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarPaquete(CentroLogisticoPtr centroLogistico,int opMenuAnterior);
//FUNCI�N DE MODIFICACI�N DE CLIENTE DE CENTRO LOGISTICO
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaClientes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICI�N: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de alg�n campo
//               de alg�n cliente solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PAR�METROS: CentroLogisticoPtr donde se generara la modificacion del cliente o chofer procedente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior);
//FUNCI�N DE MODIFICACI�N DE VEHICULO DE CENTRO LOGISTICO
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaVehiculos debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICI�N: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de alg�n campo
//               de alg�n vehiculo solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PAR�METROS: CentroLogisticoPtr donde se generara la modificacion del vehiculo procedente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior);

///--------------------------------------------------------------------------------------------------------------------------

///                                             MEN�S DE MUESTRA DE DATOS

///--------------------------------------------------------------------------------------------------------------------------


//OPERACI�N: men� de muestra de paquetes
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de paquetes debe haber sido creada y cargada con, al menos, 2 paquetes.
//POSTCONDICI�N: Imprime por pantalla la lista de paquetes sin ordenar, u ordenada bajo una serie de par�metros a elegir por el usuario
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico,int opMenuAnterior);
//OPERACI�N: men� de muestra de personas
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de personas debe haber sido creada y cargada con, al menos, 2 personas.
//POSTCONDICI�N: Imprime por pantalla la lista de personas sin ordenar, u ordenada bajo una serie de par�metros a elegir por el usuario
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - tipo: entero que indica si se quiere mostrar un chofer (1), un cliente (2), o todas las personas (3).
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo,int opMenuAnterior);
//OPERACI�N: men� de muestra de vehiculos
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de vehiculos debe haber sido creada y cargada con, al menos, 2 vehiculos.
//POSTCONDICI�N: Imprime por pantalla la lista de vehiculos sin ordenar, u ordenada bajo una serie de par�metros a elegir por el usuario
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico,int opMenuAnterior);

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
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuArmarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de cerrado de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se mueve el reparto seleccionado a la lista de repartos cerrados.
//PAR�METROS:
//      - centroLogistico: puntero a la estructura del Centro Logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuCerrarReparto(CentroLogisticoPtr centroLogistico,int opMenuAnterior);
//OPERACION: menu de busqueda de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se muestra el reparto buscado, o se muestra un mensaje de error de lo contrario.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//DEVUELVE: puntero al reparto buscado.
RepartoPtr menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);

bool menuActualizarReparto(CentroLogisticoPtr centroLogistico); ///NUEVA

//OPERACION: menu de eliminacion de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se destruye el reparto seleccionado.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior);
//OPERACION: menu de actualizacion de datos de un reparto
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se ingresan los nuevos datos del reparto y se aplican los cambios,
///              pasando previamente por el mismo proceso de chequeo que en la funcion menuArmarReparto.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior);

//OPERACION: men� de muestra de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado anteriormente, y se debe haber armado al menos un reparto.
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos y cerrados en las categorias de totales, particular, y filtrados por fecha
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior);


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
