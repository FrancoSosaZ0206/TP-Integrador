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
    PilaPtr paquetes;
} Reparto;
typedef Reparto * RepartoPtr;


//Operación: Creacion del TDArepartos.
//PRECONDICIÓN: Repartos no debe estar creado.
//POSTCONDICIÓN: Se crea un nuevo reparto.
//PARÁMETROS:
chofer: un puntero de la estructura persona representando al chofer.
vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
//DEVUELVE: un puntero a la nueva estructura.
RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes);

//Operación: Creacion del TDArepartos.
//PRECONDICIÓN: Repartos no debe estar creado.
//POSTCONDICIÓN: Se crea un nuevo reparto.
//PARÁMETROS:
chofer: un puntero de la estructura persona representando al chofer.
vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
//DEVUELVE: un puntero a la nueva estructura.
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,PilaPtr paquetes);
//Operación: Destruccion del TDArepartos.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se se libera la memoria reservada para la fecha de salida, retorno, la pila de paquetes (no los paquetes), y la estructura reparto.
//PARÁMETROS:
reparto: puntero a la estructura a destruir.
//DEVUELVE: NULL
RepartoPtr destruirReparto(RepartoPtr reparto);

//Operación: Obtencion de chofer.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se obtiene al chofer
//PARÁMETROS:
reparto: puntero a la estructura para sacar el dato.
//DEVUELVE: un puntero a la estructura.
PersonaPtr getChofer(RepartoPtr reparto);
//Operación: Obtencion de vehiculo.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se obtiene al vehiculo.
//PARÁMETROS:
reparto: puntero a la estructura para sacar el dato.
//DEVUELVE: un puntero a la estructura.
VehiculoPtr getVehiculo(RepartoPtr reparto);
//Operación: Obtencion de fecha de salida.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se obtiene la fecha de salida.
//PARÁMETROS:
reparto: puntero a la estructura para sacar el dato.
//DEVUELVE: un puntero a la estructura.
FechaPtr getFechaSalida(RepartoPtr reparto);
//Operación: Obtencion de fecha de retorno.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se obtiene la fecha de retorno.
//PARÁMETROS:
reparto: puntero a la estructura para sacar el dato.
//DEVUELVE: un puntero a la estructura.
FechaPtr getFechaRetorno(RepartoPtr reparto);
//Operación: Obtencion de el listado de paquetes del reparto.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: Se obtiene la lista de paquetes.
//PARÁMETROS:
reparto: puntero a la estructura para sacar el dato.
//DEVUELVE: un puntero a la estructura.
PilaPtr getPaquetesReparto(RepartoPtr reparto);

//Operación: Asignacion de chofer.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: El reparto cambia con el nuevo valor de chofer.
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
chofer: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void setChofer(RepartoPtr reparto,PersonaPtr chofer);
//Operación: Asignacion de vehiculo.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: El reparto cambia con el nuevo valor de vehiculo.
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
vehiculo: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo);
//Operación: Asignacion de fecha de salida.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: El reparto cambia con el nuevo valor de fecha de salida.
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
fechaSalida: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida);
//Operación: Asignacion de fecha de retorno.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: El reparto cambia con el nuevo valor de fecha de retorno.
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
fechaRetorno: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno);

//Operación: Asignacion de paquetes.
//PRECONDICIÓN: Repartos debe estar creado.
//POSTCONDICIÓN: El reparto cambia con el nuevo valor de paquetes
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
pila paquetes: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void setPaquetesReparto(RepartoPtr reparto, PilaPtr paquetes);

//Operación: Agrega un nuevo paquete a la pila de paquetes.
//PRECONDICIÓN: La pila debe haberse creado
//POSTCONDICIÓN: La pila tiene un nuevo paquete
//PARÁMETROS:
reparto: puntero a la estructura a asignar el nuevo valor.
paquete: puntero a la estructura del nuevo valor.
//DEVUELVE: nada
void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete);
//Operación: Elimina el ultimo paquete agregado en la pila.(LIFO)
//PRECONDICIÓN: La pila debe haberse creado
//POSTCONDICIÓN: La pila tiene un paquete menos.
//PARÁMETROS:
reparto: puntero a la estructura a eliminar el valor.
//DEVUELVE: un puntero a la estrutura eliminada.
PaquetePtr descargarPaquete(RepartoPtr reparto);
//Operación: calcula la cantidad de paquetes que contiene el reparto.
//PRECONDICIÓN: La pila debe haberse creado.
//POSTCONDICIÓN: Se obtiene la cantidad de paquetes del reparto.
//PARÁMETROS:
reparto: puntero a la estructura a sacar la longitud.
//DEVUELVE: un entero representando la cantidad de paquetes.
int cantidadPaquetes(RepartoPtr reparto);
//Operación: Muestra el reparto.
//PRECONDICIÓN: Reparto debe estar creado.
//POSTCONDICIÓN: Imprime el reparto.
//PARÁMETROS:
reparto: un puntero a la estructura a mostrar.
//DEVUELVE: nada
///     Tip: también muestra los paquetes.
void mostrarReparto(RepartoPtr reparto);
//Operación: Muestra un reparto con todos sus datos, excepto por los paquetes que contiene.
//PRECONDICIÓN: Reparto debe estar creado.
//POSTCONDICIÓN: Imprime el reparto sin los paquetes por pantalla.
//PARÁMETROS:
reparto: un puntero a la estructura a mostrar.
//DEVUELVE: nada
void mostrarRepartoSinPaquetes(RepartoPtr reparto); ///NUEVA

///---------------------------------------Funciones de validación------------------------------------------------

//Operación: se verifica si el paquete recibido ya se había cargado en el reparto recibido.
//PRECONDICIÓN: El reparto debe haberse creado y cargado con, al menos, un paquete.
//POSTCONDICIÓN: se recorre la pila de paquetes del reparto,
              chequeando si el ID del paquete coincide con el de algún paquete del reparto.
//PARÁMETROS:
 reparto: puntero a estructura que representa al reparto.
 paquete: puntero a la estructura paquete que se desea verificar si se cargó.
//DEVUELVE:  true si el paquete recibido ya estaba cargado en el reparto, false de lo contrario.
bool esPaqueteCargado(RepartoPtr reparto, PaquetePtr paquete); ///NUEVA

//Operación: verifica si dos repartos son iguales.
//PRECONDICIÓN: Ambos repartos deben haber sido creados.
//POSTCONDICIÓN: chequea si las estructuras son idénticas en todos sus campos
//PARÁMETROS:
 reparto1: puntero a la estructura a verificar.
 reparto2: puntero a la estructura a verificar.
//DEVUELVE:  true si son idénticos todos sus cambios, false de lo contrario.
bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2); ///NUEVA

/*  Operación: crea una copia de un reparto
PRECONDICIÓN: repartoOriginal debe haber sido armado previamente
POSTCONDICIÓN: duplica los contenidos del reparto en uno nuevo
PARÁMETROS:
    - repartoOriginal: puntero al reparto del que se quiere hacer una copia
DEVUELVE:  puntero a la copia del reparto creada. */
RepartoPtr copiarReparto(RepartoPtr repartoOriginal); ///NUEVA - Orientada para la funcion copiarLista


#endif TDAREPARTOS_H_INCLUDED
