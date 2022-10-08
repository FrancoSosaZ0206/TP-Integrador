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

//Operaci�n: Creacion del TDArepartos.
//Precondici�n: Repartos no debe estar creado.
//Postcondici�n: Se crea un nuevo reparto.
//Par�metros:
// chofer: un puntero de la estructura persona representando al chofer.
// vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
// fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
// fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
// paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
//Devuelve un puntero a la nueva estructura.
RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr listaPaquetes);

///estas 2 primeras llaman a crear y destruir reparto. Son como sin�nimos, pero m�s user-friendly.
//Operaci�n: Creacion del TDArepartos.
//Precondici�n: Repartos no debe estar creado.
//Postcondici�n: Se crea un nuevo reparto.
//Par�metros:
// chofer: un puntero de la estructura persona representando al chofer.
// vehiculo: un puntero a de la estructura vehiculo representando al vehiculo.
// fechaSalida: un puntero a la estructura fecha representando la fecha de salida.
// fechaRetorno: un puntero a la estructura fecha representando la fecha de retorno.
// paquetes: un puntero a la estructura pila que contiene los paquetes del reparto.
//Devuelve un puntero a la nueva estructura.
RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes);
//Operaci�n: Destruccion del TDArepartos.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se elimina el reparto y se libera la memoria.
//Par�metros:
// reparto: puntero a la estructura a liberar.
//Devuelve NULL
RepartoPtr cerrarReparto(RepartoPtr reparto);

//Operaci�n: Obtencion de chofer.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se obtiene al chofer
//Par�metros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
PersonaPtr getChofer(RepartoPtr reparto);
//Operaci�n: Obtencion de vehiculo.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se obtiene al vehiculo.
//Par�metros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
VehiculoPtr getVehiculo(RepartoPtr reparto);
//Operaci�n: Obtencion de fecha de salida.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se obtiene la fecha de salida.
//Par�metros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
FechaPtr getFechaSalida(RepartoPtr reparto);
//Operaci�n: Obtencion de fecha de retorno.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se obtiene la fecha de retorno.
//Par�metros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
FechaPtr getFechaRetorno(RepartoPtr reparto);
//Operaci�n: Obtencion de el listado de paquetes del reparto.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: Se obtiene la lista de paquetes.
//Par�metros:
// reparto: puntero a la estructura para sacar el dato.
//Devuelve un puntero a la estructura.
PilaPtr getPaquetesReparto(RepartoPtr reparto);

//Operaci�n: Asignacion de chofer.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: El reparto cambia con el nuevo valor de chofer.
//Par�metros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// chofer: puntero a la estructura del nuevo valor.
//Devuelve nada
void setChofer(RepartoPtr reparto,PersonaPtr chofer);
//Operaci�n: Asignacion de vehiculo.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: El reparto cambia con el nuevo valor de vehiculo.
//Par�metros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// vehiculo: puntero a la estructura del nuevo valor.
//Devuelve nada
void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo);
//Operaci�n: Asignacion de fecha de salida.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: El reparto cambia con el nuevo valor de fecha de salida.
//Par�metros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// fechaSalida: puntero a la estructura del nuevo valor.
//Devuelve nada
void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida);
//Operaci�n: Asignacion de fecha de retorno.
//Precondici�n: Repartos debe estar creado.
//Postcondici�n: El reparto cambia con el nuevo valor de fecha de retorno.
//Par�metros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// fechaRetorno: puntero a la estructura del nuevo valor.
//Devuelve nada
void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno);

//Operaci�n: Setter
//Precondici�n: La lista debe haberse creado.
//Postcondici�n: Se asigna la lista de paquetes en reparto
//Par�metros:
// reparto: puntero a la estructura a guardar
//paquetes: puntero a la estructura a guardar
//Devuelve vacio
void setListaPaquetesReparto(RepartoPtr repart, ListaPtr paquetes);

//Operaci�n: Agrega un nuevo paquete a la pila de paquetes.
//Precondici�n: La pila debe haberse creado
//Postcondici�n: La pila tiene un nuevo paquete
//Par�metros:
// reparto: puntero a la estructura a asignar el nuevo valor.
// paquete: puntero a la estructura del nuevo valor.
//Devuelve nada
void cargarPaquete(RepartoPtr reparto,PaquetePtr paquete); //agrega un paquete a la pila de paquetes.
//Operaci�n: Elimina el ultimo paquete agregado en la pila.(LIFO)
//Precondici�n: La pila debe haberse creado
//Postcondici�n: La pila tiene un paquete menos.
//Par�metros:
// reparto: puntero a la estructura a eliminar el valor.
//Devuelve un puntero a la estrutura eliminada.
PaquetePtr descargarPaquete(RepartoPtr reparto); //elimina el ultimo paquete agregado de la pila. Devuelve el paquete eliminado.
//Operaci�n: Longitud de pila de repartos.
//Precondici�n: La pila debe haberse creado.
//Postcondici�n: Se obtiene la cantidad de paquetes del reparto.
//Par�metros:
// reparto: puntero a la estructura a sacar la longitud.
//Devuelve un entero representando la cantidad de paquetes.
int cantidadPaquetes(RepartoPtr reparto); //devuelve cantidad de paquetes que contiene el reparto
//Operaci�n: Muestra el reparto.
//Precondici�n: Reparto debe estar creado.
//Postcondici�n: Imprime el reparto.
//Par�metros:
// reparto: un puntero a la estructura a mostrar.
//Devuelve nada
void mostrarReparto(RepartoPtr reparto);

//Operaci�n: Longitud de lista de repartos.
//Precondici�n: La lista debe haberse creado.
//Postcondici�n: Se obtiene la cantidad de paquetes del reparto.
//Par�metros:
// reparto: puntero a la estructura a sacar la longitud.
//Devuelve un entero representando la cantidad de paquetes.
int CantidadEntregas(RepartoPtr reparto);

//Operaci�n: Getter
//Precondici�n: La lista de paquetes debe haberse creado.
//Postcondici�n: Se obtiene la lista de paquetes
//Par�metros:
// reparto: puntero a la estructura a sacar los paquetes.
//Devuelve un puntero a la lista de paquetes
ListaPtr getListaPaquetesReparto(RepartoPtr reparto);

//Operaci�n: mostrado
//Precondici�n: La lista debe haberse creado.
//Postcondici�n: Se muestran todos los paquetes del reparto
//Par�metros:
// reparto: puntero a la estructura a mostrar
//Devuelve vacio
void mostrarPaquetesListaReparto(RepartoPtr reparto);

#endif // TDAREPARTOS_H_INCLUDED
