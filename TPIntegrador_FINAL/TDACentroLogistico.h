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
CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartos);
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
//Operación:Obtencion de la estructura de lista de vehiculos.
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene la lista de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Obtencion de la estructura de lista de vehiculos.
//Precondición:Que centro logistico haya sido creado.
//Postcondición:Se obtiene la lista de repartos
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve un puntero de la estructura lista.
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico);

//Operación:Asigna el nombre
//Precondición: Centro logistico debe haberse creado.
//Postcondición: nombre cambia con el nuevo valor de nombre.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// nombre: string representando al nuevo valor de nombre.
//Devuelve nada
void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre);
//Operación: Asigna la estructura de paquetes.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: paquetes cambia con el nuevo valor de paquetes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de paquetes.
//Devuelve nada
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes);
//Operación:Asigna la estructura de personas.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: personas cambia con el nuevo valor de personas.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPersonas: puntero a estructura que representa al nuevo valor de personas.
//Devuelve nada
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas);
//Operación:Asigna la estructura de vehiculos.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: vehiculos cambia con el nuevo valor de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaPaquetes: puntero a estructura que representa al nuevo valor de vehiculos.
//Devuelve nada
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos);
//Operación:Asigna la estructura de repartos.
//Precondición:Centro logistico debe haberse creado.
//Postcondición: repartos cambia con el nuevo valor de repartos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// listaRepartos: puntero a estructura que representa al nuevo valor de repartos.
//Devuelve nada
void setRepartos(CentroLogisticoPtr centroLogistico,ListaPtr listaRepartos);

//Operación: Muestra los paquetes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de paquetes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarPaquetes(CentroLogisticoPtr centroLogistico);
//Operación: Muestra las personas.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de personas.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarPersonas(CentroLogisticoPtr centroLogistico);
//Operación: Muestra los clientes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de clientes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarClientes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==false.
//Operación: Muestra los choferes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de choferes.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarChoferes(CentroLogisticoPtr centroLogistico); //busca y muestra solo las personas cuyo esChofer==true.

//Operación: Muestra los vehiculos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de vehiculos.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void mostrarVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Muestra los repartos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime la lista de repartos.
//Parámetros:
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
//Operación: Muestra los paquetes con el estado que le haya pasado.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: Imprime los paquetes con la condicion que se les haya pasado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// estado: entero que representa el estado del paquete. 0:en deposito 1:en curso 2:retirado  3:entregado 4:demorado 5:suspendido
//Devuelve nada
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado); //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().

//Operación: Muestra los paquetes con el estado que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de paquetes
//Postcondición: Si hay coincidencia, imprime el paquete buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// ID: entero que representa el ID del paquete.
//Devuelve true si se encontró una coincidencia, false de lo contrario.
bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID);
//Operación: Muestra las personas (clientes o choferes) con el cuil que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de clientes/choferes
//Postcondición: Si hay coincidencia, imprime la persona (cliente o chofer) con el cuil buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// cuil: string que representa el cuil de la persona.
// esChofer: booleano que aclara al buscador si se trata de un chofer (true) o un cliente (false).
//Devuelve true si se encontró una coincidencia, false de lo contrario.
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer);
//Operación: Muestra los vehiculos con la patente que le haya pasado.
//Precondición: Centro logistico debe haberse creado y llenado con una lista de vehiculos
//Postcondición: De encontrarse, imprime el vehiculo buscado.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// patente: char que representa la patente del vehiculo.
//Devuelve true si se encontró una coincidencia, false de lo contrario.
bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente);
//---------------------------------------Funciones de agregado a la lista----------------------------------------------
//Operación: Agrega un nuevo paquete.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo paquete.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// paquete: puntero a estructura que representa al nuevo paquete.
//Devuelve nada
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete);
//Operación: Agrega una nueva persona.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener una nueva persona.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// persona: puntero a estructura que representa a la nueva persona.
//Devuelve nada
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona);
//Operación: Agrega un nuevo vehiculo.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo vehiculo.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// vehiculo: puntero a estructura que representa al nuevo vehiculo.
//Devuelve nada
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo);
//Operación: Agrega un nuevo reparto.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: El centro logistico va a tener un nuevo reparto.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
// reparto: puntero a estructura que representa al nuevo reparto.
//Devuelve nada
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto);

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
// posicion: entero que representa la posicion.
//Devuelve un puntero a la estructura.
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion);
//---------------------------------------Funciones para resetear listas------------------------------------------------

///Precondición: debe existir una funcion de destruccion para cada tipo de dato.
//Operación: Elimina la lista de paquetes.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearPaquetes(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de personas.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearPersonas(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de vehiculos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearVehiculos(CentroLogisticoPtr centroLogistico);
//Operación: Elimina la lista de repartos.
//Precondición: Centro logistico debe haberse creado.
//Postcondición: La estructura pasada por referencia no existe.
//Parámetros:
// centroLogistico: puntero a estructura que representa al centro logistico.
//Devuelve nada
void resetearRepartos(CentroLogisticoPtr centroLogistico);


#endif // TDACENTROLOGISTICO_H_INCLUDED
