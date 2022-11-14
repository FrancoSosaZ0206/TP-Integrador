#ifndef TDACENTROLOGISTICO_H_INCLUDED
#define TDACENTROLOGISTICO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDARepartos.h"

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                            INTERFAZ DEL TDA CENTRO LOG�STICO

**************************************************************************************************************************
**************************************************************************************************************************
*** *********************************************************************************************************************/

typedef struct CentroLogistico
{
    char *nombre;
    ListaPtr listaPaquetes;
    ListaPtr listaPersonas;
    ListaPtr listaVehiculos;
    ListaPtr listaRepartosAbiertos; ///Nueva implementacion: Ahora los repartos que se cierran
    ListaPtr listaRepartosCerrados; ///se pasan a esta lista en lugar de ser eliminados.
} CentroLogistico;

typedef CentroLogistico * CentroLogisticoPtr;


//---------------------------------------Funciones de creacion y destruccion----------------------------------------------

/** OPERACI�N: Crea la estructura Centro Logistico
PRECONDICI�N: Que el centro logistico no haya sido creado
POSTCONDICI�N: Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
PAR�METROS:
    - nombre: string representando al nombre.
    - listaPaquete: puntero a lista representando la lista de paquetes.
    - listaPersonas: puntero a lista representando la lista de personas.
    - listaVehiculos: puntero a lista representando la lista de vehiculos.
    - listaRepartos: puntero a lista representando la lista de repartos.
DEVUELVE: un puntero de la estructura creada. */
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados);
/** OPERACI�N: Crea la estructura Centro Logistico de forma aleatoria
PRECONDICI�N: Que el centro logistico no haya sido creado
POSTCONDICI�N: Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
PAR�METROS:
    - nombre del centro log�stico
DEVUELVE: un puntero de la estructura creada.
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre); ///Crea un centro log�stico con un nombre y listas vac�as.
/** OPERACI�N: Destruye la estructura de centro logistico.
PRECONDICI�N: Que la estructura de centro logistico haya sido creada.
POSTCONDICI�N: Se destruye el centro logistico y se libera la memoria utilizada.
PAR�METROS:
    - centroLogistico: puntero a estructura representando el centro logistico.
DEVUELVE: NULL. */
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico);

//---------------------------------------getters----------------------------------------------

/** OPERACI�N: Obtencion del nombre del centro logistico.
PRECONDICI�N: Que centro logistico haya sido creado.
POSTCONDICI�N: Se obtiene el nombre de centro logistico.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un string representando el nombre del centro log�stico. */
char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Obtencion de la estructura de lista de paquetes
PRECONDICI�N: Que centro logistico haya sido creado.
POSTCONDICI�N: Se obtiene la lista de paquetes.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Obtencion de la estructura de lista de personas.
PRECONDICI�N: Que centro logistico haya sido creado.
POSTCONDICI�N: Se obtiene la lista de personas.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Obtencion de la estructura de lista de vehiculos.
PRECONDICI�N: Que centro logistico haya sido creado.
POSTCONDICI�N: Se obtiene la lista de vehiculos.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Obtencion de listas de repartos.
PRECONDICI�N: Que centro logistico haya sido creado.
POSTCONDICI�N: Se obtiene la lista de repartos
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere obtener un reparto abierto,
            false = si se quiere obtener un reparto cerrado.
DEVUELVE: puntero a la lista de repartos indicada por esRepartoAbierto. */
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

//---------------------------------------setters----------------------------------------------

/** OPERACI�N: Asigna el nombre
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: nombre cambia con el nuevo valor de nombre.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - nombre: string representando al nuevo valor de nombre.
DEVUELVE: nada. */
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);
/** OPERACI�N: Asigna la estructura de paquetes.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: paquetes cambia con el nuevo valor de paquetes.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
DEVUELVE: nada. */
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);
/** OPERACI�N: Asigna la estructura de personas.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: personas cambia con el nuevo valor de personas.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPersonas: puntero a estructura que representa al nuevo valor de personas.
DEVUELVE: nada. */
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);
/** OPERACI�N: Asigna la estructura de vehiculos.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: vehiculos cambia con el nuevo valor de vehiculos.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
DEVUELVE: nada. */
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);
/** OPERACI�N: Asigna la estructura de repartos.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: la lista de repartos seleccionada cambia con el nuevo valor de repartos.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere asignar un reparto abierto,
            false = si se quiere asignar un reparto cerrado.
    - repartos: puntero a estructura que representa al nuevo valor de repartos.
DEVUELVE: nada. */
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto);

//---------------------------------------Funciones de muestra y filtrado----------------------------------------------

/** OPERACI�N: Muestra los paquetes.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un paquete
POSTCONDICI�N: Imprime la lista de paquetes.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Muestra una las personas del centro logistico
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, una persona
POSTCONDICI�N: Imprime la lista de personas filtrada bajo una serie de par�metros a elegir por el usuario.
    -                 1 = Filtramos por Chofer
                  2 = Filtramos por Cliente
                 3 = SIN FILTRO - Se muestran todas las personas
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - modo: entero representando el modo en que se quiere mostrar la lista.
DEVUELVE: nada. */
void mostrarPersonas(CentroLogisticoPtr centroLogistico,int modo);

/** OPERACI�N: Muestra los vehiculos.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo
POSTCONDICI�N: Imprime la lista de vehiculos.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
/** OPERACI�N: Muestra los repartos.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un reparto
POSTCONDICI�N: Imprime la lista de repartos. Si es una lista de repartos cerrados,
               al final se imprime por pantalla un mensaje de advertencia para el usuario
               (ver implementaci�n en TDACentroLogistico.c).
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere mostrar un reparto abierto,
            false = si se quiere mostrar un reparto cerrado.
DEVUELVE: nada. */
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

/** OPERACI�N: Muestra lista de repartos filtrados por una fecha determinada (de salida o retorno, no importa) (sin horario, solo d�a juliano).
          De cada reparto de la lista, solo se muestran fecha, vehiculo y chofer
PRECONDICI�N: La lista debe estar creada.
POSTCONDICI�N: Se ordena la lista por fecha de salida y se muestra por pantalla los repartos
               del d�a especificado.
PAR�METROS:
    - centroLogistico: puntero al Centro Logistico del que se quiere mostrar los repartos.
    - esRepartoAbierto: booleano indicando si la lista es de repartos abiertos (true) o cerrados (false).
    - fecha: puntero a la estructura fecha que se usar� para filtrar.
DEVUELVE: nada. */
void filtrarRepartosPorFecha(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,FechaPtr fecha);

/** OPERACI�N: Muestra los paquetes con el estado que le haya pasado.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: Imprime los paquetes con la condicion que se les haya pasado.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - estado: entero que representa el estado del paquete. Valores:
              0 = en deposito
              1 = en curso
              2 = retirado
              3 = entregado
              4 = demorado
              5 = suspendido
DEVUELVE: nada. */
void filtrarPaquetesPorEstado(CentroLogisticoPtr centroLogistico,int estado); //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().

/** OPERACI�N: MOSTRADO
PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: MUESTRA LOS PAQUETES SEGUN SI ESTAN EN CURSO = ESTADO (1,2,4)
               O SI ESTAN FINALIZADOS = ESTADO (3,5)
PAR�METROS:
    - PUNTERO A CENTRO LOGISTICO
    - BOOLEANO SI SON EN CURSO O SI ESTAN FINALIZADOS
DEVUELVE: Nada. */
void filtrarPaquetesEnCurso(CentroLogisticoPtr centroLogistico, bool enCurso);

/** OPERACI�N: Muestra los paquetes.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un paquete
POSTCONDICI�N: Imprime la lista de paquetes, solamente aquellos que tienen estado = 0.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico);

/** OPERACI�N: indica si hay un chofer en un reparto en un d�a determinado
PRECONDICI�N:
POSTCONDICI�N:
PAR�METROS:
    - centroLogistico: puntero al centro logistico
    - chofer: puntero a la estructura chofer a buscar en la lista de repartos
    - fechaSalida: puntero a la fecha de salida especificada
DEVUELVE: booleano indicando si se encontr� (true) o no (false). */
bool choferEnReparto(CentroLogisticoPtr centroLogistico, PersonaPtr chofer, FechaPtr fechaSalida);

/** OPERACI�N: Muestra los choferes disponibles para un d�a determinado
PRECONDICI�N: Centro logistico debe haberse creado en memoria dinamica y haber un chofer
POSTCONDICI�N: Imprime la lista de personas filtrada por chofer, en la cual muestra aquellos
 que no se encuentran en repartos actualmente
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - fechaSalida: puntero a fecha de salida de los repartos a buscar el chofer.
DEVUELVE: nada. */
void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fechaSalida);

//---------------------------------------Funciones de b�squeda----------------------------------------------

/** OPERACI�N: Muestra los paquetes con el estado que le haya pasado.
PRECONDICI�N: Centro logistico debe haberse creado y llenado con una lista de paquetes
POSTCONDICI�N: Si hay coincidencia, imprime el paquete buscado.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - ID: entero que representa el ID del paquete.
DEVUELVE: true si se encontr� una coincidencia, false de lo contrario. */
bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);
/** OPERACI�N: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
PRECONDICI�N: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
POSTCONDICI�N: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - cuil: string que representa el cuil de la persona.
    - esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
DEVUELVE: true si se encontr� una coincidencia, false de lo contrario. */
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer);
/** OPERACI�N: Muestra los vehiculos con la patente que le haya pasado.
PRECONDICI�N: Centro logistico debe haberse creado y llenado con una lista de vehiculos
POSTCONDICI�N: De encontrarse, imprime el vehiculo buscado.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - patente: char que representa la patente del vehiculo.
DEVUELVE: true si se encontr� una coincidencia, false de lo contrario. */
bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);

/** OPERACI�N: Muestra los vehiculos con la patente que le haya pasado.
PRECONDICI�N: Centro logistico debe haberse creado y llenado con una lista de vehiculos
POSTCONDICI�N: De encontrarse, imprime el vehiculo buscado.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: booleano que representa el tipo de reparto a buscar.
    - modo: entero representando el modo de b�squeda:
      1: busca por indice de la lista de repartos.
      2: busca por CUIL del chofer.
      3: busca por patente del vehiculo.
      4: busca por fecha de salida.
      5: busca por fecha de retorno.
      6: busca por ID de alguno de los paquetes del reparto.
DEVUELVE: true si se encontr� una coincidencia, false de lo contrario. */
bool buscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo);


//---------------------------------------Funciones de agregado a la lista----------------------------------------------

/** OPERACI�N: Agrega un nuevo paquete.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El centro logistico va a tener un nuevo paquete.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a estructura que representa al nuevo paquete.
DEVUELVE: nada. */
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);
/** OPERACI�N: Agrega una nueva persona.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El centro logistico va a tener una nueva persona.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a estructura que representa a la nueva persona.
DEVUELVE: nada. */
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);
/** OPERACI�N: Agrega un nuevo vehiculo.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El centro logistico va a tener un nuevo vehiculo.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a estructura que representa al nuevo vehiculo.
DEVUELVE: nada. */
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);
/** OPERACI�N: Agrega un nuevo reparto.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: La lista de repartos correspondiente tendr� un nuevo reparto.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere agregar un reparto abierto,
            false = si se quiere agregar un reparto cerrado.
    - reparto: puntero a estructura que representa al nuevo reparto.
DEVUELVE: nada. */
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto);

///-----------------------------------------Funciones de inserci�n a la lista--------------------------------------------------
/** OPERACI�N: Inserta un paquete en la posicion de la lista pasada por referencia.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: Un nuevo paquete se va a agregar a la posicion de la lista.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a estructura que representa al nuevo paquete.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar.
bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion);
/** OPERACI�N: Inserta una persona en la posicion de la lista pasada por referencia.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: Una nueva persona se va a agregar a la posicion de la lista.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a estructura que representa a la nueva persona.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar.
bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion);
/** OPERACI�N: Inserta un vehiculo en la posicion de la lista pasada por referencia.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: Un nuevo vehiculo se va a agregar a la posicion de la lista.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a estructura que representa al nuevo vehiculo.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar.
bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion);
/** OPERACI�N: Inserta un reparto en la posicion de la lista pasada por referencia.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: Un nuevo reparto se va a agregar a la posicion de la lista.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - reparto: puntero a estructura que representa al nuevo reparto.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar.
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion);

///----------------------------------------------Funciones para remover de la lista----------------------------------------------
/** OPERACI�N: Remueve un paquete en la posicion de la lista.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El paquete de la posicion pasada por referencia se remueve.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero a la estructura.
PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion);
/** OPERACI�N: Remueve una persona en la posicion de la lista.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: La persona de la posicion pasada por referencia se remueve.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero a la estructura.
PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion);
/** OPERACI�N: Remueve un vehiculo en la posicion de la lista.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El vehiculo de la posicion pasada por referencia se remueve.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero a la estructura.
VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion);
/** OPERACI�N: Remueve un reparto en la posicion de la lista.
PRECONDICI�N: Centro logistico debe haberse creado.
POSTCONDICI�N: El reparto de la posicion pasada por referencia se remueve.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere remover un reparto abierto,
            false = si se quiere remover un reparto cerrado.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero a la estructura.
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion,bool esRepartoAbierto);

PRECONDICI�N: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
POSTCONDICI�N:
      1. Remueve un reparto seleccionado seleccionado por el usuario de la lista de repartos abiertos.
      2. Realiza una copia de los contenidos del reparto y la agrega a la lista de repartos cerrados.
      3. Imprime por pantalla un mensaje informando acerca del estado de
         los paquetes del reparto al momento de cerrar.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero representando la posicion del reparto a cerrar.
DEVUELVE: nada. */
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion);

///---------------------------------------Funciones de verificaci�n------------------------------------------------

/** OPERACI�N: se verifica si el paquete existe en el Centro Logistico.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un paquete.
POSTCONDICI�N: se recorre la lista de paquetes del centro, chequeando si en algun momento coinciden
               los campos con los el paquete recibido.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a la estructura paquete de la que se desea verificar su existencia.
DEVUELVE: true si el paquete recibido tiene el mismo ID O par�metros que uno de los paquetes, false de lo contrario. */
bool esPaqueteExistente(CentroLogisticoPtr centroLogistico, PaquetePtr paquete);
/** OPERACI�N: se verifica si la persona existe en el Centro Logistico.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, una persona.
POSTCONDICI�N: se recorre la lista de personas del centro, chequeando si en algun momento coincide el cuil con la persona recibida.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a la estructura persona de la que se desea verificar su existencia.
DEVUELVE: true si la persona recibida tiene el mismo cuil que una de las personas, false de lo contrario. */
bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona);
/** OPERACI�N: se verifica si el vehiculo existe en el Centro Logistico.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo.
POSTCONDICI�N: se recorre la lista de vehiculos del centro, chequeando si en algun momento coincide el ID
               o el resto de campos con el vehiculo recibido.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a la estructura vehiculo de la que se desea verificar su existencia.
DEVUELVE: true si el vehiculo recibido tiene el mismo ID O par�metros que uno de los vehiculos, false de lo contrario. */
bool esVehiculoExistente(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculo);
/** OPERACI�N: verifica si el chofer y fecha de salida de un reparto, son iguales a los de alg�n reparto previamente ingresado.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, una persona.
POSTCONDICI�N: se recorre las listas de repartos del centro,
               chequeando si en algun momento coincide el cuil del chofer Y la fecha de salida con los del reparto recibido.
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - reparto: puntero a la estructura reparto que se desea verificar.
DEVUELVE: true si el reparto recibido tiene el mismo chofer y fecha de salida que uno de los repartos, false de lo contrario. */
bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto);

///---------------------------------------Funciones de ordenamiento------------------------------------------------

/** OPERACI�N: ordena una lista de paquetes por una serie de par�metros:
              1 = Por ID
              2 = Por Fecha de Entrega
              3 = Por Estado (como est�n representados por n�meros, se ordenan "de menor a mayor")
PRECONDICI�N:
              - centroLogistico debe haber sido creado previamente
              - Una lista de paquetes debe haber sido creada y cargada con, al menos, 2 paquetes.
POSTCONDICI�N: reinserta dentro de centro logistico todos los paquetes ordenados segun el par�metro elegido.
PAR�METROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el par�metro con el que se quiere ordenar la lista
DEVUELVE: nada
void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo);
/** OPERACI�N: ordena una lista de personas alfab�ticamente.
PRECONDICI�N: centroLogistico debe haber sido creado anteriormente  y cargado con, al menos, 2 personas.
POSTCONDICI�N: reinserta dentro de centro logistico todas las personas ordenadas segun su apellido y nombre.
               los modos de ordenamiento son:
                  1. Por nombre.
                  2. Por apellido.
                  3. Por ambos.
PAR�METROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada
void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modo);
/** OPERACI�N: ordena una lista de veh�culos alfab�ticamente
PRECONDICI�N: centroLogistico debe haber sido creado anteriormente y cargado con, al menos, 2 veh�culos.
POSTCONDICI�N: setea dentro de centro logistico todos los veh�culos ordenados alfab�ticamente.
               los modos de ordenamiento son:
                  1. Por marca.
                  2. Por marca y modelo.
                  3. Por tipo, marca y modelo.
PAR�METROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada
void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo);


/** OPERACI�N: ordena una lista de repartos.
PRECONDICI�N:
      - centroLogistico debe haber sido creado anteriormente.
      - Se deben haber armado, al menos, 2 repartos del tipo que se quiera ordenar.
POSTCONDICI�N: reinserta dentro de centro logistico todos los repartos ordenados.
               los modos de ordenamiento son:
                  1. Por fecha de salida.
                  2. Por fecha de retorno.
                  3. Por fecha de salida y retorno.
                  4. Por nombre del chofer.
                  5. Por apellido del chofer.
                  6. Por nombre y apellido del chofer.
PAR�METROS:
    - centroLogistico: puntero a la estructura centro logistico
    - esRepartoAbierto: booleano que indica si es un reparto abierto (true) o cerrado (false)
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada
void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo);

/** OPERACI�N:
PRECONDICI�N:
POSTCONDICI�N:
PAR�METROS:
    -
DEVUELVE: Nada. */
bool hayPaquetesDisponibles(CentroLogisticoPtr centroLogistico);

/** OPERACI�N: VERIFICACION
/PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: VERIFICA SI EN LA LISTA DE PERSONAS QUE EXISTA UNA PERSONA TIPO CHOFERES
PAR�METROS:
/// PUNTERO A CENTRO LOGISTICO
DEVUELVE BOOLEANO (TRUE = EXISTEN / FALSE = NO EXISTEN)
bool hayPersonas(CentroLogisticoPtr centroLogistico,bool esChofer);

/** OPERACI�N: VERIFICACION
/PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: VERIFICA 1 POR 1 TODOS LOS IDS EXISTENTES, VERIFICANDO
 QUE EL NUEVO GENERADO SEA REALMENTE UNICO
PAR�METROS:
 PUNTERO A CENTRO LOGISTICO
 ENTERO ID DEL PAQUETE NUEVO
DEVUELVE BOOLEANO (TRUE = UNICO / FALSE = NO UNICO)
bool esIDExistente(CentroLogisticoPtr centroLogistico, int ID_Analizar);

/** OPERACI�N: VERIFICACION
/PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: REVISA 1 POR 1 TODOS LOS CUILS EXISTENTES, VERIFICANDO
               QUE EL NUEVO GENERADO SEA REALMENTE UNICO
PAR�METROS:
 PUNTERO A CENTRO LOGISTICO
 PUNTERO A CUIL NUEVO
DEVUELVE BOOLEANO (TRUE = EXISTE / FALSE = NO EXISTE)
bool esCuilExistente(CentroLogisticoPtr centroLogistico, CuilPtr cuil);

/** OPERACI�N: VERIFICACION
/PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: VERIFICA 1 POR 1 TODOS LAS PATENTES EXISTENTES, VERIFICANDO
 QUE EL NUEVO GENERADO SEA REALMENTE UNICO
PAR�METROS:
 PUNTERO A CENTRO LOGISTICO
 PUNTERO A CHAR DE LA PATENTE NUEVA
DEVUELVE BOOLEANO (TRUE = UNICO / FALSE = NO UNICO)
bool esPatenteExistente(CentroLogisticoPtr centroLogistico, char* PatenteComprobar);

/** OPERACI�N: VERIFICACION
/PRECONDICI�N: ninguna.
POSTCONDICI�N: VERIFICA QUE EL FORMATO DE LA PATENTE SEA VALIDO (AA 111 AA)
PAR�METROS:
 PUNTERO A CHAR DE LA PATENTE A VALIDAR
DEVUELVE BOOLEANO (TRUE = VALIDO / FALSE = INVALIDO)
bool esPatenteValida(char* PatenteValidar);

/** OPERACI�N: Muestra los vehiculos.
PRECONDICI�N: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo
POSTCONDICI�N: Imprime la lista de vehiculos, solo aquellos que no se encuentren en un reparto
PAR�METROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - fecha: puntero a la fecha para ver si estan disponibles
DEVUELVE: nada. */
void mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fecha);

/** OPERACI�N: BUSQUEDA
/PRECONDICI�N: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: VERIFICA SI LA PATENTE DEL VEHICULO SE ENCUENTRA DENTRO
 DE LOS VEHICULS ASIGNADOS A REPARTOS
PAR�METROS:
 PUNTERO A CENTRO LOGISTICO
 PUNTERO A CHAR DE LA PATENTE A EVALUAR
    - fecha: puntero a la fecha para buscar
DEVUELVE BOOLEANO (TRUE = NO DISPONIBLES / FALSE = DISPONIBLE)
bool esVehiculoDisponible(CentroLogisticoPtr centroLogistico, char* patente,FechaPtr fecha);


#endif // TDACENTROLOGISTICO_H_INCLUDED
