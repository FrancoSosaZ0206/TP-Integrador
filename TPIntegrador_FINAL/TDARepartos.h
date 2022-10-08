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
    ListaPtr listaPaquetes;
} Reparto;
typedef Reparto * RepartoPtr;

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
RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr listaPaquetes);

///estas 2 primeras llaman a crear y destruir reparto. Son como sinónimos, pero más user-friendly.
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
RepartoPtr cerrarReparto(RepartoPtr reparto);

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
PilaPtr getPaquetesReparto(RepartoPtr reparto);

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

//Operación: Setter
//Precondición: La lista debe haberse creado.
//Postcondición: Se asigna la lista de paquetes en reparto
//Parámetros:
// reparto: puntero a la estructura a guardar
//paquetes: puntero a la estructura a guardar
//Devuelve vacio
void setListaPaquetesReparto(RepartoPtr repart, ListaPtr paquetes);

//Operación: Agrega un nuevo paquete a la pila de paquetes.
//Precondición: La pila debe haberse creado
//Postcondición: La pila tiene un nuevo paquete
//Parámetros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// paquete: puntero a la estructura del nuevo valor.
//Devuelve nada
void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete); //agrega un paquete a la pila de paquetes.
//Operación: Elimina el ultimo paquete agregado en la pila.(LIFO)
//Precondición: La pila debe haberse creado
//Postcondición: La pila tiene un paquete menos.
//Parámetros:
// reparto: puntero a la estructura a eliminar el valor.
//Devuelve un puntero a la estrutura eliminada.
PaquetePtr descargarPaquete(RepartoPtr reparto); //elimina el ultimo paquete agregado de la pila. Devuelve el paquete eliminado.
//Operación: Longitud de pila de repartos.
//Precondición: La pila debe haberse creado.
//Postcondición: Se obtiene la cantidad de paquetes del reparto.
//Parámetros:
// reparto: puntero a la estructura a sacar la longitud.
//Devuelve un entero representando la cantidad de paquetes.
int cantidadPaquetes(RepartoPtr reparto); //devuelve cantidad de paquetes que contiene el reparto
//Operación: Muestra el reparto.
//Precondición: Reparto debe estar creado.
//Postcondición: Imprime el reparto.
//Parámetros:
// reparto: un puntero a la estructura a mostrar.
//Devuelve nada
void mostrarReparto(RepartoPtr reparto);

//Operación: Longitud de lista de repartos.
//Precondición: La lista debe haberse creado.
//Postcondición: Se obtiene la cantidad de paquetes del reparto.
//Parámetros:
// reparto: puntero a la estructura a sacar la longitud.
//Devuelve un entero representando la cantidad de paquetes.
int CantidadEntregas(RepartoPtr reparto);

//Operación: Getter
//Precondición: La lista de paquetes debe haberse creado.
//Postcondición: Se obtiene la lista de paquetes
//Parámetros:
// reparto: puntero a la estructura a sacar los paquetes.
//Devuelve un puntero a la lista de paquetes
ListaPtr getListaPaquetesReparto(RepartoPtr reparto);

//Operación: mostrado
//Precondición: La lista debe haberse creado.
//Postcondición: Se muestran todos los paquetes del reparto
//Parámetros:
// reparto: puntero a la estructura a mostrar
//Devuelve vacio
void mostrarPaquetesListaReparto(RepartoPtr reparto);

#endif // TDAREPARTOS_H_INCLUDED
