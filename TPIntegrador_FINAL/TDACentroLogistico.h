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

//Operaci�n:Crea la estructura Centro Logistico
//Precondici�n:Que el centro logistico no haya sido creado
//Postcondici�n:Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
//Par�metros:
// nombre: string representando al nombre.
// listaPaquete: puntero a lista representando la lista de paquetes.
// listaPersonas: puntero a lista representando la lista de personas.
// listaVehiculos: puntero a lista representando la lista de vehiculos.
// listaRepartos: puntero a lista representando la lista de repartos.
//Devuelve un puntero de la estructura creada.
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados);
//Operaci�n:Crea la estructura Centro Logistico de forma aleatoria
//Precondici�n:Que el centro logistico no haya sido creado
//Postcondici�n:Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
//Par�metros:
// nombre del centro log�stico
//Devuelve un puntero de la estructura creada.
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre); ///Crea un centro log�stico con un nombre y listas vac�as.
//Operaci�n: Destruye la estructura de centro logistico.
//Precondici�n: Que la estructura de centro logistico haya sido creada.
//Postcondici�n: Se destruye el centro logistico y se libera la memoria utilizada.
//Par�metros:
// centroLogistico: puntero a estructura representando el centro logistico.
//Devuelve NULL
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico);

//Operaci�n:Obtencion del nombre del centro logistico.
//Precondici�n:Que centro logistico haya sido creado.
//Postcondici�n:Se obtiene el nombre de centro logistico.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un string
char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico);
//Operaci�n:Obtencion de la estructura de lista de paquetes
//Precondici�n:Que centro logistico haya sido creado.
//Postcondici�n:Se obtiene la lista de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Obtencion de la estructura de lista de personas.
//Precondici�n:Que centro logistico haya sido creado.
//Postcondici�n:Se obtiene la lista de personas.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico);
//Operaci�n:Obtencion de la estructura de lista de vehiculos.
//Precondici�n:Que centro logistico haya sido creado.
//Postcondici�n:Se obtiene la lista de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Obtencion de listas de repartos.
//Precondici�n: Que centro logistico haya sido creado.
//Postcondici�n: Se obtiene la lista de repartos
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere obtener un reparto abierto,
//      false = si se quiere obtener un reparto cerrado.
//Devuelve: puntero a la lista de repartos indicada por esRepartoAbierto.
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

//Operaci�n: Asigna el nombre
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: nombre cambia con el nuevo valor de nombre.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// nombre: string representando al nuevo valor de nombre.
//Devuelve: nada.
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);
//Operaci�n: Asigna la estructura de paquetes.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: paquetes cambia con el nuevo valor de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
//Devuelve: nada.
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);
//Operaci�n:Asigna la estructura de personas.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: personas cambia con el nuevo valor de personas.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPersonas: puntero a estructura que representa al nuevo valor de personas.
//Devuelve: nada.
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);
//Operaci�n:Asigna la estructura de vehiculos.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: vehiculos cambia con el nuevo valor de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
//Devuelve: nada.
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);
//Operaci�n: Asigna la estructura de repartos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: la lista de repartos seleccionada cambia con el nuevo valor de repartos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere asignar un reparto abierto,
//      false = si se quiere asignar un reparto cerrado.
// repartos: puntero a estructura que representa al nuevo valor de repartos.
//Devuelve: nada.
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto);

//Operaci�n: Muestra los paquetes.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, un paquete
//Postcondici�n: Imprime la lista de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra una las personas del centro logistico
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, una persona
//Postcondici�n: Imprime la lista de personas filtrada bajo una serie de par�metros a elegir por el usuario.
//                  1 = Filtramos por Chofer
//                  2 = Filtramos por Cliente
///                 3 = SIN FILTRO - Se muestran todas las personas
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  modo: entero representando el modo en que se quiere mostrar la lista.
//Devuelve: nada.
void mostrarPersonas(CentroLogisticoPtr centroLogistico,int modo);

//Operaci�n: Muestra los vehiculos.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo
//Postcondici�n: Imprime la lista de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los repartos.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, un reparto
//Postcondici�n: Imprime la lista de repartos. Si es una lista de repartos cerrados,
//               al final se imprime por pantalla un mensaje de advertencia para el usuario
//               (ver implementaci�n en TDACentroLogistico.c).
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere mostrar un reparto abierto,
//      false = si se quiere mostrar un reparto cerrado.
//Devuelve: nada.
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

//Operacion: Muestra lista de repartos ordenados por fecha de salida.
///          De cada reparto de la lista, solo se muestran fecha, vehiculo y chofer
//Precondicion: La lista debe estar creada.
//Postcondicion: Se ordena la lista por fecha de salida y se muestra por pantalla los repartos
//               del d�a especificado.
//Parametros:
//  centroLogistico: puntero al Centro Logistico del que se quiere mostrar los repartos.
//  esRepartoAbierto: booleano indicando si la lista es de repartos abiertos (true) o cerrados (false).
//  fechaSalida: puntero a la estructura fecha que se usar� para filtrar.
//Devuelve: nada.
void filtrarPorFechaSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,FechaPtr fechaSalida); ///NUEVA
//Operaci�n: Muestra los paquetes con el estado que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime los paquetes con la condicion que se les haya pasado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// estado: entero que representa el estado del paquete. Valores:
//              0 = en deposito
//              1 = en curso
//              2 = retirado
//              3 = entregado
//              4 = demorado
//              5 = suspendido
//Devuelve: nada.
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado); //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().

//Operaci�n: Muestra los paquetes con el estado que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de paquetes
//Postcondici�n: Si hay coincidencia, imprime el paquete buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// ID: entero que representa el ID del paquete.
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);
//Operaci�n: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
//Postcondici�n: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// cuil: string que representa el cuil de la persona.
// esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
bool buscarPersona(CentroLogisticoPtr centroLogistico,char* cuilBuscar,bool esChofer);
//Operaci�n: Muestra los vehiculos con la patente que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de vehiculos
//Postcondici�n: De encontrarse, imprime el vehiculo buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// patente: char que representa la patente del vehiculo.
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);

//---------------------------------------Funciones de agregado a la lista----------------------------------------------
//Operaci�n: Agrega un nuevo paquete.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo paquete.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// paquete: puntero a estructura que representa al nuevo paquete.
//Devuelve: nada.
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);
//Operaci�n: Agrega una nueva persona.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener una nueva persona.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);
//Operaci�n: Agrega un nuevo vehiculo.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo vehiculo.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
//Devuelve: nada.
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);
//Operaci�n: Agrega un nuevo reparto.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La lista de repartos correspondiente tendr� un nuevo reparto.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere agregar un reparto abierto,
//      false = si se quiere agregar un reparto cerrado.
//  reparto: puntero a estructura que representa al nuevo reparto.
//Devuelve: nada.
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto);

///-----------------------------------------Funciones de inserci�n a la lista--------------------------------------------------
//Operaci�n: Inserta un paquete en la posicion de la lista pasada por referencia.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Un nuevo paquete se va a agregar a la posicion de la lista.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// paquete: puntero a estructura que representa al nuevo paquete.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion);
//Operaci�n: Inserta una persona en la posicion de la lista pasada por referencia.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Una nueva persona se va a agregar a la posicion de la lista.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion);
//Operaci�n: Inserta un vehiculo en la posicion de la lista pasada por referencia.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Un nuevo vehiculo se va a agregar a la posicion de la lista.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion);
//Operaci�n: Inserta un reparto en la posicion de la lista pasada por referencia.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Un nuevo reparto se va a agregar a la posicion de la lista.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// reparto: puntero a estructura que representa al nuevo reparto.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion);

///----------------------------------------------Funciones para remover de la lista----------------------------------------------
//Operaci�n: Remueve un paquete en la posicion de la lista.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El paquete de la posicion pasada por referencia se remueve.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion);
//Operaci�n: Remueve una persona en la posicion de la lista.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La persona de la posicion pasada por referencia se remueve.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion);
//Operaci�n: Remueve un vehiculo en la posicion de la lista.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El vehiculo de la posicion pasada por referencia se remueve.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion);
//Operaci�n: Remueve un reparto en la posicion de la lista.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El reparto de la posicion pasada por referencia se remueve.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere remover un reparto abierto,
//      false = si se quiere remover un reparto cerrado.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion,bool esRepartoAbierto);

//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion:
//      1. Remueve un reparto seleccionado seleccionado por el usuario de la lista de repartos abiertos.
//      2. Realiza una copia de los contenidos del reparto y la agrega a la lista de repartos cerrados.
//      3. Imprime por pantalla un mensaje informando acerca del estado de
//         los paquetes del reparto al momento de cerrar.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  posicion: entero representando la posicion del reparto a cerrar.
//Devuelve: nada.
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion);

///---------------------------------------Funciones de verificaci�n------------------------------------------------

//Operaci�n: se verifica si el paquete existe en el Centro Logistico.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, un paquete.
//Postcondici�n: se recorre la lista de paquetes del centro, chequeando si en algun momento coincide el ID
//               o el resto de campos con el paquete recibido.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  paquete: puntero a la estructura paquete de la que se desea verificar su existencia.
//Devuelve: true si el paquete recibido tiene el mismo ID O par�metros que uno de los paquetes, false de lo contrario.
bool esPaqueteExistente(CentroLogisticoPtr centroLogistico, PaquetePtr paquete);
//Operaci�n: se verifica si la persona existe en el Centro Logistico.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, una persona.
//Postcondici�n: se recorre la lista de personas del centro, chequeando si en algun momento coincide el cuil con la persona recibida.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  persona: puntero a la estructura persona de la que se desea verificar su existencia.
//Devuelve: true si la persona recibida tiene el mismo cuil que una de las personas, false de lo contrario.
bool esPersonaExistente(CentroLogisticoPtr centroLogistico, PersonaPtr persona);
//Operaci�n: se verifica si el vehiculo existe en el Centro Logistico.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, un vehiculo.
//Postcondici�n: se recorre la lista de vehiculos del centro, chequeando si en algun momento coincide el ID
//               o el resto de campos con el vehiculo recibido.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  vehiculo: puntero a la estructura vehiculo de la que se desea verificar su existencia.
//Devuelve: true si el vehiculo recibido tiene el mismo ID O par�metros que uno de los vehiculos, false de lo contrario.
bool esVehiculoExistente(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculo);
//Operaci�n: se verifica si el chofer y fecha de salida de un reparto, son iguales a los de alg�n reparto previamente ingresado.
//Precondici�n: Centro logistico debe haberse creado y cargado con, al menos, una persona.
//Postcondici�n: se recorre la lista de repartos del centro,
//               chequeando si en algun momento coincide el cuil del chofer Y la fecha de salida con los del reparto recibido.
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  reparto: puntero a la estructura reparto que se desea verificar.
//  esRepartoAbierto: booleano que indica de que reparto se trata.
//Devuelve: true si el reparto recibido tiene el mismo chofer y fecha de salida que uno de los repartos, false de lo contrario.
bool esRepartoExistente(CentroLogisticoPtr centroLogistico, RepartoPtr reparto,bool esRepartoAbierto);

///---------------------------------------Funciones de ordenamiento------------------------------------------------

//Operaci�n: ordena una lista de paquetes por una serie de par�metros:
//              1 = Por ID
//              2 = Por Fecha de Entrega
//              3 = Por Estado (como est�n representados por n�meros, se ordenan "de menor a mayor")
//PRECONDICI�N:
//              - centroLogistico debe haber sido creado previamente
//              - Una lista de paquetes debe haber sido creada y cargada con, al menos, 2 paquetes.
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el par�metro elegido.
//Parametros:
//  centroLogistico: puntero a la estructura centro logistico
//  modo: entero representando el par�metro con el que se quiere ordenar la lista
//Devuelve: nada
void ordenarPaquetes(CentroLogisticoPtr centroLogistico,int modo);
//Operaci�n: ordena una lista de personas alfab�ticamente.
//Precondicion: centroLogistico debe haber sido creado anteriormente  y cargado con, al menos, 2 personas.
//Postcondicion: reinserta dentro de centro logistico todas las personas ordenadas segun su apellido y nombre.
//               los modos de ordenamiento son:
//                  1. Por nombre.
//                  2. Por apellido.
//                  3. Por ambos.
//Parametros:
//  centroLogistico: puntero a la estructura centro logistico
//  modoOrdenamiento: entero representando el modo de ordenamiento elegido
//  modoMostrado: entero representando el modo de mostrado (clientes, chofer, ambos)
//Devuelve: nada
void ordenarPersonas(CentroLogisticoPtr centroLogistico, int modoOrdenamiento, int modoMostrado);
//Operaci�n: ordena una lista de veh�culos alfab�ticamente
//Precondicion: centroLogistico debe haber sido creado anteriormente y cargado con, al menos, 2 veh�culos.
//Postcondicion: setea dentro de centro logistico todos los veh�culos ordenados alfab�ticamente.
//               los modos de ordenamiento son:
//                  1. Por marca.
//                  2. Por marca y modelo.
//                  3. Por tipo, marca y modelo.
//Parametros:
//  centroLogistico: puntero a la estructura centro logistico
//  modo: entero representando el modo de ordenamiento elegido
//Devuelve: nada
void ordenarVehiculos(CentroLogisticoPtr centroLogistico,int modo);


//Operaci�n: ordena una lista de repartos.
//Precondicion:
//      - centroLogistico debe haber sido creado anteriormente.
//      - Se deben haber armado, al menos, 2 repartos del tipo que se quiera ordenar.
//Postcondicion: reinserta dentro de centro logistico todos los repartos ordenados.
//               los modos de ordenamiento son:
//                  1. Por fecha de salida.
//                  2. Por fecha de retorno.
//                  3. Por fecha de salida y retorno.
//                  4. Por nombre del chofer.
//                  5. Por apellido del chofer.
//                  6. Por nombre y apellido del chofer.
//Parametros:
//  centroLogistico: puntero a la estructura centro logistico
//  esRepartoAbierto: booleano que indica si es un reparto abierto (true) o cerrado (false)
//  modo: entero representando el modo de ordenamiento elegido
//Devuelve: nada
void ordenarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int modo);


///OPERACION: MOSTRAR
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE PERSONAS DEBE CONTENER ALGUN CHOFER PARA PODER MOSTRAR
///POSTCONDICION: MUESTRA POR PANTALLA TODOS LOS CHOFERES QUE NO FUERON
/// ASIGNADOS A UN REPARTO
///PARAMETROS: PUNTERO A LA ESTRUCTURA DINAMICA DE CENTRO LOGISTICO
///DEVUELVE: VACIO
void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico);

///OPERACION: MOSTRAR
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE VEHICULOS DEBE CONTENER ALGUN VEHICULO PARA PODER MOSTRAR
///POSTCONDICION: MUESTRA POR PANTALLA TODOS LOS VEHICULOS QUE NO FUERON
/// ASIGNADOS A UN REPARTO
///PARAMETROS: PUNTERO A LA ESTRUCTURA DINAMICA DE CENTRO LOGISTICO
///DEVUELVE: VACIO
void mostrarVehiculosDisponibles(CentroLogisticoPtr centroLogistico);

///OPERACION: MOSTRAR
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE PAQUETES DEBE CONTENER ALGUN PAQUETE PARA PODER MOSTRAR
///POSTCONDICION: MUESTRA POR PANTALLA TODOS LOS PAQUETES QUE NO HAN SIDO
/// ASIGNADOS A UN REPARTO, SOLO MUESTRA AQUELLOS QUE ESTAN EN DEPOSITO
///PARAMETROS: PUNTERO A LA ESTRUCTURA DINAMICA DE CENTRO LOGISTICO
///DEVUELVE: VACIO
void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico);

///OPERACION: BUSQUEDA
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE VEHICULOS ABIERTOS DEBE CONTENER ALGUN VEHICULO PARA PODER BUSCAR
///POSTCONDICION: DEVUELVE VERDADERO SI ENCONTRO AL CHOFER, FALSO SI NO LO ENCONTRO
/// STRING PUNTERO A LA PATENTE A BUSCAR
///DEVUELVE: BOOLEANO, TRUE = ENCONTRADO, FALSE = NO ENCONTRADO
bool buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente);

///OPERACION: BUSQUEDA
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE REPARTOS ABIERTOS DEBE CONTENER ALGUN REPARTO PARA PODER BUSCAR
///POSTCONDICION: DEVUELVE VERDADERO SI ENCONTRO AL CHOFER, FALSO SI NO LO ENCONTRO
///PARAMETROS:
/// PUNTERO A LA ESTRUCTURA DINAMICA DE CENTRO LOGISTICO
/// STRING PUNTERO AL CUIL A BUSCAR
///DEVUELVE: BOOLEANO, TRUE = ENCONTRADO, FALSE = NO ENCONTRADO
bool buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuilBuscar);

///OPERACION: BUSQUEDA
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE REPARTOS ABIERTOS DEBE CONTENER ALGUN REPARTO PARA PODER BUSCAR
/// LA LISTA DE REPARTOS ABIERTOS DEBE CONTENER ALGUN REPARTO PARA PODER BUSCAR
///POSTCONDICION: DEVUELVE VERDADERO SI ENCONTRO LA FECHA, FALSO SI NO LO ENCONTRO
///PARAMETROS:
/// PUNTERO A LA ESTRUCTURA DINAMICA DE CENTRO LOGISTICO
/// PUNTERO A LA ESTRUCTURA DINAMICA DE FECHA
/// ENTERO REPRESENTANDO EL MODO [1 = FECHA SALIDA, 2 = FECHA RETORNO]
///DEVUELVE: BOOLEANO, TRUE = ENCONTRADO, FALSE = NO ENCONTRADO
bool buscarFechaRepartos(CentroLogisticoPtr centroLogistico, FechaPtr fechaBuscar, int modo);

///OPERACION: BUSQUEDA
///PRECONDICION: CENTRO LOGISTICO DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
/// LA LISTA DE REPARTOS ABIERTOS DEBE CONTENER ALGUN REPARTO PARA PODER BUSCAR
/// LA LISTA DE REPARTOS ABIERTOS DEBE CONTENER ALGUN REPARTO PARA PODER BUSCAR
///POSTCONDICION: DEVUELVE VERDADERO SI ENCONTRO AL PAQUETE, FALSO SI NO LO ENCONTRO
///PARAMETROS:
/// PUNTERO A LA ESTRUCTURA DINAMICA DE REPARTO
/// ENTERO REPRESENTANDO EL IDENTIFICADOR DEL PAQUETE
///DEVUELVE: BOOLEANO, TRUE = ENCONTRADO, FALSE = NO ENCONTRADO
bool buscarPaqueteRepartos(RepartoPtr reparto, int ID);

#endif // TDACENTROLOGISTICO_H_INCLUDED
