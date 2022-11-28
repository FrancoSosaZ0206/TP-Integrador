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

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                                INTERFAZ DEL TDA REPARTOS

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Reparto
{
    PersonaPtr chofer;
    VehiculoPtr vehiculo;
    FechaPtr fechaSalida;
    FechaPtr fechaRetorno;
    PilaPtr paquetes;
    bool esAbierto;
} Reparto;
typedef Reparto * RepartoPtr;


///CREACION Y DESTRUCCION

/** OPERACI�N: Creacion del TDArepartos.
PRECONDICI�N: Repartos no debe estar creado.
POSTCONDICI�N: Se crea un nuevo reparto.
PAR�METROS:
    - chofer: un puntero de la estructura persona representando al chofer.
    - vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
    - fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
    - fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
    - paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
DEVUELVE: un puntero al nuevo reparto. */
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes);

/** OPERACI�N: Destruccion del TDArepartos.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se se libera la memoria reservada para la fecha de salida, retorno, la pila de paquetes (no los paquetes), y la estructura reparto.
PAR�METROS:
    - reparto: puntero a la estructura a destruir.
DEVUELVE: NULL. */
RepartoPtr destruirReparto(RepartoPtr reparto);



///GETTERS

/** OPERACI�N: Obtenci�n de chofer.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene al chofer
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero al chofer del reparto. */
PersonaPtr getChofer(RepartoPtr reparto);

/** OPERACI�N: Obtenci�n de vehiculo.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene al vehiculo.
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero al vehiculo del reparto. */
VehiculoPtr getVehiculo(RepartoPtr reparto);

/** OPERACI�N: Obtenci�n de fecha de salida.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene la fecha de salida.
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la fecha de salida. */
FechaPtr getFechaSalida(RepartoPtr reparto);

/** OPERACI�N: Obtenci�n de fecha de retorno.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene la fecha de retorno.
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la fecha de retorno. */
FechaPtr getFechaRetorno(RepartoPtr reparto);

/** OPERACI�N: Obtenci�n de la pila de paquetes del reparto.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene la pila de paquetes.
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la pila de paquetes. */
PilaPtr getPaquetesReparto(RepartoPtr reparto);

/** OPERACI�N: Obtenci�n del tipo del reparto (abierto/cerrado).
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: Se obtiene un booleano que representa el tipo del reparto (abierto/cerrado).
PAR�METROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: true si el reparto es abierto, false de lo contrario. */
bool getEsAbierto(RepartoPtr reparto);



///SETTERS

/** OPERACI�N: Asignacion de chofer.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de chofer.
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - chofer: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setChofer(RepartoPtr reparto,PersonaPtr chofer);

/** OPERACI�N: Asignacion de vehiculo.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de vehiculo.
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - vehiculo: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo);

/** OPERACI�N: Asignacion de fecha de salida.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de fecha de salida.
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - fechaSalida: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida);
/** OPERACI�N: Asignacion de fecha de retorno.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de fecha de retorno.
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - fechaRetorno: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno);

/** OPERACI�N: Asignacion de paquetes.
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de paquetes
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - paquetes: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setPaquetesReparto(RepartoPtr reparto, PilaPtr paquetes);

/** OPERACI�N: Asignacion de tipo de reparto (cerrado/abierto).
PRECONDICI�N: Repartos debe estar creado.
POSTCONDICI�N: El reparto cambia con el nuevo valor de paquetes
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - esAbierto: booleano representando el nuevo tipo de reparto.
DEVUELVE: nada. */
void setEsAbierto(RepartoPtr reparto,bool esAbierto);



///ESPECIALES

/** OPERACI�N: Agrega un nuevo paquete a la pila de paquetes.
PRECONDICI�N: La pila debe haberse creado
POSTCONDICI�N: La pila tiene un nuevo paquete
PAR�METROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - paquete: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete);

/** OPERACI�N: Elimina el ultimo paquete agregado en la pila.(LIFO)
PRECONDICI�N: La pila debe haberse creado
POSTCONDICI�N: La pila tiene un paquete menos.
PAR�METROS:
    - reparto: puntero a la estructura a eliminar el valor.
DEVUELVE: un puntero a la estrutura eliminada. */
PaquetePtr descargarPaquete(RepartoPtr reparto);

/** OPERACI�N: calcula la cantidad de paquetes que contiene el reparto.
PRECONDICI�N: La pila debe haberse creado.
POSTCONDICI�N: Se obtiene la cantidad de paquetes del reparto.
PAR�METROS:
    - reparto: puntero a la estructura a sacar la longitud.
DEVUELVE: un entero representando la cantidad de paquetes. */
int cantidadPaquetes(RepartoPtr reparto);

/** OPERACI�N: Muestra el reparto.
PRECONDICI�N: Reparto debe estar creado.
POSTCONDICI�N: Imprime el reparto.
PAR�METROS:
    - reparto: un puntero a la estructura a mostrar.
DEVUELVE: nada. */
///     Tip: tambi�n muestra los paquetes.
void mostrarReparto(RepartoPtr reparto);

/** OPERACI�N: Muestra un reparto con todos sus datos, excepto por los paquetes que contiene.
PRECONDICI�N: Reparto debe estar creado.
POSTCONDICI�N: Imprime el reparto sin los paquetes por pantalla.
PAR�METROS:
    - reparto: un puntero a la estructura a mostrar.
DEVUELVE: nada. */
void mostrarRepartoSinPaquetes(RepartoPtr reparto);

///---------------------------------------Funciones de validaci�n------------------------------------------------

/** OPERACI�N: se verifica si el paquete recibido ya se hab�a cargado en el reparto recibido.
PRECONDICI�N: El reparto debe haberse creado y cargado con, al menos, un paquete.
POSTCONDICI�N: se recorre la pila de paquetes del reparto,
              chequeando si el ID del paquete coincide con el de alg�n paquete del reparto.
PAR�METROS:
    - reparto: puntero a estructura que representa al reparto.
    - paquete: puntero a la estructura paquete que se desea verificar si se carg�.
DEVUELVE: true si el paquete recibido ya estaba cargado en el reparto, false de lo contrario. */
bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete);

/** OPERACI�N: verifica si dos repartos son iguales.
PRECONDICI�N: Ambos repartos deben haber sido creados.
POSTCONDICI�N: chequea si las estructuras son id�nticas en todos sus campos
PAR�METROS:
    - reparto1: puntero a la estructura a verificar.
    - reparto2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticos todos sus cambios, false de lo contrario. */
bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2);

/** OPERACI�N: crea una copia de un reparto
PRECONDICI�N: repartoOriginal debe haber sido armado previamente
POSTCONDICI�N: duplica los contenidos del reparto en uno nuevo
PAR�METROS:
    - repartoOriginal: puntero al reparto del que se quiere hacer una copia
DEVUELVE: puntero a la copia del reparto creada. */
RepartoPtr copiarReparto(RepartoPtr repartoOriginal);

/** OPERACI�N: actualizaci�n de un reparto
PRECONDICI�N: reparto debe haberse armado
POSTCONDICI�N:
    - Se actualiza el estado de los paquetes de acuerdo con
               como se van cumpliendo los plazos de retiro / entrega de los paquetes,
               y los plazos de salida / retorno del propio reparto.
    - Se imprime por pantalla qu� paquetes fueron marcados con qu� estado
      al actualizar (de haberse actualizado).
PAR�METROS:
    - reparto: puntero al reparto a actualizar
    - posicion: entero representando la posicion del reparto en la
                lista de repartos abiertos del centro (meramente para printf)
                (ver TDACentroLogistico)
DEVUELVE: booleano informando si se actualizaron repartos (true) o no (false). */
bool actualizarReparto(RepartoPtr reparto,int posicion); ///NUEVA


#endif // TDAREPARTOS_H_INCLUDED
