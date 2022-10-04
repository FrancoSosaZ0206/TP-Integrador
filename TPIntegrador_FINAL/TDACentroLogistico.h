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
    ListaPtr listaRepartos;
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
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartos);
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
//Operaci�n: Obtencion de la estructura de lista de vehiculos.
//Precondici�n:Que centro logistico haya sido creado.
//Postcondici�n:Se obtiene la lista de repartos
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico);

//Operaci�n:Asigna el nombre
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: nombre cambia con el nuevo valor de nombre.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// nombre: string representando al nuevo valor de nombre.
//Devuelve nada
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);
//Operaci�n: Asigna la estructura de paquetes.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: paquetes cambia con el nuevo valor de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
//Devuelve nada
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);
//Operaci�n:Asigna la estructura de personas.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: personas cambia con el nuevo valor de personas.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPersonas: puntero a estructura que representa al nuevo valor de personas.
//Devuelve nada
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);
//Operaci�n:Asigna la estructura de vehiculos.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: vehiculos cambia con el nuevo valor de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
//Devuelve nada
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);
//Operaci�n:Asigna la estructura de repartos.
//Precondici�n:Centro logistico debe haberse creado.
//Postcondici�n: repartos cambia con el nuevo valor de repartos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaRepartos: puntero a estructura que representa al nuevo valor de repartos.
//Devuelve nada
void setRepartos(CentroLogisticoPtr centroLogistico,ListaPtr listaRepartos);

//Operaci�n: Muestra los paquetes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de paquetes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra las personas.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de personas.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarPersonas(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los clientes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de clientes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarClientes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==false.
//Operaci�n: Muestra los choferes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de choferes.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarChoferes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==true.

//Operaci�n: Muestra los vehiculos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de vehiculos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los repartos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime la lista de repartos.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarRepartos(CentroLogisticoPtr centroLogistico);
//Operacion: Muestra lista de repartos filtrados por fecha de salida.(fecha,vehiculo, chofer)
//Precondicion: La lista debe estar creada.
//Postcondicion: Imprime lista de repartos.
//Parametros:
// listaRepartos: puntero a la estructura lista a imprimir.
//Devuelve nada
void mostrarRepartosPorFechaDeSalida(CentroLogisticoPtr centroLogistico);
//Operaci�n: Muestra los paquetes con el estado que le haya pasado.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: Imprime los paquetes con la condicion que se les haya pasado.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// estado: entero que representa el estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve nada
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
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer);
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
//Devuelve nada
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);
//Operaci�n: Agrega una nueva persona.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener una nueva persona.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve nada
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);
//Operaci�n: Agrega un nuevo vehiculo.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo vehiculo.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
//Devuelve nada
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);
//Operaci�n: Agrega un nuevo reparto.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: El centro logistico va a tener un nuevo reparto.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// reparto: puntero a estructura que representa al nuevo reparto.
//Devuelve nada
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto);

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
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion);
//---------------------------------------Funciones para resetear listas------------------------------------------------

///Precondici�n: debe existir una funcion de destruccion para cada tipo de dato.
//Operaci�n: Elimina la lista de paquetes.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearPaquetes(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de personas.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearPersonas(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de vehiculos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearVehiculos(CentroLogisticoPtr centroLogistico);
//Operaci�n: Elimina la lista de repartos.
//Precondici�n: Centro logistico debe haberse creado.
//Postcondici�n: La estructura pasada por referencia no existe.
//Par�metros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearRepartos(CentroLogisticoPtr centroLogistico);


#endif // TDACENTROLOGISTICO_H_INCLUDED
