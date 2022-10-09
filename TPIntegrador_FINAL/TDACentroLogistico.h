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

//Operación:Crea la estructura Centro Logistico
//Precondición:Que el centro logistico no haya sido creado
//Postcondición:Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
//Parámetros:
// nombre: string representando al nombre.
// listaPaquete: puntero a lista representando la lista de paquetes.
// listaPersonas: puntero a lista representando la lista de personas.
// listaVehiculos: puntero a lista representando la lista de vehiculos.
// listaRepartos: puntero a lista representando la lista de repartos.
//Devuelve un puntero de la estructura creada.
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaClientes,ListaPtr listaChoferes,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados);
//Operación:Crea la estructura Centro Logistico de forma aleatoria
//Precondición:Que el centro logistico no haya sido creado
//Postcondición:Se crea un centro logistico con nombre, lista de paquetes, lista de personas, lista de vehiculos y lista de repartos.
//Parámetros:
// nombre del centro logístico
//Devuelve un puntero de la estructura creada.
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre); ///Crea un centro logístico con un nombre y listas vacías.
//Operación: Destruye la estructura de centro logistico.
//Precondición: Que la estructura de centro logistico haya sido creada.
//Postcondición: Se destruye el centro logistico y se libera la memoria utilizada.
//Parámetros:
// centroLogistico: puntero a estructura representando el centro logistico.
//Devuelve NULL
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico);

//Operación:Obtencion del nombre del centro logistico.
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene el nombre de centro logistico.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un string
char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico);
//Operación:Obtencion de la estructura de lista de paquetes
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene la lista de paquetes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico);
//Operación: Obtencion de la estructura de lista de personas.
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene la lista de personas.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico);

ListaPtr getClientes(CentroLogisticoPtr centroLogistico);

ListaPtr getChoferes(CentroLogisticoPtr centroLogistico);

//Operación:Obtencion de la estructura de lista de vehiculos.
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene la lista de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Obtencion de listas de repartos.
//Precondición: Que centro logistico haya sido creado.
//Postcondición: Se obtiene la lista de repartos
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere obtener un reparto abierto,
//      false = si se quiere obtener un reparto cerrado.
//Devuelve: puntero a la lista de repartos indicada por esRepartoAbierto.
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);

//Operación: Asigna el nombre
//Precondición: Centro logistico debe haberse creado.
//Postcondición: nombre cambia con el nuevo valor de nombre.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// nombre: string representando al nuevo valor de nombre.
//Devuelve: nada.
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);
//Operación: Asigna la estructura de paquetes.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: paquetes cambia con el nuevo valor de paquetes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
//Devuelve: nada.
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);
//Operación:Asigna la estructura de personas.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: personas cambia con el nuevo valor de personas.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPersonas: puntero a estructura que representa al nuevo valor de personas.
//Devuelve: nada.
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);
//Operación:Asigna la estructura de vehiculos.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: vehiculos cambia con el nuevo valor de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
//Devuelve: nada.
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);
//Operación: Asigna la estructura de repartos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: la lista de repartos seleccionada cambia con el nuevo valor de repartos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere asignar un reparto abierto,
//      false = si se quiere asignar un reparto cerrado.
// repartos: puntero a estructura que representa al nuevo valor de repartos.
//Devuelve: nada.
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto);

//Operación: Muestra los paquetes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de paquetes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
//Operación: Muestra las personas.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de personas.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarPersonas(CentroLogisticoPtr centroLogistico);
//Operación: Muestra los clientes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de clientes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarClientes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==false.
//Operación: Muestra los choferes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de choferes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarChoferes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==true.

//Operación: Muestra los vehiculos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Muestra los repartos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de repartos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere mostrar un reparto abierto,
//      false = si se quiere mostrar un reparto cerrado.
//Devuelve: nada.
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);
//Operación: Muestra los paquetes con el estado que le haya pasado.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime los paquetes con la condicion que se les haya pasado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// estado: entero que representa el estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve: nada.
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado); //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().

//Operación: Muestra los paquetes con el estado que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de paquetes
//Postcondición: Si hay coincidencia, imprime el paquete buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// ID: entero que representa el ID del paquete.
//Devuelve true si se encontró una coincidencia, false de lo contrario.
int buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);
//Operación: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
//Postcondición: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// cuil: string que representa el cuil de la persona.
// esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
//Devuelve true si se encontró una coincidencia, false de lo contrario.
int buscarPersona(CentroLogisticoPtr centroLogistico,char* cuil,bool esChofer);
//Operación: Muestra los vehiculos con la patente que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de vehiculos
//Postcondición: De encontrarse, imprime el vehiculo buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// patente: char que representa la patente del vehiculo.
//Devuelve true si se encontró una coincidencia, false de lo contrario.
int buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);
//---------------------------------------Funciones de agregado a la lista----------------------------------------------
//Operación: Agrega un nuevo paquete.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo paquete.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// paquete: puntero a estructura que representa al nuevo paquete.
//Devuelve: nada.
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);
//Operación: Agrega una nueva persona.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener una nueva persona.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);
//Operación: Agrega una nueva persona.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo chofer.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarChofer(CentroLogisticoPtr centroLogistico,PersonaPtr chofer);
//Operación: Agrega una nueva persona.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo cliente.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve: nada.
void agregarCliente(CentroLogisticoPtr centroLogistico,PersonaPtr cliente);

//Operación: Agrega un nuevo vehiculo.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo vehiculo.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
//Devuelve: nada.
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);
//Operación: Agrega un nuevo reparto.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La lista de repartos correspondiente tendrá un nuevo reparto.
//Parámetros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  esRepartoAbierto: valor booleano:
//      true = si se quiere agregar un reparto abierto,
//      false = si se quiere agregar un reparto cerrado.
//  reparto: puntero a estructura que representa al nuevo reparto.
//Devuelve: nada.
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto);

//-----------------------------------------Funciones de inserción a la lista--------------------------------------------------
//Operación: Inserta un paquete en la posicion de la lista pasada por referencia.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Un nuevo paquete se va a agregar a la posicion de la lista.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// paquete: puntero a estructura que representa al nuevo paquete.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion);
//Operación: Inserta una persona en la posicion de la lista pasada por referencia.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Una nueva persona se va a agregar a la posicion de la lista.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion);
//Operación: Inserta un vehiculo en la posicion de la lista pasada por referencia.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Un nuevo vehiculo se va a agregar a la posicion de la lista.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion);
//Operación: Inserta un reparto en la posicion de la lista pasada por referencia.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Un nuevo reparto se va a agregar a la posicion de la lista.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// reparto: puntero a estructura que representa al nuevo reparto.
// posicion: entero que representa la posicion.
//Devuelve true=si pudo agregar o false=si no pudo agregar.
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion);
//----------------------------------------------Funciones para remover de la lista----------------------------------------------
//Operación: Remueve un paquete en la posicion de la lista.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El paquete de la posicion pasada por referencia se remueve.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion);
//Operación: Remueve una persona en la posicion de la lista.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La persona de la posicion pasada por referencia se remueve.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion);
//Operación: Remueve un vehiculo en la posicion de la lista.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El vehiculo de la posicion pasada por referencia se remueve.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion);
//Operación: Remueve un reparto en la posicion de la lista.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El reparto de la posicion pasada por referencia se remueve.
//Parámetros:
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
//Parámetros:
//  centroLogistico: puntero a estructura que representa al centro logistico.
//  posicion: entero representando la posicion del reparto a cerrar.
//Devuelve: nada.
void cerrarRepartoCtroLogistico(CentroLogisticoPtr centroLogistico, int posicion);

//OPERACION: busqueda de vehiculos en repartos
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide una patente, se busca si hay algun vehiculo que lo tenga.
//              De encontrarse, la muestra por pantalla, y de lo contrario se informa que no se encontró.
//PARÁMETROS:
//  puntero al centro logistico
//  patente a buscar
//DEVUELVE: Nada.
int buscarVehiculoRepartos(CentroLogisticoPtr centroLogistico, char* patente);
//OPERACION: busqueda de choferes en repartos
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PARÁMETROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarChoferRepartos(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de clientes
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de clientes .
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PARÁMETROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarCliente(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de choferes
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de choferes.
//POSTCONDICION: se pide un CUIL, se busca si hay algun chofer que lo tenga.
//               De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PARÁMETROS:
//  puntero al centro logistico
//  cuil a buscar
//DEVUELVE: Nada.
int buscarChofer(CentroLogisticoPtr centroLogistico, char* cuil);
//OPERACION: busqueda de reparto
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un indice, se busca si hay algun reparto que exista.
//              De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PARÁMETROS:
//  puntero al centro logistico
//  indice a buscar
//DEVUELVE: Nada.
int buscarReparto(CentroLogisticoPtr centroLogistico, int posicionSolicitada);
//OPERACION: busqueda de paquete
//PRECONDICIÓN: centro logistico debe haber sido creado y cargado con una lista de repartos.
//POSTCONDICION: se pide un indice, se busca si hay algun paquete que exista.
//              De encontrarse, devuelve la posicion, en caso contrario devuelve -1
//PARÁMETROS:
//  puntero al centro logistico
//  reparto en el cual buscar
//DEVUELVE: Nada.
int menuBuscarPaqueteReparto(CentroLogisticoPtr centroLogistico, RepartoPtr reparto);

//---------------------------------------Funciones para resetear listas------------------------------------------------

///Precondición: debe existir una funcion de destruccion para cada tipo de dato.
//Operación: Elimina la lista de paquetes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearPaquetes(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de personas.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearPersonas(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de vehiculos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de repartos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve: nada.
void resetearRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//---------------------------------------Funciones de ordenamiento------------------------------------------------

//Operación: ordena una lista de vehiculos por marca, alfabéticamente
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: setea dentro de centro logistico todos los vehiculos ordenados alfabeticamente
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorMarca(CentroLogisticoPtr centroLogistico);

//Operación: ordena una lista de paquetes por ID, de menor a mayor
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun su ID
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorID(CentroLogisticoPtr centroLogistico);


//Operación: ordena una lista de repartos por fecha de salida, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de salida
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaSalida(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operación: ordena una lista de repartos por fecha de retorno, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de retorno
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaRetorno(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operación: ordena una lista de repartos por fecha de salida y retorno, de X a Y.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados
//               segun su fecha de salida y retorno
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorFechaRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operación: ordena una lista de repartos alfabéticamente por nombre del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               nombre del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorNombreChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operación: ordena una lista de repartos alfabéticamente por apellido del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               apellido del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorApellidoChofer(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);
//Operación: ordena una lista de repartos alfabéticamente por nombre y apellido del chofer.
//Precondicion: centroLogistico debe haber sido creado anteriormente con crearCentroLogistico
//Postcondicion: reinserta dentro de centro logistico todos los paquetes ordenados segun el
//               nombre y el apellido del chofer
//Parametros: puntero a la estructura centro logistico
//Devuelve: nada
void ordenarPorChoferRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto);


#endif // TDACENTROLOGISTICO_H_INCLUDED
