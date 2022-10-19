#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**************************************************************************************************************************

                                                MENUS - INTERFAZ DE OPERACIONES

***************************************************************************************************************************/


///--------------------------------------------------------------------------------------------------------------------------
                                    ///MENÚS DE CARGA DE DATOS///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de carga de paquete
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un paquete y se agrega a la lista de paquetes del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de carga de personas
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea una persona y se agrega a la lista de personas del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de carga de vehiculos
//PRECONDICIÓN: centro logistico debe haberse creado en main.c
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion,
//               se crea un vehiculo y se agrega a la lista de vehiculos del centro logistico
//PARÁMETROS:
//  puntero al centro logistico
//DEVUELVE: Nada
bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                        ///MENÚS DE BÚSQUEDA DE DATOS///
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


///--------------------------------------------------------------------------------------------------------------------------
                                    ///MENÚS DE ELIMINACIÓN DE DATOS///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de eliminacion de un paquete de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de paquetes.
//POSTCONDICION: Se muestra la lista de paquetes, y el usuario elige el indice del paquete a eliminar.
//               Si el indice es valido, se destruye el paquete, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de eliminacion de un persona de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de personas.
//POSTCONDICION: Se muestra la lista de personas, y el usuario elige el indice de la persona a eliminar.
//               Si el indice es valido, se destruye la persona, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico, booleano para determinar si es un chofer o un cliente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//OPERACION: menu de eliminacion de un vehiculo de la lista
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de vehiculos.
//POSTCONDICION: Se muestra la lista de vehiculos, y el usuario elige el indice del vehiculo a eliminar.
//               Si el indice es valido, se destruye el vehiculo, y si no se muestra un mensaje
//               que informa el fracaso de la operacion.
//PARÁMETROS:
//  puntero al centro logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                    ///MENÚS DE MODIFICACIÓN DE DATOS///
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
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarPaquete(CentroLogisticoPtr centroLogistico);
//FUNCIÓN DE MODIFICACIÓN DE CLIENTE DE CENTRO LOGISTICO
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaClientes debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICIÓN: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de algún campo
//               de algún cliente solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PARÁMETROS: CentroLogisticoPtr donde se generara la modificacion del cliente o chofer procedente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer);
//FUNCIÓN DE MODIFICACIÓN DE VEHICULO DE CENTRO LOGISTICO
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - El campo de listaVehiculos debe haber sido creada con la funcion crearLista previamente en memoria dinamica
//POSTCONDICIÓN: Genera una serie de opciones por pantalla que le permite al usuario modificar el valor de algún campo
//               de algún vehiculo solciitado por el usuario, seleccionando mediante un numero
//               Luego se elige el campo que se desea modificar, y posteriormente se asigna el valor ingresado por teclado
//               Hasta que el usuario desee encerrado en un do while
//PARÁMETROS: CentroLogisticoPtr donde se generara la modificacion del vehiculo procedente
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                    ///MENÚS DE MUESTRA DE DATOS///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACIÓN: menú de muestra de paquetes
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de paquetes debe haber sido creada y cargada con, al menos, 2 paquetes.
//POSTCONDICIÓN: Imprime por pantalla la lista de paquetes sin ordenar, u ordenada bajo una serie de parámetros a elegir por el usuario
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true SI SE GUARDÓ UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: menú de muestra de personas
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de personas debe haber sido creada y cargada con, al menos, 2 personas.
//POSTCONDICIÓN: Imprime por pantalla la lista de personas sin ordenar, u ordenada bajo una serie de parámetros a elegir por el usuario
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - tipo: entero que indica si se quiere mostrar un chofer (1), un cliente (2), o todas las personas (3).
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true SI SE GUARDÓ UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo);
//OPERACIÓN: menú de muestra de vehiculos
//PRECONDICIÓN:
//              - CentroLogistico debe haber sido creado previamente con crearCentroLogistico en memoria dinamica
//              - Una lista de vehiculos debe haber sido creada y cargada con, al menos, 2 vehiculos.
//POSTCONDICIÓN: Imprime por pantalla la lista de vehiculos sin ordenar, u ordenada bajo una serie de parámetros a elegir por el usuario
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true SI SE GUARDÓ UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico);

///--------------------------------------------------------------------------------------------------------------------------
                                ///MENÚS DE ACCIÓN DEDICADOS A REPARTOS///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menu de armado de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado y llenado con, al menos:
//                  - Un chofer.
//                  - Un vehiculo.
//                  - Un paquete.
//POSTCONDICION: se arma un reparto con fecha de salida y retorno ingresadas por el usuario, y un chofer, vehiculo
//               y pila de paquetes seleccionados de las respectivas listas del centro logistico.
//               Luego, se determina si los datos del reparto no existen en ningún otro:
//                  1. De ser así, se agrega a la lista de repartos abiertos del centro logístico.
//                  2. De lo contrario, se vuelven a elegir estos ultimos datos.
//               El proceso se repite hasta que se cumpla la condicion 1.
//PARÁMETROS:
//  centroLogistico: puntero a la estructura del Centro Logistico
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuArmarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de cerrado de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se mueve el reparto seleccionado a la lista de repartos cerrados.
//PARÁMETROS:
//      - centroLogistico: puntero a la estructura del Centro Logistico
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuCerrarReparto(CentroLogisticoPtr centroLogistico);
//OPERACION: menu de busqueda de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se muestra el reparto buscado, o se muestra un mensaje de error de lo contrario.
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//DEVUELVE: nada.
void menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//OPERACION: menu de eliminacion de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se destruye el reparto seleccionado.
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//OPERACION: menu de actualizacion de datos de un reparto
//PRECONDICIÓN: centroLogistico debe haber sido creado, y se debe haber armado al menos un reparto.
//POSTCONDICION: se ingresan los nuevos datos del reparto y se aplican los cambios,
///              pasando previamente por el mismo proceso de chequeo que en la funcion menuArmarReparto.
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true si hubo cambios y se guardaron, false de lo contrario.
bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);

//OPERACION: menú de muestra de repartos
//PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente, y se debe haber armado al menos un reparto.
//POSTCONDICION: despliega una serie de opciones de menues y submenues que permiten mostrar por
//               pantalla los repartos abiertos y cerrados en las categorias de totales, particular, y filtrados por fecha
//PARÁMETROS:
//      - centroLogistico: puntero al centro logístico del que se mostrará la lista de paquetes.
//      - esRepartoAbierto: booleano que indica si es una lista repartos abiertos (true) o cerrados (false)
//      - opMenuAnterior: entero representando la variable utilizada para elegir la opcion del menú anterior.
//DEVUELVE: true SI SE GUARDÓ UN CAMBIO en el orden de la lista, false de lo contrario.
bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


///--------------------------------------------------------------------------------------------------------------------------
                            ///MENÚS DE ACCIÓN DEDICADOS A CENTROLOGISTICO///
///--------------------------------------------------------------------------------------------------------------------------


//OPERACION: menú rápido de creación de centro logistico
//PRECONDICIÓN: el centro logistico debe haber sido DECLARADO previamente y estar vacío.
//POSTCONDICION: se pide un nombre para el nuevo centro logistico, y se crea de forma rápida con listas vacías.
//PARÁMETROS:
//  ctroLog: puntero a la estructura centro logístico que se desea crear
//DEVUELVE: puntero al centro logístico creado.
CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog);


void menuActualizarReparto(CentroLogisticoPtr centroLogistico);


//OPERACIÓN: actualiza los datos de una fecha
//PRECONDICIÓN: fecha debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarFecha(FechaPtr fecha);

//OPERACIÓN: actualiza los datos de un domicilio
//PRECONDICIÓN: domicilio debe haberse creado
//POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarDomicilio(DomicilioPtr domicilio);

//OPERACIÓN: actualiza los datos de un cuil
//PRECONDICIÓN: cuil debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarCuil(CuilPtr cuil);

//OPERACIÓN: carga de fecha con datos
//PRECONDICIÓN: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos válidos
//PARÁMETROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causará memory leaks.
FechaPtr cargarFecha(FechaPtr fecha);

//OPERACIÓN: carga de domicilio con datos
//PRECONDICIÓN: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PARÁMETROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causará memory leaks.
DomicilioPtr cargarDomicilio(DomicilioPtr domicilio);


//OPERACIÓN: carga de cuil con datos
//PRECONDICIÓN: cuil debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos válidos
//PARÁMETROS:
// puntero a la estructura cuil que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el cuil con su constructora, causará memory leaks.
CuilPtr cargarCuil(CuilPtr cuil);


//OPERACIÓN: menu para continuar en un menú
//PRECONDICIÓN: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PARÁMETROS: ninguno
//DEVUELVE: booleano representando la opcion elegida:
//              true = SI, DESEA CONTINUAR
//              false = NO, DESEA SALIR
bool menuContinuar();

//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 3 - se toma un rango de índices por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  desde: entero representando la variable donde se cargará el índice mínimo.
//  hasta: entero representando la variable donde se cargará el índice máximo.
//DEVUELVE: nada.
void menuModoAccion3(ListaPtr lista,int* vec);

//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 2 - se toma un conjunto de índices por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  cantIndices: entero representando la variable que se cargará con la cantidad de indices seleccionados
//DEVUELVE: vector de enteros representando la seleccion de índices elegidos.
///ADVERTENCIA: No usar con menus o funciones que modifiquen la longitud de la lista (ej: menuEliminar).
void menuModoAccion2(ListaPtr lista,int cantIndices,int* indices);


//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 1 - se toma un indice por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//DEVUELVE: entero representando el índice elegido.
int menuModoAccion1(ListaPtr lista);


//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PARÁMETROS:
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
