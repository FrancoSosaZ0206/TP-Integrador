#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**************************************************************************************************************************

                                                MENUS - INTERFAZ DE OPERACIONES

***************************************************************************************************************************/


///--------------------------------------------------------------------------------------------------------------------------
                                    ///MEN�S DE CARGA DE DATOS///
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
                                        ///MEN�S DE B�SQUEDA DE DATOS///
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
                                    ///MEN�S DE ELIMINACI�N DE DATOS///
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
bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de eliminacion de un persona de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: Se muestra la lista de personas, y el usuario elige el indice de la persona a eliminar.
//               Si el indice es valido, se destruye la persona, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de eliminacion de un vehiculo de la lista
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: Se muestra la lista de vehiculos, y el usuario elige el indice del vehiculo a eliminar.
//               Si el indice es valido, se destruye el vehiculo, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PAR�METROS:
//  puntero al centro logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                    ///MEN�S DE MODIFICACI�N DE DATOS///
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
bool menuModificarPaquete(CentroLogisticoPtr centroLogistico);
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
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
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
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                    ///MEN�S DE MUESTRA DE DATOS///
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
bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico);
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
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo);
//OPERACI�N: men� de muestra de vehiculos
//PRECONDICI�N:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de vehiculos debe haber sido creada y cargada con, al menos, 2 vehiculos.
//POSTCONDICI�N: Imprime por pantalla la lista de vehiculos sin ordenar, u ordenada bajo una serie de par�metros a elegir por el usuario
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                ///MEN�S DE ACCI�N DEDICADOS A REPARTOS///
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
bool menuCerrarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de busqueda de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se muestra el reparto buscado, o se muestra un mensaje de error de lo contrario.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//DEVUELVE: nada.
void menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//OPERACION: menu de eliminacion de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se destruye el reparto seleccionado.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//OPERACION: menu de actualizacion de datos de un reparto
//PRECONDICI�N: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se ingresan los nuevos datos del reparto y se aplican los cambios,
///              pasando previamente por el mismo proceso de chequeo que en la funcion menuArmarReparto.
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);

//OPERACION: men� de muestra de repartos
//PRECONDICI�N: centroLogistico debe haber sido creado anteriormente, y se debe haber armado al menos un reparto.
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos y cerrados en las categorias de totales, particular, y filtrados por fecha
//PAR�METROS:
//      - centroLogistico: puntero al centro log�stico del que se mostrar� la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del men� anterior.
//DEVUELVE: true SI SE GUARD� UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


///--------------------------------------------------------------------------------------------------------------------------
                            ///MEN�S DE ACCI�N DEDICADOS A CENTROLOGISTICO///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: men� r�pido de creaci�n de centro logistico
//PRECONDICI�N: el centro logistico debe haber sido DECLARADO previamente y estar vac�o.
//POSTCONDICION: se pide un nombre para el nuevo centro logistico, y se crea de forma r�pida con listas vac�as.
//PAR�METROS:
//  ctroLog: puntero a la estructura centro log�stico que se desea crear
//DEVUELVE: puntero al centro log�stico creado.
CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog);


void menuActualizarReparto(CentroLogisticoPtr centroLogistico);


//OPERACI�N: actualiza los datos de una fecha
//PRECONDICI�N: fecha debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarFecha(FechaPtr fecha);

//OPERACI�N: actualiza los datos de un domicilio
//PRECONDICI�N: domicilio debe haberse creado
//POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarDomicilio(DomicilioPtr domicilio);

//OPERACI�N: actualiza los datos de un cuil
//PRECONDICI�N: cuil debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PAR�METROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarCuil(CuilPtr cuil);

//OPERACI�N: carga de fecha con datos
//PRECONDICI�N: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos v�lidos
//PAR�METROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causar� memory leaks.
FechaPtr cargarFecha(FechaPtr fecha);

//OPERACI�N: carga de domicilio con datos
//PRECONDICI�N: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PAR�METROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causar� memory leaks.
DomicilioPtr cargarDomicilio(DomicilioPtr domicilio);


//OPERACI�N: carga de cuil con datos
//PRECONDICI�N: cuil debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos v�lidos
//PAR�METROS:
// puntero a la estructura cuil que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el cuil con su constructora, causar� memory leaks.
CuilPtr cargarCuil(CuilPtr cuil);


//OPERACI�N: menu para continuar en un men�
//PRECONDICI�N: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PAR�METROS: ninguno
//DEVUELVE: booleano representando la opcion elegida:
//              true = SI, DESEA CONTINUAR
//              false = NO, DESEA SALIR
bool menuContinuar();

//OPERACI�N: menu de modo de accion
//PRECONDICI�N: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 3 - se toma un rango de �ndices por pantalla.
//PAR�METROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  desde: entero representando la variable donde se cargar� el �ndice m�nimo.
//  hasta: entero representando la variable donde se cargar� el �ndice m�ximo.
//DEVUELVE: nada.
void menuModoAccion3(ListaPtr lista,int* vec);

//OPERACI�N: menu de modo de accion
//PRECONDICI�N: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 2 - se toma un conjunto de �ndices por pantalla.
//PAR�METROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  cantIndices: entero representando la variable que se cargar� con la cantidad de indices seleccionados
//DEVUELVE: vector de enteros representando la seleccion de �ndices elegidos.
///ADVERTENCIA: No usar con menus o funciones que modifiquen la longitud de la lista (ej: menuEliminar).
void menuModoAccion2(ListaPtr lista,int cantIndices,int* indices);


//OPERACI�N: menu de modo de accion
//PRECONDICI�N: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 1 - se toma un indice por pantalla.
//PAR�METROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//DEVUELVE: entero representando el �ndice elegido.
int menuModoAccion1(ListaPtr lista);


//OPERACI�N: menu de modo de accion
//PRECONDICI�N: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PAR�METROS:
//  opMenuAnterior: entero representando la opcion del menu anterior
//DEVUELVE: entero representando la opcion elegida.
int menuModoAccion();


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE EL INDICE DE LA LISTA
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///         BOOLEANO
///DEVUELVE: VOID
void menuBuscarPorIndiceReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE EL CUIL DEL CHOFER
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
void menuBuscarRepartoPorCuilChofer(CentroLogisticoPtr centroLogistico);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE LA PATENTE DEL VEHICULO
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
void menuBuscarRepartoPorPatenteVehiculo(CentroLogisticoPtr centroLogistico);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE LA FECHA DE SALIDA
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
void menuBuscarRepartoPorFechaSalida(CentroLogisticoPtr centroLogistico);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE LA FECHA DE RETORNO
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
void menuBuscarRepartoPorFechaRetorno(CentroLogisticoPtr centroLogistico);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA EL REPARTO BUSCADO MEDIANTE EL ID DEL PAQUETE
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
void menuBuscarRepartoPorIDPaquete(CentroLogisticoPtr centroLogistico);



///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: DEVUELVE EL CLIENTE BUSCADO POR INDICE O POR CUIL
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
PersonaPtr menuBusquedaCliente(CentroLogisticoPtr centroLogistico);


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA LAS POSIBLES FORMAS DE BUSQUEDA
/// 1. POR CHOFER, 2. POR VEHICULO, 3. POR FECHA SALIDA, 4. POR FECHA RETORNO, 5. POR PAQUETE
/// 6. POR INDICE
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
int menuTipoMostradoRepartos();


///OPERACION: MENU
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA CON
/// CREAR CENTRO LOGISTICO
///POSTCONDICION: MUESTRA LAS POSIBLES OPCIONES DE BUSQUEDA DE UNA PERSONA
/// 1. POR INDICE, 2. POR CUIL
///PARAMETROS:
///         PUNTERO A CENTRO LOGISTICO
///DEVUELVE: VOID
int menuTipoBusquedaCliente();



///-------------------------------------------------------------------------------------------///
                            ///SECCION DE MENUES DEL MAIN///
///-------------------------------------------------------------------------------------------///


///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA AL USUARIO SI DESEA GUARDAR ANTES DE SALIR
/// A MODO DE EVITAR PERDIDA DE DATOS INVOLUNTARIA
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuGuardadoRespaldo();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE TODAS LAS LISTAS DE CENTRO LOGISTICO
/// DESEA GUARDAR EN LA " NUBE "
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuGuardarCambiosMain();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE TODAS LAS LISTAS DESEA VER POR
/// PANTALLA
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuListados();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA EN CUAL DE LAS FORMAS DESEA VER EL ESTADO
/// DE LAS ENTREGAS [ DEPOSITO, REPARTOS ABIERTOS O CERRADOS ]
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuActualizarRepartoCompleto();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA EN CUAL DE LOS TIPOS DE REPARTO DESEA BUSCAR
/// EN REPARTOS ABIERTOS O CERRADOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuBuscadoReparto();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA EN CUAL DE LOS REPARTOS DESEA MODIFICAR
/// EN REPARTOS ABIERTOS O CERRADOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuModificarRepartoCompleto();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA EN CUAL DE LOS REPARTOS DESEA ELIMINAR
/// EN REPARTOS ABIERTOS O CERRADOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuEliminarRepartoCompleto();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuOperacionesReparto();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA EN CUAL TIPO DE DATO DESEA BUSCAR
/// EN CLIENTES, CHOFERES, VEHICULOS, O PAQUETES
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuBusquedaDatos();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LOS DATOS DESEA MODIFICAR
/// CLIENTES, CHOFERES, PAQUETES, VEHICULOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuModificacionDatos();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LOS DATOS DESEA ELIMINAR
/// CLIENTES, CHOFERES, VEHICULOS, PAQUETES
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuEliminarDatos();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LOS DATOS DESEA AGREGAR A LA LISTA
/// CHOFER, PAQUETE, CLIENTE, VEHICULO
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuCargaDeDatos();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LAS OPERACIONES PRINCIPALES DESEA REALIZAR
/// CARGAR, ELIMINAR, MODIFICAR, BUSCAR DATOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuBaseDeDatos();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LAS OPERACIONES INICIALES DESEA REALIZAR
/// BASE DE DATOS, REPARTOS, RESULTADOS ENTREGA, LISTADOS, GUARDAR CAMBIOS
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuPrincipal(CentroLogisticoPtr centroLogistico);

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// PREGUNTA CUAL DE LAS OPERACIONES DE REGISTRO QUE DESEA REALIZAR
/// REGISTRARSE, O INICIAR SESION
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int menuMainMenu();

///OPERACION: MENU
///PRECONDICION: QUE EL PROGRAMA HAYA SIDO EJECUTADO
///POSTCONDICION: DESPLIEGA VARIAS OPCIONES POR PANTALLA
/// ES LA UNIDAD CENTRAL DE PROCESAMIENTO DE MENUES
/// ES DONDE CONCENTRAREMOS LAS OPERACIONES A REALIZAR
/// POR EL USUARIO
///PARAMETROS: NINGUNO
///DEVUELVE: ENTERO REPRESENTANDO LA OPCION ELEGIDA
int MAIN_MENU(CentroLogisticoPtr centroLogistico);



#endif // MENUS_H_INCLUDED
