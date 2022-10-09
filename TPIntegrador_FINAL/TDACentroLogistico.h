#ifndef TDACENTROLOGISTICO_H_INCLUDED
#define TDACENTROLOGISTICO_H_INCLUDED

#include "TDAPaquetes.h"
#include "TDAVehiculo.h"
#include "TDARepartos.h"

typedef struct CentroLogistico
{
    char *nombre;
    ListaPtr listaPaquetes;
    ListaPtr listaPersonas;
    ListaPtr listaClientes;
    ListaPtr listaChoferes;
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
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaClientes,ListaPtr listaChoferes,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados);
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

ListaPtr getClientes(CentroLogisticoPtr centroLogistico);

ListaPtr getChoferes(CentroLogisticoPtr centroLogistico);

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
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra las personas.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de personas.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarPersonas(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los clientes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de clientes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarClientes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==false.
//Operaci�n: Muestra los choferes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de choferes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarChoferes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==true.

//Operaci�n: Muestra los vehiculos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los repartos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de repartos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere mostrar un reparto abierto,
//      false = si se quiere mostrar un reparto cerrado.
//Devuelve: nada.
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);
//Operaci�n: Muestra los paquetes con el estado que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime los paquetes con la condicion que se les haya pasado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// estado: entero que representa el estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve: nada.
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado); //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().

//Operaci�n: Muestra los paquetes con el estado que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de paquetes
//Postcondici�n: Si hay coincidencia, imprime el paquete buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// ID: entero que representa el ID del paquete.
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
int buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);
//Operaci�n: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
//Postcondici�n: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// cuil: string que representa el cuil de la persona.
// esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
int buscarPersona(CentroLogisticoPtr centroLogistico,char* cuil,bool esChofer);
//Operaci�n: Muestra los vehiculos con la patente que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado y llenado con una lista de vehiculos
//Postcondici�n: De encontrarse, imprime el vehiculo buscado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// patente: char que representa la patente del vehiculo.
//Devuelve true si se encontr� una coincidencia, false de lo contrario.
int buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);
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
//Operaci�n: Agrega una nueva persona.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo chofer.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarChofer(CentroLogisticoPtr centroLogistico,PersonaPtr chofer);
//Operaci�n: Agrega una nueva persona.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo cliente.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarCliente(CentroLogisticoPtr centroLogistico,PersonaPtr cliente);

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

//-----------------------------------------Funciones de inserci�n a la lista--------------------------------------------------
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
//----------------------------------------------Funciones para remover de la lista----------------------------------------------
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

PersonaPtr removerCliente(CentroLogisticoPtr centroLogistico, int posicion);

PersonaPtr removerChofer(CentroLogisticoPtr centroLogistico, int posicion);

//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: remueve de la lista de repartosAbiertos de centroLogistico un reparto
//               seleccionado por el usuario, desplazando el reparto a listaRepartosCerrados
//Par�metros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  posicion: entero representando la posicion del reparto a cerrar.
//Devuelve: nada.
void cerrarRepartoCtroLogistico(CentroLogisticoPtr centroLogistico, int posicion);

//OPERACION: busqueda de vehiculos en repartos
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide una patente, se busca si hay algun vehiculo que lo tenga.
//              De encontrarse, la muestra por pantalla, y de lo contrario se informa que no se encontr�.
//PAR�METROS:
//  puntero al centro logistico
//  patente a buscar
//DEVUELVE: Nada.
int buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente);
//OPERACION: busqueda de choferes en repartos
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PAR�METROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de clientes
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de clientes .
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PAR�METROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarCliente(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de choferes
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de choferes.
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PAR�METROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarChofer(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de reparto
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un indice, se busca si hay algun reparto que exista.
//              De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PAR�METROS:
//  puntero al centro logistico
//  indice a buscar
//DEVUELVE: Nada.
int buscarReparto(CentroLogisticoPtr centroLogistico, int posicionSolicitada);
//OPERACION: busqueda de paquete
//PRECONDICI�N: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un indice, se busca si hay algun paquete que exista.
//              De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PAR�METROS:
//  puntero al centro logistico
//  reparto en el cual buscar
//DEVUELVE: Nada.
int menuBuscarPaqueteReparto(CentroLogisticoPtr centroLogistico, RepartoPtr reparto);

//---------------------------------------Funciones para resetear listas------------------------------------------------

///Precondici�n: debe existir una funcion de destruccion para cada tipo de dato.
//Operaci�n: Elimina la lista de paquetes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de personas.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearPersonas(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de vehiculos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de repartos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//---------------------------------------Funciones de ordenamiento------------------------------------------------

//Operaci�n: ordena una lista de vehiculos por marca, alfab�ticamente
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: setea dentro de centro logistico todos los vehiculos ordenados alfabeticamente
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorMarca(CentroLogisticoPtr centroLogistico);

//Operaci�n: ordena una lista de paquetes por ID, de menor a mayor
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun su ID
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorID(CentroLogisticoPtr centroLogistico);


//Operaci�n: ordena una lista de repartos por fecha de salida, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de salida
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operaci�n: ordena una lista de repartos por fecha de retorno, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de retorno
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaRetorno(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operaci�n: ordena una lista de repartos por fecha de salida y retorno, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de salida y retorno
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operaci�n: ordena una lista de repartos alfab�ticamente por nombre del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               nombre del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorNombreChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operaci�n: ordena una lista de repartos alfab�ticamente por apellido del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               apellido del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorApellidoChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operaci�n: ordena una lista de repartos alfab�ticamente por nombre y apellido del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               nombre y el apellido del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorChoferRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


#endif // TDACENTROLOGISTICO_H_INCLUDED
