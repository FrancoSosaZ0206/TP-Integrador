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

/** OPERACIÓN: Creacion del TDArepartos.
PRECONDICIÓN: Repartos no debe estar creado.
POSTCONDICIÓN: Se crea un nuevo reparto.
PARÁMETROS:
    - chofer: un puntero de la estructura persona representando al chofer.
    - vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
    - fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
    - fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
    - paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
DEVUELVE: un puntero al nuevo reparto. */
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes);

/** OPERACIÓN: Destruccion del TDArepartos.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se se libera la memoria reservada para la fecha de salida, retorno, la pila de paquetes (no los paquetes), y la estructura reparto.
PARÁMETROS:
    - reparto: puntero a la estructura a destruir.
DEVUELVE: NULL. */
RepartoPtr destruirReparto(RepartoPtr reparto);



///GETTERS

/** OPERACIÓN: Obtención de chofer.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene al chofer
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero al chofer del reparto. */
PersonaPtr getChofer(RepartoPtr reparto);

/** OPERACIÓN: Obtención de vehiculo.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene al vehiculo.
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero al vehiculo del reparto. */
VehiculoPtr getVehiculo(RepartoPtr reparto);

/** OPERACIÓN: Obtención de fecha de salida.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene la fecha de salida.
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la fecha de salida. */
FechaPtr getFechaSalida(RepartoPtr reparto);

/** OPERACIÓN: Obtención de fecha de retorno.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene la fecha de retorno.
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la fecha de retorno. */
FechaPtr getFechaRetorno(RepartoPtr reparto);

/** OPERACIÓN: Obtención de la pila de paquetes del reparto.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene la pila de paquetes.
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: un puntero a la pila de paquetes. */
PilaPtr getPaquetesReparto(RepartoPtr reparto);

/** OPERACIÓN: Obtención del tipo del reparto (abierto/cerrado).
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: Se obtiene un booleano que representa el tipo del reparto (abierto/cerrado).
PARÁMETROS:
    - reparto: puntero a la estructura para sacar el dato.
DEVUELVE: true si el reparto es abierto, false de lo contrario. */
bool getEsAbierto(RepartoPtr reparto);



///SETTERS

/** OPERACIÓN: Asignacion de chofer.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de chofer.
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - chofer: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setChofer(RepartoPtr reparto,PersonaPtr chofer);

/** OPERACIÓN: Asignacion de vehiculo.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de vehiculo.
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - vehiculo: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo);

/** OPERACIÓN: Asignacion de fecha de salida.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de fecha de salida.
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - fechaSalida: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida);
/** OPERACIÓN: Asignacion de fecha de retorno.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de fecha de retorno.
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - fechaRetorno: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno);

/** OPERACIÓN: Asignacion de paquetes.
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de paquetes
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - paquetes: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void setPaquetesReparto(RepartoPtr reparto, PilaPtr paquetes);

/** OPERACIÓN: Asignacion de tipo de reparto (cerrado/abierto).
PRECONDICIÓN: Repartos debe estar creado.
POSTCONDICIÓN: El reparto cambia con el nuevo valor de paquetes
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - esAbierto: booleano representando el nuevo tipo de reparto.
DEVUELVE: nada. */
void setEsAbierto(RepartoPtr reparto,bool esAbierto);



///ESPECIALES

/** OPERACIÓN: Agrega un nuevo paquete a la pila de paquetes.
PRECONDICIÓN: La pila debe haberse creado
POSTCONDICIÓN: La pila tiene un nuevo paquete
PARÁMETROS:
    - reparto: puntero a la estructura a asignar el nuevo valor.
    - paquete: puntero a la estructura del nuevo valor.
DEVUELVE: nada. */
void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete);

/** OPERACIÓN: Elimina el ultimo paquete agregado en la pila.(LIFO)
PRECONDICIÓN: La pila debe haberse creado
POSTCONDICIÓN: La pila tiene un paquete menos.
PARÁMETROS:
    - reparto: puntero a la estructura a eliminar el valor.
DEVUELVE: un puntero a la estrutura eliminada. */
PaquetePtr descargarPaquete(RepartoPtr reparto);

/** OPERACIÓN: calcula la cantidad de paquetes que contiene el reparto.
PRECONDICIÓN: La pila debe haberse creado.
POSTCONDICIÓN: Se obtiene la cantidad de paquetes del reparto.
PARÁMETROS:
    - reparto: puntero a la estructura a sacar la longitud.
DEVUELVE: un entero representando la cantidad de paquetes. */
int cantidadPaquetes(RepartoPtr reparto);

/** OPERACIÓN: Muestra el reparto.
PRECONDICIÓN: Reparto debe estar creado.
POSTCONDICIÓN: Imprime el reparto.
PARÁMETROS:
    - reparto: un puntero a la estructura a mostrar.
DEVUELVE: nada. */
///     Tip: también muestra los paquetes.
void mostrarReparto(RepartoPtr reparto);

/** OPERACIÓN: Muestra un reparto con todos sus datos, excepto por los paquetes que contiene.
PRECONDICIÓN: Reparto debe estar creado.
POSTCONDICIÓN: Imprime el reparto sin los paquetes por pantalla.
PARÁMETROS:
    - reparto: un puntero a la estructura a mostrar.
DEVUELVE: nada. */
void mostrarRepartoSinPaquetes(RepartoPtr reparto);

///---------------------------------------Funciones de validación------------------------------------------------

/** OPERACIÓN: se verifica si el paquete recibido ya se había cargado en el reparto recibido.
PRECONDICIÓN: El reparto debe haberse creado y cargado con, al menos, un paquete.
POSTCONDICIÓN: se recorre la pila de paquetes del reparto,
              chequeando si el ID del paquete coincide con el de algún paquete del reparto.
PARÁMETROS:
    - reparto: puntero a estructura que representa al reparto.
    - paquete: puntero a la estructura paquete que se desea verificar si se cargó.
DEVUELVE: true si el paquete recibido ya estaba cargado en el reparto, false de lo contrario. */
bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete);

/** OPERACIÓN: verifica si dos repartos son iguales.
PRECONDICIÓN: Ambos repartos deben haber sido creados.
POSTCONDICIÓN: chequea si las estructuras son idénticas en todos sus campos
PARÁMETROS:
    - reparto1: puntero a la estructura a verificar.
    - reparto2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticos todos sus cambios, false de lo contrario. */
bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2);

/** OPERACIÓN: crea una copia de un reparto
PRECONDICIÓN: repartoOriginal debe haber sido armado previamente
POSTCONDICIÓN: duplica los contenidos del reparto en uno nuevo
PARÁMETROS:
    - repartoOriginal: puntero al reparto del que se quiere hacer una copia
DEVUELVE: puntero a la copia del reparto creada. */
RepartoPtr copiarReparto(RepartoPtr repartoOriginal);

/** OPERACIÓN: actualización de un reparto
PRECONDICIÓN: reparto debe haberse armado
POSTCONDICIÓN:
    - Se actualiza el estado de los paquetes de acuerdo con
               como se van cumpliendo los plazos de retiro / entrega de los paquetes,
               y los plazos de salida / retorno del propio reparto.
    - Se imprime por pantalla qué paquetes fueron marcados con qué estado
      al actualizar (de haberse actualizado).
PARÁMETROS:
    - reparto: puntero al reparto a actualizar
    - posicion: entero representando la posicion del reparto en la
                lista de repartos abiertos del centro (meramente para printf)
                (ver TDACentroLogistico)
DEVUELVE: booleano informando si se actualizaron repartos (true) o no (false). */
bool actualizarReparto(RepartoPtr reparto,int posicion); ///NUEVA


#endif // TDAREPARTOS_H_INCLUDED
