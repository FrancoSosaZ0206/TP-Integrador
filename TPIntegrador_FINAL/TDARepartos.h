#ifndef TDAREPARTOS_H_INCLUDED
#define TDAREPARTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDAFechaYHora.h"
#include "TDAPaquetes.h"
#include "Lista.h"
#include "Pila.h"

typedef struct Reparto
{
    PersonaPtr chofer;
    VehiculoPtr vehiculo;
    FechaPtr fechaSalida;
    FechaPtr fechaRetorno;
    ListaPtr paquetes;
} Reparto;
typedef Reparto * RepartoPtr;

RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes);
//Operación: Creacion del TDArepartos.
//Precondición: Repartos no debe estar creado.
//Postcondición: Se crea un nuevo reparto.
//Parámetros:
// chofer: un puntero de la estructura persona representando al chofer.
// vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
// fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
// fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
// paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
//Devuelve un puntero a la nueva estructura.
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes);

//Operación: Destruccion del TDArepartos.
//Precondición: Repartos debe estar creado.
//Postcondición: Se elimina el reparto y se libera la memoria.
//Parámetros:
// reparto: puntero a la estructura a liberar.
//Devuelve NULL
RepartoPtr destruirReparto(RepartoPtr reparto);

//Operación: Obtencion de chofer.
//Precondición: Repartos debe estar creado.
//Postcondición: Se obtiene al chofer
//Parámetros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
PersonaPtr getChofer(RepartoPtr reparto);

//Operación: Obtencion de vehiculo.
//Precondición: Repartos debe estar creado.
//Postcondición: Se obtiene al vehiculo.
//Parámetros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
VehiculoPtr getVehiculo(RepartoPtr reparto);

//Operación: Obtencion de fecha de salida.
//Precondición: Repartos debe estar creado.
//Postcondición: Se obtiene la fecha de salida.
//Parámetros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
FechaPtr getFechaSalida(RepartoPtr reparto);

//Operación: Obtencion de fecha de retorno.
//Precondición: Repartos debe estar creado.
//Postcondición: Se obtiene la fecha de retorno.
//Parámetros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
FechaPtr getFechaRetorno(RepartoPtr reparto);

//Operación: Obtencion de el listado de paquetes del reparto.
//Precondición: Repartos debe estar creado.
//Postcondición: Se obtiene la lista de paquetes.
//Parámetros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
ListaPtr getPaquetesReparto(RepartoPtr reparto);

//Operación: Asignacion de chofer.
//Precondición: Repartos debe estar creado.
//Postcondición: El reparto cambia con el nuevo valor de chofer.
//Parámetros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// chofer: puntero a la estructura del nuevo valor.
//Devuelve nada
void setChofer(RepartoPtr reparto,PersonaPtr chofer);

//Operación: Asignacion de vehiculo.
//Precondición: Repartos debe estar creado.
//Postcondición: El reparto cambia con el nuevo valor de vehiculo.
//Parámetros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// vehiculo: puntero a la estructura del nuevo valor.
//Devuelve nada
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo);
//Operación: Asignacion de fecha de salida.
//Precondición: Repartos debe estar creado.
//Postcondición: El reparto cambia con el nuevo valor de fecha de salida.
//Parámetros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// fechaSalida: puntero a la estructura del nuevo valor.
//Devuelve nada
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida);

//Operación: Asignacion de fecha de retorno.
//Precondición: Repartos debe estar creado.
//Postcondición: El reparto cambia con el nuevo valor de fecha de retorno.
//Parámetros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// fechaRetorno: puntero a la estructura del nuevo valor.
//Devuelve nada
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno);

//Operación: Muestra el reparto.
//Precondición: Reparto debe estar creado.
//Postcondición: Imprime el reparto.
//Parámetros:
// reparto: un puntero a la estructura a mostrar.
//Devuelve nada
///     Tip: también muestra los paquetes.
void mostrarReparto(RepartoPtr reparto);

//Operación: Muestra un reparto con todos sus datos, excepto por los paquetes que contiene.
//Precondición: Reparto debe estar creado.
//Postcondición: Imprime el reparto sin los paquetes por pantalla.
//Parámetros:
// reparto: un puntero a la estructura a mostrar.
//Devuelve nada
void mostrarRepartoSinPaquetes(RepartoPtr reparto);

///---------------------------------------Funciones de validación------------------------------------------------

//Operación: se verifica si el paquete recibido ya se había cargado en el reparto recibido.
//Precondición: El reparto debe haberse creado y cargado con, al menos, un paquete.
//Postcondición: se recorre la pila de paquetes del reparto,
//               chequeando si el ID del paquete coincide con el de algún paquete del reparto.
//Parámetros:
//  reparto: puntero a estructura que representa al reparto.
//  paquete: puntero a la estructura paquete que se desea verificar si se cargó.
//Devuelve: true si el paquete recibido ya estaba cargado en el reparto, false de lo contrario.
bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete);

//Operación: verifica si dos repartos son iguales.
//Precondición: Ambos repartos deben haber sido creados.
//Postcondición: chequea si las estructuras son idénticas en todos sus campos
//Parámetros:
//  reparto1: puntero a la estructura a verificar.
//  reparto2: puntero a la estructura a verificar.
//Devuelve: true si son idénticos todos sus cambios, false de lo contrario.
bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2);

///OPERACION: MOSTRAR
///PRECONDICION: REPARTO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LISTA DE PAQUETES DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LOS PAQUETES DEBEN HABER SIDO CREADOS EN MEMORIA DINAMICA
///POSTCONDICION: MUESTRA TODOS LOS PAQUETES DEL REPARTO ENVIADO
///PARAMETROS:
///  PUNTERO A LA ESTRUCTURA REPARTO CREADA EN MEMORIA DINAMICA
///DEVUELVE: VACIO
void mostrarPaquetesReparto(RepartoPtr reparto);

///OPERACION: VERIFICACION
///PRECONDICION: LISTA DE PAQUETES DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LOS PAQUETES DEBEN HABER SIDO CREADOS EN MEMORIA DINAMICA
///POSTCONDICION: VERIFICA QUE PAQUETES NO FUERON ENTREGADOS, EN TAL CASO
/// LOS ASIGNA CON EL " 0 ", INDICANDO QUE YA HAN SIDO DEVUELTOS AL DEPOSITO
///PARAMETROS:
///  ListaPaquetes: PUNTERO A LA LISTA DE PAQUETES
///DEVUELVE: VACIO
void verificacionPaquetesCurso(ListaPtr ListaPaquetes);


#endif // TDAREPARTOS_H_INCLUDED
