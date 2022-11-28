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

                                            INTERFAZ DEL TDA CENTRO LOGÍSTICO

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

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

/** OPERACIÓN: Crea la estructura Centro Logistico
PRECONDICIÓN: Que el centro logistico no haya sido creado
POSTCONDICIÓN: Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
PARÁMETROS:
    - nombre: string representando al nombre.
    - listaPaquete: puntero a lista representando la lista de paquetes.
    - listaPersonas: puntero a lista representando la lista de personas.
    - listaVehiculos: puntero a lista representando la lista de vehiculos.
    - listaRepartos: puntero a lista representando la lista de repartos.
DEVUELVE: un puntero de la estructura creada. */
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados);

/** OPERACIÓN: Crea la estructura Centro Logistico de forma aleatoria
PRECONDICIÓN: Que el centro logistico no haya sido creado
POSTCONDICIÓN: Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
PARÁMETROS:
    - nombre del centro logístico
DEVUELVE: un puntero de la estructura creada. */
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre); ///Crea un centro logístico con un nombre y listas vacías.
/** OPERACIÓN: Destruye la estructura de centro logistico.
PRECONDICIÓN: Que la estructura de centro logistico haya sido creada.
POSTCONDICIÓN: Se destruye el centro logistico y se libera la memoria utilizada.
PARÁMETROS:
    - centroLogistico: puntero a estructura representando el centro logistico.
DEVUELVE: NULL. */
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico);

//---------------------------------------getters----------------------------------------------

/** OPERACIÓN: Obtencion del nombre del centro logistico.
PRECONDICIÓN: Que centro logistico haya sido creado.
POSTCONDICIÓN: Se obtiene el nombre de centro logistico.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un string representando el nombre del centro logístico. */
char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Obtencion de la estructura de lista de paquetes
PRECONDICIÓN: Que centro logistico haya sido creado.
POSTCONDICIÓN: Se obtiene la lista de paquetes.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Obtencion de la estructura de lista de personas.
PRECONDICIÓN: Que centro logistico haya sido creado.
POSTCONDICIÓN: Se obtiene la lista de personas.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Obtencion de la estructura de lista de vehiculos.
PRECONDICIÓN: Que centro logistico haya sido creado.
POSTCONDICIÓN: Se obtiene la lista de vehiculos.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: un puntero de la estructura lista. */
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Obtencion de listas de repartos.
PRECONDICIÓN: Que centro logistico haya sido creado.
POSTCONDICIÓN: Se obtiene la lista de repartos
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere obtener un reparto abierto,
            false = si se quiere obtener un reparto cerrado.
DEVUELVE: puntero a la lista de repartos indicada por esRepartoAbierto. */
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

//---------------------------------------setters----------------------------------------------

/** OPERACIÓN: Asigna el nombre
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: nombre cambia con el nuevo valor de nombre.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - nombre: string representando al nuevo valor de nombre.
DEVUELVE: nada. */
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);

/** OPERACIÓN: Asigna la estructura de paquetes.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: paquetes cambia con el nuevo valor de paquetes.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
DEVUELVE: nada. */
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);

/** OPERACIÓN: Asigna la estructura de personas.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: personas cambia con el nuevo valor de personas.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPersonas: puntero a estructura que representa al nuevo valor de personas.
DEVUELVE: nada. */
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);

/** OPERACIÓN: Asigna la estructura de vehiculos.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: vehiculos cambia con el nuevo valor de vehiculos.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
DEVUELVE: nada. */
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);

/** OPERACIÓN: Asigna la estructura de repartos.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: la lista de repartos seleccionada cambia con el nuevo valor de repartos.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere asignar un reparto abierto,
            false = si se quiere asignar un reparto cerrado.
    - repartos: puntero a estructura que representa al nuevo valor de repartos.
DEVUELVE: nada. */
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto);

//---------------------------------------Funciones de muestra y filtrado----------------------------------------------

/** OPERACIÓN: Muestra los paquetes.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un paquete
POSTCONDICIÓN: Imprime la lista de paquetes.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Muestra una las personas del centro logistico
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, una persona
POSTCONDICIÓN: Imprime la lista de personas filtrada bajo una serie de parámetros a elegir por el usuario.
                    1 = Filtramos por Chofer
                    2 = Filtramos por Cliente
                    3 = SIN FILTRO - Se muestran todas las personas
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - modo: entero representando el modo en que se quiere mostrar la lista.
DEVUELVE: nada. */
void mostrarPersonas(CentroLogisticoPtr centroLogistico,int modo);

/** OPERACIÓN: Muestra los vehiculos.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo
POSTCONDICIÓN: Imprime la lista de vehiculos.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: Muestra los repartos.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un reparto
POSTCONDICIÓN: Imprime la lista de repartos. Si es una lista de repartos cerrados,
               al final se imprime por pantalla un mensaje de advertencia para el usuario
               (ver implementación en TDACentroLogistico.c).
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere mostrar un reparto abierto,
            false = si se quiere mostrar un reparto cerrado.
DEVUELVE: nada. */
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

/** OPERACIÓN: Muestra lista de repartos filtrados por una fecha determinada (de salida o retorno, no importa) (sin horario, solo día juliano).
          De cada reparto de la lista, solo se muestran fecha, vehiculo y chofer
PRECONDICIÓN: La lista debe estar creada.
POSTCONDICIÓN: Se ordena la lista por fecha de salida y se muestra por pantalla los repartos
               del día especificado.
PARÁMETROS:
    - centroLogistico: puntero al Centro Logistico del que se quiere mostrar los repartos.
    - esRepartoAbierto: booleano indicando si la lista es de repartos abiertos (true) o cerrados (false).
    - fecha: puntero a la estructura fecha que se usará para filtrar.
DEVUELVE: nada. */
void filtrarRepartosPorFecha(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,FechaPtr fecha);

/** OPERACIÓN: Muestra los paquetes con el estado que le haya pasado.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: Imprime los paquetes con la condicion que se les haya pasado.
PARÁMETROS:
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

/** OPERACIÓN: muestra paquetes en curso o en depósito
PRECONDICIÓN: centroLogistico debe haberse creado
POSTCONDICIÓN: recorre la lista de paquetes, mostrando solamente los que coincidan con el parámetro enCurso:
                   - Si enCurso == true, se muestran los paquetes en curso - estados 1 (en curso), 2 (retirado) o 3 (demorado)
                   - Si enCurso == false, se muestran los paquetes en depósito - estados 0 (en depósito) o 5 (suspendido)
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - enCurso: booleano indicando si se quiere mostrar paquetes en curso (true) o en depósito (false)
DEVUELVE: Nada. */
void filtrarPaquetesEnCurso(CentroLogisticoPtr centroLogistico, bool enCurso);

/** OPERACIÓN: Muestra los paquetes.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un paquete
POSTCONDICIÓN: Imprime la lista de paquetes, solamente aquellos que tienen estado = 0.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
DEVUELVE: nada. */
void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: indica si hay un chofer en un reparto en un día determinado
PRECONDICIÓN:
POSTCONDICIÓN:
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - chofer: puntero a la estructura chofer a buscar en la lista de repartos
    - fechaSalida: puntero a la fecha de salida especificada
DEVUELVE: booleano indicando si se encontró (true) o no (false). */
bool choferEnReparto(CentroLogisticoPtr centroLogistico, PersonaPtr chofer, FechaPtr fechaSalida);

/** OPERACIÓN: Muestra los choferes disponibles para un día determinado
PRECONDICIÓN: Centro logistico debe haberse creado en memoria dinamica y haber un chofer
POSTCONDICIÓN: Imprime la lista de personas filtrada por chofer, en la cual muestra aquellos
 que no se encuentran en repartos actualmente
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - fechaSalida: puntero a fecha de salida de los repartos a buscar el chofer.
DEVUELVE: nada. */
void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fechaSalida);

//---------------------------------------Funciones de búsqueda----------------------------------------------

/** OPERACIÓN: Muestra los paquetes con el estado que le haya pasado.
PRECONDICIÓN: Centro logistico debe haberse creado y llenado con una lista de paquetes
POSTCONDICIÓN: Si hay coincidencia, imprime el paquete buscado.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - ID: entero que representa el ID del paquete.
DEVUELVE: true si se encontró una coincidencia, false de lo contrario. */
bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);

/** OPERACIÓN: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
PRECONDICIÓN: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
POSTCONDICIÓN: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - cuil: string que representa el cuil de la persona.
    - esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
DEVUELVE: true si se encontró una coincidencia, false de lo contrario. */
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer);

/** OPERACIÓN: Muestra los vehiculos con la patente que le haya pasado.
PRECONDICIÓN: Centro logistico debe haberse creado y llenado con una lista de vehiculos
POSTCONDICIÓN: De encontrarse, imprime el vehiculo buscado.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - patente: char que representa la patente del vehiculo.
DEVUELVE: true si se encontró una coincidencia, false de lo contrario. */
bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);

/** OPERACIÓN: Muestra los vehiculos con la patente que le haya pasado.
PRECONDICIÓN: Centro logistico debe haberse creado y llenado con una lista de vehiculos
POSTCONDICIÓN: De encontrarse, imprime el vehiculo buscado.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: booleano que representa el tipo de reparto a buscar.
    - modo: entero representando el modo de búsqueda:
            1: busca por indice de la lista de repartos.
            2: busca por CUIL del chofer.
            3: busca por patente del vehiculo.
            4: busca por fecha de salida.
            5: busca por fecha de retorno.
            6: busca por ID de alguno de los paquetes del reparto.
DEVUELVE: true si se encontró una coincidencia, false de lo contrario. */
bool buscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo);


//---------------------------------------Funciones de agregado a la lista----------------------------------------------

/** OPERACIÓN: Agrega un nuevo paquete.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El centro logistico va a tener un nuevo paquete.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a estructura que representa al nuevo paquete.
DEVUELVE: nada. */
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);

/** OPERACIÓN: Agrega una nueva persona.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El centro logistico va a tener una nueva persona.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a estructura que representa a la nueva persona.
DEVUELVE: nada. */
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);

/** OPERACIÓN: Agrega un nuevo vehiculo.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El centro logistico va a tener un nuevo vehiculo.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a estructura que representa al nuevo vehiculo.
DEVUELVE: nada. */
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);

/** OPERACIÓN: Agrega un nuevo reparto.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: La lista de repartos correspondiente tendrá un nuevo reparto.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere agregar un reparto abierto,
            false = si se quiere agregar un reparto cerrado.
    - reparto: puntero a estructura que representa al nuevo reparto.
DEVUELVE: nada. */
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto);


///-----------------------------------------Funciones de inserción a la lista--------------------------------------------------

/** OPERACIÓN: Inserta un paquete en la posicion de la lista pasada por referencia.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: Un nuevo paquete se va a agregar a la posicion de la lista.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a estructura que representa al nuevo paquete.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar. */
bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion);

/** OPERACIÓN: Inserta una persona en la posicion de la lista pasada por referencia.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: Una nueva persona se va a agregar a la posicion de la lista.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a estructura que representa a la nueva persona.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar. */
bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion);

/** OPERACIÓN: Inserta un vehiculo en la posicion de la lista pasada por referencia.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: Un nuevo vehiculo se va a agregar a la posicion de la lista.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a estructura que representa al nuevo vehiculo.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar. */
bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion);

/** OPERACIÓN: Inserta un reparto en la posicion de la lista pasada por referencia.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: Un nuevo reparto se va a agregar a la posicion de la lista.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - reparto: puntero a estructura que representa al nuevo reparto.
    - posicion: entero que representa la posicion.
DEVUELVE: true=si pudo agregar o false=si no pudo agregar. */
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion);


///----------------------------------------------Funciones para remover de la lista----------------------------------------------

/** OPERACIÓN: Remueve un paquete en la posicion de la lista.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El paquete de la posicion pasada por referencia se remueve.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero al paquete removido. */
PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion);

/** OPERACIÓN: Remueve una persona en la posicion de la lista.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: La persona de la posicion pasada por referencia se remueve.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero a la persona removida. */
PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion);

/** OPERACIÓN: Remueve un vehiculo en la posicion de la lista.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El vehiculo de la posicion pasada por referencia se remueve.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero al vehiculo removido. */
VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion);

/** OPERACIÓN: Remueve un reparto en la posicion de la lista.
PRECONDICIÓN: Centro logistico debe haberse creado.
POSTCONDICIÓN: El reparto de la posicion pasada por referencia se remueve.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - esRepartoAbierto: valor booleano:
            true = si se quiere remover un reparto abierto,
            false = si se quiere remover un reparto cerrado.
    - posicion: entero que representa la posicion.
DEVUELVE: un puntero al reparto removido. */
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion,bool esRepartoAbierto);

/** OPERACIÓN: cierra un reparto
PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
POSTCONDICIÓN:
      1. Remueve un reparto seleccionado seleccionado por el usuario de la lista de repartos abiertos.
      2. Realiza una copia de los contenidos del reparto y la agrega a la lista de repartos cerrados.
      3. Imprime por pantalla un mensaje informando acerca del estado de
         los paquetes del reparto al momento de cerrar.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - posicion: entero representando la posicion del reparto a cerrar.
DEVUELVE: nada. */
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion);

///---------------------------------------Funciones de verificación------------------------------------------------

/** OPERACIÓN: se verifica si el paquete existe en el Centro Logistico.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un paquete.
POSTCONDICIÓN: se recorre la lista de paquetes del centro, chequeando si en algun momento coinciden
               los campos con los el paquete recibido.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - paquete: puntero a la estructura paquete de la que se desea verificar su existencia.
DEVUELVE: true si el paquete recibido tiene el mismo ID O parámetros que uno de los paquetes, false de lo contrario. */
bool esPaqueteExistente(CentroLogisticoPtr centroLogistico, PaquetePtr paquete);

/** OPERACIÓN: se verifica si la persona existe en el Centro Logistico.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, una persona.
POSTCONDICIÓN: se recorre la lista de personas del centro, chequeando si en algun momento coincide el cuil con la persona recibida.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - persona: puntero a la estructura persona de la que se desea verificar su existencia.
DEVUELVE: true si la persona recibida tiene el mismo cuil que una de las personas, false de lo contrario. */
bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona);

/** OPERACIÓN: se verifica si el vehiculo existe en el Centro Logistico.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo.
POSTCONDICIÓN: se recorre la lista de vehiculos del centro, chequeando si en algun momento coincide el ID
               o el resto de campos con el vehiculo recibido.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - vehiculo: puntero a la estructura vehiculo de la que se desea verificar su existencia.
DEVUELVE: true si el vehiculo recibido tiene el mismo ID O parámetros que uno de los vehiculos, false de lo contrario. */
bool esVehiculoExistente(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculo);

/** OPERACIÓN: verifica si el chofer y fecha de salida de un reparto, son iguales a los de algún reparto previamente ingresado.
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, una persona.
POSTCONDICIÓN: se recorre las listas de repartos del centro,
               chequeando si en algun momento coincide el cuil del chofer Y la fecha de salida con los del reparto recibido.
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - reparto: puntero a la estructura reparto que se desea verificar.
DEVUELVE: true si el reparto recibido tiene el mismo chofer y fecha de salida que uno de los repartos, false de lo contrario. */
bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto);

///---------------------------------------Funciones de ordenamiento------------------------------------------------

/** OPERACIÓN: ordena una lista de paquetes por una serie de parámetros
PRECONDICIÓN:
    - centroLogistico debe haber sido creado previamente
    - Una lista de paquetes debe haber sido creada y cargada con, al menos, 2 paquetes.
POSTCONDICIÓN: reinserta dentro de centro logistico todos los paquetes ordenados segun el parámetro elegido.
PARÁMETROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el parámetro con el que se quiere ordenar la lista:
        1 = Por ID
        2 = Por Fecha de Entrega
        3 = Por Estado (ver TDAPaquetes.h)
DEVUELVE: nada. */
void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo);

/** OPERACIÓN: ordena una lista de personas alfabéticamente.
PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente  y cargado con, al menos, 2 personas.
POSTCONDICIÓN: reinserta dentro de centro logistico todas las personas ordenadas segun su apellido y nombre.
               los modos de ordenamiento son:
                  1. Por nombre.
                  2. Por apellido.
                  3. Por ambos.
PARÁMETROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada. */
void ordenarPersonas(CentroLogisticoPtr centroLogistico,int modo);

/** OPERACIÓN: ordena una lista de vehículos alfabéticamente
PRECONDICIÓN: centroLogistico debe haber sido creado anteriormente y cargado con, al menos, 2 vehículos.
POSTCONDICIÓN: setea dentro de centro logistico todos los vehículos ordenados alfabéticamente.
               los modos de ordenamiento son:
                  1. Por marca.
                  2. Por marca y modelo.
                  3. Por tipo, marca y modelo.
PARÁMETROS:
    - centroLogistico: puntero a la estructura centro logistico
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada. */
void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo);


/** OPERACIÓN: ordena una lista de repartos.
PRECONDICIÓN:
      - centroLogistico debe haber sido creado anteriormente.
      - Se deben haber armado, al menos, 2 repartos del tipo que se quiera ordenar.
POSTCONDICIÓN: reinserta dentro de centro logistico todos los repartos ordenados.
               los modos de ordenamiento son:
                  1. Por fecha de salida.
                  2. Por fecha de retorno.
                  3. Por fecha de salida y retorno.
                  4. Por nombre del chofer.
                  5. Por apellido del chofer.
                  6. Por nombre y apellido del chofer.
PARÁMETROS:
    - centroLogistico: puntero a la estructura centro logistico
    - esRepartoAbierto: booleano que indica si es un reparto abierto (true) o cerrado (false)
    - modo: entero representando el modo de ordenamiento elegido
DEVUELVE: nada. */
void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo);

/** OPERACIÓN: verificación de paquetes disponibles
PRECONDICIÓN:
    - centroLogistico debe haberse creado
    - centroLogistico debe contener una lista de paquetes
POSTCONDICIÓN: revisa si hay paquetes en la lista del centro
               cuyos estados sean 0 (en depósito) o 5 (suspendido)
PARÁMETROS:
    - centroLogistico: puntero al centro logistico a revisar
DEVUELVE: Nada. */
bool hayPaquetesDisponibles(CentroLogisticoPtr centroLogistico);

/** OPERACIÓN: verificación de existencia de personas de cierta clase
PRECONDICIÓN: centroLogistico debe haberse creado
POSTCONDICIÓN: verifica si en el centro existen personas de la clase indicada
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - esChofer: booleano indicando si se quiere ver si hay choferes (true) o clientes (false)
DEVUELVE: booleano indicando si hay personas de dicha clase (true) o no (false). */
bool hayPersonas(CentroLogisticoPtr centroLogistico,bool esChofer);

/** OPERACIÓN: verificación de existencia de un ID
PRECONDICIÓN: centroLogistico debe haberse creado
POSTCONDICIÓN: recorre todas los ID existentes del
               centro, revisando si alguno es igual al recibido
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - ID: entero representando al nuevo ID
DEVUELVE: booleano indicando si existe (true) o no (false). */
bool esIDExistente(CentroLogisticoPtr centroLogistico, int ID);

/** OPERACIÓN: verificación de existencia de un cuil
PRECONDICIÓN: centroLogistico debe haberse creado
POSTCONDICIÓN: recorre todas los cuil existentes del
               centro, revisando si alguno es igual al recibido
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - cuil: puntero al nuevo cuil
DEVUELVE: booleano indicando si existe (true) o no (false). */
bool esCuilExistente(CentroLogisticoPtr centroLogistico, CuilPtr cuil);

/** OPERACIÓN: verificación de existencia de una patente
PRECONDICIÓN: centroLogistico debe haberse creado
POSTCONDICIÓN: recorre todas las patentes existentes del
               centro, revisando si alguna es igual a la recibida
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - patente: string representando la patente a validar.
DEVUELVE: booleano indicando si la patente existe (true) o no (false). */
bool esPatenteExistente(CentroLogisticoPtr centroLogistico, char* patente);

/** OPERACIÓN: verificación de validez de una patente
PRECONDICIÓN: ninguna.
POSTCONDICIÓN: verifica que el formato de la patente sea válido (AA 111 AA)
PARÁMETROS:
    - patente: string representando la patente a validar.
DEVUELVE: booleano indicando si es una patente válida (true) o no (false). */
bool esPatenteValida(char* patente);

/** OPERACIÓN: Muestra los vehiculos disponibles
PRECONDICIÓN: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo
POSTCONDICIÓN: de la lista de vehiculos, solo imprime aquellos que no se encuentren en un reparto
PARÁMETROS:
    - centroLogistico: puntero a estructura que representa al centro logistico.
    - fecha: puntero a la fecha para ver si estan disponibles
DEVUELVE: nada. */
void mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico,FechaPtr fecha);

/** OPERACIÓN: busca si un vehículo está disponible en un día concreto
PRECONDICIÓN:
    - centroLogistico debe haberse creado
    - patente debe ser válida.
    - fecha debe ser válida.
POSTCONDICIÓN: verifica si la patente recibida pertenece a un vehiculo asignado a un reparto
PARÁMETROS:
    - centroLogistico: puntero al centro logistico
    - patente: string representando la patente del vehiculo a buscar
    - fecha: puntero a la fecha para buscar
DEVUELVE: booleano indicando si hay vehículos disponibles (true) o no (false). */
bool esVehiculoDisponible(CentroLogisticoPtr centroLogistico, char* patente,FechaPtr fecha);

/** OPERACIÓN: actualiza la lista de repartos abiertos del centro
PRECONDICIÓN: ctroLog debe haberse creado y contener repartos abiertos
POSTCONDICIÓN: se actualizan los estados de los paquetes asignados
               a los repartos de acuerdo al tiempo actual
            *** También se cierran todos los repartos de los cuales
               se hayan pasado sus fechas de retorno ***
PARÁMETROS:
    - ctroLog: puntero al centro logístico del que actualizar sus repartos
DEVUELVE: nada. */
void actualizarRepartos(CentroLogisticoPtr ctroLog); ///NUEVA


#endif // TDACENTROLOGISTICO_H_INCLUDED
